struct Tarvore{
 int estado;
 int valor;
 Tarvore* filho_a_esquerda;
 Tarvore* filho_a_direita;

}typedef struct Tarvore arvore;


int reconhece_abb( arvore *arvoreBB){

    if(arvoreBB==NULL){
        return 1;
    }
    while(arvoreBB->estado==0 ){
        if(arvoreBB->filho_a_esquerda->valor<arvoreBB->valor){
            reconhece_abb(arvoreBB->filho_a_esquerda);
        }else{
                if(arvoreBB.filho_a_direita>arvoreBB.valor){
                    reconhece_abb(arvore arvoreBB);
                }
             }
    }
    arvoreBB.estado=1;

}
