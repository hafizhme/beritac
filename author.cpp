#include "author.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void createAuthor(Author *A)
{
	A->first = NULL;
}
adrAuthor alocate(infoAuthor iA)
{
	adrAuthor eA = new elmAuthor();

	eA->info = iA;
	eA->prev = NULL;
	eA->next = NULL;
	eA->category.first = NULL;

	return eA;
}
void insertAuthor(Author *A, infoAuthor iA)
{
	adrAuthor eA, P;

	eA = alocate(iA);
	P = A->first;
	if (P == NULL) {
		A->first = eA;
		eA->next = eA;
		eA->prev = eA;
	} else {
		while (!(P->info.nameAuthor < eA->info.nameAuthor) && !(P->next == NULL))
			P = P->next;
		eA->next = P->next;
		eA->prev = P;
		P->next = eA;
		eA->next->prev = eA;
	}
}
void inputAuthor(Author *A, int sumAuthor)
{
	infoAuthor iA;
	cout << "Author Name : ";
		cin >> iA.nameAuthor;
	   sprintf(iA.idAuthor, "aut%d", sumAuthor);

	insertAuthor(A, iA);
}
adrAuthor findAuthor(Author A, infoAuthor F)
{
	adrAuthor P;

	P = A.first;
	if (P->info.nameAuthor == F.nameAuthor)
		return P;
	else {
		P = P->next;
		while (!(P == A.first) && !(P->info.nameAuthor == F.nameAuthor))
			P = P->next;
		if (P != A.first)
			return P;
		else
			return NULL;
	}
}
void deleteAuthor(Author *A, infoAuthor F)
{
	adrAuthor D;

	D = findAuthor(*A, F);
	if (D != NULL) {
		if (D == A->first) {	// D berada di pertama
			if (D->next == D)	// satu elemen
				A->first = NULL;
			else				// elemen lebih dari satu
				A->first = A->first->next;
		} else {				// D bukan di pertama
			D->prev->next = D->next;
			D->next->prev = D->prev;
		}
		D->next = NULL;
		D->prev = NULL;
		delete D;
	}
}