#ifndef NEWS_H
#define NEWS_H
#include <string>

struct infotype
{
	char id[5];
	char title[30];
	char tanggal;
	char waktu;
	string body;
};

typedef struct News *adrNews;

struct elmNews
{
	info infotype;
	adrNews prev, next;
};
struct News
{
	adrNews first;
};

#endif