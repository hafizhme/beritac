
#include "berita.h"
#include <iostream>
#include <stdio.h>

using namespace std;

adrNews alocate(infoAuthor iA)
{
	adrAuthor eA = new elmAuthor();

	eA->info = iA;
	eA->prev = NULL;
	eA->next = NULL;

	return eA;
}

    
		
void insertAuthor(Author *A, infoAuthor iA){
	adrAuthor eA, P;

	eA = alocate(iA);
	P = A->first;
	if (P != NULL){
		eA->next = P;
	  	P->prev=eA;
	}
  A->first = eA;
}
