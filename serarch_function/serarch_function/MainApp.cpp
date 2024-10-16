#include <stdio.h>
#include <stdlib.h>

// ���`�T��
int liner_search(int *arr,int size,int target) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			return i;
		}
	}
	return -1;
}

// �񕪒T��
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

	printf("�z��̃T�C�Y����͂��Ă�������:");
	scanf("%d", &size);
	int* arr = (int*)malloc(size * sizeof(int));
	if (arr == NULL) {
		printf("�������̊m�ۂɎ��s���܂����B\n");
		return 1;
	}

	printf("�z��̗v�f����͂��Ă������� (�X�y�[�X��؂�� %d ��):\n", size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	
	qsort(arr, size, sizeof(int), compare);

	printf("�z��͈ȉ��̂悤�ɐ�������܂���\n");
	for (int i = 0; i < size; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");

	// �^�[�Q�b�g�l�����
	printf("�T������^�[�Q�b�g����͂��Ă�������");
	scanf("%d", &target);

	// ���`�T��
	int linear_result = liner_search(arr, size, target);
	if (linear_result != -1) {
		printf("���`�T��: target %d �̓C���f�b�N�X %d �ɑ��݂��܂�\n", target, linear_result);
	}
	else {
		printf("���`�T��: target %d�@�͌�����܂���ł���\n", target);
	}

	// �񕪒T���֐�
	int binary_result = binary_search(arr, size, target);
	if (binary_result != -1) {
		printf("�񕪒T��: target %d �̓C���f�b�N�X %d �ɑ��݂��܂�\n", target, binary_result);
	}
	else {
		printf("�񕪒T��: target %d �͌�����܂���ł���\n", target);
	}

	free(arr);

	return 0;
}


// �[���D��T��
// ���D��T��

// �W�����v�T�[�`�̎���
// �ۊǒT���̎���
// �w���T���̎���
// �n�b�V���x�[�X�̒T��


