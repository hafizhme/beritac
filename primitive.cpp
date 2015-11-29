#include "primitive.h"
#include "news.h"
#include "category.h"
#include "author.h"
#include <iostream>
#include <string>


using namespace std;

void primInsertAuthor(Author *A, infoAuthor iA)
{
	adrAuthor eA, P;
	adrCategory Q;
	infoCategory iC;

	insertAuthor(A, iA);

	// duplikasi category
	eA = findAuthor(*A, iA);
	P = eA->next != eA? eA->next : NULL;

	if (P != NULL) {
        createCategory(&eA->category);	// create category
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
		// untuk satu pertama Author
        insertCategory(&P->category, iC);
        eC = findCategory(P->category, iC);	// create news
        createNews(&eC->news);

		P = P->next;		// lebih dari satu elemen Author
		while (P != A->first) {
			insertCategory(&P->category, iC);
			eC = findCategory(P->category, iC);	// create news
			createNews(&eC->news);
			P = P->next;
		}

	}
}
void primInsertNews(Author *A, infoAuthor iA, infoCategory iC, infoNews iN)
{
	adrAuthor eA;
	adrCategory eC;

	eA = findAuthor(*A, iA);
	if (eA != NULL) {
        eC = findCategory(eA->category, iC);
        if (eC != NULL)
            insertNews(&eC->news, iN);
        else
            cout << "tidak ada category" << endl;
	} else
        cout << "tidak ada author" << endl;
}
void primDeleteNews(Author *A, infoAuthor iA, infoCategory iC, infoNews iN)
{
	adrAuthor eA;
	adrCategory eC;

	eA = findAuthor(*A, iA);
	if (eA != NULL) {
        eC = findCategory(eA->category, iC);
        if (eC != NULL)
            deleteNews(&eC->news, iN);
        else
            cout << "tidak ada category" << endl;
	} else
        cout << "tidak ada author" << endl;
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

	eN->info.title = iNb.title;

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


void inputAuthor(Author *A)
{
	infoAuthor iA;

	cout << "Author Name : ";
		getline(cin, iA.nameAuthor);
	cout << "Author ID  : ";
		getline(cin, iA.idAuthor);

	primInsertAuthor(A, iA);
}
void inputCategory(Author *A)
{
	infoCategory iC;

	cout << "Category Name : ";
		getline(cin, iC.nameCategory);
	cout << "Category ID  : ";
		getline(cin, iC.idCategory);

	primInsertCategory(A, iC);
}
void inputNews(Author *A)
{
	infoAuthor iA;
	infoCategory iC;
	infoNews iN;
    cout << "Author List :\n";
    printAuthor(*A);
    cout << endl << "Category List :\n";
    printCategory(A->first->category);
    cout << endl;
    cout << "News detail :\n";
	cout << "idAuthor     : ";
		getline(cin, iA.idAuthor);
	cout << "idCategory   : ";
		getline(cin, iC.idCategory);
	cout << "Title   [50] : ";
		getline(cin, iN.title);
	cout << "News ID [05] : ";
		getline(cin, iN.idNews);
	cout << "Date [dd mm yyyy] : ";
		cin >> iN.date.dd >> iN.date.mm >> iN.date.yyyy;
	cout << "Body : \n";
		getline(cin, iN.body);
		getline(cin, iN.body);

	primInsertNews(A, iA, iC, iN);
}

void removeAuthor(Author *A)
{
    infoAuthor iA;
    cout << "idAuthor : ";
		getline(cin, iA.idAuthor);

    primDeleteAuthor(A, iA);
}
void removeCategory(Author *A)
{
    infoCategory iC;
    cout << "idCategory : ";
        getline(cin, iC.idCategory);

    primDeleteCategory(A, iC);
}
void removeNews(Author *A)
{
    infoAuthor iA;
    infoCategory iC;
    infoNews iN;

    cout << "idAuthor : ";
		getline(cin, iA.idAuthor);
    cout << "idCategory : ";
        getline(cin, iC.idCategory);
    cout << "idNews : ";
        getline(cin, iN.idNews);

    primDeleteNews(A, iA, iC, iN);
}
void switchCategory(Author *A)
{
    infoAuthor iA;
    infoCategory iCl, iCb;
    infoNews iN;

    cout << "idAuthor : ";
        getline(cin, iA.idAuthor);
    cout << "idCategoryLama : ";
        getline(cin, iCl.idCategory);
    cout << "idNews : ";
        getline(cin, iN.idNews);
    cout << "idCategoryBaru : ";
        getline(cin, iCb.idCategory);

    primChangeCategory(A, iA, iCl, iCb, iN);
}
void changeNewsTitle(Author *A)
{
    infoAuthor iA;
    infoCategory iC;
    infoNews iNl, iNb;

    cout << "idAuthor : ";
        getline(cin, iA.idAuthor);
    cout << "idCategory : ";
        getline(cin, iC.idCategory);
    cout << "idNews : ";
        getline(cin, iNl.idNews);
    cout << "New Title : ";
        getline(cin, iNb.title);

    primEditNewsTitle(A, iA, iC, iNl, iNb);
}
void printNtm(Author *A)
{
    infoAuthor iA;
    t_date from, until;

     cout << "idAuthor : ";
        getline(cin, iA.idAuthor);
    cout << "Tampilkan berita pada selang waktu [dd mm yyyy]\n";
    cout << "From : ";
        cin >> from.dd >> from.mm >> from.yyyy;
    cout << "Until : ";
        cin >> until.dd >> until.mm >> until.yyyy;

    printByTime(A, iA, from, until);
}
void printNct(Author *A)
{
    infoAuthor iA;
    infoCategory iC;

    cout << "idAuthor : ";
        getline(cin, iA.idAuthor);
    cout << "idCategory : ";
        getline(cin, iC.idCategory);

    printByCategory(A, iA, iC);
}
void help() {
    cout << "input author" << endl;
    cout << "\t\tmemasukkan author baru" << endl << endl;

    cout << "input category" << endl;
    cout << "\t\tmemasukkan category baru" << endl << endl;

    cout << "input news" << endl;
    cout << "\t\tmemasukkan berita ke dalam author dan category tertentu" << endl << endl;

    cout << "remove author" << endl;
    cout << "\t\tmenghapus author beserta beserta berita yang ditulis" << endl << endl;

    cout << "remove category" << endl;
    cout << "\t\tmenghapus category beserta berita dibawahnya untuk seluruh author" << endl << endl;

    cout << "remove news" << endl;
    cout << "\t\tmenghapus berita tertentu" << endl << endl;

    cout << "change news category" << endl;
    cout << "\t\tmengganti kategori suatu berita" << endl << endl;

    cout << "change news title" << endl;
    cout << "\t\tmengganti judul berita" << endl << endl;

    cout << "show news by time" << endl;
    cout << "\t\tmenampilkan berita berdasarkan rentang waktu" << endl << endl;

    cout << "show news by category" << endl;
    cout << "\t\tmenampilkan berita berdasarkan kategori" << endl << endl;

    cout << "help" << endl;
    cout << "\t\tmenampilkan bantuan" << endl;
    cout << endl;
}
void credit()
{
    cout << "lecturer" << endl;
    cout << "\tBambang Ari Wahyudi" << endl << endl;
    cout << "practicum assistant" << endl;
    cout << "\tDyah Ayu Cintya Dewi" << endl << endl;
    cout << "team leader" << endl;
    cout << "\tSatria Hafizh Rizkitama Harsono" << endl << endl;
    cout << "team member" << endl;
    cout << "\tMuhammad Andika Satrugna Mahardika" << endl;
    cout << "\tThareq Arsyad Darmawan" << endl;
    cout << "\tYisti Yisnika" << endl;
    cout << endl;
}
void translateCommand(string command, Author *A)
{
         if (command == "input author")
        inputAuthor(A);
    else if (command == "input category")
        inputCategory(A);
    else if (command == "input news")
        inputNews(A);
    else if (command == "remove author")
        removeAuthor(A);
    else if (command == "remove category")
        removeCategory(A);
    else if (command == "remove news")
        removeNews(A);
    else if (command == "change news category")
        switchCategory(A);
    else if (command == "change news title")
        changeNewsTitle(A);
    else if (command == "show news by time")
        printNtm(A);
    else if (command == "show news by category")
        printNct(A);
    else if (command == "help")
        help();
    else if (command == "credit")
        credit();
    else if (command != "") {
        cout << "periksa perintah yang anda masukkan" << endl;
        cout << "ketik \"help\" untuk menampilkan perintah" << endl;
        cout << endl;
    }
}
