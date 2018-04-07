/* Modify the temperature conversion program to print the table in reverse order,
 * that is, from 300 degrees to 0
 */

#include <stdio.h>

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300 */
main() {

	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	celsius = upper;
	printf("%8s\t \t%6s\n", "Celsius", "Fahrenheit");
	while (celsius >= lower) {
		fahr = (5.0/9.0) * (celsius-32.0);
		printf("%5.0f\t \t%15.1f\n", celsius, fahr);
		celsius = celsius - step;
	}
}
