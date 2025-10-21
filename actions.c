#include "actions.h"
#include <time.h>
#include <stdbool.h>
extern GLfloat xrot;
extern GLfloat yrot;
extern GLfloat zrot;
extern GLfloat dz;
extern int blend;
extern int light;
extern GLfloat angle;
extern GLfloat anglemain1;
extern GLfloat anglemain2;
extern GLfloat angles1;
extern GLfloat angles2;
extern GLfloat pos;
extern GLfloat pos2;
extern GLfloat dir;
extern GLfloat lum_pos;
// extern bool cond;
extern int bulle;
extern playangle P1;
extern int tab;
void touche_pressee(unsigned char key, int x, int y)
{
    usleep(200);
    switch (key) {
      case TOUCHE_tab :
        if(tab==0){
          tab=1;
        }
        else tab =0 ;
        break;
      if (tab==0){
        case TOUCHE_t :
            P1.pos2 -= 10.0f;
            break;
        case TOUCHE_g :
            P1.pos2 += 10.0f;
            break;
        case TOUCHE_f :
            P1.pos -= 10.0f;
            break;
        case TOUCHE_h :
            P1.pos += 10.0f;
            break;
        case TOUCHE_w :
          if (P1.angles1 >= -40)
            P1.angles1 -= 10.0f;
            break;
        case TOUCHE_c :
          if (P1.angles2 >= -40)
            P1.angles2 -= 10.0f;
            break;
        case TOUCHEmaj_w :
          if (P1.angles1 <= 40)
            P1.angles1 += 10.0f;
            break;
        case TOUCHEmaj_c :
          if (P1.angles2 <= 40)
            P1.angles2 += 10.0f;
            break;
        case TOUCHE_e :
          if (P1.anglemain1 >= -40)
            P1.anglemain1 -= 10.0f;
            break;
        case TOUCHE_a :
          if (P1.anglemain2 >= -40)
            P1.anglemain2 -= 10.0f;
            break;
        case TOUCHEmaj_e :
          if (P1.anglemain1 <= 40)
            P1.anglemain1 += 10.0f;
            break;
        case TOUCHEmaj_a :
          if (P1.anglemain2 <= 40)
            P1.anglemain2 += 10.0f;
            break;
        case TOUCHE_q:
          if (P1.angle >= -40)
            P1.angle -= 10.0f;
        break;
        case TOUCHE_d:
          if (P1.angle <=40)
            P1.angle += 10.0f;
        break;
    }
  //   case ESCAPE:
  //     // cond = false;
	// exit(1);
	// break;
      case Touche_m :
        lum_pos = switch_lum_pos(lum_pos);
        break;
      case ESPACE:
        xrot = 0.0f;
        yrot = 0.0f;
        zrot = 0.0f;
        dz= -20.0f;
        break;
      case TOUCHE_MIN_B:
        printf(",,,,,,");
        blend =  switch_blend(blend);
        break;
      case TOUCHE_MIN_L:
        light = switch_light(light);
        break;
  }
}

void touche_speciale(int key, int x, int y){
    usleep(100);
    if(tab==1){
      switch (key) {
          case GLUT_KEY_UP:
                dz +=1;
                break;
          case GLUT_KEY_LEFT:
                xrot+=10;
                break;
          case GLUT_KEY_RIGHT:
                xrot-=10;
                break;
          case GLUT_KEY_DOWN:
                dz -=1;
                break;
          case GLUT_KEY_INSERT:
                zrot+=10;
                break;
          case GLUT_KEY_PAGE_UP:
                yrot+=10;
                break;
          case GLUT_KEY_PAGE_DOWN:
                yrot-=10;
                break;
          case GLUT_KEY_END:
                zrot-=10;
                break;
      }
    }
}

