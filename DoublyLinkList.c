#include <stdio.h>
#include <malloc.h>
#define TIMES 3
typedef struct LNode{
    int data;
    struct LNode *next,*prior;
}LNode, *LinkList;
void PrintList(LinkList p){
    LinkList s = p;
    for (;p->next!=s;) {
        p= p->next;
        printf( "%d",p->data);
    }
}
//˫��ѭ�������ͷ�巨����
void CreateHeadDoublyList(LinkList *L,int times){
    //����ͷ�ڵ㲢��ʼ��
    (*L)= (LinkList) malloc(sizeof(LinkList));
    (*L)->next = (*L);
    (*L)->prior = (*L);
    for (int i = 0; i < times; ++i) {
        LinkList s;
        s = (LNode*) malloc(sizeof(LNode));
        scanf("%d",&s->data);
        s->prior = (*L);
        s->next = (*L)->next;
        (*L)->next = s;
    }
    PrintList(*L);

}
//˫��ѭ������İ���ɾ������
void DeleteDoubllyList(LinkList *L,int index){
    LinkList s,j,k;
    s= *L;
    int i = 0;
    for (; s && i < index; ++i) {
        s=s->next;
    }
    if(!s || i>index){ printf("����������ݷǷ�"); return;}
    j = s->next;
    k = s->prior;
    j->prior = k;
    k->next = j;
    free(s);

}
//˫��ѭ������İ���ֵɾ������
void DeleteDoubllyList2(LinkList *L,int data){
    LinkList s,j,k;
    s= *L;
    int i = 0;
    for (; s && s->data!=data; ++i) {
        s=s->next;
    }
    if(!s || s->data!=data){ printf("����������ݷǷ����ѯδ��"); return;}
    j = s->next;
    k = s->prior;
    j->prior = k;
    k->next = j;
    free(s);

}
//˫��ѭ������Ĳ������
void InsertDoubllyList(LinkList *L,int index,int data){
    LinkList s,j,p;
    p = (LNode *) malloc(sizeof(LNode));
    s= *L;
    int i = 0;
    for (; s && i < index; ++i) {
        s=s->next;
    }
    if(!s || i>index){ printf("����������ݷǷ�"); return;}
    j = s->next;
    s->next = p;
    p->prior = s;
    p->next = j;
    j->prior = p;
    p->data = data;

}
//˫��ѭ�������β�巨����
void CreateTailDoublyList(LinkList *L,int times){
    //����ͷ�ڵ㲢��ʼ��
    (*L)= (LinkList) malloc(sizeof(LinkList));
    (*L)->next = (*L);
    (*L)->prior = (*L);
    //����β�ڵ�
    LNode* j= (LinkList) malloc(sizeof(LinkList));
    j = (*L);
    for (int i = times; i > 0 ; --i) {
        LinkList s;
        s = (LNode *) malloc(sizeof(LNode));
        scanf("%d", &s->data);
        j->next = s;
        s->prior = j;
        s->next = (*L);
        j=s;
    }
    PrintList(*L);
}

int main(){
    LinkList p;
    CreateTailDoublyList(&p,TIMES);
    InsertDoubllyList(&p,2,999);
    DeleteDoubllyList2(&p,2);
    return 0;
}