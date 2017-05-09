#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <stdlib.h>
#include "SOIL.h"
#include <string>

using namespace std;

static int dX = 0;
static int dY = 0;
static int dZ = 180;

static float lX = 0.0f;
static float lY = 0.0f;
static float lZ = 5.0f;
static float x = 0.0f;
static float y = 0.0f;
static float z = -20.0f;

static bool mView = false;
static bool nView = false;

static int prevMouseX;
static int prevMouseY;
GLuint texture[6];
string PATH = "C:\\Users\\Kristianto\\Desktop\\grafika_itb\\Tugas9Grafika\\Tugas9Grafika\\src\\";

/* GLUT callback Handlers */
class Point {
    public:
        GLfloat x,y,z;
        Point(GLfloat a, GLfloat b, GLfloat c) {
            x = a - 8.0f; y = b - 12.34f; z = c;
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

Building perpus(1,{
                {9.18,8.95,0},
                {9.44,8.95,0},
                {9.44,9.26,0},
                {9.32,9.26,0},
                {9.32,9.54,0},
                {9.09,9.76,0},
                {8.84,9.76,0},
                {8.84,9.69,0},
                {8.56,9.69,0},
                {8.40,9.54,0},
                {8.40,9.17,0},
                {8.14,9.17,0},
                {8.14,8.88,0},
                {8.26,8.88,0},
                {8.26,8.56,0},
                {8.39,8.45,0},
                {9.02,8.45,0},
                {9.18,8.64,0}
                });

Building timurJauhAtas(1,{
                {11.60,9.59,0},
                {11.59,9.76,0},
                {12.70,9.86,0},
                {12.70,9.78,0},
                {13.43,9.87,0},
                {13.49,9.34,0},
                {10.98,9.14,0},
                {10.96,9.54,0}
                });

Building timurJauhBawah(1,{
                {11.70,10.67,0},
                {11.76,9.78,0},
                {12.28,9.83,0},
                {12.26,10.34,0},
                {12.46,10.37,0},
                {12.46,10.43,0},
                {13.08,10.68,0},
                {13.09,10.93,0},
                {12.44,10.88,0},
                {12.42,11.13,0},
                {11.02,11.00,0},
                {11.05,10.60,0}
                });

Building pln2(1,{
                {3.59,15.15,0},
                {3.59,14.59,0},
                {5.04,14.59,0},
                {5.04,15.15,0}
                });

Building fisika(1,{
                {3.72,16.28,0},
                {3.72,16.54,0},
                {5.83,16.54,0},
                {5.83,15.49,0},
                {4.63,15.49,0},
                {4.63,15.34,0},
                {3.82,15.34,0},
                {3.54,15.58,0},
                {3.54,16.28,0}
                });

Building arsiPlano(1,{
                {9.89,17.14,0},
                {9.69,17.14,0},
                {9.69,16.80,0},
                {9.76,16.80,0},
                {9.76,16.30,0},
                {12.17,16.30,0},
                {12.17,17.52,0},
                {10.86,17.52,0},
                {10.86,17.86,0},
                {9.89,17.86,0}
                });

Building sr(1,{
                {11.13,17.86,0},
                {11.13,17.67,0},
                {11.55,17.67,0},
                {11.55,18.47,0},
                {10.91,18.77,0},
                {10.91,18.42,0},
                {10.36,18.42,0},
                {10.36,18.04,0},
                {9.81,18.04,0},
                {9.81,17.86,0}
                });

Building mesin(1,{
                {3.40,12.58,0},
                {4.16,12.58,0},
                {4.16,13.12,0},
                {2.51,13.12,0},
                {2.51,12.10,0},
                {3.40,12.10,0}
                });

Building gedungBaratLaut(1,{
                {4.30,10.10,0},
                {5.06,10.10,0},
                {5.06,8.49,0},
                {2.74,8.49,0},
                {2.74,10.89,0},
                {4.30,10.89,0}
});
Building lantai(1,{
                {0.0,0.0,0},
                {16.0,0.0,0},
                {16.0,24.68,0},
                {0.0,24.68,0}
                });
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
                {6.30,8.84,0},
                {5.38,8.76,0},
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

static void resize(int width, int height){
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
}

GLuint textureLantai;
GLuint textureLabtekV[2];
GLuint textureLabtekVI[2];
GLuint textureLabtekVII[2];
GLuint textureLabtekVIII[2];
GLuint textureComlabs[2];
GLuint textureMektan[2];
GLuint textureCcBarat[3];
GLuint textureCcTimur[3];
GLuint textureHmtl[2];
GLuint texturePln[1];
GLuint textureTvst[2];
GLuint textureOktagon[2];
GLuint textureGkuBarat[3];
GLuint texturePau[2];
GLuint textureAltim[4];
GLuint textureAlbar[4];
GLuint textureBengkok[4];
GLuint textureHMSSelatan[1];
GLuint textureDoping[4];
GLuint textureGkuTimur[4];
GLuint textureKimia[1];
GLuint textureHms[1];
GLuint textureFttm[1];
GLuint textureLabbir[1];
GLuint textureDepanAltim[4];
GLuint textureCadl[4];
GLuint textureMetalurgi[1];
GLuint textureHmsutara1[4];
GLuint textureHmsutara2[4];

void initTexture(){
    textureLantai = SOIL_load_OGL_texture (
        (PATH+"img\\lantai.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureLabtekV[0] = SOIL_load_OGL_texture (
        (PATH+"img\\labtek56\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureLabtekV[1] = SOIL_load_OGL_texture (
        (PATH+"img\\labtek56\\utara1.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureLabtekVI[0] = SOIL_load_OGL_texture (
        (PATH+"img\\labtek56\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureLabtekVI[1] = SOIL_load_OGL_texture (
        (PATH+"img\\labtek56\\utara1.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureLabtekVII[0] = SOIL_load_OGL_texture (
        (PATH+"img\\labtekvii\\samping kiri.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureLabtekVII[1] = SOIL_load_OGL_texture (
        (PATH+"img\\labtekvii\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureLabtekVIII[0] = SOIL_load_OGL_texture (
        (PATH+"img\\labtekvii\\samping kiri.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureLabtekVIII[1] = SOIL_load_OGL_texture (
        (PATH+"img\\labtekvii\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureComlabs[0] = SOIL_load_OGL_texture (
        (PATH+"img\\comlabs\\comlabs.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureComlabs[1] = SOIL_load_OGL_texture (
        (PATH+"img\\comlabs\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureMektan[0] = SOIL_load_OGL_texture (
        (PATH+"img\\mektan\\Mektan_Selatan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureMektan[1] = SOIL_load_OGL_texture (
        (PATH+"img\\mektan\\timur tengah.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureCcBarat[0] = SOIL_load_OGL_texture (
        (PATH+"img\\ccbarat\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureCcBarat[1] = SOIL_load_OGL_texture (
        (PATH+"img\\ccbarat\\selatan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureCcBarat[2] = SOIL_load_OGL_texture (
        (PATH+"img\\ccbarat\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureCcTimur[0] = SOIL_load_OGL_texture (
        (PATH+"img\\ccbarat\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureCcTimur[1] = SOIL_load_OGL_texture (
        (PATH+"img\\ccbarat\\selatan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureCcTimur[2] = SOIL_load_OGL_texture (
        (PATH+"img\\ccbarat\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureHmtl[0] = SOIL_load_OGL_texture (
        (PATH+"img\\depanlabtek viii\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureHmtl[1] = SOIL_load_OGL_texture (
        (PATH+"img\\depanlabtek viii\\barat.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    texturePln[0] = SOIL_load_OGL_texture (
        (PATH+"img\\pln\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureTvst[0] = SOIL_load_OGL_texture (
        (PATH+"img\\tvst\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureTvst[1] = SOIL_load_OGL_texture (
        (PATH+"img\\tvst\\selatan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureOktagon[0] = SOIL_load_OGL_texture (
        (PATH+"img\\oktagon\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureOktagon[1] = SOIL_load_OGL_texture (
        (PATH+"img\\oktagon\\samping.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureGkuBarat[0] = SOIL_load_OGL_texture (
        (PATH+"img\\gkubarat\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureGkuBarat[1] = SOIL_load_OGL_texture (
        (PATH+"img\\gkubarat\\samping1.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureGkuBarat[2] = SOIL_load_OGL_texture (
        (PATH+"img\\gkubarat\\samping2.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    texturePau[0] = SOIL_load_OGL_texture (
        (PATH+"img\\pau\\timur.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    texturePau[1] = SOIL_load_OGL_texture (
        (PATH+"img\\pau\\barat.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureAltim[0] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureAltim[1] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\baratdaya.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureAltim[2] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\selatankanan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureAltim[3] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\baratdaya2.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureAlbar[0] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\utara.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureAlbar[1] = SOIL_load_OGL_texture (
        (PATH+"img\\aulabarat\\baratdaya2.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureAlbar[2] = SOIL_load_OGL_texture (
        (PATH+"img\\aulabarat\\baratdaya1.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureAlbar[3] = SOIL_load_OGL_texture (
        (PATH+"img\\aulabarat\\baratdaya2.png").c_str(), //sama kayak texture[1], cuma males ngedit if-nya
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureBengkok[0] = SOIL_load_OGL_texture (
        (PATH+"img\\sebelahbengkok.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureHMSSelatan[0] = SOIL_load_OGL_texture (
        (PATH+"img\\sebelahbengkok.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureDoping[0] = SOIL_load_OGL_texture (
        (PATH+"img\\doping\\selatan.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureDoping[1] = SOIL_load_OGL_texture (
        (PATH+"img\\doping\\barat.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureDoping[2] = SOIL_load_OGL_texture (
        (PATH+"img\\doping\\selatan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureDoping[3] = SOIL_load_OGL_texture (
        (PATH+"img\\doping\\barat.png").c_str(), //sama kayak texture[1], cuma males ngedit if-nya
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureGkuTimur[0] = SOIL_load_OGL_texture (
        (PATH+"img\\gkutimur\\selatan.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureGkuTimur[1] = SOIL_load_OGL_texture (
        (PATH+"img\\gkutimur\\barat.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureGkuTimur[2] = SOIL_load_OGL_texture (
        (PATH+"img\\gkutimur\\sampingbelakang.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureGkuTimur[3] = SOIL_load_OGL_texture (
        (PATH+"img\\gkutimur\\barat.png").c_str(), //sama kayak texture[1], cuma males ngedit if-nya
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureKimia[0] = SOIL_load_OGL_texture (
        (PATH+"img\\kimia.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureHms[0] = SOIL_load_OGL_texture (
        (PATH+"img\\sebelahbengkok.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureFttm[0] = SOIL_load_OGL_texture (
        (PATH+"img\\geomatika.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureLabbir[0] = SOIL_load_OGL_texture (
        (PATH+"img\\biru\\utara.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureDepanAltim[0] = SOIL_load_OGL_texture (
        (PATH+"img\\altim\\selatankanan.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureDepanAltim[1] = SOIL_load_OGL_texture (
        (PATH+"img\\altim\\selatankanan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureDepanAltim[2] = SOIL_load_OGL_texture (
        (PATH+"img\\altim\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureDepanAltim[3] = SOIL_load_OGL_texture (
        (PATH+"img\\altim\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureCadl[0] = SOIL_load_OGL_texture (
        (PATH+"img\\cadl\\selatan.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureCadl[1] = SOIL_load_OGL_texture (
        (PATH+"img\\cadl\\selatan1.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureCadl[2] = SOIL_load_OGL_texture (
        (PATH+"img\\cadl\\selatan.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureCadl[3] = SOIL_load_OGL_texture (
        (PATH+"img\\cadl\\selatan1.png").c_str(), //sama kayak texture[1], cuma males ngedit if-nya
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureMetalurgi[0] = SOIL_load_OGL_texture (
        (PATH+"img\\mesin.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureHmsutara1[0] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\utara.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureHmsutara1[1] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\selatan kiri.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureHmsutara1[2] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureHmsutara1[3] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\selatan kiri.png").c_str(), //sama kayak texture[1], cuma males ngedit if-nya
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureHmsutara2[0] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\utara.png").c_str(), //pake yang altim lebih bagus
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureHmsutara2[1] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\selatan kiri.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureHmsutara2[2] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\utara.png").c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
    textureHmsutara2[3] = SOIL_load_OGL_texture (
        (PATH+"img\\aulatimur\\selatan kiri.png").c_str(), //sama kayak texture[1], cuma males ngedit if-nya
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_DDS_LOAD_DIRECT
    );
}
void displayLantai(Building building,int h){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureLantai);
    glBegin(GL_POLYGON);
        glTexCoord3f(0.0, 1.0, 0.0);
        glVertex3f(lantai.points[0].x, lantai.points[0].y, lantai.points[0].z);
        glTexCoord3f(1.0, 1.0, 0.0);
        glVertex3f(lantai.points[1].x, lantai.points[1].y, lantai.points[1].z);
        glTexCoord3f(1.0, 0.0, 0.0);
        glVertex3f(lantai.points[2].x, lantai.points[2].y, lantai.points[2].z);
        glTexCoord3f(0.0, 0.0, 0.0);
        glVertex3f(lantai.points[3].x, lantai.points[3].y, lantai.points[3].z);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void displayLabtekV(Building building,int h){

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 1 ||i == 3){
          glBindTexture(GL_TEXTURE_2D, textureLabtekV[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureLabtekV[1]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 1 ||i == 3){
          glBindTexture(GL_TEXTURE_2D, textureLabtekVI[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureLabtekVI[1]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 1 ||i == 3){
          glBindTexture(GL_TEXTURE_2D, textureLabtekVII[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureLabtekVII[1]);
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
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 1 || i == 3){
          glBindTexture(GL_TEXTURE_2D, textureLabtekVIII[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureLabtekVIII[1]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 1){
          glBindTexture(GL_TEXTURE_2D, textureComlabs[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureComlabs[1]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0 || i == 2){
          glBindTexture(GL_TEXTURE_2D, textureMektan[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureMektan[1]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i == 0 ){
          glBindTexture(GL_TEXTURE_2D, textureCcBarat[0]);
        } else if (i == 2) {
            glBindTexture(GL_TEXTURE_2D, textureCcBarat[1]);
        }
        else {
            glBindTexture(GL_TEXTURE_2D, textureCcBarat[2]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0 ){
          glBindTexture(GL_TEXTURE_2D, textureCcTimur[0]);
        } else if (i == 2) {
            glBindTexture(GL_TEXTURE_2D, textureCcTimur[1]);
        }
        else {
            glBindTexture(GL_TEXTURE_2D, textureCcTimur[2]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0 || i == 2){
          glBindTexture(GL_TEXTURE_2D, textureHmtl[0]);
        }
        else {
            glBindTexture(GL_TEXTURE_2D, textureHmtl[1]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texturePln[0]);

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
void displayTvst(Building building,int h){

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i == 3){
          glBindTexture(GL_TEXTURE_2D, textureTvst[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureTvst[1]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i == 3){
          glBindTexture(GL_TEXTURE_2D, textureOktagon[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureOktagon[1]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 3){
          glBindTexture(GL_TEXTURE_2D, textureGkuBarat[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, textureGkuBarat[1]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureGkuBarat[2]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 3){
          glBindTexture(GL_TEXTURE_2D, texturePau[0]);
        } else {
            glBindTexture(GL_TEXTURE_2D, texturePau[1]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, textureAltim[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, textureAltim[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, textureAltim[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureAltim[3]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, textureAlbar[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, textureAlbar[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, textureAlbar[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureAlbar[3]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureBengkok[0]);

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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureHMSSelatan[0]);

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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, textureDoping[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, textureDoping[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, textureDoping[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureDoping[3]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, textureGkuTimur[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, textureGkuTimur[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, textureGkuTimur[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureGkuTimur[3]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureKimia[0]);

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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureHms[0]);

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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureFttm[0]);

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
void displayLabbir(Building building,int h){

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, textureLabbir[0]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, textureDepanAltim[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, textureDepanAltim[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, textureDepanAltim[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureDepanAltim[3]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, textureCadl[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, textureCadl[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, textureCadl[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureCadl[3]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, textureMetalurgi[0]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, textureHmsutara1[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, textureHmsutara1[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, textureHmsutara1[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureHmsutara1[3]);
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

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);
        for (int i = 0 ; i < building.pointsLength ; i++) {
            glVertex3f(building.points[i].x, building.points[i].y, building.points[i].z);
        }
    glEnd();
    for (int i = 0 ; i < building.pointsLength ; i++) {
        glEnable(GL_TEXTURE_2D);
        if ( i  == 0){
          glBindTexture(GL_TEXTURE_2D, textureHmsutara2[0]);
        } else if (i==1) {
            glBindTexture(GL_TEXTURE_2D, textureHmsutara2[1]);
        } else if (i==2) {
            glBindTexture(GL_TEXTURE_2D, textureHmsutara2[2]);
        } else {
            glBindTexture(GL_TEXTURE_2D, textureHmsutara2[3]);
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

static void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glTranslatef(x, y, z);
    if (nView == false) {
        glRotated(dX, 1, 0, 0);
        glRotated(dY, 0, 1, 0);
        glRotated(dZ, 0, 0, 1);
    } else {
        const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
        const double a = t * 30.0;
        glRotated(dX, 1, 0, 0);
        glRotated(dY, 0, 1, 0);
        glRotated(a, 0, 0, 1);
    }

    GLfloat light_position[] = { lX, lY, lZ, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    displayLantai(lantai,0);

    //tepi
    displayLabtekV(labtekV,2);
    displayLabtekVI(labtekVI,2);
    displayLabtekVII(labtekVII,2);
    displayLabtekVIII(labtekVIII,2);
    displayComlabs(comlabs,3);
    displayMektan(mekTan,2);
    displayCcbarat(ccBarat,2);
    displayCctimur(ccTimur,2);
    displayHmtl(hmtl,2);
    displayPln(pln,2);

    //Dyas
    displayTvst(tvst,3);
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

    //arizho
    displayHMSSelatan(hmsselatan,2);
    displayHms(hms,2);
    displayGkuTimur(gkutimur,2);
    displayFttm(fttm,2);
    displayKimia(amisca,2);
    displayDoping(doping,2);

    glutSwapBuffers();
}

static void mouse(int button, int state, int mouseX, int mouseY) {
    if (button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON)
    {
         prevMouseX = mouseX;
         prevMouseY = mouseY;
    } else if (button == 3) {
        if (z >= -40) {
            z--;
        }
    } else if (button == 4) {
        if (z < -10) {
            z++;
        }
    }
}

static void mouseMov(int mouseX, int mouseY) {
    x += (float)(mouseX - prevMouseX) / 1500.0f;
    y += (float)(mouseY - prevMouseY) * -1 / 1500.0f;
}

static void key(unsigned char key, int keyX, int keyY) {
    switch (key)
    {
        case 27 :
            exit(0);
            break;

        case 'd':
            dX = 0;
            dY = 0;
            dZ = 180;

            lX = 0.0f;
            lY = 0.0f;
            lZ = 5.0f;

            x = 0.0f;
            y = 0.0f;
            z = -20.0f;

            mView = false;
            nView = false;
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

        case 'p':
            lZ += 2;
            break;

        case 'o':
            lZ -= 2;
            break;

        case 'i':
            lY -= 2;
            break;

        case 'k':
            lY += 2;
            break;

        case 'j':
            lX += 2;
            break;

        case 'l':
            lX -= 2;
            break;

        case 'm':
            if (mView == false) {
                dX = -70;
                x = 0.0f;
                y = 0.0f;
                z = -23.0f;
                mView = true;
            } else {
                dX = 0;
                x = 0.0f;
                y = 0.0f;
                z = -20.0f;
                mView = false;
                nView = false;
            }
            break;

        case 'n':
            if (mView == true) {
                nView = !nView;
            }
            break;
    }

    glutPostRedisplay();
}

static void idle(void) {
    glutPostRedisplay();
}

/* Program entry point */

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Peta ITB");

    initGL();
    initTexture();

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMov);
    glutIdleFunc(idle);

    glutMainLoop();

    return EXIT_SUCCESS;
}
