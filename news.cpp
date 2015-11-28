#include "news.h"
#include <iostream>
#include <cstring>

using namespace std;

void createNews(News *N)
{
	N->first =  NULL;
}
adrNews alocate(infoNews iN)
{
	adrNews eN = new elmNews();

	eN->info = iN;
	eN->prev = NULL;
	eN->next = NULL;

	return eN;
}
void insertNews(News *N, infoNews iN)
{
	// urut dari yang terbaru, hingga terlama
	// paling baru berada di first
	adrNews eN;
	adrNews P;

	eN = alocate(iN);
	if (N->first != NULL){
		P = N->first;
		while (!(eN->info.date.dt > P->info.date.dt) && !(P->next == NULL))
			P = P->next;

		if (P == N->first) {
			N->first = eN;
			eN->next = P;
			P->prev = eN;
		} else {
			eN->next = P;
			eN->prev = P->prev;
			P->prev->next = eN;
			P->prev = eN;
		}
	} else {
		N->first = eN;
	}
}
adrNews findNews(News N, infoNews F)
{
	adrNews P;

	P = N.first;
	while (!(P == NULL) && !(P->info.idNews == F.idNews))
		P = P->next;
	return P;
}
void deleteNews(News *N, infoNews F)
{
	adrNews D;

	D = findNews(*N, F);
	if (D == N->first) {			// D first
		N->first = (N->first)->prev;
		D->prev = NULL;
		D->next = NULL;
	} else if (D->next != NULL){	// D mid
		D->prev->next = D->next;
		D->next->prev = D->prev;
		D->next = NULL;
		D->prev = NULL;
	} else {						// D last
		D->prev->next = D->next;
		D->next = NULL;
		D->prev = NULL;
	}
	delete D;
}
void printNews(News N)
{
	adrNews P;

	P = N.first;
	if (P!=NULL) {
		cout << "idNews |  nameNews\n";

		while (P != NULL) {
			cout << "   " << P->info.idNews;
			cout << "\t"  << P->info.title;
			cout << endl;

			P = P->next;
		}
	} else {
		cout << "   tidak ada data" << endl;
	}
}
