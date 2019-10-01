#include <iostream>
#include <vector>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include "game.h"
#include "my-matrix.h"
#include "bricks.h"
using namespace std;

bool Game::Initial()
{
  // SDL initialisations
  int sdlresult = SDL_Init(SDL_INIT_VIDEO);
  if (sdlresult != 0) {
    SDL_Log("Unable to initialize: %s", SDL_GetError());
    return false;
  }

  mWindow = SDL_CreateWindow("Snakes Game",
                             SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED,
                             mWidth, mHeight, SDL_WINDOW_RESIZABLE);

  if (!mWindow) {
    SDL_Log("Fail to create window: %s", SDL_GetError());
    return false;
  }

  mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (!mRenderer) {
    SDL_Log("Fail to create renderer: %s", SDL_GetError());
    return false;
  }

  // Game initialisations

  return true;
}

void Game::Loop()
{
  while (mIsRunning) {
    ProcessInput();
  }
}

void Game::Close()
{
  SDL_DestroyRenderer(mRenderer);
  SDL_DestroyWindow(mWindow);
  SDL_Quit();
}

void Game::ProcessInput()
{
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      mIsRunning = false;
      break;
    default:
      break;
    }

    const Uint8 *state = SDL_GetKeyboardState(nullptr);

    if (state[SDL_SCANCODE_ESCAPE]) 
      mIsRunning = false;
    else if (state[SDL_SCANCODE_A]) 
      mIsRunning = false;
    // else if (state[SDL_SCANCODE_J]
    //          && mSnake.mDir != UP)
    //   mSnake.mDir = DOWN;
    // else if (state[SDL_SCANCODE_K]
    //          && mSnake.mDir != DOWN)
    //   mSnake.mDir = UP;
    // else if (state[SDL_SCANCODE_H]
    //          && mSnake.mDir != RIGHT)
    //   mSnake.mDir = LEFT;
    // else if (state[SDL_SCANCODE_L]
    //          && mSnake.mDir != LEFT)
    //   mSnake.mDir = RIGHT;
    // else if (state[SDL_SCANCODE_S])
    //   mSnake.mDir = STOP;
  }
}

void Game::UpdateGame()
{
  // Frame limiting to 30FPS.
  while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTickCount + 1000 / mFPS)) {}
  
  float deltaTime = (SDL_GetTicks() - mTickCount) / 1000.0f;
  const float max_delta_time = 0.05f;

  deltaTime = deltaTime > max_delta_time ? max_delta_time : deltaTime;

  mTickCount = SDL_GetTicks();

}

void Game::GenerateOutput()
{
  SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 100);
  SDL_RenderClear(mRenderer);

  SDL_RenderPresent(mRenderer);
}

int main()
{
  Game game;

  bool success = game.Initial();

  if (success) 
    game.Loop();


  game.Close();
  
  return 0;
}
