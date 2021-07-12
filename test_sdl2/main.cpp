#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

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
      switch (event.key.keysym.sym)
      {
      case SDLK_w:
        std::cout << "w" << std::endl;
        break;
      case SDLK_s:
        std::cout << "s" << std::endl;
        break;
      }
      break;
    case SDL_KEYUP:
      isEnd = true;
      break;
    case SDL_MOUSEMOTION:
      std::cout << "mouse motion (" << event.motion.x << ", " << event.motion.y << ")" << std::endl;
      break;
    }
  }

  SDL_SetRenderDrawColor(renderer, 50, 50, 50, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  SDL_Rect dest;
  dest.x = 100;
  dest.y = 50;
  dest.w = 100;
  dest.h = 100;
  SDL_RenderCopyEx(renderer, texture, NULL, &dest, 0, NULL, SDL_FLIP_NONE);

  dest.x = 200;
  dest.y = 200;
  dest.w = 100;
  dest.h = 100;
  SDL_SetRenderDrawColor(renderer, 250, 50, 50, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(renderer, &dest);

  SDL_RenderPresent(renderer);
}

void mainLoop()
{
#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(onFrame, 0, 1);
#else
  while (!isEnd)
  {
    onFrame();
    SDL_Delay(20);
  }
#endif
}

extern "C" int main(int argc, char **argv)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  if (IMG_Init(IMG_INIT_PNG) < 0)
  {
    std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
    return 1;
  }

  if (TTF_Init() < 0)
  {
    std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
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

  mainLoop();

  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  TTF_Quit();
  IMG_Quit();
  SDL_Quit();

  return 0;
}
