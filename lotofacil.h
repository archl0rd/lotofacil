#include <stdio.h>
#include <stdlib.h>
#define clear() printf("\033[H\033[J")
#define SIZE 15

typedef struct{
  int concurso;
  int dezena[15];
}Sorteio;

void menu(int c){
  printf("\n\n\t\tLOTOFACIL - ULTIMO CONCURSO: %d\n", c );
  printf("\n100.\tDIGITAR UM JOGO. 15 NUMEROS" );
  printf("\n101.\tVERIFICAR SE O JOGO JA FOI SORTEADO" );
  printf("\n102.\tNUMEROS REPETIDOS DO JOGO ANTERIOR" );
  printf("\n\n---.\tMOSTRAR ESTATISTICAS DO JOGO DIGITADO" );

  printf("\n201.\tNUMEROS EM CADA LINHA DA CARTELA" );
  printf("\n202.\tNUMEROS EM CADA COLUNA DA CARTELA" );
  printf("\n203.\tNUMEROS DE FIBONACCI");
  printf("\n204.\tNUMEROS PRIMOS");
  printf("\n205.\tMULTIPLOS <2,3,4,5,6,7,8>" );
  printf("\n\n---.\tMOSTRAR ESTATISTICAS DE TODOS JOGOS SORTEADOS" );
  printf("\n301.\tMULTIPLOS DE 2" );
  printf("\n302.\tMULTIPLOS DE 3" );
  printf("\n303.\tMULTIPLOS DE 4" );
  printf("\n304.\tMULTIPLOS DE 5" );
  printf("\n305.\tMULTIPLOS DE 6" );
  printf("\n306.\tMULTIPLOS DE 7" );
  printf("\n307.\tMULTIPLOS DE 8" );
  printf("\n308.\tNUMEROS PRIMOS " );
  printf("\n309.\tNUMEROS DE FIBONACCI " );
  printf("\n\n---.OUTRAS ESTATISTICAS" );
  printf("\n401.\tNUMEROS EM CADA LINHA" );
  printf("\n---.\n000.\tSAIR" );
  printf("\n\n" );
  printf("DIGITE UM CODIGO: " );
}

void wait(){
  char c;
  printf("\n\nCONTINUAR? ( S | N) \n" );
  scanf("\n%c", &c);
  if (c == 'n' || c == 'N') {
    ;
  }
  clear();
}

int verificar_dezenas(Sorteio *s, int *v, int qt){
  int i, j, iq;

  for (int x = 0; x < qt; x++) {
    iq=0;
    for ( i = 0; i < SIZE; i++) {
      if (s[x].dezena[i] == v[i]) {
        iq++;
      }
      if (iq==15)
        return s[x].concurso;
    }
  }
  return 0;
}

int n_sorteio_anterior(Sorteio *s, int *v, int *n_repetidos, int qt){
  int i, j, x, count=0, ult_jogo[SIZE];

    for ( x = 0; x < qt; x++) {
      if (x==qt-1) {
        for (i = 0; i < SIZE; i++) {
            ult_jogo[i] = s[x].dezena[i];
        }
      }
    }

    for ( i = 0; i < SIZE; i++) {
      n_repetidos[i] = 0;
    }

    for ( i = 0; i < SIZE; i++) {
      for (j = 0; j < SIZE; j++) {
        if (ult_jogo[i] == v[j]) {
          n_repetidos[i] = ult_jogo[j];
          count++;
        }

      }
    }

  return count;
}

void insertion_sort(Sorteio *v, int qt){
  int i, j, eleito;
  for (int x=0; x < qt; x++) {
    for (i = 0; i < SIZE; i++) {
      eleito = v[x].dezena[i];
      j = i-1;
      while (j>=0 && eleito < v[x].dezena[j])  {
        v[x].dezena[j+1] = v[x].dezena[j];
        j=j-1;
      }
      v[x].dezena[j+1] = eleito;
    }
  }
}

void sort(int *v){
  int i, j, eleito;
    for (i = 0; i < SIZE; i++) {
      eleito = v[i];
      j = i-1;
      while (j>=0 && eleito < v[j])  {
        v[j+1] = v[j];
        j=j-1;
      }
      v[j+1] = eleito;
    }

}

