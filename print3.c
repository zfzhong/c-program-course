#include<stdio.h>
#include<stdlib.h>

void print3(int *arr, int n, int factor)
{
    // print numbers at index 3,6,9,...
    for (int i=0; i<n; ++i)
    {   
        if ((i+1)%3 == 0)
        {
            printf("%d ", arr[i]*factor); // printf() is from <stdio.h>
        }
    }
    printf("\n"); // print linebreak
}

int main(int argc, char *argv[])
{
    // check the input numbers, if the user doesn't
    // input numbers, we prompt to remind him/her.
    if (argc < 2)
    {
        printf("Input some integers:\n");
        return 1;
    }

    // get the total count of input numbers
    int n = argc - 1;

    // allocate memory space to store the input numbers
    // malloc() is from <stdlib.h>
    // the memory space is allocated from heap
    int *arr = (int *) malloc(sizeof(int) * n); 

    // copy the numbers from input arguments space to
    // the space allocated
    for (int i=0; i<n; ++i)
    {
        arr[i] = atoi(argv[i+1]);
    }

    print3(arr, n, 1);
    print3(arr, n, 3);

    // free the memrory space (from heap)
    free(arr);
    arr = NULL;

    return 0;
}
