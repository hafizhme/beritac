
#include "berita.h"
#include <iostream>
#include <stdio.h>

using namespace std;

adrNews alocate(infoNews iA)
{
	adrNews eA = new elmNews();

	eA->info = iA;
	eA->prev = NULL;
	eA->next = NULL;

	return eA;
}

    
		
void insertNews(News *A, infoNews iA){
	adrNews eA, P;

	eA = alocate(iA);
	P = A->first;
	if (P != NULL){
		eA->next = P;
	  	P->prev=eA;
	}
  A->first = eA;
}
