#include <stdio.h>
#include <malloc.h>
#define TIMES 3
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;
void PrintList(LinkList p){
    LinkList s = p;
    for (;p->next!=s;) {
        p= p->next;
        printf( "%d",p->data);
    }
}
//Ѱ�ҳ�ʼ��β�ڵ�
LNode* ReaserchTailLNode(LinkList Tc){
    for (;Tc->next!=NULL;) {
        Tc = Tc->next;
    }
    return Tc;
}
//Ѱ��ѭ�������β�ڵ�
LNode* ReaserchTailLNode2(LinkList Tc){
    LNode *s = Tc->next;
    for (;s->next!=Tc;) {
        s = s->next;
    }
    printf("β�ڵ��ǣ�%d",s->data);
    return s;
}
//����ѭ������ĺϲ�
void Connect(LinkList Ta, LinkList Tb){
    //Ѱ��β�ڵ�
    LinkList r1= ReaserchTailLNode2(Ta);
    LinkList r2= ReaserchTailLNode2(Tb);
    LinkList s= r1->next;
    r1->next = r2->next->next;
    free(r2->next);
    r2->next = s;
    PrintList(Ta);
}

//����ѭ������ͷ�巨�Ľ���
void CreateCirculateLinkList(LinkList *p,int times){
    //����ͷ�ڵ�
    (*p)= (LinkList) malloc(sizeof(LinkList));
    (*p)->next = (*p);
    LNode *s;
    //��ʼ������
       for (int i = 0; i < times; ++i) {
        //�����½ڵ�
           s = (LNode *) malloc(sizeof (LNode));
           s->next = (*p)->next;
           scanf("%d",&s->data);
           (*p)->next = s;
    }
    PrintList(*p);

}
int main(void) {
    LinkList p,j;
    CreateCirculateLinkList(&p,TIMES);
    CreateCirculateLinkList(&j,TIMES);
    Connect(p,j);
    return 0;
}
