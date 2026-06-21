#include "stdio.h"

#include "stdlib.h"

#define MAX_VERTEX_NUM 20     /*最大顶点数设为20*/

#define MAX_EDGB_NUM 20         //最大边数为20*，这个是邻接表所设计的最大连接边数。

typedef char Vertex_type[10]; /*顶点类型设为字符型*/
typedef int Edge_type;        /*边的类型设为整型*/
typedef struct node        /*边表结点*/
{
    int adjvex;        /*邻接点域*/
    int weight;
    struct node *next; /*指向下一个邻接点的指针域*/
}Edge_node;

typedef struct   /*顶点表结点*/
{
    Vertex_type vertex;  /*顶点域*/
    Edge_node *firstedge;/*边表头指针*/
}Vertex_node;

typedef struct
{
    Vertex_node   adjlist[MAX_VERTEX_NUM]; /*邻接表*/
    int n,m;  /*顶点数和边数*/
}Lgraph;


void create_graph(Lgraph *g)
{
    int i,j,k,w;
    Edge_node *p,*q,*t;
    printf("请输入顶点数和边数(输入格式为：顶点数  边数，空格隔开):\n");
    scanf("%d%d",&(g->n),&(g->m));
    getchar();
    printf("请输入顶点信息（输入格式为:顶点号<回车>):\n");      
    for(i=0;i<g->n;i++)
    {
        printf("\n 第%d个顶点:",i+1);/*顶点序号从1开始*/
        scanf("%s",g->adjlist[i].vertex);
        g->adjlist[i].firstedge=nullptr;
    }
    printf("\n请输入每条边对应的两个顶点的序号和权值(输入格式为:i j w,空格隔开):\n");
    for (k=0;k<g->m;k++)
    {
        printf("第%d条边：\n",k+1);
        scanf("%d %d %d",&i,&j,&w);
        if(i>=1 && i<=g->n && j>=1 && j<=g->n)//输入的边的顶点从1开始（不是从0开始！)
        {
            i--;
            j--;
        }
        else
        {
            printf("%d %d 边的顶点号输入有误，请重新输入！\n",i,j);
            k--;    continue;
        }

        p=(Edge_node *)malloc(sizeof(Edge_node));
        p->adjvex=j;
        p->weight=w;
        p->next=NULL;
        t=g->adjlist[i].firstedge;
        g->adjlist[i].firstedge=p;
        p->next=t;
        /*若建立有向图的邻接链表，下面的语句可省去*/
        q=(Edge_node *)malloc(sizeof(Edge_node));
        q->adjvex=i;
        q->weight=w;
        q->next=NULL;
        t=g->adjlist[j].firstedge;
        g->adjlist[j].firstedge=q;
        q->next=t;
    }
}



void dfs(Lgraph *g,int i,int visited[])

{

    int k;

    Edge_node *p;

    printf("visit vertex:%s\n",g->adjlist[i].vertex);/*访问顶点vi*/

    visited[i]=1;                    //标记vi已访问

    p=g->adjlist[i].firstedge;//取vi边表的头指针

    while(p)

    {

        k=p->adjvex;

        if(!visited[k])

            dfs(g,k,visited);

        p=p->next;

    }

}

int main()

{

    Lgraph *g;

    int visited[MAX_VERTEX_NUM];

    int x,i;

    g=(Lgraph *)malloc(sizeof(Lgraph));

    create_graph(g);

    for(i=0;i<MAX_VERTEX_NUM;i++)

        visited[i]=0;

    do

    {

        printf("请输入遍历首顶点序号：");//从1开始哦。

        scanf("%d",&x);

        printf("\n");

        if(x>=1 && x<=g->n)

        {

            x--;break;

        }

        else

        {

            printf("顶点号输入有误，请重新输入！\n");

        }      

    }while(1);

    dfs(g,x,visited);

    return 0;

}