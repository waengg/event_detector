#include <iostream>
#include "Coordinate.h"
using namespace std;


Coordinate:: Coordinate(int x1, int y1) {
    x = x1;
    y = y1;
    infected = false;
}

int Coordinate:: getX(){
    return x;
}

int Coordinate:: getY(){
    return y;
}

void Coordinate:: setX(int x1) {
    x = x1;
}

void Coordinate:: setY(int y1) {
    y = y1;
}

void Coordinate:: setInfected() {
    infected = true;
}

bool Coordinate:: isInfected() {
    return infected;
}

string Coordinate:: toString() {
    return getX() + ", " + getY();
}


