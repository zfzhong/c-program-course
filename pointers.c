#include<stdio.h>
#include<stdlib.h>

int main()
{
    /* allocate a 16-byte space, convert it to integer blocks */
    int *pti = (int *) malloc(16);

    /* convert the 'int *' type pointer to a 'void *' type pointer */    
    void *p1 = (void *) pti;
    printf("%p\n", p1);
   
    /* move the pointer to next block, and print the address */
    ++ pti; // the address increase by 4
    printf("%p\n", (void *) pti);


    char *ptc = (char *) malloc(16);
    printf("%p\n", (void *)ptc);
 
    ++ ptc; // the address increase by 1
    printf("%p\n", (void *)ptc);
    

    return 0;
}


