/*
* AUTHOR: ADRIANO FREITAS - adrianofreitas.me
* MODIFIED: JAN/08/2017
* VERSION: 0.1
*/
#include <stdio.h>
#include <stdlib.h>
#include "lotofacil.h"

//MAIN
int main(){
  int i, qt;

  FILE *n_concurso;
  n_concurso = fopen("files/concurso.txt","r");
  FILE *arq_entrada;
  arq_entrada = fopen("files/jogos-sorteados.txt","r");

  FILE *arq_saida;
  arq_saida = fopen("files/jogos-sorteados-ordenados.txt","w");

  if(arq_entrada == NULL || arq_saida == NULL){
    puts("ERRO NA ABERTURA DO ARQUIVO!");
    return(1);
  }else{
    fscanf(n_concurso, "%d", &qt);
    Sorteio a[qt];
    for (i = 0;i < qt; i++) {
      fscanf(arq_entrada,"%d",&a[i].concurso);
      for (int x = 0; x < SIZE; x++) {
        fscanf(arq_entrada,"%d",&a[i].dezena[x]);
      }
    }
    Sorteio *s = a;
    for(i=0; i<qt; i++){
      clear();
      printf("ORDENANDO CONCURSO No: %d\n ",i+1);
      for (int x = 0; x < SIZE; x++) {

        insertion_sort(s, qt);
      }
    }

    for(i=0; i<qt; i++){
      fprintf(arq_saida, "%d\t", a[i].concurso);

      for (int x = 0; x < SIZE; x++) {
        fprintf(arq_saida, "%d\t", a[i].dezena[x]);
      }
      fprintf(arq_saida, "\n");

    }
  }
  fclose(arq_entrada);
  fclose(arq_saida);

  printf("\n");

  return 0;
}
