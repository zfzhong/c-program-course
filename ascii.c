#include<stdio.h>
#include<stdlib.h>

int ascii()
{
    char a = 'A'; // the 8 bits of this meory is: '0100 0001'
    char d = 'd'; // 
    char e = 'e'; // 
    char n = 'n'; // 
    printf("%c%c%c%c\n", a,d,e,n);
    
    printf("ASCII %c: %d\n", a, a);
    printf("ASCII %c: %d\n", d, d);

    int s = sizeof(a); // 'int' data type: 4 bytes
    printf("ASCII %c size: %d\n", a, s);

    int x = 0;
    int xs = sizeof(x);
    printf("Integer %d size: %d\n", x, xs);

    return 0;
}

int array() 
{
    /* define an array of char */
    char name [] = {'A', 'd', 'e', 'n', ' ', '\0'};
    
    for(int i=0; i<6; ++i)
    {
        printf("%c, %d\n", name[i], name[i]); // name[0]: 'A'
    }

    printf("%s\n", name);
    
    return 0;
}

int main() 
{
    ascii();
    array();

    return 0;
}
