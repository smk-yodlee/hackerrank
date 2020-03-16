//Basic brute force implmentation problem
//Checks for number crunching skills
//A modified kaprekar no is one that when sqaured and divided into 2 numbers l and r where r is the righrmost d digits of squared value
//where d id the no of digits of original no, and the sum of l+r=num
//Given a range, find all mod. kap. nos.

//However, this problem is here because the limits are given in int and they can be upto 10^9
//So it is a common mistake to choose i as int and iterate from i=lower_limit to i=upper_limit
//But that causes a problem
//The square of i may exceed over int limit
//People who notice this may try to use long long int sq = i*i
//but this is also an error as i is still int
//i*i is also truncated to int and this int result is stored in the long long int var
//Instead, we should use long long int sq = (long long int)i * (long long int)i


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

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {

    long long unsigned int sq;
    int i;
    int flag=0;
    for(i=p;i<=q;i++)
    {
        int num=i;
        int count=0;
        while(num!=0)
        {
            count++;
            num/=10;
        }
        sq=(long long unsigned int)pow(i,2);
        //printf("%llu\n",sq);
        long long unsigned int left,right;
        left=right=0;
        int cl,cr;
        cl=cr=0;
        while(sq!=0)
        {
            if(count>0){
                right = right+(sq%10)*((int)pow(10,cr));
                cr++;
            }
            else {
                left = left+(sq%10)*((int)pow(10,cl));
                cl++;
            }
            count--;
            sq/=10;
            //printf("%llu %llu\n",left,right);
        }
        if((left+right)==i)
        {   
            flag=1;
            printf("%d ",i);
        }
    }
    if(flag==0)
    {
        printf("INVALID RANGE");
    }
}

int main()
{
    char* p_endptr;
    char* p_str = readline();
    int p = strtol(p_str, &p_endptr, 10);

    if (p_endptr == p_str || *p_endptr != '\0') { exit(EXIT_FAILURE); }

    char* q_endptr;
    char* q_str = readline();
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    kaprekarNumbers(p, q);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}
