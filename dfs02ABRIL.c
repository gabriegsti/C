#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

/* Vértices de grafos são representados por objetos do tipo vertice. */
#define vertice int;
static int cnt;
int pre[1000];

/* A função GRAPHdfs() faz uma busca em profundidade no grafo G. Ela atribui um número de ordem pre[x] a cada vértice x de modo que o k-ésimo vértice descoberto receba o número de ordem k.*/
void GRAPHdfs( Graph G)
{
   cnt = 0;
   for (vertice v = 0; v < G->V; ++v){
      pre[v] = -1;
   }
   for (vertice v = 0; v < G->V; ++v){
      if (pre[v] == -1)
         dfsR( G, v); // começa nova etapa

   }
}

/* A funçao dfsR() visita todos os vértices de G que podem ser alcançados a partir do vértice v sem passar por vértices já descobertos. A função atribui cnt+k a pre[x] se x é o k-ésimo vértice descoberto. (O código supõe que G é representado por uma matriz de adjacências.) */
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
