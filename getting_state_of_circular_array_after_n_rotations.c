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

// Complete the circularArrayRotation function below.

// Please store the size of the integer array to be returned in result_count pointer. For example,
// int a[3] = {1, 2, 3};
//
// *result_count = 3;
//
// return a;
//

//Brute Force - Get state of array after every rotation and store it in a different array
//1st optimisation - Get state of array after n rotations directly using idx = (idx+n)%size_of_array relation - Saves time
//2nd optimisation - Instead of using a different array to store every element of rotated array, just track idx of starting element after n rotations
//start = (0 + n)%size_of_array
//Then idx to report is diff ahead of start. If idx < start, then diff = idx + size_of_array - start, otherwise, diff = idx - start
//Then required element at rotated array[idx] = initial_array[diff]
//Saves both time and space
//Time complexity - O(1) for each query
//Space complexity - O(1) for each query

int* circularArrayRotation(int a_count, int* a, int k, int queries_count, int* queries, int* result_count) {
    int start = 0;
    start = k%a_count;
    int i;
    *result_count = queries_count;
    int *result = (int *)malloc(sizeof(int)*queries_count);
    int l = 0;
    for(i=0;i<queries_count;i++)
    {
        int diff;
        if(queries[i]<start)
        {
            diff = queries[i]+a_count-start;
        }
        else
        {
            diff = queries[i] - start;
        }
        result[l++]=a[diff];
    }
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nkq = split_string(readline());

    char* n_endptr;
    char* n_str = nkq[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* k_endptr;
    char* k_str = nkq[1];
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    char* q_endptr;
    char* q_str = nkq[2];
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    char** a_temp = split_string(readline());

    int* a = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* a_item_endptr;
        char* a_item_str = *(a_temp + i);
        int a_item = strtol(a_item_str, &a_item_endptr, 10);

        if (a_item_endptr == a_item_str || *a_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(a + i) = a_item;
    }

    int a_count = n;

    int* queries = malloc(q * sizeof(int));

    for (int i = 0; i < q; i++) {
        char* queries_item_endptr;
        char* queries_item_str = readline();
        int queries_item = strtol(queries_item_str, &queries_item_endptr, 10);

        if (queries_item_endptr == queries_item_str || *queries_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(queries + i) = queries_item;
    }

    int queries_count = q;

    int result_count;
    int* result = circularArrayRotation(a_count, a, k, queries_count, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

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

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
