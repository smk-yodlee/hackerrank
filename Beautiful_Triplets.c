//Given a array of of non decreasing integers upto limit n, a triplet of indices i,j,k are said to be beautiful iff
//i<j<k && arr[j] - arr[i] = arr[k] - arr[j] = d
//Best solution is O(N) with hash map of size n+1
//For arr[i] make hash[arr[i]]=1
//Then for i=0 to size(arr)-1, check if hash[arr[i]] == hash[arr[i]+d] == hash[arr[i] + 2*d] == 1
//If yes, increment counter



#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the beautifulTriplets function below.
int beautifulTriplets(int d, int arr_count, int* arr) {
    
    int flag[20005];
    memset(flag,0,sizeof(flag));
    int i;
    for(i=0;i<arr_count;i++)
    {
        flag[arr[i]]=1;
    }
    int count=0;
    for(i=0;i<arr_count;i++)
    {
        if(flag[arr[i]]==1 && flag[arr[i]+d]==1 && flag[arr[i]+2*d]==1)
        count++;
    }
    return count;
}

int main()
{
    int n,d;
    scanf("%d %d",&n,&d);
    int i;
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int c = beautifulTriplets(d, n, arr);
    printf("%d\n",c);
}
