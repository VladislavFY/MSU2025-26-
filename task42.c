#include "prototypes_42.h"

int main(void)
{
        FILE *f = fopen("data_42.txt", "r");
    if (f == NULL)
    {
        printf("File error\n");
        return -4;
    }
    else
        {
            printf("Answer: %d\n", function_of_check(f));
            return 0;
        }
}
