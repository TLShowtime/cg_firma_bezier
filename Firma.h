#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

#define H_SIZE 1280
#define V_SIZE 500

#define POINT_LENGTH 500

#define SCALE_VAR 8

typedef struct {
  double r;
  double g;
  double b;
} COLOR;

typedef struct {
    int x;
    int y;
} POINT;

void calculate_Brezier(POINT* P0, POINT* P1, POINT* P2, POINT* P3);
void plot(int x,int y);
void bressenham_line (int x0, int y0, int x1, int y1);


