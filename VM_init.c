#include "VM_init.h"

extern GLfloat xrot;
extern GLfloat yrot;
extern GLfloat zrot;
extern GLfloat dz;

void VM_init() {
    glDepthMask( GL_TRUE );
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,dz);
    glRotatef(xrot,1.0f,0.0f,0.0f);
    glRotatef(yrot,0.0f,1.0f,0.0f);
    glDepthMask( GL_FALSE );
}
