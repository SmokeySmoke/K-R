/* Our binary search makes two tests inside the loop, when one would
 * suffice (at the price of more tests outside). Write a version with
 * only one test inside the loop and measure the difference in run-time.
 *
 * binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
#include <stdio.h>
#include <time.h>
#define ARLEN 10
int binsearch(int x, int v[], int n);
int mybinsearch(int x, int v[], int n);

int main(void)
{
	clock_t start, end;
	double runtime;
	int ar[] = {0,1,2,3,4,5,6,7,8,9};
	int x, product;

	printf("Choose a number from 0-9 (q to quit): ");
	while (scanf("%d", &x) == 1)
	{
		start = clock();
		product = binsearch(x, ar, ARLEN);
		end = clock();
		runtime = (double) (end - start) / CLOCKS_PER_SEC;
		printf("\n%d %s in array ", x, product == -1 ? "NOT FOUND" : "FOUND");
		if (product > -1)
			printf("index %d!\n", product);
		else
			puts("!");
		printf("Book runtime: %lf\n\n", runtime);

		start = clock();
		product = mybinsearch(x, ar, ARLEN);
		end = clock();
		runtime = (double) (end - start) / CLOCKS_PER_SEC;
		printf("%d %s in array ", x, product == -1 ? "NOT FOUND" : "FOUND");
		if (product > -1)
			printf("index %d!\n", product);
		else
			puts("!");
		printf("MY runtime: %lf\n\n", runtime);

		printf("Choose another number (q to quit): ");
	}
	puts("Bye!");

	return 0;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else	// found match
			return mid;
	}
	return -1;	// no match
}

int mybinsearch(int x, int v[], int n)
{
	int low, high, mid;
	_Bool comp;

	low = 0;
	high = n - 1;
	mid = (low+high) / 2;
	while ((comp = low <= high) && x != v[mid])
	{
		x < v[mid] ? (high = mid-1) : (low = mid+1);
		mid = (low+high) / 2;
	}
	
	return comp == 1 ? mid : -1;
}
