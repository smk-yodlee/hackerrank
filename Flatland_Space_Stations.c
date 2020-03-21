//Given an no of cities where certain cities contain a space station, find the maximum distance of a city from its nearest space station
//Input - n : No of cities, m-No of space stations, m indices - which cities have the space stations
//Below approach is O(n^2)
//More efficient approach would be to use DP
//For every city in O(n), we can calculate distance to nearest space station on left using dp[i] = dp[i-1]+1 if arr[i]!=0, otherwise dp[i]=0
//Similarly for right side. Finally find maximum of these


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

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, int c_count, int* c) {
    if(n==c_count)
    return 0;

    int sp[n];
    memset(sp,0,sizeof(sp));
    int dist[n];
    memset(dist,0,sizeof(dist));
    int i;
    for(i=0;i<c_count;i++)
    {
        sp[c[i]]=1;
    }
    for(i=0;i<n;i++)
    {
        //printf("\ni=%d ",i);
        int j,k,ldist,rdist;
        ldist = rdist = INT_MAX;
        if(sp[i]==1)
        dist[i]=0;
        else {
            for(j=i-1;j>=0;j--)
            {
                if(sp[j]==1)
                {
                    ldist=i-j;
                    break;
                }
            }
            for(k=i+1;k<n;k++)
            {   
                if(sp[k]==1)
                {
                    rdist=k-i;
                    break;
                }
            }
            dist[i]=ldist<rdist?ldist:rdist;
        }
    }
    int maxd = INT_MIN;
    for(i=0;i<n;i++)
    {
        //printf("%d ",dist[i]);
        if(dist[i]>maxd)
        maxd=dist[i];
    }
    //printf("\n");
    return maxd;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[m];
    int i;
    for(i=0;i<m;i++)
    {
        scanf("%d",&arr[i]);
    }
    int maxd = flatlandSpaceStations(n, m, arr);
    printf("%d\n",maxd);
    return 0;
}
