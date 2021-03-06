#ifndef CATEGORY_H
#define CATEGORY_H
#include "news.h"
#include <string>

struct infoCategory
{
	string idCategory;
	string nameCategory;
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

void createCategory(Category *C);
adrCategory alocate(infoCategory iC);
void insertCategory(Category *C, infoCategory iC);
adrCategory findCategory(Category C, infoCategory F);
void deleteCategory(Category *C, infoCategory F);
void printCategory(Category C);

#endif
