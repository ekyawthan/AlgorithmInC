/*##########################################################################
# Name			: Kyaw Than Mong
# email 		: ekyawthan@gmail.com
# Assigment 		: HW4
# Reference		: http://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
# Test System Info	:
# Compiler		:
###########################################################################*/


#include <stdio.h>
#include <string.h>



void 
compute_prefix_function(char *p, int *pi)
{
	int m; 
	m = strlen(p);
	int k = 0;
	int q;
	for (q = 1; q<m; q++)
	{
		while(k>0 && p[k] !=p[q])
		{
			k = pi[k-1];
		}
		if(p[k] ==p[q])
		{
			k = k+1;
		}
		pi[q] = k;

	}
}

int 
find_string(char *s, char *t)
{
	int n = strlen(s);
	int m = strlen(t);
	int tmp[m];
	tmp[0] = 0;
	compute_prefix_function(t,tmp);
	int i;
	int q = 0;
	for(i = 0; i<n; i++)
	{
		while(q>0 && t[q] !=s[i])
		{
			q = tmp[q-1];
		
		}
		if(t[q] ==s[i])
		{
			q = q+1;
		}
		if (q==m)
		{
			return i-m+1;
		}

	}
	return -1;
}

 
