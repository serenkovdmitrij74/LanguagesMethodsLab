https://drive.google.com/file/d/1BPu9EcBI0Rjb3IuSb_aDxyzOVDqiuw0G/view?usp=drivesdk

$(ProjectDir)

opengl32.lib
glu32.lib
glut32.lib

#include <windows.h>
#include <GL/glut.h>
#include <cmath>


const float PI = 3.1415926f;

void drawStar(float cx, float cy, float rOut, float rIn, bool fill) {
    glBegin(fill ? GL_TRIANGLE_FAN : GL_LINE_LOOP);
    if (fill) glVertex2f(cx, cy);
    for (int i = 0; i <= 10; i++) {
        float angle = i * PI / 5.0f - PI / 2.0f;
        float r = (i % 2 == 0) ? rIn : rOut;
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }
    glEnd();
}

void drawPentagon(float cx, float cy, float r, bool fill) {
    glBegin(fill ? GL_POLYGON : GL_LINE_LOOP);
    for (int i = 0; i < 5; i++) {
        float angle = PI + (i * 2.0f * PI / 5.0f - PI / 2.0f);
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }
    glEnd();
}

void drawHexagon(float cx, float cy, float w, float h) {
    h *= 0.5;
    glBegin(GL_LINE_LOOP);
    glVertex2f(cx - w, cy +h);
    glVertex2f(cx, cy + h*2);
    glVertex2f(cx + w, cy + h);
    glVertex2f(cx + w, cy - h);
    glVertex2f(cx, cy - h*2);
    glVertex2f(cx - w, cy - h);
    glEnd();
}

// 4. Рисование 4-конечной звезды/вспышки (для Фигуры 4)
void drawSparkle(float cx, float cy, float rOut, float rIn) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 8; i++) {
        float angle = i * PI / 4.0f;
        float r = (i % 2 == 0) ? rOut : rIn;
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }
    glEnd();
}

void drawHeart(float cx, float cy, float scale) {
    glBegin(GL_LINE_LOOP);
    for (float t = 0; t < 2 * PI; t += 0.05f) {
        float x = 16.0f * pow(sin(t), 3);
        float y = 13.0f * cos(t) - 5.0f * cos(2 * t) - 2.0f * cos(3 * t) - cos(4 * t);
        glVertex2f(cx + x * scale, cy + y * scale);
    }
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0f);

    //звезда
    glColor3ub(255, 161, 97);
    drawStar(-20.0f, 8.0f, 6.0f, 2.3f, true);
    glColor3ub(139, 0, 0);
    drawStar(-20.0f, 8.0f, 6.0f, 2.3f, false);
    drawStar(-20.0f, 8.0f, 3.5f, 1.3f, false);

    //пятиугольник
    glColor3ub(135, 206, 235);
    drawPentagon(0.0f, 8.0f, 5.0f, true);
    glColor3ub(218, 165, 32);
    drawPentagon(0.0f, 8.0f, 5.0f, false);
    glColor3ub(255, 69, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 10.0f);
    glVertex2f(1.5f, 8.0f);
    glVertex2f(0.0f, 6.0f);
    glVertex2f(-1.5f, 8.0f);
    glEnd();

    //шестиугольник
    glColor3ub(128, 0, 0);
    drawHexagon(20.0f, 8.0f, 7.0f, 3.5f);
    glColor3ub(154, 205, 50);
    drawHexagon(20.0f, 8.0f, 5.5f, 2.7f);
    glColor3ub(255, 165, 0);
    drawHexagon(20.0f, 8.0f, 4.0f, 2.0f);

    //звезда
    glColor3ub(128, 0, 128);
    drawSparkle(-20.0f, -8.0f, 6.0f, 1.2f);
    glColor3ub(0, 191, 255);
    drawSparkle(-20.0f, -8.0f, 4.5f, 0.9f);
    glColor3ub(0, 128, 0);
    drawSparkle(-20.0f, -8.0f, 2.5f, 0.5f);

    //сердцe
    glColor3ub(0, 206, 209);
    drawHeart(0.0f, -7.0f, 0.35f);
    glColor3ub(30, 144, 255);
    drawHeart(0.0f, -7.0f, 0.25f);
    glColor3ub(75, 0, 130);
    drawHeart(0.0f, -7.0f, 0.12f);

    //пятиконечн. звезда
    glColor3ub(255, 105, 180);
    drawStar(20.0f, -8.0f, 6.0f, 2.3f, false);
    glColor3ub(255, 140, 0);
    drawStar(20.0f, -8.0f, 4.5f, 1.7f, false);
    glColor3ub(0, 191, 255);
    drawStar(20.0f, -8.0f, 3.0f, 1.1f, false);

    glFlush();
}


void reshape(int width, int height) {
    if (height == 0) height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = (float)width / (float)height;
    if (width >= height) {
        gluOrtho2D(-20.0 * aspect, 20.0 * aspect, -20.0, 20.0);
    }
    else {
        gluOrtho2D(-32.0, 32.0, -32.0 / aspect, 32.0 / aspect);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(750, 450);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("Лабораторная работа №1 - Фигуры");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
