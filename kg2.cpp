#include <windows.h>
#include <GL/glut.h>
#include <cmath>

const float PI = 3.1415926f;

float circleAngle = 0.0f;
float playerX = 0.0f;
float playerY = 0.0f;

const float LIMIT_MIN_X = -18.0f;
const float LIMIT_MAX_X = 18.0f;
const float LIMIT_MIN_Y = -18.0f;
const float LIMIT_MAX_Y = 18.0f;

const float OBJ_HALF_WIDTH = 1.5f;
const float OBJ_BOTTOM = -1.5f;
const float OBJ_TOP = 3.0f;


void drawCircle(float r, bool fill) {
    glBegin(fill ? GL_POLYGON : GL_LINE_LOOP);
    for (int i = 0; i < 360; i += 10) {
        float angle = i * PI / 180.0f;
        glVertex2f(cos(angle) * r, sin(angle) * r);
    }
    glEnd();
}

void drawCompositeObject() {
    glColor3ub(30, 144, 255);
    glBegin(GL_QUADS);
    glVertex2f(-OBJ_HALF_WIDTH, OBJ_BOTTOM);
    glVertex2f(OBJ_HALF_WIDTH, OBJ_BOTTOM);
    glVertex2f(OBJ_HALF_WIDTH, 1.5f);
    glVertex2f(-OBJ_HALF_WIDTH, 1.5f);
    glEnd();

    glColor3ub(255, 69, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-OBJ_HALF_WIDTH, 1.5f);
    glVertex2f(OBJ_HALF_WIDTH, 1.5f);
    glVertex2f(0.0f, OBJ_TOP);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.0f);

    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(-20.0f, -20.0f); glVertex2f(-18.0f, -20.0f);
    glVertex2f(-18.0f, 20.0f);  glVertex2f(-20.0f, 20.0f);

    glVertex2f(18.0f, -20.0f);  glVertex2f(20.0f, -20.0f);
    glVertex2f(20.0f, 20.0f);   glVertex2f(18.0f, 20.0f);

    glVertex2f(-18.0f, -20.0f); glVertex2f(18.0f, -20.0f);
    glVertex2f(18.0f, -18.0f);  glVertex2f(-18.0f, -18.0f);

    glVertex2f(-18.0f, 18.0f);  glVertex2f(18.0f, 18.0f);
    glVertex2f(18.0f, 20.0f);   glVertex2f(-18.0f, 20.0f);
    glEnd();

    glColor3ub(154, 205, 50);
    for (float i = -16.0f; i <= 14.0f; i += 4.0f) {
        glBegin(GL_TRIANGLES);
        glVertex2f(i, i);
        glVertex2f(i + 2.0f, i);
        glVertex2f(i + 1.0f, i + 2.0f);
        glEnd();
    }

    glPushMatrix();
    float trajX = 10.0f * cos(circleAngle);
    float trajY = 10.0f * sin(circleAngle);
    glTranslatef(trajX, trajY, 0.0f);
    glColor3ub(255, 215, 0);
    drawCircle(1.5f, true);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(playerX, playerY, 0.0f);
    drawCompositeObject();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void timer(int value) {
    circleAngle += 0.04f;
    if (circleAngle > 2 * PI) {
        circleAngle -= 2 * PI;
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}


void specialKeys(int key, int x, int y) {
    float speed = 0.5f; 

    switch (key) {
    case GLUT_KEY_UP:
        if (playerY + OBJ_TOP + speed <= LIMIT_MAX_Y) {
            playerY += speed;
        }
        break;
    case GLUT_KEY_DOWN:
        if (playerY + OBJ_BOTTOM - speed >= LIMIT_MIN_Y) {
            playerY -= speed;
        }
        break;
    case GLUT_KEY_LEFT:
        if (playerX - OBJ_HALF_WIDTH - speed >= LIMIT_MIN_X) {
            playerX -= speed;
        }
        break;
    case GLUT_KEY_RIGHT:
        if (playerX + OBJ_HALF_WIDTH + speed <= LIMIT_MAX_X) {
            playerX += speed;
        }
        break;
    }
    glutPostRedisplay();
}

void reshape(int width, int height) {
    int side = (width < height) ? width : height;
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-20.0, 20.0, -20.0, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("Лр 2");

    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
