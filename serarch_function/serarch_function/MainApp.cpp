#include <stdio.h>
#include <stdlib.h>

// 線形探索
int liner_search(int *arr,int size,int target) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			return i;
		}
	}
	return -1;
}

// 二分探索
int binary_search(int* arr, int size, int target) {
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int middle = left + (right - left) / 2;

		if (arr[middle] == target) {
			return middle;
		}
		if (arr[middle] < target) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	return -1;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}



int main() {
	int size;
	int target;

	printf("配列のサイズを入力してください:");
	scanf("%d", &size);
	int* arr = (int*)malloc(size * sizeof(int));
	if (arr == NULL) {
		printf("メモリの確保に失敗しました。\n");
		return 1;
	}

	printf("配列の要素を入力してください (スペース区切りで %d 個):\n", size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	
	qsort(arr, size, sizeof(int), compare);

	printf("配列は以下のように整理されました\n");
	for (int i = 0; i < size; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");

	// ターゲット値を入力
	printf("探索するターゲットを入力してください");
	scanf("%d", &target);

	// 線形探索
	int linear_result = liner_search(arr, size, target);
	if (linear_result != -1) {
		printf("線形探索: target %d はインデックス %d に存在します\n", target, linear_result);
	}
	else {
		printf("線形探索: target %d　は見つかりませんでした\n", target);
	}

	// 二分探索関数
	int binary_result = binary_search(arr, size, target);
	if (binary_result != -1) {
		printf("二分探索: target %d はインデックス %d に存在します\n", target, binary_result);
	}
	else {
		printf("二分探索: target %d は見つかりませんでした\n", target);
	}

	free(arr);

	return 0;
}


// 深さ優先探索
// 幅優先探索

// ジャンプサーチの実装
// 保管探索の実装
// 指数探索の実装
// ハッシュベースの探索


