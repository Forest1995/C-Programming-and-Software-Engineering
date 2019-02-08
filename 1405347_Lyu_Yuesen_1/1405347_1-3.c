#include<stdio.h>/*include information about standard library stdio.h*/
#define PI 3.14159
main() {
	float radius, volume, surface_area;  /*declare three variables of the type of float namely radius,volume and surface_area */
	printf("Please enter the radius:");  /*ask user to input a number representing the radius*/
	scanf_s("%f", &radius);              /*store the value into variable radius*/
	volume = 4 * PI*radius*radius*radius / 3;  /*compute the volume according to the provided formula*/
	surface_area = 4 * PI*radius*radius;       /*compute the surface area according to the provided formula*/
	printf("The volume of the sphere is : %f\n", volume);            /*display the volume of the sphere*/
	printf("The surface area of the sphere is : %f\n", surface_area);/*display the surface area of the sphere*/
}