#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include <ctime>
#include <string.h>
#include <locale.h>
#include <ctype.h>
FILE* file;

struct partner_require {
	char eye[10];
	int hight;
	char hair[15];
	char name[15];
	char face[20];
	char character[15];
	char goroskop[30];
	char job[30];
};

struct date_register {
	int date;
	char month[20];
	int year;
};

struct marryed {
	char sex[20];
	int number_register;
	struct date_register dates;
	char* information;
	struct partner_require requirements;
};

struct my_self {
	char sex[20];
	int number_register;
	struct date_register dates;
	char* information;		
	struct partner_require requirements;
};

struct couple {
	char sex[20];
	int number_register;
	struct date_register dates;
	char* information;
	struct partner_require requirements;
};
struct delete_couple {
	char sex[20];
	int number_register;
	struct date_register dates;
	char* information;
	struct partner_require requirements;
};

void output_delete_archive(int num_del_cou, struct delete_couple** delete_archive, char** token_menu);
void fill_archive(int* num_cou,struct couple*** archive,char* way2);
void fill_delete_archive(int* num_del_cou,struct delete_couple*** delete_archive,char* way3);
void delete_couple1(int* num_del_cou, struct delete_couple*** delete_archive, char* way3, char** token_month,int* num_cou,struct couple*** archive,char** token_menu,char* way2);
void output_archive(struct couple*** archive, int* num_cou, char** token_menu, char* way2);
void choose_one(int num, struct marryed* partner, int** index_of_needless_partners);
void output_couple(struct marryed** partner,struct my_self* me,int* index_of_needless_partners,int* num,char** token_menu,char* way2,char* way1,char* way);
void information_me(int num_me,struct my_self** me);
void fill_str_me(int num_me, struct my_self** me, char* way1);
void input1_myself(struct my_self* me, char* way1);
void find_candidat_delete_without_date(int num, struct marryed* partner, char* del_name, char* del_sex, char* del_eye, char* del_hair, int del_hight, int** temp_index_of_need_partner);
void find_candidat_delete_with_date(int num, struct marryed* partner, char* del_name, int delete_date, char* delete_month, int delete_year, char* del_sex, char* del_eye, char* del_hair, int del_hight, int** temp_index_of_need_partner);
void delete_partner(int* num, struct marryed** partner, char* del_name, char* del_dates, char* del_sex, char* del_eye, char* del_hair, int del_hight, char** token_month, int number_of_month, char** token_menu, char* way, int test_name, int test_dates, int test_sex, int test_eye, int test_hair, int test_hight,int** index_to_indeficate_partner,int* test_of_number_delete_partner);
void sort(int num, struct marryed* partner, int** index_of_needless_partners, int type_sort, int* test, char** token_month,int number_of_month);
void output_all(int num, struct marryed* partner, char** token_menu,int* index_of_needless_partners);
void information(int num,struct marryed** partner);
void fill_str(int *num, struct marryed** partner,char* way);
void input1(int num,struct marryed* partner,char* way);
void menu1(int num, struct marryed* partner,char** token_menu,char** token_month,char* way,int number_of_month,struct my_self* me,int num_me,char* way1,char* way2,int num_cou,struct couple** archive,int num_del_cou,struct delete_couple** delete_archive,char* way3);
void find(int num, struct marryed* partner, char* partner_sex, char* partner_eye, int partner_hight, char* partner_hair, char* partner_name, char* partner_face, char* partner_character,int** index_of_needless_partners,char* partner_goroskop,char* partner_job);
void output_finded(int num, struct marryed* partner, int* index_of_needless_partners,char** token_menu);
void find_candidat(int num, struct marryed* partner, char* partner_sex, char* partner_eye, int partner_hight, char* partner_hair, char* partner_name, char* partner_face, char* partner_character, int** temp_index_of_needless_partners,char* partner_goroskop,char* partner_job,char* test_sex);

int main() {
	//setlocale(LC_ALL, "uk_UA.UTF-8");
	system("chcp 1251"); system("cls");
	char way[] = "D:\\My Homework\\Practika_1\\Practica_3_partner.txt";
	char way1[] = "D:\\My Homework\\Practika_1\\Practica_3_me.txt";
	char way2[] = "D:\\My Homework\\Practika_1\\Practica_3_archive.txt";
	char way3[] = "D:\\My Homework\\Practika_1\\Practica_3_delete_archive.txt";
	srand((unsigned)time(NULL));
	struct marryed* partner;
	int num = 0;
	int num_me = 1;
	int num_cou = 1;
	int num_del_cou = 1;
	partner = (struct marryed*)malloc(num+1 * sizeof(struct marryed));
	struct my_self* me;
	struct couple** archive;
	struct delete_couple** delete_archive;
	delete_archive = NULL;
	archive = NULL;
	//archive = (struct couple*)malloc(num_cou * sizeof(struct couple));
	me = NULL;
	me = (struct my_self*)malloc(num_me * sizeof(struct my_self));
	do {
		fill_str(&num, &partner,way);
		//information(num, &partner);
		if (num != 0) {
			break;
		}
		else {
			printf("В вашій базі даний немає кандидатів, заповніть її!!!\n");
			input1(num, partner, way);
		}
	} while (num == 0);

	
	// MONTHS;
	char *month1;
	month1 = NULL;
	month1 = (char*)malloc(250 * sizeof(char));
	if (month1 == NULL) {
		printf("Errro!!!\n");
		return 1;
	}
	strcpy(month1, "січень,лютий,березень,квітень,травень,червень,липень,серпень,вересень,жовтень,листопад,грудень");
	int len_of_month = strlen(month1)+1;
	month1 = (char*)realloc(month1,len_of_month * sizeof(char));
	char** token_month;
	int size_token = 1;
	int index = 0;
	char* context;
	context = NULL;
	char delimiters[] = ",";
	char* token;
	token_month = (char**)malloc(size_token * sizeof(char*));
	token = strtok_s(month1, delimiters, &context);
	int len_token_month = strlen(token) + 1;
	token_month[index] = (char*)malloc(len_token_month * sizeof(char));
	while (token != NULL) {
		token_month[index] = token;
		index++;
		size_token++;
		token_month = (char**)realloc(token_month, size_token * sizeof(char*));
		token = strtok_s(NULL, delimiters, &context);
		if (token == NULL) {
			break;
		}
		len_token_month = strlen(token) + 1;
		token_month[index] = (char*)malloc(len_token_month * sizeof(char));
	}
	int number_of_month = size_token - 1;
	/*for (int i = 0; i < number_of_month; i++) {
		printf("Token[%d] = %s\n", i, token_month[i]);
	}*/
	// MONTHS;

	// MENU FOR PARTNER;
	char menu_partner[] = "Регістраційний номер: ,Ім'я: ,Стать: ,Дата народження : ,Колір очей: ,Ріст: ,Колір волося: ,Тип лиця: ,Характер: ,Гороскоп: ,Місце роботи: ,Інформація про його(неї): ";
	char** token_menu;
	int number_token = 1;
	int index_token = 0;
	char* context1;
	context1 = NULL;
	char delimiters_for_menu[] = ",";
	char* token1;
	token_menu = (char**)malloc(number_token * sizeof(char*));
	token1 = strtok_s(menu_partner, delimiters_for_menu, &context1);
	int len_of_menu_tok = strlen(token1) + 1;
	token_menu[index_token] = (char*)malloc(len_of_menu_tok * sizeof(char));
	while (token1 != NULL) {
		token_menu[index_token] = token1;
		number_token++;
		index_token++;
		token_menu = (char**)realloc(token_menu, number_token * sizeof(char*));
		token1 = strtok_s(NULL, delimiters_for_menu, &context1);
		if (token1 == NULL) {
			break;
		}
		len_of_menu_tok = strlen(token1) + 1;
		token_menu[index_token] = (char*)malloc(len_of_menu_tok * sizeof(char));
	}
	int number_of_menu_element = number_token - 1;

	/*for (int i = 0; i < number_of_menu_element; i++) {
		printf("%s\n", token_menu[i]);
	}*/
	// MENU FOR PARTNER;

	//printf("Мене звати %s ,я народився %d-го %s %d-го року ,я %s ,мій номер реєстрації %d ,я маю %s очі,%s волося,%s лице,я маю такий ріст %d,я %s , також я маю деяку інформацію про себе\n%s", partner[0].requirements.name, partner[0].dates.date, partner[0].dates.month, partner[0].dates.year, partner[0].sex, partner[0].number_register, partner[0].requirements.eye, partner[0].requirements.hair, partner[0].requirements.face, partner[0].requirements.hight, partner[0].requirements.character, partner[0].information);
	char* action_program;
	char* temp_value;
	action_program = (char*)malloc(20 * sizeof(char));
	do {
		menu1(num, partner,token_menu,token_month,way,number_of_month,me,num_me,way1,way2,num_cou,archive,num_del_cou,delete_archive,way3);
		printf("Contninue to using this program (yes or no)?\nEnter : ");
		fgets(action_program, 10, stdin);
		temp_value = strchr(action_program, '\n');
		if (temp_value != NULL) {
			*temp_value = '\0';
		}
		if (strcmp(action_program, "no") == 0) {
			printf("Program is finished!!!\n");
			return 1;
		}
	} while (strcmp(action_program, "no") != 0);
	return 0;
}

void fill_str(int *num,struct marryed** partner,char* way) {
	*num = 0;
	int temp_number;
	char*** token;
	char* context1;
	char* context2;
	context1 = NULL;
	context2 = NULL;
	char delimiters1[] = "#";
	char delimiters2[] = "\n";
	char* temp_token;
	char* temp_str;
	temp_token = NULL;
	temp_str = NULL;
	temp_token = (char*)malloc(300 * sizeof(char));
	temp_str = (char*)malloc(400 * sizeof(char));
	int number_string = (*num)+1;
	int size_token = 0;
	int number_token = 1;
	int pointer;
	char* buffer;
	buffer = NULL;
	char* temp_string;
	int size_of_string;
	size_of_string = NULL;
	file = fopen(way, "r+");
	if (file == NULL) {
		perror("Помилка відриття файла!!!\n");
		exit(EXIT_FAILURE);
	}
	fseek(file, 0, SEEK_END);
	pointer = ftell(file) / sizeof(char);
	if (pointer == 0) {
		return;
	}
	rewind(file);
	buffer = (char*)malloc(pointer * sizeof(char));
	temp_string = (char*)malloc(pointer * sizeof(char));
	temp_string[0] = '\0';
	while (fgets(buffer, pointer, file) != NULL) {
		strcat(temp_string, buffer);
	}
	temp_str = strtok_s(temp_string, delimiters2, &context2);
	temp_token = strtok_s(temp_str, delimiters1, &context1);
	token = (char***)malloc(number_string * sizeof(char**));
	token[*num] = (char**)malloc(number_token * sizeof(char*));
	token[*num][size_token] = (char*)malloc(500 * sizeof(char));
	while (temp_str != NULL) {
		if (temp_str == NULL) {
			break;
		}
		while (temp_token != NULL) {
			if (temp_token == NULL) {
				break;
			}
			strcpy(token[*num][size_token], temp_token);
			size_token++;
			number_token++;
			token[*num] = (char**)realloc(token[*num], number_token * sizeof(char*));
			token[*num][size_token] = (char*)malloc(500 * sizeof(char));
			temp_token = strtok_s(NULL, delimiters1, &context1);
		}
		(*num)+=1;
		number_string++;
		token = (char***)realloc(token, number_string * sizeof(char**));
		temp_str = strtok_s(NULL, delimiters2, &context2);
		if (temp_str == NULL) {
			break;
		}
		size_token = 0;
		number_token = 1;
		temp_token = strtok_s(temp_str, delimiters1, &context1);
		token[*num] = (char**)malloc(number_token * sizeof(char*));
		token[*num][size_token] = (char*)malloc(300 * sizeof(char));
	}


	*partner = NULL;
	*partner = (struct marryed*)malloc((*num) * sizeof(struct marryed));
	if (*partner == NULL) {
		// Обробка помилки в разі, якщо realloc не вдалося виділити пам'ять
		printf("Помилка realloc\n");
		exit(EXIT_FAILURE);
	}
	// Information;

	for (int i = 0; i < *num; i++) {
		(*partner)[i].information = (char*)malloc(400 * sizeof(char));
	}
	// Information;
	

	for (int i = 0; i < *num; i++) {
		for (int j = 0; j < number_token; j++) {
			if (j == 0) {
				strcpy((*partner)[i].sex, token[i][j]);
			}
			if (j == 1) {
				strcpy((*partner)[i].dates.month, token[i][j]);
			}
			if (j == 2) {
				strcpy((*partner)[i].information, token[i][j]);
			}
			if (j == 3) {
				strcpy((*partner)[i].requirements.eye, token[i][j]);
			}
			if (j == 4) {
				strcpy((*partner)[i].requirements.hair, token[i][j]);
			}
			if (j == 5) {
				strcpy((*partner)[i].requirements.name, token[i][j]);
			}
			if (j == 6) {
				strcpy((*partner)[i].requirements.face, token[i][j]);
			}
			if (j == 7) {
				strcpy((*partner)[i].requirements.character, token[i][j]);
			}
			if (j == 8) {
				temp_number = atoi(token[i][j]);
				(*partner)[i].number_register = temp_number;
			}
			if (j == 9) {
				temp_number = atoi(token[i][j]);
				(*partner)[i].dates.date = temp_number;
			}
			if (j == 10) {
				temp_number = atoi(token[i][j]);
				(*partner)[i].dates.year = temp_number;
			}
			if (j == 11) {
				temp_number = atoi(token[i][j]);
				(*partner)[i].requirements.hight = temp_number;
			}
			if (j == 12) {
				strcpy((*partner)[i].requirements.goroskop, token[i][j]);
			}
			if (j == 13) {
				strcpy((*partner)[i].requirements.job, token[i][j]);
			}
		}
	}
	free(buffer);
	free(temp_string);
	free(temp_token);
	free(temp_str);

	fclose(file);
}

void fill_str_me(int num_me, struct my_self** me, char* way1) {
	num_me = 0;
	int temp_number;
	char*** token;
	char* context1;
	char* context2;
	context1 = NULL;
	context2 = NULL;
	char delimiters1[] = "#";
	char delimiters2[] = "\n";
	char* temp_token;
	char* temp_str;
	temp_token = NULL;
	temp_str = NULL;
	temp_token = (char*)malloc(300 * sizeof(char));
	temp_str = (char*)malloc(400 * sizeof(char));
	int number_string = (num_me)+1;
	int size_token = 0;
	int number_token = 1;
	int pointer;
	char* buffer;
	buffer = NULL;
	char* temp_string;
	int size_of_string;
	size_of_string = NULL;
	file = fopen(way1, "r+");
	if (file == NULL) {
		perror("Помилка відриття файла!!!\n");
		exit(EXIT_FAILURE);
	}
	fseek(file, 0, SEEK_END);
	pointer = ftell(file) / sizeof(char);
	if (pointer == 0) {
		return;
	}
	rewind(file);
	buffer = (char*)malloc(pointer * sizeof(char));
	temp_string = (char*)malloc(pointer * sizeof(char));
	temp_string[0] = '\0';
	while (fgets(buffer, pointer, file) != NULL) {
		strcat(temp_string, buffer);
	}
	temp_str = strtok_s(temp_string, delimiters2, &context2);
	temp_token = strtok_s(temp_str, delimiters1, &context1);
	token = (char***)malloc(number_string * sizeof(char**));
	token[num_me] = (char**)malloc(number_token * sizeof(char*));
	token[num_me][size_token] = (char*)malloc(500 * sizeof(char));
	while (temp_str != NULL) {
		if (temp_str == NULL) {
			break;
		}
		while (temp_token != NULL) {
			if (temp_token == NULL) {
				break;
			}
			strcpy(token[num_me][size_token], temp_token);
			size_token++;
			number_token++;
			token[num_me] = (char**)realloc(token[num_me], number_token * sizeof(char*));
			token[num_me][size_token] = (char*)malloc(500 * sizeof(char));
			temp_token = strtok_s(NULL, delimiters1, &context1);
		}
		(num_me) += 1;
		number_string++;
		token = (char***)realloc(token, number_string * sizeof(char**));
		temp_str = strtok_s(NULL, delimiters2, &context2);
		if (temp_str == NULL) {
			break;
		}
		size_token = 0;
		number_token = 1;
		temp_token = strtok_s(temp_str, delimiters1, &context1);
		token[num_me] = (char**)malloc(number_token * sizeof(char*));
		token[num_me][size_token] = (char*)malloc(300 * sizeof(char));
	}


	*me = NULL;
	*me = (struct my_self*)malloc(num_me * sizeof(struct my_self));
	if (*me == NULL) {
		// Обробка помилки в разі, якщо realloc не вдалося виділити пам'ять
		printf("Помилка realloc\n");
		exit(EXIT_FAILURE);
	}
	// Information;

	for (int i = 0; i < num_me; i++) {
		(*me)[i].information = (char*)malloc(400 * sizeof(char));
	}
	// Information;


	for (int i = 0; i < num_me; i++) {
		for (int j = 0; j < size_token+1; j++) {
			if (j == 0) {
				strcpy((*me)[i].sex, token[i][j]);
			}
			if (j == 1) {
				strcpy((*me)[i].dates.month, token[i][j]);
			}
			if (j == 2) {
				strcpy((*me)[i].information, token[i][j]);
			}
			if (j == 3) {
				strcpy((*me)[i].requirements.eye, token[i][j]);
			}
			if (j == 4) {
				strcpy((*me)[i].requirements.hair, token[i][j]);
			}
			if (j == 5) {
				strcpy((*me)[i].requirements.name, token[i][j]);
			}
			if (j == 6) {
				strcpy((*me)[i].requirements.face, token[i][j]);
			}
			if (j == 7) {
				strcpy((*me)[i].requirements.character, token[i][j]);
			}
			if (j == 8) {
				temp_number = atoi(token[i][j]);
				(*me)[i].number_register = temp_number;
			}
			if (j == 9) {
				temp_number = atoi(token[i][j]);
				(*me)[i].dates.date = temp_number;
			}
			if (j == 10) {
				temp_number = atoi(token[i][j]);
				(*me)[i].dates.year = temp_number;
			}
			if (j == 11) {
				temp_number = atoi(token[i][j]);
				(*me)[i].requirements.hight = temp_number;
			}
			if (j == 12) {
				strcpy((*me)[i].requirements.goroskop, token[i][j]);
			}
			if (j == 13) {
				strcpy((*me)[i].requirements.job, token[i][j]);
			}
		}
	}
	free(buffer);
	free(temp_string);
	free(temp_token);
	free(temp_str);

	fclose(file);
}

