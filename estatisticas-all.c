/*
* AUTHOR: ADRIANO FREITAS - adrianofreitas.me
* MODIFIED: JAN/08/2017
* VERSION: 0.2
*/
#include <stdio.h>
#include <stdlib.h>
#include "lotofacil.h"
//MAIN
int main(){
  int vetor1[SIZE], vetor2[SIZE];
  int *v1=vetor1, *v2=vetor2;
  int i, qt=3;

  FILE *arq_entrada;
  arq_entrada = fopen("jogos-sorteados-ordenados.txt","r");
  //FILE *arq_saida;
  //arq_saida = fopen("estatisticas.txt","w");

  if(arq_entrada == NULL ){
    puts("ERRO NA ABERTURA DO ARQUIVO!");
    //return(1);
  }else{
    printf("QTD de SORTEIOS: ");
    scanf("\n%d", &qt);
    Sorteio a[qt];
    for (i = 0;i < qt; i++) {
      fscanf(arq_entrada,"%d",&a[i].concurso);
      for (int x = 0; x < SIZE; x++) {
        fscanf(arq_entrada,"%d",&a[i].dezena[x]);
      }
    }
    Sorteio *s = a;

    x2_all(s, qt);
    x3_all(s, qt);
    x4_all(s, qt);
    x5_all(s, qt);
    x6_all(s, qt);
    x7_all(s, qt);
    x_all8(s, qt);
    fibo_all(s, qt);
    prime_all(s, qt);

    /*Criar outras funcoes para as linhas comentadas abaixo! */
    //numeros_repetidos(v1, v2);
    //soma_dezenas(v1);
    //linhas(v1);
    //numero_digitos(v1);
    //soma_digitos(v1);
  }



  fclose(arq_entrada);
  //fclose(arq_saida);

  printf("\n");

  return 0;
}
