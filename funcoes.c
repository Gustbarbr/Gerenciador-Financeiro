#include <stdio.h>
#include <string.h>
#include <time.h>

// Struct das receitas
struct dados {
  double valor;
  char descricao;
  int dia;
  int mes;
  int ano;
  char categoria;
};

struct dados info;

// Struct dos gastos
struct mais_dados {
  double valor_gastos;
  char descricao_gastos;
  int dia_gastos;
  int mes_gastos;
  int ano_gastos;
  char categoria_gastos;
};

struct mais_dados mais_info;

//------------------------  Receitas -------------------------
int receitas() {

  char x[3];
  char resp;
  char s[] = "S";

  FILE *f;
  // Abrir o arquivo e escrever
  f = fopen("Receita", "ab");

  if ("Receita" != NULL) {
    printf("Gostaria de sobrescrever os dados? (S/N)");
    scanf("%s", x);

    resp = strcmp(x, s);
    if (resp == 0) {
      // printf e scanf para receber valor, descrição, data e categoria
      printf("Insira suas receitas:\n");
      printf("Valor: ");
      scanf("%lf", &info.valor);

      printf("Descrição: ");
      scanf("%s", &info.descricao);

      printf("Data:\n");
      printf("Dia: ");
      scanf("%d", &info.dia);
      printf("Mês: ");
      scanf("%d", &info.mes);
      printf("Ano: ");
      scanf("%d", &info.ano);

      printf("Categoria: ");
      scanf("%s", &info.categoria);

      printf("\n");

      fwrite(&info, sizeof(struct dados), 1, f);

      fclose(f);
    }
  }
}

//--------------------------- Gastos -------------------------
int gastos() {

  char x[3];
  char resp;
  char s[] = "S";

  FILE *g;
  // Abrir o arquivo e escrever
  g = fopen("Gastos", "ab");

  if ("Gastos" != NULL) {
    printf("Gostaria de sobrescrever os dados? (S/N)");
    scanf("%s", x);

    resp = strcmp(x, s);
    if (resp == 0) {
      // printf e scanf para receber valor, descrição, data e categoria
      printf("Insira seus gastos:\n");
      printf("Valor: ");
      scanf("%lf", &mais_info.valor_gastos);

      printf("Descrição: ");
      scanf("%s", &mais_info.descricao_gastos);

      printf("Data:\n");
      printf("Dia: ");
      scanf("%d", &mais_info.dia_gastos);
      printf("Mês: ");
      scanf("%d", &mais_info.mes_gastos);
      printf("Ano: ");
      scanf("%d", &mais_info.ano_gastos);

      printf("Categoria: ");
      scanf("%s", &mais_info.categoria_gastos);

      printf("\n");

      fwrite(&info, sizeof(struct mais_dados), 1, g);

      fclose(g);
    }
  }
}

//--------------------- Ultimos 12 meses ---------------------