void information(int num, struct marryed** partner) {
	int* number_of_tabs;
	number_of_tabs = (int*)malloc(num * sizeof(int));
	int* len_of_information = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++) {
		len_of_information[i] = strlen((*partner)[i].information);
		if (len_of_information[i] > 25 && len_of_information[i] % 25 != 0) {
			number_of_tabs[i] = len_of_information[i] / 25;
		}
		else if (len_of_information[i] > 25 && len_of_information[i] % 25 == 0) {
			number_of_tabs[i] = (len_of_information[i] / 25) - 1;
		}
	}
	for (int i = 0; i < num; i++) {
		len_of_information[i] = strlen((*partner)[i].information);
	}
	int test_first = 0;
	char add_temp_info[] = "     ";
	char temp_info[400];
	char* context2;
	context2 = NULL;
	char* token2;
	int j;
	int len_to_tab;
	int len_of_token2;
	char* delimiters_info;
	char temp_value_tab;
	int* d;
	int temp_d = 0;
	d = &temp_d;
	int type_element;
	int temp_i;
	int temp_j;
	int* l;
	int temp_l = 0;
	l = &temp_l;
	char* temp_token2;
	int len_of_partner_info;
	temp_token2 = (char*)malloc(25 * sizeof(char));
	int size_of_temp_token2;
	int context2_size;
	for (int i = 0; i < num; i++) {
		for (int t = 0; t < 400; t++) {
			temp_info[t] = '\0';
		}
		test_first = 0;
		temp_d = 0;
		j = 24;
		if (len_of_information[i] <= 25) {
			for (int full_info = 0; full_info < len_of_information[i]; full_info++, (*d)++) {
				temp_info[*d] = (*partner)[i].information[full_info];
			}
			for (int full_info = len_of_information[i]; full_info < 25; full_info++, (*d)++) {
				temp_info[*d] = ' ';
			}
			temp_info[*d] = '|';
			for (int temp_i2 = 0; temp_i2 < len_of_information[i]; temp_i2++) {
				(*partner)[i].information[temp_i2] = '\0';
			}
			(*d)++;
			temp_info[*d] = '\0';
			len_of_partner_info = (*d) + 1;
			(*partner)[i].information = (char*)realloc((*partner)[i].information, len_of_partner_info * sizeof(char));
			for (int h = 0; h < len_of_partner_info; h++) {
				(*partner)[i].information[h] = temp_info[h];
			}
			continue;
		}
		j += 0;
		delimiters_info = (char*)malloc(2 * sizeof(char));
		delimiters_info[0] = (*partner)[i].information[j];
		delimiters_info[1] = '\0';
		token2 = strtok_s((*partner)[i].information, delimiters_info, &context2);
		if (context2[0] == delimiters_info[0]) {
			test_first = 2;
		}
		if (token2 == NULL) {
			break;
		}
		len_of_token2 = strlen(token2);
		if (len_of_token2 != 24) {
			temp_l = 0;
			size_of_temp_token2 = 0;
			while (size_of_temp_token2 != 25) {
				if (token2 == NULL) {
					break;
				}
				for (temp_j = 0; temp_j < len_of_token2; (*l)++, temp_j++) {
					temp_token2[*l] = token2[temp_j];
					size_of_temp_token2++;
				}
				temp_token2[*l] = delimiters_info[0];
				size_of_temp_token2++;
				if (size_of_temp_token2 == 25) {
					break;
				}
				if (context2[0] == delimiters_info[0]) {
					(*l)++;
					temp_token2[*l] = delimiters_info[0];
					size_of_temp_token2++;
				}
				token2 = strtok_s(NULL, delimiters_info, &context2);
				if (token2 == NULL) {
					break;
				}
				len_of_token2 = strlen(token2);
				(*l)++;
			}
			if (test_first != 2) {
				for (temp_i = 0; temp_i < size_of_temp_token2; (*d)++, temp_i++) {
					temp_info[*d] = temp_token2[temp_i];
				}
			}
			else if (test_first == 2) {
				for (temp_i = 0; temp_i < size_of_temp_token2-1; (*d)++, temp_i++) {
					temp_info[*d] = temp_token2[temp_i];
				}
			}
			temp_info[*d] = '|';
			temp_info[(*d) + 1] = '\n';
			(*d) += 6;
			temp_info[(*d) - 4] = '\t';
			temp_info[(*d) - 3] = '|';
			temp_info[(*d) - 2] = '\t';
			temp_info[(*d) - 1] = '\t';
			temp_info[(*d)] = '\t';
			strcat(temp_info, add_temp_info);
			(*d) += 7;
			temp_info[(*d) - 1] = '|';
			temp_info[*d] = '|';
		}
		else {
			for (temp_i = 0; temp_i < len_of_token2 + 1; (*d)++, temp_i++) {
				temp_info[*d] = token2[temp_i];
			}
			temp_info[(*d) - 1] = delimiters_info[0];
			temp_info[*d] = '|';
			temp_info[(*d) + 1] = '\n';
			(*d) += 6;
			temp_info[(*d) - 4] = '\t';
			temp_info[(*d) - 3] = '|';
			temp_info[(*d) - 2] = '\t';
			temp_info[(*d) - 1] = '\t';
			temp_info[(*d)] = '\t';
			strcat(temp_info, add_temp_info);
			(*d) += 7;
			temp_info[(*d) - 1] = '|';
			temp_info[*d] = '|';
		}
		for (int k = 1; k < number_of_tabs[i] + 1; k++) {
			test_first = 0;
			context2_size = strlen(context2);
			if (context2_size <= 25 && context2_size != 0) {
				(*d)++;
				for (int i = 0; i < context2_size; i++) {
					temp_info[*d] = context2[i];
					(*d)++;
				}
				for (int i = 0; i < (25 - context2_size); i++, (*d) += 1) {
					temp_info[*d] = ' ';
				}
				temp_info[*d] = '|';
				break;
			}
			if (token2 == NULL) {
				break;
			}
			(*d)++;
			j += 25;
			delimiters_info[0] = (*partner)[i].information[j];
			delimiters_info[1] = '\0';
			if (context2[0] == delimiters_info[0]) {
				temp_info[*d] = delimiters_info[0];
				(*d)++;
				test_first = 1;
			}
			token2 = strtok_s(NULL, delimiters_info, &context2);
			if (token2 == NULL) {
				break;
			}
			len_of_token2 = strlen(token2);
			if (len_of_token2 != 24) {
				temp_l = 0;
				size_of_temp_token2 = 0;
				if (test_first == 1) {
					size_of_temp_token2++;
				}
				while (size_of_temp_token2 != 25) {
					if (token2 == NULL) {
						break;
					}
					for (temp_j = 0; temp_j < len_of_token2; (*l)++, temp_j++) {
						temp_token2[*l] = token2[temp_j];
						size_of_temp_token2++;
					}
					temp_token2[*l] = delimiters_info[0];
					size_of_temp_token2++;
					if (size_of_temp_token2 == 25) {
						break;
					}
					if (context2[0] == delimiters_info[0]) {
						(*l)++;
						temp_token2[*l] = delimiters_info[0];
						size_of_temp_token2++;
					}
					token2 = strtok_s(NULL, delimiters_info, &context2);
					if (token2 == NULL) {
						break;
					}
					len_of_token2 = strlen(token2);
					(*l)++;
				}
				if (test_first != 1) {
					for (temp_i = 0; temp_i < size_of_temp_token2; (*d)++, temp_i++) {
						temp_info[*d] = temp_token2[temp_i];
					}
				}
				else if (test_first == 1) {
					for (temp_i = 0; temp_i < size_of_temp_token2-1; (*d)++, temp_i++) {
						temp_info[*d] = temp_token2[temp_i];
					}
				}
				temp_info[*d] = '|';
				temp_info[(*d) + 1] = '\n';
				(*d) += 6;
				temp_info[(*d) - 4] = '\t';
				temp_info[(*d) - 3] = '|';
				temp_info[(*d) - 2] = '\t';
				temp_info[(*d) - 1] = '\t';
				temp_info[(*d)] = '\t';
				strcat(temp_info, add_temp_info);
				(*d) += 7;
				temp_info[(*d) - 1] = '|';
				temp_info[*d] = '|';
			}
			else {
				len_of_token2 = strlen(token2) + 1;
				for (temp_i = 0; temp_i < len_of_token2; (*d)++, temp_i++) {
					temp_info[*d] = token2[temp_i];
				}
				temp_info[*d - 1] = delimiters_info[0];
				temp_info[*d] = '|';
				temp_info[(*d) + 1] = '\n';
				(*d) += 6;
				temp_info[(*d) - 4] = '\t';
				temp_info[(*d) - 3] = '|';
				temp_info[(*d) - 2] = '\t';
				temp_info[(*d) - 1] = '\t';
				temp_info[(*d)] = '\t';
				strcat(temp_info, add_temp_info);
				(*d) += 7;
				temp_info[(*d) - 1] = '|';
				temp_info[*d] = '|';
			}
		}

		for (int temp_i2 = 0; temp_i2 < len_of_information[i]; temp_i2++) {
			(*partner)[i].information[temp_i2] = '\0';
		}
		(*d)++;
		temp_info[*d] = '\0';
		len_of_partner_info = (*d) + 1;
		(*partner)[i].information = (char*)realloc((*partner)[i].information, len_of_partner_info * sizeof(char));
		for (int h = 0; h < len_of_partner_info; h++) {
			(*partner)[i].information[h] = temp_info[h];
		}
	}
	/*for (int i = 0; i < num; i++) {
		printf("%s\n", (*partner)[i].information);
	}*/
}

void information_me(int num_me,struct my_self** me) {
	int* number_of_tabs;
	number_of_tabs = (int*)malloc(num_me * sizeof(int));
	int* len_of_information = (int*)malloc(num_me * sizeof(int));
	for (int i = 0; i < num_me; i++) {
		len_of_information[i] = strlen((*me)[i].information);
		if (len_of_information[i] > 25 && len_of_information[i] % 25 != 0) {
			number_of_tabs[i] = len_of_information[i] / 25;
		}
		else if (len_of_information[i] > 25 && len_of_information[i] % 25 == 0) {
			number_of_tabs[i] = (len_of_information[i] / 25) - 1;
		}
	}
	for (int i = 0; i < num_me; i++) {
		len_of_information[i] = strlen((*me)[i].information);
	}
	int test_first = 0;
	char add_temp_info[] = "     ";
	char temp_info[400];
	char* context2;
	context2 = NULL;
	char* token2;
	int j;
	int len_to_tab;
	int len_of_token2;
	char* delimiters_info;
	char temp_value_tab;
	int* d;
	int temp_d = 0;
	d = &temp_d;
	int type_element;
	int temp_i;
	int temp_j;
	int* l;
	int temp_l = 0;
	l = &temp_l;
	char* temp_token2;
	int len_of_partner_info;
	temp_token2 = (char*)malloc(25 * sizeof(char));
	int size_of_temp_token2;
	int context2_size;
	for (int i = 0; i < num_me; i++) {
		for (int t = 0; t < 400; t++) {
			temp_info[t] = '\0';
		}
		test_first = 0;
		temp_d = 0;
		j = 24;
		if (len_of_information[i] <= 25) {
			for (int full_info = 0; full_info < len_of_information[i]; full_info++, (*d)++) {
				temp_info[*d] = (*me)[i].information[full_info];
			}
			for (int full_info = len_of_information[i]; full_info < 25; full_info++, (*d)++) {
				temp_info[*d] = ' ';
			}
			temp_info[*d] = '|';
			for (int temp_i2 = 0; temp_i2 < len_of_information[i]; temp_i2++) {
				(*me)[i].information[temp_i2] = '\0';
			}
			(*d)++;
			temp_info[*d] = '\0';
			len_of_partner_info = (*d) + 1;
			(*me)[i].information = (char*)realloc((*me)[i].information, len_of_partner_info * sizeof(char));
			for (int h = 0; h < len_of_partner_info; h++) {
				(*me)[i].information[h] = temp_info[h];
			}
			continue;
		}
		j += 0;
		delimiters_info = (char*)malloc(2 * sizeof(char));
		delimiters_info[0] = (*me)[i].information[j];
		delimiters_info[1] = '\0';
		token2 = strtok_s((*me)[i].information, delimiters_info, &context2);
		if (context2[0] == delimiters_info[0]) {
			test_first = 2;
		}
		if (token2 == NULL) {
			break;
		}
		len_of_token2 = strlen(token2);
		if (len_of_token2 != 24) {
			temp_l = 0;
			size_of_temp_token2 = 0;
			while (size_of_temp_token2 != 25) {
				if (token2 == NULL) {
					break;
				}
				for (temp_j = 0; temp_j < len_of_token2; (*l)++, temp_j++) {
					temp_token2[*l] = token2[temp_j];
					size_of_temp_token2++;
				}
				temp_token2[*l] = delimiters_info[0];
				size_of_temp_token2++;
				if (size_of_temp_token2 == 25) {
					break;
				}
				if (context2[0] == delimiters_info[0]) {
					(*l)++;
					temp_token2[*l] = delimiters_info[0];
					size_of_temp_token2++;
				}
				token2 = strtok_s(NULL, delimiters_info, &context2);
				if (token2 == NULL) {
					break;
				}
				len_of_token2 = strlen(token2);
				(*l)++;
			}
			if (test_first != 2) {
				for (temp_i = 0; temp_i < size_of_temp_token2; (*d)++, temp_i++) {
					temp_info[*d] = temp_token2[temp_i];
				}
			}
			else if (test_first == 2) {
				for (temp_i = 0; temp_i < size_of_temp_token2 - 1; (*d)++, temp_i++) {
					temp_info[*d] = temp_token2[temp_i];
				}
			}
			temp_info[*d] = '|';
			temp_info[(*d) + 1] = '\n';
			(*d) += 6;
			temp_info[(*d) - 4] = '\t';
			temp_info[(*d) - 3] = '|';
			temp_info[(*d) - 2] = '\t';
			temp_info[(*d) - 1] = '\t';
			temp_info[(*d)] = '\t';
			strcat(temp_info, add_temp_info);
			(*d) += 7;
			temp_info[(*d) - 1] = '|';
			temp_info[*d] = '|';
		}
		else {
			for (temp_i = 0; temp_i < len_of_token2 + 1; (*d)++, temp_i++) {
				temp_info[*d] = token2[temp_i];
			}
			temp_info[(*d) - 1] = delimiters_info[0];
			temp_info[*d] = '|';
			temp_info[(*d) + 1] = '\n';
			(*d) += 6;
			temp_info[(*d) - 4] = '\t';
			temp_info[(*d) - 3] = '|';
			temp_info[(*d) - 2] = '\t';
			temp_info[(*d) - 1] = '\t';
			temp_info[(*d)] = '\t';
			strcat(temp_info, add_temp_info);
			(*d) += 7;
			temp_info[(*d) - 1] = '|';
			temp_info[*d] = '|';
		}
		for (int k = 1; k < number_of_tabs[i] + 1; k++) {
			test_first = 0;
			context2_size = strlen(context2);
			if (context2_size <= 25 && context2_size != 0) {
				(*d)++;
				for (int i = 0; i < context2_size; i++) {
					temp_info[*d] = context2[i];
					(*d)++;
				}
				for (int i = 0; i < (25 - context2_size); i++, (*d) += 1) {
					temp_info[*d] = ' ';
				}
				temp_info[*d] = '|';
				break;
			}
			if (token2 == NULL) {
				break;
			}
			(*d)++;
			j += 25;
			delimiters_info[0] = (*me)[i].information[j];
			delimiters_info[1] = '\0';
			if (context2[0] == delimiters_info[0]) {
				temp_info[*d] = delimiters_info[0];
				(*d)++;
				test_first = 1;
			}
			token2 = strtok_s(NULL, delimiters_info, &context2);
			if (token2 == NULL) {
				break;
			}
			len_of_token2 = strlen(token2);
			if (len_of_token2 != 24) {
				temp_l = 0;
				size_of_temp_token2 = 0;
				if (test_first == 1) {
					size_of_temp_token2++;
				}
				while (size_of_temp_token2 != 25) {
					if (token2 == NULL) {
						break;
					}
					for (temp_j = 0; temp_j < len_of_token2; (*l)++, temp_j++) {
						temp_token2[*l] = token2[temp_j];
						size_of_temp_token2++;
					}
					temp_token2[*l] = delimiters_info[0];
					size_of_temp_token2++;
					if (size_of_temp_token2 == 25) {
						break;
					}
					if (context2[0] == delimiters_info[0]) {
						(*l)++;
						temp_token2[*l] = delimiters_info[0];
						size_of_temp_token2++;
					}
					token2 = strtok_s(NULL, delimiters_info, &context2);
					if (token2 == NULL) {
						break;
					}
					len_of_token2 = strlen(token2);
					(*l)++;
				}
				if (test_first != 1) {
					for (temp_i = 0; temp_i < size_of_temp_token2; (*d)++, temp_i++) {
						temp_info[*d] = temp_token2[temp_i];
					}
				}
				else if (test_first == 1) {
					for (temp_i = 0; temp_i < size_of_temp_token2 - 1; (*d)++, temp_i++) {
						temp_info[*d] = temp_token2[temp_i];
					}
				}
				temp_info[*d] = '|';
				temp_info[(*d) + 1] = '\n';
				(*d) += 6;
				temp_info[(*d) - 4] = '\t';
				temp_info[(*d) - 3] = '|';
				temp_info[(*d) - 2] = '\t';
				temp_info[(*d) - 1] = '\t';
				temp_info[(*d)] = '\t';
				strcat(temp_info, add_temp_info);
				(*d) += 7;
				temp_info[(*d) - 1] = '|';
				temp_info[*d] = '|';
			}
			else {
				len_of_token2 = strlen(token2) + 1;
				for (temp_i = 0; temp_i < len_of_token2; (*d)++, temp_i++) {
					temp_info[*d] = token2[temp_i];
				}
				temp_info[*d - 1] = delimiters_info[0];
				temp_info[*d] = '|';
				temp_info[(*d) + 1] = '\n';
				(*d) += 6;
				temp_info[(*d) - 4] = '\t';
				temp_info[(*d) - 3] = '|';
				temp_info[(*d) - 2] = '\t';
				temp_info[(*d) - 1] = '\t';
				temp_info[(*d)] = '\t';
				strcat(temp_info, add_temp_info);
				(*d) += 7;
				temp_info[(*d) - 1] = '|';
				temp_info[*d] = '|';
			}
		}

		for (int temp_i2 = 0; temp_i2 < len_of_information[i]; temp_i2++) {
			(*me)[i].information[temp_i2] = '\0';
		}
		(*d)++;
		temp_info[*d] = '\0';
		len_of_partner_info = (*d) + 1;
		(*me)[i].information = (char*)realloc((*me)[i].information, len_of_partner_info * sizeof(char));
		for (int h = 0; h < len_of_partner_info; h++) {
			(*me)[i].information[h] = temp_info[h];
		}
	}
}

