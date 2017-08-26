#ifndef COORDINATE_H
#define COORDINATE_H

using namespace std;

class Coordinate
{
    int x, y;
    bool infected;

    public:
        Coordinate(int, int);
        int getX();
        int getY();
        void setX(int);
        void setY(int);
        void setInfected();
        bool isInfected();
        string toString();
};

#endif // COORDINATE_H
