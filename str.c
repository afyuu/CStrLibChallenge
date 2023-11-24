/**
 * Coded by afyuu
 * I made this library in like less than 2 hours in the middle of the night
 * Do not use this for your work
*/


#include "str.h"


str *String(int numargs, ...) {
    va_list args; va_start(args, numargs);

    char *input; int length;
    if (numargs == 2) {
        input = va_arg(args, char *);
        length = va_arg(args, int);
    } else {
        input = va_arg(args, char *);
        length = 0;
    }

    if (length == 0) {
        int i = 0;
        while (input[i] != '\0') {
            i++; length++;
        }
    }
    

    str *new = malloc(sizeof(str));
    new->length = length;
    new->data = malloc(length);

    for (int i = 0; i < length; i++) {
        char *ptr = new->data + i;
        *ptr = input[i];
    }

    return new;
}


void print(str *string) {
    for (int i = 0; i < string->length; i++) {\
        printf("%c", *(string->data + i));
    } 
    printf("\n");
}


void printextra(str *string) {
    printf("Custom string type '");
    for (int i = 0; i < string->length; i++) {
        printf("%c", *(string->data + i));
    }
    printf("' has a length of [%d] characters and takes up [%lld] bytes.\n", string->length, sizeof(str) + string->length + sizeof(int) + 1);
}


void delete(str *string) {
    free(string->data);
    free(string);
}


int getlength(str *string) {
    return string->length;
}


char grabchar(str *string, int pos) {
    return *(string->data + pos);
}


int replacechar(str *string, char old, char new) {
    int count = 0;
    for (int i = 0; i < getlength(string); i++) {
        if (grabchar(string, i) == old) {
            *(string->data + i) = new;
            count++;
        }
    }
    return count;
}


str *concatenate(str *left, str *right) {
    unsigned int count = 1;
    char *combined = malloc(count);

    for (int i = 0; i < left->length; i++) {
        combined[i] = grabchar(left, i);
        count++; combined = realloc(combined, count);
    }
    for (int i = 0; i < right->length; i++) {
        combined[i + left->length] = grabchar(right, i);
        count++; combined = realloc(combined, count);
    }

    combined[left->length + right->length] = '\0';
    str *new = String(1, combined);

    free(combined);
    return new;
}



str *duplicate(str *origin) {
    str *dupe = String(2, origin->data, origin->length);
    return dupe;
}


double compare(str *a, str *b, char usekeyboard) {
    int numchars = a->length;
    if (b->length > numchars) {
        numchars = b->length;
    }

    int score = 0;

    for (int i = 0; i < numchars; i++) {
        char x = grabchar(a, i); char y = grabchar(b, i);
        if (x > 127) {
            x = 127;
        };
        if (y > 127) {
            y = 127;
        };
        
        if (usekeyboard == true) {
            score += getqwertydistance(x, y);
        } else {
            score += getalphadistance(x, y);
        }
    }
    return (double)score / (double)numchars;
}


signed char getalphadistance(char a, char b) {
    if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z') {
        return b - a;
    }
    return -127;
}


signed char getqwertydistance(char a, char b) {
    char keyboard[4][10] = {
        {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
        {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
        {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm'},
        {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'},
    };
    unsigned char ax = 255; unsigned char ay = 255; unsigned char bx = 255; unsigned char by = 255; 

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            if (keyboard[i][j] == a) {
                ax = i; ay = j;
            };
            if (keyboard[i][j] == b) {
                bx = i; by = j;
            };
        }
    }

    if (ax != 255 && ay != 255 && bx != 255 && by != 255) {
        return abs(bx - ax) + abs(by - ay);
    } else {
        return 127;
    }
}