void input1(int num, struct marryed* partner,char* way) {
	char* sex;
	sex = NULL;
	sex = (char*)malloc(20 * sizeof(char));
	int number_register;
	int dates_date;
	char* dates_month;
	dates_month = NULL;
	dates_month = (char*)malloc(20 * sizeof(char));
	int dates_year;
	char* information;
	information = NULL;
	information = (char*)malloc(300 * sizeof(char));
	char* eye;
	eye = NULL;
	eye = (char*)malloc(20 * sizeof(char));
	int hight;
	char* hair;
	hair = NULL;
	hair = (char*)malloc(20 * sizeof(char));
	char* name;
	name = NULL;
	name = (char*)malloc(20 * sizeof(char));
	char* face;
	face = NULL;
	face = (char*)malloc(20 * sizeof(char));
	char* character;
	character = NULL;
	character = (char*)malloc(20 * sizeof(char));
	char* goroskop;
	goroskop = NULL;
	goroskop = (char*)malloc(30 * sizeof(char));
	char* job;
	job = NULL;
	job = (char*)malloc(30 * sizeof(char));
	char* newpoint;
	file = fopen(way, "a+");
	if (file == NULL) {
		perror("Помилка відриття файла!!!\n");
		exit(EXIT_FAILURE);
	}
	printf("Введіть стать для кандидата : "); fgets(sex, 20, stdin);
	newpoint = strchr(sex, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	number_register = rand() % ((10000000 - 1000000) + 1) + 1000000;
	printf("Введіть дату народження (число) кандидата : "); scanf_s("%d", &dates_date);
	while (getchar() != '\n');
	printf("Введіть місяць народження для кандидата : "); fgets(dates_month, 20, stdin);
	newpoint = strchr(dates_month, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Введіть рік народження для кандидата : "); scanf_s("%d", &dates_year);
	while (getchar() != '\n');
	printf("Введіть колір очей кандидата : "); fgets(eye, 20, stdin);
	newpoint = strchr(eye, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Ріст кандидата : "); scanf_s("%d", &hight);
	while (getchar() != '\n');
	printf("Введіть колір волося кандидата : "); fgets(hair, 20, stdin);
	newpoint = strchr(hair, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Введіть ім'я кандидата : "); fgets(name, 20, stdin);
	newpoint = strchr(name, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Введіть тип лиця кандидата : "); fgets(face, 20, stdin);
	newpoint = strchr(face, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Введіть характер кандидата : "); fgets(character, 20, stdin);
	newpoint = strchr(character, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Введіть гороскоп для кандидата : "); fgets(goroskop, 30, stdin);
	newpoint = strchr(goroskop, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Введіть місце роботи кандидата : "); fgets(job, 100, stdin);
	newpoint = strchr(job, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Введіть інформацію про кандидата : "); fgets(information, 300, stdin);
	newpoint = strchr(information, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	fprintf(file, "%s#", sex);
	fprintf(file, "%s#", dates_month);
	fprintf(file, "%s#", information);
	fprintf(file, "%s#", eye);
	fprintf(file, "%s#", hair);
	fprintf(file, "%s#", name);
	fprintf(file, "%s#", face);
	fprintf(file, "%s#", character);
	fprintf(file, "%d#", number_register);
	fprintf(file, "%d#", dates_date);
	fprintf(file, "%d#", dates_year);
	fprintf(file, "%d#", hight);
	fprintf(file, "%s#", goroskop);
	fprintf(file, "%s#", job);
	fprintf(file, "%s", "\n");
	fflush(file);
	fclose(file);
}

void input1_myself(struct my_self* me, char* way1) {
	char* sex;
	sex = NULL;
	sex = (char*)malloc(20 * sizeof(char));
	int number_register;
	int dates_date;
	char* dates_month;
	dates_month = NULL;
	dates_month = (char*)malloc(20 * sizeof(char));
	int dates_year;
	char* information;
	information = NULL;
	information = (char*)malloc(300 * sizeof(char));
	char* eye;
	eye = NULL;
	eye = (char*)malloc(20 * sizeof(char));
	int hight;
	char* hair;
	hair = NULL;
	hair = (char*)malloc(20 * sizeof(char));
	char* name;
	name = NULL;
	name = (char*)malloc(20 * sizeof(char));
	char* face;
	face = NULL;
	face = (char*)malloc(20 * sizeof(char));
	char* character;
	character = NULL;
	character = (char*)malloc(20 * sizeof(char));
	char* goroskop;
	goroskop = NULL;
	goroskop = (char*)malloc(30 * sizeof(char));
	char* job;
	job = NULL;
	job = (char*)malloc(30 * sizeof(char));
	char* newpoint;
	file = fopen(way1, "w");
	if (file == NULL) {
		perror("Помилка відриття файла!!!\n");
		exit(EXIT_FAILURE);
	}
	printf("Введіть свою стать : "); fgets(sex, 20, stdin);
	newpoint = strchr(sex, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	number_register = rand() % ((10000000 - 1000000) + 1) + 1000000;
	printf("Введіть свою дату народження (число) : "); scanf_s("%d", &dates_date);
	while (getchar() != '\n');
	printf("Введіть свій місяць народження : "); fgets(dates_month, 20, stdin);
	newpoint = strchr(dates_month, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Введіть свій рік народження : "); scanf_s("%d", &dates_year);
	while (getchar() != '\n');
	printf("Введіть свій колір очей : "); fgets(eye, 20, stdin);
	newpoint = strchr(eye, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Введіть свій ріст : "); scanf_s("%d", &hight);
	while (getchar() != '\n');
	printf("Введіть свій колір волося : "); fgets(hair, 20, stdin);
	newpoint = strchr(hair, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Введіть своє ім'я : "); fgets(name, 20, stdin);
	newpoint = strchr(name, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Введіть свій тип лиця : "); fgets(face, 20, stdin);
	newpoint = strchr(face, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Введіть свій характер : "); fgets(character, 20, stdin);
	newpoint = strchr(character, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Введіть свій гороскоп : "); fgets(goroskop, 30, stdin);
	newpoint = strchr(goroskop, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Введіть своє місце роботи : "); fgets(job, 100, stdin);
	newpoint = strchr(job, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	printf("Введіть свою інформацію : "); fgets(information, 300, stdin);
	newpoint = strchr(information, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	fprintf(file, "%s#", sex);
	fprintf(file, "%s#", dates_month);
	fprintf(file, "%s#", information);
	fprintf(file, "%s#", eye);
	fprintf(file, "%s#", hair);
	fprintf(file, "%s#", name);
	fprintf(file, "%s#", face);
	fprintf(file, "%s#", character);
	fprintf(file, "%d#", number_register);
	fprintf(file, "%d#", dates_date);
	fprintf(file, "%d#", dates_year);
	fprintf(file, "%d#", hight);
	fprintf(file, "%s#", goroskop);
	fprintf(file, "%s#", job);
	fprintf(file, "%s", "\n");
	fflush(file);
	fclose(file);
}

void find(int num, struct marryed* partner,char* partner_sex,char* partner_eye,int partner_hight,char* partner_hair,char* partner_name,char* partner_face,char* partner_character,int** index_of_needless_partners,char* partner_goroskop,char* partner_job) {
	char* test_sex;
	test_sex = NULL;
	test_sex = (char*)malloc(40 * sizeof(char));
	char* newpoint;
	char* action;
	action = (char*)malloc(20 * sizeof(char));
	int x;
	printf("\t\t _____________________________________________________________________________________________\n");
	printf("\t\t|Введіть, які ви хочете параметри для свого партнера і ми вам підберемо ідеального партнера!!!|\n");
	printf("\t\t|_____________________________________________________________________________________________|\n");
	char** menu_punkt;
	char** menu_num;
	menu_punkt = NULL;
	menu_num = NULL;
	menu_num = (char**)malloc(9 * sizeof(char*));
	for (int i = 0; i < 9; i++) {
		menu_num[i] = (char*)malloc(200 * sizeof(char));
		if (i == 0) {
			strcpy(menu_num[i], "(1) - стать партнера;");
		}
		if (i == 1) {
			strcpy(menu_num[i], "(2) - колір очей;");
		}
		if (i == 2) {
			strcpy(menu_num[i], "(3) - ріст партнера;");
		}
		if (i == 3) {
			strcpy(menu_num[i], "(4) - колір волос'я;");
		}
		if (i == 4) {
			strcpy(menu_num[i], "(5) - ім'я партнера;");
		}
		if (i == 5) {
			strcpy(menu_num[i], "(6) - тип лиця;");
		}
		if (i == 6) {
			strcpy(menu_num[i], "(7) - характер партнера;");
		}
		if (i == 7) {
			strcpy(menu_num[i], "(8) - гороскоп партнера;");
		}
		if (i == 8) {
			strcpy(menu_num[i], "(9) - Місце роботи партнера;");
		}

	}
	menu_punkt = (char**)malloc(9 * sizeof(char*));
	for (int i = 0; i < 9; i++) {
		menu_punkt[i] = (char*)malloc(200 * sizeof(char));
		strcpy(menu_punkt[i], menu_num[i]);
	}
	printf("\t\t\t ______________________________________\n");
	printf("\t\t\t|____________Search_Partner____________|\n");
	printf("\t\t\t|       %-31s|\n", menu_punkt[0]);
	printf("\t\t\t|______________________________________|\n");
	printf("\t\t\t|       %-31s|\n", menu_punkt[1]);
	printf("\t\t\t|______________________________________|\n");
	printf("\t\t\t|       %-31s|\n", menu_punkt[2]);
	printf("\t\t\t|______________________________________|\n");
	printf("\t\t\t|       %-31s|\n", menu_punkt[3]);
	printf("\t\t\t|______________________________________|\n");
	printf("\t\t\t|       %-31s|\n", menu_punkt[4]);
	printf("\t\t\t|______________________________________|\n");
	printf("\t\t\t|       %-31s|\n", menu_punkt[5]);
	printf("\t\t\t|______________________________________|\n");
	printf("\t\t\t|%31s       |\n", menu_punkt[6]);
	printf("\t\t\t|______________________________________|\n");
	printf("\t\t\t|%31s       |\n", menu_punkt[7]);
	printf("\t\t\t|______________________________________|\n");
	printf("\t\t\t|%31s       |\n", menu_punkt[8]);
	printf("\t\t\t|______________________________________|\n");

	int test_of_right = 0;
	do {
		do {
			printf("\t\t\t  Введіть дію(0 - закінчити!!!): ");
			scanf_s("%d", &x);
			while (getchar() != '\n');
			switch (x) {
				case 1: {
					printf("\t\t\t  Введіть стань партнера : "); fgets(partner_sex, 40, stdin);
					newpoint = strchr(partner_sex, '\n');
					if (newpoint != NULL) {
						*newpoint = '\0';
					}
					test_of_right = 1;
					strcpy(test_sex, partner_sex);
					break;
				}
				case 2: {
					printf("\t\t\t  Введіть колір очей партнера : "); fgets(partner_eye, 40, stdin);
					newpoint = strchr(partner_eye, '\n');
					if (newpoint != NULL) {
						*newpoint = '\0';
					}
					test_of_right = 1;
					break;
				}
				case 3: {
					printf("\t\t\t  Введіть ріст партнера,який вам найбільше підходить : "); scanf_s("%d", &partner_hight);
					while (getchar() != '\n');
					test_of_right = 1;
					break;
				}
				case 4: {
					printf("\t\t\t  Введіть колір волос`я партнера : "); fgets(partner_hair, 40, stdin);
					newpoint = strchr(partner_hair, '\n');
					if (newpoint != NULL) {
						*newpoint = '\0';
					}
					test_of_right = 1;
					break;
				}
				case 5: {
					printf("\t\t\t  Введіть ім'я партнера,яке вам найбільше імпонує : "); fgets(partner_name, 40, stdin);
					newpoint = strchr(partner_name, '\n');
					if (newpoint != NULL) {
						*newpoint = '\0';
					}
					test_of_right = 1;
					break;
				}
				case 6: {
					printf("\t\t\t  Введіть тип лиця партнера,який вам найбільше імпонує : "); fgets(partner_face, 40, stdin);
					newpoint = strchr(partner_face, '\n');
					if (newpoint != NULL) {
						*newpoint = '\0';
					}
					test_of_right = 1;
					break;
				}
				case 7: {
					printf("\t\t\t  Введіть характер партнера,який вам найбільше імпонує : "); fgets(partner_character, 40, stdin);
					newpoint = strchr(partner_character, '\n');
					if (newpoint != NULL) {
						*newpoint = '\0';
					}
					test_of_right = 1;
					break;
				}
				case 8: {
					printf("\t\t\t  Введіть гороскоп для свого кандидата : "); fgets(partner_goroskop, 40, stdin);
					newpoint = strchr(partner_goroskop, '\n');
					if (newpoint != NULL) {
						*newpoint = '\0';
					}
					test_of_right = 1;
					break;
				}
				case 9: {
					printf("\t\t\t  Введіть міце роботи для вашого кандидата : "); fgets(partner_job, 40, stdin);
					newpoint = strchr(partner_job, '\n');
					if (newpoint != NULL) {
						*newpoint = '\0';
					}
					test_of_right = 1;
					break;
				}
			}
		} while (x!=0);
		printf("\t\t\t  Continue to using this search menu('n' to end!!!) : "); fgets(action, 40, stdin);
		newpoint = strchr(action, '\n');
		if (newpoint != NULL) {
			*newpoint = '\0';
		}
	} while (strcmp(action, "n") != 0);
	if (test_of_right == 0) {
		printf(" ____________________________________________________________________________________________________\n");
		printf("|                                                                                                    |\n");
		printf("|            Вибачте (ERROR!!!) ви не ввели щодної характеристи для вашого партнера!!!               |\n");
		printf("|____________________________________________________________________________________________________|\n");
		return;
	}
	int* temp_index_of_needless_partners;
	temp_index_of_needless_partners = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++) {
		temp_index_of_needless_partners[i] = 0;
	}
	find_candidat(num, partner, partner_sex, partner_eye, partner_hight, partner_hair, partner_name, partner_face, partner_character, &temp_index_of_needless_partners,partner_goroskop,partner_job,test_sex);
	for (int i = 0; i < num; i++) {
		(*index_of_needless_partners)[i] = (temp_index_of_needless_partners[i]);
	}
}

void find_candidat(int num, struct marryed* partner, char* partner_sex, char* partner_eye, int partner_hight, char* partner_hair, char* partner_name, char* partner_face, char* partner_character, int** temp_index_of_needless_partners,char* partner_goroskop,char* partner_job,char* test_sex) {
		int* number_of_same;
		number_of_same = NULL;
		number_of_same = (int*)malloc(num * sizeof(int));
		for (int i = 0; i < num; i++) {
			number_of_same[i] = 0;
		}
		for (int i = 0; i < num; i++) {
			if (strcmp(partner[i].sex, partner_sex) == 0 && partner_sex != NULL) {
				number_of_same[i]++;
			}
			if (strcmp(partner[i].requirements.eye, partner_eye) == 0 && partner_eye != NULL) {
				number_of_same[i]++;
			}
			if (partner[i].requirements.hight == partner_hight && partner_hight != NULL) {
				number_of_same[i]++;
			}
			if (strcmp(partner[i].requirements.hair, partner_hair) == 0 && partner_hair != NULL) {
				number_of_same[i]++;
			}
			if (strcmp(partner[i].requirements.name, partner_name) == 0 && partner_name != NULL) {
				number_of_same[i]++;
			}
			if (strcmp(partner[i].requirements.face, partner_face) == 0 && partner_face != NULL) {
				number_of_same[i]++;
			}
			if (strcmp(partner[i].requirements.character, partner_character) == 0 && partner_character != NULL) {
				number_of_same[i]++;
			}
			if (strcmp(partner[i].requirements.goroskop, partner_goroskop) == 0 && partner_goroskop != NULL) {
				number_of_same[i]++;
			}
			if (strcmp(partner[i].requirements.job, partner_job) == 0 && partner_job != NULL) {
				number_of_same[i]++;
			}
		}
		/*for (int i = 0; i < num; i++) {
			printf("|%d|\n", number_of_same[i]);
		}*/
		int max = 0;
		for (int i = 0; i < num; i++) {
			if (number_of_same[i] > number_of_same[max]) {
				max = i;
			}
			else if (number_of_same[i] == number_of_same[max] && number_of_same[i] != 0) {
				max = i;
			}
			else {
				continue;
			}
		}
		for (int i = 0; i < num; i++) {
			if (number_of_same[i] == number_of_same[max]&&strcmp(partner[i].sex,test_sex)==0) {
				(*temp_index_of_needless_partners)[i] = partner[i].number_register;
			}
			else {
				continue;
			}
		}
}

void choose_one(int num, struct marryed* partner, int** index_of_needless_partners) {
	char* newpoint;
	int test_size_partner = 0;
	int number_choosen = 0;
	char* choose;
	choose = NULL;
	choose = (char*)malloc(10 * sizeof(char));
	for (int i = 0; i < num; i++) {
		if ((*index_of_needless_partners)[i] != 0) {
			test_size_partner++;
		}
		else {
			continue;
		}
	}
	if (test_size_partner > 1) {
		printf("\t\tЧи ви хочете вибрати одного з цих кандидатів (так чи ні) : "); fgets(choose, 10, stdin);
		newpoint = strchr(choose, '\n');
		if (newpoint != NULL) {
			*newpoint = '\0';
		}
		if (strcmp(choose, "так") == 0) {
			printf("\t\t _______________________________________________________ \n");
			printf("\t\t|                                                       |\n");
			printf("\t\t|Виберіть одного кандидата,який вам найбільше сподобався|\n");
			printf("\t\t|________________(Введіть номер кандидата)______________|\n");
			printf("\t\tВведіть : "); scanf_s("%d", &number_choosen);
			number_choosen -= 1;
		}
		else if (strcmp(choose, "ні") == 0) {
			return;
		}
	}
	else if (test_size_partner == 1) {
		return;
	}
	int* partner_register;
	partner_register = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++) {
		partner_register[i] = partner[i].number_register;
	}
	for (int i = 0; i < num; i++) {
		(*index_of_needless_partners)[i] = 0;
	}
	for (int i = 0; i < num; i++) {
			if (partner[i].requirements.name == partner[number_choosen].requirements.name) {
				continue;
			}
			partner[i].number_register = 0;
	}
	for (int i = 0; i < num; i++) {
		if (partner[i].number_register == 0) {
			partner[i].number_register = partner_register[i];
			continue;
		}
		else {
			(*index_of_needless_partners)[i]=partner[i].number_register;
		}
	}
}

void menu1(int num, struct marryed* partner,char** token_menu,char** token_month,char* way,int number_of_month,struct my_self* me,int num_me,char* way1,char* way2,int num_cou,struct couple** archive,int num_del_cou,struct delete_couple** delete_archive,char* way3) {
	int* index_to_indeficate_delete_partner;
	index_to_indeficate_delete_partner = NULL;
	index_to_indeficate_delete_partner = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++) {
		index_to_indeficate_delete_partner[i] = 0;
	}
	int test_of_number_delete_partner = 0;
	int test_enter9 = 0;
	char* partner_sex;
	char* partner_eye;
	int partner_hight;
	char* partner_hair;
	char* partner_name;
	char* partner_face;
	char* partner_character;
	char* partner_goroskop;
	char* partner_job;
	char* action;
	action = (char*)malloc(20 * sizeof(char));
	char* newpoint;
	int choose_menu;
	int test_succesfull;
	int* index_of_needless_partners;
	index_of_needless_partners = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++) {
		index_of_needless_partners[i] = NULL;
	}
	do {
		char** menu_punkt;
		char** menu_num;
		menu_punkt = NULL;
		menu_num = NULL;
		menu_num = (char**)malloc(11 * sizeof(char*));
		for (int i = 0; i < 11; i++) {
			menu_num[i] = (char*)malloc(200 * sizeof(char));
			if (i == 0) {
				strcpy(menu_num[i], "(1) - Знайти накращого кандидата на місце нареченого;");
			}
			if (i == 1) {
				strcpy(menu_num[i], "(2) - Показати нашого партнера, який нам найбільше підходить;");
			}
			if (i == 2) {
				strcpy(menu_num[i], "(3) - Добавити кандидата в базу даних;");
			}
			if (i == 3) {
				strcpy(menu_num[i], "(4) - Показати всіх кандидатів;");
			}
			if (i == 4) {
				strcpy(menu_num[i], "(5) - Сортувати всі знайдений кандидатів за параметрами;");
			}
			if (i == 5) {
				strcpy(menu_num[i], "(6) - Видалення кандидата з бази даних;");
			}
			if (i == 6) {
				strcpy(menu_num[i], "(7) - Заповнити свою анкету;");
			}
			if (i == 7) {
				strcpy(menu_num[i], "(8) - Показати нашу пару та зробити рішення;");
			}
			if (i == 8) {
				strcpy(menu_num[i], "(9) - Вивести архів пар;");
			}
			if (i == 9) {
				strcpy(menu_num[i], "(10) - Видалити пару з архіва;");
			}
			if (i == 10) {
				strcpy(menu_num[i], "(11) - Вивести резервний архів з видаленими парами;");
			}

		}
		menu_punkt = (char**)malloc(11 * sizeof(char*));
		for (int i = 0; i < 11; i++) {
			menu_punkt[i] = (char*)malloc(200 * sizeof(char));
			strcpy(menu_punkt[i], menu_num[i]);
		}
		printf("\t\t _________________________________________________________________ \n");
		printf("\t\t|_________________________|M|E|N|U|_______________________________|\n");
		printf("\t\t|    %-61s|\n",menu_punkt[0]);
		printf("\t\t|_________________________________________________________________|\n");
		printf("\t\t|%65s|\n",menu_punkt[1]);
		printf("\t\t|_________________________________________________________________|\n");
		printf("\t\t|    %-61s|\n",menu_punkt[2]);
		printf("\t\t|_________________________________________________________________|\n");
		printf("\t\t|    %-61s|\n",menu_punkt[3]);
		printf("\t\t|_________________________________________________________________|\n");
		printf("\t\t|    %-61s|\n",menu_punkt[4]);
		printf("\t\t|_________________________________________________________________|\n");
		printf("\t\t|    %-61s|\n",menu_punkt[5]);
		printf("\t\t|_________________________________________________________________|\n");
		printf("\t\t|    %-61s|\n",menu_punkt[6]);
		printf("\t\t|_________________________________________________________________|\n");
		printf("\t\t|    %-61s|\n",menu_punkt[7]);
		printf("\t\t|_________________________________________________________________|\n");
		printf("\t\t|    %-61s|\n",menu_punkt[8]);
		printf("\t\t|_________________________________________________________________|\n");
		printf("\t\t|    %-61s|\n",menu_punkt[9]);
		printf("\t\t|_________________________________________________________________|\n");
		printf("\t\t|    %-61s|\n",menu_punkt[10]);
		printf("\t\t|_________________________________________________________________|\n");

		printf("\t\t\t\tВведіть : "); scanf_s("%d", &choose_menu);
		while (getchar() != '\n');
		if (choose_menu == 0) {
			return;
		}
		switch (choose_menu) {
			case 1: {
				for (int i = 0; i < num; i++) {
					index_of_needless_partners[i] = NULL;
				}
				partner_sex = NULL;
				partner_sex = (char*)malloc(10 * sizeof(char));
				partner_eye = NULL;
				partner_eye = (char*)malloc(10 * sizeof(char));
				partner_hight = NULL;			
				partner_hair = NULL;
				partner_hair = (char*)malloc(15 * sizeof(char));				
				partner_name = NULL;
				partner_name = (char*)malloc(15 * sizeof(char));
				partner_face = NULL;
				partner_face = (char*)malloc(10 * sizeof(char));
				partner_character = NULL;
				partner_character = (char*)malloc(250 * sizeof(char));
				partner_goroskop = NULL;
				partner_goroskop = (char*)malloc(40 * sizeof(char));
				partner_job = NULL;
				partner_job = (char*)malloc(100 * sizeof(char));
				find(num, partner, partner_sex, partner_eye, partner_hight, partner_hair, partner_name, partner_face, partner_character,&index_of_needless_partners,partner_goroskop,partner_job);
				while (getchar() != '\n');
				break;
			}
			case 2: {
				output_finded(num,partner,index_of_needless_partners,token_menu);
				while (getchar() != '\n');
				choose_one(num, partner, &index_of_needless_partners);
				break;
			}
			case 3: {
				input1(num, partner,way);
				fill_str(&num, &partner, way);
				index_of_needless_partners[num - 1] = 0;
				//information(num, &partner);
				break;
			}
			case 4: {
				output_all(num, partner, token_menu,index_of_needless_partners);
				//while (getchar() != '\n');
				break;
			}
			case 5: {
				char** menu_punkt;
				char** menu_num;
				menu_punkt = NULL;
				menu_num = NULL;
				menu_num = (char**)malloc(2 * sizeof(char*));
				for (int i = 0; i < 2; i++) {
					menu_num[i] = (char*)malloc(200 * sizeof(char));
					if (i == 0) {
						strcpy(menu_num[i], "(1) - за датою народження;");
					}
					if (i == 1) {
						strcpy(menu_num[i], "(2) - за ростом;");
					}
				}
				menu_punkt = (char**)malloc(2 * sizeof(char*));
				for (int i = 0; i < 2; i++) {
					menu_punkt[i] = (char*)malloc(200 * sizeof(char));
					strcpy(menu_punkt[i], menu_num[i]);
				}
				int test;
				int type_sort;
				do {
					printf("\t\t\t\t ____________________________________\n");
					printf("\t\t\t\t|_____________СОРТУВАННЯ_____________|\n");
					printf("\t\t\t\t|%36s|\n",menu_punkt[0]);
					printf("\t\t\t\t|____________________________________|\n");
					printf("\t\t\t\t|          %-26s|\n",menu_punkt[1]);
					printf("\t\t\t\t|____________________________________|\n");
					printf("\t\t\t\tВведіть тип сортування (0 - вийти!!!): ");
					scanf_s("%d", &type_sort);
					if (type_sort == 0) {
						printf("\t\t __________________________________________________________________\n");
						printf("\t\t|<-------^------->Роботу з сортуванням закінено!!!<-------^------->|\n");
						printf("\t\t|__________________________________________________________________|\n");
						while (getchar() != '\n');
						break;
					}
					while (getchar() != '\n');
					sort(num, partner, &index_of_needless_partners, type_sort,&test,token_month,number_of_month);
					fill_str(&num, &partner, way);
					//information(num, &partner);
				} while (test == 1);
				break;
			}
			case 6: {
				char* action_del;
				action_del = NULL;
				action_del = (char*)malloc(10 * sizeof(char));
				menu_punkt = NULL;
				menu_num = NULL;
				menu_num = (char**)malloc(7 * sizeof(char*));
				for (int i = 0; i < 7; i++) {
					menu_num[i] = (char*)malloc(200 * sizeof(char));
					if (i == 0) {
						strcpy(menu_num[i], "Знайти партнера якого ви хочете видалити з бази даних(за параметрами)!;");
					}
					if (i == 1) {
						strcpy(menu_num[i], "(1) - за Ім'ям;");
					}
					if (i == 2) {
						strcpy(menu_num[i], "(2) - за датою народження;(Пр: 28.01.2006)!!!");
					}
					if (i == 3) {
						strcpy(menu_num[i], "(3) - за статю;");
					}
					if (i == 4) {
						strcpy(menu_num[i], "(4) - за кольором очей;");
					}
					if (i == 5) {
						strcpy(menu_num[i], "(5) - за кольором волося;");
					}
					if (i == 6) {
						strcpy(menu_num[i], "(6) - за ростом;");
					}

				}
				menu_punkt = (char**)malloc(7 * sizeof(char*));
				for (int i = 0; i < 7; i++) {
					menu_punkt[i] = (char*)malloc(200 * sizeof(char));
					strcpy(menu_punkt[i], menu_num[i]);
				}
				int index_delete;
				char* del_name;
				
				char* del_dates;
				
				char* del_sex;
				
				char* del_eye;
				
				char* del_hair;
				
				int del_hight;
				
				do {
					del_name = NULL;
					del_name = (char*)malloc(40 * sizeof(char));
					int test_name = 0;
					del_dates = NULL;
					del_dates = (char*)malloc(40 * sizeof(char));
					int test_dates = 0;
					del_sex = NULL;
					del_sex = (char*)malloc(40 * sizeof(char));
					int test_sex = 0;
					del_eye = NULL;
					del_eye = (char*)malloc(40 * sizeof(char));
					int test_eye = 0;
					del_hair = NULL;
					del_hair = (char*)malloc(40 * sizeof(char));
					int test_hair = 0;
					del_hight = 0;
					int test_hight = 0;
					printf("\t\t _______________________________________________________________________\n");
					printf("\t\t|_____________________|D|E|L|E|T|E|_|P|A|R|T|N|E|R|_____________________|\n");
					printf("\t\t|%71s|\n", menu_punkt[0]);
					printf("\t\t|_______________________________________________________________________|\n");
					printf("\t\t|                    %-51s|\n", menu_punkt[1]);
					printf("\t\t|_______________________________________________________________________|\n");
					printf("\t\t|                    %-51s|\n", menu_punkt[2]);
					printf("\t\t|_______________________________________________________________________|\n");
					printf("\t\t|                    %-51s|\n", menu_punkt[3]);
					printf("\t\t|_______________________________________________________________________|\n");
					printf("\t\t|                    %-51s|\n", menu_punkt[4]);
					printf("\t\t|_______________________________________________________________________|\n");
					printf("\t\t|                    %-51s|\n", menu_punkt[5]);
					printf("\t\t|_______________________________________________________________________|\n");
					printf("\t\t|                    %-51s|\n", menu_punkt[6]);
					printf("\t\t|_______________________________________________________________________|\n");
					do {
						printf("\t\t\tВведіть значення(0 - закінчити введення!!!) : "); scanf_s("%d", &index_delete);
						while (getchar() != '\n');
						if (index_delete == 1) {
							printf("\t\tВведіть ім'я кандидата,якого ви хочете видалити : "); fgets(del_name, 40, stdin);
							newpoint = strchr(del_name, '\n');
							if (newpoint != NULL) {
								*newpoint = '\0';
							}
							test_name = 1;
						}
						else if (index_delete == 2) {
							printf("\t\tВведіть дату народження кандидата : "); fgets(del_dates, 40, stdin);
							newpoint = strchr(del_dates, '\n');
							if (newpoint != NULL) {
								*newpoint = '\0';
							}
							test_dates = 1;
						}
						else if (index_delete == 3) {
							printf("\t\tВведіть стать кандидата : "); fgets(del_sex, 40, stdin);
							newpoint = strchr(del_sex, '\n');
							if (newpoint != NULL) {
								*newpoint = '\0';
							}
							test_sex = 1;
						}
						else if (index_delete == 4) {
							printf("\t\tВведіть колір очей кандидата :"); fgets(del_eye, 40, stdin);
							newpoint = strchr(del_eye, '\n');
							if (newpoint != NULL) {
								*newpoint = '\0';
							}
							test_eye = 1;
						}
						else if (index_delete == 5) {
							printf("\t\tВведіть колір волося кандидата : "); fgets(del_hair, 40, stdin);
							newpoint = strchr(del_hair, '\n');
							if (newpoint != NULL) {
								*newpoint = '\0';
							}
							test_hair = 1;
						}
						else if (index_delete == 6) {
							printf("\t\tВведіть ріст кандидата : "); scanf_s("%d", &del_hight);
							while (getchar() != '\n');
							test_hight = 1;
						}
						else {
							continue;
						}
					} while (index_delete != 0);
					delete_partner(&num, &partner, del_name, del_dates, del_sex, del_eye, del_hair, del_hight, token_month, number_of_month, token_menu, way, test_name, test_dates, test_sex, test_eye, test_hair, test_hight,&index_to_indeficate_delete_partner,&test_of_number_delete_partner);
					printf("\t\t\t _______________________________________________________ \n");
					printf("\t\t\t|_______________CONTINUE_TO_USE_DELETING________________|\n");
					printf("\t\t\tENTER(y - yes;n - no) : ");
					fgets(action_del, 10, stdin);
					newpoint = strchr(action_del, '\n');
					if (newpoint != NULL) {
						*newpoint = '\0';	
					}
				} while (strcmp(action_del, "n") != 0);
				break;
			}
			
			case 7: {
				input1_myself(me, way1);
				fill_str_me(num_me, &me, way1);
				//information_me(num_me,&me);
				break;
			}
			case 8: {
				int j;
				int test_to_delete_candidat = 0;
				int test_partner = 0;
				int test_me = 0;
				for (int i = 0; i < num; i++) {
					if (index_of_needless_partners[i] != 0) {
						test_partner++;
					}
				}
				file = fopen(way1, "r+");
				if (file == NULL) {
					printf("ERROR WITH FILE!!!\n");
					exit(EXIT_FAILURE);
				}
				fseek(file, 0, SEEK_END);
				test_me = ftell(file);
				rewind(file);
				fclose(file);
				if (test_partner != 0 && test_me != 0) {
					fill_str_me(num_me, &me, way1);
					for (int k = 0; k < num; k++) {
						if (index_to_indeficate_delete_partner[k] != 0) {
							for (int i = 0; i < num; i++) {
								if (index_of_needless_partners[i] != 0) {
									if (i > index_to_indeficate_delete_partner[k]) {
										j = 1;
										index_of_needless_partners[i] = 0;
										index_of_needless_partners[i - j] = partner[i - j].number_register;
										index_to_indeficate_delete_partner[k] = 0;
									}
									else if (i == index_to_indeficate_delete_partner[k]) {
										printf("\t\t _____________________________________________ \n");
										printf("\t\t|                                             |\n");
										printf("\t\t|----------ВИ_ВИДАЛИЛИ_ВАШОГО_КАНДИДАТА-------|\n");
										printf("\t\t|_____________________________________________|\n");
										test_to_delete_candidat = 1;
									}
								}
								if (test_to_delete_candidat == 1) {
									break;
								}
							}
						}
						if (test_to_delete_candidat == 1) {
							break;
						}
					}
					if (test_to_delete_candidat != 1) {
						output_couple(&partner, me, index_of_needless_partners, &num, token_menu, way2, way1, way);
					}
				}
				else {
					printf("\t\t\t _______________________________________ \n");
					printf("\t\t\t|                                       |\n");
					printf("\t\t\t|--------->НЕМАЄ_ЗНАЙДЕНОЇ_ПАРИ<--------|\n");
					printf("\t\t\t|_______________________________________|\n");
				}
				//while (getchar() != '\n');
				break;
			}
			case 9: {
				file = fopen(way2, "r+");
				if (file == NULL) {
					printf("ERROR WITH FILE!!!\n");
					exit(EXIT_FAILURE);
				}
				fseek(file, 0, SEEK_END);
				test_succesfull = ftell(file);
				rewind(file);
				fclose(file);
				if (test_succesfull > 0) {
					fill_archive(&num_cou, &archive, way2);
					test_enter9 = 1;
					output_archive(&archive, &num_cou, token_menu, way2);
				}
				else {
					printf("\t\t\t _______________________________________ \n");
					printf("\t\t\t|                                       |\n");
					printf("\t\t\t|-------------->АРХІВ_ПУСТИЙ<-----------|\n");
					printf("\t\t\t|_______________________________________|\n");
				}
				//while (getchar() != '\n');
				break;
			}
			case 10: {
				file = fopen(way2, "r+");
				if (file == NULL) {
					printf("ERROR WITH FILE!!!\n");
					exit(EXIT_FAILURE);
				}
				fseek(file, 0, SEEK_END);
				test_succesfull = ftell(file);
				rewind(file);
				fclose(file);
				if (test_succesfull > 0) {
					if (test_enter9 != 1) {
						fill_archive(&num_cou, &archive, way2);
					}
					delete_couple1(&num_del_cou,&delete_archive,way3,token_month,&num_cou,&archive,token_menu,way2);
				}
				else {
					printf("\t\t\t _______________________________________ \n");
					printf("\t\t\t|                                       |\n");
					printf("\t\t\t|-------------->АРХІВ_ПУСТИЙ<-----------|\n");
					printf("\t\t\t|_______________________________________|\n");
				}
				//while (getchar() != '\n');
				break;
			}
			case 11: {
				file = fopen(way3, "r+");
				if (file == NULL) {
					printf("ERROR WITH FILE!!!\n");
					exit(EXIT_FAILURE);
				}
				fseek(file, 0, SEEK_END);
				test_succesfull = ftell(file);
				rewind(file);
				fclose(file);
				if (test_succesfull > 0) {
					fill_delete_archive(&num_del_cou, &delete_archive, way3);
				}
				else {
					printf("\t\t _________________________________ \n");
					printf("\t\t|                                 |\n");
					printf("\t\t|-ФАЙЛ_З_ВИДАЛЕНИМИ_ПАРАМИ_ПУСТИЙ-|\n");
					printf("\t\t|_________________________________|\n");
					while (getchar() != '\n');
					break;
				}
				char* action_of_delete_archive;
				action_of_delete_archive = (char*)malloc(20 * sizeof(char));
				printf("\t\t\t ________________________________________________________________________ \n");
				printf("\t\t\t|_________________ВИ_БАЖАЄТЕ_ВИВЕСТИ_ВАШ_АРХІВ_ВИДАЛЕНИХ_ПАР_____________|\n");
				printf("\t\t\tENTER(yes or no) : ");
				fgets(action_of_delete_archive, 10, stdin);
				newpoint = strchr(action_of_delete_archive, '\n');
				if (newpoint != NULL) {
					*newpoint = '\0';
				}
				if (strcmp(action_of_delete_archive, "yes") == 0) {
					output_delete_archive(num_del_cou, delete_archive, token_menu);
				}
				else {
					printf("\t\t ____________________________________ \n");
					printf("\t\t|                                    |\n");
					printf("\t\t|-----ВИ_НЕ_ВИВЕЛИ_ВИДАЛЕНИЙ_АРХІВ---|\n");
					printf("\t\t|____________________________________|\n");
				}
				//while (getchar() != '\n');
				break;
			}
		}
		/*printf("\t\t\tContinue to using this program('y' - yes; 'n' - no) : ");                                        
		fgets(action, 10, stdin);
		newpoint = strchr(action, '\n');
		if (newpoint != NULL) {
			*newpoint = '\0';
		}*/
		printf("\t\t\tPress any key . . . . . .");
		while (getchar() != '\n');
		system("cls");
	} while (strcmp(action, "n") != 0);
}

void output_delete_archive(int num_del_cou, struct delete_couple** delete_archive, char** token_menu) {
		for (int i = 0; i < num_del_cou; i++) {
			int j = 0;
			printf("\t _______________________________________________________  _______________________________________________________\n");
			printf("\t|---------------------->МОЯ_АНКЕТА<---------------------||-------------------->АНКЕТА_КАНДИДАТА<-----------------|\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 0) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25d||%25s%-30d|", delete_archive[i][0].number_register, " ", delete_archive[i][1].number_register);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 1) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", delete_archive[i][0].requirements.name, " ", delete_archive[i][1].requirements.name);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 2) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", delete_archive[i][0].sex, " ", delete_archive[i][1].sex);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 3) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%-7d%9s%9d||%15s%-7d%14s%19d|", delete_archive[i][0].dates.date, delete_archive[i][0].dates.month, delete_archive[i][0].dates.year, "  ", delete_archive[i][1].dates.date, delete_archive[i][1].dates.month, delete_archive[i][1].dates.year);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 4) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", delete_archive[i][0].requirements.eye, " ", delete_archive[i][1].requirements.eye);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 5) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25d||%25s%-30d|", delete_archive[i][0].requirements.hight, " ", delete_archive[i][1].requirements.hight);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 6) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", delete_archive[i][0].requirements.hair, " ", delete_archive[i][1].requirements.hair);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 7) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", delete_archive[i][0].requirements.face, " ", delete_archive[i][1].requirements.face);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 8) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", delete_archive[i][0].requirements.character, " ", delete_archive[i][1].requirements.character);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 9) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", delete_archive[i][0].requirements.goroskop, " ", delete_archive[i][1].requirements.goroskop);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 10) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", delete_archive[i][0].requirements.job, " ", delete_archive[i][1].requirements.job);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			printf("\n");
			printf("\t ________________________________________________________________________________________________________________ \n");
			printf("\t|                                                                                                                |\n");
			printf("\t|                                                                                                                |\n");
			printf("\t|-----------<---->---------<---->------------------->НОВА_ПАРА<-------------<--->-----------------<--->----------|\n");
			printf("\t|                                                                                                                |\n");
			printf("\t|________________________________________________________________________________________________________________|\n");
		}

}

void fill_delete_archive(int* num_del_cou, struct delete_couple*** delete_archive, char* way3) {
	int temp_number;
	int* temp_i;
	int temp_element = 1;
	temp_i = &temp_element;
	int pointer;
	char*** token;
	char* context_string;
	context_string = NULL;
	char* context_couple;
	context_couple = NULL;
	char* context_token;
	context_token = NULL;
	char* temp_couple = (char*)malloc(800 * sizeof(char));
	char* temp_string = (char*)malloc(400 * sizeof(char));
	char* temp_token = (char*)malloc(400 * sizeof(char));
	temp_couple[0] = '\0';
	temp_string[0] = '\0';
	temp_token[0] = '\0';
	int number_couple = 0;
	int number_string = 1;
	int number_token = 1;
	int number_struct = 0;
	int size_token = 0;
	int index_token = 0;
	char delimiters_couple[] = "@";
	char delimiters_string[] = "\n";
	char delimiters_token[] = "#";
	char* temp_archive;
	char* buffer;
	file = fopen(way3, "r+");
	if (file == NULL) {
		printf("ERROR WITH FILE!!!\n");
		exit(EXIT_FAILURE);
	}
	fseek(file, 0, SEEK_END);
	pointer = ftell(file);
	rewind(file);
	buffer = (char*)malloc(pointer * sizeof(char));
	temp_archive = (char*)malloc(pointer * sizeof(char));
	temp_archive[0] = '\0';
	while (fgets(buffer, pointer, file) != NULL) {
		strcat(temp_archive, buffer);
	}
	rewind(file);
	(*delete_archive) = (struct delete_couple**)malloc((number_struct + 1) * sizeof(struct delete_couple*));
	(*delete_archive)[number_struct] = (struct delete_couple*)malloc((number_couple + 1) * sizeof(struct delete_couple));
	(*delete_archive)[number_struct][0].information = (char*)malloc(400 * sizeof(char));
	temp_couple = strtok_s(temp_archive, delimiters_couple, &context_couple);
	temp_string = strtok_s(temp_couple, delimiters_string, &context_string);
	temp_token = strtok_s(temp_string, delimiters_token, &context_token);
	token = (char***)malloc(number_string * sizeof(char**));
	token[number_couple] = (char**)malloc(number_token * sizeof(char*));
	token[number_couple][size_token] = (char*)malloc(400 * sizeof(char));
	while (temp_couple != NULL) {
		if (temp_couple == NULL) {
			break;
		}
		while (temp_string != NULL) {
			if (temp_string == NULL) {
				break;
			}
			while (temp_token != NULL) {
				if (temp_token == NULL) {
					break;
				}
				strcpy(token[index_token][size_token], temp_token);
				size_token++;
				number_token++;
				token[index_token] = (char**)realloc(token[index_token], number_token * sizeof(char*));
				token[index_token][size_token] = (char*)malloc(400 * sizeof(char));
				temp_token = strtok_s(NULL, delimiters_token, &context_token);
			}
			for (int i = 0; i < 1; i++) {
				for (int j = 0; j < number_token; j++) {
					if (j == 0) {
						strcpy((*delete_archive)[number_struct][number_couple].sex, token[i][j]);
					}
					if (j == 1) {
						strcpy((*delete_archive)[number_struct][number_couple].dates.month, token[i][j]);
					}
					if (j == 2) {
						strcpy((*delete_archive)[number_struct][number_couple].information, token[i][j]);
					}
					if (j == 3) {
						strcpy((*delete_archive)[number_struct][number_couple].requirements.eye, token[i][j]);
					}
					if (j == 4) {
						strcpy((*delete_archive)[number_struct][number_couple].requirements.hair, token[i][j]);
					}
					if (j == 5) {
						strcpy((*delete_archive)[number_struct][number_couple].requirements.name, token[i][j]);
					}
					if (j == 6) {
						strcpy((*delete_archive)[number_struct][number_couple].requirements.face, token[i][j]);
					}
					if (j == 7) {
						strcpy((*delete_archive)[number_struct][number_couple].requirements.character, token[i][j]);
					}
					if (j == 8) {
						temp_number = atoi(token[i][j]);
						(*delete_archive)[number_struct][number_couple].number_register = temp_number;
					}
					if (j == 9) {
						temp_number = atoi(token[i][j]);
						(*delete_archive)[number_struct][number_couple].dates.date = temp_number;
					}
					if (j == 10) {
						temp_number = atoi(token[i][j]);
						(*delete_archive)[number_struct][number_couple].dates.year = temp_number;
					}
					if (j == 11) {
						temp_number = atoi(token[i][j]);
						(*delete_archive)[number_struct][number_couple].requirements.hight = temp_number;
					}
					if (j == 12) {
						strcpy((*delete_archive)[number_struct][number_couple].requirements.goroskop, token[i][j]);
					}
					if (j == 13) {
						strcpy((*delete_archive)[number_struct][number_couple].requirements.job, token[i][j]);
					}
				}
			}
			temp_string = strtok_s(NULL, delimiters_string, &context_string);
			if (temp_string == NULL) {
				break;
			}
			number_couple++;
			(*delete_archive)[number_struct] = (struct delete_couple*)realloc((*delete_archive)[number_struct], (number_couple + 1) * sizeof(struct delete_couple));
			for ((*temp_i); (*temp_i) < number_couple + 1; (*temp_i)++) {
				(*delete_archive)[number_struct][(*temp_i)].information = (char*)malloc(400 * sizeof(char));
			}
			number_string++;
			//token = (char***)realloc(token, number_string * sizeof(char**));
			size_token = 0;
			number_token = 1;
			temp_token = strtok_s(temp_string, delimiters_token, &context_token);
			token[index_token] = NULL;
			token[index_token] = (char**)malloc(number_token * sizeof(char*));
			token[index_token][size_token] = (char*)malloc(400 * sizeof(char));
		}
		temp_couple = strtok_s(NULL, delimiters_couple, &context_couple);
		if (temp_couple == NULL) {
			break;
		}
		number_struct++;
		number_couple = 0;
		number_token = 1;
		number_string = 1;
		size_token = 0;
		(*delete_archive) = (struct delete_couple**)realloc((*delete_archive), (number_struct + 1) * sizeof(struct delete_couple*));
		(*delete_archive)[number_struct] = (struct delete_couple*)malloc((number_couple + 1) * sizeof(struct delete_couple));
		(*delete_archive)[number_struct][0].information = (char*)malloc(400 * sizeof(char));
		temp_string = strtok_s(temp_couple, delimiters_string, &context_string);
		temp_token = strtok_s(temp_string, delimiters_token, &context_token);
		token = NULL;
		token = (char***)malloc(number_string * sizeof(char**));
		token[index_token] = (char**)malloc(number_token * sizeof(char*));
		token[index_token][size_token] = (char*)malloc(400 * sizeof(char));
		temp_element = 1;
	}
	fclose(file);
	(*num_del_cou) = number_struct + 1;
}

void delete_couple1(int* num_del_cou, struct delete_couple*** delete_archive, char* way3, char** token_month,int* num_cou,struct couple*** archive,char** token_menu,char* way2) {
	char* action_del;
	action_del = NULL;
	action_del = (char*)malloc(20 * sizeof(char));
	int index_of_delete_couple;
	int** temp_index_of_need_partner = NULL;
	temp_index_of_need_partner = (int**)malloc((*num_cou) * sizeof(int*));
	for (int i = 0; i < (*num_cou); i++) {
		temp_index_of_need_partner[i] = (int*)malloc(2 * sizeof(int));
	}
	for (int i = 0; i < (*num_cou); i++) {
		for (int j = 0; j < 2; j++) {
			temp_index_of_need_partner[i][j] = 0;
		}
	}
	char* newpoint;
	char** menu_punkt = NULL;
	char** menu_num = NULL;
	menu_num = (char**)malloc(7 * sizeof(char*));
	for (int i = 0; i < 7; i++) {
		menu_num[i] = (char*)malloc(200 * sizeof(char));
		if (i == 0) {
			strcpy(menu_num[i], "Знайти пару, яку ви хочете видалити з архіва (за параметрами)!;");
		}
		if (i == 1) {
			strcpy(menu_num[i], "(1) - за Ім'ям;");
		}
		if (i == 2) {
			strcpy(menu_num[i], "(2) - за датою народження;(Пр: 28.01.2006)!!!");
		}
		if (i == 3) {
			strcpy(menu_num[i], "(3) - за статю;");
		}
		if (i == 4) {
			strcpy(menu_num[i], "(4) - за кольором очей;");
		}
		if (i == 5) {
			strcpy(menu_num[i], "(5) - за кольором волося;");
		}
		if (i == 6) {
			strcpy(menu_num[i], "(6) - за ростом;");
		}

	}
	menu_punkt = (char**)malloc(7 * sizeof(char*));
	for (int i = 0; i < 7; i++) {
		menu_punkt[i] = (char*)malloc(200 * sizeof(char));
		strcpy(menu_punkt[i], menu_num[i]);
	}
	int index_delete;
	char* del_name;

	char* del_dates;

	char* del_sex;

	char* del_eye;

	char* del_hair;

	int del_hight;
	do {
		del_name = NULL;
		del_name = (char*)malloc(40 * sizeof(char));
		int test_name = 0;
		del_dates = NULL;
		del_dates = (char*)malloc(40 * sizeof(char));
		int test_dates = 0;
		del_sex = NULL;
		del_sex = (char*)malloc(40 * sizeof(char));
		int test_sex = 0;
		del_eye = NULL;
		del_eye = (char*)malloc(40 * sizeof(char));
		int test_eye = 0;
		del_hair = NULL;
		del_hair = (char*)malloc(40 * sizeof(char));
		int test_hair = 0;
		del_hight = 0;
		int test_hight = 0;
		printf("\t\t _______________________________________________________________________\n");
		printf("\t\t|_____________________|D|E|L|E|T|E|_|C|O|U|P|L|E|_______________________|\n");
		printf("\t\t|%71s|\n", menu_punkt[0]);
		printf("\t\t|_______________________________________________________________________|\n");
		printf("\t\t|                    %-51s|\n", menu_punkt[1]);
		printf("\t\t|_______________________________________________________________________|\n");
		printf("\t\t|                    %-51s|\n", menu_punkt[2]);
		printf("\t\t|_______________________________________________________________________|\n");
		printf("\t\t|                    %-51s|\n", menu_punkt[3]);
		printf("\t\t|_______________________________________________________________________|\n");
		printf("\t\t|                    %-51s|\n", menu_punkt[4]);
		printf("\t\t|_______________________________________________________________________|\n");
		printf("\t\t|                    %-51s|\n", menu_punkt[5]);
		printf("\t\t|_______________________________________________________________________|\n");
		printf("\t\t|                    %-51s|\n", menu_punkt[6]);
		printf("\t\t|_______________________________________________________________________|\n");
		do {
			printf("\t\t\tВведіть значення(0 - закінчити введення!!!) : "); scanf_s("%d", &index_delete);
			while (getchar() != '\n');
			if (index_delete == 1) {
				printf("\t\tВведіть ім'я кандидата,якого ви хочете видалити : "); fgets(del_name, 40, stdin);
				newpoint = strchr(del_name, '\n');
				if (newpoint != NULL) {
					*newpoint = '\0';
				}
				test_name = 1;
			}
			else if (index_delete == 2) {
				printf("\t\tВведіть дату народження кандидата : "); fgets(del_dates, 40, stdin);
				newpoint = strchr(del_dates, '\n');
				if (newpoint != NULL) {
					*newpoint = '\0';
				}
				test_dates = 1;
			}
			else if (index_delete == 3) {
				printf("\t\tВведіть стать кандидата : "); fgets(del_sex, 40, stdin);
				newpoint = strchr(del_sex, '\n');
				if (newpoint != NULL) {
					*newpoint = '\0';
				}
				test_sex = 1;
			}
			else if (index_delete == 4) {
				printf("\t\tВведіть колір очей кандидата :"); fgets(del_eye, 40, stdin);
				newpoint = strchr(del_eye, '\n');
				if (newpoint != NULL) {
					*newpoint = '\0';
				}
				test_eye = 1;
			}
			else if (index_delete == 5) {
				printf("\t\tВведіть колір волося кандидата : "); fgets(del_hair, 40, stdin);
				newpoint = strchr(del_hair, '\n');
				if (newpoint != NULL) {
					*newpoint = '\0';
				}
				test_hair = 1;
			}
			else if (index_delete == 6) {
				printf("\t\tВведіть ріст кандидата : "); scanf_s("%d", &del_hight);
				while (getchar() != '\n');
				test_hight = 1;
			}
			else {
				continue;
			}
		} while (index_delete != 0);
		int test_right;
		printf("\t\t _____________________________________________ \n");
		printf("\t\t|                                             |\n");
		printf("\t\t|---------ПРОДОВЖИТИ_ВИДАЛЕННЯ_ПАРИ-----------|\n");
		printf("\t\t|_____________________________________________|\n");
		printf("\t\tВведіть (1 - так; 0 - ні) : "); scanf_s("%d", &test_right);
		if (test_right == 0) {
			printf("\t\t _______________________________________ \n");
			printf("\t\t|                                       |\n");
			printf("\t\t|-----РОБОТУ_З_ВИДАЛЕННЯМ_ЗАВЕРШЕНО-----|\n");
			printf("\t\t|_______________________________________|\n");
			break;
		}
		int** number_same;
		number_same = NULL;
		number_same = (int**)malloc((*num_cou) * sizeof(int*));
		for (int i = 0; i < (*num_cou); i++) {
			number_same[i] = (int*)malloc(2 * sizeof(int));
		}
		for (int i = 0; i < (*num_cou); i++) {
			for (int j = 0; j < 2; j++) {
				number_same[i][j] = 0;
			}
		}
		if (test_dates == 1) {
			int delete_date = 0;
			char* delete_month = NULL;
			int delete_year = 0;
			char** token_dates;
			char* context_dates;
			char delimiters_dates[] = ".";
			char* temp_token_month;
			temp_token_month = (char*)malloc(100 * sizeof(char));
			int number_token_dates = 1;
			int size_token_dates = 0;
			token_dates = (char**)malloc(sizeof(char*));
			token_dates[size_token_dates] = (char*)malloc(100 * sizeof(char));
			temp_token_month = strtok_s(del_dates, delimiters_dates, &context_dates);
			while (temp_token_month != NULL) {
				strcpy(token_dates[size_token_dates], temp_token_month);
				number_token_dates++;
				size_token_dates++;
				token_dates = (char**)realloc(token_dates, number_token_dates * sizeof(char*));
				token_dates[size_token_dates] = (char*)malloc(100 * sizeof(char));
				temp_token_month = strtok_s(NULL, delimiters_dates, &context_dates);
			}
			delete_date = atoi(token_dates[0]);
			int temp_number = atoi(token_dates[1]);
			delete_month = (char*)malloc(100 * sizeof(char));
			strcpy(delete_month, token_month[temp_number - 1]);
			delete_year = atoi(token_dates[2]);
			for (int i = 0; i < (*num_cou); i++) {
				for (int j = 0; j < 2; j++) {
					if (strcmp((*archive)[i][j].requirements.name, del_name) == 0 && del_name != NULL) {
						number_same[i][j]++;
					}
					if ((*archive)[i][j].dates.date == delete_date && delete_date != 0) {
						number_same[i][j]++;
					}
					if (strcmp((*archive)[i][j].dates.month, delete_month) == 0 && delete_month != NULL) {
						number_same[i][j]++;
					}
					if ((*archive)[i][j].dates.year == delete_year && delete_year != 0) {
						number_same[i][j]++;
					}
					if (strcmp((*archive)[i][j].sex, del_sex) == 0 && del_sex != NULL) {
						number_same[i][j]++;
					}
					if (strcmp((*archive)[i][j].requirements.eye, del_eye) == 0 && del_eye != NULL) {
						number_same[i][j]++;
					}
					if (strcmp((*archive)[i][j].requirements.hair, del_hair) == 0 && del_hair != NULL) {
						number_same[i][j]++;
					}
					if ((*archive)[i][j].requirements.hight == del_hight && del_hight != 0) {
						number_same[i][j]++;
					}
				}
			}
		}
		else if (test_dates != 1) {
			for (int i = 0; i < (*num_cou); i++) {
				for (int j = 0; j < 2; j++) {
					if (strcmp((*archive)[i][j].requirements.name, del_name) == 0 && del_name != NULL) {
						number_same[i][j]++;
					}
					if (strcmp((*archive)[i][j].sex, del_sex) == 0 && del_sex != NULL) {
						number_same[i][j]++;
					}
					if (strcmp((*archive)[i][j].requirements.eye, del_eye) == 0 && del_eye != NULL) {
						number_same[i][j]++;
					}
					if (strcmp((*archive)[i][j].requirements.hair, del_hair) == 0 && del_hair != NULL) {
						number_same[i][j]++;
					}
					if ((*archive)[i][j].requirements.hight == del_hight && del_hight != 0) {
						number_same[i][j]++;
					}
				}
			}
		}
			int max_i = 0;
			int max_j = 0;
			for (int i = 0; i < (*num_cou); i++) {
				for (int j = 0; j < 2; j++) {
					if (number_same[i][j] >= number_same[max_i][max_j]) {
						max_i = i;
						max_j = j;
					}
					else {
						continue;
					}
				}
			}
			for (int i = 0; i < (*num_cou); i++) {
				for (int j = 0; j < 2; j++) {
					if (number_same[i][j] == number_same[max_i][max_j]) {
						temp_index_of_need_partner[i][j] = (*archive)[i][j].number_register;
					}
				}
			}
			int number_of_couple_finded = 0;
			for (int i = 0; i < (*num_cou); i++) {
				for (int j = 0; j < 2; j++) {
					if (temp_index_of_need_partner[i][j] != 0) {
						index_of_delete_couple = i;
						number_of_couple_finded++;
					}
				}
			}
			if (number_of_couple_finded == 0) {
				printf("\t\t\t\t ________________________________________________ \n");
				printf("\t\t\t\t|                                                |\n");
				printf("\t\t\t\t|------------Пару не було знайдено!!!------------|\n");
				printf("\t\t\t\t|________________________________________________|\n");
				return;
			}
			if (number_of_couple_finded > 1) {
				printf("\t\t\t ________________________________________________ \n");
				printf("\t\t\t|                                                |\n");
				printf("\t\t\t|------ВИБЕРІТЬ ПАРУ ЯКУ ВИ ХОЧЕТЕ ВИДАЛИТИ------|\n");
				printf("\t\t\t|________________________________________________|\n");
				for (int i = 0; i < (*num_cou); i++) {
					for (int j = 0; j < 2; j++) {
						if (temp_index_of_need_partner[i][j] == (*archive)[i][j].number_register) {
							int j = 0;
							printf("\t|__________________________________________________%2d кандидат___________________________________________________|\n",i+1);
							printf("\t _______________________________________________________  _______________________________________________________\n");
							printf("\t|---------------------->МОЯ_АНКЕТА<---------------------||-------------------->АНКЕТА_КАНДИДАТА<-----------------|\n");
							printf("\t|_______________________________________________________||_______________________________________________________|\n");
							if (j == 0) {
								printf("\t|%28s|", token_menu[j]);
								j++;
							}
							printf("|%25d||%25s%-30d|", (*archive)[i][0].number_register, " ", (*archive)[i][1].number_register);
							printf("\n");
							printf("\t|_______________________________________________________||_______________________________________________________|\n");
							if (j == 1) {
								printf("\t|%28s|", token_menu[j]);
								j++;
							}
							printf("|%25s||%25s%-30s|", (*archive)[i][0].requirements.name, " ", (*archive)[i][1].requirements.name);
							printf("\n");
							printf("\t|_______________________________________________________||_______________________________________________________|\n");
							if (j == 2) {
								printf("\t|%28s|", token_menu[j]);
								j++;
							}
							printf("|%25s||%25s%-30s|", (*archive)[i][0].sex, " ", (*archive)[i][1].sex);
							printf("\n");
							printf("\t|_______________________________________________________||_______________________________________________________|\n");
							if (j == 3) {
								printf("\t|%28s|", token_menu[j]);
								j++;
							}
							printf("|%-7d%9s%9d||%15s%-7d%14s%19d|", (*archive)[i][0].dates.date, (*archive)[i][0].dates.month, (*archive)[i][0].dates.year, "  ", (*archive)[i][1].dates.date, (*archive)[i][1].dates.month, (*archive)[i][1].dates.year);
							printf("\n");
							printf("\t|_______________________________________________________||_______________________________________________________|\n");
							if (j == 4) {
								printf("\t|%28s|", token_menu[j]);
								j++;
							}
							printf("|%25s||%25s%-30s|", (*archive)[i][0].requirements.eye, " ", (*archive)[i][1].requirements.eye);
							printf("\n");
							printf("\t|_______________________________________________________||_______________________________________________________|\n");
							if (j == 5) {
								printf("\t|%28s|", token_menu[j]);
								j++;
							}
							printf("|%25d||%25s%-30d|", (*archive)[i][0].requirements.hight, " ", (*archive)[i][1].requirements.hight);
							printf("\n");
							printf("\t|_______________________________________________________||_______________________________________________________|\n");
							if (j == 6) {
								printf("\t|%28s|", token_menu[j]);
								j++;
							}
							printf("|%25s||%25s%-30s|", (*archive)[i][0].requirements.hair, " ", (*archive)[i][1].requirements.hair);
							printf("\n");
							printf("\t|_______________________________________________________||_______________________________________________________|\n");
							if (j == 7) {
								printf("\t|%28s|", token_menu[j]);
								j++;
							}
							printf("|%25s||%25s%-30s|", (*archive)[i][0].requirements.face, " ", (*archive)[i][1].requirements.face);
							printf("\n");
							printf("\t|_______________________________________________________||_______________________________________________________|\n");
							if (j == 8) {
								printf("\t|%28s|", token_menu[j]);
								j++;
							}
							printf("|%25s||%25s%-30s|", (*archive)[i][0].requirements.character, " ", (*archive)[i][1].requirements.character);
							printf("\n");
							printf("\t|_______________________________________________________||_______________________________________________________|\n");
							if (j == 9) {
								printf("\t|%28s|", token_menu[j]);
								j++;
							}
							printf("|%25s||%25s%-30s|", (*archive)[i][0].requirements.goroskop, " ", (*archive)[i][1].requirements.goroskop);
							printf("\n");
							printf("\t|_______________________________________________________||_______________________________________________________|\n");
							if (j == 10) {
								printf("\t|%28s|", token_menu[j]);
								j++;
							}
							printf("|%25s||%25s%-30s|", (*archive)[i][0].requirements.job, " ", (*archive)[i][1].requirements.job);
							printf("\n");
							printf("\t|_______________________________________________________||_______________________________________________________|\n");
							printf("\n");
							printf("\t ________________________________________________________________________________________________________________ \n");
							printf("\t|                                                                                                                |\n");
							printf("\t|                                                                                                                |\n");
							printf("\t|-----------<---->---------<---->------------------->НОВА_ПАРА<-------------<--->-----------------<--->----------|\n");
							printf("\t|                                                                                                                |\n");
							printf("\t|________________________________________________________________________________________________________________|\n");
						}
					}
				}
				while (getchar() != '\n');
				printf("\t\tВведіть номер пари, яку ви хочете видалити з архіва : "); scanf_s("%d", &index_of_delete_couple);
				index_of_delete_couple -= 1;
			}
			int point;
			char* temp_archive;
			char* buffer;
			char** token_archive;
			char* temp_token_archive;
			int number_token_archive = 1;
			int size_token_archive = 0;
			char* context_archive;
			char delimiters_archive[] = "@";
			file = fopen(way2, "r+");
			if (file == NULL) {
				printf("ERROR WITH FILE!!!\n");
				exit(EXIT_FAILURE);
			}
			fseek(file, 0, SEEK_END);
			point = ftell(file);
			rewind(file);
			temp_archive = NULL;
			buffer = NULL;
			temp_archive = (char*)malloc(point * sizeof(char));
			temp_archive[0] = '\0';
			buffer = (char*)malloc(point * sizeof(char));
			while (fgets(buffer, point, file) != NULL) {
				strcat(temp_archive, buffer);
			}
			token_archive = (char**)malloc(number_token_archive * sizeof(char*));
			token_archive[size_token_archive] = (char*)malloc(400 * sizeof(char));
			temp_token_archive = strtok_s(temp_archive, delimiters_archive, &context_archive);
			while (temp_token_archive != NULL) {
				strcpy(token_archive[size_token_archive], temp_token_archive);
				number_token_archive++;
				size_token_archive++;
				token_archive = (char**)realloc(token_archive,number_token_archive * sizeof(char*));
				token_archive[size_token_archive] = (char*)malloc(400 * sizeof(char));
				temp_token_archive = strtok_s(NULL, delimiters_archive, &context_archive);
			}
			fclose(file);
			file = fopen(way2, "w");
			if (file == NULL) {
				printf("ERROR WITH FILE!!!\n");
				exit(EXIT_FAILURE);
			}
			for (int i = 0; i < (*num_cou); i++) {
				if (i == index_of_delete_couple) {
					continue;
				}
				fputs(token_archive[i], file);
				fputs("@", file);
			}
			(*num_cou)-=1;
			fclose(file);
			file = fopen(way3, "a+");
			if (file == NULL) {
				printf("ERROR WITH FILE!!!\n");
				exit(EXIT_FAILURE);
			}
			fputs(token_archive[index_of_delete_couple], file);
			fputs("@", file);
			fclose(file);
			(*archive) = NULL;
			(*archive) = (struct couple**)malloc((*num_cou) * sizeof(struct couple*));
			for (int i = 0; i < (*num_cou); i++) {
				(*archive)[i] = (struct couple*)malloc(2 * sizeof(struct couple));
			}
			fill_archive(num_cou, archive, way2);
			






			while (getchar() != '\n');
			printf("\t\t\t _______________________________________________________ \n");
			printf("\t\t\t|_______________CONTINUE_TO_USE_DELETING________________|\n");
			printf("\t\t\tENTER(y - yes;n - no) : ");
			fgets(action_del, 10, stdin);
			newpoint = strchr(action_del, '\n');
			if (newpoint != NULL) {
				*newpoint = '\0';
			}
	} while (strcmp(action_del, "n") != 0);
}

void fill_archive(int* num_cou, couple*** archive, char* way2){
	int temp_number;
	int* temp_i;
	int temp_element = 1;
	temp_i = &temp_element;
	int pointer;
	char*** token;
	char* context_string;
	context_string = NULL;
	char* context_couple;
	context_couple = NULL;
	char* context_token;
	context_token = NULL;
	char* temp_couple = (char*)malloc(800 * sizeof(char));
	char* temp_string = (char*)malloc(400 * sizeof(char));
	char* temp_token = (char*)malloc(400 * sizeof(char));
	temp_couple[0] = '\0';
	temp_string[0] = '\0';
	temp_token[0] = '\0';
	int number_couple = 0;
	int number_string = 1;
	int number_token = 1;
	int number_struct = 0;
	int size_token = 0;
	int index_token = 0;
	char delimiters_couple[] = "@";
	char delimiters_string[] = "\n";
	char delimiters_token[] = "#";
	char* temp_archive;
	char* buffer;
	file = fopen(way2, "r+");
	if (file == NULL) {
		printf("ERROR WITH FILE!!!\n");
		exit(EXIT_FAILURE);
	}
	fseek(file, 0, SEEK_END);
	pointer = ftell(file);
	rewind(file);
	buffer = (char*)malloc(pointer * sizeof(char));
	temp_archive = (char*)malloc(pointer * sizeof(char));
	temp_archive[0] = '\0';
	while (fgets(buffer, pointer, file) != NULL) {
		strcat(temp_archive, buffer);
	}
	rewind(file);
	(*archive) = (struct couple**)malloc((number_struct + 1) * sizeof(struct couple*));
	(*archive)[number_struct] = (struct couple*)malloc((number_couple + 1) * sizeof(struct couple));
	(*archive)[number_struct][0].information = (char*)malloc(400 * sizeof(char));
	temp_couple = strtok_s(temp_archive, delimiters_couple, &context_couple);
	temp_string = strtok_s(temp_couple, delimiters_string, &context_string);
	temp_token = strtok_s(temp_string, delimiters_token, &context_token);
	token = (char***)malloc(number_string * sizeof(char**));
	token[number_couple] = (char**)malloc(number_token * sizeof(char*));
	token[number_couple][size_token] = (char*)malloc(400 * sizeof(char));
	while (temp_couple != NULL) {
		if (temp_couple == NULL) {
			break;
		}
		while (temp_string != NULL) {
			if (temp_string == NULL) {
				break;
			}
			while (temp_token != NULL) {
				if (temp_token == NULL) {
					break;
				}
				strcpy(token[index_token][size_token], temp_token);
				size_token++;
				number_token++;
				token[index_token] = (char**)realloc(token[index_token], number_token * sizeof(char*));
				token[index_token][size_token] = (char*)malloc(400 * sizeof(char));
				temp_token = strtok_s(NULL, delimiters_token, &context_token);
			}
			for (int i = 0; i < 1; i++) {
				for (int j = 0; j < number_token; j++) {
					if (j == 0) {
						strcpy((*archive)[number_struct][number_couple].sex, token[i][j]);
					}
					if (j == 1) {
						strcpy((*archive)[number_struct][number_couple].dates.month, token[i][j]);
					}
					if (j == 2) {
						strcpy((*archive)[number_struct][number_couple].information, token[i][j]);
					}
					if (j == 3) {
						strcpy((*archive)[number_struct][number_couple].requirements.eye, token[i][j]);
					}
					if (j == 4) {
						strcpy((*archive)[number_struct][number_couple].requirements.hair, token[i][j]);
					}
					if (j == 5) {
						strcpy((*archive)[number_struct][number_couple].requirements.name, token[i][j]);
					}
					if (j == 6) {
						strcpy((*archive)[number_struct][number_couple].requirements.face, token[i][j]);
					}
					if (j == 7) {
						strcpy((*archive)[number_struct][number_couple].requirements.character, token[i][j]);
					}
					if (j == 8) {
						temp_number = atoi(token[i][j]);
						(*archive)[number_struct][number_couple].number_register = temp_number;
					}
					if (j == 9) {
						temp_number = atoi(token[i][j]);
						(*archive)[number_struct][number_couple].dates.date = temp_number;
					}
					if (j == 10) {
						temp_number = atoi(token[i][j]);
						(*archive)[number_struct][number_couple].dates.year = temp_number;
					}
					if (j == 11) {
						temp_number = atoi(token[i][j]);
						(*archive)[number_struct][number_couple].requirements.hight = temp_number;
					}
					if (j == 12) {
						strcpy((*archive)[number_struct][number_couple].requirements.goroskop, token[i][j]);
					}
					if (j == 13) {
						strcpy((*archive)[number_struct][number_couple].requirements.job, token[i][j]);
					}
				}
			}
			temp_string = strtok_s(NULL, delimiters_string, &context_string);
			if (temp_string == NULL) {
				break;
			}
			number_couple++;
			(*archive)[number_struct] = (struct couple*)realloc((*archive)[number_struct], (number_couple + 1) * sizeof(struct couple));
			for ((*temp_i); (*temp_i) < number_couple + 1; (*temp_i)++) {
				(*archive)[number_struct][(*temp_i)].information = (char*)malloc(400 * sizeof(char));
			}
			number_string++;
			//token = (char***)realloc(token, number_string * sizeof(char**));
			size_token = 0;
			number_token = 1;
			temp_token = strtok_s(temp_string, delimiters_token, &context_token);
			token[index_token] = NULL;
			token[index_token] = (char**)malloc(number_token * sizeof(char*));
			token[index_token][size_token] = (char*)malloc(400 * sizeof(char));
		}
		temp_couple = strtok_s(NULL, delimiters_couple, &context_couple);
		if (temp_couple == NULL) {
			break;
		}
		number_struct++;
		number_couple = 0;
		number_token = 1;
		number_string = 1;
		size_token = 0;
		(*archive) = (struct couple**)realloc((*archive), (number_struct + 1) * sizeof(struct couple*));
		(*archive)[number_struct] = (struct couple*)malloc((number_couple + 1) * sizeof(struct couple));
		(*archive)[number_struct][0].information = (char*)malloc(400 * sizeof(char));
		temp_string = strtok_s(temp_couple, delimiters_string, &context_string);
		temp_token = strtok_s(temp_string, delimiters_token, &context_token);
		token = NULL;
		token = (char***)malloc(number_string * sizeof(char**));
		token[index_token] = (char**)malloc(number_token * sizeof(char*));
		token[index_token][size_token] = (char*)malloc(400 * sizeof(char));
		temp_element = 1;
	}
	fclose(file);
	(*num_cou) = number_struct + 1;
}

void output_archive(struct couple*** archive, int* num_cou, char** token_menu, char* way2) {
	char* newpoint;
	char* action;
	action = (char*)malloc(10 * sizeof(char));
	printf("\t\t\t ________________________________________________________________________ \n");
	printf("\t\t\t|_________________ВИ_БАЖАЄТЕ_ВИВЕСТИ_ВАШ_АРХІВ_ПАР_______________________|\n");
	printf("\t\t\tENTER(yes or no) : ");
	fgets(action, 10, stdin);
	newpoint = strchr(action, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	if (strcmp(action, "yes") == 0) {

		for (int i = 0; i < (*num_cou); i++) {
			int j = 0;
			printf("\t _______________________________________________________  _______________________________________________________\n");
			printf("\t|---------------------->МОЯ_АНКЕТА<---------------------||-------------------->АНКЕТА_КАНДИДАТА<-----------------|\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 0) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25d||%25s%-30d|", (*archive)[i][0].number_register, " ", (*archive)[i][1].number_register);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 1) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", (*archive)[i][0].requirements.name, " ", (*archive)[i][1].requirements.name);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 2) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", (*archive)[i][0].sex, " ", (*archive)[i][1].sex);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 3) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%-7d%9s%9d||%15s%-7d%14s%19d|", (*archive)[i][0].dates.date, (*archive)[i][0].dates.month, (*archive)[i][0].dates.year, "  ", (*archive)[i][1].dates.date, (*archive)[i][1].dates.month, (*archive)[i][1].dates.year);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 4) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", (*archive)[i][0].requirements.eye, " ", (*archive)[i][1].requirements.eye);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 5) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25d||%25s%-30d|", (*archive)[i][0].requirements.hight, " ", (*archive)[i][1].requirements.hight);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 6) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", (*archive)[i][0].requirements.hair, " ", (*archive)[i][1].requirements.hair);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 7) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", (*archive)[i][0].requirements.face, " ", (*archive)[i][1].requirements.face);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 8) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", (*archive)[i][0].requirements.character, " ", (*archive)[i][1].requirements.character);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 9) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", (*archive)[i][0].requirements.goroskop, " ", (*archive)[i][1].requirements.goroskop);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			if (j == 10) {
				printf("\t|%28s|", token_menu[j]);
				j++;
			}
			printf("|%25s||%25s%-30s|", (*archive)[i][0].requirements.job, " ", (*archive)[i][1].requirements.job);
			printf("\n");
			printf("\t|_______________________________________________________||_______________________________________________________|\n");
			printf("\n");
			printf("\t ________________________________________________________________________________________________________________ \n");
			printf("\t|                                                                                                                |\n");
			printf("\t|                                                                                                                |\n");
			printf("\t|-----------<---->---------<---->------------------->НОВА_ПАРА<-------------<--->-----------------<--->----------|\n");
			printf("\t|                                                                                                                |\n");
			printf("\t|________________________________________________________________________________________________________________|\n");
		}
	}
	else if (strcmp(action, "yes") != 0) {
		printf("\t\t\t ________________________________________________________________________ \n");
		printf("\t\t\t|________________РОБОТА_ЗАКІНЧЕННА_БЕЗ_ВИВЕДЕННЯ_АРХІВУ__________________|\n");
		printf("\t\t\t|________________________________________________________________________|\n");
		return;
	}

}