void ler(int *v){
  int error=0;
  int aux;
  printf("DIGITE 15 NUMEROS <1 - 25>: ");
   for (int i = 0; i < SIZE; i++) {
    do {
      scanf("\n%d", &v[i]);

        aux=v[i];
        for (int x = 0; x < i; x++) {
          if (aux == v[x]) {
            printf("NUMERO REPETIDO: %d\n", aux);
            printf("VERIFIQUE OS NUMEROS DIGITADOS E TENTE NOVAMENTE!\n" );
            //scanf("\n%d", &v[i]);
            exit;
          }
        }


      if (v[i]<1 || v[i]>25) {
        printf("NUMERO INVALIDO: %d\n",v[i] );
        printf("VERIFIQUE OS NUMEROS DIGITADOS E TENTE NOVAMENTE!\n" );
        exit;
      }
    } while(v[i]<1 || v[i]>25);
  }
}

void exibir(int *v){
  for (int i = 0; i < SIZE; i++) {
    if (v[i] != 0)
      printf("%d ", v[i]);
  }
}


void x2_all(Sorteio *v, int qt){
  int total=0;
  int aux[13];

  for (int i = 0; i < 13; i++) {
    aux[i]=0;
  }

  for (int x=0; x < qt; x++) {
    int qtd_x=0;
    for (int i = 0; i < SIZE; i++) {
      if(v[x].dezena[i] % 2 == 0)
        qtd_x++;
    }
    aux[qtd_x]++;
  }

  printf("\n\nMULTIPLOS X2:");

  for (int i = 0; i < 13; i++) {
    total+=aux[i];
  }
  printf("\nQTD\tVEZES\t%%");
  for (int i = 2 ; i < 13; i++) {
    float p = (float)(100*aux[i])/total;
    printf("\n%d\t%d\t%.2f", i, aux[i], p);
  }
}

//MULTIPLOS x3
void x3_all(Sorteio *v, int qt){
  int total=0;
  int aux[9];

  for (int i = 0; i < 9; i++) {
    aux[i]=0;
  }

  for (int x=0; x < qt; x++) {
    int qtd_x=0;
    for (int i = 0; i < SIZE; i++) {
      if(v[x].dezena[i] % 3 == 0)
        qtd_x++;
    }
    aux[qtd_x]++;
  }

  printf("\n\nMULTIPLOS X3:");

  for (int i = 0; i < 9; i++) {
    total+=aux[i];
  }
  printf("\nQTD\tVEZES\t%%");
  for (int i = 0; i < 9; i++) {
    float p = (float)(100*aux[i])/total;
    printf("\n%d\t%d\t%.2f", i, aux[i], p);
  }
}

//MULTIPLOS x4
void x4_all(Sorteio *v, int qt){
  int total=0;
  int aux[7];

  for (int i = 0; i < 7; i++) {
    aux[i]=0;
  }

  for (int x=0; x < qt; x++) {
    int qtd_x=0;
    for (int i = 0; i < SIZE; i++) {
      if(v[x].dezena[i] % 4 == 0)
        qtd_x++;
    }
    aux[qtd_x]++;
  }

  printf("\n\nMULTIPLOS X4:");

  for (int i = 0; i < 7; i++) {
    total+=aux[i];
  }
  printf("\nQTD\tVEZES\t%%");
  for (int i = 0; i < 7; i++) {
    float p = (float)(100*aux[i])/total;
    printf("\n%d\t%d\t%.2f", i, aux[i], p);
  }
}

//MULTIPLOS x5
void x5_all(Sorteio *v, int qt){
  int total=0;
  int aux[6];

  for (int i = 0; i < 6; i++) {
    aux[i]=0;
  }

  for (int x=0; x < qt; x++) {
    int qtd_x=0;
    for (int i = 0; i < SIZE; i++) {
      if(v[x].dezena[i] % 5 == 0)
        qtd_x++;
    }
    aux[qtd_x]++;
  }

  printf("\n\nMULTIPLOS X5:");

  for (int i = 0; i < 6; i++) {
    total+=aux[i];
  }
  printf("\nQTD\tVEZES\t%%");
  for (int i = 0; i < 6; i++) {
    float p = (float)(100*aux[i])/total;
    printf("\n%d\t%d\t%.2f", i, aux[i], p);
  }
}

