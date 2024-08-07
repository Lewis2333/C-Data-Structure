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
//按序列查找数据
void ResearchIndex(LinkList *L,int index){
    int i=0;

    LNode *p;
    p = *L;

    for (;p && i < index; ++i) {
        p=p->next;
    }
    if(!p||i>index){
        printf("您输入的位置不合法！");
        return;
    }
    printf("该位置的数据是%d",p->data);
}
//按值查找序列
void ReaseachData(LinkList *L,int data){
    int i = 0;
    LNode *p;
    p = *L;
    for (;p && p->data != data ; ++i) {
        p=p->next;
    }
    if(p){
        printf("该数据的位置是%d",i);
        return;
    }else{
        printf("未找到数据或序列非法");
        return;
    }

}
//插入数据
void InsertData(LinkList *L,int index,int data){
    LinkList p;
    p = (*L);
    int i =0;
    for (;p && i < index - 1; ++i) {
        p = p->next;
    }
    if(!p || i>index){
        printf("您输入的位置不合法！");
        return;
    }
    LNode *s = (LinkList) malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = data;
    printf("插入成功！");
    PrintList(*L);

}
//删除数据
void DeleteData(LinkList *L,int index){
    int i = 0;
    LNode *s;
    s=(*L);
    for (;s->next && i < index -1; ++i) {
        s =s->next;
    }
    if(!(s->next) || i> index - 1){
        printf("您输入的位置不合法！");
        return;
    }
    LNode *p = (LinkList) malloc(sizeof(LNode));
    p->next = s->next->next;
    free(s->next);
    s->next = p->next;
    printf("删除成功！");
    PrintList(*L);
}
//头插法初始化链表
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
//尾插法初始化链表
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
    InsertData(p,2,999);
    DeleteData(p,2);
    ResearchIndex(p,1);
    ReaseachData(p,1);
    return 0;
}
