#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <stdlib.h>
#include "SOIL.h"

using namespace std;

class Point {
    public:
        GLfloat x,y,z;
        Point(GLfloat a, GLfloat b, GLfloat c) {
            x = a; y = b; z = c;
        }
        Point() {
            x = 0; y = 0; z = 0;
        }
};

class Building {
    public:
        Point * points;
        int indexTexture;
        int pointsLength;
        Building(int index, initializer_list<Point> pointsIn) {
            indexTexture = index;
            points = new Point[pointsIn.size()];
            pointsLength = pointsIn.size();
            copy(pointsIn.begin(),pointsIn.end(),points);
        }
};

/* GLUT callback Handlers */
Building labtekV(1,{
                 {5.14,14.82,0},
                 {7.58,14.82,0},
                 {7.58,14.13,0},
                 {5.14,14.13,0}
                 });
Building labtekVI(1,{
                  {5.00,13.84,0},
                  {7.58,13.84,0},
                  {7.58,13.10,0},
                  {5.00,13.10,0}
                  });
Building labtekVII(1,{
                   {7.97,13.84,0},
                   {10.43,13.84,0},
                   {10.43,13.10,0},
                   {7.97,13.10,0}
                   });
Building labtekVIII(1,{
                    {7.97,14.82,0},
                    {10.43,14.82,0},
                    {10.43,14.12,0},
                    {7.97,14.12,0}
                    });
Building labPower(1,{
                  {3.58,15.15,0},
                  {5.04,15.15,0},
                  {5.04,14.57,0},
                  {3.58,14.57,0}
                  });
Building ccBarat(1,{
                 {6.21,16.07,0},
                 {6.21,17.10,0},
                 {6.55,17.10,0},
                 {6.55,16.07,0},
                 {7.51,16.07,0},
                 {7.51,15.55,0},
                 {6.10,15.55,0},
                 {6.10,16.07,0}
                 });
Building ccTimur(1,{
                 {8.05,16.06,0},
                 {9.40,16.06,0},
                 {9.40,15.54,0},
                 {8.05,15.54,0}
                 });

Building amisca(1,{
                {11.01,11.72,0},
                {12.70,11.87,0},
                {12.76,11.33,0},
                {11.06,11.17,0}
                });

Building fttm(1,{
                {10.94,12.41,0},
                {12.87,12.58,0},
                {12.93,12.14,0},
                {10.97,11.97,0}
                });

Building gkutimur(1,{
                  {12.20,14.52,0},
                  {12.81,14.52,0},
                  {12.81,14.09,0},
                  {12.19,14.52,0}
                  });

Building doping(1,{
                  {12.14,15.01,0},
                  {12.53,15.01,0},
                  {12.53,14.59,0},
                  {12.14,14.59,0}
                  });

Building hms(1,{
                  {3.62,17.52,0},
                  {5.83,17.52,0},
                  {5.83,17.20,0},
                  {3.62,17.20,0}
                  });
Building hmsselatan(1,{
                  {3.91,18.03,0},
                  {5.83,18.03,0},
                  {5.83,17.70,0},
                  {3.91,17.70,0}
                  });

Building hmsutara1(1,{
                  {3.61,17.13,0},
                  {4.48,17.13,0},
                  {4.48,16.79,0},
                  {3.61,16.79,0}
                  });

Building hmsutara2(1,{
                  {4.58,16.9,0},
                  {5.79,16.9,0},
                  {5.79,16.64,0},
                  {4.58,16.64,0}
                  });

Building kmpn(1,{
                  {2.51,13.11,0},
                  {4.17,13.11,0},
                  {4.17,12.57,0},
                  {3.75,12.57,0},
                  {3.75,12.72,0},
                  {3.39,12.72,0},
                  {3.39,12.10,0},
                  {2.51,12.10,0}
                  });

Building labmetalurgi(1,{
                  {2.59,12.03,0},
                  {4.23,12.03,0},
                  {4.23,11.12,0},
                  {2.59,11.12,0}
                  });

Building cadl(1,{
                {5.38,9.88,0},
                {6.23,9.88,0},
                {6.32,9.79,0},
                {6.32,8.85,0},
                {6.23,8.76,0},
                {5.38,8.76,0},
                {6.30,8.84,0},
                {5.29,9.79,0}
                });
/*Building mekTan(1,{
                {9.45,12.06,0},
                {9.45,12.54,0},
                {,12.54,0},
                {,,0},
                {,,0},
                {,,0}
                });*/
static int dX = 0;
static int dY = 180;
static int dZ = 180;

static float lX = 0.0f;
static float lY = 0.0f;
static float lZ = -1.0f;

static int z = -50;
static int y = 10;
static int x = -10;
GLuint texture[6];



void initGL() {
    texture[0] = SOIL_load_OGL_texture (
        "C:\\Users\\Kristianto\\Desktop\\Tugads9Grafika\\Tugas9Grafika\\src\\img\\top.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[5]);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);

    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.5);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
}

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
}

static void printBuilding(Building building) {
    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glTranslated(x, y, z);
    glRotated(dX, 1, 0, 0);
    glRotated(dY, 0, 1, 0);
    glRotated(dZ, 0, 0, 1);

    GLfloat light_position[] = { lX, lY, lZ, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    printBuilding(labtekV);
    printBuilding(labtekVI);
    printBuilding(labtekVII);
    printBuilding(labtekVIII);
    printBuilding(labPower);
    printBuilding(ccBarat);
    printBuilding(ccTimur);
    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
            exit(0);
            break;

        case 'w':
            dX -= 10;
            break;

        case 's':
            dX += 10;
            break;

        case 'a':
            dY += 10;
            break;

        case 'd':
            dY -= 10;
            break;

        case 'q':
            dZ -= 10;
            break;

        case 'e':
            dZ += 10;
            break;

        case '-':
            if (z >= -40) {
                z--;
            }
            break;

        case '=':
            if (z < -10) {
                z++;
            }
            break;

        case 'i':
            lX += 5;
            break;

        case 'k':
            lX -= 5;
            break;

        case 'j':
            lY += 5;
            break;

        case 'l':
            lY -= 5;
            break;

        case 'o':
            lZ += 5;
            break;

        case 'u':
            lZ -= 5;
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Xiaomi Mi4i");

    //initGL();

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glutMainLoop();

    return EXIT_SUCCESS;
}
