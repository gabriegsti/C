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

/* Um Graph � um ponteiro para um graph, ou seja, um Graph cont�m o endere�o de um graph. */
typedef struct graph *Graph;

/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o MATRIXint() aloca uma matriz com linhas 0..r-1 e colunas 0..c-1. Cada elemento da matriz recebe valor val. */
static int **MATRIXint( int r, int c, int val) {
   int **m = malloc( r * sizeof (int *));
   for (vertex i = 0; i < r; ++i)
      m[i] = malloc( c * sizeof (int));
   for (vertex i = 0; i < r; ++i)
      for (vertex j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}

/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o GRAPHinit() constr�i um grafo com v�rtices 0 1 .. V-1 e nenhum arco. */
Graph GRAPHinit( int V) {
   Graph G = malloc( sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = MATRIXint( V, V, 0);
   return G;
}



/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o GRAPHinsertArc() insere um arco v-w no grafo G. A fun��o sup�e que v e w s�o distintos, positivos e menores que G->V. Se o grafo j� tem um arco v-w, a fun��o n�o faz nada. */
void GRAPHinsertArc( Graph G, vertex entrada, vertex saida,int valor) {
   if (G->adj[entrada][saida] == 0) {
      G->adj[entrada][saida] = valor;
      G->A++;
   }
}


/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o GRAPHremoveArc() remove do grafo G o arco v-w. A fun��o sup�e que v e w s�o distintos, positivos e menores que G->V. Se n�o existe arco v-w, a fun��o n�o faz nada. */
void GRAPHremoveArc( Graph G, vertex v, vertex w) {
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0;
      G->A--;
   }
}


/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o GRAPHshow() imprime, para cada v�rtice v do grafo G, em uma linha, todos os v�rtices adjacentes a v. */
void GRAPHshow( Graph G) {

    for(vertex v=0;v<G->V;v++){
        printf("%2d",v);
    }
    printf( "\n");

   for (vertex v = 1; v < G->V; ++v) {
      printf( "%2d", v);
      for (vertex w = 1; w < G->V; ++w){
         //if (G->adj[v][w] == 1)
            printf("%2d",G->adj[v][w]);
            //printf( " %2d", 0);

    }
      printf( "\n");
   }
         printf( "===================================================================================\n");

}


Graph GRAPHbuildComplete( int V) {
   Graph G;
   G = GRAPHinit( V);
   for (vertex v = 1; v < G->V; v++){
      for (vertex w = 1; w < G->V; w++){
         //if (w != v)
            //GRAPHinsertArc( G, v, w);
        if (G->adj[v][w] == 0) {
      G->adj[v][w] = 0;
      G->A++;
   }

      }
   }

   return G;
}


/* A fun�ao dfsR() visita todos os v�rtices de G que podem ser alcan�ados a partir do v�rtice v sem passar por v�rtices j� descobertos.  (O c�digo sup�e que G � representado por uma matriz de adjac�ncias.) */
void dfsR( Graph G, vertex v, int valor)
{

   for (vertex w = (G->V)-1; w >0; --w){
      if (G->adj[v][w] == valor){
            printf("\n Encontrado valor %d em Matriz ADJ[%d][%d] \n ",valor,v,w);

               GRAPHremoveArc(G,v,w);

        }
   }
}


/* A fun��o GRAPHdfs() faz uma busca em profundidade no grafo G. */
void GRAPHdfs( Graph G,int valor)
{
   for (vertex v =(G->V)-1 ; v >0; --v)
         dfsR( G, v, valor); // come�a nova etapa
}





int main(int argc, char **argv){
Graph G;
G=GRAPHbuildComplete(6);
GRAPHshow(G);
GRAPHinsertArc(G,1,1,2);
GRAPHinsertArc(G,1,5,5);
GRAPHinsertArc(G,5,3,7);
GRAPHinsertArc(G,2,4,1);
GRAPHinsertArc(G,5,4,5);
GRAPHshow(G);

GRAPHdfs(G,5);

}
