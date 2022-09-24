#include <stdio.h>

int main(){
	int a, b;
	if(&a>&b)
		printf("&a > &b\n\n a = %p  b = %p\n", &a, &b);
	else	printf("&b > &a\n\n a = %p  b = %p\n", &a, &b);
	
	return 0;

}
