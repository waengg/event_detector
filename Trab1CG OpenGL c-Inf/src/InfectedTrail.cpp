#include "InfectedTrail.h"
#include "Coordinate.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

InfectedTrail::InfectedTrail()
{

}


void InfectedTrail:: addTrail (Coordinate c) {
    trail.push_back(c);
}


bool InfectedTrail:: InfectByTrail (Coordinate c) {
     if (c.getX() == -1) {
            cout << "retorna " << endl;
            return false;}
    for (Coordinate aux : trail) {
                int xJ = c.getX();
                int yJ = c.getY();
                int xI = aux.getX();
                int yI = aux.getY();
                int x = xJ - xI;
                x = x*x;
                int y = yJ - yI;
                y = y*y;
                double soma = x + y;
                double distance = sqrt (soma);
                //cout << distance << endl;
                if (distance <= 100) {
                    return true;
                }
                return false;

    }
}


void InfectedTrail:: clearTrail() {
    trail.clear();
    for (Coordinate aux : trail) {
        cout<< aux.toString() << endl;
    }
}
