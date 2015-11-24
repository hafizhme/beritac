#ifndef CATEGORY_H
#define CATEGORY_H
#include "news.h"

struct infoCategory
{
	char id[5];
	char nameCategory[20];
	char descCategory[50];
};

typedef struct elmCategory *adrCategory;

struct elmCategory
{
	infoCategory info;
	adrCategory prev, next;
	News news;
};
struct Category
{
	adrCategory first;
};

#endif