#ifndef __ACTIONS
#define __ACTIONS

/* ascii codes for various special keys */

#include "affines.h"
#include "touches.h"
#include "switch_blend.h"
#include "switch_light.h"
#include "lumiere.h"
#include <stdlib.h>
void touche_pressee(unsigned char key, int x, int y);
void touche_speciale(int key, int x, int y);
#endif

