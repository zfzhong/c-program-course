#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please input a comma-separated array and a number!\n");
        return 1;
    }
   

    int n = strlen(argv[1]);
    int comma_count = 0;
    for (int i=0; i<n; ++i)
    {
        if (argv[1][i] == ',')
        {
            comma_count += 1;
        }
    }


    int length = comma_count + 1;
    
    // allocate memory for the array of integers
    int *a = (int *) malloc(length * 4);
    
    // put the first number into a[0]
    a[0] = atoi(&argv[1][0]);

    int j = 1;

    for (int i=0; i<n; ++i)
    {
        if (argv[1][i] == ',')
        {
            a[j] = atoi(&argv[1][i+1]);
            j += 1;
        }
    }

    print_array(a, length);
    sort_array(a, length);    
    print_array(a, length);


    return 0;
}
