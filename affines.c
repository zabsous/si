#include "affines.h"
#include <time.h>
#include <stdbool.h>

extern int flagSens;
extern float random_number1;
extern float random_number2;
extern GLfloat angles12;
extern GLfloat anglemain12;
extern GLfloat angles22;
extern GLfloat anglemain22;
extern char* tab[];
extern GLuint textures[];

extern GLfloat limite1;
extern GLfloat limite2;


void constangle(playangle * p){
    p->angle=0.0f;
    p->anglemain1=0.0f;
    p->anglemain2=0.0f;
    p->angles1=0.0f;
    p->angles2=0.0f;
    p->pos=0.0f;
    p->pos2=0.0f;
}
GLfloat * translation (float a, float b, float c) {
    GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
    res[0] = (GLfloat)1.0f;
    res[1] = (GLfloat)0.0f;
    res[2] = (GLfloat)0.0f;
    res[3] = (GLfloat)0.0f;
    res[4] = (GLfloat)0.0f;
    res[5] = (GLfloat)1.0f;
    res[6] = (GLfloat)0.0f;
    res[7] = (GLfloat)0.0f;
    res[8] = (GLfloat)0.0f;
    res[9] = (GLfloat)0.0f;
    res[10] = (GLfloat)1.0f;
    res[11] = (GLfloat)0.0f;
    res[12] = (GLfloat)a;
    res[13] = (GLfloat)b;
    res[14] = (GLfloat)c;
    res[15] = (GLfloat)1.0f;
    return res;
}

GLfloat * homothetie (float a, float b, float c) {
    GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
    res[0] = (GLfloat)a;
    res[1] = (GLfloat)0.0f;
    res[2] = (GLfloat)0.0f;
    res[3] = (GLfloat)0.0f;
    res[4] = (GLfloat)0.0f;
    res[5] = (GLfloat)b;
    res[6] = (GLfloat)0.0f;
    res[7] = (GLfloat)0.0f;
    res[8] = (GLfloat)0.0f;
    res[9] = (GLfloat)0.0f;
    res[10] = (GLfloat)c;
    res[11] = (GLfloat)0.0f;
    res[12] = (GLfloat)0.0f;
    res[13] = (GLfloat)0.0f;
    res[14] = (GLfloat)0.0f;
    res[15] = (GLfloat)1.0f;
    return res;
}

void head() {
    glPushMatrix(); {
    glMultMatrixf(translation(0.0f, 3.0f,0.0f));
    glPushMatrix(); {
        glMultMatrixf (homothetie(5.0f,5.0f,5.0f));
        glutSolidCube(1.0);
        }
        glPopMatrix();
    }
    glPopMatrix();
}

void neck() {
    glPushMatrix(); {
        glMultMatrixf(translation(0.0f, 5.0f,0.0f));
        glPushMatrix(); {
            glMultMatrixf (homothetie(3.0f, 1.0f, 3.0f));
            glutSolidCube(1.0);
        }   glPopMatrix();
        head();
    }
    glPopMatrix();
}
void main1(playangle * p){
    glPushMatrix(); {
        glMultMatrixf(translation(0.0f,-3.0f,0.0f));
        glRotatef(p->anglemain1, 0.0f, 1.0f, 0.0f); 
        glPushMatrix(); {
            glMultMatrixf (homothetie(2.0f, 0.5f, 2.0f));
            glutSolidCube(1.0);
        }   glPopMatrix();
        glPushMatrix(); {
            glMultMatrixf(translation(-0.75f,-0.75f,0.0f));
            glMultMatrixf (homothetie(0.5f, 1.0f, 2.0f));
            glutSolidCube(1.0);
        }
        glPopMatrix();
        glPushMatrix(); {
            glMultMatrixf(translation(0.75f,-0.75f,0.0f));
            glMultMatrixf (homothetie(0.5f, 1.0f, 2.0f));
            glutSolidCube(1.0);
        }
        glPopMatrix();
    }
    glPopMatrix();
}
void main2(playangle * p){
    glPushMatrix(); {
        glMultMatrixf(translation(0.0f,-3.0f,0.0f));
        glRotatef(p->anglemain2, 0.0f, 1.0f, 0.0f); 
        glPushMatrix(); {
            glMultMatrixf (homothetie(2.0f, 0.5f, 2.0f));
            glutSolidCube(1.0);
        }   glPopMatrix();
        glPushMatrix(); {
            glMultMatrixf(translation(0.75f,-0.75f,0.0f));
            glMultMatrixf (homothetie(0.5f, 1.0f, 2.0f));
            glutSolidCube(1.0);
        }
        glPopMatrix();
        glPushMatrix(); {
            glMultMatrixf(translation(-0.75f,-0.75f,0.0f));
            glMultMatrixf (homothetie(0.5f, 1.0f, 2.0f));
            glutSolidCube(1.0);
        }
        glPopMatrix();
    }
    glPopMatrix();
}
void bras1(playangle * p){
    glPushMatrix(); {
        glMultMatrixf(translation(-0.5f, -3.5f,0.0f));
        glutSolidCube(1.0);
        glPushMatrix(); {
            glMultMatrixf (homothetie(1.0f, 6.0f, 3.0f));
            glutSolidCube(1.0);
        }
        glPopMatrix();
        main1(p);
    }
    glPopMatrix();
}
void bras2(playangle * p){
    glPushMatrix(); {
        glMultMatrixf(translation(0.5f, -3.5f,0.0f));
        glPushMatrix(); {
            glMultMatrixf (homothetie(1.0f, 6.0f, 3.0f));
            glutSolidCube(1.0);
        }
        glPopMatrix();
        // glRotatef(angle, 1.0f, 0.0f, 0.0f); 
        main2(p);
    }
    glPopMatrix();
}
void should1(playangle * p){
    glPushMatrix(); {
        glMultMatrixf(translation(-4.5f,3.5f,0.0f));
        glRotatef(p->angles1, 1.0f, 0.0f, 0.0f); 
        glPushMatrix(); {
            glMultMatrixf (homothetie(2.0f, 2.0f, 3.0f));
            glutSolidCube(1.0);
        }glPopMatrix();
        bras1(p);
    }
    glPopMatrix();
}
void should2(playangle * p){
    glPushMatrix(); {
        glMultMatrixf(translation(4.5f, 3.5f,0.0f));
        glRotatef(p->angles2, 1.0f, 0.0f, 0.0f); 
        glPushMatrix(); {
            glMultMatrixf (homothetie(2.0f, 2.0f, 3.0f));
            glutSolidCube(1.0);
        }glPopMatrix();
        bras2(p);
    }
    glPopMatrix();
}

