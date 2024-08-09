#include <stdio.h>
#include <malloc.h>
#define TIMES 3
/*
 * ����Ӧ��֮ ������������������
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
//β�巨������ʼ����
void CreateInitLinkList(LinkList *L,int times){
    *L = (LinkList) malloc(sizeof(LNode));
    //����β�ڵ�
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
//��ȡ����ĳ���
int GetLinkListLenth(LinkList a){
    int i = 0;
    for (;a->next!=NULL;) {
        a = a->next;
        i++;
    }
    return i;
}
//��ȡ�������ֵ
int GetLinkListData(LinkList L,int index){
    int i = 0;
    for (;L->next&& i < index; ++i) {
        L=L->next;
    }
    return L->data;
}
//��ȡ��������������
LinkList GetMax(LinkList *a,LinkList *b){
    //��ʼ��������
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
