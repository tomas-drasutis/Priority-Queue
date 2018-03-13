#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pqueuet.h"
#include "priorq.h"

int main()
{
    UserDataType variable;
    int a, priority, q, pQname;

    tArray *listHead=NULL;
    tArray *headToJoin=NULL;
    tArray *arrayHead=NULL;

    printf("0 - End program\n1 - Create PQ\n");
    printf("2 - Add element\n3 - Remove element\n4 - First elements data\n");
    printf("5 - Is PQ empty\n6 - Delete PQ");
    printf("\n7 - Print PQ\n8 - Is PQ full\n");
    printf("9 - Join queues");

    do
    {
        printf("\n\nEnter what to do: ");
        scanf("%d", &a);
        if(a>1&&a<9&&a!=0)
        {
            printf("With which PQ will you be working: ");
            scanf("%d", &pQname);
            listHead=ReturnPQhead(arrayHead, pQname);
            if(listHead==NULL)
            {
                printf("PQ doesn't exist");
                continue;
            }
        }
        switch(a)
        {
            case 0:
                break;
            case 1:
                printf("Enter PQ's name: ");
                scanf("%d", &pQname);
                listHead=ReturnPQhead(arrayHead, pQname);
                if(listHead!=NULL)
                {
                    printf("PQ already exists");
                    continue;
                }
                Create(&arrayHead, pQname);
                printf("PQ is created");
                break;
            case 2:
                printf("Enter element: ");
                scanf(Placeholder, &variable);

                printf("Enter its priority: ");
                scanf("%d", &priority);
                Insert(listHead, variable, priority);
                break;
            case 3:
                if((q=Remove(listHead, &variable))==1)
                    printf("Removed element: "Placeholder"\n", variable);
                else if(q==0)
                    printf("PQ is empty");
                break;
            case 4:
                if((q=Peek(listHead, &variable, &priority))==1)
                {
                    printf("First element: "Placeholder", it's priority: %d", variable, priority);
                }
                else if(q==0)
                    printf("First element doesn't have data");
                break;
            case 5:
                if((q=IsEmpty(listHead))==1)
                {
                    printf("PQ is empty");
                }
                else if(q==0)
                {
                    printf("PQ is not empty");
                }
                break;
            case 6:
                if(Delete(&arrayHead, listHead))
                    {printf("PQ deleted!");
                    continue;}
                else
                    printf("PQ wasn't deleted!");
                break;
            case 7:
                PrintList(listHead);
                break;
            case 8:
                if((q=IsFull(listHead))==1)
                {
                    printf("PQ is full!!!");
                }
                else if(q==0)
                {
                    printf("PQ is not full");
                }
                break;
            case 9:
                printf("Enter name of first PQ: ");
                scanf("%d", &pQname);
                listHead=ReturnPQhead(arrayHead, pQname);

                printf("Enter name of PQ to be joined: ");
                scanf("%d", &pQname);
                headToJoin=ReturnPQhead(arrayHead, pQname);
                if(listHead==NULL||headToJoin==NULL)
                {
                printf("Atleast 1 of these PQ's doesn't exist!!");
                continue;
                }
                JoinPqueues(&listHead, &headToJoin);
                Delete(&arrayHead, headToJoin);
                break;
            default:
                printf("Unknown command!");
                break;
        }
    }while(a!=0);

    return 0;
}
