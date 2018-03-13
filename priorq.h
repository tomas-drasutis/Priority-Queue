#include "pqueuet.h"
typedef struct LinkedList
{
    UserDataType data;
    struct LinkedList *next;
    int priority;

} tNode;

typedef struct HeadArray
{
    int name;
    struct HeadArray *next;
    tNode *head;

} tArray;

int Create(tArray **arrayHead, int pQname);
void Insert(tArray *listHead, UserDataType variable, int priority);
int Remove(tArray *listHead, UserDataType *variable);
int Peek(tArray *listHead, UserDataType *variable, int *priority);
int IsEmpty(tArray *listHead);
int Delete(tArray **arrayHead, tArray *listHead);
void PrintList(tArray *listHead);
int IsFull(tArray *listHead);
tArray *ReturnPQhead(tArray *arrayHead, int pQname);
void JoinPqueues(tArray **listHead, tArray **headToJoin);

