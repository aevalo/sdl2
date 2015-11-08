#include <SDL_stdinc.h>
#include "zlib_dso.hpp"

zlib::zlib()
 : base("libz.so.1"), mVersionFunc(NULL)
{
  mVersionFunc = (const char* (*)())sdl2::dso::LoadFunction(mHandle, "zlibVersion");
}

zlib::~zlib()
{
}

const char* zlib::version()
{
  return mVersionFunc();
}
