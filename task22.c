#include "prototypes_22.h"



int main(void)
{
        FILE *f = fopen("data_22.txt", "r");
    if (f == NULL)
    {
        printf("File error");
        return -5;
    }
    if ((function_of_check(f))==0)
    {
        printf("YES\n");
        return 0;
    }
    else{
        printf("NO\n");
        return 0;
    }
}
