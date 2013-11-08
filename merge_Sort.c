#include <stdio.h>
#include <stdlib.h>


struct listnode
{
	int 			value;
	struct listnode *next;
	/* data */
};

struct listnode *mergesort(struct listnode *list)
{
	struct listnode *list1, *end1, *list2, *end2, *end, *tmp;
	// split list in two
	list1 = end1= list; list = list->next;
	if(list == NULL)
		return (list1); //base case;
	list2 = end2 = list; list = list->next;
	while(list !=NULL)
	{
		end1->next = list; list = list->next; end1 = end1->next;
		tmp = list1; list1 = list2; list2 = tmp;
		tmp = end1; end1 = end2; end2 = tmp;
	}
	end1->next = NULL; end2->next= NULL; /*teminate both lists*/
	// recursive call 
	list1 = mergesort(list1); list2 = mergesort(list2);

	//merging sorted list
	if(list1->value <list2->value)
		{ list = list1; list1 = list1->next;}
	else
		{ list =list2; list2 = list2->next;}
	end = list;
	while(list1 != NULL && list2 !=NULL)
	{
		if(list1->value <list2->value)
			{ end->next = list1; list1 = list1->next;}
		else
			{end->next = list2; list2 = list2->next;}
		end = end->next;
	}
	if(list1 != NULL)
		{ end->next = list1; list1 = NULL;}
	else if(list2 != NULL)
		{ end->next = list2; list2 = NULL;}
	else
		end->next = NULL;
	return (list);
}

