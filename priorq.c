#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pqueuet.h"
#include "priorq.h"

int Create(tArray **arrayHead, int pQname)
{
    tArray *newTemp=(tArray*)malloc(sizeof(tArray));
    tArray *tempHead=(*arrayHead);
    newTemp->next=NULL;
    newTemp->head=NULL;

    if((*arrayHead)==NULL)
    {
        (*arrayHead)=newTemp;
        (*arrayHead)->name=pQname;
        return 1;
    }
    else
    {
        while(tempHead->next!=NULL)
        {
            tempHead=tempHead->next;
        }
        tempHead->next=newTemp;
        newTemp->name=pQname;
    }
    return 1;
}
void Insert(tArray *listHead, UserDataType variable, int priority)
{
    tNode *newTemp=(tNode*)malloc(sizeof(tNode));
    tNode *tempHead=listHead->head;

    newTemp->data=variable;
    newTemp->next=NULL;
    newTemp->priority=priority;

    if(listHead->head==NULL)
    {
        listHead->head=newTemp;
        return;
    }
    if(listHead->head->priority<newTemp->priority)
    {
        newTemp->next=listHead->head;
        listHead->head=newTemp;
    }
    else
    {
        for(tempHead=listHead->head;tempHead;tempHead=tempHead->next)
        {
            if((tempHead->priority>=newTemp->priority)&&tempHead->next==NULL)
            {
                tempHead->next=newTemp;
                break;
            }
            if((tempHead->priority>=newTemp->priority)&&tempHead->next->priority<newTemp->priority)
            {
                newTemp->next=tempHead->next;
                tempHead->next=newTemp;
                break;
            }
        }
    }
}
int Remove(tArray *listHead, UserDataType *variable)
{
    if(listHead->head==NULL)
    {
        return 0;
    }

    tNode *temp=listHead->head;
    *variable=temp->data;

    if(listHead->head->next==NULL)
    {
        listHead->head=NULL;
    }
    else
    {
        listHead->head=listHead->head->next;
    }
    free(temp);
    return 1;

}
int Peek(tArray *listHead, UserDataType *variable, int *priority)
{
    tNode *temp=listHead->head;
    if(listHead->head==NULL)
    {
        return 0;
    }
    else
    {
        *variable=temp->data;
        *priority=temp->priority;
        return 1;
    }
}
int IsEmpty(tArray *listHead)
{
    if(listHead->head==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Delete(tArray **arrayHead, tArray *listHead)
{
    tNode *temp;
    while(listHead->head)
    {
        temp=listHead->head;
        listHead->head=(listHead->head)->next;
        free(temp);
    }
    if(*arrayHead==listHead)
    {
        (*arrayHead)=(*arrayHead)->next;
        free(listHead);
    }
    else
    {
        tArray *temp=(*arrayHead);
        while(temp->next!=listHead)
        {
            temp=temp->next;
        }
        temp->next=listHead->next;
        free(listHead);
    }
    return 1;
}
void PrintList(tArray *listHead)
{
    tNode *temp=listHead->head;

    if(temp==NULL)
    {
        printf("PQ is empty");
        return;
    }

    while(temp->next!=NULL)
    {
        printf(Placeholder" ", temp->data);
        temp=temp->next;
    }
    printf(Placeholder" ", temp->data);
}
int IsFull(tArray *listHead)
{
    int message;

    tNode *temp=(tNode*)malloc(sizeof(tNode));
    if (temp==NULL)
    {
        message=1;
    }
    else
    {
        message=0;
    }
    free(temp);

    return message;
}
tArray *ReturnPQhead(tArray *arrayHead, int pQname)
{
    tArray *temp=arrayHead;
    while(temp)
    {
        if(temp->name==pQname)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
void JoinPqueues(tArray **listHead, tArray **headToJoin)
{
    tNode *tempHead=(*listHead)->head;
    tNode *i, *j;
    UserDataType tempVariable;
    int tempPriority;

    while(tempHead->next!=NULL)
    {
        tempHead=tempHead->next;
    }

    tempHead->next=(*headToJoin)->head;
    (*headToJoin)->head=NULL;

    for(i=(*listHead)->head;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->priority < j->priority)
            {
                tempVariable=i->data;
                tempPriority=i->priority;

                i->data=j->data;
                i->priority=j->priority;

                j->data=tempVariable;
                j->priority=tempPriority;
            }
        }
    }
}

