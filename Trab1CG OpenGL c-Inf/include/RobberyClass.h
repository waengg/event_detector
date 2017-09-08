#ifndef ROBBERYCLASS_H
#define ROBBERYCLASS_H


class RobberyClass
{
    Coordinate **matrix;
    Coordinate **infected;
    GLfloat x1 = 1.0f;
    GLfloat y1 = 1.0f;
    GLsizei rsize = 30;
    int frame = 0;
    int simulation = 0;

    public:
        RobberyClass();

    protected:

    private:
};

#endif // ROBBERYCLASS_H
