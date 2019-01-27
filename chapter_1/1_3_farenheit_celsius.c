#include <stdio.h>

/* print Fahrenhei-Celsius table 
   for fahr = 0, 20, ...,<300 */

int main () {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;    /* lower limit of temperature table */
    upper = 300;  /* uper limit */
    step = 20;    /* step size */
 
    /* Heading */
    printf("**************************************************\n");
    printf("This program prints the Celsius from Fahrenheit table\n");
    printf("**************************************************\n");

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0); /* formula for getting Celsius from Fahrenheit */
        printf("%3.0f %6.1f\n", fahr, celsius); 
        /* %3.0f formats the fahr float is to be printed at least 3 characters wide, */
        /* with no decimal point and no fraction digits */
        /* %6.1f prints celsius with 6 charaters wide and 1 digit after the decimal point */
        fahr = fahr + step;
    }

    return 0;
}
