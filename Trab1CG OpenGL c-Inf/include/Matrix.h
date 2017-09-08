#ifndef MATRIX_H
#define MATRIX_H
#include <string>
#include "Coordinate.h"
#include <unordered_map>

class Matrix
{
    Coordinate **matrix;
    Coordinate **infected;
    public:

        Matrix(int, int);
        void mInsertCoord(Coordinate, int, int);
        void Initialize();
        void toString();
        void readFile(std:: string);
        void setInfected(int, int);
        void attInfected(int);
        Coordinate getCoord(int, int);
        void desenhaTrajeto (int, int);
        void infectThroughTrace(int);
        void insertCoordinateIntoHashMap(Coordinate);
        bool findCoordinateFromMap(Coordinate);
        void clearMap();
        void setStartInfections(int);
        Coordinate** getMatrix();
};

#endif // MATRIX_H
