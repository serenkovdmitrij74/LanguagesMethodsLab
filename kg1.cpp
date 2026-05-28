https://drive.google.com/file/d/1BPu9EcBI0Rjb3IuSb_aDxyzOVDqiuw0G/view?usp=drivesdk

$(ProjectDir)

opengl32.lib
glu32.lib
glut32.lib

#include <windows.h>
#include <GL/glut.h>


// Пункт 5
void reshape(int width, int height) {
    if (height == 0) height = 1;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float a = (float)width / (float)height;

    if (width >= height) {
        gluOrtho2D(-1.0 * a, 1.0 * a, -1.0, 1.0);
    }
    else {
        gluOrtho2D(-1.0, 1.0, -1.0 / a, 1.0 / a);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Пункт 4
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(5.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(0.8f, -1.7f);
    glEnd();


    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.4f, -0.2f);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.0f, 0.5f);
    glEnd();


    glLoadIdentity();
    glTranslatef(-0.5f, 0.5f, 0.0f);
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();

    glFlush();
}

//Пункт 2
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Лаб. №1");

    glutDisplayFunc(display);


    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    //Пункт 3
    glutDisplayFunc(display);       
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
