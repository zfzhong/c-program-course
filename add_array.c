#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add(int a[], int len1, int b[], int len2, int r[], int len3)
{
    // p[]: keep the gregrouping digits
    int *p = (int *) malloc(len3 * 4);

    // initialize to all 0s
    for (int i=0; i<len3; ++i)
    {
        p[i] = 0;
    }

    /* Add the digits in the shorter array:
     * a[] = {1,2,3,4,5,6}
     * b[] = {9,7,5}
     * len = 3
     * r[] = {0,0,9}
     */
    int len = (len1 < len2) ? len1 : len2;

    for (int i=0; i<len; ++i)
    {
        int t = a[i] + b[i] + p[i];
        if (t >= 10)
        {
            p[i+1] = 1; // regroup 1
        }
        
        r[i] = t % 10; // unit digit of t
    }
    
    // x: point to the longer array 
    int *x = (len1 > len2) ? a : b;

    /* Work on the rest of the longer array: 
     * add each digit with the regrouping digit, if any.
     */
    for (int i=len; i<len3-1; ++i)
    {
        int t = x[i] + p[i];
        if (t >= 10) 
        {
            p[i+1] = 1;
        }

        r[i] = t % 10;
    } 
   
    // Deal with the highest digit
    r[len3-1] = p[len3-1];

    free(p); p = NULL;

    return 0;
}

int format_print(int a[], int len, int max_len)
{ 
    /* if a[] = [3,4,5], which means the number is 543.
     * len = 3; max_len = 10;
     * the format and print result: "       543".
     */
    char buffer[8];   
    sprintf(buffer, "%%%dd", max_len - len + 1);
    printf(buffer, a[len-1]);

    for (int i=len-2; i>=0; --i)
    {
        printf("%d",a[i]);
    }
    printf("\n");
    
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Please input 2 numbers!\n");
        return 1;
    }

    // 1) copy argv[1] to a[]
    int length1 = strlen(argv[1]);
    int *a = (int *) malloc(length1 * 4);
    
    for (int i=0; i<length1; ++i)
    {
        /* argv[1][] = {'3','4','5','6'}
         * a[] = {6, 5, 4, 3}
         *
         * a[0] = argv[1][3];
         * a[1] = argv[1][2];
         */
        a[i] = argv[1][length1-1-i] - '0';
    }
    
    // 2) copy argv[2] to b[]
    int length2 = strlen(argv[2]);
    int *b = (int *) malloc(length2 * 4);

    for (int i=0; i<length2; ++i)
    {
        /* argv[2] = {'4', '3', '0', '9'}
         * b[] = {9, 0, 3, 4}
         */
        b[i] = argv[2][length2-1-i] - '0';
    }

    // length3: larger of length1 and length2, and plus 1.
    int length3 = (length1 > length2) ? length1+1 : length2+1;

    int *r = (int *) malloc(length3 * 4);
    add(a, length1, b, length2, r, length3);

    printf("The calculation:\n");

    format_print(a, length1, length3+1);
    printf("+ ");
    format_print(b, length2, length3-1);

    for(int i=0; i<=length3; ++i) { printf("-"); }   
    printf("\n");

    format_print(r, length3, length3+1);

    free(a); a = NULL;
    free(b); b = NULL;
    free(r); r = NULL;

    return 0;
}

