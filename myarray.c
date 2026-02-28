#include<stdio.h>
#include "myarray.h"

int sort_array(int *a, int len)
{
    for(int i=0; i<len-1; ++i) 
    {
        find_min_and_swap(a+i, len-i);
    }

    return 0;
}

int print_array(int *a, int len)
{
    for(int i=0; i<len; ++i)
    {
       printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}


int find_min_and_swap(int *a, int len)
{
    int j = 0; //location
    int m = a[0]; //min value

    for(int i=1; i<len; ++i)
    {
        if(a[i]<m) 
        {
            m = a[i];
            j = i;
        }
    }

    //printf("min value:%d\n", m);
    //printf("location:%d\n", j); 

    //swap the value of a[j] with a[0]
    // m = a[j];
    a[j] = a[0];
    a[0] = m;

    return 0;
}

