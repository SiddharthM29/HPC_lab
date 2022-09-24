 #include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

 
 int main(){
 	long long sum = 0;
 	int c0=0,c1=0,c2=0,c3=0;
 	double getInTime = omp_get_wtime();
 	
 	#pragma omp parallel for reduction(+ : sum)
 	
 	for(int i=1;i<=100;i++){
 		sum += (i*i);
 		int id=omp_get_thread_num();
 		cout << "thread number" << id << endl;
 		if(id==0) c0++;
 		else if(id==1)c1++;
 		else if(id==2)c2++;
 		  else  c3++;
	 }
 	
 	double getOutTime = omp_get_wtime();
 	
 	double exptTime = getOutTime - getInTime;
 	
 	
 	printf("Time Required For Execution in Parallel : %f\n",exptTime);
 	
 	printf("Answer is : %lld",sum);
 	cout << "c0 is" << c0 <<endl;
 	cout << "c1 is" << c1 << endl << "c2 is" << c2 << endl << "c3 is" << c3;
 	
 	return 0;
 	
 }
