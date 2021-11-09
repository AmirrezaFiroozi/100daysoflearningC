#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20
/* print a table showing Fahrenheit for Celsius = 0, 20, ..., 300 */
int main(){

int celsius; 
printf("Fahrenheit\tCelsius\n");
for (celsius = LOWER; celsius <= UPPER; celsius += STEP)
    printf("   %3d\t\t%6.0f\n", celsius, (float) (celsius * 9.0/5.0) + 32);

return 0;
}
