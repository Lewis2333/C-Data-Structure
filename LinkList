#include <stdio.h>
#include <malloc.h>
#define TIMES 3
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;
void PrintList(LinkList p){
    for (;p->next!=NULL;) {
        p= p->next;
        printf( "%d",p->data);
    }
}
void CreatList_Head(LinkList *p,int times){
    //创建头节点
    *p = (LinkList) malloc(sizeof(LNode));
    (*p)->next = NULL;

    for (int i = times; i > 0; --i) {
        //创建新节点
        LNode *j= (LNode*) malloc(sizeof(LNode));
        scanf("%d",&j->data);
        j->next = (*p)->next;
        (*p)->next = j;
    }
    printf("头插法成功！");
    PrintList(*p);
}
void CreatList_Tail(LinkList *L,int times){
    //创建头节点
    LinkList p;
    *L = (LinkList) malloc(sizeof(LNode));
    //创建尾指针
    p=*L;
    for (int i = times; i > 0 ; --i) {
        //创建新节点
        LNode * j = (LNode*) malloc(sizeof (LNode));
        scanf("%d",&j->data);
        j->next = NULL;
        p->next = j;
        p = j;
    }
    printf("尾插法成功！");
    PrintList(*L);
};

int main() {
    LinkList p;
    CreatList_Head(&p, TIMES);
    CreatList_Tail(&p,TIMES );
    return 0;
}
