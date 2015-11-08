#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sdl_init.hpp>
#include <sdl_error.hpp>
#include <sdl_window.hpp>
#include <sdl_renderer.hpp>
#include <img_init.hpp>
#include "zlib_dso.hpp"
#include "bzip2_dso.hpp"


int main(int argc, const char* const argv[])
{
  std::srand(std::time(NULL));
  sdl2::renderer* rend = NULL;

  try
  {
    sdl2::Init(SDL_INIT_VIDEO);
    std::atexit(sdl2::Quit);

    sdl2::image::Init(IMG_INIT_PNG);
    std::atexit(sdl2::image::Quit);
    zlib libz;
    bzip2 libbz2;

    std::cout << "zlib version: " << libz.version() << std::endl;
    std::cout << "bzip2 version: " << libbz2.version() << std::endl;

    sdl2::window window(640, 480, SDL_WINDOW_SHOWN, &rend);
    SDL_Surface* icon = IMG_Load("resources/iconzilla.png");
    if (!icon)
    {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load icon file: %s\n", IMG_GetError());
      delete rend;
      std::exit(EXIT_FAILURE);
    }
    window.icon(icon);
    SDL_FreeSurface(icon);
    window.title("SDL2 test app");
    SDL_Renderer* renderer = *rend;

    int done = 0;
    SDL_Point lines[3][2] = {
      {
        {std::rand() % 640, std::rand() % 480},
        {std::rand() % 640, std::rand() % 480}
      },
      {
        {std::rand() % 640, std::rand() % 480},
        {std::rand() % 640, std::rand() % 480}
      },
      {
        {std::rand() % 640, std::rand() % 480},
        {std::rand() % 640, std::rand() % 480}
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
  }
  catch(const sdl2::sdl_error& error)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to initialize SDL2:  %s\n", error.what());
    delete rend;
    exit(EXIT_FAILURE);
  }

  delete rend;
  return 0;
}