#include<stdio.h>
#include<stdlib.h>

int find_max(int n, int arr[])
{
    /* use 'curr_max' to keep the current max value */
    int curr_max = arr[0];
 
    for (int i = 1; i < n; ++i)
    {
        int a = arr[i];

        if (a > curr_max) { curr_max = a; }
    }

    return curr_max;
}

int main(int argc, char *argv[])
{
    if (argc < 2) 
    {
        printf("Input some integers, like this:\n");
        printf("%s 1 2 5 ...\n", argv[0]);
        return 1;
    }

    if (argc > 21) 
    {
        printf("Dont input more than 20 integers!\n");
        return 1;    
    }

    int n = argc - 1; // the number of integers
   
    /* Use malloc() allocate memory space for the array of integers.
     * Each integer occupies 4 bytes, so totally we allocate 4*n bytes.
     */
    int *arr = (int *) malloc(4 * n);

    for (int i = 0; i < n; ++i)
    {
        // convert an array of 'char' into an array of 'int'
        arr[i] = atoi(argv[i+1]);
    }

    int s = find_max(n, arr);

    printf("The max value is: %d\n", s);

    // release the memory space
    free(arr);
    arr = NULL; // NULL is equivalent to '\0', which has ascii code is 0.

    return 0;
}

