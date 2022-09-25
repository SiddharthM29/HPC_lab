//Write OpenMP code for two 2D Matrix addition, vary the size of your matrices
//from 250, 500, 750, 1000, and 2000 and measure the runtime with one thread (Use
//functions in C in calculate the execution time or use GPROF)
//i.For each matrix size, change the number of threads from 2,4,8., and plot the
//speedup versus the number of threads.
//ii.Explain whether or not the scaling behaviour is as expected.

 #include<iostream>
#include<stdio.h>
#include<omp.h>
using namespace std;
int main()
{
int size=0;
printf("Size of matrix\n");
scanf("%d", &size);
// omp_set_num_threads(10);
int* matrix = new int[size*size];
int* vector = new int[size];
int* result = new int[size];
#pragma omp for
for(int i=0; i<size; i++)
{
for(int j=0; j<size; j++)
*(matrix+i*size+j) = 2;
}
#pragma omp for
for(int i=0; i<size; i++)
{
*(vector+i)= 3;
}
int temp=0,threads;
double time = omp_get_wtime();
#pragma omp parallel for num_threads(8)
for(int i=0; i<size; i++)
{
for(int j=0; j<size; j++)
{
temp=0;
for(int k=0; k<size; k++)
{
temp += *(matrix+j*size+k) * *(vector+k);
}
}
threads = omp_get_num_threads();
*(result+i) = temp;
}
// for(int i=0; i<size; i++)
// {
// printf(" %d ", result[i]);
// }
printf("\nExecuted when size = %d and threads =%d \nDone in %f seconds\n",
size,threads, omp_get_wtime()-time);
return 0;
}