void  torse(playangle * p) {
    glPushMatrix(); {
        glMultMatrixf(translation(0.0f, 5.5f,0.0f)); 
        glPushMatrix(); {
            glMultMatrixf (homothetie(7.0f, 9.0f, 5.0f));
            glutSolidCube(1.0);
        }
        glPopMatrix();
        neck();
        should1(p);
        should2(p);
    }
    glPopMatrix();
}

void jambe1(float x, float z,playangle * p){
    // glRotatef(0.0f,,0.0f,0.0f);
    glPushMatrix(); {
       glTranslatef(p->pos,0.0f,p->pos2);
       glMultMatrixf(translation(x,-13.0f,z));
       glPushMatrix();{
            // glMultMatrixf(translation(0.0f, 0.0,1.0f));
            glRotatef(p->angle, 1.0f, 0.0f, 0.0f);
            torse(p);
       }glPopMatrix();
       glPushMatrix();{
            glColor3d(0.0,1.0,1.0);
            glMultMatrixf (homothetie(7.0f, 2.0f, 4.0f));
            glutSolidCube(1.0);
        }glPopMatrix();
        glPushMatrix();{
            glColor3d(0.0,1.0,1.0);
            glMultMatrixf(translation(-2.5f,-4.5,0.0f));
            glPushMatrix();{
                glMultMatrixf (homothetie(2.0f, 7.0f, 3.0f));
                glutSolidCube(1.0);
            }glPopMatrix();
            glPushMatrix();{
                glMultMatrixf(translation(0.0f,-4.0,1.0f));
                glMultMatrixf (homothetie(2.0f, 1.0f, 5.0f));
                glutSolidCube(1.0);
            }glPopMatrix();
        }glPopMatrix();
        glPushMatrix();{
            glMultMatrixf(translation(2.5f,-4.5,0.0f));
            glPushMatrix();{
                glMultMatrixf (homothetie(2.0f, 7.0f, 3.0f));
                glutSolidCube(1.0);
            }glPopMatrix();
            glPushMatrix();{
                glMultMatrixf(translation(0.0f,-4.0,1.0f));
                glMultMatrixf (homothetie(2.0f, 1.0f, 5.0f));
                glutSolidCube(1.0);
            }glPopMatrix();
        }glPopMatrix();
    }
    glPopMatrix();
}
// void sol(){
//     glPushMatrix();{
//             glMultMatrixf(translation(0.0f,-20.0,0.0f));
//             glColor3d(0.0,1.0,0.0);
//             glMultMatrixf (homothetie(70.0f, 2.0f, 70.0f));
//             glutSolidCube(1.0);
//     }glPopMatrix();
// }



