#ifndef CATEGORY_H
#define CATEGORY_H
#include "news.h"

struct infotype
{
	char id[5];
	char nameCategory[20];
};

typedef struct Category *adrCategory;

struct elmCategory
{
	info infotype;
	adrCategory prev, next;
	adrNews news;
};
struct Category
{
	adrCategory first;
};

#endif