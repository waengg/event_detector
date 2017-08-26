#include <iostream>
#include "Matrix.h"
#include <stdlib.h>
#include <fstream>	// para usar file streams (ifstream,ofstream)
#include <string>	// para usar string
#include <iomanip>	// para usar manipuladores (setw, right, ...)
#include <cstdlib>	// para usar srand(), rand() e exit()
#include <GL/glut.h>
#include <cmath>

using namespace std;

std::unordered_map<std::string, std::string> infectedCoordinateMap;

Matrix::Matrix(int persons, int frames)
{

    Coordinate initiate (-1, -1);

    int i,j; //Variáveis Auxiliares

    matrix = (Coordinate**)malloc(persons * sizeof(Coordinate*)); //Aloca um Vetor de Ponteiros

    for (i = 0; i < persons; i++)  //Percorre as linhas do Vetor de Ponteiros
    {
        matrix[i] = (Coordinate*) malloc(frames * sizeof(Coordinate)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
        for (j = 0; j < frames; j++)  //Percorre o Vetor de Inteiros atual.
        {
            matrix[i][j] = initiate; //Inicializa com 0.q
        }
    }

}

void Matrix:: mInsertCoord (Coordinate c, int person, int frame)
{
    matrix [person][frame] = c;
}

Coordinate Matrix:: getCoord (int person, int frame)
{
    return matrix[person][frame];
}

void Matrix:: toString ()
{
    int i;
    int j;
    for (i = 0; i < 20; i++)
    {
        cout << "\n\n\n Pessoa " << i << ":" << endl;
        for (j = 0; j < 1000; j++)
        {
            Coordinate coord = matrix [i] [j];
            cout << "(" << coord.getX();
            cout<< ", " << coord.getY() << ") ";
        }
    }
}

void Matrix:: setInfected (int person, int frame)
{
    int k;
    for (k = frame; k < 1000; k++)
        matrix[person][k].setInfected();
}

void Matrix:: attInfected(int frame)
{
    for (int i=0; i<50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (matrix[i][frame].isInfected() == true && matrix[i][frame].getX() != -1)
            {
                int xJ = matrix[j][frame].getX();
                int yJ = matrix[j][frame].getY();
                int xI = matrix[i][frame].getX();
                int yI = matrix[i][frame].getY();
                int x = xJ - xI;
                x = x*x;
                int y = yJ - yI;
                y = y*y;
                double soma = x + y;
                double distance = sqrt (soma);
                if (distance <= 100) {
                    setInfected(j, frame);
                }
            }
        }
    }
}

void Matrix:: infectThroughTrace(int frame) {

    for (int i = 0; i < 50; i++) {
        if (findCoordinateFromMap(matrix[i][frame])) setInfected(i, frame);
    }

}

void Matrix:: insertCoordinateIntoHashMap(Coordinate c) {
    if (c.isInfected()) infectedCoordinateMap.emplace(c.toString(), c.toString());
}

bool Matrix:: findCoordinateFromMap(Coordinate c) {
    if (infectedCoordinateMap.count(c.toString()) == 0) return false;
    return true;
}


void Matrix:: desenhaTrajeto(int person, int frame)
{
    glLineWidth(3.0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    for (int i = 0; i<frame; i++)
    {
        Coordinate Coord = matrix[person] [i];
        if (Coord.isInfected() && Coord.getX() != -1)
            glVertex3f(Coord.getX(), Coord.getY(), 0.0);
    }
    glEnd();
}


void  Matrix :: readFile ()
{
    Coordinate initiate (-1, -1);

    int posPerson = 0;
    int posFrame;
    //LEITURA DE ARQUIVO

    // Cria input file stream (ifstream)
    ifstream arq;

    cout << "Abrindo arquivo texto..." << endl;

    // Abre arquivo
    arq.open( "Brasil2.txt", ios::in );

    // Se houver erro, sai do programa
    if (!arq.is_open())
        cout << "Arquivo inválido" << endl;

    // Lê cabeçalho
    string cabecalho;
    getline(arq,cabecalho);

    // Exibe cabeçalho na tela
    cout << cabecalho << endl;
    // Agora, lê n registros numéricos
    do
    {
        posFrame = 0;
        string person, coords;
        arq >> person >> coords;
        if(!arq.fail())
        {
            while (coords != "\n")
            {
                size_t init = coords.find("(");
                if (init != 0)
                {
                    break;
                }
                size_t fim = coords.find (")");
                string coord1 = coords.substr(init, fim-init+1);

                //Adquire os dados das coordenadas
                size_t posX = coord1.find (",");
                string x = coord1.substr (init+1, posX - init-1);
                string coord2 = coord1.substr (posX+1);
                size_t posY = coord2.find (","); //coord1
                string y = coord2.substr (0, posY);
                string initFrame = coord2.substr (posY+1);
                size_t posFrame = initFrame.find (")");
                string frame = initFrame.substr (0, posFrame);
                //cout << "(" << x << ", " << y << ", " <<frame << ") " <<endl;
                //--
                int cordX = atoi(x.c_str());
                int cordY = atoi(y.c_str());
                int cFrame = atoi(frame.c_str());

                Coordinate Coor(cordX, cordY);
                //cout<< "Posicao: " <<posPerson<< " " << cFrame << endl;
                mInsertCoord(Coor, posPerson, cFrame-1);

                coords = coords.substr(fim+1);
                posFrame++;
            }
        }

        posPerson++;
    }
    while(arq.good());
    if(arq.bad() || !arq.eof())
    {
        cout << "Erro fatal!" << endl;
        exit(1);		// Aborta programa
    }
    cout << "Fechando o arquivo..." << endl;
    arq.close();

    return;
}