void output_finded(int num, struct marryed* partner, int* index_of_needless_partners, char** token_menu) {
	int temp_index = 0;
	int index_first_partner;
	int* sort_index;
	int nul_index = 0;
	sort_index = &nul_index;
	for (int i = 0; i < num; i++) {
		if (index_of_needless_partners[i] != 0) {
			temp_index++;
		}
		else {
			continue;
		}
	}
	
	int number_of_repet;
	if (temp_index % 5 == 0) {
		number_of_repet = temp_index / 5;
	}
	else if (temp_index % 5 != 0) {
		number_of_repet = (temp_index / 5) + 1;
	}
	if (temp_index == 0) {
		printf(" _________________________________________________________________________________________________________________\n");
		printf("|Ми не можемо вивести найкращого партнера, тому що ми не знайшли його(або ти просто не шукав його в базі даних)!!!|\n");
		printf("|_________________________________________________________________________________________________________________|\n");
		return;
	}
	int temp_index_first;
	for (int i = 0; i < num; i++) {
		if (index_of_needless_partners[i] != 0) {
			temp_index_first = i;
			break;
		}
	}
	for (int i = 0; i < num; i++) {
		if (index_of_needless_partners[temp_index_first] == partner[i].number_register) {
			index_first_partner = i;
		}
	}
	index_first_partner = -1;
	int* i;
	int temp_i = 0;
	i = &temp_i;
	int* i1;
	int temp_i1 = 0;
	i1 = &temp_i1;
	int* i2;
	int temp_i2 = 0;
	i2 = &temp_i2;
	int* i3;
	int temp_i3 = 0;
	i3 = &temp_i3;
	int* i4;
	int temp_i4 = 0;
	i4 = &temp_i4;
	int* i5;
	int temp_i5 = 0;
	i5 = &temp_i5;
	int* i6;
	int temp_i6 = 0;
	i6 = &temp_i6;
	int* i7;
	int temp_i7 = 0;
	i7 = &temp_i7;
	int* i8;
	int temp_i8 = 0;
	i8 = &temp_i8;
	int* i9;
	int temp_i9 = 0;
	i9 = &temp_i9;
	int* i10;
	int temp_i10 = 0;
	i10 = &temp_i10;
	int* i11;
	int temp_i11 = 0;
	i11 = &temp_i11;
	int* i_n;
	int temp_i_n = 0;
	i_n = &temp_i_n;
	int* i_k;
	int temp_i_k = 0;
	i_k = &temp_i_k;
	int* i_l;
	int temp_i_l = 0;
	i_l = &temp_i_l;
	int* i_1;
	int temp_i_1 = 0;
	i_1 = &temp_i_1;
	int* i_2;
	int temp_i_2 = 0;
	i_2 = &temp_i_2;
	int* i_3;
	int temp_i_3 = 0;
	i_3 = &temp_i_3;
	int* i_4;
	int temp_i_4 = 0;
	i_4 = &temp_i_4;
	int* i_5;
	int temp_i_5 = 0;
	i_5 = &temp_i_5;
	int* i_6;
	int temp_i_6 = 0;
	i_6 = &temp_i_6;
	int* i_7;
	int temp_i_7 = 0;
	i_7 = &temp_i_7;
	int* i_8;
	int temp_i_8 = 0;
	i_8 = &temp_i_8;
	int* i_9;
	int temp_i_9 = 0;
	i_9 = &temp_i_9;
	int* i_10;
	int temp_i_10 = 0;
	i_10 = &temp_i_10;
	int* i_11;
	int temp_i_11 = 0;
	i_11 = &temp_i_11;

	int* index_delete;
	int temp_delete_index = 0;
	index_delete = &temp_delete_index;

	int* r;
	int temp_r = 0;
	r = &temp_r;
	int* r1;
	int temp_r1 = 0;
	r1 = &temp_r1;
	int* r2;
	int temp_r2 = 0;
	r2 = &temp_r2;
	int* r3;
	int temp_r3 = 0;
	r3 = &temp_r3;
	int* r4;
	int temp_r4 = 0;
	r4 = &temp_r4;
	int* r5;
	int temp_r5 = 0;
	r5 = &temp_r5;
	int* r6;
	int temp_r6 = 0;
	r6 = &temp_r6;
	int* r7;
	int temp_r7 = 0;
	r7 = &temp_r7;
	int* r8;
	int temp_r8 = 0;
	r8 = &temp_r8;
	int* r9;
	int temp_r9 = 0;
	r9 = &temp_r9;
	int* r10;
	int temp_r10 = 0;
	r10 = &temp_r10;
	int* r11;
	int temp_r11 = 0;
	r11 = &temp_r11;
	int* r12;
	int temp_r12 = 0;
	r12 = &temp_r12;
	int* r13;
	int temp_r13 = 0;
	r13 = &temp_r13;
	int* r14;
	int temp_r14 = 0;
	r14 = &temp_r14;
	int* r15;
	int temp_r15 = 0;
	r15 = &temp_r15;
	int* r16;
	int temp_r16 = 0;
	r16 = &temp_r16;
	int* r17;
	int temp_r17 = 0;
	r17 = &temp_r17;
	int* r18;
	int temp_r18 = 0;
	r18 = &temp_r18;
	int* r19;
	int temp_r19 = 0;
	r19 = &temp_r19;
	int* r20;
	int temp_r20 = 0;
	r20 = &temp_r20;
	int* r21;
	int temp_r21 = 0;
	r21 = &temp_r21;
	int* r22;
	int temp_r22 = 0;
	r22 = &temp_r22;
	int* r23;
	int temp_r23 = 0;
	r23 = &temp_r23;
	int* r24;
	int temp_r24 = 0;
	r24 = &temp_r24;
	int* r25;
	int temp_r25 = 0;
	r25 = &temp_r25;
	int* r26;
	int temp_r26 = 0;
	r26 = &temp_r26;
	int* i_12;
	int temp_i_12 = 0;
	i_12 = &temp_i_12;

	int temp_test5 = 0;
	int j = 0;
	for (int k = 0; k < number_of_repet; k++) {
		for (*(i_n); *(i_n) < num; (*i_n)++) {
			if (index_of_needless_partners[*(i_n)] == NULL || (*i_n) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[*(i_n)] == partner[l].number_register) {
					printf(" __________________________ ");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1 ) {
				temp_test5 = 0;
				(*i_n)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");
		for (*(i_k); *(i_k) < num; (*i_k)++) {

			if (index_of_needless_partners[*(i_k)] == NULL || *(i_k) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[*(i_k)] == partner[l].number_register) {
					printf("|------>%2d_кандидат<-------|", l + 1);
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0&& number_of_repet != 1) {
				temp_test5 = 0;
				(*i_k)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");

		for (*(i_l); *(i_l) < num; (*i_l)++) {

			if (index_of_needless_partners[*(i_l)] == NULL || *(i_l) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[*(i_l)] == partner[l].number_register) {
					printf("|__________________________|");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_l)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");
		////////
		
		for (*i; *i < num; (*i)++) {

			if (index_of_needless_partners[(*i)] == NULL || (*i) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i)] == partner[l].number_register) {
					printf("|%26d|", partner[l].number_register);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");
		
		for (*i_1; *i_1 < num; (*i_1)++) {

			if (index_of_needless_partners[(*i_1)] == NULL || (*i_1) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i_1)] == partner[l].number_register) {
					printf("|__________________________|");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_1)++;
				break;
			}
		}
		temp_test5 = 0;
		///////
		printf("\n");
		
		for (*i1; (*i1) < num; (*i1)++) {

			if (index_of_needless_partners[(*i1)] == NULL || (*i1) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i1)] == partner[l].number_register) {
					printf("|%26s|", partner[l].requirements.name);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i1)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");
		
		for ((*i_2); (*i_2) < num; (*i_2)++) {

			if (index_of_needless_partners[(*i_2)] == NULL || (*i_2) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i_2)] == partner[l].number_register) {
					printf("|__________________________|");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_2)++;
				break;
			}
		}
		temp_test5 = 0;
		//////////
		printf("\n");
		
		for ((*i2); (*i2) < num; (*i2)++) {

			if (index_of_needless_partners[(*i2)] == NULL || (*i2) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i2)] == partner[l].number_register) {
					printf("|%26s|", partner[l].sex);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i2)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");
		
		for ((*i_3); (*i_3) < num; (*i_3)++) {

			if (index_of_needless_partners[(*i_3)] == NULL || (*i_3) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i_3)] == partner[l].number_register) {
					printf("|__________________________|");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_3)++;
				break;
			}
		}
		temp_test5 = 0;
		/////////
		printf("\n");
		
		for ((*i3); (*i3) < num; (*i3)++) {

			if (index_of_needless_partners[(*i3)] == NULL || (*i3) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i3)] == partner[l].number_register) {
					printf("|%-7d%9s%10d|", partner[l].dates.date, partner[l].dates.month, partner[l].dates.year);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i3)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");
		
		for ((*i_4); (*i_4) < num; (*i_4)++) {

			if (index_of_needless_partners[(*i_4)] == NULL || (*i_4) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i_4)] == partner[l].number_register) {
					printf("|__________________________|");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_4)++;
				break;
			}
		}
		temp_test5 = 0;
		//////////
		printf("\n");
		
		for ((*i4); (*i4) < num; (*i4)++) {

			if (index_of_needless_partners[(*i4)] == NULL || (*i4) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i4)] == partner[l].number_register) {
					printf("|%26s|", partner[l].requirements.eye);
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i4)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");
		
		for ((*i_5); (*i_5) < num; (*i_5)++) {

			if (index_of_needless_partners[(*i_5)] == NULL || (*i_5) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i_5)] == partner[l].number_register) {
					printf("|__________________________|");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_5)++;
				break;
			}
		}
		temp_test5 = 0;
		/////////////
		printf("\n");
		
		for ((*i5); (*i5) < num; (*i5)++) {

			if (index_of_needless_partners[(*i5)] == NULL || (*i5) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i5)] == partner[l].number_register) {
					printf("|%26d|", partner[l].requirements.hight);
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i5)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");
		
		for ((*i_6); (*i_6) < num; (*i_6)++) {

			if (index_of_needless_partners[(*i_6)] == NULL || (*i_6) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i_6)] == partner[l].number_register) {
					printf("|__________________________|");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_6)++;
				break;
			}
		}
		temp_test5 = 0;
		////////////
		printf("\n");
		
		for ((*i6); (*i6) < num; (*i6)++) {
			if (index_of_needless_partners[(*i6)] == 0 || (*i6) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i6)] == partner[l].number_register) {
					printf("|%26s|", partner[l].requirements.hair);
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i6)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");
		
		for ((*i_7); (*i_7) < num; (*i_7)++) {
			if (index_of_needless_partners[(*i_7)] == 0 || (*i_7) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i_7)] == partner[l].number_register) {
					printf("|__________________________|");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_7)++;
				break;
			}
		}
		temp_test5 = 0;
		/////////////
		printf("\n");
		
		for ((*i7); (*i7) < num; (*i7)++) {

			if (index_of_needless_partners[(*i7)] == 0 || (*i7) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i7)] == partner[l].number_register) {
					printf("|%26s|", partner[l].requirements.face);
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i7)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");
		
		for ((*i_8); (*i_8) < num; (*i_8)++) {
			
			if (index_of_needless_partners[(*i_8)] == 0 || (*i_8) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i_8)] == partner[l].number_register) {
					printf("|__________________________|");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_8)++;
				break;
			}
		}
		temp_test5 = 0;
		/////////////
		printf("\n");
		
		for ((*i8); (*i8) < num; (*i8)++) {
			
			if (index_of_needless_partners[(*i8)] == 0 || (*i8) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i8)] == partner[l].number_register) {
					printf("|%26s|", partner[l].requirements.character);
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i8)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");
		
		for ((*i_9); (*i_9) < num; (*i_9)++) {
			
			if (index_of_needless_partners[(*i_9)] == 0 || (*i_9) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i_9)] == partner[l].number_register) {
					printf("|__________________________|");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_9)++;
				break;
			}
		}
		temp_test5 = 0;
		//////////
		printf("\n");
		
		for ((*i9); (*i9) < num; (*i9)++) {
			if (index_of_needless_partners[(*i9)] == 0 || (*i9) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i9)] == partner[l].number_register) {
					printf("|%26s|", partner[l].requirements.goroskop);
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i9)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");
		
		for ((*i_10); (*i_10) < num; (*i_10)++) {
			
			if (index_of_needless_partners[(*i_10)] == 0 || (*i_10) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i_10)] == partner[l].number_register) {
					printf("|__________________________|");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_10)++;
				break;
			}
		}
		temp_test5 = 0;
		//////////
		printf("\n");
		
		for ((*i10); (*i10) < num; (*i10)++) {
			if (index_of_needless_partners[(*i10)] == 0 || (*i10) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i10)] == partner[l].number_register) {
					printf("|%26s|", partner[l].requirements.job);
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i10)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");
		
		for ((*i_11); (*i_11) < num; (*i_11)++) {
			
			if (index_of_needless_partners[(*i_11)] == 0 || (*i_11) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i_11)] == partner[l].number_register) {
					printf("|__________________________|");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_11)++;
				break;
			}
		}
		///////
		/*printf("\n");
		if (j == 11) {
			printf("\t|%28s|", token_menu[j]);
			j++;
		}
		for ((*r25); (*r25) < 1; (*r25)++) {
			printf("|%25s|", partner[index_first_partner].information);
		}
		for ((*i11); (*i11) < num; (*i11)++) {
			if (index_of_needless_partners[(*i11)] == 0 || (*i11) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i11)] == partner[l].number_register) {
					printf("|%26s|", partner[(*i11)].information);
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0) {
				(*i11)++;
				break;
			}
		}
		printf("\n");
		for ((*r26); (*r26) < 1; (*r26)++) {
			printf("\t|____________________________||_________________________|");
		}
		for ((*i_12); (*i_12) < num; (*i_12)++) {
			if (index_of_needless_partners[(*i_12)] == 0 || (*i_12) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i_12)] == partner[l].number_register) {
					printf("|__________________________|");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0) {
				(*i_12)++;
				break;
			}
		}*/
		/*for ((*index_delete); (*index_delete) < num; (*index_delete)++) {

			if (index_of_needless_partners[(*index_delete)] == NULL) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*index_delete)] == partner[l].number_register) {
					index_of_needless_partners[(*index_delete)] = NULL;
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0) {
				(*index_delete)++;
				break;
			}
		}*/
		temp_test5 = 0;
		printf("\n");
	}
}

