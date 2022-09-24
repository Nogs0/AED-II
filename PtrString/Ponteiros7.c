#include <stdio.h>

int main()
{
	int i = 3, j =5, *p, *q;
	p = &i;
	p = &*&i;
	i = *&j;
	i = *&*&j;
	q = &j;
	i = (*p)++ + *q;

	return 0;
}
