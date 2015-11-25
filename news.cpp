
#include "news.h"
#include <iostream>
#include <stdio.h>

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
	adrNews eN;

	eN = alocate(iN);
	if (N->first != NULL){
		eN->next = N->first;
	  	N->first->prev = eN;
	}
 	N->first = eN;
}
adrNews findNews(News N, infoNews F)
{
	adrNews P;

	P = N.first;
	while (!(P == NULL) && !(P->info.title == F.title))
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