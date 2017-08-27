#include "TextFiles.h"
#include <string>
#include <time.h>
#include <cstdlib>
TextFiles::TextFiles()
{
    file = " ";
    simulation = 0;
}


void TextFiles:: delay(float secs)
{
	float end = clock()/CLOCKS_PER_SEC + secs;
	while((clock()/CLOCKS_PER_SEC) < end);
}

void TextFiles:: startNew (Matrix M)
{
    switch (simulation) {
    case 0:
        file = "Alemanha1.txt";
        simulation++;
        break;

    case 1:
        file = "Alemanha2.txt";
        simulation++;
        break;

    case 2:
        file = "Austria1.txt";
        simulation++;
        break;

    case 3:
        file = "Austria2.txt";
        simulation++;
        break;

    case 4:
        file = "Austria3.txt";
        simulation++;
        break;

    case 5:
        file = "Brasil1.txt";
        simulation++;
        break;

    case 6:
        file = "Brasil2.txt";
        simulation++;
        break;

    case 7:
        file = "Brasil3.txt";
        simulation++;
        break;

    case 8:
        file = "Brasil4.txt";
        simulation++;
        break;

    case 9:
        file = "Brasil5.txt";
        simulation++;
        break;

    case 10:
        file = "Brasil6.txt";
        simulation++;
        break;

    case 11:
        file = "Brasil7.txt";
        simulation++;
        break;

    case 12:
        file = "Brasil8.txt";
        simulation++;
        break;

    case 13:
        file = "China1.txt";
        simulation++;
        break;

    case 14:
        file = "China2.txt";
        simulation++;
        break;

    case 15:
        file = "China3.txt";
        simulation++;
        break;

    case 16:
        file = "Desconhecido1.txt";
        simulation++;
        break;

    case 17:
        file = "Desconhecido2.txt";
        simulation++;
        break;

    case 18:
        file = "Desconhecido3.txt";
        simulation++;
        break;

    case 19:
        file = "Dubai1.txt";
        simulation++;
        break;

    case 20:
        file = "Dubai2.txt";
        simulation++;
        break;

    case 21:
        file = "Espanha1.txt";
        simulation++;
        break;

    case 22:
        file = "Franca1.txt";
        simulation++;
        break;

    case 23:
        file = "Franca2.txt";
        simulation++;
        break;

    case 24:
        file = "Inglaterra1.txt";
        simulation = 0;
        break;


    case 25:
        file = "Japao1.txt";
        simulation++;
        break;

    case 26:
        file = "Japao2.txt";
        simulation++;
        break;

    case 27:
        file = "Portugal1.txt";
        simulation++;
        break;

    case 28:
        file = "Turquia1.txt";
        simulation=0;
        break;


    }
    delay (3.0);
    M.Initialize();
    M.clearMap();
    M.readFile(file);
    M.setInfected(0, 0);
    M.setInfected(5, 0);
}
