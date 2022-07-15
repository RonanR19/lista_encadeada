#include <stdlib.h>
#include  <stdio.h>
#include <locale.h>
typedef struct registro{
/*
a estrutura registra � composta dos seguintes  termos
variavel numero que representa o valor a ser adicionado na lista.
O pontoieiro proximo  da estrutura apontoa para
 o pr�ximo registro a ser feito na lista

*/
   int numero;
   struct registro *proximo;
}registro;
typedef struct lista{
/*
A estrutura lista � composta por:
variavel quantidade que contara o total de valores adicionados
e umponteiro da variavel registro que aponta par o inicio da lista.
*/
  int quantidade;
  struct registro *inicio;
}lista;


void limpar_tela();
void incia_menu(lista *l1, lista *l2);
void incluir_no_inicio_da_lista(lista *l , int valor);
lista *aloca_lista();
registro *aloca_registro();
void mostar_lista (lista *l);
int remover_valor ( lista *l);
void ordenacao_bbsote(lista *l);


int main(){
    setlocale(LC_ALL,"");
//CRIAR DOIS PONTERIOS DE LISTAS DISTINTOS.
    lista *l1, *l2;
    /*
    Ser� alocado so endere�os das listas com a fun�o aloca lista

    */
    l1 = aloca_lista();
    l2= aloca_lista();
    incia_menu(l1, l2);


return 0;
}
void limpar_tela(){
system ("CLS");

}
void incia_menu(lista *l1, lista *l2){
  int opcao;
  int numero;
   do{
  //limpar_tela();
  printf("Menu de opções.\n");
  printf(" Digite 1 para incluir  valor no topo da fila. \n");
  printf(" Digite 2 para remover valor  da fila. \n");
  printf(" Digite 3 para mostrar  fila. \n");
  printf(" Digite 4 para ordenar a lista no BBs. \n");

  printf(" Digite 9 para mostrar o total de elementos da pila. \n");
  printf(" Digite 10 para sair da lista. \n");

  scanf("%d", &opcao);
   getchar();

      switch (opcao){
  case 1:
      printf("Digite o valor a ser adiconado.\n");
      scanf("%d",&numero);
     incluir_no_inicio_da_lista(l1 , numero);
      break ;
  case 2:
      if(remover_valor (l1)){
        printf("Valor removido\n ");
      }else{
            printf("Fila  vazia\n");
                   }

      break ;
  case 3:
  mostar_lista (l1);
      break ;
  case 4:
       ordenacao_bbsote(l1);

      break ;
  case 5:


      break ;
  case 9:
     printf("Total de elementos na lista %d \n",l1->quantidade);
      break ;
  case 10:
      printf("Voce est� deixando a lista.\n");
      break ;
  default:

   printf("Oppção inválida. \n");
      break ;

      }
    }while(opcao!=10);

}
lista *aloca_lista(){
/*
� uma fun�o que retorna aloca um ponteiro do tipo lista e retorna a aloca�o dopontoeiro.
*/

 lista *novo;  // ponteiro que ser� alocado
 novo=(lista *)malloc(sizeof(lista));
   //Aponta o ponterio inciio da estrutura registro como  NULL

   novo->inicio = NULL ;
   novo->quantidade =0;//incializa o contador da lista
  return novo;
}
  registro *aloca_registro(){
    registro *novo;// ponterio que ira receber o endere�o de mem�ria.
      novo=(registro *)malloc(sizeof(registro));
      novo->numero = 0 ;//incializa a variavel a ser armazenada com 0
      novo->proximo = NULL;  // o ponteorio regtistro proximo � null
    return novo;

  }
void incluir_no_inicio_da_lista(lista *l , int valor){
 // O incio da lista � o toppo da pilha
   registro *novo; // cria umponteiro da estrutura registro
   novo = aloca_registro(); // oponteorio novo recebe o endere�o de aloca registro
   novo->numero=valor;
   //preciso verificar se a lista est� vazia
   if (l->inicio== NULL){
    //sigifica qeu a lsita est� vazia e recebe o valor de novo
    l->inicio = novo;
   }else{
   /*lista n�o est� vazia.
     novo->proximo  recebe da l->incio o endere�o
   */
     novo->proximo = l->inicio;
      l->inicio = novo;
   }
   l->quantidade++;
}
void mostar_lista (lista *l){
   //ponterio aux dotepo registro para percorrer a lista
   registro *aux;

if (l->inicio == NULL){
    printf("lista vazia.\n");
}else{
  aux= l->inicio;
  //varrendo enquato aux difereten de NULL
    while(aux != NULL)    {
    printf(" %d ", aux->numero);
    //aux recebe o endere�o do proximo registro
    aux= aux->proximo;
   }
   printf("\n");

}
}

int remover_valor ( lista *l) {
  //testrtar se alista est� vazia
   int temp;
   int i=1;
  if(l->inicio == NULL){
    return 0;
  }else{
      registro *aux; //valor auxiliar
      registro *pos; // armaze3na o valor anterior
      registro *novo;
      novo =aloca_registro();
       aux = l->inicio;
        temp = l->quantidade ;
        printf("temp = %d\n ", temp);

        while(i<=temp){

              aux=aux->proximo;
               pos=aux;
              i++;
              }
              aux->proximo = NULL;
              aux= aux->proximo;
              novo->proximo = aux;
              free(aux);
     return 1;
  }
}
void ordenacao_bbsote(lista *l){

    if (l->inicio ==NULL){
        printf("lista vazia");
        }else{

        registro *i,*j;
        int aux;
        int tamanho_lista = l->quantidade;

            for (i=l->inicio;i->proximo != NULL; i = i->proximo){

                for (j=i->proximo; j != NULL;j=j->proximo){
                     if (j->numero < i->numero){
                     aux = i->numero;
                     i->numero = j->numero;
                     j->numero = aux;

                     }


                }

            }

    }


}
