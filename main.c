#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 20

struct hashTable
{
    int data;
    int key;
};
struct hashTable *item;
struct hashTable *array[SIZE];

void search(int key)
{
    int hashIndex=key%SIZE;
    if (array[hashIndex]==NULL)
    {
        printf("element not found\n");
    }
    while(array[hashIndex]!=NULL)
    {
        if(array[hashIndex]->key==key)
        {
            printf("element found=%d\n",array[hashIndex]->data);
        }
        hashIndex++;
        
    }
    
}
void insert(int key,int data)
{
    struct hashTable *item=(struct hashTable*)malloc(sizeof(struct hashTable));
    item->key=key;
    item->data=data;
    int hashIndex=key%SIZE;
    while(array[hashIndex]!=NULL)
    {
       
        hashIndex++;
        hashIndex=hashIndex%SIZE; /* This commands helps when the index got incremented more than the size of array. In this example if hashIndex becomes 20 it can be 0 after this .*/
    }
    array[hashIndex]=item;   
}
void delete(int key)
{
    int hashIndex=key%SIZE;
    while(array[hashIndex]!=NULL)
    {
        if(array[hashIndex]->key==key)
        {
            array[hashIndex]=NULL;
        }
        hashIndex++;
    }
}

void display()
{
    int i=0;
    for(i=0;i<SIZE;i++)
    {
        if(array[i]!=NULL)
        {
         printf("[Key =%d,Value =%d]",array[i]->key,array[i]->data);   
        }
        else
            printf("[ ~~ ]");
    }
    printf("\n");
}

int main()
{
    
    insert(2,20);
    insert(4,42);
    insert(2,13);
    insert(6,12);
    display();
    search(7);
    delete(6);
    display();
    exit(0);
}