//MULTIPLOS x6
void x6_all(Sorteio *v, int qt){
  int total=0;
  int aux[5];

  for (int i = 0; i < 5; i++) {
    aux[i]=0;
  }

  for (int x=0; x < qt; x++) {
    int qtd_x=0;
    for (int i = 0; i < SIZE; i++) {
      if(v[x].dezena[i] % 6 == 0)
        qtd_x++;
    }
    aux[qtd_x]++;
  }

  printf("\n\nMULTIPLOS X6:");

  for (int i = 0; i < 5; i++) {
    total+=aux[i];
  }
  printf("\nQTD\tVEZES\t%%");
  for (int i = 0; i < 5; i++) {
    float p = (float)(100*aux[i])/total;
    printf("\n%d\t%d\t%.2f", i, aux[i], p);
  }
}

//MULTIPLOS x7
void x7_all(Sorteio *v, int qt){
  int total=0;
  int aux[4];

  for (int i = 0; i < 4; i++) {
    aux[i]=0;
  }

  for (int x=0; x < qt; x++) {
    int qtd_x=0;
    for (int i = 0; i < SIZE; i++) {
      if(v[x].dezena[i] % 7 == 0)
        qtd_x++;
    }
    aux[qtd_x]++;
  }

  printf("\n\nMULTIPLOS X7:");

  for (int i = 0; i < 4; i++) {
    total+=aux[i];
  }
  printf("\nQTD\tVEZES\t%%");
  for (int i = 0; i < 4; i++) {
    float p = (float)(100*aux[i])/total;
    printf("\n%d\t%d\t%.2f", i, aux[i], p);
  }
}


//MULTIPLOS x8
void x8_all(Sorteio *v, int qt){
  int total=0;
  int aux[6];

  for (int i = 0; i < 4; i++) {
    aux[i]=0;
  }

  for (int x=0; x < qt; x++) {
    int qtd_x=0;
    for (int i = 0; i < SIZE; i++) {
      if(v[x].dezena[i] % 8 == 0)
        qtd_x++;
    }
    aux[qtd_x]++;
  }

  printf("\n\nMULTIPLOS X8:");

  for (int i = 0; i < 4; i++) {
    total+=aux[i];
  }
  printf("\nQTD\tVEZES\t%%");
  for (int i = 0; i < 4; i++) {
    float p = (float)(100*aux[i])/total;
    printf("\n%d\t%d\t%.2f", i, aux[i], p);
  }
}

void prime_all(Sorteio *v, int qt){
  int total=0;
  int aux[11];

  for (int i=0; i < 12; i++) {
    aux[i]=0;
  }
  for (int x=0; x<qt; x++) {
    int qtd_x=0;
    for (int i = 0; i < SIZE; i++) {
        if(v[x].dezena[i] == 1  ||
           v[x].dezena[i] == 2  ||
           v[x].dezena[i] == 3  ||
           v[x].dezena[i] == 5  ||
           v[x].dezena[i] == 7  ||
           v[x].dezena[i] == 11 ||
           v[x].dezena[i] == 13 ||
           v[x].dezena[i] == 17 ||
           v[x].dezena[i] == 19 ||
           v[x].dezena[i] == 23
         ){
             qtd_x++;
           }
    }
    aux[qtd_x]++;
  }

  printf("\n\nNUMEROS PRIMOS:");
  for (int i=0; i < 11; i++) {
    total+=aux[i];
  }
  printf("\nQTD\tVEZES\t%%");
  for (int i = 0; i < 11; i++) {
    float p = (float)(100*aux[i])/total;
    printf("\n%d\t%d\t%.2f", i, aux[i], p);
  }
}

