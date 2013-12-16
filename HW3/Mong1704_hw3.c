/*##########################################################################
# Name			         : Kyaw Than Mong
# email 		         : ekyawthan@gmail.com
# Assigment 		     : HW4
# Reference		        : http://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm
# Test System Info	  : Linux Ubuntu
# Compiler		        : GCC
#Limitation           : The Size of queue is Fix
# Test Result         :
                      prepared capacity matrix, now executing maxflow code
                      Outflow of  0 is 10, should be 10
                      Inflow of 999 is 10, should be 10
                      End Test
                      
###########################################################################*/


#include <stdio.h>
#include <limits.h>


#define false 0
#define true 1
typedef int bool;



//Queue Declaretion and Definition 
int head, tail;
int q[10000000];
void 
push(int x){
	q[tail] = x;
	tail++;
}
int 
pop(){
	int x = q[head];
	head++;
	return x;
}



//finding minmum function
int 
min(int a, int b){
  return a<b? a:b;
}
// finding Argument path if residual capacity still exist 
// using Breath First Search Alorithm 
bool 
argPath(int n, int s, int t, int *rGraph,int frontier[]){
  int i, j, visited[n]; 
  for(i = 0; i < n; i++) visited[i] = 0; 
  visited[s] = true;
	head = tail = 0;
	push(s);
  frontier[s] = -1;


  while( head !=tail){
   	i = pop();
   	for (j=0; j<n; j++){
   		if (*(rGraph + i*n + j) > 0 && visited[j] == false){
   			push(j);
   			frontier[j] = i;
   			visited[j] = true;
 		 	}
   	}
   }
   return (visited[t] == true) ;  
}

void 
maximum_flow(int n, int s, int t, int *capacity, int *flow){
	int i, j, rGraph[n][n], frontier[n]; 
  int min_flow_path = INT_MAX; 

    
  for (i = 0; i < n; i++){
   	for (j = 0; j < n; j++){
     		rGraph[i][j] = *(capacity + i*n + j);
    		*(flow + i*n + j) = 0; 
    	}
    }

  while (argPath(n, s, t, &(rGraph[0][0]), frontier)){
   	for (j = n-1; frontier[j]>=0; j = frontier[j]){
    		i = frontier[j];
    		min_flow_path = min(min_flow_path, rGraph[i][j]);
    	}
 
    for (j = n-1; frontier[j]>=0; j = frontier[j]){
    		i = frontier[j];
    		if(*(capacity + i*n + j) > 0) 
    			*(flow + i*n + j) += min_flow_path;
   			else 
   				*(flow + j*n + i) -= min_flow_path;
    		rGraph[i][j] -= min_flow_path;
    		rGraph[j][i] += min_flow_path;
    	}
   	}
}

