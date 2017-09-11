#include <stdio.h>
#include <stdlib.h>
//两个有序链表序列的合并
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
void Attach(int data, List *Rear) {
    List L;
    L=(List)malloc(sizeof(struct Node));
    L->Data = data;
    L->Next = NULL;
    (*Rear)->Next = L;
    *Rear = L;
}
List Read(){
    int N,data;
    List L,Rear,t;
    scanf("%d",&N);
    L=(List)malloc(sizeof(struct Node));
    L->Next = NULL;
    Rear = L;
    while (N--) {
        scanf("%d",&data);
        Attach(data,&Rear);
    }
    t=L;L=L->Next;free(t);
    return L;

}
void Print( List L ){
    if (!L){
        return;
    }
    if (L->Next== NULL){
        printf("NULL\n");
        return;
    }
    int flag = 0;
    while(L){
        if(!flag){
            flag = 1;
        } else {
            printf(" ");
        }
        printf("%d",L->Data);
        L=L->Next;
    }
    printf("\n");
}

//清空链表
int ClearList(List L)
{
    List p,q;
    if(L==NULL)
        return 0;
    p=L->Next;
    while(p!=NULL)
    {
        q=p->Next;
        free(p);
        p=q;
    }
    L->Next=NULL;
    return 1;
}

List Merge( List L1, List L2 ){
    List L,Rear,t;
    L=(List)malloc(sizeof(struct Node));
    L->Next = NULL;
    Rear = L;

    List P1 = L1;
    List P2 = L2;
    int sum;
    while(P1&&P2){
        if (P1->Data<P2->Data) {
            Attach(P1->Data,&Rear);
            P1 = P1->Next;
        } else if(P1->Data>P2->Data) {
            Attach(P2->Data,&Rear);
            P2 = P2->Next;
        } else {
            sum = P1->Data+P2->Data;
            if (sum) Attach(P1->Data,&Rear);
            P1=P1->Next;
            P2=P2->Next;
        }
    }
    for(;P1;P1=P1->Next) {Attach(P1->Data,&Rear);};
    for(;P2;P2=P2->Next) {Attach(P2->Data,&Rear);};

    t=L;L=L->Next;free(t);

//    ClearList(L1);
//    ClearList(L2);
    return L;
}