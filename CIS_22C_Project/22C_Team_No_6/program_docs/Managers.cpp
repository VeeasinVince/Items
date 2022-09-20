//
// Created by  Joakim Eckerman on 11/28/2020.
//

#include<iostream>
#include"Managers.h"

/****************************************************
* Insert function                                   *
****************************************************/

/*
This function takes a Listhead pointer,
it prompts the user to choose which key to insert by and calls the corresponding function.
The function returns an int "choice".
*/
int insertManager(Listhead* cars)
{
    string key, maker, model, colour, type;
    float cost;
    int i = 0;

    cout << endl << "||=====================================||" << endl;
    cout << "|| Welcome to the primary insert menu. ||" << endl;
    cout << "||=====================================||" << endl;

    cout << "Please enter the engine number of your entry: ";
    cin >> key;

    if (key.length() == 6)
    {

        Car* temp = new Car;                                            // Creating a temporary instance of Car to pass the key to secondary insert.
        temp->setEngineNumber(key);
        cars->getHash()->search(temp, key);                             // Check if there is already another car with the same engine number
        if (temp->getCost() == 0)                                       // If there is no other car with the same engine number, ask for the remaining info.
        {
            cout << "Please enter the car's maker: ";
            cin >> maker;
            while (maker[i] != '\0')                                    // Converting user input to correct format.
            {
                if (i == 0) {
                    maker[0] = toupper(maker[0]);
                    i++;
                }
                else {

                    maker[i] = tolower(maker[i]);
                    i++;
                }
            }
            i = 0;
            temp->setMaker(maker);
            cout << "Please enter the car's model: ";
            cin >> model;
            while (model[i] != '\0')                                    // Converting user input to correct format.
            {
                if (i == 0) {
                    model[0] = toupper(model[0]);
                    i++;
                }
                else {

                    model[i] = tolower(model[i]);
                    i++;
                }
            }
            i = 0;
            temp->setModel(model);
            cout << "Please enter the car's cost: ";
            cin >> cost;
            temp->setCost(cost);
            cout << "Please enter the car's colour: ";
            cin >> colour;
            while (colour[i] != '\0')                                   // Converting user input to correct format.
            {
                if (i == 0) {
                    colour[0] = toupper(colour[0]);
                    i++;
                }
                else {

                    colour[i] = tolower(colour[i]);
                    i++;
                }
            }
            i = 0;
            temp->setColour(colour);
            cout << "Please enter the car's type: ";
            cin >> type;
            while (type[i] != '\0')                                     // Converting user input to correct format.
            {
                if (i == 0) {
                    type[0] = toupper(type[0]);
                    i++;
                }
                else {

                    type[i] = tolower(type[i]);
                    i++;
                }
            }
            i = 0;
            temp->setType(type);
            cars->addcars();
            cars->getHash()->insert(temp);                              // Insert the car data.
            cars->getBst()->insert(temp);                               // Insert the car data.

        }
        else
            cout << "There is already a car with identical engine number in the system." << endl;
    }
    else
        cout << "Engine number must be exacly 6 digits." << endl;
    int choice = 0;
    do {
        cout << "What would you like to do next? (1-9) (8 for help) ";
        cin >> choice;
        if (choice < 1 || choice > 11)
        {
            std::cin.ignore();
            cout << "Enter a number between 1 and 9." << endl;
        }
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore();
            cout << "Enter a number not a character. ";
            choice = -1;
        }
    } while (choice < 0 || choice > 11);
    cout << endl << endl;
    return choice;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/****************************************************
* Search functions                                  *
****************************************************/

