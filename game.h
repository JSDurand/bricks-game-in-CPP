#ifndef GAME_H
#define GAME_H
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

class Game
{
public:
  Game() = default;

  bool Initial();
  void Loop();
  void Close();
private:
  void ProcessInput();
  void UpdateGame();
  void GenerateOutput();

  bool mIsRunning = true;
  // bool mPause     = false;
  int mWidth      = 1024;
  int mHeight     = 768;

  SDL_Window *mWindow;

  SDL_Renderer *mRenderer;

  Uint32 mTickCount;

  int mFPS = 30;
};

#endif
