#ifndef ZLIB_DSO_HPP_INCLUDED
#define ZLIB_DSO_HPP_INCLUDED

#include <sdl_dso.hpp>

class zlib : public sdl2::dso::base
{
  public:
    zlib();
    virtual ~zlib();
    const char* version();
  private:
    const char* (*mVersionFunc)();
};

#endif // ZLIB_DSO_HPP_INCLUDED