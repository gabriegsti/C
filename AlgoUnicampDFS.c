#include<stdio.h>
#include<stdlib.h>

int visitado[MAXN];

void DFS(int no) {
  visitado[no] = 1;

  PreProcessa(no);

  for(int i=0; i<grau[no]; i++)
    if(!visitado[ G[no][i] ])
      DFS( G[no][i] );

  PosProcessa(no);
}

int main(){

for(int i=0; i<n;i++)
    visitado[i]=0;
DFS(no_inicial);

}
