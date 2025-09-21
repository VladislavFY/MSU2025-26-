 
#include "prototypes_22.h"

int function_of_check(FILE *f)
{
    double curr = 0, prev = 0, prevprev = 0;
    int violations_typeC = 0;
    int violations_typeE = 0;
    double next=0;
    int have_next = 0;
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

 

    while (1) {
        if (have_next) {
            curr = next;
            have_next = 0;
        } else {
            if ( fscanf(f, "%lf", &curr) != 1 ) break;
        }

        if (curr - prev <= eps) {
            violations_typeC++;
            if (violations_typeC > 1) return -2;

            if ( fscanf(f, "%lf", &next) == 1 ) {
                have_next = 1;
                int can_change_prev = (curr - prevprev > eps);
                int can_change_curr = (next - prev > eps);

                if (!can_change_prev && !can_change_curr) return -2;

                if (can_change_prev) {
                    double new_prev = prevprev + eps;
                    prevprev = new_prev;
                    prev = curr;
                } else {
                    curr = prev + eps;
                    prevprev = prev;
                    prev = curr;
                }
                continue;
            } else {
                return 0;
            }
        }

        prevprev = prev;
        prev = curr;
    }

    return 0;
}
