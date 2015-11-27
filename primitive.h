#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include "news.h"
#include "category.h"
#include "author.h"
#include <iostream>
#include <cstring>

void primInsertAuthor(Author *A, infoAuthor iA);
void primInsertCategory(Author *A, infoCategory iC);
void primInsertNews(Author *A, infoAuthor iA, infoCategory iC, infoNews iN);
void primDeleteNews(Author *A, infoAuthor iA, infoCategory iC, infoNews iN);
void primDeleteCategory(Author *A, infoCategory iC);
void primDeleteAuthor(Author *A, infoAuthor iA);
void primChangeCategory(Author *A, infoAuthor iA, infoCategory iCl, infoCategory iCb, infoNews iN);
void primEditNewsTitle(Author *A, infoAuthor iA, infoCategory iC, infoNews iNl, infoNews iNb);
void printByTime(Author *A, infoAuthor iA, t_date dFrom, t_date dUntil);
void printByCategory(Author *A, infoAuthor iA, infoCategory iC);

// METHOD DI BAWAH YANG DIPANGGIL DI MAIN METHOD -----------------
void inputAuthor(Author *A);
void inputCategory(Author *A);
void inputNews(Author *A);
void removeAuthor(Author *A);
void removeCategory(Author *A);
void removeNews(Author *A);
void switchCategory(Author *A);
void changeNewsTitle(Author *A);
void printNtm(Author *A);
void printNct(Author *A);

#endif
