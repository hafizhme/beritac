#ifndef AUTHOR_H
#define AUTHOR_H
#include "category.h"

struct infotype
{
	char id[5];
	char nameAuthor[20];
};

typedef struct Author *adrAuthor;

struct elmAuthor
{
	info infotype;
	adrAuthor prev, next;
	adrCategory category;
};
struct Author
{
	adrAuthor first;
};

#endif