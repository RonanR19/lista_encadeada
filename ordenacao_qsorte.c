#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//prototipagem de funcoes.
void cria_vetor(int *vet, int tam );
void imprime_vetor( int *vet, int tam);
void ordena_vetor_quicksort(int *vet,int inicio, int fim);



int main(void){
srand(time(NULL));
int *vet;
int tamanho;
printf("digite o tamnho do vetor.\n");
scanf("%d",&tamanho);
getchar();
vet =(int * )calloc(tamanho,sizeof(int));
cria_vetor(vet, tamanho );
imprime_vetor( vet, tamanho);
ordena_vetor_quicksort(vet,0, tamanho-1);
imprime_vetor( vet, tamanho);


}
void cria_vetor(int *vet, int tam ){
    int i;
     int indice;
     int troca;
    for(i=0; i<tam;i++){
    vet[i]=i+1;
    }

    for(i=0; i<tam;i++){
     indice = rand()%tam;
     troca = vet[i];
     vet[i]=vet[indice];
     vet[indice]=troca;
    }



}
void imprime_vetor ( int *vet, int tam){
  int i;
  int cont=0;
  for(i=0;i<tam;i++){
  cont++;
    printf(" %d ",vet[i]);
     if(cont==10){
     printf("\n");
     cont =0;
     }
  }
  printf("\n");

}
void ordena_vetor_quicksort(int *vet,int inicio, int fim){
   if (inicio>fim)
   return;

    int pivo;
    int aux;
    int troca;
    int t=0;
    pivo = inicio;
    aux= fim;
    while(pivo!=aux){
   //verificar se o valor de pivo e menor que de aux assim vet[pivo]> vet[aux troca sera efetuada]
      if (pivo <aux && vet[pivo] > vet[aux]){
         troca = vet[pivo];
         vet[pivo]= vet[aux];
         vet[aux]=troca;// trocando o pivo com aux
         troca = pivo;
         pivo=aux;
          aux= troca;
      }

      if (pivo >aux && vet[pivo] < vet[aux]){
         troca = vet[pivo];
         vet[pivo]= vet[aux];
         vet[aux]=troca;// trocando o pivo com aux
         troca = pivo;
         pivo=aux;
         aux= troca;

      }
      // aux desloca em direção ao pivo
        if(pivo<aux){
        aux--;
        }else{
        aux++;
        }



    }
      ordena_vetor_quicksort(vet, inicio, pivo-1);
        ordena_vetor_quicksort(vet, pivo+1,fim);

}
