/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <tgmath.h>
int main()
{
    printf("Please enter the angle in radians(real number):");
    double a;
    scanf("%lf", &a);
    double z1 = (sin(2 * a) + sin(5 * a) - sin(3 * a))/(cos(a) - 1 + (2 * pow(sin(a),2)) );
    double z2 = 2 * sin(a);
    printf("z1 = %lf\nz2 = %lf", z1, z2);

    return 0;
}
