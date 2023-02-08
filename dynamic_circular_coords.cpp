// --- os conditional includes ---
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#include <gl/glut.h> // includes glu.h and gl.h
#else
#include <GL/glut.h>  // includes glu.h and gl.h
#endif
// --- standard includes ---
#include <iostream>
#include <stdlib.h>
#include <math.h>

// --- constants ---
#define WINDOW_TITLE "Dynamic Circular Coordinates - Workspace - OpenGL (CPP)"
#define WINDOW_SIZE  640
#define TAU          2.0f*M_PI
#define PNT_A        [0.3, 0.6, 0.5, 0.8]
#define VERTICES     1000
#define SCALE        0.85f
#define GRAY         0.7f

// --- callback functions ---
void display() {
   glClearColor(GRAY, GRAY, GRAY, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);

   glBegin(GL_LINE_LOOP);
      glColor3f(0.0f, 0.0f, 1.0f); 

      for (int i = 0; i < VERTICES; i++) {

          GLfloat angle = i * (0.36);
          printf("%f\n", angle);

          glColor3f(0.0f, 0.0f, 1.0f);
          GLfloat x = SCALE * sin(i * TAU / VERTICES);
          GLfloat y = SCALE * cos(i * TAU / VERTICES);
          glVertex2f(x, y);
      }
   glEnd();
   glFlush();
}

void keyboard(unsigned char, int, int) {
    printf("Exiting program\n");
    exit(0);
}

// --- main routine ---
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);

   // get screen sizes
   int screen_width  = glutGet(GLUT_SCREEN_WIDTH);
   int screen_height = glutGet(GLUT_SCREEN_HEIGHT);

   // calculate center location coordinate
   int center_loc_x = (screen_width - WINDOW_SIZE) / 2;
   int center_loc_y = (screen_height - WINDOW_SIZE) / 2;

   glutInitWindowPosition(center_loc_x, center_loc_y);

   glutCreateWindow(WINDOW_TITLE);
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
