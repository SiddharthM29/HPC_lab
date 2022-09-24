//Write a program to print the sum of squares of 1 to hundred numbers using OpenMp

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;


static int sum =0;
int main()
{
    #pragma omp parallel
    {

        for(int i=1; i<=100;i++)
        {
            if(i%4==omp_get_thread_num())
            {
                printf("thread No. %d Number : %d Square : %d\n", omp_get_thread_num(), i, i * i);  
                sum+=i*i;
                printf("Sum is %d ",sum);
                cout<<endl;
                
            }
        }
    }
    return 0;
}
