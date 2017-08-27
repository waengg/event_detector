//Autores: João M Júnior e Gabriel Henrique

#include <iostream>
#include <stdlib.h>
#include "Coordinate.h"
#include "Matrix.h"
#include "TextFiles.h"
#include "InfectedTrail.h"
#include <fstream>	// para usar file streams (ifstream,ofstream)
#include <string>	// para usar string
#include <iomanip>	// para usar manipuladores (setw, right, ...)
#include <cstdlib>	// para usar srand(), rand() e exit()
#include <time.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>


using namespace std;
Matrix M (50, 1000);
GLfloat x1 = 1.0f;
GLfloat y1 = 1.0f;
GLsizei rsize = 30;
int frame = 0;
int simulation = 0;
string file;
TextFiles files;
bool automatic;
InfectedTrail trail;

void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(33,Timer, 1);
}

void delay(float secs)
{
	float end = clock()/CLOCKS_PER_SEC + secs;
	while((clock()/CLOCKS_PER_SEC) < end);
}


void setInfectedColor (Coordinate c) {
    if (c.isInfected() && c.getStartInfection()>8) {
        glColor3f (0.0, 0.9f, 0.0f);
        return;
    }
    switch (c.getStartInfection()) {
    case 0:
        glColor3f (0.0, 0.0f, 0.0f);
        break;
    case 1:
        glColor3f (0.0, 0.1f, 0.0f);
        break;
    case 2:
        glColor3f (0.0, 0.2f, 0.0f);
        break;
    case 3:
        glColor3f (0.0, 0.3f, 0.0f);
        break;
    case 4:
        glColor3f (0.0, 0.4f, 0.0f);
        break;
    case 5:
        glColor3f (0.0, 0.5f, 0.0f);
        break;
    case 6:
        glColor3f (0.0, 0.6f, 0.0f);
        break;
    case 7:
        glColor3f (0.0, 0.7f, 0.0f);
        break;
    case 8:
        glColor3f (0.0, 0.8f, 0.0f);
        break;
    }
}

void Desenha(void)
{
    bool finished = true;
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
    M.setStartInfections(frame);
    for (int i = 0; i < 50; i++) {
    Coordinate c = M.getCoord(i, frame);
    if (c.isInfected() && c.getX() != -1) {
        //M.insertCoordinateIntoHashMap(c);
        trail.addTrail(c);
    }
    int xInc = c.getX();
    int yInc = c.getY();
    //cout << frame << endl;
    if (xInc != -1 && yInc != -1 && frame != 1000) {
    if (trail.InfectByTrail (c)) M.setInfected(i, frame);
     finished = false;
     glBegin(GL_QUADS);
                if (c.isInfected()) {
                    setInfectedColor(c);
                    //glColor3f (0.0, 0.5f, 0.0f);
               }

               if (!c.isInfected()) glColor3f(0.0f, 0.0f, 0.7f);
               glVertex2i(xInc,yInc+rsize);
               glVertex2i(xInc,yInc);
               glVertex2i(xInc+rsize,yInc);
               glVertex2i(xInc+rsize,yInc+rsize);
     glEnd();
    }
    if (c.isInfected()) M.desenhaTrajeto(i, frame);
    }
    M.attInfected(frame);
    M.infectThroughTrace(frame);
    frame++;
    if (finished == true) {
            if (automatic == true){
                trail.clearTrail();
                files.startNew(M);
                frame = 0;
            }
    }
     // Executa os comandos OpenGL
     glutSwapBuffers();
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
    int op;
    string arq;
    cout << "\t Voce deseja executar automaticamente? \n 1- Sim \n 2- Nao \n" << endl;
    cin >> op;
    if (op == 2) {
        cout << " Digite o nome do arquivo para execucao: " << endl;
        cin >> arq;
        M.readFile(arq);
        M.setInfected(0, 0);
    }
    else {
        automatic = true;
        files.startNew(M);
    }
    //M.readFile();
    //M.attInfected(frame);
    //M.toString();

	int argc = 0;
	char *argv[] = { (char *)"gl", 0 };

	glutInit(&argc,argv);

// Define do modo de operação da GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(900,750);

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



