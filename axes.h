#ifndef __AXES
#define __AXES

#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glut.h>

void axes(void);
void draw_cone(int x,int y,int z,int dx,int dy,int dz,int color);
#endif
// def draw_axes():
//     """Affiche les trois axes X, Y et Z en OpenGL."""
//     glLineWidth(2.0)  # Épaisseur des lignes
    
//     glBegin(GL_LINES)

//     # Axe X (Rouge)
//     glColor3f(1, 0, 0)  # Rouge
//     glVertex3f(-1, 0, 0)
//     glVertex3f(1, 0, 0)

//     # Axe Y (Vert)
//     glColor3f(0, 1, 0)  # Vert
//     glVertex3f(0, -1, 0)
//     glVertex3f(0, 1, 0)

//     # Axe Z (Bleu)
//     glColor3f(0, 0, 1)  # Bleu
//     glVertex3f(0, 0, -1)
//     glVertex3f(0, 0, 1)

//     glEnd()

// def display():
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
//     glLoadIdentity()
//     gluLookAt(2, 2, 2, 0, 0, 0, 0, 1, 0)  # Caméra positionnée en 3D
//     draw_axes()
//     glutSwapBuffers()

// def main():
//     glutInit()
//     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH)
//     glutInitWindowSize(500, 500)
//     glutCreateWindow("Axes en OpenGL")
//     glEnable(GL_DEPTH_TEST)
//     glutDisplayFunc(display)
//     glutMainLoop()