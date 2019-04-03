#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Tpeca{

}peca;
//Testa se há repetições no vetor
int existe(int valores[],int tamanho,int valor){
    int i;
    for( i=0;i<tamanho;i++){
        if(valores[i]==valor)
            return 1;
    }
return 0;
}
//sorteia os numeros do vetor que preenche a matriz
int sorteio(int sorteados[],int tamanho){
    int numero,i;

    srand(time(NULL));
   for(i=0;i<tamanho;i++){
    numero=(rand()%9);//pega o resto da divisão do numero aleatorio por 9 (um numero menor q 9)
    while(existe(sorteados,i,numero)){
        numero=(rand()%9);
    }
    sorteados[i]=numero;
   }

}
//cria matriz
void build_matriz( int matriz[][3], int linha, int coluna){
    int i,j,k;
    int tamanho=9;
    int sorteados[tamanho];
    sorteio(sorteados,tamanho);
    k=0;
    for(i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            matriz[i][j]=sorteados[k];
            k++;
        }
    }
}
//mostra matriz
void show_matriz(int matriz[][3],int linha, int coluna){
for(int i=0;i<linha;i++){
    for(int j=0;j<coluna;j++){
        printf("+%d",matriz[i][j]);
    }
    printf("\n");
}

}

int main(int argc, char *argv[ ]){
int linha=3;
int coluna=3;
int puzzle[linha][coluna]={{1,2,3},{4,5,6},{7,8,0}};
int mat[linha][coluna];
build_matriz(mat,linha,coluna);
show_matriz(mat,linha,coluna);
show_matriz(puzzle,linha,coluna)


}
