#include <spin.h>
#include <stdio.h>

int x = 5;
struct spin s = spin_const_new(&x);

int
main()
{
	spin(int *x, &s){
		*x = 10;
	}
	spin(int *x, &s){
		printf("%d\n", *x);
	}
}