void output_couple(struct marryed** partner, struct my_self* me, int* index_of_needless_partners, int* num, char** token_menu,char* way2,char* way1,char* way) {
	int index_of_choosen_partner;
	for (int i = 0; i < (*num); i++) {
		if ((*partner)[i].number_register == index_of_needless_partners[i]) {
			index_of_choosen_partner = i;
		}
	}
	int j = 0;
	printf("\t _______________________________________________________  _______________________________________________________\n");
	printf("\t|---------------------->МОЯ_АНКЕТА<---------------------||-------------------->АНКЕТА_КАНДИДАТА<-----------------|\n");
	printf("\t|_______________________________________________________||_______________________________________________________|\n");
	if (j == 0) {
		printf("\t|%28s|", token_menu[j]);
		j++;
	}
	printf("|%25d||%25s%-30d|", me[0].number_register," ", (*partner)[index_of_choosen_partner].number_register);
	printf("\n");
	printf("\t|_______________________________________________________||_______________________________________________________|\n");
	if (j == 1) {
		printf("\t|%28s|", token_menu[j]);
		j++;
	}
	printf("|%25s||%25s%-30s|", me[0].requirements.name, " ", (*partner)[index_of_choosen_partner].requirements.name);
	printf("\n");
	printf("\t|_______________________________________________________||_______________________________________________________|\n");
	if (j == 2) {
		printf("\t|%28s|", token_menu[j]);
		j++;
	}
	printf("|%25s||%25s%-30s|", me[0].sex, " ", (*partner)[index_of_choosen_partner].sex);
	printf("\n");
	printf("\t|_______________________________________________________||_______________________________________________________|\n");
	if (j == 3) {
		printf("\t|%28s|", token_menu[j]);
		j++;
	}
	printf("|%-7d%9s%9d||%15s%-7d%14s%19d|", me[0].dates.date, me[0].dates.month, me[0].dates.year,"  " , (*partner)[index_of_choosen_partner].dates.date, (*partner)[index_of_choosen_partner].dates.month, (*partner)[index_of_choosen_partner].dates.year);
	printf("\n");
	printf("\t|_______________________________________________________||_______________________________________________________|\n");
	if (j == 4) {
		printf("\t|%28s|", token_menu[j]);
		j++;
	}
	printf("|%25s||%25s%-30s|", me[0].requirements.eye, " ", (*partner)[index_of_choosen_partner].requirements.eye);
	printf("\n");
	printf("\t|_______________________________________________________||_______________________________________________________|\n");
	if (j == 5) {
		printf("\t|%28s|", token_menu[j]);
		j++;
	}
	printf("|%25d||%25s%-30d|", me[0].requirements.hight, " ", (*partner)[index_of_choosen_partner].requirements.hight);
	printf("\n");
	printf("\t|_______________________________________________________||_______________________________________________________|\n");
	if (j == 6) {
		printf("\t|%28s|", token_menu[j]);
		j++;
	}
	printf("|%25s||%25s%-30s|", me[0].requirements.hair, " ", (*partner)[index_of_choosen_partner].requirements.hair);
	printf("\n");
	printf("\t|_______________________________________________________||_______________________________________________________|\n");
	if (j == 7) {
		printf("\t|%28s|", token_menu[j]);
		j++;
	}
	printf("|%25s||%25s%-30s|", me[0].requirements.face, " ", (*partner)[index_of_choosen_partner].requirements.face);
	printf("\n");
	printf("\t|_______________________________________________________||_______________________________________________________|\n");
	if (j == 8) {
		printf("\t|%28s|", token_menu[j]);
		j++;
	}
	printf("|%25s||%25s%-30s|", me[0].requirements.character, " ", (*partner)[index_of_choosen_partner].requirements.character);
	printf("\n");
	printf("\t|_______________________________________________________||_______________________________________________________|\n");
	if (j == 9) {
		printf("\t|%28s|", token_menu[j]);
		j++;
	}
	printf("|%25s||%25s%-30s|", me[0].requirements.goroskop, " ", (*partner)[index_of_choosen_partner].requirements.goroskop);
	printf("\n");
	printf("\t|_______________________________________________________||_______________________________________________________|\n");
	if (j == 10) {
		printf("\t|%28s|", token_menu[j]);
		j++;
	}
	printf("|%25s||%25s%-30s|", me[0].requirements.job, " ", (*partner)[index_of_choosen_partner].requirements.job);
	printf("\n");
	printf("\t|_______________________________________________________||_______________________________________________________|\n");
	//printf("\t|____________________________||_________________________||____________________________||_________________________|\n");
	/*if (j == 11) {
		printf("\t|%28s|", token_menu[j]);
		j++;
	}
	printf("|%15s|%15s", me[0].information, partner[index_of_choosen_partner].information);
	printf("\n");*/
	printf("\t\t\t ________________________ВИВЕДЕННЯ_ЗНАЙДЕНОЇ_ПАРИ_ЗАКІНЕНО_________________________ \n");
	printf("\t\t\t|                                                                                  |\n");
	printf("\t\t\t|_________________ВІДБУВАЄТЬСЯ_ПЕРЕНЕСЕННЯ_ЗНАЙДЕНОЇ_ПАРИ_В_АРХІВ__________________|\n");
	printf("\t\t\t|                                                                                  |\n");
	printf("\t\t\t|__________________________________________________________________________________|\n");

	char* decision;
	char* newpoint;
	decision = NULL;
	decision = (char*)malloc(10 * sizeof(char));
	printf("\t\t\tВведіть чи ви хочете перенести пару в архів (yes чи no) : "); fgets(decision, 10, stdin);
	newpoint = strchr(decision, '\n');
	if (newpoint != NULL) {
		*newpoint = '\0';
	}
	if (strcmp(decision, "yes") == 0) {
		int pointer;
		pointer = NULL;
		file = fopen(way2, "a+");
		if (file == NULL) {
			printf("ERROR WITH FILE\n");
			exit(EXIT_FAILURE);
		}
		fseek(file, 0, SEEK_END);
		pointer = ftell(file) / sizeof(char);
		/*char*** token;
		char* temp_string;
		char* temp_token;
		temp_string = NULL;
		temp_token = NULL;
		int number_string = 1;
		int number_token = 1;
		int size_token = 0;
		temp_string = (char*)malloc(400 * sizeof(char));
		temp_token = (char*)malloc(400 * sizeof(char));
		char* context_string;
		char delimiters_string[] = "\n";
		char delimiters_token[] = "#";
		char* context_token;
		temp_string = strtok_s()*/
		fprintf(file, "%s#", me[0].sex);
		fprintf(file, "%s#", me[0].dates.month);
		fprintf(file, "%s#", me[0].information);
		fprintf(file, "%s#", me[0].requirements.eye);
		fprintf(file, "%s#", me[0].requirements.hair);
		fprintf(file, "%s#", me[0].requirements.name);
		fprintf(file, "%s#", me[0].requirements.face);
		fprintf(file, "%s#", me[0].requirements.character);
		fprintf(file, "%d#", me[0].number_register);
		fprintf(file, "%d#", me[0].dates.date);
		fprintf(file, "%d#", me[0].dates.year);
		fprintf(file, "%d#", me[0].requirements.hight);
		fprintf(file, "%s#", me[0].requirements.goroskop);
		fprintf(file, "%s#", me[0].requirements.job);
		fprintf(file, "%s", "\n");

		fprintf(file, "%s#", (*partner)[index_of_choosen_partner].sex);
		fprintf(file, "%s#", (*partner)[index_of_choosen_partner].dates.month);
		fprintf(file, "%s#", (*partner)[index_of_choosen_partner].information);
		fprintf(file, "%s#", (*partner)[index_of_choosen_partner].requirements.eye);
		fprintf(file, "%s#", (*partner)[index_of_choosen_partner].requirements.hair);
		fprintf(file, "%s#", (*partner)[index_of_choosen_partner].requirements.name);
		fprintf(file, "%s#", (*partner)[index_of_choosen_partner].requirements.face);
		fprintf(file, "%s#", (*partner)[index_of_choosen_partner].requirements.character);
		fprintf(file, "%d#", (*partner)[index_of_choosen_partner].number_register);
		fprintf(file, "%d#", (*partner)[index_of_choosen_partner].dates.date);
		fprintf(file, "%d#", (*partner)[index_of_choosen_partner].dates.year);
		fprintf(file, "%d#", (*partner)[index_of_choosen_partner].requirements.hight);
		fprintf(file, "%s#", (*partner)[index_of_choosen_partner].requirements.goroskop);
		fprintf(file, "%s#", (*partner)[index_of_choosen_partner].requirements.job);
		fprintf(file, "%s", "@");
		fflush(file);
		fclose(file);
		printf("\t\t\t __________________________________________________________________________________ \n");
		printf("\t\t\t|                                                                                  |\n");
		printf("\t\t\t|_______________________ПАРА_УСПІШНО_ЗАНЕСЕННА_В_АРХІВ!!!__________________________|\n");
		printf("\t\t\t|                                                                                  |\n");
		printf("\t\t\t|__________________________________________________________________________________|\n");
		free(me);
		me = NULL;
		me = (struct my_self*)malloc(1 * sizeof(struct my_self));
		file = fopen(way1, "w");
		if (file == NULL) {
			printf("ERROR WITH FILE!!!\n");
			exit(EXIT_FAILURE);
		}
		fclose(file);
		int point;
		point = NULL;
		file = fopen(way, "r+");
		if (file == NULL) {
			printf("ERROR WITH FILE!!!\n");
			exit(EXIT_FAILURE);
		}
		fseek(file, 0, SEEK_END);
		point = ftell(file);
		rewind(file);
		char* temp_string = NULL;
		char* buffer = NULL;
		temp_string = (char*)malloc(point * sizeof(char));
		temp_string[0] = '\0';
		buffer = (char*)malloc(point * sizeof(char));
		while (fgets(buffer, point, file) != NULL) {
			strcat(temp_string, buffer);
		}
		fclose(file);
		char** token_par;
		char* context_par;
		char* temp_token_par;
		int number_token_par = 1;
		int size_token_par = 0;
		char delimiters_par[] = "\n";
		temp_token_par = strtok_s(temp_string, delimiters_par, &context_par);
		token_par = (char**)malloc(number_token_par * sizeof(char*));
		token_par[size_token_par] = (char*)malloc(400 * sizeof(char));
		while (temp_token_par != NULL) {
			strcpy(token_par[size_token_par], temp_token_par);
			number_token_par++;
			size_token_par++;
			token_par = (char**)realloc(token_par, number_token_par * sizeof(char*));
			token_par[size_token_par] = (char*)malloc(400 * sizeof(char));
			temp_token_par = strtok_s(NULL, delimiters_par, &context_par);
		}
		file = fopen(way, "w+");
		if (file == NULL) {
			printf("ERROR WITH FILE!!!\n");
			exit(EXIT_FAILURE);
		}
		rewind(file);
		for (int i = 0; i < (*num); i++) {
			if (i == index_of_choosen_partner) {
				continue;
			}
			fputs(token_par[i], file);
			fputs("\n", file);
		}
		fflush(file);
		fclose(file);
		(*num) -= 1;
		fill_str(num, partner, way);
	}
	else if (strcmp(decision, "no") == 0) {
		int point;
		point = 0;
		file = fopen(way1, "r+");
		if (file == NULL) {
			printf("ERROR WITH FILE!!!\n");
			exit(EXIT_FAILURE);
		}
		fseek(file, 0, SEEK_END);
		point = ftell(file);
		rewind(file);
		char* string_me;
		string_me = NULL;
		string_me = (char*)malloc(point * sizeof(char));
		string_me[0] = '\0';
		char* buffer_me;
		buffer_me = NULL;
		buffer_me = (char*)malloc(point * sizeof(char));
		buffer_me[0] = '\0';
		while (fgets(buffer_me, point, file) != NULL) {
			strcat(string_me, buffer_me);
			//strcat(string_me, "\n");
		}
		fclose(file);
		file = fopen(way1, "w");
		if (file == NULL) {
			printf("ERROR WITH FILE!!!\n");
			exit(EXIT_FAILURE);
		}
		rewind(file);
		fclose(file);
		file = fopen(way,"a+");
		if (file == NULL) {
			printf("ERROR WITH FILE!!!\n");
			exit(EXIT_FAILURE);
		}
		fseek(file, 0, SEEK_END);
		fputs(string_me, file);
		fflush(file);
		fclose(file);
		printf("\t\t\t __________________________________________________________________________________ \n");
		printf("\t\t\t|                                                                                  |\n");
		printf("\t\t\t|_______________________ПАРА_НЕ_БУЛО_ЗАНЕСЕННО_В_АРХІВ!!!__________________________|\n");
		printf("\t\t\t|                                                                                  |\n");
		printf("\t\t\t|__________________________________________________________________________________|\n");
		(*num) += 1;
		fill_str(num, partner, way);
	}
	else {
		printf("\t\t\t __________________________________________________________________________________ \n");
		printf("\t\t\t|                                                                                  |\n");
		printf("\t\t\t|__________________ВИ_ВИБРАЛИ_НЕПРАВИЛЬНУ_ЗАПИС_(YES_OR_NO)!!!_____________________|\n");
		printf("\t\t\t|                                                                                  |\n");
		printf("\t\t\t|__________________________________________________________________________________|\n");
		return;
	}
}

