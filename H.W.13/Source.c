#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

int main(void) {
	setlocale(LC_CTYPE, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	char user_string[200];
	char end_letter = '\0';
	int count = 0;

	puts("Введите вашу строку:");
	fgets(user_string, 199, stdin);

	for (int i = 0; user_string[i] != '\0'; i++) user_string[i] = tolower(user_string[i]);
	

	for (int i = 0; user_string[i] != '\0'; i++) {

		if (user_string[i + 1] == ' ' || user_string[i + 1] == '\0' || user_string[i + 1] == '\n') { end_letter = user_string[i]; break; }

	}

	for (int i = 1; user_string[i] != '\0'; i++) {
	
		if ((user_string[i - 1] == ' ') && (user_string[i] == end_letter)) count++;

	}

	if (user_string[0] == end_letter) count++;

	printf("%d слов начинается с последней буквы первого слова", count);

	return 0;
}