int Meses() {
  FILE *g;

  // strings para receber e comparar
  char x[9]; // 1 letra a mais que a maior palavra
  char receita[] = "receitas";
  char gastos[] = "gastos";
  int rec;
  int gas;

  int cont = 14; // Foi escolhido esse número para que mostre 12 meses na tela

  // Parte da declaração do time.h
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  printf("Qual arquivo deseja abrir?\n");
  printf("Escreva receitas ou gastos.\n");

  // Receber uma string como variável
  scanf("%s", x);

  printf("\n");
  
  // Comparar ambas strings para ver se são idênticas
  rec = strcmp(x, receita);
  if (rec == 0) {

    g = fopen("Receitas_meses.txt", "w");

    // Enquanto o contador estiver acima de 1 as funções vão continuar para que
    // se chegue aos 12 meses
    while (cont != 1) {
      fprintf(g, "------------------------------\n");
      fprintf(g, "Valor: %lf\n", info.valor);
      fprintf(g, "Descrição: %s\n", &info.descricao);
      fprintf(g, "Dia: %d\n", tm.tm_mday - 1);
      fprintf(g, "Categoria: %s\n", &info.categoria);
      tm.tm_mday -= 1; // Cada vez que as funções rodarem será descontado 1 dia
      // Se o dia for igual a 1 haverá uma mudança de mês, e dependendo do mês
      // serão adicionados 28, 30 ou 31 dias
      if (tm.tm_mday == 1) {
        if (tm.tm_mon == 1 || tm.tm_mon == 3 || tm.tm_mon == 5 ||
            tm.tm_mon == 7 || tm.tm_mon == 8 || tm.tm_mon == 10 ||
            tm.tm_mon == 12) {
          fprintf(g, "------------------------------\n");
          fprintf(g, "Mês: %d\n", tm.tm_mon);
          tm.tm_mon -= 1;
          tm.tm_mday += 31;
          cont -= 1;
        } else if (tm.tm_mon == 4 || tm.tm_mon == 6 || tm.tm_mon == 9 ||
                   tm.tm_mon == 11) {
          fprintf(g, "------------------------------\n");
          fprintf(g, "Mês: %d\n", tm.tm_mon);
          tm.tm_mon -= 1;
          tm.tm_mday += 30;
          cont -= 1;
        } else if (tm.tm_mon == 2) {
          fprintf(g, "------------------------------\n");
          fprintf(g, "Mês: %d\n", tm.tm_mon);
          tm.tm_mon -= 1;
          tm.tm_mday += 28;
          cont -= 1;
        }

        // Se o mês for inferior a 1 serão adicionados mais 12 meses e será
        // descontado 1 ano
        if (tm.tm_mon == 0) {
          tm.tm_mon += 12;
          fprintf(g, "------------------------------\n");
          fprintf(g, "Ano: %d\n", tm.tm_year + 1899);
        }
      }
    }
    fclose(g);
  }

  // Comparar ambas strings para ver se são idênticas
  gas = strcmp(x, gastos);
  if (gas == 0) {
    g = fopen("Gastos_meses.txt", "w");

    // Enquanto o contador estiver acima de 1 as funções vão continuar para que
    // se chegue aos 12 meses
    while (cont != 1) {
      fprintf(g, "------------------------------\n");
      fprintf(g, "Valor: %lf\n", mais_info.valor_gastos);
      fprintf(g, "Descrição: %s\n", &mais_info.descricao_gastos);
      fprintf(g, "Dia: %d\n", tm.tm_mday - 1);
      fprintf(g, "Categoria: %s\n", &mais_info.categoria_gastos);
      tm.tm_mday -= 1; // Cada vez que as funções rodarem será descontado 1 dia

      // Se o dia for igual a 1 haverá uma mudança de mês, e dependendo do mês
      // serão adicionados 28, 30 ou 31 dias
      if (tm.tm_mday == 1) {
        if (tm.tm_mon == 1 || tm.tm_mon == 3 || tm.tm_mon == 5 ||
            tm.tm_mon == 7 || tm.tm_mon == 8 || tm.tm_mon == 10 ||
            tm.tm_mon == 12) {
          fprintf(g, "------------------------------\n");
          fprintf(g, "Mês: %d\n", tm.tm_mon);
          tm.tm_mon -= 1;
          tm.tm_mday += 31;
          cont -= 1;
        } else if (tm.tm_mon == 4 || tm.tm_mon == 6 || tm.tm_mon == 9 ||
                   tm.tm_mon == 11) {
          fprintf(g, "------------------------------\n");
          fprintf(g, "Mês: %d\n", tm.tm_mon);
          tm.tm_mon -= 1;
          tm.tm_mday += 30;
          cont -= 1;
        } else if (tm.tm_mon == 2) {
          fprintf(g, "------------------------------\n");
          fprintf(g, "Mês: %d\n", tm.tm_mon);
          tm.tm_mon -= 1;
          tm.tm_mday += 28;
          cont -= 1;
        }

        // Se o mês for inferior a 1 serão adicionados mais 12 meses e será
        // descontado 1 ano
        if (tm.tm_mon == 0) {
          tm.tm_mon += 12;
          fprintf(g, "------------------------------\n");
          fprintf(g, "Ano: %d\n", tm.tm_year + 1899);
        }
      }
    }
    fclose(g);
  }
}

//---------------------------- Último mês ---------------------

