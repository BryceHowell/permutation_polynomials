#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

FILE * OUT;


void print_list(int * list, int length) {
	for (int i=0; i<length; i++) fprintf(OUT,"%d ",list[i]);
	//printf("\n");
	}

void calculate_poly(int * list, int length) {
	class matrix A(length,length+1,length);
	A.setup(list,length);
	A.RREF();
	A.solution(OUT);
	A.clean();
	}

	
	
void recurse_permutation(int * list, int length, int pos) {
	if (pos==length-1) { print_list(list,length); fprintf(OUT," ="); calculate_poly(list,length);} else {
	for (int i=pos; i<length; i++) {
		int temp=list[i]; list[i]=list[pos]; list[pos]=temp;
		recurse_permutation(list,length,pos+1);
		temp=list[i]; list[i]=list[pos]; list[pos]=temp;
		}
	}
   }
   
   
int main() {
    int length=11;
	OUT=fopen("11permutation.txt","w");
	int * list=(int *)malloc(length*sizeof(int));
	for (int i=0; i<length; i++) list[i]=i;
	recurse_permutation(list,length,0);
	}