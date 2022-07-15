#include <stdio.h>
#include <stdlib.h>

// estruturas do programa
typedef struct registro {

  int novo_valor;
struct registro *proximo ;

}registro;

typedef struct lista {
  int qtd_elementos;
  struct registro *inicio;


}lista;


//  funcoes do programa
void incia_menu(lista *l1);
registro * aloca_registro ();
lista * aloca_lista();
void incluir_incio_lista ( lista *l , int adicionar_valor);
void mostrar_lista (lista *l);
void incluir_final_lista(lista *l , int adicionar_valor);
void ordenar_lista_bbs (lista *l);




int main(void){

lista *l1;
l1 = aloca_lista();

 incia_menu(l1);



}

void incia_menu(lista *l1){
  int opcao;
  int numero;
   do{
  //limpar_tela();
  printf("\n");
  printf("Menu de opções.\n");
  printf(" Digite 1 para incluir  valor no incio da lista . \n");
  printf(" Digite 2 para incluir  valor no fim  da lista . \n");
  printf(" Digite 3 para remover valor  da fila. \n");
  printf(" Digite 4 para mostrar  fila. \n");
  printf(" Digite 5 para ordenar a lista no BBs. \n");

  printf(" Digite 9 para mostrar o total de elementos da pila. \n");
  printf(" Digite 10 para sair da lista. \n");

  scanf("%d", &opcao);
   getchar();

      switch (opcao){
  case 1:
      printf("Digite o valor a ser adiconado.\n");
           scanf("%d",&numero);
          incluir_incio_lista ( l1, numero);
      break ;
  case 2:
       printf("Digite o valor a ser adiconado.\n");
           scanf("%d",&numero);
        incluir_final_lista( l1 , numero);

      break ;
  case 3:

      break ;
  case 4:
        mostrar_lista (l1);

      break ;
  case 5:

            ordenar_lista_bbs (l1);

      break ;
  case 9:

      break ;
  case 10:

      break ;
  default:

   printf("Oppção inválida. \n");
      break ;

      }
    }while(opcao!=10);

}

 registro * aloca_registro (){

    registro *novo_registro;
    novo_registro =(registro*)calloc(1,sizeof(registro));
    return novo_registro;

 }
 lista * aloca_lista(){
      lista *nova_lista;
         nova_lista =(lista *)calloc(1,sizeof(lista));
         return nova_lista;

 }
  void incluir_incio_lista ( lista *l , int adicionar_valor){

  registro *novo;
    novo= aloca_registro();
    novo->novo_valor = adicionar_valor;
          if (l->inicio == NULL){
            l->inicio = novo;
            }else{
                   novo->proximo  = l->inicio;
                   l->inicio = novo;
                  }
                l->qtd_elementos++;


  }
  void mostrar_lista (lista *l){

  if (l->inicio == NULL){
    printf("A lista está vazia.\n");
  }else{
     registro *aux;
     aux= l->inicio;
     while  (aux!= NULL){

        printf(" %d ", aux->novo_valor);
         aux= aux->proximo;
     }


  }
 printf("\n\n");

  }
  void incluir_final_lista(lista *l , int adicionar_valor){

      registro *novo;
      novo= aloca_registro ();
       novo->novo_valor = adicionar_valor;
        if (l->inicio == NULL){
          l->inicio = novo;
        }else{
        registro *aux;
        aux = l->inicio;
          while (aux->proximo !=NULL){
          aux = aux->proximo;
          }
           aux->proximo  = novo;
        }
        l->qtd_elementos++;
  }
  void ordenar_lista_bbs (lista *l){

     if (l->inicio == NULL){
     printf("A lista está vazia .\n");
     }else{
     registro *i,*j;
      int troca;
         for (i = l->inicio; i->proximo != NULL; i = i->proximo){
             for (j= i->proximo ;j != NULL; j = j->proximo){
                if(j->novo_valor  < i->novo_valor ){
                   troca = j->novo_valor ;
                     j->novo_valor = i->novo_valor;
                     i->novo_valor = troca;


                }

             }


         }
     }


  }
    int busca_binaria ( int valor_buscado, int qtd_elementos, lista *l){

         if (l->inicio == NULL){
         printf("lista vazia\n");
         return 0 ;
         }else{

          int meio = qtd_elementos/2;
          int contador =0;
          registro *aux;
          aux=l->inicio;
            while ( aux!= NULL  && aux->novo_valor != valor_buscado){

               if (contador == meio ){
                 if (aux->novo_valor == valor_buscado){
                  return (aux->valor);
                 }else{


                 }

               }

            if (p->prox->conteudo == x)
              return p->prox;
              aux = aux->proximo;
            contador ++;
            }


         }


    return 0;
    }
