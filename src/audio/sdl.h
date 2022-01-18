#include "taAudio.h"
#if (defined(_WIN32) || defined(HAVE_GUI)) && !defined(DEVENDOR_LIBRARIES)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

class TAAudioSDL: public TAAudio {
  SDL_AudioSpec ac, ar;
  SDL_AudioDeviceID ai;

  public:
    void onProcess(unsigned char* buf, int nframes);

    void* getContext();
    bool quit();
    bool setRun(bool run);
    bool init(TAAudioDesc& request, TAAudioDesc& response);
};
