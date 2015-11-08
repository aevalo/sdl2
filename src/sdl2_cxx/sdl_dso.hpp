#ifndef SDL_DSO_HPP_INCLUDED
#define SDL_DSO_HPP_INCLUDED

namespace sdl2
{
  namespace dso
  {
    void* LoadFunction(void* handle, const char* name);
    void* LoadObject(const char* sofile);
    void UnloadObject(void* handle);

    class base
    {
      public:
        base(const char* sofile);
        virtual ~base();
      protected:
        void* mHandle;
    };
  }
}

#endif // SDL_DSO_HPP_INCLUDED