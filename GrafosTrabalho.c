#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

/* Vértices de grafos são representados por objetos do tipo vertex. */
#define vertex int

struct graph {
   int V;
   int A;
   int **adj;
};
    /* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHshow() imprime, para cada vértice v do grafo G, em uma linha, todos os vértices adjacentes a v. */
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

/* Um Graph é um ponteiro para um graph, ou seja, um Graph contém o endereço de um graph. */
typedef struct graph *Graph;




/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHinit() constrói um grafo com vértices 0 1 .. V-1 e nenhum arco. */
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
