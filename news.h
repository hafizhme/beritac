#ifndef NEWS_H
#define NEWS_H
#include <string>

using namespace std;

struct t_date {
	int dd;		// hari : 01 - 31
	int mm;		// bulan : 01 - 12
	int yyyy;	// tahun : 2000 - 2020
	int dt = yyyy*10000 + mm*100 + dd;
};

struct infoNews
{
	char idNews[5];
	char title[30];
	t_date date;
	string body;
};

typedef struct elmNews *adrNews;

struct elmNews
{
	infoNews info;
	adrNews prev, next;
};
struct News
{
	adrNews first;
};
void createNews(News *N);
adrNews alocate(infoNews iN);
void insertNews(News *N, infoNews iN);
adrNews findNews(News N, infoNews F);
void deleteNews(News *N, infoNews F);
void printNews(News N);

#endif
