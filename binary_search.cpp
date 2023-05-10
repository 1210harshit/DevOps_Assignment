//Program for performing binary search
#include<stdio.h>
#define max 20

int binary_search(int a[],int low,int high, int x);

int main()
	{
		//Variable declaration
		int a[max],n,i,k,x;
		
			printf("Enter the limit for the array\n");
		scanf("%d",&n);
		
		printf("Enter the elements for the array in sorting order : ");
		  for(i=0;i<n;i++)
		  	  scanf("%d",&a[i]);
		  	  
		printf("Enter the number to be searched in the array :");
		scanf("%d",&x);  	  
		
		k=binary_search(a,0,n-1,x);
		
		if(k==-1)
		  printf("Number is not found in the array :(");
		else
		  printf("Numner is found at postion %d....Yippee :)",(k+1));  
		  
		  return 0;
			}//End of main method
			
int binary_search(int a[],int low, int high, int x)	
	{
		int mid;
		while(low<=high)
			{
			   mid=(low+high)/2;
			   
			   if(a[mid]==x)
			   return mid;
			   
			   if(a[mid]>x)
			   high=mid-1;
			   
			   else
			    low=mid+1;	
		}//End of while
			
			return -1;
  }//End of binary_search 
			
					
