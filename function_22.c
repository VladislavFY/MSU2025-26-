 
#include "prototypes_22.h"

int function_of_check(FILE *f)
{
        
    double curr = 0, prev = 0, prevprev = 0;
    int violations_typeC = 0;
    int violations_typeE = 0;
    if ( fscanf(f, "%lf", &prevprev) != 1)
    {
        printf("File is empty");
        return -3;
    }
    if ( fscanf(f, "%lf", &prev) != 1)
    {
        printf( "File doesnt have two numbers!");
        return -4;
    }
    while( fscanf(f, "%lf", &curr) == 1){
        if(curr-prev<=eps) violations_typeC++;
        if(fabs(curr-prevprev>eps)) violations_typeE++;
        if(violations_typeC>1){
                return -2;
        }
          if(violations_typeE>1){
                return -6;
        }
        prevprev=prev;
        prev=curr;
    }
    return 0;
}
