#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

typedef struct label
{
    char *name;
    int addr;
    struct label *next;
}label;

struct label *head;

void insertLabel(char *name, int addr)
{
    struct label *temp = (struct label*) malloc(sizeof(struct label));
    temp->name = name;
    temp->addr = addr;
    temp->next = head;
    head = temp;
}

int getLabelAddress(char *name)
{
    struct label *temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
        {
            return temp->addr;
        }
        temp = temp->next;
    }
    return -1;
}