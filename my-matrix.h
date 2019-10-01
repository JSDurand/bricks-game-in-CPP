#ifndef MY_MATRIX_H
#define MY_MATRIX_H
#include <vector>

struct point {
  point() = default;
  point(float x, float y): x(x), y(y) {};
  float x = 0;
  float y = 0;
};

typedef std::vector<point> vpoint;


#endif
