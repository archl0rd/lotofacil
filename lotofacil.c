/*
* AUTHOR: ADRIANO FREITAS - adrianofreitas.me
* MODIFIED: JAN/2017
* VERSION: 0.2
*/
/*Criar outras funcoes para as linhas comentadas abaixo! */
//numeros_repetidos(v1, v2);
//soma_dezenas(v1);
//linhas(v1);
//numero_digitos(v1);
//soma_digitos(v1);
#include <stdio.h>
#include <stdlib.h>
#include "lotofacil.h"
//MAIN
int main(){
  int vetor1[SIZE], vetor2[SIZE];
  int *v1=vetor1, *v2=vetor2;
  int i, qt;
  int  op;

  FILE *n_concurso;
  n_concurso = fopen("files/concurso.txt","r");

  FILE *arq_entrada;
  arq_entrada = fopen("files/jogos-sorteados-ordenados.txt","r");
  FILE *arq_saida;
  arq_saida = fopen("files/estatisticas.txt","w");
  clear();
  if(arq_entrada == NULL || arq_saida == NULL || n_concurso == NULL){
    puts("ERRO NA ABERTURA DO ARQUIVO!");
    return(0);
  }else{
    //printf("QTD de SORTEIOS: ");
    //scanf("\n%d", &qt);
    fscanf(n_concurso, "%d", &qt);

    Sorteio a[qt];
    for (i = 0;i < qt; i++) {
      fscanf(arq_entrada,"%d",&a[i].concurso);
      for (int x = 0; x < SIZE; x++) {
        fscanf(arq_entrada,"%d",&a[i].dezena[x]);
      }
    }
    Sorteio *s = a;

    do {
      menu(qt);
      scanf("\n%d", &op);
      switch (op) {
        case 100:
        clear();
        ler(v1);
        wait();
        break;
        case 101:
          clear();
          sort(v1);
          int verificador = verificar_dezenas(s, v1, qt);
          if (verificador != 0) {
            printf("\nESSAS DEZENAS JA FORAM SORTEADAS: \n");
            exibir(v1);
            printf("\nCONCURSO No: %d", verificador);
          }else{
            printf("\nESSAS DEZENAS AINDA NAO FORAM SORTEADAS: \n");
            exibir(v1);
          }
          wait();
        break;
        case 102:
          clear();
          printf("\nQTD DEZENAS REPETIDAS: %d", n_sorteio_anterior(s, v1, v2, qt));
          printf("\nDEZENAS: ");
          sort(v2);
          exibir(v2);
          wait();
        break;
        case 201:
          clear();
          linhas(v1);
          wait();
        break;
        case 202:
          clear();
          //colunas(v1);
          wait();
        break;
        case 203:
          clear();
          fibo(v1);
          wait();
        break;
        case 204:
          clear();
          prime(v1);
          wait();
        break;
        case 205:
          clear();
          exibir(v1);
          x2(v1);
          x3(v1);
          x4(v1);
          x5(v1);
          x6(v1);
          x7(v1);
          x8(v1);
          wait();
        break;

        case 301:
          clear();
          x2_all(s, qt);
          wait();
        break;
        case 302:
          clear();
          x3_all(s, qt);
          wait();
        break;
        case 303:
          clear();
          x4_all(s, qt);
          wait();
        break;
        case 304:
          clear();
          x5_all(s, qt);
          wait();
        break;
        case 305:
          clear();
          x6_all(s, qt);
          wait();
        break;
        case 306:
          clear();
          x7_all(s, qt);
          wait();
        break;
        case 307:
          clear();
          x8_all(s, qt);
          wait();
        break;
        case 308:
          clear();
          prime_all(s, qt);
          wait();
        break;
        case 309:
          clear();
          fibo_all(s, qt);
          wait();
        break;
        case 401:
          clear();
          linhas_all(s, qt);
          wait();
        break;
        default:
        printf("\nCODIGO INVALIDO!" );
        wait();
        break;
      }
    } while(op!=0);

  }

  fclose(arq_entrada);
  fclose(arq_saida);

  printf("\n");

  return 0;
}
