#include <GLUT/glut.h>
#include <OPENGL/gl.h>
#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

float radius = 15.0;
float phi = 0.0f;
float theta = 0.0f;

bool isDragging = false;
int prevX = 0;
int prevY = 0;

float eyeX = 0.0f;
float eyeY = 0.0f;
float eyeZ = 5.0f;

void init(void)
{
  glEnable(GL_DEPTH_TEST);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(eyeX, eyeY, eyeZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

  glutSolidTeapot(3);

  {
    glPushMatrix();

    glRotatef(phi, 1.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0f, 0.8f);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-0.8f, 0.0f);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.8f, 0.0f);
    glEnd();

    glPopMatrix();
  }

  {
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-5.0f, 0.f, 0.0f);
    glVertex3f(5.0f, 0.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.0f, 0.0f, 5.0f);
    glVertex3f(0.0f, 0.0f, -5.0f);
    glEnd();
  }

  glutSwapBuffers();
}

void reshape(GLint width, GLint height)
{
  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(54.0f, (float)width / height, 0.1f, 100.0f);

  glMatrixMode(GL_MODELVIEW);
}

void Keyboard(unsigned char key, int x, int y)
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

void MouseButton(int button, int state, int x, int y)
{
  if (state == GLUT_DOWN)
  {
    isDragging = true;

    prevX = x;
    prevY = y;
  }
  else
  {
    isDragging = false;
  }
}

void MouseMotion(int x, int y)
{
  if (isDragging)
  {
    theta += (x - prevX) * 1.f;
    phi += (y - prevY) * 1.f;
    if (phi < 0.0f)
    {
      phi = 0.1f;
    }
    if (phi > 180.0f)
    {
      phi = 179.0f;
    }

    float _theta = theta * (float)M_PI / 180.0f;
    float _phi = phi * (float)M_PI / 180.0f;

    eyeX = radius * std::sin(_phi) * std::sin(_theta);
    eyeY = radius * std::cos(_phi);
    eyeZ = radius * std::sin(_phi) * std::cos(_theta);

    prevX = x;
    prevY = y;
  }

  glutPostRedisplay();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(800, 600);
  glutInitWindowPosition(100, 100);

  glutCreateWindow("OpenGL");

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(Keyboard);
  glutMouseFunc(MouseButton);
  glutMotionFunc(MouseMotion);

  init();

  glutMainLoop();

  return 0;
}
