#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

/* V�rtices de grafos s�o representados por objetos do tipo vertex. */
#define vertex int

struct graph {
   int V;
   int A;
   int **adj;
};
    /* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o GRAPHshow() imprime, para cada v�rtice v do grafo G, em uma linha, todos os v�rtices adjacentes a v. */
void GRAPHshow( Graph G) {
    for(vertex v=0;v<G->A;v++){
        printf("%2d",v);
    }

   for (vertex v = 0; v < G->V; ++v) {
      printf( "%2d ", v);
      for (vertex w = 0; w < G->V; ++w){
         if (G->adj[v][w] == 1)
            printf( " %2d", w);

    }
      printf( "\n");
   }
         printf( "===================================================================================\n");

}

/* Um Graph � um ponteiro para um graph, ou seja, um Graph cont�m o endere�o de um graph. */
typedef struct graph *Graph;




/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o GRAPHinit() constr�i um grafo com v�rtices 0 1 .. V-1 e nenhum arco. */
Graph GRAPHinit( int V) {
   Graph G = malloc( sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = MATRIXint( V, V, 0);
   return G;
}


Graph GRAPHbuildComplete( int V) {
   Graph G;
   G = GRAPHinit( V);
   for (vertex v = 0; v < G->V; v++){
      for (vertex w = 0; w < G->V; w++){
         //if (w != v)
            GRAPHinsertArc( G, v, 0);
      }
   }

   return G;
}
