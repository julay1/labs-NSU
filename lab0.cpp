#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#define num_len 80
#define full_mass 80

int badinput(int t)
{

	if (t != 2)
	{
		printf("bad input");
		return 0;
	}
	return 1;
}
int main()
{
	int c[num_len], d[num_len], i=0, t=0, b1=0, b2=0, flag=0, kc=0, kd=0, ks=0;
	char st[full_mass];
	char st2[full_mass];
	ks = 0;
	if (badinput(t = scanf("%d %d", &b1, &b2)) == 0)
		return 0;

	if (b1 < 2 || b1>16 || b2 < 2 || b2>16)//proverka na ss
	{
		printf("bad input");
		return 0;
	}
	scanf("%s", st);
	int pos = -1;
	for (int j = 0; j < strlen(st); j++)if (st[j] == '.')pos = j; // proverka na .
	if ((pos == strlen(st) - 1) || (pos == 0)) {
		printf("bad input");
	}
	if (st[0] == '-') flag = 1;//proverka na minus
	else flag = 0;
	kc = 0;
	for (i = flag; i < strlen(st) && st[i] != '.'; i++)// proverka na pravilniy vvod celoy chasti
	{
		if (st[i] >= '0' && st[i] <= '9')
			c[i - flag] = st[i] - '0';
		else
			if (st[i] >= 'A' && st[i] <= 'F')
				c[i - flag] = (st[i] - 'A') + 10;
			else
				if (st[i] >= 'a' && st[i] <= 'f')
					c[i - flag] = (st[i] - 'a') + 10;
				else
				{
					printf("bad input");
					return 0;
				}
		kc++;
		if (c[i - flag] >= b1 || c[i - flag] < 0)
		{
			printf("bad input");
			return 0;
		}
	}
	kd = 0;
	for (i += 1; i < strlen(st); i++)// proverka na pravilniy vvod drobnoy chasti
	{
		if (st[i] >= '0' && st[i] <= '9')
			d[kd] = st[i] - '0';
		else
			if (st[i] >= 'A' && st[i] <= 'F')
				d[kd] = (st[i] - 'A') + 10;
			else
				if (st[i] >= 'a' && st[i] <= 'f')
					d[kd] = (st[i] - 'a') + 10;
				else
				{
					printf("bad input");
					return 0;
				}
		if (d[kd] >= b1 || d[kd] < 0)
		{
			printf("bad input");
			return 0;
		}
		kd++;
	}
	/*perevod v 10*/
	double num = 0;
	for (i = 0; i < kc; i++)
		num += c[i] * pow(b1, kc - i - 1);
	for (i = 0; i < kd; i++)
		num += d[i] * pow(b1, -(i + 1));

	/*perevod v b2*/
	long long n = (long long)num;
	if (n == 0) { //esli celaya=0
		kc = 1;
	}
	else {
		for (i = 0; n != 0; i++)
		{
			c[i] = n % b2;
			n /= b2;
		}
		kc = i;
	}
	double m = num - (long long)num;
	for (i = 0; m != 0 && i < 12; i++)
	{
		d[i] = (long long)(m*b2);
		m = m * b2 - (d[i]);
	}
	kd = i;
	if (flag == 1)
		st2[0] = '-';
	ks = flag;
	for (i = 0; i < kc; i++)//vivod celoy chasti
	{
		if (c[kc - i - 1] <= 9 && c[kc - i - 1] >= 0)
			st2[i + flag] = c[kc - i - 1] + '0';
		if (c[kc - i - 1] <= 15 && c[kc - i - 1] >= 10)
			st2[i + flag] = (c[kc - i - 1] - 10) + 'A';
		ks++;
	}
	if (kd == 0)//esli net drobnoy
	{
		for (i = 0; i<ks; i++)
			printf("%c", st2[i]);
		return 0;
	}
	if (kd>0)// vivod drobnoy
	{
		st2[i + flag] = '.';
		ks++;
	}
	for (i = 0; i < kd; i++)
	{
		if (d[i] <= 9 && d[i] >= 0)
			st2[flag + kc + 1 + i] = d[i] + '0';
		if (d[i] <= 15 && d[i] >= 10)
			st2[flag + kc + 1 + i] = (d[i] - 10) + 'A';
		ks++;
	}
	for (i = 0; i<ks; i++)
		printf("%c", st2[i]);
	return 0;
}
