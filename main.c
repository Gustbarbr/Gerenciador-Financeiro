#include <stdio.h>
#include "funcoes.h"

//Struct das opções
struct escolha{
  int x ;
};

struct escolha opcoes;

// Main
int main() {

  //Ler o arquivo no início do programa
 FILE *f;
  if("Receita" != NULL){
    f = fopen("Receita", "rb");
    }
  if("Gastos" != NULL){
    f = fopen("Gastos", "rb");
  }
  
// Define x como 0
  int x = 0;
  
// Enquanto o x for 0 as opções aparecerão
  while(x == 0){
    printf("Feito por: Gustavo Gomes Barbosa RA: 24.122.061-5\n");
    printf("E por: Fernando Milani Venerando RA: 24.122.063-1\n");
    printf("------------------------------------------\n");
    printf("Digite a função desejada:\n");
    printf("1 - Cadastro de receitas\n");
    printf("2 - Cadastro de gastos\n");
    printf("3 - Relatório de movimentação nos últimos 12 meses\n");
    printf("4 - Relatório de movimentação no último mês\n");
    printf("5 - Investimento\n");
    printf("6 - Gerenciador\n");

    //Pergunta qual função o usuário deseja
    printf("Digite um número: ");
    scanf("%d", &x);
    
    //Limpar a tela
    system("clear");
    
    //Se o x for 1 a função receitas é chamada
    if(x == 1){
      printf("------------------------------------------\n");
      receitas();
      x = 0;
    }

    //Se o x for 2 a função gastos é chamada
    if(x == 2){
      printf("------------------------------------------\n");
      gastos();
      x = 0;
    }

    //Se o x for 3 a função do relatório dos últimos 12 meses é chamada
    if(x == 3){
      printf("------------------------------------------\n");
      Meses();
      x = 0;
    }

    if(x == 4){
      printf("------------------------------------------\n");
      mes();
      x = 0;
    }

    if(x == 5){
      printf("------------------------------------------\n");
      investimento();
      x = 0;
    }

    if(x == 6){
      printf("------------------------------------------\n");
      gerenciador();
      x = 0;
    }
  
    //Se o x for diferente dos reconhecidos aparecerá uma mensagem de erro e o usuário será redirecionado a página inicial
    if(x < 0 || x > 6){
      printf("------------------------------------------\n");
      printf("[Comando não reconhecido!]\n");
      x = 0;
    }
  }


  
}











