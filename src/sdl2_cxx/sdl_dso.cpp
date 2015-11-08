#include <SDL_loadso.h>
#include "sdl_dso.hpp"
#include "sdl_error.hpp"

namespace sdl2
{
  namespace dso
  {
    void* LoadFunction(void* handle, const char* name)
    {
      void* func = SDL_LoadFunction(handle, name);
      if(func == NULL)
      {
        throw sdl_error();
      }
      return func;
    }

    void* LoadObject(const char* sofile)
    {
      void* handle = SDL_LoadObject(sofile);
      if(handle == NULL)
      {
        throw sdl_error();
      }
      return handle;
    }

    void UnloadObject(void* handle)
    {
      SDL_UnloadObject(handle);
    }

    base::base(const char* sofile)
     : mHandle(NULL)
    {
      mHandle = LoadObject(sofile);
    }

    base::~base()
    {
      UnloadObject(mHandle);
    }
  }
}
