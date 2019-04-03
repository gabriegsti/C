#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

/* V�rtices de grafos s�o representados por objetos do tipo vertice. */
#define vertice int;
static int cnt;
int pre[1000];

/* A fun��o GRAPHdfs() faz uma busca em profundidade no grafo G. Ela atribui um n�mero de ordem pre[x] a cada v�rtice x de modo que o k-�simo v�rtice descoberto receba o n�mero de ordem k.*/
void GRAPHdfs( Graph G)
{
   cnt = 0;
   for (vertice v = 0; v < G->V; ++v){
      pre[v] = -1;
   }
   for (vertice v = 0; v < G->V; ++v){
      if (pre[v] == -1)
         dfsR( G, v); // come�a nova etapa

   }
}

/* A fun�ao dfsR() visita todos os v�rtices de G que podem ser alcan�ados a partir do v�rtice v sem passar por v�rtices j� descobertos. A fun��o atribui cnt+k a pre[x] se x � o k-�simo v�rtice descoberto. (O c�digo sup�e que G � representado por uma matriz de adjac�ncias.) */
static void dfsR( Graph G, vertice v)
{
   pre[v] = cnt++;
   for (vertice w = 0; w < G->V; ++w){
        if (G->adj[v][w] != 0 && pre[w] == -1){
            printf("%d, %d",G,w);
            dfsR( G, w);
        }
    }
}

int main(string args[])
