#include "primitive.h"
#include "news.h"
#include "category.h"
#include "author.h"
#include <iostream>
#include <cstring>


using namespace std;

void primInsertAuthor(Author *A, infoAuthor iA)
{
	adrAuthor eA, P;
	adrCategory Q;
	infoCategory iC;
	
	insertAuthor(A, iA);
	
	// duplikasi category
	eA = findAuthor(*A, iA);

	createCategory(&eA->category);	// create category

	P = eA->next != eA? eA->next : NULL;

	if (P != NULL) {
		if (P->category.first != NULL) {	// cek apakah ada category
			Q = P->category.first;
			while (Q != NULL) {		// masukkan masing masing category
				iC = Q->info;
				insertCategory(&eA->category, iC);
				Q = Q->next;
			}
		}
	}
}
void primInsertCategory(Author *A, infoCategory iC)
{
	adrAuthor P;
	adrCategory eC;

	P = A->first;
	if (P != NULL) {
		if (P->next == P) {		// untuk satu elemen Author
			insertCategory(&P->category, iC);
			eC = findCategory(P->category, iC);	// create news
			createNews(&eC->news);
		} else {
			P = P->next;		// lebih dari satu elemen Author
			while (P != A->first) {
				insertCategory(&P->category, iC);
				eC = findCategory(P->category, iC);	// create news
				createNews(&eC->news);
				P = P->next;
			}
		}
	}
}
void primInsertNews(Author *A, infoAuthor iA, infoCategory iC, infoNews iN)
{
	adrAuthor eA;
	adrCategory eC;

	eA = findAuthor(*A, iA);
	eC = findCategory(eA->category, iC);
	insertNews(&eC->news, iN);
}
void primDeleteNews(Author *A, infoAuthor iA, infoCategory iC, infoNews iN)
{
	adrAuthor eA;
	adrCategory eC;

	eA = findAuthor(*A, iA);
	eC = findCategory(eA->category, iC);
	deleteNews(&eC->news, iN);
}
void primDeleteCategory(Author *A, infoCategory iC)
{
	adrAuthor eA;
	adrCategory eC;
	adrNews eN;

	eA = A->first;
	if (eA != NULL) {
		eC = findCategory(eA->category, iC);
		eN = eC->news.first;
		while (eN != NULL) {
			deleteNews(&eC->news, eN->info);
			eN = eC->news.first;
		}
		deleteCategory(&eA->category, eC->info);
		eA = eA->next;
		while (eA != A->first) {
			eC = findCategory(eA->category, iC);
			eN = eC->news.first;
			while (eN != NULL) {
				deleteNews(&eC->news, eN->info);
				eN = eC->news.first;
			}
			deleteCategory(&eA->category, eC->info);
			eA = eA->next;	
		}
	}
}
void primDeleteAuthor(Author *A, infoAuthor iA)
{
	adrAuthor eA;
	adrCategory eC;
	adrNews eN;

	eA = findAuthor(*A, iA);
	eC = eA->category.first;
	while (eC != NULL) {
		eN = eC->news.first;
		while (eN != NULL) {
			deleteNews(&eC->news, eN->info);
			eN = eC->news.first;
		}
		deleteCategory(&eA->category, eC->info);
		eC = eA->category.first;
	}
	deleteAuthor(A, iA);
}
void primChangeCategory(Author *A, infoAuthor iA, infoCategory iCl, infoCategory iCb, infoNews iN)
{
	adrAuthor eA;
	adrCategory eC;
	adrNews eN;
	infoNews iNT;

	eA = findAuthor(*A, iA);
	eC = findCategory(eA->category, iCl);
	iNT = findNews(eC->news, iN)->info;

	primInsertNews(A, iA, iCb, iNT);
	primDeleteNews(A, iA, iCl, iN);

}
void primEditNewsTitle(Author *A, infoAuthor iA, infoCategory iC, infoNews iNl, infoNews iNb)
{
	adrAuthor eA;
	adrCategory eC;
	adrNews eN;
	
	eA = findAuthor(*A, iA);
	eC = findCategory(eA->category, iC);
	eN = findNews(eC->news, iNl);

	strcpy(eN->info.title, iNb.title);
}
void printByTime(Author *A, infoAuthor iA, t_date dFrom, t_date dUntil)
{
	News tN;
	Category C;
	News N;
	adrAuthor eA;
	adrCategory eC;
	adrNews eN;

	eA = findAuthor(*A, iA);
	C = eA->category;

	// menyimpan news yang dimaksud ke dalam temporary list
	createNews(&tN);
	eC = C.first;
	while (eC != NULL) {
		N = eC->news;
		eN = N.first;
		while (eN != NULL) {
			insertNews(&tN, eN->info);
			eN = eN->next;
		}
		eC = eC->next;
	}


	// print news
	eN = tN.first;
	while (eN != NULL) {
		if ((dFrom.dt >= eN->info.date.dt) && (eN->info.date.dt >= dUntil.dt)) {
			cout << eN->info.title << endl;
			cout << eN->info.date.dd << "-" << eN->info.date.mm << "-" << eN->info.date.yyyy << endl;
			cout << eN->info.body << endl;
			cout << "----------------------------------------\n";
		} else if (eN->info.date.dt < dUntil.dt) {
			eN = NULL;
		}
		eN = eN->next;
	}
}
void printByCategory(Author *A, infoAuthor iA, infoCategory iC)
{
	News tN;
	adrAuthor eA;
	adrCategory eC;
	adrNews eN;

	eA = A->first;
	if (eA != NULL) {
		// menyimpan news yang dimaksud ke dalam temporary list
		createNews(&tN);
		eC = findCategory(eA->category, iC);
		eN = eC->news.first;
		while (eN != NULL) {
			insertNews(&tN, eN->info);
			eN = eN->next;
		}
		eA = eA->next;
		while (eA != A->first) {
			eC = findCategory(eA->category, iC);
			eN = eC->news.first;
			while (eN != NULL) {
				insertNews(&tN, eN->info);
				eN = eN->next;
			}
			eA = eA->next;	
		}

		// print news
		eN = tN.first;
		while (eN != NULL) {
			cout << eN->info.title << endl;
			cout << eN->info.date.dd << "-" << eN->info.date.mm << "-" << eN->info.date.yyyy << endl;
			cout << eN->info.body << endl;
			cout << "----------------------------------------\n";
			eN = eN->next;
		}
	}
}