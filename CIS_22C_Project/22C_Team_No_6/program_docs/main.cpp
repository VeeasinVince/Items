//CIS22C Rental Car Database
//Done by SRIHARSHA EDUKULLA

//Header files:
#include<iostream>
#include <cctype>
#include<fstream>
#include<string>
#include <conio.h>
#include "Managers.h"
using namespace std;
#include "Car.h"

//Fuction definitions:
void ReadManager(Listhead* cars);
void vDisplay(Car* item);
void iDisplay(Car*, int);
int DisplayMenu();
void DisplayHeading();
void EndDisplay();
void Save_to_file(Listhead* cars);
int printnames();
int findsize();
bool isPrime(int n);



int main()
{
    bool opt;
    int hashsize = findsize();
    Listhead* carsinfo = new Listhead(hashsize);
    ReadManager(carsinfo);
    int choice = 1, clr = 0;
    bool counter = true;
    cout << "-----------------------------------" << endl;
    cout << "Welcome Fox Rental service database" << endl;
    cout << "-----------------------------------" << endl;
    choice = DisplayMenu();
    while (choice < 13) {
        switch (choice) {
            case 1:
                choice = insertManager(carsinfo);
                break;

            case 2:
                choice = searchManager(carsinfo);
                break;

            case 3:
                choice = deleteManager(carsinfo);
                break;
            case 4:
                undoDelete(carsinfo);
                choice = exitManager();
                break;
            case 5:
                DisplayHeading();
                carsinfo->getBst()->inOrder(vDisplay);
                choice = exitManager();
                break;
            case 6:
                stats(carsinfo);
                choice = exitManager();
                break;
            case 7:
                Save_to_file(carsinfo);
                choice = exitManager();
                break;
            case 8:
                choice = DisplayMenu();
                break;
            case 9:
                Save_to_file(carsinfo);
                EndDisplay();
                return 0;
                break;
            case 10:
                choice = printnames();
                break;
            case 11:
                cout << "Printing indented." << endl;
                carsinfo->getBst()->printTree(iDisplay);
                choice = exitManager();
                break;
        }

    };
    Save_to_file(carsinfo);
    EndDisplay();
    return 0;
}
/*
We use this function for reading our dataset and saving them in bst and hash
 */

void ReadManager(Listhead* cars)
{
    ifstream fin;
    fin.open("dataset.txt");
    if (!fin)
    {
        cout << "Error opening the input file: \"" << endl;
        exit(EXIT_FAILURE);
    }
    string code, colour, type, maker, name;
    float cost;
    while (!fin.eof()) {
        getline(fin, code, '\t');
        getline(fin, name, '\t');
        getline(fin, maker, '\t');
        fin >> cost;
        fin.ignore();
        getline(fin, colour, '\t');
        getline(fin, type, '\n');
        Car* C1 = new Car(code, name, maker, cost, colour, type);
        cars->getBst()->insert(C1);
        cars->addcars();
        cars->getHash()->insert(C1);
    }
}

void vDisplay(Car* item)
{
    displayManager(item);
}

void iDisplay(Car* item, int level)
{
    for (int i = 1; i < level; i++)
        cout << "..";
    cout << level << "). ";
    displayManager(item);
    cout << endl;

}

//This is our menu function
int DisplayMenu() {
    int choice = 1;

    cout << endl << "||===========================||" << endl;
    cout << "|| Welcome to the main menu. ||" << endl;
    cout << "||===========================||" << endl;

    cout << "Choose one of the below options" << endl;
    cout << "1) Add a new car to the database" << endl;
    cout << "2) Search for a car in the database" << endl;
    cout << "3) Delete a car from the database" << endl;
    cout << "4) Undo delete" << endl;
    cout << "5) Display all the Data from the Database" << endl;
    cout << "6) Display Statistics" << endl;
    cout << "7) Save to file" << endl;
    cout << "8) Help (Show menu)" << endl;
    cout << "9) Exit the menu(Ending the program)" << endl;
    cout << " -------------------------------------------------" << endl;
    do
    {
        cout << "Enter choice: ";
        std::cin >> choice;
        if (choice < 1 || choice > 11)
        {
            cout << "Enter a choice between 1 and 9 " << endl;
        }
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore();
            choice = -1;
        }
    } while (choice < 1 || choice > 11);

    return choice;
}



void EndDisplay()
{
    cout << endl << endl;
    cout << "Ending the code........";
}

/*
This is save to file we use this to save to the output file in hash order
 */
void Save_to_file(Listhead* cars)
{
    cout << "Saving data to file......" << endl;
    ofstream fon;
    fon.open("outfile.txt");
    cars->getHash()->Savehashtofile(fon);
    cars->deletestack();
    fon.close();
}

//This is the hidden option
int printnames()
{
    int choice = 0;
    cout << endl;
    cout << "This program was created by:" << endl;
    cout << "1) Sriharsha Edukulla " << endl;
    cout << "2) Vincent Nguyen " << endl;
    cout << "3) Khush Naidu " << endl;
    cout << "4) Joakim Eckerman" << endl;
    choice = exitManager();
    return choice;
}

//This function is used to find the size of the hash
int findsize()
{
    string line;
    int count = 1;
    ifstream fin;
    fin.open("dataset.txt");	//TESTING PURPOSES
    if (!fin)
    {
        cout << "Error opening the input file: \"" << endl;
        exit(EXIT_FAILURE);
    }
    while (!fin.eof()) {
        getline(fin, line);
        count++;
    }
    fin.close();
    count = count * 2;
    while (!isPrime(count))
    {
        count++;
    }
    return count;
}


//This is used to calculate if the given number is prime or no
bool isPrime(int n)
{
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}