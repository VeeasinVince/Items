#include <iostream>
#include <string>
#include <fstream>
#include "book.h"
//Editted for use by Vincent to make quantity sort from largest to smallest... :)
using namespace std;

int main()
{
	string word;
	int contt;
	int k = 50;		//idk since I can't pass j for some reason
	cout << "Test program starting" << endl;
	cout << "Reading from data/catalog.txt" << endl << endl;
	cout << "Enter directory: ";

	cin >> word;
	//C:\Users\peter\catalog.txt
	//H:\

	string   line;
	ifstream file(word);
	if (!file)
		cout << "Error, can't open file" << endl;

	Book books[50];
	int  i = 0;

	while (getline(file, line))
	{
		books[i] = Book(line);
		i++;
	}

	cout << endl;

	for (int j = 0; j < i; j++)							//This is where the books are being printed.
		cout << books[j] << endl;

	cout << "Press a number to continue: ";
	cin >> contt;
	//////////////////////Quantity///////////////
	system("CLS");
	Book sorter;
	cout << "Now I will sort the books by quantity!" << endl << endl;

	books[0].setDetail(1);		//1 is used to compare the quantity detail
	sorter.sort(books, k);

	for (int t = 0; t < 50; t++)							//This is where the books are being printed.
		cout << books[t] << endl;

	cout << "Press a number to continue: ";
	cin >> contt;
	//////////////////////ListedPrice/////////////
	system("CLS");
	cout << "Now I will sort the books by wholesale price!" << endl << endl;

	books[0].setDetail(2);		//2 is used to compare the wholesale detail
	sorter.sort(books, k);

	for (int t = 0; t < 50; t++)							//This is where the books are being printed.
		cout << books[t] << endl;

	cout << "Press a number to continue: ";
	cin >> contt;

	//////////////////////OriginalPrice/////////////
	system("CLS");
	cout << "Now I will sort the books by retail price!" << endl << endl;

	books[0].setDetail(3);		//3 is used to compare the retail detail
	sorter.sort(books, k);

	for (int t = 0; t < 50; t++)							//This is where the books are being printed.
		cout << books[t] << endl;

	cout << "Press a number to continue: ";
	cin >> contt;

	//////////////////////Title/////////////
	system("CLS");
	cout << "Now I will sort the books by title!" << endl << endl;

	books[0].setDetail(4);		//4 is used to compare the title detail
	sorter.sort(books, k);

	for (int t = 0; t < 50; t++)							//This is where the books are being printed.
		cout << books[t] << endl;

	cout << "Press a number to continue: ";
	cin >> contt;

	//////////////////////Date/////////////Ignore this one beacuase it's broken.
	system("CLS");
	cout << "Now I will sort the books by date!" << endl << endl;

	books[0].setDetail(5);		//5 is used to compare the date detail
	sorter.sort(books, k);

	for (int t = 0; t < 50; t++)							//This is where the books are being printed.
		cout << books[t] << endl;

	cout << "Press a number to continue: ";
	cin >> contt;

	//////////////////////Author/////////////
	system("CLS");
	cout << "Now I will sort the books by Author!" << endl << endl;

	books[0].setDetail(6);		//6 is used to compare the author detail
	sorter.sort(books, k);

	for (int t = 0; t < 50; t++)							//This is where the books are being printed.
		cout << books[t] << endl;

	cout << "Press a number to continue: ";
	cin >> contt;

	//////////////////////ISBN/////////////
	system("CLS");
	cout << "Now I will sort the books by ISBN!" << endl << endl;

	books[0].setDetail(7);		//7 is used to compare the ISBN detail
	sorter.sort(books, k);

	for (int t = 0; t < 50; t++)							//This is where the books are being printed.
		cout << books[t] << endl;

	cout << "Press a number to continue: ";
	cin >> contt;




	system("pause");
	return 0;
}

//////////////////////////////////
