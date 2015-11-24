#ifndef AUTHOR_H
#define AUTHOR_H
#include "category.h"

struct infoAuthor
{
	char idAuthor[5];
	char nameAuthor[20];
};

typedef struct elmAuthor *adrAuthor;

struct elmAuthor
{
	infoAuthor info;
	adrAuthor prev, next;
	adrCategory category;
};
struct Author
{
	adrAuthor first;
};

#endif