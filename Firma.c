#include "Firma.h"

COLOR **buffer;



void calculate_Brezier(POINT* P0, POINT* P1, POINT* P2, POINT* P3){
    double t, q_x, q_y, previous_x, previous_y;

    previous_x = (double)P0->x; 
    previous_y = (double)P0->y;

    for (t = 0.001; t <= 1.0; t += 0.001){
        q_x = P0->x * pow((1 - t),3) + P1->x * 3 * t * pow((1 - t),2) + P2->x * 3 * pow(t, 2) * (1 - t) + P3->x * pow(t,3);
        q_y = P0->y * pow((1 - t),3) + P1->y * 3 * t * pow((1 - t),2) + P2->y * 3 * pow(t, 2) * (1 - t) + P3->y * pow(t,3);
        
        bressenham_line((int)previous_x, (int)previous_y, (int)q_x, (int)q_y);

        previous_x = q_x;
        previous_y = q_y;

    }
    
};

void display (void)
{
  glClear (GL_COLOR_BUFFER_BIT);
  int x, y;
  // Z
  x = 40;
  y = 380;

  POINT P0 = {.x = x, .y = y};
  POINT P1 = {.x = 17*SCALE_VAR + x, .y = 1 * SCALE_VAR + y};
  POINT P2 = {.x = 19*SCALE_VAR + x, .y = y - SCALE_VAR};
  POINT P3 = {.x = 7* SCALE_VAR + x, .y = y - 6*SCALE_VAR};

  calculate_Brezier(&P0,&P1,&P2,&P3);
  
  P0.x = P3.x;
  P0.y = P3.y;
  P1.x = P0.x - 10 * SCALE_VAR;
  P1.y = P0.y - 6 * SCALE_VAR;
  P2.x = P0.x - 6 * SCALE_VAR;
  P2.y = P0.y - 6 * SCALE_VAR;
  P3.x = P0.x + 10 * SCALE_VAR;
  P3.y = P0.y - 7 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  // h
  P0.x = P0.x + 10 * SCALE_VAR;
  P0.y = 380;
  P1.x = P0.x + 1 * SCALE_VAR;
  P1.y = P0.y - 6 * SCALE_VAR;
  P2.x = P0.x + 2 * SCALE_VAR;
  P2.y = P0.y - 9 * SCALE_VAR;
  P3.x = P0.x + 2.5 * SCALE_VAR;
  P3.y = P0.y - 14 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  P0.x = P3.x;
  P0.y = P3.y;
  P1.x = P3.x - 2 * SCALE_VAR;
  P1.y = P3.y + 6 * SCALE_VAR;
  P2.x = P3.x + 4 * SCALE_VAR;
  P2.y = P3.y + 8 * SCALE_VAR;
  P3.x = P3.x + 3 * SCALE_VAR;
  P3.y = P3.y + 2 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);
  
  //O
  P0.x = 250;
  P0.y = 320;
  P1.x = P0.x - 1.5 * SCALE_VAR;
  P1.y = P0.y - 0.5 * SCALE_VAR;
  P2.x = P1.x;
  P2.y = P0.y - 3 * SCALE_VAR;
  P3.x = P0.x;
  P3.y = P0.y - 4 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);
  
  P1.x = P0.x + 5 * SCALE_VAR;
  P1.y = P0.y - 1 * SCALE_VAR;
  P2.x = P0.x + 2.5 * SCALE_VAR;
  P2.y = P0.y - 4 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);
  
  // N
  P0.x = 280;
  P0.y = 320;
  P1.x = P0.x + 2 * SCALE_VAR;
  P1.y = P0.y - 3 * SCALE_VAR;
  P2.x = P0.x + 2 * SCALE_VAR;
  P2.y = P0.y - 3 * SCALE_VAR;
  P3.x = P0.x + 2.25 * SCALE_VAR;
  P3.y = P0.y - 5 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  P0.x = P3.x;
  P0.y = P3.y;
  P1.x = P3.x - 2 * SCALE_VAR;
  P1.y = P3.y + 6 * SCALE_VAR;
  P2.x = P3.x + 4 * SCALE_VAR;
  P2.y = P3.y + 8 * SCALE_VAR;
  P3.x = P3.x + 3 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  //G
  P0.x = 380;
  P0.y = 310;
  P1.x = P0.x - 8 * SCALE_VAR;
  P1.y = P0.y + 3.5 * SCALE_VAR;
  P2.x = P0.x - 4.5 * SCALE_VAR;
  P2.y = P0.y - 9.5 * SCALE_VAR;
  P3.x = P0.x + 10;
  P3.y = P0.y +  5;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  P0.x = P3.x;
  P0.y = P3.y;
  P1.x = P0.x + 2 * SCALE_VAR;
  P1.y = P0.y - 17 * SCALE_VAR;
  P2.x = P0.x - 1.5 * SCALE_VAR;
  P2.y = P0.y - 14 * SCALE_VAR;
  P3.x = P0.x - 7 * SCALE_VAR;
  P3.y = P0.y - 15 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);
  
  // J
  P0.x = 490;
  P0.y = 350;
  P1.x = P0.x + 3.5 * SCALE_VAR;
  P1.y = P0.y - 11 * SCALE_VAR;
  P2.x = P0.x - 2  * SCALE_VAR;
  P2.y = P0.y - 12 * SCALE_VAR;
  P3.x = P0.x - 5 * SCALE_VAR;
  P3.y = P0.y - 7 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  P1.x = P0.x;
  P1.y = P0.y;
  P0.x = P3.x;
  P0.y = P1.y - SCALE_VAR;
  P2.x = P1.x + 3 * SCALE_VAR;
  P2.y = P1.y + SCALE_VAR;
  P3.x = P1.x + 6 * SCALE_VAR;
  P3.y = P1.y + 1.5 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);
  
  // I
  P0.x = P3.x - 8 ;
  P0.y = 300 ;
  P1.x = P0.x + 0.5 * SCALE_VAR;
  P1.y = P0.y - 2 * SCALE_VAR;
  P2.x = P0.x + 1 * SCALE_VAR;
  P2.y = P0.y - 3 * SCALE_VAR;
  P3.x = P0.x + 1 * SCALE_VAR;
  P3.y = P0.y - 4 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  // E
  P0.x = P0.x + 30;
  P1.x = P0.x + 2 * SCALE_VAR;
  P1.y = P0.y - 8 * SCALE_VAR;
  P2.x = P0.x + 11 * SCALE_VAR;
  P2.y = P0.y + 4 * SCALE_VAR;
  P3.x = P0.x + 1.75 * SCALE_VAR;
  P3.y = P0.y + 2 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  P0.x = P3.x;
  P0.y = P3.y;
  P1.x = P0.x - 2 * SCALE_VAR;
  P1.y = P0.y - 0.5 * SCALE_VAR;
  P2.x = P0.x;
  P2.y = P0.y - 12 * SCALE_VAR;
  P3.x = P0.x + 5 * SCALE_VAR;
  P3.y = P0.y - 6 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  // L
  P0.x = 700;
  P0.y = 370;
  P1.x = P0.x + 0.5 * SCALE_VAR;
  P1.y = P0.y - 8 * SCALE_VAR;
  P2.x = P0.x - 3 * SCALE_VAR;
  P2.y = P1.y - 5 * SCALE_VAR;
  P3.x = P0.x + 1 * SCALE_VAR;
  P3.y = P0.y - 12 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  P0.x = P3.x;
  P0.y = P3.y;
  P1.x = P0.x + 0.5 * SCALE_VAR;
  P1.y = P0.y;
  P2.x = P0.x + 5 * SCALE_VAR;
  P2.y = P1.y;
  P3.x = P0.x + 8 * SCALE_VAR;
  P3.y = P0.y;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  // I
  P0.x = P3.x + 10;
  P0.y = P3.y + 35;
  P1.x = P0.x + 0.5 * SCALE_VAR;
  P1.y = P0.y - 2 * SCALE_VAR;
  P2.x = P0.x + 1 * SCALE_VAR;
  P2.y = P0.y - 3 * SCALE_VAR;
  P3.x = P0.x + 1 * SCALE_VAR;
  P3.y = P0.y - 4 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  // U
  P0.x = P0.x + 20;
  P0.y = P0.y;
  P1.x = P0.x - SCALE_VAR;
  P1.y = P0.y - 6 * SCALE_VAR;
  P2.x = P0.x + 3 * SCALE_VAR;
  P2.y = P0.y - 6 * SCALE_VAR;
  P3.x = P0.x + 4 * SCALE_VAR;
  P3.y = P0.y - 2 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  P0.x = P3.x;
  P0.y = P3.y;
  P1.x = P0.x;
  P1.y = P0.y - 1 * SCALE_VAR;
  P2.x = P0.x;
  P2.y = P0.y - 3 * SCALE_VAR;
  P3.x = P0.x + SCALE_VAR;
  P3.y = P0.y - 2.5 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);
  
  // G
  P0.x = 1040;
  P0.y = 350;
  P1.x = P0.x - 1 * SCALE_VAR ;
  P1.y = P0.y + 7 * SCALE_VAR;
  P2.x = P0.x - 21 * SCALE_VAR;
  P2.y = P0.y - 15 * SCALE_VAR;
  P3.x = P0.x - 2 * SCALE_VAR;
  P3.y = P0.y - 10 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  P0.x = P3.x;
  P0.y = P3.y;
  P1.x = P0.x + 6 * SCALE_VAR ;
  P1.y = P0.y + 4 * SCALE_VAR;
  P2.x = P0.x - 5 * SCALE_VAR;
  P2.y = P0.y + 6 * SCALE_VAR;
  P3.x = P0.x - 3 * SCALE_VAR;
  P3.y = P0.y + 4 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  // U
  P0.x = 1060;
  P0.y = 310;
  P1.x = P0.x - SCALE_VAR;
  P1.y = P0.y - 6 * SCALE_VAR;
  P2.x = P0.x + 3 * SCALE_VAR;
  P2.y = P0.y - 6 * SCALE_VAR;
  P3.x = P0.x + 6 * SCALE_VAR;
  P3.y = P0.y;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  P0.x = P3.x;
  P0.y = P3.y;
  P1.x = P0.x;
  P1.y = P0.y - 2 * SCALE_VAR;
  P2.x = P0.x - 2 * SCALE_VAR;
  P2.y = P0.y - 7 * SCALE_VAR;
  P3.x = P0.x + SCALE_VAR;
  P3.y = P0.y - 4.5 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  //O
  P0.x = 1135;
  P0.y = 310;
  P1.x = P0.x - 1.5 * SCALE_VAR;
  P1.y = P0.y - 0.5 * SCALE_VAR;
  P2.x = P1.x;
  P2.y = P0.y - 3 * SCALE_VAR;
  P3.x = P0.x;
  P3.y = P0.y - 5 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);
  
  P1.x = P0.x + 7 * SCALE_VAR;
  P1.y = P0.y - 1 * SCALE_VAR;
  P2.x = P0.x + 7 * SCALE_VAR;
  P2.y = P0.y - 4 * SCALE_VAR;
  calculate_Brezier(&P0,&P1,&P2,&P3);

  glFlush();
}

