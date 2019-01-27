#include <stdio.h>

float celsiusToFahrenheit(int celsius) {
	return (9.0/5.0) * (celsius) + 32.0;
}

int main () {
    float celsius;
    int lower, upper, step;

    lower = 0;    /* lower limit of temperature table */
    upper = 300;  /* uper limit */
    step = 20;    /* step size */
 
    /* Heading */
    printf("**************************************************\n");
    printf("This program prints the Fahrenheit from Celsius table\n");
    printf("**************************************************\n");

    celsius = lower;

    while (celsius <= upper) {
        printf("%3.0f %6.1f\n", celsius, celsiusToFahrenheit(celsius)); 
        
        celsius = celsius + step;
    }

    return 0;
}

