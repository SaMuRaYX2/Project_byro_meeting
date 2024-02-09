#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

int main() {
	system("chcp 1251"); system("cls");
	FILE* file;
	char way[] = "D:\\My Homework\\Practika_1\\partner1.txt";
	char* string;
	char* newpoint;
	int new_string;
	int y;
	char* temp_token;
	char** token;
	char* context;
	char delimiters[] = "\n";
	int size_token;
	int number_token;
	char* temp_string;
	int size_of_file;
	int size_of_new_string;
	int size_of_string;
	char* buffer;
	char buffer1[100];
	do {
		string = NULL;
		newpoint = NULL;
		temp_string = NULL;
		buffer = NULL;
		new_string = 0;
		size_of_file = 0;
		size_of_new_string = 0;
		size_of_string = 0;
		string = (char*)malloc(100 * sizeof(char));
		for (int i = 0; i < 100; i++) {
			size_of_string += sizeof(string[i]);
		}
		file = fopen(way, "a");
		if (file == NULL) {
			printf("ERROR!!!\n");
			return 1;
		}
		buffer = (char*)malloc(100 * sizeof(char));
		printf("Введіть рядок : "); fgets(buffer1, sizeof(buffer1), stdin);
		newpoint = strchr(buffer1, '\n');
		if (newpoint != NULL) {
			*newpoint = '\0';
		}
		if (fprintf(file, "Рядок : %s\n", buffer1) == EOF) {
			perror("Помилка!!!\n");
			return 1;
		}
		while (feof(file) != true) {
			if (fgets(buffer, 100, file) != NULL) {
				printf("%s", buffer);
			}
		}
		free(buffer);
		fclose(file);
		file = fopen(way, "r");
		if (file == NULL) {
			printf("Помилка створення чи знаходження файла!!!\n");
			return 1;
		}
		fseek(file, 0, SEEK_END);
		size_of_file = ftell(file);
		rewind(file);
		buffer = (char*)malloc(size_of_file * sizeof(char));
		while (feof(file) != true) {
			if (fgets(buffer, size_of_file, file) != NULL) {
				printf("%s", buffer);
			}
		}
		temp_string = (char*)malloc((size_of_file + 1) * sizeof(char));
		fread(temp_string, sizeof(char), size_of_file, file);
		temp_string[size_of_file] = '\0';
		fclose(file);
		int x;
		printf("Введіть дію над командою(1 - добавити в файл рядок!!!)(2 - змінити рядок!!!)(3 - вивести вміст файлу!!!): "); scanf_s("%d", &x);
		switch (x) {
		case 1: {
			file = fopen(way, "a");
			if (file == NULL) {
				printf("Error!!!\n");
				return 1;
			}
			printf("Введіть рядок,який ви хочете записати в файл : "); fgets(string, size_of_string, stdin);
			newpoint = strchr(string, '\n');
			if (newpoint != NULL) {
				*newpoint = '\0';
			}
			fprintf(file, "Рядок : %s\n", string);
			fclose(file);
			break;
		}
		case 2: {
			buffer = NULL;
			buffer = (char*)malloc(100 * sizeof(char));
			file = fopen(way, "r+");
			if (file == NULL) {
				printf("Помилка створення чи знаходження файла!!!\n");
				return 1;
			}
			printf("Введіть рядок,який ви хочете записати в файл : "); fgets(string, size_of_string, stdin);
			newpoint = strchr(string, '\n');
			if (newpoint != NULL) {
				*newpoint = '\0';
			}
			size_of_new_string = strlen(string)+1;
			printf("Введіть рядок, який ви будете замінювати : "); scanf_s("%d", &new_string);
			while (getchar() != '\n');
			temp_token = NULL;
			size_token = 1;
			number_token = 0;
			context = NULL;
			token = (char**)malloc(size_token * sizeof(char*));
			token[number_token] = (char*)malloc(100 * sizeof(char));
			temp_token = strtok_s(temp_string, delimiters, &context);
			while (temp_token != NULL) {
				if (temp_token == NULL) {
					break;
				}
				strcpy(token[number_token], temp_token);
				size_token++;
				number_token++;
				token = (char**)realloc(token, size_token * sizeof(char*));
				token[number_token] = (char*)malloc(100 * sizeof(char));
				temp_token = strtok_s(NULL, delimiters, &context);
			}
			for (int i = 0; i < number_token; i++) {
				printf("(%s)\n", token[i]);
			}
			token[new_string - 1] = NULL;
			token[new_string - 1] = (char*)malloc(size_of_new_string * sizeof(char));
			strcpy(token[new_string - 1], string);
			for (int i = 0; i < number_token; i++) {
				fputs(token[i], file);
			}
			while (feof(file) != true) {
				if (fgets(buffer, sizeof(buffer), file) != NULL) {
					printf("%s", buffer);
				}
			}
			fclose(file);
			break;
		}
		case 3: {
			buffer = NULL;
			buffer = (char*)malloc(100 * sizeof(char));
			file = fopen(way, "r");
			if (file == NULL) {
				printf("Помилка створення чи знаходження файла!!!\n");
				return 1;
			}
			while (feof(file) != true) {
				if (fgets(buffer, sizeof(buffer), file) != NULL) {
					printf("%s", buffer);
				}
			}
			fclose(file);
			break;
		}
		}
		printf("Введіть дію над програмою 1 - продовжити; 0 - закінчити;\nВведіть : ");
		while (scanf_s("%d", &y) != 1 && scanf_s("%d", &y) != 0) {
			printf("Введіть дію над програмою 1 - продовжити; 0 - закінчити;\nВведіть : ");
			while (getchar() != '\n');
		}
	} while (y != 0);
	return 0;
}