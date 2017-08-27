

#ifndef TEXTFILES_H
#define TEXTFILES_H
#include <string>
#include "Matrix.h"
class TextFiles
{
    std::string file;
    int simulation;

    public:
        TextFiles();
        void delay (float);
        void startNew(Matrix M);
};

#endif // TEXTFILES_H



