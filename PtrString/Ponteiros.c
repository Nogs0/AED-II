#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n1= 20, *ptr_n;
	float  n2= 10, *ptr_n2;
	char letra= 'j', *ptr_letra;
	ptr_n = &n1;
	ptr_n2 =&n2;
	ptr_letra = &letra;

	*ptr_n = 100;
	*ptr_n2 = 1.54;
	*ptr_letra = 'a';

	printf("%d  %f  %c\n\n\n", n1,n2,letra); 
}
