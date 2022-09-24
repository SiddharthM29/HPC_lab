//write a program to print Hello World using OpenMp

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	
	#pragma omp parallel
	{
		int id=omp_get_thread_num();
		printf("thread No. %d  Hello World\n", id);
	}
    return 0;
}
