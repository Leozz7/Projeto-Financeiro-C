#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void cabecalho1()
{
  printf("=================================\n");
  printf("| GERENCIADOR FINANCEIRO MENSAL |\n");
  printf("=================================\n");
}

void perfil()
{
  printf("=================================\n");
  printf("|        PERFIL INVESTIDOR      |\n");
  printf("=================================\n");
}

int main()
{
  char nome[30], cate[4][30], cont[3], mes[30];
  float desp[4] = {0}, rece[4] = {0}, totalcate[4] = {0}, recet[4] = {0}, despt[4] = {0};
  float receitatotal = 0, despesatotal = 0, resultado = 0;
  int compara, i, j, k, opcao, opcao2, opcao3, r, l, resp[1];

  setlocale(LC_ALL, "Portuguese");

  system("cls");

  cabecalho1();

  printf("NOME  : ");
  fflush(stdin);
  gets(nome);

  printf("MES   : ");
  fflush(stdin);
  gets(mes);

  system("cls");

  compara = 0;
  j = 0;

  // Definir as categorias
  for (i = 0; compara == 0 && i < 4; i++)
  {
    cabecalho1();

    printf("Categorias da despesa ou receita: [MAX 4]\n");
    fflush(stdin);
    gets(cate[i]);

    printf("Tem outra? [S/N]");
    scanf("%s.\n", cont);

    compara = strcmp(cont, "S");

    j++;

    system("cls");

    if (i == 3)
    {
      printf("Limite de categorias atingido\n\n");

      system("pause");
      system("cls");

      break;
    }
  }

  do
  {
    cabecalho1();

    // Menu Principal
    printf("Escolha uma opcao: \n");
    printf("[1] Adicionar uma transacao \n");
    printf("[2] Gerar relatorios \n");
    printf("[3] Gerar recomendacoes \n");
    printf("[4] Sair \n");

    scanf("%d", &opcao);
    fflush(stdin);

    if (opcao == 1)
    {
      system("cls");

      cabecalho1();

      // Exibir Todas as Categorias que o Usuário Inseriu
      for (k = 0; k < j; k++)
      {
        printf("[%d] %s \n", k + 1, cate[k]);
      }

      scanf("%d", &opcao2);
      fflush(stdin);

      if (opcao2 >= 1 && opcao2 <= j)
      {
        system("cls");

        cabecalho1();

        // Menu de Transações
        printf("CATEGORIA ESCOLHIDA : %s\n", cate[opcao2 - 1]);
        printf("[1] Despesa \n");
        printf("[2] Receita\n");
        printf("[3] Sair \n");
        scanf("%d", &opcao3);
        fflush(stdin);

        if (opcao3 == 1)
        {
          system("cls");

          cabecalho1();
          printf("CATEGORIA ESCOLHIDA : %s\n", cate[opcao2 - 1]);
          printf("Insira o valor da Despesa\n");
          scanf("%f", &desp[opcao2 - 1]);
          fflush(stdin);

          despt[opcao2 - 1] += desp[opcao2 - 1];
        }
        else if (opcao3 == 2)
        {
          system("cls");
          cabecalho1();
          printf("CATEGORIA ESCOLHIDA : %s\n", cate[opcao2 - 1]);
          printf("Insira o valor da Receita Destinada\n");
          scanf("%f", &rece[opcao2 - 1]);
          fflush(stdin);

          recet[opcao2 - 1] += rece[opcao2 - 1];
        }
      }
    }

    // Gerar Relatórios com base nas transações inseridas
    else if (opcao == 2)
    {
      system("cls");

      cabecalho1();

      printf("Usuario : %s\n", nome);
      printf("Mês     : %s\n\n", mes);

      for (r = 0; r < j; r++)
      {
        printf("CATEGORIA : %s\n", cate[r]);
        printf("   RECEITA    : R$ %.2f \n", recet[r]);
        printf("   DESPESA    : R$ %.2f \n", despt[r]);

        totalcate[r] = recet[r] - despt[r];

        printf("RESULT. CATE. %d: R$ %.2f\n\n", r + 1, totalcate[r]);

        receitatotal += recet[r];
        despesatotal += despt[r];
      }

      resultado = receitatotal - despesatotal;

      printf("-------------------\n");
      printf("     TOTAL \n");
      printf("RECEITA : R$ %.2f\n", receitatotal);
      printf("DESPESA : R$ %.2f\n", despesatotal);

      if (resultado > 0)
      {
        printf("SALDO : R$ %.2f\n", resultado);
        printf("RESULTADO : POSITIVO\n");
      }
      else
      {
        printf("SALDO : R$ %.2f\n", resultado);
        printf("RESULTADO : NEGATIVO\n");
      }
      receitatotal = 0;
      despesatotal = 0;

      system("pause");
    }
    else if (opcao == 3)
    {

      // Perguntas para definir o perfil de investidor
      if (resultado > 0)
      {
        system("cls");

        perfil();
        printf("Primeiro responda essas perguntas :\n\n");
        printf("Qual e o seu principal objetivo ao investir?.\n");
        printf("[1] Preservacao de capital \n");
        printf("[2] Crescimento moderado\n");
        printf("[3] Crescimento agressivo \n");
        scanf("%d", &resp[0]);
        fflush(stdin);

        printf("Qual e o seu horizonte de investimento?\n");
        printf("[1] Curto prazo (ate 2 anos) \n");
        printf("[2] Medio prazo (2-5 anos) \n");
        printf("[3] Longo prazo (mais de 5 anos) \n");
        scanf("%d", &resp[1]);
        fflush(stdin);

        // Recomendações com base no perfil e no saldo disponivel
        if ((resp[0] == 1 && resp[1] == 1))
        {
          system("cls");

          perfil();
          printf("Usuario : %s\n", nome);

          printf("Perfil : Conservador\n");
          if (resultado < 100)
          {
            printf("Sugestao: Como seu saldo e menor que R$ 100,00\n");
            printf("Recomendamos investir no Tesouro Direto.\n");
            printf("Investimento em titulos do governo federal, como o Tesouro Selic.\n\n");

            system("pause");
          }
          else if (resultado >= 100 && resultado < 300)
          {
            printf("Sugestao: Como seu saldo e maior que R$ 100,00 e menor que R$ 300,00\n");
            printf("Recomendamos investir nos fundos DI de baixa taxa de administracao.\n");
            printf("Fundos que investem em titulos de renda fixa de baixo risco, como CDBs e titulos publicos.\n\n");

            system("pause");
          }
          else if (resultado >= 300)
          {
            printf("Sugestao: Como seu saldo e maior que R$ 300,00\n");
            printf("Recomendamos investir nos CDBs (Certificados de Depósito Bancario) de bancos solidos e com boa rentabilidade.\n\n");

            system("pause");
          }
        }
        else if ((resp[0] == 1 && resp[1] == 2) || (resp[0] == 2 && resp[1] == 1) || (resp[0] == 2 && resp[1] == 2) || (resp[0] == 2 && resp[1] == 3))
        {
          system("cls");

          perfil();

          printf("Usuario : %s\n", nome);
          printf("Perfil : Moderado\n");
          if (resultado < 100)
          {
            printf("Sugestao: Como seu saldo e menor que R$ 100,00\n");
            printf("Recomendamos investir no Fundos de Investimento em Renda Fixa.\n");
            printf("Podem ter uma pequena exposicao a renda variavel e ser uma opcao interessante para diversificacao.\n\n");

            system("pause");
          }
          else if (resultado >= 100 && resultado < 300)
          {
            printf("Sugestao: Como seu saldo e maior que R$ 100,00 e menor que R$ 300,00\n");
            printf("Recomendamos investir nos fundos multimercado. \n.");
            printf("Investem em diferentes classes de ativos, como renda fixa, renda variavel, cambio, entre outros. \n\n");

            system("pause");
          }
          else if (resultado >= 300)
          {
            printf("Sugestao: Como seu saldo e maior que R$ 300,00");
            printf("Recomendamos investir no LCI (Letra de Credito Imobiliario) ou no LCA (Letra de Credito do Agronegocio).\n");
            printf("Isentas de IR(Imposto de Renda) para pessoa fisica e oferecem boa rentabilidade para o medio prazo.\n\n");

            system("pause");
          }
        }
        else if ((resp[0] == 1 && resp[1] == 3) || (resp[0] == 3 && resp[1] == 1) || (resp[0] == 3 && resp[1] == 2) || (resp[0] == 3 && resp[1] == 3))
        {
          system("cls");

          perfil();
          printf("Usuario : %s\n", nome);

          printf("Perfil : Agressivo\n");
          if (resultado < 100)
          {
            printf("Sugestao: Como seu saldo e menor que R$ 100,00");
            printf("Recomendamos investir no Fundos de Ações.\n");
            printf("Investem principalmente em acoes de empresas listadas na bolsa de valores.\n\n");

            system("pause");
          }
          else if (resultado >= 100 && resultado < 300)
          {
            printf("Sugestao: Como seu saldo e maior que R$ 100,00 e menor que R$ 300,00");
            printf("Recomendamos investir nos ETFs (Exchange Traded Funds).\n ");
            printf("Fundos de indice negociados na bolsa de valores, que replicam a performance de um indice especifico, como o Ibovespa.\n\n");

            system("pause");
          }
          else if (resultado >= 300)
          {
            printf("Sugestao: Como seu saldo e maior que R$ 300,00");
            printf("Recomendamos investir em acoes de empresas solidas e com potencial de crescimento.\n");
            printf("A estrategia pode ser construir uma carteira diversificada de acoes de empresas de diferentes setores.\n\n");

            system("pause");
          }
        }
      }

      // Usuário não inseriu as transações ou tenha um saldo igual a 0
      else if (resultado == 0)
      {
        system("cls");

        perfil();
        printf("Seu saldo e igual a 0 ou ainda nao inseriu suas transacoes\n\n");

        system("pause");
      }

      // Usuário com saldo negativo
      else if (resultado < 0)
      {
        system("cls");

        perfil();
        for (l = 0; l < j; l++)
        {
          if (totalcate[l] < 0)
          {
            printf("Voce precisa economizar na categoria: %s \n\n", cate[l]);
          }
        }

        system("pause");
      }
    }

    system("cls");
  } while (opcao != 4);

  return 0;
}

