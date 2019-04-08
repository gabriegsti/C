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

printf("===#======#======#======#===\n");

}
int acha_linha(int mat[][3]){
int i,j;
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        if(mat[i][j]==0)
            return i;
    }
}

}
int acha_coluna(int mat[][3]){
int i,j;
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        if(mat[i][j]==0)
            return j;
    }
}

}


//mover o zerinho para a direita.
 void move_dir(int dir[][3], int linha, int coluna){
 int i,j;
 int dir2[3][3];
 int aux;
 for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        dir2[i][j]=dir[i][j];
    }
}
 aux=dir2[linha][coluna+1];
 dir[linha][coluna+1]=dir2[linha][coluna];
 dir[linha][coluna]=aux;
 }

 //mover o zerinho para a esquerda
 void move_esq(int esq[][3], int linha, int coluna){
 int esq2[3][3];
 int aux;
 int i,j;
 for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        esq2[i][j]=esq[i][j];
    }
}
 aux=esq2[linha][coluna-1];
 esq[linha][coluna-1]=esq2[linha][coluna];
 esq[linha][coluna]=aux;

 }

 //mover o zerinho para cima
void move_cima(int cima[][3], int linha, int coluna){
 int cima2[3][3];
 int aux;
 int i,j;
 for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        cima2[i][j]=cima[i][j];
    }
}
 aux=cima2[linha-1][coluna];
 cima[linha-1][coluna]=cima2[linha][coluna];
 cima[linha][coluna]=aux;
 }

 //mover o zerinho para baixo
 void move_baixo(int baixo[][3], int linha, int coluna){
 int baixo2[3][3];
 int aux;
 int i,j;
 for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        baixo2[i][j]=baixo[i][j];
    }
}
 aux=baixo2[linha+1][coluna];
 baixo[linha+1][coluna]=baixo2[linha][coluna];
 baixo[linha][coluna]=aux;
 }

 void compara(int mat[][3],int puzzle[][3],int esq[][3],int dir[][3],int cima[][3],int baixo[][3]){
 int opt1=0,opt2=0,opt3=0,opt4=0;
 int i,j;
 for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        if(puzzle[i][j]==esq[i][j])
            opt1++;
    }
 }
 for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        if(puzzle[i][j]==dir[i][j])
            opt2++;
    }
 }
 for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        if(puzzle[i][j]==cima[i][j])
            opt3++;
    }
 }
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        if(puzzle[i][j]==baixo[i][j])
            opt4++;
    }
 }
 if(opt1>opt2){
    if(opt1>opt3){
     if(opt1>opt4){
        mat=esq;
        return ;
     }
    }
 }
if(opt2>opt1){
    if(opt2>opt3){
     if(opt2>opt4){
        mat=dir;
        return ;
    }
    }
}
 if(opt3>opt2){
    if(opt3>opt1){
     if(opt3>opt4){
        mat=cima;
        return 0;
     }
    }
 }
 if(opt4>opt2){
    if(opt4>opt3){
     if(opt4>opt1){
        mat=baixo;
        return 0;
     }
    }
 }
}
//mover posição do zero de acordo com o puzzle
void move_posicao(int mat[][3],int puzzle[][3]){
int mat2[3][3],baixo[3][3],cima[3][3],esq[3][3],dir[3][3];
int linha= acha_linha(mat);
int coluna = acha_coluna(mat);
mat=baixo;
mat=cima;
mat=esq;
mat=dir;

    if((dir[linha][coluna+1]!=0) && (dir[linha][coluna+1]!=NULL))
        move_dir(dir,linha,coluna);

    if((esq[linha][coluna-1]!=0) && (esq[linha][coluna-1]!=NULL))
        move_esq(esq,linha,coluna);

    if((cima[linha-1][coluna]!=0) && (cima[linha-1][coluna]!=NULL))
        move_cima(cima,linha,coluna);

    if((baixo[linha+1][coluna]!=0) && (baixo[linha+1][coluna]!=NULL))
        move_baixo(baixo,linha,coluna);

    compara(mat,puzzle,esq,dir,cima,baixo);
    show_matriz(mat,3,3);

}

int main(int argc, char *argv[ ]){
int linha=3;
int coluna=3;
int puzzle[3][3]={{1,2,3},{4,5,6},{7,8,0}};
int mat[linha][coluna];
build_matriz(mat,linha,coluna);
show_matriz(mat,linha,coluna);
show_matriz(puzzle,linha,coluna);

//Passos do programa em busca do puzzle ideal.
int cont=0;
while(mat != puzzle){
        cont++;
printf("\n Passo %d \n :", cont);
    move_posicao(mat,puzzle);
}



}