void output_all(int num, struct marryed* partner, char** token_menu,int* index_of_needless_partners) {
	/*int temp_index = 0;*/
	int* index_of_all_partner;
	index_of_all_partner = NULL;
	index_of_all_partner = (int*)malloc(num * sizeof(int));
	int index_first_partner;
	for (int i = 0; i < num; i++) {
		index_of_all_partner[i] = partner[i].number_register;
	}
	/*for (int i = 0; i < num; i++) {
		if (index_of_needless_partners[i] != 0) {
			temp_index++;
		}
		else {
			continue;
		}
	}*/
	int number_of_repet;
	if (num % 5 == 0) {
		number_of_repet = num / 5;
	}
	else if (num % 5 != 0) {
		number_of_repet = (num / 5) + 1;
	}
	/*if (temp_index == 0) {
		printf(" _________________________________________________________________________________________________________________\n");
		printf("|Ми не можемо вивести найкращого партнера, тому що ми не знайшли його(або ти просто не шукав його в базі даних)!!!|\n");
		printf("|_________________________________________________________________________________________________________________|\n");
		return;
	}*/
	/*int temp_index_first;
	for (int i = 0; i < num; i++) {
		if (index_of_needless_partners[i] != 0) {
			temp_index_first = i;
			break;
		}
	}
	for (int i = 0; i < num; i++) {
		if (index_of_needless_partners[temp_index_first] == partner[i].number_register) {
			index_first_partner = i;
		}
	}*/
	index_first_partner = -1;
	int* i;
	int temp_i = 0;
	i = &temp_i;
	int* i1;
	int temp_i1 = 0;
	i1 = &temp_i1;
	int* i2;
	int temp_i2 = 0;
	i2 = &temp_i2;
	int* i3;
	int temp_i3 = 0;
	i3 = &temp_i3;
	int* i4;
	int temp_i4 = 0;
	i4 = &temp_i4;
	int* i5;
	int temp_i5 = 0;
	i5 = &temp_i5;
	int* i6;
	int temp_i6 = 0;
	i6 = &temp_i6;
	int* i7;
	int temp_i7 = 0;
	i7 = &temp_i7;
	int* i8;
	int temp_i8 = 0;
	i8 = &temp_i8;
	int* i9;
	int temp_i9 = 0;
	i9 = &temp_i9;
	int* i10;
	int temp_i10 = 0;
	i10 = &temp_i10;
	int* i11;
	int temp_i11 = 0;
	i11 = &temp_i11;
	int* i_n;
	int temp_i_n = 0;
	i_n = &temp_i_n;
	int* i_k;
	int temp_i_k = 0;
	i_k = &temp_i_k;
	int* i_l;
	int temp_i_l = 0;
	i_l = &temp_i_l;
	int* i_1;
	int temp_i_1 = 0;
	i_1 = &temp_i_1;
	int* i_2;
	int temp_i_2 = 0;
	i_2 = &temp_i_2;
	int* i_3;
	int temp_i_3 = 0;
	i_3 = &temp_i_3;
	int* i_4;
	int temp_i_4 = 0;
	i_4 = &temp_i_4;
	int* i_5;
	int temp_i_5 = 0;
	i_5 = &temp_i_5;
	int* i_6;
	int temp_i_6 = 0;
	i_6 = &temp_i_6;
	int* i_7;
	int temp_i_7 = 0;
	i_7 = &temp_i_7;
	int* i_8;
	int temp_i_8 = 0;
	i_8 = &temp_i_8;
	int* i_9;
	int temp_i_9 = 0;
	i_9 = &temp_i_9;
	int* i_10;
	int temp_i_10 = 0;
	i_10 = &temp_i_10;
	int* i_11;
	int temp_i_11 = 0;
	i_11 = &temp_i_11;

	int* index_delete;
	int temp_delete_index = 0;
	index_delete = &temp_delete_index;

	int* r;
	int temp_r = 0;
	r = &temp_r;
	int* r1;
	int temp_r1 = 0;
	r1 = &temp_r1;
	int* r2;
	int temp_r2 = 0;
	r2 = &temp_r2;
	int* r3;
	int temp_r3 = 0;
	r3 = &temp_r3;
	int* r4;
	int temp_r4 = 0;
	r4 = &temp_r4;
	int* r5;
	int temp_r5 = 0;
	r5 = &temp_r5;
	int* r6;
	int temp_r6 = 0;
	r6 = &temp_r6;
	int* r7;
	int temp_r7 = 0;
	r7 = &temp_r7;
	int* r8;
	int temp_r8 = 0;
	r8 = &temp_r8;
	int* r9;
	int temp_r9 = 0;
	r9 = &temp_r9;
	int* r10;
	int temp_r10 = 0;
	r10 = &temp_r10;
	int* r11;
	int temp_r11 = 0;
	r11 = &temp_r11;
	int* r12;
	int temp_r12 = 0;
	r12 = &temp_r12;
	int* r13;
	int temp_r13 = 0;
	r13 = &temp_r13;
	int* r14;
	int temp_r14 = 0;
	r14 = &temp_r14;
	int* r15;
	int temp_r15 = 0;
	r15 = &temp_r15;
	int* r16;
	int temp_r16 = 0;
	r16 = &temp_r16;
	int* r17;
	int temp_r17 = 0;
	r17 = &temp_r17;
	int* r18;
	int temp_r18 = 0;
	r18 = &temp_r18;
	int* r19;
	int temp_r19 = 0;
	r19 = &temp_r19;
	int* r20;
	int temp_r20 = 0;
	r20 = &temp_r20;
	int* r21;
	int temp_r21 = 0;
	r21 = &temp_r21;
	int* r22;
	int temp_r22 = 0;
	r22 = &temp_r22;
	int* r23;
	int temp_r23 = 0;
	r23 = &temp_r23;
	int* r24;
	int temp_r24 = 0;
	r24 = &temp_r24;
	int* r25;
	int temp_r25 = 0;
	r25 = &temp_r25;
	int* r26;
	int temp_r26 = 0;
	r26 = &temp_r26;
	int* i_12;
	int temp_i_12 = 0;
	i_12 = &temp_i_12;

	int temp_test5 = 0;
	int j = 0;
	for (int k = 0; k < number_of_repet; k++) {
		for (*(i_n); *(i_n) < num; (*i_n)++) {
			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[*(i_n)] == partner[l].number_register ) {
					printf(" __________________________ ");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_n)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");
		for (*(i_k); *(i_k) < num; (*i_k)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[*(i_k)] == partner[l].number_register ) {
					printf("|------>%2d_кандидат<-------|", l + 1);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_k)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");

		for (*(i_l); *(i_l) < num; (*i_l)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[*(i_l)] == partner[l].number_register ) {
					printf("|__________________________|");
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_l)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");
		////////

		for (*i; *i < num; (*i)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i)] == partner[l].number_register ) {
					printf("|%26d|", partner[l].number_register);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");

		for (*i_1; *i_1 < num; (*i_1)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i_1)] == partner[l].number_register ) {
					printf("|__________________________|");
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_1)++;
				break;
			}
		}
		temp_test5 = 0;
		///////
		printf("\n");

		for (*i1; (*i1) < num; (*i1)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i1)] == partner[l].number_register ) {
					printf("|%26s|", partner[l].requirements.name);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i1)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");

		for ((*i_2); (*i_2) < num; (*i_2)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i_2)] == partner[l].number_register ) {
					printf("|__________________________|");
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_2)++;
				break;
			}
		}
		temp_test5 = 0;
		//////////
		printf("\n");

		for ((*i2); (*i2) < num; (*i2)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i2)] == partner[l].number_register ) {
					printf("|%26s|", partner[l].sex);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i2)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");

		for ((*i_3); (*i_3) < num; (*i_3)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i_3)] == partner[l].number_register ) {
					printf("|__________________________|");
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_3)++;
				break;
			}
		}
		temp_test5 = 0;
		/////////
		printf("\n");

		for ((*i3); (*i3) < num; (*i3)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i3)] == partner[l].number_register ) {
					printf("|%-7d%9s%10d|", partner[l].dates.date, partner[l].dates.month, partner[l].dates.year);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i3)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");

		for ((*i_4); (*i_4) < num; (*i_4)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i_4)] == partner[l].number_register ) {
					printf("|__________________________|");
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_4)++;
				break;
			}
		}
		temp_test5 = 0;
		//////////
		printf("\n");

		for ((*i4); (*i4) < num; (*i4)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i4)] == partner[l].number_register ) {
					printf("|%26s|", partner[l].requirements.eye);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i4)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");

		for ((*i_5); (*i_5) < num; (*i_5)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i_5)] == partner[l].number_register ) {
					printf("|__________________________|");
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_5)++;
				break;
			}
		}
		temp_test5 = 0;
		/////////////
		printf("\n");

		for ((*i5); (*i5) < num; (*i5)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i5)] == partner[l].number_register ) {
					printf("|%26d|", partner[l].requirements.hight);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i5)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");

		for ((*i_6); (*i_6) < num; (*i_6)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i_6)] == partner[l].number_register ) {
					printf("|__________________________|");
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_6)++;
				break;
			}
		}
		temp_test5 = 0;
		////////////
		printf("\n");

		for ((*i6); (*i6) < num; (*i6)++) {
			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i6)] == partner[l].number_register ) {
					printf("|%26s|", partner[l].requirements.hair);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i6)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");

		for ((*i_7); (*i_7) < num; (*i_7)++) {
			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i_7)] == partner[l].number_register ) {
					printf("|__________________________|");
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_7)++;
				break;
			}
		}
		temp_test5 = 0;
		/////////////
		printf("\n");

		for ((*i7); (*i7) < num; (*i7)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i7)] == partner[l].number_register ) {
					printf("|%26s|", partner[l].requirements.face);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i7)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");

		for ((*i_8); (*i_8) < num; (*i_8)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i_8)] == partner[l].number_register ) {
					printf("|__________________________|");
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_8)++;
				break;
			}
		}
		temp_test5 = 0;
		/////////////
		printf("\n");

		for ((*i8); (*i8) < num; (*i8)++) {

			
			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i8)] == partner[l].number_register ) {
					printf("|%26s|", partner[l].requirements.character);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i8)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");

		for ((*i_9); (*i_9) < num; (*i_9)++) {

			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i_9)] == partner[l].number_register ) {
					printf("|__________________________|");
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_9)++;
				break;
			}
		}
		temp_test5 = 0;
		//////////
		printf("\n");

		for ((*i9); (*i9) < num; (*i9)++) {

			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i9)] == partner[l].number_register ) {
					printf("|%26s|", partner[l].requirements.goroskop);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i9)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");

		for ((*i_10); (*i_10) < num; (*i_10)++) {

			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i_10)] == partner[l].number_register ) {
					printf("|__________________________|");
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_10)++;
				break;
			}
		}
		temp_test5 = 0;
		//////////
		printf("\n");

		for ((*i10); (*i10) < num; (*i10)++) {

			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i10)] == partner[l].number_register ) {
					printf("|%26s|", partner[l].requirements.job);
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i10)++;
				break;
			}
		}
		temp_test5 = 0;
		printf("\n");

		for ((*i_11); (*i_11) < num; (*i_11)++) {

			for (int l = 0; l < num; l++) {
				if (index_of_all_partner[(*i_11)] == partner[l].number_register ) {
					printf("|__________________________|");
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0 && number_of_repet != 1) {
				temp_test5 = 0;
				(*i_11)++;
				break;
			}
		}
		///////
		/*printf("\n");
		if (j == 11) {
			printf("\t|%28s|", token_menu[j]);
			j++;
		}
		for ((*r25); (*r25) < 1; (*r25)++) {
			printf("|%25s|", partner[index_first_partner].information);
		}
		for ((*i11); (*i11) < num; (*i11)++) {
			if (index_of_needless_partners[(*i11)] == 0 || (*i11) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i11)] == partner[l].number_register) {
					printf("|%26s|", partner[(*i11)].information);
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0) {
				(*i11)++;
				break;
			}
		}
		printf("\n");
		for ((*r26); (*r26) < 1; (*r26)++) {
			printf("\t|____________________________||_________________________|");
		}
		for ((*i_12); (*i_12) < num; (*i_12)++) {
			if (index_of_needless_partners[(*i_12)] == 0 || (*i_12) == index_first_partner) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*i_12)] == partner[l].number_register) {
					printf("|__________________________|");
					temp_test5++;
				}
			}
			if (temp_test5 % 5 == 0) {
				(*i_12)++;
				break;
			}
		}*/
		/*for ((*index_delete); (*index_delete) < num; (*index_delete)++) {

			if (index_of_needless_partners[(*index_delete)] == NULL) {
				continue;
			}
			for (int l = 0; l < num; l++) {
				if (index_of_needless_partners[(*index_delete)] == partner[l].number_register) {
					index_of_needless_partners[(*index_delete)] = NULL;
					temp_test5++;
					break;
				}
			}
			if (temp_test5 % 5 == 0) {
				(*index_delete)++;
				break;
			}
		}*/
		temp_test5 = 0;
		printf("\n");
	}
}

