#include "news.h"
#include "category.h"
#include "author.h"
#include "primitive.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string command;
	Author A;
	createAuthor(&A);

    cout << "------=== APLIKASI PENGATURAN BLOG BERITA ===------" << endl;
    cout << "                      2015" << endl;
    cout << "              IF-38-05 / kelompok 8" << endl;
    cout << endl;
    cout << endl;
    cout << "ketik \"help\" untuk menampilkan perintah" << endl;
    cout << endl;
    cout << endl;

	for (;;) {
        cout << " > ";
        getline(cin, command);
        if (command != "exit")
            translateCommand(command, &A);
        else
            break;
    }
    cout << "                  END OF PROGRAM" << endl;
    cout << "------=== APLIKASI PENGATURAN BLOG BERITA ===------" << endl;

	return 0;
}
