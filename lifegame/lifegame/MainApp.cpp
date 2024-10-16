#include <vector>
#include <iostream> // std::cout, std::endl���g����悤�ɂȂ�

// �����_���p
#include <cstdlib> // �����āAcls�p
#include <ctime>


#include<thread> // �X���[�v�p
#include<chrono> // �~���Z�J���h�p

#ifdef _WIN32
#define CLEAR_COMMAND "cls" // Windows�̏ꍇ�̉�ʃN���A�R�}���h
#else
#define CLEAR_COMMAND "clear" // Unix�n�iLinux, macOS�j�̏ꍇ�̉�ʃN���A�R�}���h
#endif


int countLivingNeighbors(const std::vector<std::vector<int>>& grid, int x, int y) {

	// �O���b�h�̍s�����擾
	int n = grid.size();
	// �O���b�h�̗񐔂��擾
	int m = grid[0].size();
	int count = 0;

	// 8�����̗אڃZ�����m�F
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) continue; // �������g�̓X�L�b�v

			int nx = x + i;
			int ny = y + j;

			// �O���b�h�͈͓̔��Ȃ�J�E���g
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
			if (std::rand() % 150 == 0) { // 100����1�̊m���Ő������Z���ɂ���
				grid[i][j] = 1;
			}
			// <<�́A���V�t�g���Z�q�Ƃ��Ă��g���邪�Astd::cout�Ƃ̑g�ݍ��킹�ł͏o�͉��Z�q�Ƃ��Ďg����
			if (grid[i][j] == 1) {
				std::cout << "\033[33m* \033[0m"; // ���F
				if (std::rand() % 30 == 0) {
					std::cout << "\033[37m* \033[0m"; // ���F
				}
				if (std::rand() % 200 == 0) {
					std::cout << "\033[31m* \033[0m"; // �ԐF
				}
				if (std::rand() % 700 == 0) {
					std::cout << "\033[34m* \033[0m"; // �F
				}
				if (std::rand() % 10000 == 0) { // �����Ń^�k�L�ɏo��m���炵��w
					std::cout << "\033[32m* \033[0m"; // ���F 
				}
			}
			else {
				// " "�́A�X�y�[�X��\��
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

	// std::vector<int>(m, 0)�͒���m�̃x�N�g�����쐬���A���ׂĂ̗v�f��0�ŏ�����
	//�@std::vector<std::vector<int>>�́A�x�N�g���̒��ɕʂ̃x�N�g�������\���@���@2�����z��
	// �����^(int)�̓��I�z��
	std::vector<std::vector<int>> grid(n, std::vector<int>(m, 0));

	std::srand(std::time(0)); // �����_���V�[�h�����݂̎����Őݒ� �������邱�ƂŁA����قȂ闐�������������


	for (int gen = 0; gen < 1000; gen++) {
		// ��ʃN���A
		system(CLEAR_COMMAND);

		std::cout << gen+1 << "�����" << std::endl;
	

		//int x = 5, y = 5;
		//std::cout << "�ΏۃZ��(" << x << "," << y << ")�̎���Ő����Ă���Z���̐�:"
		//	<< countLivingNeighbors(grid, x, y) << std::endl;

		displayGrid(grid);

		// ���̐���ɍX�V
		updateGrid(grid);

		// ��ʍX�V�̂��߂ɏ����҂�
		// 
		// std::this_thread::sleep_for(std::chrono::microseconds(55000)); ��55,000�}�C�N���b �� 0.055�b
		// 1�b��1,000,000�i100���j�}�C�N���b
		std::this_thread::sleep_for(std::chrono::microseconds(55000));
	}
	return 0;
}


// cout�Ƃ́H
// cout��console output�̗�

// endl�Ƃ́H
// end of line�̗�

// std::
// cout���W�����O���(st)�ɑ����Ă��邱�Ƃ������Ă���B

// std::endl
// ���s�R�[�h\n�ɉ����A�o�b�t�@���t���b�V�����邱�ƂŁA�R���\�[���Ƀf�[�^���m���ɕ\�������悤�ɂȂ�B

// ��

// �o�b�t�@�Ƃ́H
// �v���O�������f�[�^�������ɏo�͂����ɁA�ꎞ�I�ɒ~���Ă������߂��������̈�̂���

// �o�b�t�@�̃t���b�V�����K�v�ȗ��R
// �f�[�^�͂܂��o�b�t�@�ɒ~�����A���L�̂悤�Ȉ��̃^�C�~���O�ł܂Ƃ߂ďo�͂����B
// 1. �o�b�t�@�������ς��ɂȂ����Ƃ�
// 2. �v���O�������I�������Ƃ�
// 3. �����I�Ƀt���b�V��������s�����Ƃ��@std::endl��flush()���g���ꍇ
