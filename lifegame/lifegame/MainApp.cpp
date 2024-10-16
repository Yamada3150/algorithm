#include <vector>
#include <iostream> // std::cout, std::endlが使えるようになる

// ランダム用
#include <cstdlib> // 加えて、cls用
#include <ctime>


#include<thread> // スリープ用
#include<chrono> // ミリセカンド用

#ifdef _WIN32
#define CLEAR_COMMAND "cls" // Windowsの場合の画面クリアコマンド
#else
#define CLEAR_COMMAND "clear" // Unix系（Linux, macOS）の場合の画面クリアコマンド
#endif


int countLivingNeighbors(const std::vector<std::vector<int>>& grid, int x, int y) {

	// グリッドの行数を取得
	int n = grid.size();
	// グリッドの列数を取得
	int m = grid[0].size();
	int count = 0;

	// 8方向の隣接セルを確認
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) continue; // 自分自身はスキップ

			int nx = x + i;
			int ny = y + j;

			// グリッドの範囲内ならカウント
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				count += grid[nx][ny];
			}
		}
	}
	return count;

}
void displayGrid(std::vector<std::vector<int>>& grid) {
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (std::rand() % 150 == 0) { // 100文の1の確立で生きたセルにする
				grid[i][j] = 1;
			}
			// <<は、左シフト演算子としても使われるが、std::coutとの組み合わせでは出力演算子として使われる
			if (grid[i][j] == 1) {
				std::cout << "\033[33m* \033[0m"; // 黄色
				if (std::rand() % 30 == 0) {
					std::cout << "\033[37m* \033[0m"; // 白色
				}
				if (std::rand() % 200 == 0) {
					std::cout << "\033[31m* \033[0m"; // 赤色
				}
				if (std::rand() % 700 == 0) {
					std::cout << "\033[34m* \033[0m"; // 青色
				}
				if (std::rand() % 10000 == 0) { // 東京でタヌキに出会う確率らしいw
					std::cout << "\033[32m* \033[0m"; // 水色 
				}
			}
			else {
				// " "は、スペースを表す
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}

void updateGrid(std::vector<std::vector<int>>& grid){
	int n = grid.size();
	int m = grid[0].size();
	std::vector<std::vector<int>> nextGrid = grid;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int livingNeighbors = countLivingNeighbors(grid, i, j);

			if (grid[i][j] == 1) {
				if (livingNeighbors < 2 || livingNeighbors > 3) {
					nextGrid[i][j] = 0;
				}
				else {
					nextGrid[i][j] = 1;
				}
			} else {
				if (livingNeighbors == 3) {
					nextGrid[i][j] = 1;
				}
			}

		}
	}
	grid = nextGrid;
}


int main() {
	int n = 26;
	int m = 60;

	// std::vector<int>(m, 0)は長さmのベクトルを作成し、すべての要素を0で初期化
	//　std::vector<std::vector<int>>は、ベクトルの中に別のベクトルを持つ構造　→　2次元配列
	// 整数型(int)の動的配列
	std::vector<std::vector<int>> grid(n, std::vector<int>(m, 0));

	std::srand(std::time(0)); // ランダムシードを現在の時刻で設定 これをやることで、毎回異なる乱数が生成される


	for (int gen = 0; gen < 1000; gen++) {
		// 画面クリア
		system(CLEAR_COMMAND);

		std::cout << gen+1 << "世代目" << std::endl;
	

		//int x = 5, y = 5;
		//std::cout << "対象セル(" << x << "," << y << ")の周りで生きているセルの数:"
		//	<< countLivingNeighbors(grid, x, y) << std::endl;

		displayGrid(grid);

		// 次の世代に更新
		updateGrid(grid);

		// 画面更新のために少し待つ
		// 
		// std::this_thread::sleep_for(std::chrono::microseconds(55000)); は55,000マイクロ秒 → 0.055秒
		// 1秒は1,000,000（100万）マイクロ秒
		std::this_thread::sleep_for(std::chrono::microseconds(55000));
	}
	return 0;
}


// coutとは？
// coutはconsole outputの略

// endlとは？
// end of lineの略

// std::
// coutが標準名前空間(st)に属していることを示している。

// std::endl
// 改行コード\nに加え、バッファをフラッシュすることで、コンソールにデータが確実に表示されるようになる。

// ↓

// バッファとは？
// プログラムがデータをすぐに出力せずに、一時的に蓄えておくためもメモリ領域のこと

// バッファのフラッシュが必要な理由
// データはまずバッファに蓄えられ、下記のような一定のタイミングでまとめて出力される。
// 1. バッファがいっぱいになったとき
// 2. プログラムが終了したとき
// 3. 明示的にフラッシュ操作を行ったとき　std::endlやflush()を使う場合