void fibo_all(Sorteio *v, int qt){
  int total=0;
  int aux[8];

  for (int i=0; i < 9; i++) {
    aux[i]=0;
  }

  for (int x=0; x<qt; x++) {
    int qtd_x=0;
    for (int i = 0; i < SIZE; i++) {
        if(v[x].dezena[i] == 1  ||
           v[x].dezena[i] == 2  ||
           v[x].dezena[i] == 3  ||
           v[x].dezena[i] == 5  ||
           v[x].dezena[i] == 8  ||
           v[x].dezena[i] == 13 ||
           v[x].dezena[i] == 21
         ){
             qtd_x++;
           }

    }
    aux[qtd_x]++;
  }
  printf("\n\nNUMEROS FIBONACCI:");
  for (int i=0; i < 8; i++) {
    total+=aux[i];
  }
  printf("\nQTD\tVEZES\t%%");
  for (int i = 0; i < 8; i++) {
    float p = (float)(100*aux[i])/total;
    printf("\n%d\t%d\t%.2f", i, aux[i], p);
  }

}


void x2(int *v){
  int qtd_par=0;
  for (int i = 0; i < SIZE; i++) {
    if(v[i] % 2 == 0)
      qtd_par++;
  }
  printf("\nQTD NUMEROS PARES: %d", qtd_par);
  printf("\nQTD NUMEROS IMPARES: %d", SIZE - qtd_par);
}

//MULTIPLOS x3
void x3(int *v){
  int qtd_x=0;
  for (int i = 0; i < SIZE; i++) {
    if(v[i] % 3 == 0)
      qtd_x++;
  }
  printf("\nQTD MULTIPLOS X3: %d", qtd_x);
}

//MULTIPLOS x4
void x4(int *v){
  int qtd_x=0;
  for (int i = 0; i < SIZE; i++) {
    if(v[i] % 4 == 0)
      qtd_x++;
  }
  printf("\nQTD MULTIPLOS X4: %d", qtd_x);
}

//MULTIPLOS x5
void x5(int *v){
  int qtd_x=0;
  for (int i = 0; i < SIZE; i++) {
    if(v[i] % 5 == 0)
      qtd_x++;
  }
  printf("\nQTD MULTIPLOS X5: %d", qtd_x);
}

//MULTIPLOS x6
void x6(int *v){
  int qtd_x=0;
  for (int i = 0; i < SIZE; i++) {
    if(v[i] % 6 == 0)
      qtd_x++;
  }
  printf("\nQTD MULTIPLOS X6: %d", qtd_x);
}

//MULTIPLOS x7
void x7(int *v){
  int qtd_x=0;
  for (int i = 0; i < SIZE; i++) {
    if(v[i] % 7 == 0)
      qtd_x++;
  }
  printf("\nQTD MULTIPLOS X7: %d", qtd_x);
}

//MULTIPLOS x8
void x8(int *v){
  int qtd_x=0;
  for (int i = 0; i < SIZE; i++) {
    if(v[i] % 8 == 0)
      qtd_x++;
  }
  printf("\nQTD MULTIPLOS X8: %d", qtd_x);
}

void prime(int *v){
  int qtd_x=0;
  for (int i = 0; i < SIZE; i++) {
      if(v[i] == 1 ||
         v[i] == 2 ||
         v[i] == 3 ||
         v[i] == 5 ||
         v[i] == 7 ||
         v[i] == 11 ||
         v[i] == 13 ||
         v[i] == 17 ||
         v[i] == 19 ||
         v[i] == 23
       ){
           qtd_x++;
         }

  }
  printf("\nQTD NUMEROS RIMOS: %d", qtd_x);
}

void fibo(int *v){
  int qtd_x=0;
  for (int i = 0; i < SIZE; i++) {
      if(v[i] == 1 ||
         v[i] == 2 ||
         v[i] == 3 ||
         v[i] == 5 ||
         v[i] == 8 ||
         v[i] == 13 ||
         v[i] == 21
       ){
           qtd_x++;
         }

  }
  printf("\nQTD NUMEROS FIBONACCI: %d", qtd_x);
}

void soma_dezenas(int *v){
  int soma=0;
  for (int i = 0; i < SIZE; i++) {
      soma+=v[i];
  }
  printf("\nSOMA DAS DEZENAS: %d", soma);
}


