#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

using namespace std;

int euclidean(int a, int b) {
	int r1=a,r2=b,r;
	do { r=r1%r2; r1=r2; r2=r;
		// printf("%d mod %d\n",r1,r2);  
		} while (r!=1 && r!=0);
	//printf("%d ",r2);
	return r1;
	}

int mult_inv(int a, int m) {
   int m0 = m, t, q;
   int x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
		}
    // Make x1 positive
    if (x1 < 0) x1 += m0;
    return x1;	
	}	
	
	
matrix::matrix(int r, int c, int mod) {
	A=(int *)malloc(r*c*(sizeof(int)));
	rows=r; cols=c;
	m=mod;
	}
	

void matrix::clean() {
	free(A);
	}
	
void matrix::set_entry(int r,int c,int value) {
	A[c+cols*r]=value;
	}
	
int matrix::get_entry(int r,int c) {
	return A[c+cols*r];
	}
	
	
void matrix::display() {
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) printf("%d ",A[j+i*cols]); 
		printf("\n");
		}
	}
	
void matrix::setup(int * list, int length) {
	//free(A);
	//A=(int *)malloc(length*(length+1)*(sizeof(int)));
	//rows=length;
	//cols=length+1;
	//m=length;
	int x=1;
	for(int i=0; i<length; i++) {
		x=1;
		for (int j=0; j<length; j++) { 
			set_entry(i,j,x);
			x*=i; x%=m;
			}
		
		set_entry(i,length,list[i]);
		}
	}	
	
void matrix::scalar_row(int row, int scalar) {
	for (int j=0; j<cols; j++) set_entry(row,j,(get_entry(row,j)*scalar)%m);
	}

void matrix::add_row(int row2, int row, int scalar) { // row2 is target for adding row times scalar
	for (int j=0; j<cols; j++) set_entry(row2,j,(get_entry(row2,j)+get_entry(row,j)*scalar)%m);
	}
	
	
void matrix::RREF() {
	for (int i=0; i<rows; i++) {
		// normalize row so diagonal coeff == 1
		int mult=get_entry(i,i);
		//printf("%d mult^-1 = ",mult);
		mult=mult_inv(mult,m);
		//printf("%d\n",mult);
		scalar_row(i,mult);
		for (int j=0; j<rows; j++) {
			if (i!=j) {
				add_row(j,i,m-get_entry(j,i));
				} 
			}
		}
	}
	
void matrix::solution(FILE * OUT) {
	int first=1;
	for (int i=rows-1; i>=0; i--) {
		if (get_entry(i,cols-1)!=0) {
			if (!first) { fprintf(OUT,"+"); } else first=0;
			if (i==0) fprintf(OUT,"%d",get_entry(i,cols-1)); else fprintf(OUT,"%dx^%d",get_entry(i,cols-1),i);
			}
		}
		fprintf(OUT,"\n");
}
	
	
/*	
int main() {
	//printf("\n%d \n",euclidean(31,5));
	//printf("\n%d \n",mult_inv(3,31));
	int list[7]={0,2,3,1,6,5,4};
	int length=7;
	class matrix A(7,8,7);
	A.setup(list,length);
	A.display();
	A.RREF();
	A.display();
	A.solution();
	} */