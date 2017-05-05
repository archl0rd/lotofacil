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
  int i, qt, ultimo_concurso;

  FILE *n_concurso;
  n_concurso = fopen("files/concurso.txt","r");

  FILE *arquivo;
  arquivo = fopen("files/jogos-sorteados.txt","a+");

  if(arquivo == NULL)
    puts("ERRO NA ABERTURA DO ARQUIVO!");
  else{
    printf("QTD de JOGOS  A SEREM ADICIONADOS AO BANCO DE DADOS: ");
    scanf("%d", &qt);
    Sorteio a[qt];

    fscanf(n_concurso, "%d", &ultimo_concurso);

    for(i=0; i<qt; i++){
      a[i].concurso = ultimo_concurso+1;
      ultimo_concurso = a[i].concurso;

      printf("CONCURSO No: %d\n", a[i].concurso);
      printf("DIGITE AS 15 DEZENAS SORTEADAS: ");
      for (int x = 0; x < SIZE; x++) {
        scanf("\n%d", &a[i].dezena[x]);
      }
    }
    for(i=0; i<qt; i++){
      fprintf(arquivo, "%d\t", a[i].concurso);

      for (int x = 0; x < SIZE; x++) {
        fprintf(arquivo, "%d\t", a[i].dezena[x]);
      }
      fprintf(arquivo, "\n");

    }
  }
  fclose(arquivo);
  printf("\n");

  return 0;
}
