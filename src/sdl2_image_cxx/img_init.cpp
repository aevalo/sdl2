#include <SDL_image.h>
#include <sdl_error.hpp>
namespace sdl2
{
  namespace image
  {
    void LinkedVersion(SDL_version& version)
    {
      const SDL_version* link_version = IMG_Linked_Version();
      version.major = link_version->major;
      version.minor = link_version->minor;
      version.patch = link_version->patch;
    }

    void CompiledVersion(SDL_version& version)
    {
      SDL_IMAGE_VERSION(&version);
    }

    void Init(int flags)
    {
      int initted = IMG_Init(flags);
      if(initted & flags != flags)
      {
        throw sdl_error();
      }
    }

    void Quit()
    {
      IMG_Quit();
    }
  }
}
