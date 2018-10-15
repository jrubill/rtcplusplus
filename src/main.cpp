#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Engine.h"
#include "Color.h"

const int WIDTH = 500;
const int HEIGHT = 500;


Color white(255,255,255);

void write(int x, int y, const Color &c) {
    glColor3f(c.getR(),c.getG(),c.getB());
    glBegin(GL_POINTS);
    glVertex3i(x,y,0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    std::vector<Color> buffer = Engine::getInstance()->getBuffer(); 

    // write pixels to display
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            write(i,j, buffer[WIDTH * i + j]);

    // swap out the frame buffer
    glutSwapBuffers();
}

void init() {
    glClearColor(0,0,0,0);
    glShadeModel(GL_SMOOTH);
    glOrtho(0,500,0,500,-1,1);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(WIDTH,HEIGHT); 
    glutCreateWindow("Title");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    init();
    glutMainLoop();
}
