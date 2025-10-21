#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint texture;
void loadTexture(const char* filename) {
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    GLenum format = (nrChannels == 3) ? GL_RGB : GL_RGBA;
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glEnable(GL_TEXTURE_2D);

    stbi_image_free(data);
}
void drawTexturedQuad() {
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, 0.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, 0.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, 0.0f);
    glEnd();
}
