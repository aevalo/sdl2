#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char* const argv[])
{
  srand(time(NULL));

  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to initialize SDL:  %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  atexit(SDL_Quit);

  if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to initialize SDL2 image:  %s\n", IMG_GetError());
    exit(EXIT_FAILURE);
  }
  atexit(IMG_Quit);

  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;
  if (SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_SHOWN, &window, &renderer) < 0)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  SDL_Surface* icon = IMG_Load("resources/iconzilla.png");
  if (!icon)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load icon file: %s\n", IMG_GetError());
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    exit(EXIT_FAILURE);
  }
  SDL_SetWindowIcon(window, icon);
  SDL_FreeSurface(icon);
  SDL_SetWindowTitle(window, "SDL2 test app");

  int done = 0;
  SDL_Point lines[3][2] = {
    {
      {rand() % 640, rand() % 480},
      {rand() % 640, rand() % 480}
    },
    {
      {rand() % 640, rand() % 480},
      {rand() % 640, rand() % 480}
    },
    {
      {rand() % 640, rand() % 480},
      {rand() % 640, rand() % 480}
    }
  };
  SDL_Color colors[3] = {
    {255, 0, 0, SDL_ALPHA_OPAQUE},
    {0, 255, 0, SDL_ALPHA_OPAQUE},
    {0, 0, 255, SDL_ALPHA_OPAQUE}
  };
  while (!done)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_WINDOWEVENT)
      {
        switch (event.window.event)
        {
          case SDL_WINDOWEVENT_CLOSE:
            done = 1;
            break;
        }
      }
    }
    if (SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) < 0)
    {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to set draw color: %s\n", SDL_GetError());
    }
    if (SDL_RenderClear(renderer) < 0)
    {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to clear renderer: %s\n", SDL_GetError());
    }
    for(int i = 0; i < 3; i++)
    {
      if (SDL_SetRenderDrawColor(renderer, colors[i].r, colors[i].g, colors[i].b, colors[i].a) < 0)
      {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to set draw color: %s\n", SDL_GetError());
      }
      if (SDL_RenderDrawLines(renderer, lines[i], 2) < 0)
      {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to draw line: %s\n", SDL_GetError());
      }
    }
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  return 0;
}