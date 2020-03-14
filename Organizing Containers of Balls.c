//Initial config is that there are n containers and n types of balls
//Given the different amount of each type of ball present in each container, determine if it is possible to make swaps such that
//each container has only 1 type of ball
//This will only be possible if the amount of balls for any colour is equal to the amount of balls stored in a container at any time
//No of balls for every colour = sum of columns
//No of balls in containers = sum of every row
//Check if sum_col[i] = sum_row[j] for some j for every i
//Make sum_row[j] = -1 so that it does not hamper checks for other i's.



#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int q; 
    scanf("%d",&q);
    for(int a0 = 0; a0 < q; a0++){
        int n; 
        scanf("%d",&n);
        int M[n][n];
        for(int M_i = 0; M_i < n; M_i++){
           for(int M_j = 0; M_j < n; M_j++){
              
              scanf("%d",&M[M_i][M_j]);
           }
        }
        
        int x[n], y[n], i, j, k;
     
        for(i=0; i<n; i++){
            x[i] = 0;
            y[i] = 0;
        }
        
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                x[i] = x[i] + M[i][j];
            }
        }
        
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                y[i] = y[i] + M[j][i];
            }
            
            for(k=0; k<n; k++){
                if(y[i] == x[k]){
                    x[k] = -1;
                    
                } 
            }}
        int flag = 0;
            
        for(i=0; i<n; i++){
            if(x[i] != -1) flag = 1;
        }
        
        if(flag == 1) printf("Impossible\n");
        else printf("Possible\n");
            
        
        // your code goes here
    }
    return 0;
}
