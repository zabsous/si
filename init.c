#include "init.h"
// #include <time.h>
// #include <stdbool.h>
// extern GLfloat pos3;
// extern GLfloat pos4;
// extern bool cond;
int window;

GLvoid Redimensionne(GLsizei Width, GLsizei Height) {
    glViewport(0, 0, Width, Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, (GLfloat)Width/(GLfloat)Height ,0.1f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
}

int notre_init(int argc, char** argv, void (*DrawGLScene)()) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0,0);
    window = glutCreateWindow("OpenGL");
    glDepthMask( GL_FALSE );
    glutDisplayFunc(DrawGLScene);
    loadTexture(0,"herbe.ppm");
    glutIdleFunc(DrawGLScene);
    glDisable(GL_BLEND);
    glutReshapeFunc(&Redimensionne);
    lumiere();
    glutKeyboardFunc(&touche_pressee);
    glutSpecialFunc(&touche_speciale);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glutMainLoop();
    glDepthMask( GL_TRUE );
    // while(cond){
    //   srand(time(NULL));
    //   int random_number1 = (rand() % 21) - 10;
    //   pos3+=random_number1;
    //   int random_number2 = (rand() % 21) - 10;
    //   pos4+=random_number2;
    // }
    return 1;
}
