#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#define dl 256
#define max_size_shablon 16

long hash(unsigned char *shablon, int dl_shablona) {
	long h = 0;
	for (int i = 0; i < dl_shablona; i++)
		h += (shablon[i] % 3) * (pow(3,i));
	return h;
}

int main() {

	FILE *in = NULL;
	in = fopen("in.txt", "r");
	if (in == NULL) {
		return 0;
	}
	unsigned char symbol = 0;
	unsigned char shablon[max_size_shablon];
	for (int i = 0; i < max_size_shablon; i++) {
		shablon[i] = 0;
	}
	int dl_shablona = 0;
	symbol = fgetc(in);
	for (int i = 0; (i < max_size_shablon) && (symbol != '\n'); i++) {
		shablon[i] = symbol;
		dl_shablona++;
		symbol = fgetc(in);
	}
	if (dl_shablona == 0) {
		fclose(in);
		return 0;
	}
	int mainhash = hash(shablon, dl_shablona);
	unsigned char buffer[max_size_shablon];
	for (int i = 0; i < max_size_shablon; i++) {
		buffer[i] = 0;
	}
	int k = fread(buffer, sizeof(unsigned char), dl_shablona, in);
	int subhash = hash(buffer, dl_shablona);
	int maxpow = pow(3, dl_shablona - 1);
	FILE *out = NULL;
	out = fopen("out.txt", "w");
	if (out == NULL) {
		return 0;
	}
	fprintf(out, "%d ", mainhash);
	for (int i = 1; !feof(in); ++i) {
		if (mainhash == subhash) {
			for (int j = i; j < i+ dl_shablona; j++) 
				fprintf(out, "%d ", j);
		}
		unsigned char b = buffer[(i % dl_shablona)+dl_shablona];
		unsigned char new_symbol = (unsigned char)fgetc(in);
		subhash = (subhash - (b% 3)) / 3 + ((new_symbol % 3) * maxpow);
		buffer[i % dl_shablona] = new_symbol;
	}
	fclose(in);
	fclose(out);
	return 0;
}
