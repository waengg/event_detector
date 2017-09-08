#ifndef INFECTIONCLASS_H
#define INFECTIONCLASS_H
#include <string>
#include "Coordinate.h"
#include <unordered_map>
#include <GL/gl.h>
#include <GL/glut.h>

class InfectionClass
{
    Coordinate **matrix;
    Coordinate **infected;
    GLfloat x1 = 1.0f;
    GLfloat y1 = 1.0f;
    GLsizei rsize = 30;
    int frame = 0;
    int simulation = 0;
    public:

        InfectionClass();
        void attMatrix(Coordinate**);
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
        void setInfectedColor (Coordinate);
        bool drawInfectionSimulation();
};

#endif // MATRIX_H
