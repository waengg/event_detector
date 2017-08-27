#ifndef INFECTEDTRAIL_H
#define INFECTEDTRAIL_H
#include "Coordinate.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class InfectedTrail
{
    std::vector<Coordinate> trail;
    public:
        InfectedTrail();
        void addTrail (Coordinate);
        bool InfectByTrail(Coordinate);
        void clearTrail ();
};

#endif // INFECTEDTRAIL_H
