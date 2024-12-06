#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "meb.h"

void all_vivod(baza* a){
	mebel* con=a->first;
	if(con == NULL){
		printf("Список пуст\n");
		return;}
	printf("Список мебели в наличии: \n");
	while (con != NULL){
		printf("Вид мебели: %s, Цвет: %s, Артикул: %i\n",con->name,con->color,con->art);
	con=con->next;
}}

void add(baza* a, int f){
	mebel* one = malloc(sizeof(mebel));
	if(one == NULL){
		return;}
	if(f){
		printf("Введите вид мебели (1 слово): \n");
		if (scanf(" %49[^\n]", one->name) != 1){
			free(one);
			return;
        }
		printf("Введите цвет (1 слово): ");
		if (scanf(" %49[^\n]", one->color) != 1) {
			free(one);
			return;
        }
		printf("Введите артикул: ");
		if (scanf("%i", &one->art) != 1) {
			free(one);
			while (getchar() != '\n' && getchar() != EOF);
			return;
        }
		while (getchar() != '\n' && getchar() != EOF);
    }
	one->next = NULL;
	if (a->first == NULL) {
		a->first = one;
		a->last = one;}
	else {
		a->last->next = one;
		a->last = one;
    }
}

void delite(baza* a, char* name){
	mebel* con = a->first;
    	mebel* pro = NULL;
    	while (con != NULL) {
        	if (strcmp(con->name, name) == 0) {
            		if (pro == NULL) {
                		a->first = con->next;}
            		else {
                		pro->next = con->next;}
            	if (con == a->last) {
                	a->last = pro;}
            	free(con);
            	printf("Удален объект: %s \n", name);
            	return ;
		}
		pro = con;
		con = con->next;
	}
	printf("Объект %s не найден.\n", name);
}

void search(baza* a, char*name, int art){
	mebel* con = a->first;
	int set=0;
	while (con != NULL){
		if((strcmp(con->name, name) == 0)&&(con->art == art)){
			printf("По запросу нашлось: %s %s %i\n",con->name,con->color,con->art);
			set = 1;}
		else if((strcmp(con->name, name) == 0)||(con->art == art)){
			printf("Похожие данные: %s %s %i\n",con->name,con->color,con->art);
			set = 1;}
		con=con->next;
	}
	if(!set){
		printf("Данных по вашему запросу не нашлось\n");
		return;}
}

void redact(baza* a, char* name){
	mebel* con = a->first;
	int found = 0;
	while (con != NULL){
		if (strcmp(con->name, name) == 0){
			printf("Редактирование элемента %s:\n", name);

			        char newName[50];
           			char newColor[50];

			printf("Введите новый вид мебели (1 слово): \n");
	                scanf("%s", newName);
			strcpy(con->name, newName);

        	        printf("Введите новый цвет (1 слово): \n");
                	scanf("%s", newColor);
			strcpy(con->color, newColor);

			printf("Введите новый артикул: \n");
	                scanf("%d", &con->art);

		found = 1;
		break;
	}
		con=con->next;
	}
		if (!found){
		printf("Элемент не найден");
}
while(getchar() != '\n' && getchar() != EOF);
}

void save(const char* filename, baza* a){
	FILE* file = fopen(filename, "w");
	if(file==NULL){
		return;
	}
	mebel* con = a->first;
	while (con != NULL){
		fprintf(file, "%s %s %i\n", con->name, con->color, con->art);
		con=con->next;
	}
	fclose(file);
}

void load(char* filename, baza* a) {
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		fprintf(stderr, "Ошибка открытия файла: %s\n", filename);
		return;
	}
	char name[50], color[50];
	int art;

	while (fscanf(file, "%s %s %i", name, color, &art) == 3) {
		add(a, 0);
		strcpy(a->last->name, name);
		strcpy(a->last->color, color);
		a->last->art = art;
	}
	if (ferror(file)){
		printf("Ошибка чтения данных из файлa");
	}
	fclose(file);
}
