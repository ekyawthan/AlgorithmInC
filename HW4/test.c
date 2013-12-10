#include <stdlib.h>
#define POSITION 89765
#include "mong_1704_hw4.c"




int main(void)
{  char sequence[100001];
  char pattern[1000];
  int i, j;
  for(i=0; i<100000; i++)
     sequence[i] = 'a';
  sequence[100000]='\0';
  printf(sequence);	
  for(i=0; i<4000; i++)
  {  j = rand()%100000;
     sequence[j]='b';      
  }
	printf(sequence);
  for(j=0; j< 1000; j++)
     pattern[j] = sequence[POSITION+j];
  pattern[1000] = '\0';
  if(find_string(sequence, pattern) == POSITION )
    printf("accepted\n");
  else
    printf("needs check?\n");
}
