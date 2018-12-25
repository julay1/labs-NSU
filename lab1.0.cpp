#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#define dl 256
#define max_size_shablon 16

void key_tab(int *tab, char *shablon, int shablon_size) {
	for (int i = 0; i < dl; i++) {
		tab[i] = shablon_size;
	}
	for (int i = 0; i < shablon_size-1; i++) {
		tab[(int)shablon[i]] = shablon_size-i-1;
	}

}

int main() {
	int tab[dl];

	FILE *in=NULL;
	in = fopen("in.txt", "r");
	if (in == NULL) {
		return 0;
	}
	char symbol=0;
	char shablon[max_size_shablon];
	for (int i = 0; i < max_size_shablon; i++) {
		shablon[i] = 0;
	}
	int dl_shablona=0;//считываем шаблон
	symbol = fgetc(in);// esli '\n' - 1 symbol
	for (int i=0; (i < max_size_shablon)&&(symbol!='\n'); i++) {
		shablon[i] = symbol;
		dl_shablona++;
		symbol = fgetc(in);
	}
	if (dl_shablona == 0) {
		fclose(in);
		return 0;
	}

	key_tab(tab, shablon, dl_shablona);

	char buffer[max_size_shablon];
	for (int i = 0; i < max_size_shablon; i++) {
		buffer[i] = 0;
	}

	int sdvig = dl_shablona;// считываем строку 
	int k=fread(buffer, sizeof(char), sdvig, in);
	FILE *out = NULL;
	out = fopen("out.txt", "w");
	if (out == NULL) {
		return 0;
	}
	int i = 0;
	int position = 1;//позиция символа в тексте
	while( k == sdvig) {//начинаем печатать сравнения 
		i = 0;
		for (i; (i < dl_shablona) && (buffer[dl_shablona-1-i] == shablon[dl_shablona-1-i]); i++) {
			fprintf(out, "%d ", position + dl_shablona - 1 - i);
		}
		if (i == dl_shablona) {
			sdvig = dl_shablona;
		}
		else {
			fprintf(out, "%d ", position + dl_shablona - 1 - i);
			sdvig = tab[(int)buffer[dl_shablona - 1]];
		}
		if (sdvig < dl_shablona) {
			for (int j = sdvig; j < dl_shablona; j++) {
				buffer[j - sdvig] = buffer[j];
			}
		}
		position += sdvig;
		k = fread(buffer + dl_shablona - sdvig, sizeof(char), sdvig, in);
	}
	

	fclose(in);
	fclose(out);
	return 0;
}
