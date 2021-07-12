#include <GLUT/glut.h>
#include <OPENGL/gl.h>
#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

float angle = 0.0f;

void init(void)
{
  glEnable(GL_DEPTH_TEST);
}

void displayCallback(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(0.0f, 5.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

  angle++;
  glRotatef(angle, 0.0f, 1.0f, 0.0f);

  glutSolidTeapot(3);

  glutSwapBuffers();
}

void reshapeCallback(GLint width, GLint height)
{
  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(54.0f, (float)width / height, 0.1f, 100.0f);

  glMatrixMode(GL_MODELVIEW);
}

void keyboardCallback(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27:
    std::exit(0);
    break;
  case 'l':
    // SelectFromMenu(MENU_LIGHTING);
    break;
  case 'p':
    // SelectFromMenu(MENU_POLYMODE);
    break;
  case 't':
    // SelectFromMenu(MENU_TEXTURING);
    break;
  }
}

void mouseCallback(int button, int state, int x, int y)
{
  if (state == GLUT_DOWN)
  {
  }

  if (state == GLUT_UP)
  {
  }
}

void motionCallback(int x, int y)
{
}

void idleCallback()
{
  glutPostRedisplay();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 100);

  glutCreateWindow("OpenGL");

  glutDisplayFunc(displayCallback);
  glutReshapeFunc(reshapeCallback);
  glutKeyboardFunc(keyboardCallback);
  glutMouseFunc(mouseCallback);
  glutMotionFunc(motionCallback);
  glutIdleFunc(idleCallback);

  init();

  glutMainLoop();

  return 0;
}
