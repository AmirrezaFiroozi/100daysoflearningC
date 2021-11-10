#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* A function converting an integer fahrenheit degree to its equivalent (float) celsius degree */
float fahrToCelsius(int fahr);
/* print a table showing temperature in Celsius for Fahr = 0, 20, ..., 300 */
int main(){

printf("Fahrenheit\tCelsius\n");
for (int fahr = LOWER; fahr <= UPPER; fahr += STEP)
    printf("   %3d\t\t%6.2f\n", fahr, fahrToCelsius(fahr) );

return 0;
}

float fahrToCelsius(int fahr){
    return (float) (5.0 / 9.0) * (fahr-32);
}
