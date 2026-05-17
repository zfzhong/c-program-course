#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "myarray.h"

int contra(int *va, int la, int *vb, int lb)
{
  /* va: 1 2 3 4 5 7 8
   * vb: 2 4 5 7 0
   * result: 1*2 + 2*4 + 3*5 + 4*7 + 5*0
   */

   result =  0;

   return result;
}


int read_file(char * filename)
{
    FILE *fp = fopen(filename, "r");

    // always check to make sure opening file success
    if (fp == NULL) 
    {
        /* if open file failed, just return */
        printf("Error: open file failed.\n");
        return 1;
    }

    char buf[255];

    // read the first row
    char *p = fgets(buf, sizeof(buf), fp);
       
    int va[100]; // vector a
    int la = 0;  // length of a

    // tokenize the first row
    char * token=strtok(buf, ",\n");
    while(token!=NULL)
    {
        va[la] = atoi(token);
        la += 1;

        token=strtok(NULL,",\n");
    }
 
    printf("First vector, %d elements:\n", la);
    print_array(va, la);
    
    p = fgets(buf, sizeof(buf), fp);
   
    fclose(fp);
    return 0;
}


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Please input filename!\n");
        return 1;
    }

    char * filename = argv[1];
    read_file(filename);

    return 0;
}


