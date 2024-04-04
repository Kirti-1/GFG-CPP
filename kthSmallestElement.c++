//{ Driver Code Starts
//Initial Template for C

/**
------------------ Description ---------------
Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Note :-  l and r denotes the starting and ending index of the array.

Example 1:

Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
L=0 R=5

Output : 7
Explanation :
3rd smallest element in the given 
array is 7. 
*/


#include<stdio.h>

// } Driver Code Ends
//User function Template for C


//Quick Select  with average asymptotic notation of O(N)
int kthSmallest(int arr[], int l, int r, int k)
    {   
        int pivotindex = l;
        int rindex = r;
        while(rindex+1!=k){
            rindex = findSmallestGroup(arr,l,rindex);
        }
        return arr[rindex];
        
        
    }
    int findSmallestGroup(int arr[], int l, int r){
        int pivot = arr[l];
        int i=l,j=r;
        do{
            while(i<=r && arr[i]<=pivot){
                i++;
            }
            while(arr[j]>pivot){
                j--;   
            }
            
            if(i<j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }while(i<j);
        int temp = arr[l];
        arr[l] = arr[j];
        arr[j] = temp;
        //index of pivot element also r
        return j;
    }

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    scanf("%d",&test_case);
    while(test_case--)
    {
        int number_of_elements;
        scanf("%d", &number_of_elements);
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            scanf("%d", &a[i]);
            
        int k;
        scanf("%d",&k);
        printf("%d",kthSmallest(a, 0, number_of_elements-1, k));
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends