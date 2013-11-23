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