/*
This function takes a Listhead pointer,
it prompts the user to choose which key to search by and calls the corresponding function.
The function returns an int "choice".
*/
int searchManager(Listhead* cars)
{
    char option;
    do
    {
        cout << "Do you want to search by Engine number or by Maker? (E/M) ";
        cin >> option;
        if (toupper(option) == 'E')
            primaryKeySearchManager(cars);
        else if (toupper(option) == 'M')
            secondaryKeySearchManager(cars);
        else
            cout << "Please enter either E or M." << endl;
    } while (toupper(option) != 'E' && toupper(option) != 'M');
    int choice = 0;
    do {
        cout << "What would you like to do next? (1-9) (8 for help) ";
        cin >> choice;
        if (choice < 1 || choice > 11)
        {
            std::cin.ignore();
            cout << "Enter a number between 1 and 9." << endl;
        }
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore();
            cout << "Enter a number not a character. ";
            choice = -1;
        }
    } while (choice < 0 || choice > 11);
    cout << endl << endl;
    return choice;
}



void primaryKeySearchManager(Listhead* cars)
{
    cout << endl << "||=======================================||" << endl;
    cout << "|| Welcome to the primary search menu.   ||" << endl;
    cout << "||=======================================||" << endl;


    Car* dataout = new Car;
    string key;
    cout << "You have chosen to Search for a car using the engine number ";
    cout << "Enter Primary Key: ";
    cin >> key;
    dataout->setEngineNumber(key);
    if (!cars->getHash()->search(dataout, key))
    {
        cout << "No matches found." << endl;
    }
    else {
        cout << "Here is your match:" << endl;
        displayManager(dataout);
        cout << endl;
    }
}

/*
This function takes a Listhead pointer,
it provides a UI for the search by secondary key function.
The function returns nothing.
*/
void secondaryKeySearchManager(Listhead* cars)
{
    bool value = true;
    int option = 0;

    cout << endl << "||=======================================||" << endl;
    cout << "|| Welcome to the secondary search menu. ||" << endl;
    cout << "||=======================================||" << endl;

    do
    {
        Car* copies[15] = { 0 };
        string key;
        cout << "Please enter the maker of the desired car: ";          // prompt user to enter the disred Maker.
        cin >> key;
        int i = 0;
        while (key[i] != '\0')                                          // Converting user input to correct format.
        {
            if (i == 0) {
                key[0] = toupper(key[0]);
                i++;
            }
            else {

                key[i] = tolower(key[i]);
                i++;
            }
        }
        Car* Temp = new Car;                                            // Creating a temporary instance of Car to pass the key to search.
        Temp->setMaker(key);
        int m = 0;
        if (cars->getBst()->search(Temp, copies))                       // if there are any cars by the given Maker.
        {
            cout << endl << "These are the cars we found by " << key << endl;
            cout << "||==============================================================================================||" << endl
                 << "|| S.No ||    Model    ||  Engine #  ||    Maker    ||   Cost   ||    Color   ||      Type      ||" << endl
                 << "||==============================================================================================||" << endl;
            while (copies[m] != 0)                                      // Loop for every car found
            {
                cout << "||" << setw(4) << (m + 1) << ". ";
                displayManager(copies[m]);                              // Call displayManager to display each car
                m++;
            }
            do {
                cin.ignore();
                cout << "Enter 0 to try again, or any other number to continue. ";
                cin >> option;
                value = true;
                if (!std::cin) {                                        // Checking that the user enters a number.
                    std::cin.clear();
                    std::cin.ignore();
                    cout << "Enter a number not a character " << endl;
                    value = false;
                }
            } while (!value);
        }
        else
        {
            cout << "Sorry, we do not have any cars by that maker in stock." << endl;
            do {
                std::cin.ignore();
                cout << "Enter 0 to try again, or any other number to continue. " << endl;
                cin >> option;
                value = true;
                if (!std::cin) {                                        // Checking that the user enters a number.
                    std::cin.clear();
                    std::cin.ignore();
                    cout << "Enter a number not a character " << endl;
                    value = false;
                }
            } while (!value);
        }
    } while (option == 0);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/****************************************************
* Delete functions                                  *
****************************************************/

/*
This function takes a Listhead pointer,
it prompts the user to choose which key to delete by and calls the corresponding function.
The function returns an int "choice".
*/
int deleteManager(Listhead* cars)
{
    char option;
    do
    {
        cout << "Do you want to delete by Engine number or by Maker? (E/M) ";
        cin >> option;
        if (toupper(option) == 'E')
            primaryDeleteManager(cars);
        else if (toupper(option) == 'M')
            secondaryDeleteManager(cars);
        else
            cout << "Please enter either E or M." << endl;
    } while (toupper(option) != 'E' && toupper(option) != 'M');
    int choice = 0;
    do {
        cout << "What would you like to do next? (1-9) (8 for help) ";
        cin >> choice;
        if (choice < 1 || choice > 11)
        {
            std::cin.ignore();
            cout << "Enter a number between 1 and 9." << endl;
        }
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore();
            cout << "Enter a number not a character. ";
            choice = -1;
        }
    } while (choice < 0 || choice > 11);
    cout << endl << endl;
    return choice;
}



