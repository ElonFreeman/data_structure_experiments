#include <stdio.h>

#include <stdlib.h>

struct Arcnode

{

    int adjvex;

    struct Arcnode *next;

};

struct Vertexnode

{

    int in;

    char vertex;

    struct Arcnode *firstedge;

};

#define Maxsize 20

typedef struct

{

    struct Vertexnode adjlist[Maxsize];

    int vertexnum;

    int arcnum;

} ALgraph;

void ALgraph_init(ALgraph *G, char a[], int n, int e)

{

    G->vertexnum = n;

    G->arcnum = e;

    int i, j, k, m, in;

    for (i = 0; i < G->vertexnum; i++)

    {

        G->adjlist[i].vertex = a[i];

        G->adjlist[i].firstedge = NULL;

    }

    for (i = 0; i < G->vertexnum; i++)

    {

        scanf("%d", &in);

        G->adjlist[i].in = in;

    }

    for (k = 0; k < G->arcnum; k++)

    {

        scanf("%d%d", &i, &j);

        struct Arcnode *s;

        s = (struct Arcnode *)malloc(sizeof(struct Arcnode));

        s->adjvex = j;

        s->next = G->adjlist[i].firstedge;

        G->adjlist[i].firstedge = s;

    }

}

void ALgraph_destroy(ALgraph *G)

{

    int i;

    struct Arcnode *p;

    for (i = 0; i < G->vertexnum; i++)

    {

        p = G->adjlist[i].firstedge;

        while (p)

        {

            struct Arcnode *q = p;

            p = p->next;

            free(q);

        }

    }

}

void ALgraph_TopSort(ALgraph *G)

{

    int Q[Maxsize];

    int vex[Maxsize];

    int front, rear, i, k, count;

    struct Arcnode *p;

    front = -1;

    rear = -1;

    count = 0;

    for (i = 0; i < G->vertexnum; i++)

    {

        if (                      )

            Q[++rear] = i;

    }

    while (front != rear)

    {

        k = Q[++front];

        vex[count++] = k;

        p = G->adjlist[k].firstedge;

        while (p != NULL)

        {

            G->adjlist[p->adjvex].in--;

            if (G->adjlist[p->adjvex].in == 0)

                Q[++rear] = p->adjvex;

                               

        }

    }

    if (count < G->vertexnum)

        printf("有回路\n");

    else

    {

        for (i = 0; i < G->vertexnum; i++)

            printf("%c ", G->adjlist[vex[i]].vertex);

        printf("\n");

    }

}

int main()

{

    int i, n, m;

    scanf("%d %d", &n, &m);

    char *b = (char *)malloc(sizeof(char) * n);

    for (i = 0; i < n; i++)

    {

        scanf(" %c", &b[i]);

    }

    ALgraph al;

    ALgraph_init(&al, b, n, m);

    ALgraph_TopSort(&al);

    ALgraph_destroy(&al);

    free(b);

    return 0;

}