#ifndef ENGINE_H_
#define ENGINE_H_

//#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <ctime>
#include <cmath>

enum class Dirs {
   UP,
   DOWN,
   RIGHT,
   LEFT
};
//#define UP 10
//#define DOWN -10
//#define RIGHT 20
//#define LEFT -20
#define SNAKE_MAX 60

void initGrid(int x, int y);
void drawGrid();
void unit(int x, int y);
void drawSnake();
void drawFood();

#endif // ENGINE_H_

