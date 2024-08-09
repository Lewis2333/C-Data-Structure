#include <stdio.h>
#include <malloc.h>
#define TIMES 3
/*
 * 链表应用之 查找两个链表的最大项
 */
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
//尾插法创建初始链表
void CreateInitLinkList(LinkList *L,int times){
    *L = (LinkList) malloc(sizeof(LNode));
    //创建尾节点
    LNode *s;
    s = *L;
    for (int i = 0; i < times; ++i) {
        LinkList j;
        j = (LNode*)malloc(sizeof(LNode));
        j->next = NULL;
        s->next = j;
        s = j;
        scanf("%d",&j->data);
    }
   // PrintList(*L);
}
//获取链表的长度
int GetLinkListLenth(LinkList a){
    int i = 0;
    for (;a->next!=NULL;) {
        a = a->next;
        i++;
    }
    return i;
}
//获取链表的数值
int GetLinkListData(LinkList L,int index){
    int i = 0;
    for (;L->next&& i < index; ++i) {
        L=L->next;
    }
    return L->data;
}
//获取两个链表的最大项
LinkList GetMax(LinkList *a,LinkList *b){
    //初始化新链表
    int i = 0;
    LinkList c,p;
    (c) = (LNode*) malloc(sizeof(LNode));
    p=c;
    int j,k;
    j = GetLinkListLenth(*a);
    k = GetLinkListLenth(*b);
    int min = (j<=k)?j:k;
    for (;(*a)->next && (*b)->next &&i < min; ++i) {
           if(GetLinkListData(*a,i) > GetLinkListData(*b,i)){
                p->next = (*a)->next;
                p = (*a)->next;
            }else{p->next = (*b)->next;p = (*b)->next;}
                (*a) = (*a)->next;
                (*b) = (*b)->next;
                if(i>=min){if(*a){
                        p->next->next = (*a);
                    }else if(*b){
                        p->next->next = (*b);
                    }}
        }

    PrintList(c);
    return c;
}


int main(void) {
    LinkList L,K;
    CreateInitLinkList(&L,TIMES);
    CreateInitLinkList(&K,TIMES+1);
    GetMax(&L,&K);
    return 0;
}
