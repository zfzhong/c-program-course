#include<stdio.h>
#include<stdlib.h>


int get_sum(int n, int arr[])
{
    int curr_sum = arr[0];

    for (int i = 1; i < n; ++i)
    {
        curr_sum = curr_sum + arr[i];
    }

    return curr_sum; 
}


int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("Please input some numbers, like this:\n");
        printf("%s 1 2 3\n", argv[0]);
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
    /* do your work to put arguments into an array */


    int s = get_sum(n, arr);
    printf("The sum is: %d\n", s);

    // release the memory
    free(arr);
    arr = NULL;


    return 0;
}


