#ifndef MEB_H
#define MEB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct mebel {
	char name[50];
	char color[50];
	int art;
	struct mebel* next;
} mebel;
typedef struct baza{
	mebel* first;
	mebel* last;
} baza;

void all_vivod(baza* a);
void add(baza* a, int f);
void delite(baza* a, char* name);
void search(baza* a, char*name, int art);
void redact(baza* a, char* name);
void save(const char* filename, baza* a);
void load(char* filename, baza* a);
#endif