void primaryDeleteManager(Listhead* cars)
{
    string target;

    cout << endl << "||=======================================||" << endl;
    cout << "|| Welcome to the primary delete menu.   ||" << endl;
    cout << "||=======================================||" << endl;

    cout << "Enter Engine number: ";
    cin >> target;
    if (target.length() == 6)
    {
        Car* dataout = new Car;
        dataout->setEngineNumber(target);
        if (!cars->getHash()->search(dataout, target))                                    // If there is no car found.
        {
            cout << "There are no cars in our system with that engine number." << endl;
        }
        else {
            cars->getHash()->remove(dataout, target);
            cars->getBst()->deleteCar(dataout);
            cout << endl << dataout->getMaker() << " " << dataout->getModel() << " was deleted successfully." << endl;
            cars->getUndodelete()->push(dataout);
            cars->subcars();
        }
    }
    else
        cout << "Engine number must be exacly 6 digits." << endl;
}


/*
* This function takes a Listhead pointer,
* it provides a UI for the delete by secondary key function.
* The function returns nothing.
 */
void secondaryDeleteManager(Listhead* cars)
{
    int option = 0;
    Car* copies[15] = { 0 };
    string key;
    int i = 0;

    cout << endl << "||=======================================||" << endl;
    cout << "|| Welcome to the secondary delete menu. ||" << endl;
    cout << "||=======================================||" << endl;

    do
    {
        cout << "Enter Secondary Key: ";                                // prompt user to enter the disred Maker.
        cin >> key;
        while (key[i] != '\0')                                          // Converting user input to correct format.
        {
            if (i == 0) {
                key[0] = toupper(key[0]);
                i++;
            }
            else {

                key[i] = tolower(key[i]);
                i++;
            }
        }
        Car* Temp = new Car;                                            // Creating a temporary instance of Car to pass the key to search.
        Temp->setMaker(key);
        int m = 0;
        if (cars->getBst()->search(Temp, copies))                       // If there are any cars by the desired Maker.
        {
            cout << endl << "These are the cars we found by " << key << endl;
            cout << "||==============================================================================================||" << endl
                 << "|| S.No ||    Model    ||  Engine #  ||    Maker    ||   Cost   ||    Color   ||      Type      ||" << endl
                 << "||==============================================================================================||" << endl;
            while (copies[m] != 0)                                      // Loop for every car found
            {
                cout << "||" << setw(4) << (m + 1) << ". ";
                displayManager(copies[m]);                              // Call displayManager to display each car
                m++;
            }
            int elm;
            cout << "Select which number to delete: ";
            cin >> elm;
            if (elm >= 1 && elm <= (m))                                 // Check that the given number is present.
            {
                Car* Del = new Car();
                Del = copies[elm - 1];
                if (cars->getBst()->deleteCar(Del))                     // Check that the selcted car was deleted.
                {
                    cars->getHash()->remove(Del, Del->getEngineNumber());
                    Temp->setModel(copies[elm - 1]->getModel());
                    cout << endl << Temp->getMaker() << " " << Temp->getModel() << " was deleted successfully." << endl;
                    cars->getUndodelete()->push(copies[elm - 1]);
                    cars->subcars();
                    return;                                             // returns to the previous function.
                }
                else
                {
                    cout << endl;
                    cout << "The car could not be deleted.";            // Error deleting the car data.
                }
            }
            else
            {
                cout << "That is not a valid option, enter 0 to try again or any other number to exit." << endl;
                cin >> option;
            }
        }
        else
        {
            cout << "Sorry, no cars by \"" << key << "\" was found in our list." << endl;       // Error finding car by given maker.
        }
        cout << endl << endl;
    } while (option == 0);
    exitManager();                                                      // Calls the exitManager function
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/****************************************************
* Other functions                                   *
****************************************************/

/*
* This function takes a Car pointer,
* and it displays the data in a formatted fashion.
* The function returns nothing.
*/
void displayManager(Car* C)
{
    cout << "||" << setw(11) << C->getModel() << "  ||" << setw(9) << C->getEngineNumber() << "   ||"
         << setw(11) << C->getMaker() << "  ||" << " $" << setw(6) << C->getCost() << "  ||" << setw(10)
         << C->getColour() << "  ||" << setw(14) << C->getType() << "  ||" << endl;
}

/*
 Work in Process
 This function takes no parameters,
 it provides an option to either continue or exit the program.
 The function returns an int "choice".
 */
int exitManager()
{
    //bool counter = true;
    int clr;
    cout << endl;
    char choice;
    cout << "Do you wish to Exit(E) or return to Continue(C)? (E/C) ";
    do
    {
        cin >> choice;
        if (toupper(choice) == 'E')                                     // Case insensitive option to exit program.
            return 9;
        else if (toupper(choice) == 'C') {
            int choice = 0;
            do {
                cout << endl << "What would you like to do next? (1-9) (8 for help) ";
                cin >> choice;
                if (!std::cin) {
                    std::cin.clear();
                    std::cin.ignore();
                    cout << endl << "Enter a number not a character. " << endl;
                    choice = -1;
                }
                else if (choice < 1 || choice > 11)
                {
                    std::cin.ignore();
                    cout << endl << "Enter a number between 1 and 9." << endl;
                }
            } while (choice < 0 || choice > 11);
            cout << endl << endl;
            return choice;                                              // return the desired choice.
        }
        else
            cout << "Please enter a valid option (E/C)." << endl;
    } while (toupper(choice) != 'E' || toupper(choice) != 'C');         // Checks for valid input (case insensitive).
}

void DisplayHeading()
{
    cout << showpoint << fixed << setprecision(2);
    cout << "||======================================================================================||" << endl
         << "||    Model    ||  Engine #  ||    Maker    ||   Cost   ||    Color   ||      Type      ||" << endl
         << "||======================================================================================||" << endl;
}

/*
* This function takes a Listhead pointer,
* it pops the last deleted data and inserts it to the dataset.
* The function returns an int "choice".
*/
void undoDelete(Listhead* cars)
{
    int choice;
    if (cars->getUndodelete()->getLength() > 0)                           // Check if there are any deleted data.
    {
        Car* Temp = new Car;
        Temp = cars->getUndodelete()->pop();
        cout << "The following car data has been restored: " << endl;
        DisplayHeading();
        displayManager(Temp);
        cars->getBst()->insert(Temp);                                      // Success, data restored.
        cars->getHash()->insert(Temp);                                     // Success, data restored.
        cars->addcars();
    }
    else
        cout << "There are no deleted cars." << endl;                      // Failure, no deleted data.
}


void stats(Listhead* cars)
{
    cout << "Number of elements in our hash are: " << cars->getHash()->getCount() << endl;
    if (cars->getHash()->getCount() == 0)
    {
        cout << "There are no elements here " << endl;
    }
    else {
        cars->getHash()->findstats();
        cout << "The stats are as follows: " << endl;
        cout << "The load factor is: " << cars->getHash()->getLoadFactor() << endl;
        cout << "Number of collisions are: " << cars->getHash()->getNoCols() << endl;
        cout << " The longest linked list comprises of " << cars->getHash()->getLongestlinkedlist() << " elements" << endl;
        cout << " Total number of linked list with the highest number are: " << cars->getHash()->getNumberoflongest() << endl;
    }
}