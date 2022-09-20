#pragma once
// Created by Sriharsha Edukulla on 11/22/2020.
 /* ==============================================================================================
                                    <DESCRIPTION>

This is the Car class which comprises our car details. There are getters and setters and
 we have two overload of "<<" operators. One to print to screen and other to print to file.
=================================================================================================
 */

#pragma once

#include<iostream>
#include<fstream>
#include <iomanip>
#include <string>
using namespace std;

class Car
{

private:
    string EngineNumber;
    string Model;
    string Maker;
    float Cost;
    string Colour;
    string Type;

public:
    Car()
    {
        EngineNumber = "";
        Model = "";
        Maker = "";
        Cost = 0.0;
        Colour = "";
        Type = "";
    }
    Car(string EN, string MO, string MA, float amount, string CO, string TY) {
        EngineNumber = EN;
        Model = MO;
        Maker = MA;
        Cost = amount;
        Colour = CO;
        Type = TY;
    }
    ~Car()
    {
        delete this;
    }
    //Getters:
    string getEngineNumber();
    string getModel();
    string getMaker();
    float getCost() const;
    string getColour();
    string getType();

    //Setters:
    void setEngineNumber(string en) { EngineNumber = en; }
    void setModel(string mo) { Model = mo; }
    void setMaker(string ma) { Maker = ma; }
    void setCost(float cos) { Cost = cos; }
    void setColour(string col) { Colour = col; }
    void setType(string ty) { Type = ty; }

    // overloaded operators
    //dont use friend, refer to older labs
    friend std::ostream& operator<<(std::ostream& output, Car* C);    //Cout operator
    friend std::ofstream &operator<< (std::ofstream &stream,  Car *car);    //Cout operator

};



