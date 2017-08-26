#ifndef MATRIX_H
#define MATRIX_H
#include "Coordinate.h"
#include <unordered_map>

using namespace std;

class Matrix
{
    Coordinate **matrix;
    Coordinate **infected;
    public:

        Matrix(int, int);
        void mInsertCoord(Coordinate, int, int);
        void toString();
        void readFile();
        void setInfected(int, int);
        void attInfected(int);
        Coordinate getCoord(int, int);
        void desenhaTrajeto (int, int);
        void infectThroughTrace(int);
        void insertCoordinateIntoHashMap(Coordinate);
        bool findCoordinateFromMap(Coordinate);
};

#endif // MATRIX_H
