#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void imprime_vetor(long long int *vet, long long int tam, FILE *arq);
long long int *cria_vetor(long long int tam, int ordenado);
void quicksort(long long int *vet, long long int inicio, long long int fim);
void quicksort2(long long int *vet, long long int inicio, long long int fim);
void quicksort3( long long int *vet,  long long int inicio,  long long int fim);

int main(){
long long int *vet;
char url[]="saida_q.txt";
FILE *arq;
arq = fopen(url, "w");
char url2[]="saida_q2.txt";
FILE *arq2;
arq2 = fopen(url2, "w");
float tempo;
if (arq==NULL)
    printf("Erro na abertura d o arquivo\n");
clock_t start, end;
long long int t_max, i;
srand(time(NULL));
t_max = 101;
for (i=1000; i<100000;i=i+1000){
    vet= cria_vetor(i, 0);
   //imprime_vetor(vet, i, arq2);
   start=clock();
    quicksort3( vet, 0, i-1);
    //quicksort2( vet, 0, i-1);
   end= clock();
   //imprime_vetor(vet, i, arq2);
   tempo = (double)(end- start)/((double)CLOCKS_PER_SEC);
   fprintf(arq,"%lld  %f \n", i, tempo);
   printf(" %lld %f\n",i, tempo);
   free(vet);
}



return 0;
}
void imprime_vetor(long long int *vet, long long int tam, FILE *arq){
   // printf("\n mostrando vetor: ");
    long long int i;
    for (i = 0; i < tam; i++)
    {
        //printf(" %lld ", vet[i]);
       fprintf(arq," %lld ", vet[i]);
    }
printf("\n");
fprintf(arq," \n");
}


long long int *cria_vetor(long long int tam, int ordenado){
long long int *vet, i;
long long int modificador, auxiliar;
vet = (long long int * )calloc (tam, sizeof(long long int));
for (i=0 ;i<tam;i++){
    vet[i]= 1+i;
}
if (ordenado !=1){
     for (i=0 ;i<tam;i++){
    modificador = rand()%tam;
     auxiliar = vet[i];
   vet[i]=vet[modificador];
   vet[modificador]= auxiliar;
}



}
return vet;
}



void quicksort(long long int *vet, long long int inicio, long long int fim){
    //se fim for menor que incio  paara execução
   if (inicio > fim)
        return;

    //criar aux , pivo , auxiliar para troca
    long long int pivo, aux, temp;
      pivo = inicio;
      aux = fim;
      while(pivo!= aux){

        /*como pivo está anterior au aux a troca ocorrerá quando valor do vetor naposição pivo
           for maior que valor do vetor na posição aux
        */
        if(pivo<aux)
        {

            if(vet[pivo] > vet[aux])//efetuar a troca
            {

                temp = vet[pivo];
                vet[pivo]=vet[aux];
                vet[aux]=temp;
                temp = pivo;
                pivo = aux;
                aux=temp;
                }
        }
                else{

                if (vet[pivo]<vet[aux]) //efetua a troca se  pivo for maior que aux
                {
                temp = vet[pivo];
                vet[pivo]=vet[aux];
                vet[aux]=temp;
                temp = pivo;
                pivo = aux;
                aux=temp;
                }
                }

            //aux andar em direção ao pivo
            if(pivo<aux)
            {
                aux--;
            }else
            {
                aux++;
            }

      }
      quicksort( vet, inicio,pivo-1);
      quicksort( vet, pivo+1,fim);
    }

    void quicksort2(long long int *vet, long long int inicio, long long int fim)
{
    if (inicio > fim)
        return;

    long long int pivo, aux, troca;

    pivo = inicio;
    aux = fim;

    while (pivo != aux)
    {
        if (pivo < aux)
        {
            if (vet[pivo] > vet[aux])
            {
                troca = vet[pivo];
                vet[pivo] = vet[aux];
                vet[aux] = troca;
                troca = pivo;
                pivo = aux;
                aux = troca;
            }
        }
        else
        {
            if (vet[pivo] < vet[aux])
            {
                troca = vet[pivo];
                vet[pivo] = vet[aux];
                vet[aux] = troca;
                troca = pivo;
                pivo = aux;
                aux = troca;
            }
        }

        if (pivo<aux)
        {
            aux--;
        }
        else
        {
            aux++;
        }
    }

    quicksort2(vet,inicio,pivo-1);
    quicksort2(vet,pivo+1,fim);

}
void quicksort3( long long int *vet,  long long int inicio,  long long int fim)
{
    if(inicio > fim)
        return;

long long int pivo, aux, troca;
pivo = inicio;
aux = fim;
while(pivo!=aux)
{
if(pivo <aux && vet[pivo]> vet[aux])
{
    troca = vet[pivo];
    vet[pivo] = vet[aux];
    vet[aux] = troca;
    troca = pivo;
    pivo = aux;
    aux = troca;
}
if(pivo > aux && vet[pivo] < vet[aux])
{
troca = vet[pivo];
    vet[pivo] = vet[aux];
    vet[aux] = troca;
    troca = pivo;
    pivo = aux;
    aux = troca;
}
if(pivo < aux)
{
    aux--;
}
else
{
    aux++;
}
}
    quicksort3(vet,inicio,pivo-1);
    quicksort3(vet,pivo+1,fim);
}

