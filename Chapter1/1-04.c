// Modify the temperature conversion program to print a heading above the table.
#include <stdio.h>

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300 */
main() {

	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	celsius = lower;
	printf("%8s\t \t%6s\n", "Celsius", "Fahrenheit");
	while (celsius <= upper) {
		fahr = (5.0/9.0) * (celsius-32.0);
		printf("%5.0f\t \t%15.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
