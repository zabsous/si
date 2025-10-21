#ifndef __AFFINES
#define __AFFINES
#include <stdio.h>
#include "stdlib.h"
#include "math.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include <string.h>
#include <stdbool.h>
typedef struct {
    GLfloat angle;
    GLfloat anglemain1;
    GLfloat anglemain2 ;
    GLfloat angles1 ;
    GLfloat angles2 ;
    GLfloat pos;
    GLfloat pos2;
}playangle;


typedef struct
{
  int width, height, bpp;
  unsigned char *data;
} TEXTURE_STRUCT;

GLfloat * translation (float a, float b, float c);
GLfloat * homothetie (float a, float b, float c);
void head();
void main1(playangle * P);
void main2(playangle * P);
void bras1(playangle * P);
void bras2(playangle * P);
void should1(playangle * P);
void should2(playangle * P);
void neck();
void torse(playangle * P);
void jambe1(float x , float z,playangle * P);
void mouvement(playangle * p);
void constangle(playangle * p);
void sol();
void  loadTexture(int index, char *filename) ;
#endif