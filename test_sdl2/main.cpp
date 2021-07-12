#include <iostream>
#include <SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Surface *surface;
SDL_Texture *texture;
bool isEnd = false;

void onFrame()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      isEnd = true;
      break;
    case SDL_KEYDOWN:
      isEnd = true;
      break;
    case SDL_KEYUP:
      isEnd = true;
      break;
    }
  }

  SDL_SetRenderDrawColor(renderer, 128, 128, 128, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  SDL_Rect dest = {100, 100, 200, 200};
  SDL_RenderCopyEx(renderer, texture, NULL, &dest, 0, NULL, SDL_FLIP_NONE);

  SDL_RenderPresent(renderer);
}

int main(int argc, char **argv)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
  if (!window)
  {
    std::cout << "SDL could not create window! SDL Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer)
  {
    std::cout << "SDL could not create renderer! SDL Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  surface = SDL_LoadBMP("assets/image.bmp");
  if (!surface)
  {
    std::cout << "SDL could not load image! SDL Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (!texture)
  {
    std::cout << "SDL could not create texture! SDL Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  SDL_FreeSurface(surface);

  while (!isEnd)
  {
    onFrame();
    SDL_Delay(20);
  }

  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  SDL_Quit();

  return 0;
}
