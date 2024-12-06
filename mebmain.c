#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "meb.h"

int main(){
baza a ={NULL,NULL};
load("mebel.txt",&a);
int option;
char title[100];

do{
	printf("\nВыберите опцию\n");
	printf("1. Вывести базу данных\n");
        printf("2. Добавить новый элемент\n");
        printf("3. Удалить элемент\n");
        printf("4. Найти элемент\n");
        printf("5. Изменить информацию об элементе\n");
        printf("6. Завершить работу\n");
        printf("Введите выбранное число: ");
        scanf("%i", &option);
	printf("\n");

switch(option){
	case 1:
		all_vivod(&a);
		break;
	case 2:
		add(&a ,1);
		save("mebel.txt", &a);
		all_vivod(&a);
		break;
	case 3:
		printf("Название элемента для удаления: ");
                scanf("%s", title);
                delite(&a, title);
		save("mebel.txt", &a);
		all_vivod(&a);
                break;
	case 4:
		printf("Название элемента для поиска: ");
                scanf("%s", title);
                int art;
                printf("Артикул элемента: ");
                scanf("%i", &art);
                search(&a, title, art);
                break;
	case 5:
		printf("Название элемента для редактирования: ");
		scanf("%s", title);
		redact(&a, title);
		save("mebel.txt", &a);
		all_vivod(&a);
		break;
	case 6:
		break;
	default:
		printf("Некорректный выбор, попробуйте еще раз\n");
		break;
	}
}while (option != 6);

mebel* con = a.first;
while (con != NULL){
	mebel* nexty = con->next;
	free(con);
	con=nexty;
}
return 0;
}
