#include <iostream>
#include <stdlib.h>
#include "Coordinate.h"
#include "Matrix.h"
#include <fstream>	// para usar file streams (ifstream,ofstream)
#include <string>	// para usar string
#include <iomanip>	// para usar manipuladores (setw, right, ...)
#include <cstdlib>	// para usar srand(), rand() e exit()

#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;
Matrix M (50, 1000);
GLfloat x1 = 1.0f;
GLfloat y1 = 1.0f;
GLsizei rsize = 30;
int frame = 0;

void Desenha(void)
{
    // Limpa a janela de visualização com a cor branca
    glClearColor(1,1,1,0);
    //glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    // Especifica que a cor corrente é vermelha
    //         R     G     B
    //glColor3f(1.0f, 0.0f, 0.0f);

    // Desenha um quadrado preenchido com a cor corrente
    for (int i = 0; i < 50; i++)
    {
        Coordinate c = M.getCoord(i, frame);
        if (c.isInfected()) M.insertCoordinateIntoHashMap(c);
        int xInc = c.getX();
        int yInc = c.getY();
        //cout << frame << endl;
        if (xInc != -1 && yInc != -1 && frame != 1000)
        {
            //cout<< "Desenha" << frame << endl;
            glBegin(GL_QUADS);
            if (c.isInfected())
            {
                glColor3f(0.0f, 1.0f, 1.0f);
            }
            else glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2i(xInc,yInc+rsize);
            glVertex2i(xInc,yInc);
            glVertex2i(xInc+rsize,yInc);
            glVertex2i(xInc+rsize,yInc+rsize);
            glEnd();
        }
        if (c.isInfected()) M.desenhaTrajeto(i, frame);
        M.attInfected(frame);
        M.infectThroughTrace(frame);
    }
    frame++;

    // Executa os comandos OpenGL
    glutSwapBuffers();
}


void Timer(int value)
{
    //int xInc = M.getCoord(3, frame).getX();
    //int yInc = M.getCoord(3, frame).getY();
    // Move o quadrado
    //x1 = xInc;
    //y1 = yInc;
    //frame++;
    // Redesenha o quadrado com as novas coordenadas
    glutPostRedisplay();
    glutTimerFunc(33,Timer, 1);
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);
}

// Função responsável por inicializar parâmetros e variáveis
void Inicializa(void)
{
    // Define a janela de visualização 2D
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0,2000.0,-1.0,2000.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(void)
{
    //Cria matriz de dados
    M.readFile();
    M.setInfected(0, 0);
    //M.attInfected(frame);
    //M.toString();

    int argc = 0;
    char *argv[] = { (char *)"gl", 0 };

    glutInit(&argc,argv);

    // Define do modo de operação da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(1000,1000);

    // Cria a janela passando como argumento o título da mesma
    glutCreateWindow("Trabalho 1 Computação Gráfica");

    // Registra a função callback de redesenho da janela de visualização
    glutDisplayFunc(Desenha);


    // Registra a função callback para tratamento das teclas ASCII
    glutKeyboardFunc (Teclado);

    glutTimerFunc(33, Timer, 1);
    // Chama a função responsável por fazer as inicializações
    Inicializa();

    // Inicia o processamento e aguarda interações do usuário
    glutMainLoop();


    return 0;
}



