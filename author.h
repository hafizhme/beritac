#ifndef AUTHOR_H
#define AUTHOR_H
#include "category.h"
#include <string>

using namespace std;

struct infoAuthor
{
	string idAuthor;
	string nameAuthor;
};

typedef struct elmAuthor *adrAuthor;

struct elmAuthor
{
	infoAuthor info;
	adrAuthor prev, next;
	Category category;
};
struct Author
{
	adrAuthor first;
};

void createAuthor(Author *A);
adrAuthor alocate(infoAuthor iA);
void insertAuthor(Author *A, infoAuthor iA);
void inputAuthor(Author *A, int sumAuthor);
adrAuthor findAuthor(Author A, infoAuthor F);
void deleteAuthor(Author *A, infoAuthor F);
void printAuthor(Author A);

#endif
