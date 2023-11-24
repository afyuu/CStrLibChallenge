/**
 * Coded by afyuu
 * I made this library in like less than 2 hours in the middle of the night
 * Do not use this for your work
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


#define true 1
#define false 0


#define MAX_STR_LENGTH 2048


typedef struct {
    char *data;
    unsigned int length;
} str;


/**
 * Initialization and deconstruction functions
*/


/**
 * The function creates a new string object with a given input and length, or calculates the length if
 * not provided, and returns the string object.
 * 
 * @param numargs The number of arguments passed through ...
 * 
 * @return a pointer to a dynamically allocated `str` structure.
 */
str *String(int numargs, ...);

/**
 * The delete function frees the memory allocated for a string and the string itself.
 * 
 * @param string The parameter "string" is a pointer to a struct of type "str".
 */
void delete(str *string);


/**
 * The function "print" takes a pointer to a string and prints each character in the string.
 * 
 * @param string The parameter "string" is a pointer to a structure of type "str".
 */
void print(str *string);


/**
 * The function `printextra` prints information about a custom string type, including its length and
 * memory usage.
 * 
 * @param string The parameter "string" is a pointer to a custom string type called "str".
 */
void printextra(str *string);


/**
 * Access and Manipulation functions
*/


/**
 * The function "getlength" returns the length of a given string.
 * 
 * @param string The parameter "string" is a pointer to a structure of type "str".
 * 
 * @return The length of the string.
 */
int getlength(str *string);


/**
 * The function `grabchar` returns the character at a specified position in a string.
 * 
 * @param string The parameter "string" is a pointer to a structure of type "str".
 * @param pos The parameter "pos" is an integer that represents the position of the character to be
 * grabbed from the string.
 * 
 * @return the character at the specified position in the string.
 */
char grabchar(str *string, int pos);


/**
 * The function replaces all occurrences of a specified character in a string and returns the number of
 * replacements made.
 * 
 * @param string The parameter "string" is a pointer to a structure of type "str".
 * @param old The parameter "old" is a character that you want to replace in the string.
 * @param new The parameter "new" is of type char and represents the character that will replace the
 * old character in the string.
 * 
 * @return the count of how many times the old character was replaced with the new character in the
 * string.
 */
int replacechar(str *string, char old, char new);


/**
 * The function concatenates two strings by dynamically allocating memory and copying the characters
 * from both strings into a new string.
 * 
 * @param left A pointer to a str struct representing the left string to concatenate.
 * @param right The "right" parameter is a pointer to a string object.
 * 
 * @return a pointer to a new string (`str`) that is the concatenation of the `left` and `right`
 * strings.
 */
str *concatenate(str *left, str *right);


/**
 * The function "duplicate" creates a duplicate of a given string.
 * 
 * @param origin The "origin" parameter is a pointer to a structure of type "str".
 * 
 * @return a duplicate of the input string.
 */
str *duplicate(str *origin);


/**
 * Comparison functions
*/


/**
 * The function `compare` calculates a score based on the similarity between two strings, taking into
 * account the length of the strings and whether to use keyboard distance or alphabetical distance.
 * 
 * @param a Pointer to a string object representing the first string to compare.
 * @param b The parameter "b" is a pointer to a string object.
 * @param usekeyboard The parameter "usekeyboard" is a boolean variable that determines whether to use
 * the keyboard layout distance or the alphabetical distance for calculating the score. If
 * "usekeyboard" is true, the function will use the "getqwertydistance" function to calculate the
 * distance between characters. If "usekeyboard"
 * 
 * @return a double value, which is the score calculated by comparing two strings.
 */
double compare(str *a, str *b, char usekeyboard);


/**
 * The function calculates the distance between two lowercase alphabets and returns it as a signed
 * char.
 * 
 * @param a The parameter 'a' is a character representing the starting alphabet.
 * @param b The parameter 'b' represents the second character in the alphabet.
 * 
 * @return the distance between two lowercase alphabetic characters. If both characters are lowercase
 * alphabets, it returns the difference between the ASCII values of the two characters. If the
 * characters are not lowercase alphabets, it returns -127.
 */
signed char getalphadistance(char a, char b);


/**
 * The function calculates the distance between two characters on a QWERTY keyboard.
 * 
 * @param a The parameter 'a' represents the first character on the keyboard.
 * @param b The parameter 'b' represents the second character for which we want to calculate the
 * distance on the QWERTY keyboard.
 * 
 * @return the distance between two characters on a QWERTY keyboard. If the characters are found on the
 * keyboard, the function returns the sum of the absolute differences in row and column indices. If
 * either character is not found on the keyboard, the function returns 127.
 */
signed char getqwertydistance(char a, char b);