int mes() {
  FILE *g;


  // strings para receber e comparar
  char x[9]; // 1 letra a mais que a maior palavra
  char receita[] = "receitas";
  char gastos[] = "gastos";
  int rec;
  int gas;

  int cont = 3; // Foi escolhido esse número para que mostre 1 mes na tela

  // Parte da declaração do time.h
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  printf("Qual arquivo deseja abrir?\n");
  printf("Escreva receitas ou gastos.\n");

  // Receber uma string como variável
  scanf("%s", x);

  printf("\n");



  // Comparar ambas strings para ver se são idênticas
  rec = strcmp(x, receita);
  if (rec == 0) {

    g = fopen("Receitas_mes.txt", "w");

    // Enquanto o contador estiver acima de 1 as funções vão continuar para que
    // se chegue ao mês anterior
    while (cont != 1) {
      fprintf(g, "------------------------------\n");
      fprintf(g, "Valor: %lf\n", info.valor);
      fprintf(g, "Descrição: %s\n", &info.descricao);
      fprintf(g, "Dia: %d\n", tm.tm_mday - 1);
      fprintf(g, "Categoria: %s\n", &info.categoria);
      tm.tm_mday -= 1; // Cada vez que as funções rodarem será descontado 1 dia

      // Se o dia for igual a 1 haverá uma mudança de mês, e dependendo do mês
      // serão adicionados 28, 30 ou 31 dias
      if (tm.tm_mday == 1) {
        if (tm.tm_mon == 1 || tm.tm_mon == 3 || tm.tm_mon == 5 ||
            tm.tm_mon == 7 || tm.tm_mon == 8 || tm.tm_mon == 10 ||
            tm.tm_mon == 12) {
          fprintf(g, "------------------------------\n");
          fprintf(g, "Mês: %d\n", tm.tm_mon);
          tm.tm_mon -= 1;
          tm.tm_mday += 31;
          cont -= 1;
        } else if (tm.tm_mon == 4 || tm.tm_mon == 6 || tm.tm_mon == 9 ||
                   tm.tm_mon == 11) {
          fprintf(g, "------------------------------\n");
          fprintf(g, "Mês: %d\n", tm.tm_mon);
          tm.tm_mon -= 1;
          tm.tm_mday += 30;
          cont -= 1;
        } else if (tm.tm_mon == 2) {
          fprintf(g, "------------------------------\n");
          fprintf(g, "Mês: %d\n", tm.tm_mon);
          tm.tm_mon -= 1;
          tm.tm_mday += 28;
          cont -= 1;
        }

        // Se o mês for inferior a 1 serão adicionados mais 12 meses e será
        // descontado 1 ano
        if (tm.tm_mon == 0) {
          tm.tm_mon += 12;
          fprintf(g, "------------------------------\n");
          fprintf(g, "Ano: %d\n", tm.tm_year + 1899);
        }
      }
    }
    fclose(g);

  }

  gas = strcmp(x, gastos);
  if (gas == 0) {
    g = fopen("Gastos_mes.txt", "w");

    // Enquanto o contador estiver acima de 1 as funções vão continuar para que
    // se chegue ao mês anterior
    while (cont != 1) {
      fprintf(g, "------------------------------\n");
      fprintf(g, "Valor: %lf\n", mais_info.valor_gastos);
      fprintf(g, "Descrição: %s\n", &mais_info.descricao_gastos);
      fprintf(g, "Dia: %d\n", tm.tm_mday - 1);
      fprintf(g, "Categoria: %s\n", &mais_info.categoria_gastos);
      tm.tm_mday -= 1; // Cada vez que as funções rodarem será descontado 1 dia

      // Se o dia for igual a 1 haverá uma mudança de mês, e dependendo do mês
      // serão adicionados 28, 30 ou 31 dias
      if (tm.tm_mday == 1) {
        if (tm.tm_mon == 1 || tm.tm_mon == 3 || tm.tm_mon == 5 ||
            tm.tm_mon == 7 || tm.tm_mon == 8 || tm.tm_mon == 10 ||
            tm.tm_mon == 12) {
          fprintf(g, "------------------------------\n");
          fprintf(g, "Mês: %d\n", tm.tm_mon);
          tm.tm_mon -= 1;
          tm.tm_mday += 31;
          cont -= 1;
        } else if (tm.tm_mon == 4 || tm.tm_mon == 6 || tm.tm_mon == 9 ||
                   tm.tm_mon == 11) {
          fprintf(g, "------------------------------\n");
          fprintf(g, "Mês: %d\n", tm.tm_mon);
          tm.tm_mon -= 1;
          tm.tm_mday += 30;
          cont -= 1;
        } else if (tm.tm_mon == 2) {
          fprintf(g, "------------------------------\n");
          fprintf(g, "Mês: %d\n", tm.tm_mon);
          tm.tm_mon -= 1;
          tm.tm_mday += 28;
          cont -= 1;
        }

        // Se o mês for inferior a 1 serão adicionados mais 12 meses e será
        // descontado 1 ano
        if (tm.tm_mon == 0) {
          tm.tm_mon += 12;
          fprintf(g, "------------------------------\n");
          fprintf(g, "Ano: %d\n", tm.tm_year + 1899);
        }
      }
    }
    fclose(g);
  
  }
}

