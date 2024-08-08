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
//双向循环链表的头插法建立
void CreateHeadDoublyList(LinkList *L,int times){
    //创建头节点并初始化
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
//双向循环链表的按序删除操作
void DeleteDoubllyList(LinkList *L,int index){
    LinkList s,j,k;
    s= *L;
    int i = 0;
    for (; s && i < index; ++i) {
        s=s->next;
    }
    if(!s || i>index){ printf("你输入的数据非法"); return;}
    j = s->next;
    k = s->prior;
    j->prior = k;
    k->next = j;
    free(s);

}
//双向循环链表的按数值删除操作
void DeleteDoubllyList2(LinkList *L,int data){
    LinkList s,j,k;
    s= *L;
    int i = 0;
    for (; s && s->data!=data; ++i) {
        s=s->next;
    }
    if(!s || s->data!=data){ printf("你输入的数据非法或查询未果"); return;}
    j = s->next;
    k = s->prior;
    j->prior = k;
    k->next = j;
    free(s);

}
//双向循环链表的插入操作
void InsertDoubllyList(LinkList *L,int index,int data){
    LinkList s,j,p;
    p = (LNode *) malloc(sizeof(LNode));
    s= *L;
    int i = 0;
    for (; s && i < index; ++i) {
        s=s->next;
    }
    if(!s || i>index){ printf("你输入的数据非法"); return;}
    j = s->next;
    s->next = p;
    p->prior = s;
    p->next = j;
    j->prior = p;
    p->data = data;

}
//双向循环链表的尾插法建立
void CreateTailDoublyList(LinkList *L,int times){
    //创建头节点并初始化
    (*L)= (LinkList) malloc(sizeof(LinkList));
    (*L)->next = (*L);
    (*L)->prior = (*L);
    //创建尾节点
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