#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char* agrv[]){
  // Error
   if (SDL_Init(SDL_INIT_EVERYTHING)) 
        std::cout << SDL_GetError() <<std::endl;
  /* Code Body */
//     SDL_DestroyTexture(tex);
//     SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
