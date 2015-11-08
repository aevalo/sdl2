#include <SDL_stdinc.h>
#include "bzip2_dso.hpp"

bzip2::bzip2()
 : base("libbz2.so.1"), mVersionFunc(NULL)
{
  mVersionFunc = (const char* (*)())sdl2::dso::LoadFunction(mHandle, "BZ2_bzlibVersion");
}

bzip2::~bzip2()
{
}

const char* bzip2::version()
{
  return mVersionFunc();
}