#include <stdio.h>
#include "lotofacil.h"

void formatar(int *v);

int main(){
  int vetor1[SIZE], vetor2[SIZE];
  int *v1=vetor1, *v2=vetor2;
  int matriz[28][15];
  int vetor[420];

  FILE *arq_entrada;
  arq_entrada= fopen("files/p.txt","r");

  FILE *arquivo;
  arquivo =fopen("files/palpites.txt","w");

  if(arq_entrada == NULL || arquivo == NULL ){
    puts("ERRO NA ABERTURA DO ARQUIVO!");
    return(0);
  }else{
    for (int i = 0;i < 420; i++) {
        fscanf(arq_entrada,"%d",&vetor[i]);
    }
    //matriz[][] = vetor[];
    for (int x = 0; x < 28; x+15) {
      for (int i = 0; i < 420; i++) {

          printf("%d ", vetor[i]);


      }
      printf("\n " );
    }
/*
    for (int i = 0; i < 28; i++) {
      for (int j = 0; j < 15; j++) {
        printf("%d ", matriz[i][j]);
      }
      printf("\n" );
    }*/
  }
    return 0;

}
