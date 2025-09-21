 
#include "prototypes_42.h"

int function_of_check(FILE *f)
{
        
    double curr = 0, prev = 0;
    int len_of_curr= 1;
    int max_len=0;
    if ( fscanf(f, "%lf", &prev) != 1)
    {
        printf( "File empty");
        return -3;
    }
    while( fscanf(f, "%lf", &curr) == 1){
        if(curr-prev >= -eps ){
            len_of_curr++;
            if(len_of_curr>=max_len){
                max_len=len_of_curr;
            }
        }
        if(curr-prev<0){
            len_of_curr=1;
        }
        prev=curr;
    }
    return max_len;
}
