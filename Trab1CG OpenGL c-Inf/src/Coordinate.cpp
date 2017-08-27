#include <iostream>
#include "Coordinate.h"
#include <string>
#include <sstream>
using namespace std;


Coordinate:: Coordinate(int x1, int y1) {
    x = x1;
    y = y1;
    infected = false;
    startInfection = 0;
}

int Coordinate:: getX (){
    return x;
}

int Coordinate:: getY (){
    return y;
}

void Coordinate:: setX (int x1) {
    x = x1;
}

void Coordinate:: setY (int y1) {
    y = y1;
}

void Coordinate:: setInfected () {
    infected = true;
}

bool Coordinate:: isInfected () {
    return infected;
}

int Coordinate:: getStartInfection () {
    return startInfection;
}

void Coordinate:: countStartInfection () {
    startInfection++;
}


string Coordinate:: toString() {
    string result;
    ostringstream converter;
    converter << getX() << ", " << getY();
    return result = converter.str();
}
