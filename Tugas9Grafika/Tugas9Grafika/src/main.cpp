#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <stdlib.h>
#include "SOIL.h"
#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"
#include <string>

using namespace std;

static int dX = 0;
static int dY = 180;
static int dZ = 180;

static float lX = 0.0f;
static float lY = 0.0f;
static float lZ = -1.0f;
static float x = 0.0f;
static float y = 0.0f;
static float z = -20.0f;

static int prevMouseX;
static int prevMouseY;
GLuint texture[6];
string PATH = "C:\\Users\\user-ari\\Desktop\\grafika_itb\\Tugas9Grafika\\Tugas9Grafika\\src\\";

/* GLUT callback Handlers */

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
Building mekTan(1,{
                {9.45,12.06,0},
                {9.45,12.54,0},
                {10.41,12.54,0},
                {10.41,10.50,0},
                {9.40,10.50,0},
                {9.40,12.06,0}
                });

Building hmtl(1,{
                {10.02,15.55,0},
                {10.02,15.47,0},
                {9.75,15.47,0},
                {9.75,16.03,0},
                {11.47,16.03,0},
                {11.47,15.96,0},
                {12.06,15.96,0},
                {12.06,15.55,0}
                });

Building comlabs(1,{
                {9.17,10.60,0},
                {9.25,10.60,0},
                {9.25,10.30,0},
                {8.32,10.30,0},
                {8.12,10.51,0},
                {8.12,10.90,0},
                {8.37,11.15,0},
                {9.16,11.15,0},
                {9.28,11.07,0},
                {9.28,10.69,0}
                });

Building pln(1,{
                {9.27,11.58,0},
                {9.17,11.49,0},
                {8.37,11.49,0},
                {8.07,11.77,0},
                {8.07,11.93,0},
                {8.18,12.02,0},
                {9.18,12.02,0},
                {9.28,11.95,0}
                });

Building tvst(1,{
                {7.10,11.40,0},
                {6.88,11.40,0},
                {6.51,11.77,0},
                {6.51,12.01,0},
                {6.88,12.36,0},
                {7.10,12.36,0},
                {7.47,12.01,0},
                {7.47,11.77,0}
                });

Building oktagon(1,{
                {7.08,10.27,0},
                {6.90,10.27,0},
                {6.52,10.65,0},
                {6.52,10.83,0},
                {6.90,11.22,0},
                {7.08,11.22,0},
                {7.47,10.83,0},
                {7.47,10.65,0}
                });

Building gkuBarat(1,{
                {4.06,13.38,0},
                {3.68,13.38,0},
                {3.41,13.64,0},
                {3.41,14.03,0},
                {3.66,14.31,0},
                {4.08,14.31,0},
                {4.33,14.03,0},
                {4.33,13.64,0}
                });

Building pau(1,{
                {6.52,8.64,0},
                {6.52,9.80,0},
                {7.36,9.80,0},
                {7.36,8.48,0},
                {7.26,8.48,0},
                {7.26,8.38,0},
                {7.18,8.38,0},
                {7.18,8.30,0},
                {6.37,8.30,0},
                {6.37,8.64,0}
                });

Building altim(1,{
                {9.72,18.20,0},
                {9.72,18.06,0},
                {8.87,18.06,0},
                {8.87,18.20,0},
                {8.69,18.20,0},
                {8.69,18.93,0},
                {9.80,18.93,0},
                {9.80,18.72,0},
                {10.26,18.72,0},
                {10.26,18.20,0}
                });

Building depanaltim(1,{
                {8.02,18.35,0},
                {8.02,18.57,0},
                {8.12,18.69,0},
                {8.23,18.91,0},
                {8.31,18.91,0},
                {8.31,18.75,0},
                {8.55,18.75,0},
                {8.55,18.64,0},
                {8.69,18.35,0}
                });

Building albar(1,{
                {5.81,18.35,0},
                {5.48,18.35,0},
                {5.48,18.62,0},
                {5.72,18.62,0},
                {5.72,18.91,0},
                {6.83,18.92,0},
                {6.83,18.61,0},
                {7.50,18.61,0},
                {7.50,18.35,0},
                {6.78,18.35,0},
                {6.78,18.26,0},
                {6.59,18.26,0},
                {6.59,18.11,0},
                {5.81,18.11,0}
                });

Building labbirbawah(1,{
                {5.11,12.12,0},
                {5.11,12.42,0},
                {5.36,12.42,0},
                {5.36,12.12,0},
                {6.31,12.12,0},
                {6.31,11.49,0},
                {5.81,11.49,0},
                {5.81,11.14,0},
                {4.85,11.14,0},
                {4.85,11.49,0},
                {4.54,11.49,0},
                {4.54,12.12,0}
                });

Building labbiratas(1,{
                {5.36,10.52,0},
                {4.54,10.52,0},
                {4.54,11.14,0},
                {6.30,11.14,0},
                {6.30,10.52,0},
                {5.91,10.52,0},
                {5.91,10.21,0},
                {4.97,10.21,0}
                });

