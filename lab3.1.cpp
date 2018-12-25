#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
	int z = *x;
	*x = *y;
	*y = z;
}

void sort(int *a, int left, int right) {
	int l = left;
	int r = right;
	int mid = a[(left + right) / 2];
		do {
		while (a[l] < mid)
			l++;

		while (a[r] > mid)
			r--;

		if (l > r) {
			break;
		}
		if (a[l] > a[r]) {
			swap(&a[l], &a[r]);
		}
		l++;
		r--;
	}
			while (l <= r);
			if (l < right)
			sort(a, l, right);
			if (left < r)
			sort(a, left, r);
}

int main() {
	int n;
	scanf("%d\n", &n);
	int *a = (int*)malloc ((n * sizeof(int)));
	if (a == NULL) {
		printf("bad input");
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, 0, n - 1);
	for (int j = 0; j < n; ++j) {
		printf("%d ", a[j]);
	}
	return 0;
}