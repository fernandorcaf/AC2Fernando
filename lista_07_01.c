#include <stdio.h>
#include <stdlib.h>

void f1 (int v) {
	v = v + 1; // 1 + 1 
	printf (" f1 = %d\n " , v ); // f1 = 2
}
void f2 (int *v) {
	*v = *v + 1; //1 + 1
	printf (" f2 = %d\n " , *v ); // f2 = 2
}
int f3 (int v) {
	v = v + 1; // 2 + 1 
	printf (" f3 = %d\n " , v ); // f3 = 3
	return v;
}
int main (void) {
	int v = 1;
	f1 (v);
	f2 (&v);
	v = f3 (v); // v = 3
	printf (" main = %d \n" , v ); // main = 3
	return 0;
}
