//
// Created by Sriharsha Edukulla on 11/22/2020.
//
//==============================================
// This is used to implement all the function of cars.h
//====================================================
#pragma once
#include "Car.h"
string Car::getEngineNumber()
{
    return EngineNumber;
}

string Car::getModel()
{
    return Model;
}

string Car::getMaker()
{
    return Maker;
}

float Car::getCost() const
{
    return Cost;
}

string Car::getColour()
{
    return Colour;
}

string Car::getType()
{
    return Type;
}


std::ostream& operator<<(std::ostream& output, Car* C)
{
    cout << "||" << setw(11) << C->getModel() << "  ||" << setw(9) << C->getEngineNumber() << "   ||"
         << setw(11) << C->getMaker() << "  ||" << " $" << setw(6) << C->getCost() << "  ||" << setw(10)
         << C->getColour() << "  ||" << setw(14) << C->getType() << "  ||" << endl;

    return output;
}

std::ofstream &operator<< (std::ofstream &stream,Car *car)
{
    stream << car->EngineNumber << "\t"
           << car->Model << "\t"
           << car->Maker << "\t"
           << car->Cost << "\t"
           << car->Colour << "\t"
           << car->Type << "\t";
    stream<<endl;

    return stream;
}
