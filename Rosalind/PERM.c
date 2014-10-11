#include "stdio.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int * my_alloc(long size) 
{
    int *temp = NULL;
    int i     = 0;
    
    temp = (int *)calloc(1, size);
 
    if (!temp) {
        printf("\nCalloc Error\n");
        exit(0);
    }

    for (i=1; i<=size; i++) {
         temp[i-1] = i;
    }

    return temp;
}

void printarr(int *arr, int len) 
{
    int i = 0;
 
    for (i = 0; i<len; i++) {
         printf("%d ",arr[i]);
    }

    printf("\n");

} 

void swap (int *a, int *b) 
{
    int temp = 0;
 
    temp = *a;
    *a   = *b;
    *b   = temp;

}

void permute(int *arr, int pos, int len)
{

    int i = pos;

    if (pos == len) {
        printarr(arr, len);
        return;
    }

    for (i=pos; i<len; i++) {
         swap(arr+pos, arr+i);
         permute(arr, i+1, len);
         swap(arr+pos, arr+i);
    }    
  
    return;
}

int main ()
{
    FILE         *fp  = NULL;
    int         size = 0;
    int         *arr = NULL;
    

    fp = fopen("rosalind_perm.txt","r");
    if (fp == NULL) {
        printf("\nError opening file\n");
        return 0;
    }

    fscanf(fp, "%d", &size);
    arr = my_alloc(size);
    permute(arr, 0, size);   
  
    return 0;
}
