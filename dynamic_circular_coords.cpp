// windows specific headers
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__) // windows test
#include <windows.h>
#include <gl/glut.h> // glut, includes glu.h and gl.h
#else // other than windows
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#endif

// standard library headers
#include <iostream> // I/O
#include <math.h>   // planned for PI, cos, sin
#include <tuple>    // to pack coordinates

#define WINDOW_SIZE 640 // 1:1 resolution
#define WINDOW_TITLE "Dynamic Circular Coordinates - Workspace - OpenGL (CPP)"

#define TAU 2.0f*M_PI // "the ratio of the circumference to the radius of a circle"

// Window repaint callback
void display() {
   glClearColor(0.7f, 0.7f, 0.7f, 0.0f);
   glClear(GL_COLOR_BUFFER_BIT);

   glBegin(GL_LINE_LOOP);
      glColor3f(0.0f, 0.0f, 1.0f);
      for (int i = 0; i < 1000; i++) {
          glVertex2f(0.75 * sin(-i * TAU / 1000), 0.75 * cos(-i * TAU / 1000));
      }
   glEnd();

   glFlush();
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
   glutMainLoop();
   return 0;
}
