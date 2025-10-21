#include "switch_blend.h"
#include <stdio.h>
int switch_blend(int k ){
    if(k==0){
        glEnable(GL_BLEND);
        printf("huhuhuh");
        return 1;
    }
    else{
        glDisable(GL_BLEND);
        printf("zazazza");
        return 0;
    }
}