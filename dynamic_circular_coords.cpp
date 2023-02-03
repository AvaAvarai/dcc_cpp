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

// Window repaint callback
void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);

   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.5f, -0.5f);
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
      glVertex2f(-0.5f,  0.5f);
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
