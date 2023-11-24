/**
 * Coded by afyuu
 * I made this library in like less than 2 hours in the middle of the night
 * Do not use this for your work
*/


#include "str.h"


int main() {
    str *a = String(1, "supercalifragilisticexpialidocious"); print(a);
    str *b = String(1, "supercalifragilisticexpialidocious"); print(b);
    printf("Difference = %f\n", compare(a, b, true));

    str *ab = concatenate(a, b); print(ab);
    str *dupe = duplicate(ab); printf("Duplicate "); print(dupe);


    // printf("KEYBOARD DISTANCE\n");
    // printf("Distance from d to a = %d\n", getqwertydistance('d', 'a'));
    // printf("Distance from k to n = %d\n", getqwertydistance('k', 'n'));
    // printf("Distance from j to z = %d\n", getqwertydistance('j', 'z'));
    // printf("Distance from f to f = %d\n", getqwertydistance('f', 'f'));
    // printf("Distance from b to ] = %d\n", getqwertydistance('b', ']'));

    // printf("\nALPHABETICAL DISTANCE\n");
    // printf("Distance from d to a = %d\n", getalphadistance('d', 'a'));
    // printf("Distance from k to n = %d\n", getalphadistance('k', 'n'));
    // printf("Distance from j to z = %d\n", getalphadistance('j', 'z'));
    // printf("Distance from f to f = %d\n", getalphadistance('f', 'f'));
    // printf("Distance from b to ] = %d\n", getalphadistance('b', ']'));
    

    delete(a); delete(b); delete(ab); delete(dupe);
    return 0;
}
