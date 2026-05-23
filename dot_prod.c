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

   int total = 0;
   int len = la < lb ? la : lb;

   for (int i=0; i<len; ++i)
   {
        total += va[i] * vb[i];
   }

   return total;
}

int get_vector(int *v, char *buf)
{
    /* parse a row of data, and keep the values 
     * into a vector/array.
     * 
     * - buf: row of data (string)
     * - v: the array to keep values
     */

    int len = 0;

    // tokenize the row
    char * token = strtok(buf, ",\n");
    while(token != NULL)
    {
        v[len] = atoi(token);
        len += 1;

        token = strtok(NULL,",\n");
    }
 
    return len;
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
    while (p != NULL)
    {   
        // 1) parse the first row
        int va[100]; // vector a
        int la = get_vector(va, buf);
        print_array(va, la);

        // 2) read/parse the 2nd row    
        p = fgets(buf, sizeof(buf), fp);

        // stop if no 2nd row  
        if (p == NULL) break;
 
        int vb[100]; // vector b
        int lb = get_vector(vb, buf); 
        print_array(vb, lb);

        // 3) calculate the dot product (contraction)
        int res = contra(va, la, vb, lb);
        printf("the inner prod: %d\n", res);

        // 4) continue to read more rows
        p = fgets(buf, sizeof(buf), fp);
    }

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