int main(int argc, char** argv) 
{
  int i, j;

  buffer = (COLOR **)malloc(H_SIZE * sizeof(COLOR*));
  for (i = 0; i < H_SIZE; i++) 
      {
       buffer[i] = (COLOR *)malloc(V_SIZE * sizeof(COLOR));
      }

  for (i = 0; i < H_SIZE; i++) 
      {
       for (j = 0; j < V_SIZE; j++) 
           {
            buffer[i][j].r = 0;
            buffer[i][j].g = 0;
            buffer[i][j].b = 0;
           }
      }

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(H_SIZE,V_SIZE);
  glutCreateWindow("Firma");
  glClear(GL_COLOR_BUFFER_BIT); 
  gluOrtho2D(-0.5, H_SIZE +0.5, -0.5, V_SIZE + 0.5);

  glutDisplayFunc(display);
 
  glutMainLoop();
}

void plot(int x,int y){
  COLOR color;
  buffer[x][y].r = 255;
  buffer[x][y].g = 255;
  buffer[x][y].b = 255;
  glColor3f (buffer[x][y].r,buffer[x][y].g,buffer[x][y].b);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}


void bressenham_line(int x0, int y0, int x1, int y1){
  int Delta_E, Delta_NE, Delta_N, Delta_NO, x, xAbs, d;
  int Delta_O, Delta_SO, Delta_S, Delta_SE, y, yAbs;

  x = x0; y = y0;
  plot(x, y);

  xAbs = abs(x1 - x0);
  yAbs = abs(y1 - y0);
  
  if (x0<=x1){
    if (y0<=y1){
      Delta_NE  =  2 * ((y1 - y0) - (x1 - x0)); //Valor para avanzar un pixel hacia arriba y uno a la derecha
      if (xAbs>=yAbs){ //octante 1
        d = 2*(y1-y0) - (x1-x0);
        Delta_E   =  2 * (y1 - y0);                 //Valor para avanzar un pixel a la derecha
        while (x < x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d < 0){
            x++;
            d = d + Delta_E;
          }
          else{
            x++; y++;
            d = d + Delta_NE;
          }
          plot(x,y);
        }
      }
      else{ //octante 2
        d = (y1-y0) - 2*(x1-x0);
        Delta_N  = -2 * (x1 - x0);             //Valor para avanzar un pixel hacia arriba
        while (y < y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d > 0){
            y++;
            d = d + Delta_N;
          }
          else{
            x++; y++;
            d = d + Delta_NE;
          }
          plot(x,y);
        }
      }
    }
    else{
      Delta_SE  =  2 * ((y1 - y0) + (x1 - x0)); //Valor para avanzar un pixel hacia abajo y uno a la derecha
      if (xAbs<=yAbs){ //octante 7
        d = (y1-y0) + 2*(x1-x0);
        Delta_S   =  2 * (x1 - x0);             //Valor para avanzar un pixel hacia abajo
        while (y > y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d < 0){
            y--;
            d = d + Delta_S;
          }
          else{
            x++; y--;
            d = d + Delta_SE;
          }
          plot(x,y);
        }
      }
      else{ //octante 8
        d = 2*(y1-y0) + (x1-x0);
        Delta_E   =  2 * (y1 - y0);                 //Valor para avanzar un pixel a la derecha
        while (x < x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d >= 0){
            x++;
            d = d + Delta_E;
          }
          else{
            x++; y--;
            d = d + Delta_SE;
          }
          plot(x,y);
        }
      }
    }
  }
  else{
    if (y0<=y1){
      Delta_NO  = -2 * ((y1 - y0) + (x1 - x0)); //Valor para avanzar un pixel hacia arriba y uno a la izquierda
      if (yAbs>=xAbs){ //octante 3
        d = -1*(y1-y0) - 2*(x1-x0);
        Delta_N   = -2 * (x1 - x0);             //Valor para avanzar un pixel hacia arriba
        while (y < y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d <= 0){
            y++;
            d = d + Delta_N;
          }
          else{
            x--; y++;
            d = d + Delta_NO;
          }
          plot(x,y);
        }
      }    
      else{ //octante 4
        d = -2* (y1 - y0) - (x1 - x0);
        Delta_O   = -2 * (y1 - y0);                 //Valor para avanzar un pixel a la izquierda
        while (x > x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d > 0){
            x--;
            d = d + Delta_O;
          }
          else{
            x--; y++;
            d = d + Delta_NO;
          }
          plot(x,y);
        }
      }
    }
    else{
      Delta_SO  = -2 * ((y1 - y0) - (x1 - x0)); //Valor para avanzar un pixel hacia abajo y uno a la izquierda
      if (xAbs>=yAbs){ //octante 5
        d = -2* (y1 - y0) + (x1 - x0);
        Delta_O   = -2 * (y1 - y0);                 //Valor para avanzar un pixel a la izquierda
        while (x > x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d <= 0){
            x--;
            d = d + Delta_O;
          }
          else{
            x--; y--;
            d = d + Delta_SO;
          }
          plot(x,y);
        }
      }
      else{ //octante 6
        d = -1*(y1 - y0) + 2 * (x1 - x0);
        Delta_S   =  2 * (x1 - x0);               //Valor para avanzar un pixel hacia abajo
        while (y > y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d >= 0){
            y--;
            d = d + Delta_S;
          }
          else{
            x--; y--;
            d = d + Delta_SO;
          }
          plot(x,y);
        }
      }
    }
  }
};