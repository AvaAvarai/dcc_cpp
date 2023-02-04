// windows specific headers
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#include <gl/glut.h> // includes glu.h and gl.h
// linux specific headers
#else
#include <GL/glut.h>  // includes glu.h and gl.h
#endif

// standard library headers
#include <iostream>
#include <stdlib.h>
#include <math.h> 

#define WINDOW_TITLE "Dynamic Circular Coordinates - Workspace - OpenGL (CPP)"

// 1:1 window resolution
#define WINDOW_SIZE 640

// math constant
#define TAU 2.0f*M_PI
// 4-d data point
#define PNT_A [0.3, 0.6, 0.5, 0.8]
// vertex count
#define VERTICES 1000

// window repaint callback
void display() {
   glClearColor(0.7f, 0.7f, 0.7f, 0.0f);
   glClear(GL_COLOR_BUFFER_BIT);
   GLfloat color = 0.0f;
   glBegin(GL_LINE_LOOP);
      glColor3f(0.0f, 0.0f, color);
      for (int i = 0; i < VERTICES; i++) {
          glColor3f(0.0f, 0.0f, color+=0.001f);
          GLfloat x = 0.75 * sin(i * TAU / VERTICES);
          GLfloat y = 0.75 * cos(i * TAU / VERTICES);
          glVertex2f(x, y);
          printf("(x: %f, y: %f)\n", x, y);
      }
   glEnd();

   glFlush();
}

// keyboard callback
void keyboard(unsigned char, int, int) {
    printf("Exiting program\n");
    exit(0);
}

// main routine
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);

   // get screen sizes
   int screen_width = glutGet(GLUT_SCREEN_WIDTH);
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
