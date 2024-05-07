#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

#define TAM 100

typedef struct
{
    char pergunta[TAM];
    char resp1[TAM];
    char resp2[TAM];
    char resp3[TAM];
    int correta;
}tQuestao;

void limparQuestao(tQuestao *questao)
{
    for (int i = 0; i <= TAM; i++)
    {
        questao ->pergunta[i] = '\0';
        questao ->resp1[i] = '\0';
        questao ->resp2[i] = '\0';
        questao ->resp3[i] = '\0';
    }
    questao ->correta = 0;
}

void gravarQuestaoNoArquivo(tQuestao questao)
{
    FILE  *arq;

    arq = fopen("bancoquestoes.qz", "ab");

    if (arq == NULL)
    {
        printf("\n\n Não foi possivel abrir o arquivo");
    }
    else
    {
        fwrite(&questao, sizeof(tQuestao), 1, arq);

        fclose(arq);
    }

    printf("Sua questão está sendo cadastrada");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");

    printf("\n\nSua questão foi cadastrada com exito!");

    Sleep(2500);
}

void criarQuestao()
{
    tQuestao nova;

    limparQuestao(&nova);
    printf("Criando questao...\n\n");

    printf("Digite sua pergunta: ");
    fflush(stdin);
    fgets(nova.pergunta, TAM, stdin);

    printf("Digite a primeira alternativa(1/3): ");
    fflush(stdin);
    fgets(nova.resp1, TAM, stdin);

    printf("Digite a segunda alternativa(2/3): ");
    fflush(stdin);
    fgets(nova.resp2, TAM, stdin);

    printf("Digite a terceira alternativa(3/3): ");
    fflush(stdin);
    fgets(nova.resp3, TAM, stdin);

    do{
        printf("Qual a alternativa correta: (1, 2 ou 3)");
        scanf("%d", &nova.correta);
    }while(!((nova.correta == 1) || (nova.correta == 2) || (nova.correta == 3)));


    gravarQuestaoNoArquivo(nova);

    fflush(stdin);
    getchar();
}

void configurarQuestao()
{
    char opcaoConfig;

    while(!(opcaoConfig == 'b' || opcaoConfig == 'B'))
    {
        system("cls");
        printf("Página de configuração\n\n");

        printf("A) Configurar uma nova questão no banco de questões\n");
        printf("B) Voltar para o menu principal\n");

        printf("Escolha sua opção: ");
        fflush(stdin);
        scanf("%c", &opcaoConfig);

        switch(opcaoConfig)
        {
            case 'a':
            case 'A':
                criarQuestao();
                break;

            case 'b':
            case 'B':
                break;

            default:
                printf("Opçao inválida! Aperte a tecla ENTER para tentar novamente");
                fflush(stdin);
                getchar();
                break;
        }
    }

    fflush(stdin);
}

void jogar()
{
    printf("Página para jogar");
    fflush(stdin);
    getchar();
}

void menu()
{
    int opcao;

    while (opcao != 3)
    {
        system("cls");
        printf("***************** Jogo Quiz *****************\n\n");
        printf("[1] Configurar questão\n");
        printf("[2] Jogar\n");
        printf("[3] Sair\n\n");

        printf("Escolha uma das opções acima: ");
        scanf("%i", &opcao);

        switch(opcao)
        {
            case 1:
                configurarQuestao();
                break;

            case 2:
                jogar();
                break;

            case 3:
                break;

            default:
                printf("Opção inválida!");

        }
    }
    fflush(stdin);
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    menu();
    return 0;
}
