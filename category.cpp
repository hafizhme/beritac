#include "category.h"
#include "author.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void createCategory(Category *C)
{
	C->first = NULL;
}
adrCategory alocate(infoCategory iC)
{
	adrCategory eC = new elmCategory();

	eC->info = iC;
	eC->prev = NULL;
	eC->next = NULL;
	eC->news.first = NULL;

	return eC;
}
void insertCategory(Category *C, infoCategory iC)
{	// insert first
	adrCategory eC, P;

	eC = alocate(iC);
	P = C->first;
	if (P != NULL){
		eC->next = P;
	  	P->prev=eC;
	}
 	C->first = eC;
}
adrCategory findCategory(Category C, infoCategory F)
{
	adrCategory P;

	P = C.first;
	if (P->info.nameCategory == F.nameCategory)
		return P;
	else {
		P = P->next;
		while (!(P == C.first) && !(P->info.nameCategory == F.nameCategory))
			P = P->next;
		if (P != C.first)
			return P;
		else
			return NULL;
	}
}
void deleteCategory(Category *C, infoCategory F)
{
	adrCategory D;

	D = findCategory(*C, F);
	if (D == C->first) {			// D first
		C->first = (C->first)->prev;
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