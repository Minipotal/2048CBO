// 2048CBO.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SDL.h>
#include "affichage.h"
#include "case.h"


int main(int argc, char* argv[]) {
	Affichage a;

    int res = a.init();
    if (res)
        a.drawGrid();
    else
        std::cout << "Initialisation ratée";
    return 0;
}