void sort(int num,struct marryed* partner,int** index_of_needless_partners,int type_sort,int* test,char** token_month,int number_of_month) {
	int test_to_index = 0;
	for (int i = 0; i < num; i++) {
		if ((*index_of_needless_partners)[i] != 0) {
			test_to_index++;
		}
		else {
			continue;
		}
	}
	if (test_to_index == 0) {
		printf("\t\t\t ____________________________________________________________________________________________________\n");
		printf("\t\t\t|                                                                                                    |\n");
		printf("\t\t\t|Вибачте (ERROR!!!) ви не знайшли найкращого чи найкращих кандидатій, тому вам потрібно це зробити!!!|\n");
		printf("\t\t\t|____________________________________________________________________________________________________|\n");
		*test = 1;
		return;
	}
	
	if (test_to_index == 1) {
		printf("\t\t\t ____________________________________________________\n");
		printf("\t\t\t|                                                    |\n");
		printf("\t\t\t|В вас лише один кандидат вам немає кого сортувати!!!|\n");
		printf("\t\t\t|____________________________________________________|\n");
		return;
	}
	int sort_type1;
	printf("\t\t ________________________________ \n");
	printf("\t\t|                                |\n");
	printf("\t\t|---->Введіть_тип_сортування<----|\n");
	printf("\t\t|1 - за зростанням років чи росту|\n");
	printf("\t\t|2 - за спаданням років чи росту |\n");
	printf("\t\t|________________________________|\n");
	printf("\t\t\tВведіть : "); scanf_s("%d", &sort_type1);

	int* index_register = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++) {
		index_register[i] = -1;
	}

	int* index_finded = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++) {
		index_finded[i] = -1;
	}


	int* index;
	int temp_index = 0;
	index = &temp_index;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if ((*index_of_needless_partners)[i] == partner[j].number_register && (*index_of_needless_partners)[i] != 0) {
				index_register[*index] = i;
				index_finded[*index] = j;
				(*index)++;
			}
			else if ((*index_of_needless_partners)[i] == 0) {
				break;
			}
		}
	}

	if (sort_type1 == 2) {
		*test = 0;
		if (type_sort == 1) {
			int* month_num;
			month_num = (int*)malloc(num * sizeof(int));
			for (int i = 0; i < num; i++) {
				month_num[i] = NULL;
			}
			for (int i = 0; i < num; i++) {
				if (index_finded[i] == -1) {
					continue;
				}
				for (int j = 0; j < number_of_month; j++) {
					if (strcmp(partner[index_finded[i]].dates.month, token_month[j]) == 0) {
						month_num[index_finded[i]] = j + 1;
					}
				}
			}
			int temp_number;
			int temp_test = 1;
			while (temp_test != 0) {
				temp_test = 0;
				for (int i = (*index) - 1; i > 0; i--) {
					if (partner[index_finded[i]].dates.year < partner[index_finded[i - 1]].dates.year) {
						temp_number = (*index_of_needless_partners)[index_register[i]];
						(*index_of_needless_partners)[index_register[i]] = (*index_of_needless_partners)[index_register[i - 1]];
						(*index_of_needless_partners)[index_register[i - 1]] = temp_number;
						temp_number = index_finded[i];
						index_finded[i] = index_finded[i - 1];
						index_finded[i - 1] = temp_number;
						temp_test = 1;
					}
					else if (partner[index_finded[i]].dates.year == partner[index_finded[i - 1]].dates.year) {
						if (month_num[index_finded[i]] < month_num[index_finded[i - 1]]) {
							temp_number = (*index_of_needless_partners)[index_register[i]];
							(*index_of_needless_partners)[index_register[i]] = (*index_of_needless_partners)[index_register[i - 1]];
							(*index_of_needless_partners)[index_register[i - 1]] = temp_number;
							temp_number = index_finded[i];
							index_finded[i] = index_finded[i - 1];
							index_finded[i - 1] = temp_number;
							temp_test = 1;
						}
						else if (month_num[index_finded[i]] == month_num[index_finded[i - 1]]) {
							if (partner[index_finded[i]].dates.date < partner[index_finded[i - 1]].dates.date) {
								temp_number = (*index_of_needless_partners)[index_register[i]];
								(*index_of_needless_partners)[index_register[i]] = (*index_of_needless_partners)[index_register[i - 1]];
								(*index_of_needless_partners)[index_register[i - 1]] = temp_number;
								temp_number = index_finded[i];
								index_finded[i] = index_finded[i - 1];
								index_finded[i - 1] = temp_number;
								temp_test = 1;
							}
							else if (partner[index_finded[i]].dates.date == partner[index_finded[i - 1]].dates.date) {
								continue;
							}
						}
					}
				}
			}
		}
		else if (type_sort == 2) {
			int temp_test = 1;
			int temp_number;
			while (temp_test != 0) {
				temp_test = 0;
				for (int i = (*index) - 1; i > 0; i--) {
					if (partner[index_finded[i]].requirements.hight > partner[index_finded[i - 1]].requirements.hight) {
						temp_number = (*index_of_needless_partners)[index_register[i]];
						(*index_of_needless_partners)[index_register[i]] = (*index_of_needless_partners)[index_register[i - 1]];
						(*index_of_needless_partners)[index_register[i - 1]] = temp_number;
						temp_number = index_finded[i];
						index_finded[i] = index_finded[i - 1];
						index_finded[i - 1] = temp_number;
						temp_test = 1;
					}
					else if (partner[index_finded[i]].requirements.hight == partner[index_finded[i - 1]].requirements.hight) {
						continue;
					}
				}
			}
		}
		else {
			printf(" ____________________________________________________________________________________________________\n");
			printf("|                                                                                                    |\n");
			printf("|          Ви ввели не правильний тип сортування (введіть 1 - за датою або 2 - за ростом)!!!         |\n");
			printf("|____________________________________________________________________________________________________|\n");
			while (getchar() != '\n');
			*test = 1;
		}
	}
	else if (sort_type1 == 1) {
		*test = 0;
		if (type_sort == 1) {
			int* month_num;
			month_num = (int*)malloc(num * sizeof(int));
			for (int i = 0; i < num; i++) {
				month_num[i] = NULL;
			}
			for (int i = 0; i < num; i++) {
				if (index_finded[i] == -1) {
					continue;
				}
				for (int j = 0; j < number_of_month; j++) {
					if (strcmp(partner[index_finded[i]].dates.month, token_month[j]) == 0) {
						month_num[index_finded[i]] = j + 1;
					}
				}
			}
			int temp_number;
			int temp_test = 1;
			while (temp_test != 0) {
				temp_test = 0;
				for (int i = (*index) - 1; i > 0; i--) {
					if (partner[index_finded[i]].dates.year > partner[index_finded[i - 1]].dates.year) {
						temp_number = (*index_of_needless_partners)[index_register[i]];
						(*index_of_needless_partners)[index_register[i]] = (*index_of_needless_partners)[index_register[i - 1]];
						(*index_of_needless_partners)[index_register[i - 1]] = temp_number;
						temp_number = index_finded[i];
						index_finded[i] = index_finded[i - 1];
						index_finded[i - 1] = temp_number;
						temp_test = 1;
					}
					else if (partner[index_finded[i]].dates.year == partner[index_finded[i - 1]].dates.year) {
						if (month_num[index_finded[i]] > month_num[index_finded[i - 1]]) {
							temp_number = (*index_of_needless_partners)[index_register[i]];
							(*index_of_needless_partners)[index_register[i]] = (*index_of_needless_partners)[index_register[i - 1]];
							(*index_of_needless_partners)[index_register[i - 1]] = temp_number;
							temp_number = index_finded[i];
							index_finded[i] = index_finded[i - 1];
							index_finded[i - 1] = temp_number;
							temp_test = 1;
						}
						else if (month_num[index_finded[i]] == month_num[index_finded[i - 1]]) {
							if (partner[index_finded[i]].dates.date > partner[index_finded[i - 1]].dates.date) {
								temp_number = (*index_of_needless_partners)[index_register[i]];
								(*index_of_needless_partners)[index_register[i]] = (*index_of_needless_partners)[index_register[i - 1]];
								(*index_of_needless_partners)[index_register[i - 1]] = temp_number;
								temp_number = index_finded[i];
								index_finded[i] = index_finded[i - 1];
								index_finded[i - 1] = temp_number;
								temp_test = 1;
							}
							else if (partner[index_finded[i]].dates.date == partner[index_finded[i - 1]].dates.date) {
								continue;
							}
						}
					}
				}
			}
		}
		else if (type_sort == 2) {
			int temp_test = 1;
			int temp_number;
			while (temp_test != 0) {
				temp_test = 0;
				for (int i = (*index) - 1; i > 0; i--) {
					if (partner[index_finded[i]].requirements.hight < partner[index_finded[i - 1]].requirements.hight) {
						temp_number = (*index_of_needless_partners)[index_register[i]];
						(*index_of_needless_partners)[index_register[i]] = (*index_of_needless_partners)[index_register[i - 1]];
						(*index_of_needless_partners)[index_register[i - 1]] = temp_number;
						temp_number = index_finded[i];
						index_finded[i] = index_finded[i - 1];
						index_finded[i - 1] = temp_number;
						temp_test = 1;
					}
					else if (partner[index_finded[i]].requirements.hight == partner[index_finded[i - 1]].requirements.hight) {
						continue;
					}
				}
			}
		}
		else {
			printf(" ____________________________________________________________________________________________________\n");
			printf("|                                                                                                    |\n");
			printf("|          Ви ввели не правильний тип сортування (введіть 1 - за датою або 2 - за ростом)!!!         |\n");
			printf("|____________________________________________________________________________________________________|\n");
			while (getchar() != '\n');
			*test = 1;
		}
	}
	else {
		printf(" ____________________________________________________________________________________________________\n");
		printf("|                                                                                                    |\n");
		printf("|      Ви ввели не правильний тип сортування (введіть 1 - за зростанням або 2 - за спаданням)!!!     |\n");
		printf("|____________________________________________________________________________________________________|\n");
		while (getchar() != '\n');
		*test = 1;
	}
}

