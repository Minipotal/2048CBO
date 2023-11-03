#include "SDL.h"
#include <iostream>
#include "affichage.h"

Affichage::Affichage() {

}


bool Affichage::init() {
    int iError = SDL_Init(SDL_INIT_VIDEO);
    if (iError != 0)
    {
        std::cout << "Error SDL_Init :" << SDL_GetError();
        exit(1);
    }


    pWindow = SDL_CreateWindow("2048 Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 720, SDL_WINDOW_SHOWN);
    if (pWindow == NULL) {
        std::cout << "Erreur SDL_CreateWindow :" << SDL_GetError();
        exit(1);

    }

    pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (pRenderer == NULL) {
        std::cout << "Erreur SDL_CreateRenderer :" << SDL_GetError();
        exit(1);
    }

    return true;
}

void Affichage::drawGrid() {
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(pRenderer);

    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            SDL_Rect tileRect = { col * 180, row * 180, 180, 180 };

            SDL_SetRenderDrawColor(pRenderer, 204, 153, 102, 255);
            SDL_RenderFillRect(pRenderer, &tileRect);

            SDL_SetRenderDrawColor(pRenderer, 102, 51, 0, 255);
            SDL_RenderDrawRect(pRenderer, &tileRect);
        }
    }

    SDL_RenderPresent(pRenderer);
}


void Affichage::close()
{
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}



