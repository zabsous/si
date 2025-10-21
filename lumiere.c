#include "lumiere.h"
#include <time.h>
#include <stdbool.h>


// Fonction d'initialisation
void lumiere() {
    GLfloat lum_ambiante[] = {0.2f,0.2f,0.2f,0.5f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lum_ambiante);

    GLfloat lum_positionel[] = {1.0f,1.0f,1.0f,0.0f};
    GLfloat pos_lum_positionel[] = { -2.0, 0.5f,0.0f,0.0f};
    glLightfv(GL_LIGHT0 ,GL_POSITION,pos_lum_positionel);
    glLightfv(GL_LIGHT0 ,GL_DIFFUSE,lum_positionel);
    // glLightfv(GL_LIGHT0 ,GL_POSITION,lum_positionel);
    glEnable(GL_LIGHT0);

    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

GLfloat switch_lum_pos(GLfloat position){
    if(position == 1.0){
        glDisable(GL_LIGHT0);
        return 0.0;
    }
    else{
        glEnable(GL_LIGHT0);
        return 1.0;
    }
}