void delete_partner(int* num, struct marryed** partner, char* del_name, char* del_dates, char* del_sex, char* del_eye, char* del_hair, int del_hight, char** token_month, int number_of_month, char** token_menu, char* way, int test_name, int test_dates, int test_sex, int test_eye, int test_hair, int test_hight,int** index_to_indeficate_partner,int* test_of_number_delete_partner) {
	if (test_name != 1 && test_dates != 1 && test_eye != 1 && test_hair != 1 && test_sex != 1 && test_hight != 1) {
		printf("\t\t\t __________________________________________________________ \n");
		printf("\t\t\t|                                                          |\n");
		printf("\t\t\t|------>ВИ НЕ ВИКОНАЛИ ЩОДНОГО ПОШУКУ ЗА ПАРАМЕТРАМИ<------|\n");
		printf("\t\t\t|                                                          |\n");
		printf("\t\t\t|__________________________________________________________|\n");
		return;

	}
	int* temp_index_of_need_partner;
	temp_index_of_need_partner = NULL;
	temp_index_of_need_partner = (int*)malloc((*num) * sizeof(int));
	for (int i = 0; i < (*num); i++) {
		temp_index_of_need_partner[i] = NULL;
	}
	int index_of_partner_delete;
	int index_test = 0;
	int temp_number;
	if (test_dates == 1) {
		int delete_date = 0;
		char* delete_month = NULL;
		int delete_year = 0;
		delete_month = (char*)malloc(100 * sizeof(char));
		if (del_dates != NULL) {
			char** token;
			char* temp_token_date;
			char* context;
			context = NULL;
			char delimiters[] = ".";
			int size_token = 1;
			int number_token = 0;
			token = (char**)malloc(size_token * sizeof(char*));
			token[number_token] = (char*)malloc(100 * sizeof(char));
			temp_token_date = strtok_s(del_dates, delimiters, &context);
			while (temp_token_date != NULL) {
				strcpy(token[number_token], temp_token_date);
				size_token++;
				number_token++;
				token = (char**)realloc(token, size_token * sizeof(char*));
				token[number_token] = (char*)malloc(100 * sizeof(char));
				temp_token_date = strtok_s(NULL, delimiters, &context);
				if (temp_token_date == NULL) {
					break;
				}
			}
			delete_date = atoi(token[0]);
			temp_number = atoi(token[1]);
			delete_year = atoi(token[2]);
			strcpy(delete_month, token_month[temp_number - 1]);
			find_candidat_delete_with_date(*num, *partner, del_name, delete_date, delete_month, delete_year, del_sex, del_eye, del_hair, del_hight, &temp_index_of_need_partner);
		}
		else if (del_dates == NULL) {
			find_candidat_delete_without_date(*num, *partner, del_name, del_sex, del_eye, del_hair, del_hight, &temp_index_of_need_partner);
		}
	}
	else {
		find_candidat_delete_without_date(*num, *partner, del_name, del_sex, del_eye, del_hair, del_hight, &temp_index_of_need_partner);
	}
	temp_number = 0;
	for (int i = 0; i < (*num); i++) {
		if (temp_index_of_need_partner[i] != NULL) {
			temp_number++;
		}
		else {
			continue;
		}
	}
	if (temp_number == 0) {
		printf("\t ____________________________________________________________________________________________________\n");
		printf("\t|                                                                                                    |\n");
		printf("\t|Вибачте (ERROR!!!) ви не знайшли найкращого чи найкращих кандидатій, тому вам потрібно це зробити!!!|\n");
		printf("\t|____________________________________________________________________________________________________|\n");
		return;
	}
	else {
		printf("\t\t ______________________________________ \n");
		printf("\t\t|---------->ЦЕ_ВАШІ_КАНДИДАТИ<---------|\n");
		printf("\t\t|______________________________________|\n");
		output_finded(*num, *partner, temp_index_of_need_partner, token_menu);
		if (temp_number > 1) {
			printf("\tВведіть якого кандидата ви хочете видалити : "); scanf_s("%d", &index_of_partner_delete);
			while (getchar() != '\n');
			for (int i = 0; i < (*num); i++) {
				if (temp_index_of_need_partner[i] != NULL && index_of_partner_delete == i + 1) {
					index_of_partner_delete = i;
					(*index_to_indeficate_partner)[i] = index_of_partner_delete;
				}
			}
		}
		else if (temp_number == 1) {
			for (int i = 0; i < (*num); i++) {
				if (temp_index_of_need_partner[i] != NULL) {
					index_of_partner_delete = i;
					(*index_to_indeficate_partner)[i] = index_of_partner_delete;
				}
			}
		}
		int newpoint;
		char* buffer;
		char* temp_string;
		char* temp_context1;
		file = fopen(way, "r+");
		if (file == NULL) {
			printf("ПОМИЛКА ВІДКРИТТЯ ФАЙЛА!!!\n");
			exit(EXIT_FAILURE);
		}
		fseek(file, 0, SEEK_END);
		newpoint = ftell(file) / sizeof(char);
		rewind(file);
		buffer = (char*)malloc(newpoint * sizeof(char));
		temp_string = (char*)malloc(newpoint * sizeof(char));
		temp_string[0] = '\0';
		while (fgets(buffer, newpoint, file) != NULL) {
			strcat(temp_string, buffer);
		}
		char** token1;
		char* temp_token1;
		char* context1;
		context1 = NULL;
		char delimiters1[] = "\n";
		int size_token1 = 1;
		int number_token1 = 0;
		token1 = (char**)malloc(size_token1 * sizeof(char*));
		token1[number_token1] = (char*)malloc(400 * sizeof(char));
		temp_token1 = strtok_s(temp_string, delimiters1, &context1);
		while (temp_token1 != NULL) {
			strcpy(token1[number_token1], temp_token1);
			size_token1++;
			number_token1++;
			token1 = (char**)realloc(token1, size_token1 * sizeof(char*));
			token1[number_token1] = (char*)malloc(400 * sizeof(char*));
			temp_token1 = strtok_s(NULL, delimiters1, &context1);
			if (temp_token1 == NULL) {
				break;
			}
		}
		for (int i = 0; i < number_token1; i++) {
			strcat(token1[i], "\n");
		}
		fclose(file);
		file = fopen(way, "w");
		if (file == NULL) {
			printf("ПОМИЛКА ВІДКРИТТЯ ФАЙЛА!!!\n");
			exit(EXIT_FAILURE);
		}
		rewind(file);
		for (int i = 0; i < (*num); i++) {
			if (index_of_partner_delete == i) {
				continue;
			}
			else {
				fputs(token1[i], file);
				fflush(file);
			}
		}
		fclose(file);
	}
	*partner = NULL;
	*num = 0;
	*partner = (struct marryed*)malloc((*num) + 1 * sizeof(struct marryed));
	fill_str(num, partner, way);
	//information(*num, partner);
	(*test_of_number_delete_partner)++;
}

void find_candidat_delete_with_date(int num, struct marryed* partner, char* del_name, int delete_date,char* delete_month,int delete_year, char* del_sex, char* del_eye, char* del_hair, int del_hight, int** temp_index_of_need_partner) {
	int* number_same;
	number_same = NULL;
	number_same = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++) {
		number_same[i] = 0;
	}
	for (int i = 0; i < num; i++) {
		if (strcmp(partner[i].requirements.name, del_name) == 0 && del_name != NULL) {
			number_same[i]++;
		}
		if (partner[i].dates.date == delete_date && delete_date != 0) {
			number_same[i]++;
		}
		if (strcmp(partner[i].dates.month, delete_month) == 0 && delete_month != NULL) {
			number_same[i]++;
		}
		if (partner[i].dates.year == delete_year && delete_year != 0) {
			number_same[i]++;
		}
		if (strcmp(partner[i].sex, del_sex) == 0 && del_sex != NULL) {
			number_same[i]++;
		}
		if (strcmp(partner[i].requirements.eye, del_eye) == 0 && del_eye != NULL) {
			number_same[i]++;
		}
		if (strcmp(partner[i].requirements.hair, del_hair) == 0 && del_hair != NULL) {
			number_same[i]++;
		}
		if (partner[i].requirements.hight == del_hight && del_hight != 0) {
			number_same[i]++;
		}
	}
	
	int max = 0;
	for (int i = 0; i < num; i++) {
		if (number_same[i] >= number_same[max]) {
			max = i;
		}
		else {
			continue;
		}
	}
	for (int i = 0; i < num; i++) {
		if (number_same[i] == number_same[max]) {
			(*temp_index_of_need_partner)[i] = partner[i].number_register;
		}
	}
}

void find_candidat_delete_without_date(int num, struct marryed* partner, char* del_name, char* del_sex, char* del_eye, char* del_hair, int del_hight, int** temp_index_of_need_partner) {
	int* number_same;
	number_same = NULL;
	number_same = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++) {
		number_same[i] = 0;
	}
	for (int i = 0; i < num; i++) {
		if (strcmp(partner[i].requirements.name, del_name) == 0 && del_name != NULL) {
			number_same[i]++;
		}
		if (strcmp(partner[i].sex, del_sex) == 0 && del_sex != NULL) {
			number_same[i]++;
		}
		if (strcmp(partner[i].requirements.eye, del_eye) == 0 && del_eye != NULL) {
			number_same[i]++;
		}
		if (strcmp(partner[i].requirements.hair, del_hair) == 0 && del_hair != NULL) {
			number_same[i]++;
		}
		if (partner[i].requirements.hight == del_hight && del_hight != 0) {
			number_same[i]++;
		}
	}

	int max = 0;
	for (int i = 0; i < num; i++) {
		if (number_same[i] >= number_same[max]) {
			max = i;
		}
		else {
			continue;
		}
	}
	for (int i = 0; i < num; i++) {
		if (number_same[i] == number_same[max]) {
			(*temp_index_of_need_partner)[i] = partner[i].number_register;
		}
	}
}