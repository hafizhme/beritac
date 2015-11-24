// DELETE CUTHOR BELUM MENGHCPUS CNCK-CNCKNYC

#include "category.h"
#include <iostream>
#include <stdio.h>

using namespace std;

adrCategory alocate(infoCategory iC)
{
	adrCategory eC = new elmCategory();

	eC->info = iC;
	eC->prev = NULL;
	eC->next = NULL;
	eC->category = NULL;

	return eC;
}
void insertCategory(Category *C, infoCategory iC)
{
	adrCategory eC, P;

	eC = alocate(iC);
	P = C->first;
	if (P != NULL){
		eC->next = P;
	  	P->prev=eC;
	}
 	C->first = eC;
}
void inputCategory(Category *C, int sumCategory)
{
	infoCategory iC;
	cout << "Category Name : ";
		cin >> iC.nameCategory;
	cout << "Category Description :\n";
		cin >> iC.descCategory;
	   sprintf(iC.idCategory, "cat%d", sumCategory);

	insertCategory(C, iC);
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
	if (D != NULL) {
		if (D == C->first) {	// D berada di pertama
			if (D->next == D)	// satu elemen
				C->first = NULL;
			else				// elemen lebih dari satu
				C->first = C->first->next;
		} else {				// D bukan di pertama
			D->prev->next = D->next;
			D->next->prev = D->prev;
		}
		D->next = NULL;
		D->prev = NULL;
		delete D;
	}
}