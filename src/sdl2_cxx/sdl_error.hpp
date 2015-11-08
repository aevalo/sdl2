#ifndef SDL_ERROR_HPP_INCLUDED
#define SDL_ERROR_HPP_INCLUDED

#include <exception>
#include <string>

namespace sdl2
{
  class sdl_error : public std::exception
  {
    public:
      sdl_error() throw();
      sdl_error(const std::string& msg) throw();
      virtual ~sdl_error() throw();
      virtual const char* what() const throw();
    private:
      int         mError;
      std::string mMessage;
  };
}

#endif // SDL_ERROR_HPP_INCLUDED