//---------------------------- Investimento ---------------------

int investimento() {

  float y;
  int cont = 0;
  float total = 0;

  // O tanto que a pessoa investirá, definido manualmente
  int tamanho;
  printf("Quantas vezes gostaria de investir?\n");
  scanf("%d", &tamanho);

  FILE *q;

  // As informações são guardadas em um arquivo txt
  q = fopen("Investimento.txt", "a");

  // Cada vez que o programa rodar o contador aumenta em 1 e enquanto for menor
  // que o tamanho definido manualmente ele continuará rodando
  while (cont < tamanho) {
    if (feof(q)) // Ele para se todas as linhas foram lidas
      break;
    else {
      printf("Quanto gostaria de investir?\n");
      scanf("%f", &y);
      float porcentagem = (10 * y) / 100; // 10% do investido
      float w = y + porcentagem;          // O investido + 10%
      fread(&y, sizeof(float), 1, q);
      total += w; // A soma de todos os investimentos
      fprintf(q, "----------------\n");
      fprintf(q, "|Investido: %.2f|\n", y);
      fprintf(q, "|Total: %.2f    |\n", total);
      fprintf(q, "-----------------\n");
    }
    cont += 1;
  }

  fclose(q);
}

//-------------------------- Gerenciador ------------------------

int gerenciador() {
  // Variáveis para as contas, salário e tempo
  float salario, agua, luz, internet, dispesas, vestuario, objetivo, restante;
  float quantia_final, garantia;
  int tempo;

  char x[3];
  char resp;
  char s[] = "S";

  // Variáveis para capturar os valores manualmente
  printf("Digite o seu salário: ");
  scanf("%f", &salario);

  printf("Digite sua conta de água:\n");
  scanf("%f", &agua);
  printf("Digite sua conta de luz:\n");
  scanf("%f", &luz);
  printf("Digite sua conta de internet:\n");
  scanf("%f", &internet);
  printf("Digite seu gasto com as dispesas:\n");
  scanf("%f", &dispesas);
  printf("Digite seu gasto com vestuario:\n");
  scanf("%f", &vestuario);

  // O que sobrará no final ao subtrair as contas do salário
  quantia_final = salario - (agua + luz + internet + dispesas + vestuario);
  printf("Você ficará com R$%.2f ao pagar todas as contas.\n", quantia_final);

  // O limite que a pessoa é recomendada a gastar desse total
  garantia = (25 * quantia_final) / 100;
  if (garantia > 0) {
    printf("Recomendo que gaste apenas R$%.2f desse total.(APENAS "
           "RECOMENDAÇÃO!)\n",
           garantia);
  } else {
    printf("Não sobrou dinheiro!\n");
  }

  // Pergunta se a pessoa possui um objetivo e recolhe a resposta
  printf("Você possui algum objetivo de compra? (S/N)\n");
  scanf("%s", x);
  resp = strcmp(x, s);
  // Se a pessoa esccolher que possui um objetivo ele calculará quanta falta
  // para esse objetivo
  if (resp == 0) {
    printf("Qual o valor desse objetivo?\n");
    scanf("%f", &objetivo);
    // Em qauntso meses a pessoa pretende comprar o item
    printf("Em quantos meses você planeja comprar?\n");
    scanf("%i", &tempo);

    // Uma conta para saber o quanto a pessoa terá nesse número de meses se
    // gastar apenas o recomendado do salário final
    restante = (quantia_final * tempo) - (garantia * tempo);

    // Se o dinheiro da pessoa no final for o suficiente ou não, o programa
    // avisará
    if (restante > objetivo) {
      printf("Se você guardar seu saldo final gastando apenas o recomendado, "
             "em %d meses você terá %.2f e conseguirá comprar.\n",
             tempo, restante);
    } else {
      printf("Se você guardar seu saldo final gastando apenas o recomendado, "
             "em %d meses você terá %.2f e não conseguirá comprar.\n",
             tempo, restante);
    }
  }
}