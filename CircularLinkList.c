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
//寻找初始化尾节点
LNode* ReaserchTailLNode(LinkList Tc){
    for (;Tc->next!=NULL;) {
        Tc = Tc->next;
    }
    return Tc;
}
//寻找循环链表的尾节点
LNode* ReaserchTailLNode2(LinkList Tc){
    LNode *s = Tc->next;
    for (;s->next!=Tc;) {
        s = s->next;
    }
    printf("尾节点是：%d",s->data);
    return s;
}
//单向循环链表的合并
void Connect(LinkList Ta, LinkList Tb){
    //寻找尾节点
    LinkList r1= ReaserchTailLNode2(Ta);
    LinkList r2= ReaserchTailLNode2(Tb);
    LinkList s= r1->next;
    r1->next = r2->next->next;
    free(r2->next);
    r2->next = s;
    PrintList(Ta);
}

//单向循环链表头插法的建立
void CreateCirculateLinkList(LinkList *p,int times){
    //创建头节点
    (*p)= (LinkList) malloc(sizeof(LinkList));
    (*p)->next = (*p);
    LNode *s;
    //初始化链表
       for (int i = 0; i < times; ++i) {
        //创建新节点
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