void linhas_all(Sorteio *v, int qt){
  int total1=0,total2=0,total3=0,total4=0,total5=0;
  int aux1[6],aux2[6],aux3[6],aux4[6],aux5[6];

  for (int i = 0; i < 6; i++) {
    aux5[i]=0;
    aux4[i]=0;
    aux3[i]=0;
    aux2[i]=0;
    aux1[i]=0;
  }

  for (int x=0; x < qt; x++) {
    int l1=0,l2=0,l3=0,l4=0,l5=0;
    for (int i = 0; i < SIZE; i++) {
      if(v[x].dezena[i] < 5)
        l1++;
      else if(v[x].dezena[i] < 10)
        l2++;
      else if(v[x].dezena[i] < 15)
        l3++;
      else if(v[x].dezena[i] < 20)
        l4++;
      else
        l5++;
    }
    aux1[l1]++;
    aux2[l2]++;
    aux3[l3]++;
    aux4[l4]++;
    aux5[l5]++;
  }


  for (int i = 0; i < 6; i++) {
    total1+=aux1[i];
    total2+=aux2[i];
    total3+=aux3[i];
    total4+=aux4[i];
    total5+=aux5[i];
  }

  printf("\nLINHA\t01" );
  printf("\nQTD\tVEZES\t%%");
  for (int i = 0; i < 6; i++) {
    float p = (float)(100*aux1[i])/total1;
    printf("\n%d\t%d\t%.2f", i, aux1[i], p);
  }
  printf("\n\nLINHA\t02" );
  printf("\nQTD\tVEZES\t%%");
  for (int i = 0; i < 6; i++) {
    float p = (float)(100*aux2[i])/total2;
    printf("\n%d\t%d\t%.2f", i, aux2[i], p);
  }
  printf("\n\nLINHA\t03" );
  printf("\nQTD\tVEZES\t%%");
  for (int i = 0; i < 6; i++) {
    float p = (float)(100*aux3[i])/total3;
    printf("\n%d\t%d\t%.2f", i, aux3[i], p);
  }
  printf("\n\nLINHA\t04" );
  printf("\nQTD\tVEZES\t%%");
  for (int i = 0; i < 6; i++) {
    float p = (float)(100*aux4[i])/total4;
    printf("\n%d\t%d\t%.2f", i, aux4[i], p);
  }
  printf("\n\nLINHA\t05" );
  printf("\nQTD\tVEZES\t%%");
  for (int i = 0; i < 6; i++) {
    float p = (float)(100*aux5[i])/total5;
    printf("\n%d\t%d\t%.2f", i, aux5[i], p);
  }
}

void linhas(int *v){
  int l1=0,l2=0,l3=0,l4=0,l5=0;
  for (int i = 0; i < SIZE; i++) {
    if(v[i] <= 5)
      l1++;
    else if(v[i] <= 10)
      l2++;
    else if(v[i] <= 15)
      l3++;
    else if(v[i] <= 20)
      l4++;
    else
      l5++;
  }
  printf("\nNUMEROS LINHA 1: %d", l1);
  printf("\nNUMEROS LINHA 2: %d", l2);
  printf("\nNUMEROS LINHA 3: %d", l3);
  printf("\nNUMEROS LINHA 4: %d", l4);
  printf("\nNUMEROS LINHA 5: %d", l5);
}

void numero_digitos(int *v){
  int d1=0,d2=0;
  for (int i = 0; i < SIZE; i++) {
    if(v[i] < 10)
      d1++;
    else
      d2+=2;
    }
    printf("\nNUMERO DE DIGITOS: %d", d1+d2);
}

void soma_digitos(int *v){
  int soma=0;
  for (int i = 0; i < SIZE; i++) {
    if(v[i] < 10)
      soma += v[i];
    else
      soma = soma + v[i]/10 + v[i]%10;
    }
    printf("\nSOMA DE DIGITOS: %d", soma);
}

void numeros_repetidos(int *v1, int *v2){
  int i, j, x=0;
  for(i = 0; i < SIZE; i++){
    if (i <= v1[i]) {
      for (j = 0; j < SIZE; j++) {
        if (v1[i] == v2[j]) {
          x++;
        }
      }
    }

  }
  printf("\nNUMEROS REETIDOS: %d", x);
}
