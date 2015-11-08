#ifndef BZIP2_DSO_HPP_INCLUDED
#define BZIP2_DSO_HPP_INCLUDED

#include <sdl_dso.hpp>

class bzip2 : public sdl2::dso::base
{
  public:
    bzip2();
    virtual ~bzip2();
    const char* version();
  private:
    const char* (*mVersionFunc)();
};

#endif // BZIP2_DSO_HPP_INCLUDED