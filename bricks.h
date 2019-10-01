#ifndef BRICKS_H
#define BRICKS_H
#include "my-matrix.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

struct Brick
{
public:
  Brick() = default;

  void draw() const {};
  void translate(point);
  void rotate(float);
private:
  point center = point();
  point v      = point();
  float w      = 0.0f;
  float theta  = 0.0f;
  vpoint vertices;
};

#endif
