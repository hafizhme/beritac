#include "news.h"
#include "category.h"
#include "author.h"
#include "primitive.h"

int main(int argc, char const *argv[])
{
	Author A;
	createAuthor(&A);

	cout << "1 Tambahkan Author" << endl;
	cout << "2 Tambahkan Category" << endl;
	cout << "3 Tambahkan Berita" << endl;
	return 0;
}
