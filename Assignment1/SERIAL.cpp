#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

 
 int main(){
 	
 	long long sum = 0;
 	
 	double inTime = omp_get_wtime();
 	
 	
 	int i;
 	for(i=1;i<=100000000;i++){
 		sum += (i*i);
	 }
	 
	 
	 double outTime = omp_get_wtime();
	 
	 double expcTime = outTime - inTime;
	 
	 printf("Time Required for Execution in Serial : %f\n",expcTime);
	 printf("Answer is : %lld",sum);
 	
 	return 0;
 }