Building bengkok1(1,{
                {11.91,13.97,0},
                {12.71,13.97,0},
                {12.71,13.55,0},
                {11.46,13.55,0},
                {11.46,14.08,0},
                {11.91,14.08,0}
                });

Building bengkok2(1,{
                {12.36,13.36,0},
                {12.60,13.36,0},
                {12.60,12.95,0},
                {10.99,12.95,0},
                {10.99,13.48,0},
                {12.36,13.48,0}
                });

Building atasnyabengkok2(1,{
                {10.93,12.49,0},
                {10.88,12.88,0},
                {12.85,12.88,0},
                {12.85,12.69,0}
                });
void initGL() {
    texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\top.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\bottom.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[1]);

    texture[2] = SOIL_load_OGL_texture (
        (PATH+"img\\front.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[2]);

    texture[3] = SOIL_load_OGL_texture (
        (PATH+"img\\back.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[3]);

    texture[4] = SOIL_load_OGL_texture (
        (PATH+"img\\left.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[4]);

    texture[5] = SOIL_load_OGL_texture (
        (PATH+"img\\right.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
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

static void printBuilding(Building building, int h) {
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayLabtekV(Building building,int h){
    GLuint this_texture[6];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\labtek56\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\labtek56\\utara1.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 1 ||i == 3){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayLabtekVI(Building building,int h){
    GLuint this_texture[6];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\labtek56\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\labtek56\\utara1.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 1 ||i == 3){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayLabtekVII(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\labtekvii\\samping kiri.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\labtekvii\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 1 ||i == 3){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayLabtekVIII(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\labtekvii\\samping kiri.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\labtekvii\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 1 ||i == 3){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayComlabs(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\comlabs\\comlabs.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\comlabs\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 1){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayMektan(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\mektan\\Mektan_Selatan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\mektan\\timur tengah.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0 || i == 2){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayCcbarat(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\ccbarat\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\ccbarat\\selatan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\ccbarat\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0 ){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else if (i == 2) {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        }
        else {
            glBindTexture(GL_TEXTURE_2D, this_texture[2]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayCctimur(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\ccbarat\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\ccbarat\\selatan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\ccbarat\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0 ){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else if (i == 2) {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        }
        else {
            glBindTexture(GL_TEXTURE_2D, this_texture[2]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayHmtl(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\depanlabtek viii\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\depanlabtek viii\\barat.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0 || i == 2){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        }
        else {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayPln(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\pln\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;

    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, this_texture[0]);

        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}


///////////////////////////////////Dyas///////////////////////

void displayTvst(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\tvst\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\tvst\\selatan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 3){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayOktagon(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\oktagon\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\oktagon\\samping.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 3){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayGkuBarat(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\gkubarat\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\gkubarat\\samping1.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    this_texture[2] = SOIL_load_OGL_texture (
        (PATH+"img\\gkubarat\\samping2.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 3){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[2]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayPau(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\pau\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\pau\\barat.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 3){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayAltim(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\baratdaya.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    this_texture[2] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\selatankanan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[3] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\baratdaya2.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, this_texture[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[3]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayAlbar(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\utara.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\aulabarat\\baratdaya2.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    this_texture[2] = SOIL_load_OGL_texture (
        (PATH+"img\\aulabarat\\baratdaya1.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[3] = SOIL_load_OGL_texture (
        (PATH+"img\\aulabarat\\baratdaya2.png").c_str(), //sama kayak texture[1], cuma males ngedit if-nya
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, this_texture[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[3]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayBengkok(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\sebelahbengkok.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, this_texture[0]);

        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayHMSSelatan(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\sebelahbengkok.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, this_texture[0]);

        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayDoping(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\doping\\selatan.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\doping\\barat.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    this_texture[2] = SOIL_load_OGL_texture (
        (PATH+"img\\doping\\selatan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[3] = SOIL_load_OGL_texture (
        (PATH+"img\\doping\\barat.png").c_str(), //sama kayak texture[1], cuma males ngedit if-nya
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, this_texture[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[3]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayGkuTimur(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\gkutimur\\selatan.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\gkutimur\\barat.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    this_texture[2] = SOIL_load_OGL_texture (
        (PATH+"img\\gkutimur\\sampingbelakang.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[3] = SOIL_load_OGL_texture (
        (PATH+"img\\gkutimur\\barat.png").c_str(), //sama kayak texture[1], cuma males ngedit if-nya
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, this_texture[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[3]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayKimia(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\kimia.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, this_texture[0]);

        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayHms(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\sebelahbengkok.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, this_texture[0]);

        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayFttm(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\geomatika.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, this_texture[0]);

        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

//////////////////////////////// ade ////////////////////////////////////////////

void displayLabbir(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\biru\\utara.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, this_texture[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[3]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayDepanaltim(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\altim\\selatankanan.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\altim\\selatankanan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    this_texture[2] = SOIL_load_OGL_texture (
        (PATH+"img\\doping\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[3] = SOIL_load_OGL_texture (
        (PATH+"img\\doping\\utara.png").c_str(), //sama kayak texture[1], cuma males ngedit if-nya
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, this_texture[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[3]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayCadl(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\cadl\\selatan.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\cadl\\selatan1.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    this_texture[2] = SOIL_load_OGL_texture (
        (PATH+"img\\cadl\\selatan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[3] = SOIL_load_OGL_texture (
        (PATH+"img\\cadl\\selatan1.png").c_str(), //sama kayak texture[1], cuma males ngedit if-nya
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, this_texture[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[3]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayLabmetalurgi(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\mesin.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, this_texture[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[3]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayHmsutara1(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\utara.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\selatan kiri.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    this_texture[2] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[3] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\selatan kiri.png").c_str(), //sama kayak texture[1], cuma males ngedit if-nya
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, this_texture[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[3]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

void displayHmsutara2(Building building,int h){
    GLuint this_texture[4];
    this_texture[0] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\utara.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[1] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\selatan kiri.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    this_texture[2] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
     cout << SOIL_last_result() << endl;
    this_texture[3] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\selatan kiri.png").c_str(), //sama kayak texture[1], cuma males ngedit if-nya
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    cout << SOIL_last_result() << endl;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, this_texture[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, this_texture[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, this_texture[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, this_texture[3]);
        }
        glBegin(GL_POLYGON);
            glTexCoord3f(0.0, 1.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
            glTexCoord3f(1.0, 1.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z);
            glTexCoord3f(1.0, 0.0, 0.0);
            glVertex3f(building.points[(i+1)%building.pointsLength].x, building.points[(i+1)%building.pointsLength].y, building.points[(i+1)%building.pointsLength].z+h);
            glTexCoord3f(0.0, 0.0, 0.0);
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z+h);
        }
    glEnd();
}

/////////////////////////////////////////////////////////////////


static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glTranslated(x, y, z);
    glRotated(dX, 1, 0, 0);
    glRotated(dY+180, 0, 1, 0);
    glRotated(dZ, 0, 0, 1);

    GLfloat light_position[] = { lX, lY, lZ, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    //printBuilding(labtekV,2);
    displayLabtekV(labtekV,2);
    displayLabtekVI(labtekVI,2);
    displayLabtekVII(labtekVII,2);
    displayLabtekVIII(labtekVIII,2);
    displayComlabs(comlabs,3);
    displayMektan(mekTan,4);
    displayCcbarat(ccBarat,5);
    displayCctimur(ccTimur,6);
    displayHmtl(hmtl,2);
    displayPln(pln,2);

    //Dyas
    /*displayTvst(tvst,3);
    displayOktagon(oktagon,3);
    displayGkuBarat(gkuBarat,4);
    displayPau(pau,3);
    displayAltim(altim,2);
    displayAlbar(albar,2);
    displayBengkok(atasnyabengkok2,3);
    displayBengkok(bengkok2,2);

    //ade
    displayBengkok(bengkok1,2);
    displayLabbir(labbiratas,3);
    displayLabbir(labbirbawah,3);
    displayDepanaltim(depanaltim,2);
    displayCadl(cadl,2);
    displayLabmetalurgi(labmetalurgi,2);
    displayHmsutara1(hmsutara1,2);
    displayHmsutara2(hmsutara2,2);
    */

    //Ade
    /*printBuilding(bengkok1,2);
>>>>>>> 1843c4454254b261d360ab86b3b44c27b9c398d7
    printBuilding(labbiratas,3);
    printBuilding(labbirbawah,3);
    printBuilding(depanaltim,2);
    printBuilding(cadl,2);
    printBuilding(labmetalurgi,2);
    printBuilding(hmsutara2,2);
<<<<<<< HEAD
    printBuilding(hmsutara1,2);
    printBuilding(hmsselatan,2);
    printBuilding(hmsutara1,2);*/

    //Ari
    displayHMSSelatan(hmsselatan,2);
    displayHms(hms,2);
    displayGkuTimur(gkutimur,2);
    displayFttm(fttm,2);
    displayKimia(amisca,2);
    displayDoping(doping,2);
    glutSwapBuffers();


}

static void mouse(int button, int state, int mouseX, int mouseY)
{
    if ((button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON))
    {
         prevMouseX = mouseX;
         prevMouseY = mouseY;
    }
}

static void mouseMov(int mouseX, int mouseY)
{
    x += (float)(mouseX - prevMouseX) / 1500.0f;
    y += (float)(mouseY - prevMouseY) * -1 / 1500.0f;
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
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Grafika");

    initGL();

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMov);
    glutIdleFunc(idle);

    glutMainLoop();

    return EXIT_SUCCESS;
}
