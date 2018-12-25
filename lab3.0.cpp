#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

void swap(int *x, int *y) {
	int z = *x;
	*x = *y;
	*y = z;
}

void shift(int *arr, int i, int n) {
	int max;
	while (i * 2 + 1 < n) {
		if ((i * 2 + 1 == n - 1) || (arr[i * 2 + 1] > arr[i * 2 + 2]))
			max = i * 2 + 1;
		else
			max = i * 2 + 2;

		if (arr[i] < arr[max]) {
			swap(&arr[i], &arr[max]);
			i = max;
		}
		else break;
	}
}

void heapsort(int *arr, int n) {
	for (int i = n / 2 - 1; i >= 0; --i) {
		shift(arr, i, n);
	}

	for (int i = n - 1; i > 0; --i) {
		swap(&arr[0], &arr[i]);
		shift(arr, 0, i);
	}
}

int main() {

	int n = 0;
	scanf("%d\n", &n);
	int *arr = (int*)malloc((size_t)(n * sizeof(int)));
	if (arr == NULL) {
		printf("bad input");
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	heapsort(arr, n);
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	return 0;
}