TEXTURE_STRUCT * readPpm(char *ppmFileName)
{
	FILE *file;
	TEXTURE_STRUCT *texture = NULL;
	char buffer[255];
	int pixelFormat;
	int i;


	if ((file = fopen(ppmFileName, "rb")) == NULL)
	{
		printf ("(ERROR) : C function fopen failed in readPpm(%s)\n", ppmFileName);
		getchar();
		return NULL;
	}

	//Test of the magic header (must be P3 or P6)
	fread (buffer, sizeof(char), 2, file);
	buffer[2] = '\0';
	if (strncmp(buffer, "P3", 2) & strncmp(buffer, "P6", 2))
	{
		printf ("(ERROR) : File %s doesn't seem to be a ppm, the header says %s [function readPpm]\n", ppmFileName, buffer);
		getchar();
		return NULL;
	}
	printf("%s\n", buffer);
	//Allocation of the pointer to the TEXTURE_STRUCT variable
	if ((texture = (TEXTURE_STRUCT *)malloc(sizeof(TEXTURE_STRUCT))) == NULL)
	{
		printf ("(ERROR) : C function malloc failed in readPpm(%s)\n", ppmFileName);
		getchar();
		return NULL;
	}
	
	//Ignoring backspaces, tabulations, end of lines and carriage return
	while (1)
	{
		fread (buffer, sizeof(char), 1, file);
		if (!((buffer[0]==32) || (buffer[0]==9) || (buffer[0]==10) || (buffer[0]==13)))
			break;
	}
	//Reading Width
	i = 1;
	while (1)
	{
		fread (buffer+i, sizeof(char), 1, file);
		if ((buffer[i]==32) || (buffer[i]==9) || (buffer[i]==10) || (buffer[i]==13))
			break;
		i++;
	}
	buffer[i] = '\0';
	texture->width = atoi(buffer);
	//Ignoring backspaces, tabulations, end of lines and carriage return	
	while (1)
	{
		fread (buffer, sizeof(char), 1, file);
		if (!((buffer[0]==32) || (buffer[0]==9) || (buffer[0]==10) || (buffer[0]==13)))
			break;
	}
	//Reading Height
	i = 1;
	while (1)
	{
		fread (buffer+i, sizeof(char), 1, file);
		if ((buffer[i]==32) || (buffer[i]==9) || (buffer[i]==10) || (buffer[i]==13))
			break;
		i++;
	}
	buffer[i] = '\0';
	texture->height = atoi(buffer);
	//Ignoring backspaces, tabulations, end of lines and carriage return	
	while (1)
	{
		fread (buffer, sizeof(char), 1, file);
		if (!((buffer[0]==32) || (buffer[0]==9) || (buffer[0]==10) || (buffer[0]==13)))
			break;
	}
	//Reading bpp
	i = 1;
	while (1)
	{
		fread (buffer+i, sizeof(char), 1, file);
		if ((buffer[i]==32) || (buffer[i]==9) || (buffer[i]==10) || (buffer[i]==13))
			break;
		i++;
	}
	buffer[i] = '\0';
	pixelFormat = atoi(buffer);
	pixelFormat++;
	printf ("%d %d %d\n", texture->width, texture->height, pixelFormat);
	//Finding the number of bits fitting the pixel format, if available
	if (pixelFormat <= 0)
	{
		printf ("(ERROR) : Pixel Format of the %s ppm file is less or equal to 0\n", ppmFileName);
		getchar();
		free (texture);
		return NULL;
	}
	texture->bpp = 1;
	while ((pixelFormat - (1 << texture->bpp)) >= 1)
		texture->bpp++;
	//printf ("Detected %d BPP\n", texture->bpp);
	//Ignoring backspaces, tabulations, end of lines and carriage return	
	while (1)
	{
		fread (buffer, sizeof(char), 1, file);
		if (!((buffer[0]==32) || (buffer[0]==9) || (buffer[0]==10) || (buffer[0]==13)))
			break;
	}
	//Reading the texture
	//	if ((texture->data = (unsigned char *)malloc(texture->width*texture->height*3*sizeof(unsigned char))) == NULL)
	if ((texture->data = (unsigned char *)malloc(256*256*3*sizeof(unsigned char))) == NULL)
	{
		printf ("(ERROR) : C function malloc failed in readPpm(%s)\n", ppmFileName);
		getchar();
		free(texture);
		return NULL;
	}
	fseek(file, -1, SEEK_CUR);

	int ligne = 0;
	while(ligne < texture->height) {
	  fread(texture->data+(3*256*ligne), sizeof(unsigned char), 3*texture->width, file);
	  ligne++;
	}
	// fread(texture->data, sizeof(unsigned char), 3*texture->width*texture->height, file);
	
	printf ("(OK) : The file %s was correctly parsed and uploaded in memory [function readPpm]\n", ppmFileName);
	//printf ("%d %d %d\n", texture->width, texture->height, texture->bpp);getchar();getchar();

	texture->width = 256;
	texture->height = 256;
	return texture;

}


