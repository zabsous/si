#include "axes.h"

void axes(void){
    glLineWidth(3.5)  ;
    
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);  
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0)  ;
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);
    
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, -1);
    glVertex3f(0, 0, 0);
    
    // draw_cone(1, 0, 0, 1, 0, 0, (1, 0, 0))  ;
    // draw_cone(0, 1, 0, 0, 1, 0, (0, 1, 0))  ;
    // draw_cone(0, 0, 1, 0, 0, 1, (0, 0, 1))  ;
    glEnd();
}
// void draw_cone(int x,int y,int z,int dx,int dy,int dz,int color){
//     glPushMatrix();
//     glTranslatef(x, y, z);
//     int angle = 0;
//     axis = (0, 0, 1);

//     if (dx != 0 or dy != 0){
//         from math import acos, sqrt, degrees;
//         length = sqrt(dx**2 + dy**2 + dz**2);
//         angle = degrees(acos(dz / length)) ;
//         axis = (-dy, dx, 0)  ;
//     }

//     glRotatef(angle, *axis) ;
    
//     glColor3f(*color) ;
//     quadric = gluNewQuadric();
//     gluCylinder(quadric, 0.05, 0, 0.2, 20, 20)  # Base = 0.05, pointe = 0, hauteur = 0.2
//     glPopMatrix()
// }