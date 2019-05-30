#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#define max_dl 11
using namespace std;

void swap(char* arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int perm(char* a, int N)
{
	int i = N - 1;
	while (i > 0 && a[i - 1] >= a[i])
		i--;
	if (!i)
		return 0;
	int j = N - 1;
	while (a[j] <= a[i - 1])
		j--;
	swap(a, i - 1, j);
	j = N - 1;
	while (i++ < j--)
		swap(a, i, j);
	return 1;
}

int check(char* a)
{
	int s[max_dl - 1] = { 0 };
	for (int index = 0; index < strlen(a); index++)
	{
		if (s[a[index] - '0'] || a[index] > '9' || a[index] < '0')
			return 0;
		s[a[index] - '0'] = 1;
	}
	return 1;
}


int main()
{
	int N;
	char a[max_dl];
	cin >> a >> N;
	if (!check(a))
		cout << "bad input";
	else
		while (perm(a, strlen(a)) && N--)
			cout << a<< "\n";
	return 0;
}
