#include "stdlib.h"

#include "stdio.h"

#define MAX_VERTEX_NUM 20     /*最大顶点数设为20*/

typedef char Vertex_type[10]; /*顶点类型设为字符型*/

typedef int Edge_type;        /*边的类型设为整型*/

typedef struct

{

    Vertex_type vexs[MAX_VERTEX_NUM];       /*顶点表*/

    Edge_type edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  /*邻接矩阵，即边表*/

    int n,m;                                /*顶点数和边数*/

}Segraph;                                 /*Segragh是以邻接矩阵存储的图类型*/



void create_Segraph(Segraph *g)

{

    int i,j,k;

    printf("请输入顶点数和边数(输入格式为：顶点数  边数):\n");

    scanf("%d%d",&(g->n),&(g->m));

    printf("请输入%d个顶点名称:\n",g->n);  

    getchar();

    for(i=0;i<g->n;i++)

        scanf("%s",&(g->vexs));

    for(i=0;i<g->n;i++)

      for(j=0;j<g->n;j++)

        g->edges[i][j]=0;/*初始化邻接矩阵*/

    printf("请输入每条边对应的两个顶点的序号(输入格式为:i j):\n");

    for (k=0;k<g->m;k++)

    {

        scanf("%d %d",&i,&j);

        g->edges[i][j]=1;

    }

}

int main()

{

    Segraph *g;

    int i,j;

    g=(Segraph *)malloc(sizeof(Segraph));

    create_Segraph(g);

    for(i=0;i<g->n;i++)

    {

        printf("\n");

        for(j=0;j<g->n;j++)

            printf("%2d",g->edges[i][j]);

    }  

    return 0;

}