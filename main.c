// gcc main.c opmat.c affines.c actions.c init.c VM_init.c axes.o  lumiere.o switch_blend.o  switch_light.o -lm -lGL -lGLU -lglut -o test



#include "init.h"
#include "axes.h"
#include "affines.h"
#include "VM_init.h"
#include "opmat.h"
#include <time.h>
// #include <stdbool.h>
int blend = 0;
int light = 0;
GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat zrot = 0.0f;
GLfloat dz = -40.0f;
GLfloat dir = 0.0f;
GLfloat lum_pos=0.0f;
int flagSens = 1;
float random_number1=0;
float random_number2=0;
GLfloat angles12 = 0.0f;
GLfloat anglemain12 = 0.0f;
GLfloat angles22 = 0.0f;
GLfloat anglemain22 = 0.0f;
// bool cond= true;
// int tab =0;
playangle  P1;
playangle  P2;
GLuint textures[2]; 

GLfloat limite1 = 40.0f;
GLfloat limite2 = -40.0f;



char* tab[2] = {
 "herbe.ppm",
 "./img/ballon.ppm"
};
GLvoid Modelisation()
{
  VM_init();
  glPushMatrix();
  {
    // GLfloat * params = new GLfloat[4];
    // params[0] = (GLfloat)3.0f;
    // params[1] = (GLfloat)3.0f;
    // params[2] = (GLfloat)3.0f;
    // params[3] = (GLfloat)1.0f;
    // glLightfv(0, GL_POSITION, params);
    // glEnable(GL_LIGHT0);
    // hand(angle);
    // torse();
     // Initialisation du générateur de nombres aléatoires
    // Générer un nombre entre -10 et 10
    // Afficher le nombre généré
    // hand();
    glPushMatrix();
    {
      GLfloat * ma_translation = translation(0,-22,0);
      glMultMatrixf(ma_translation);
      sol();
    }
    glPopMatrix();
    jambe1(0.0,0.0,&P1);  
    jambe1(20.0,0.0,&P2);
    mouvement(&P2);
    //triangle(angle);
  }
  glPopMatrix();
  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  constangle(&P2);
  constangle(&P1);
  return notre_init(argc, argv, &Modelisation);
}
