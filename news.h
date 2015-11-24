#ifndef NEWS_H
#define NEWS_H
#include <string>

using namespace std;

struct infoNews
{
	char id[5];
	char title[30];
	char tanggal;
	char waktu;
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

#endif