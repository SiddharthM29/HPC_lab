// Analyse and implement a Parallel code for below program using OpenMP.
// C Program to find the minimum scalar product of two vectors (dot product

#include<omp.h>
#include<stdio.h>
#include<iostream>
#include<time.h>
#define n 1000
using namespace std;
void sort(int nums[])
{
	int i,j;
	for(int i=0;i <n-1;i++)
	{
		int turn =i%2;
		#pragma omp parallel for
		for(int j=turn;j<n-1;j++)
		{
			if(nums[j]>nums[j+1])
			{
				int t=nums[j];
				nums[j]=nums[j+1];
				nums[j+1]=t;
			}
		}
	}
}
void sort_desc(int nums[])
{
	int i,j;
	for(int i=0;i <n-1;i++)
	{
		int turn=i%2;
		#pragma omp parallel for
		for(int j=i;j<n-1;j++)
		{
			if(nums[j]<nums[j+1])
			{
				int t=nums[j];
				nums[j]=nums[j+1];
				nums[j+1]=t;
			}
		}
	}
}
int main()
{
	int nums1[n],nums2[2];
	for(int i=0;i <n;i++)
	{
		if(i%2)
		{
		nums1[i]=i+2;
		}
		else{
			nums1[i]=i*2;
		}
		
	}
	for(int i=0;i <n;i++)
	{
		if(i%2)
		{
			nums2[i]=i*2;
		}
		else{
		nums2[i]=i+1;
		}
		cout << nums2[i] << endl;
	}
	clock_t t;
	t=clock();
	sort(nums1);
	sort_desc(nums2);
	t=clock()-t;
	 cout << endl << "hello";
double time_taken = ((double)t) / CLOCKS_PER_SEC;
 printf("Time taken (para): %f\n", time_taken);
 int sum = 0;
 for (int i = 0; i < n; i++) {
 sum = sum + (nums1[i] * nums2[i]);
 }
 printf("%d\n", sum);
 return 0;
}