unsigned char * rgb2rgba(TEXTURE_STRUCT * texture)
{
  int width = texture->width;
  int height = texture->height;
  unsigned char * data = texture->data;
  unsigned char * temp = (unsigned char *) malloc (sizeof(unsigned char) * width* height *4);
  int i = 0;

  for (i=0; i<width*height; i++)
    {
      temp[i*4+0] = data[i*3+0];
      temp[i*4+1] = data[i*3+1];
      temp[i*4+2] = data[i*3+2];      
      if ((data[i*3+0]==0) && (data[i*3+1]==0) && (data[i*3+2]==0))
	temp[i*4+3] = 255;	// Pixel noir donc transparent
      else
	temp[i*4+3] = (unsigned char)0; // Pixel complÃ¨tement opaque
    }									       
  return temp;
}

void loadTexture(int index, char *filename) {
    // Lecture de la texture à partir du fichier PPM
    TEXTURE_STRUCT *texture = readPpm(filename);

    if (!texture) {
        printf("Failed to load texture\n");
        return;
    }

    // Création d'une texture OpenGL
    glGenTextures(1, &textures[index]);
    printf("ID de texture généré: %d\n", textures[index]);

    glBindTexture(GL_TEXTURE_2D, textures[index]);

    // Définir les paramètres de la texture (filtrage, répétition, etc.)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    unsigned char* rgbaData = rgb2rgba(texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->width, texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, rgbaData);

    free(rgbaData);

    // Libération de la texture lue en mémoire
    free(texture->data);
    free(texture);
    printf("Texture loaded successfully!\n");
}

void sol() {
    glPushMatrix();
    {
        GLfloat largeurSol = limite1 - limite2;

        // Active le test de profondeur et la texture
        glEnable(GL_TEXTURE_2D);  

        glBindTexture(GL_TEXTURE_2D, textures[0]);  // Lier la texture chargée
        glColor3f(1.0f, 1.0f, 1.0f);  // Assurez-vous que la couleur ne masque pas la texture

        glBegin(GL_QUADS);
        
        // Définir les coordonnées de texture et les sommets du sol
        glTexCoord2f(0.0f, 5.0f);  // Coordonnée de texture pour le coin supérieur gauche
        glVertex3f(-largeurSol / 2, 0.0f, -largeurSol / 2);
        
        glTexCoord2f(5.0f, 5.0f);  // Coordonnée de texture pour le coin supérieur droit
        glVertex3f(largeurSol / 2, 0.0f, -largeurSol / 2);
        
        glTexCoord2f(5.0f, 1.0f);  // Coordonnée de texture pour le coin inférieur droit
        glVertex3f(largeurSol / 2, 0.0f, largeurSol / 2);
        
        glTexCoord2f(0.0f, 1.0f);  // Coordonnée de texture pour le coin inférieur gauche
        glVertex3f(-largeurSol / 2, 0.0f, largeurSol / 2);
        
        glEnd();
        
        // Désactive la texture après le dessin
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}
void mouvement(playangle * p){
    srand(time(NULL));
    // Générer un nombre entre -3 et 3q
    int random_number = (rand() % 7) - 3;
    printf("Le nombre est : %d\n",random_number);
    switch (random_number)
    {
    case 0:
        random_number = (rand() % 7) - 3;
        if ((p->angles1+random_number >= -40)&&(p->angles1+random_number <= 40))
            p->angles1 += random_number;
        break;
    case 1:
        random_number = (rand() % 7) - 3;
        if ((p->anglemain1+random_number >= -40)&&(p->anglemain1+random_number <= 40))
            p->anglemain1 += random_number;
        break;
    case 2:
        random_number = (rand() % 7) - 3;
        if ((p->angle+random_number >= -40)&&(p->angle+random_number <= 40))
            p->angle += random_number;
        break;
    case 3:
        random_number = (rand() % 7) - 3;
        if ((p->angles2+random_number >= -40)&&(p->angles2+random_number <= 40))
            p->angles2 += random_number;
        break;
    case -1:
        random_number = (rand() % 7) - 3;
        if ((p->anglemain2+random_number >= -40)&&(p->anglemain2+random_number <= 40))
            p->anglemain2 += random_number;
        break;
    case -2:
        random_number = (rand() % 5) - 2;
        if ((p->pos+random_number >= limite2)&&(p->pos+random_number <= limite1))
            p->pos += random_number;
        break;
    case -3:
        random_number = (rand() % 5) - 2;
        if ((p->pos2+random_number >= limite2)&&(p->pos2+random_number <= limite1))
            p->pos2 += random_number;
        break; 
    default:
        break;
    }
    }