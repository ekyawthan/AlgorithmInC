#include <stdio.h>
#include <stdlib.h>


struct listnode
{
	long 			value;
	struct listnode *next;
	
};

int Length(struct listnode *list)
{
	struct listnode *tmp = list;
	int counter = 0;
	while(tmp != NULL)
	{
		counter++;
		tmp =tmp->next;
	}
	return counter;
}

struct listnode *randomizedPivot(struct listnode *data)
{
	int size, i = 0,k ;
	size = Length(data);
	struct listnode *pivot = data;
	k = rand()%size;
	for(; i<k; i++)
	{
		pivot = pivot->next;
	} 
	return pivot;
}

struct listnode *concatenation(struct listnode *ls1, struct listnode *pivotElm, struct listnode *ls2)
{
	struct listnode *tmp= NULL;
	if(ls1 != NULL)
	{
		tmp = ls1;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		pivotElm->next = ls2;
		tmp->next = pivotElm;		
		return ls1;
	}
	else{
		pivotElm->next = ls2;
		return pivotElm;
	}
}


struct listnode *quicksort(struct listnode *data)
{
	int size;
	size = Length(data);
	if(size <= 1) return data;

	struct listnode *list1=NULL, *list2=NULL, *nextPtr, *tailPtr, *tmp=NULL;
	
	struct listnode *pivot = randomizedPivot(data);

	
	while(data != NULL)
	{
		nextPtr = data->next;
		if(data->value != pivot->value){
			if( data->value<pivot->value)
			{
				data->next = list1;
				list1 = data;
			}
			else{
				data->next = list2;
				list2 = data;
			}
		}
		data = nextPtr;
	}
	
	list1 = quicksort(list1); list2 = quicksort(list2);
	
	return (concatenation(list1, pivot, list2));
	
}

int main(void)
{  
   long i; 
   struct listnode *node, *tmpnode, *space;
   space =  (struct listnode *) malloc( 1000000*sizeof(struct listnode));
   for( i=0; i< 1000000; i++ )
   {  (space + i)->value = 2*((17*i)%1000000);
      (space + i)->next = space + (i+1);
   }
   (space+999999)->next = NULL;
   node = space;
   //printList(node);
   //struct listnode *pivot; int size = 0;
  //randomizedPivot(node, &pivot, &size);
  //printf("%d\n",pivot->value); printf("%d\n",size);

   printf("\n prepared list, now starting sort\n");
    node = quicksort(node);
   printf("\n checking sorted list\n");
   for( i=0; i < 1000000; i++)
   {  if( node == NULL )
      {  printf("List ended early\n"); exit(0);
      }
      if( node->value != 2*i )
      {  printf("Node contains wrong value\n"); exit(0);
      }
      node = node->next;
   }
   printf("Sort successful\n");
   exit(0);
}
