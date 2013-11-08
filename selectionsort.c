#include <stdio.h>
#include <stdlib.h>


void selectionsort(int *a, int lenght)
{
	int i, j ,tmp, min;
	if(length<=1) return;
	i = min;
	for(i = 1; i<lenght; i++)
	{
		for(j = i+1; j<lenght; j++)
		{
			if(a[j]<a[i]) 
			{
				min = j;
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
