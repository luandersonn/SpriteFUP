#include "sprite.h"

int main()
{
    // Abre o cenário
    printf("Digite o nome do arquivo de cenario: ");
    char nome_arquivo[50];
    scanf("%s", nome_arquivo);
    sprite *cenario;
    // Enquanto o arquivo do cenário for inválido, tenta ler novamente
    while ((cenario = abrir_arquivo(nome_arquivo)) == NULL)
    {
        printf("Arquivo nao encontrado, tente novamente: ");
        scanf("%s", nome_arquivo);
    }

    // Abre o sprite 1
    printf("Digite o nome do arquivo do sprite 1: ");
    scanf("%s", nome_arquivo);
    sprite *sprite1;
    // Enquanto o arquivo do sprite 1 for inválido, tenta ler novamente
    while ((sprite1 = abrir_arquivo(nome_arquivo)) == NULL)
    {
        printf("Arquivo nao encontrado, tente novamente: ");
        scanf("%s", nome_arquivo);
    }

    // Informa a cor de background do sprite 1
    pixel cor_fundo_sprite1;
    printf("Digite a cor de fundo RGB (separado por espacos): ");
    scanf("%d", &cor_fundo_sprite1.R);
    scanf("%d", &cor_fundo_sprite1.G);
    scanf("%d", &cor_fundo_sprite1.B);

    // Lê o deslocamento da imagem
    int linhaDeslocamento;
    int colunaDeslocamento;
    printf("Digite o deslocamento de colunas linhas (separado por espaco): ");
    int valores_invalidos = 0;
    do
    {
        valores_invalidos = 0;
        scanf("%d", &linhaDeslocamento);
        scanf("%d", &colunaDeslocamento);

        if (linhaDeslocamento < 1 || colunaDeslocamento < 1)
        {
            printf("Somente numeros positivos. Digite novamente: ");
            valores_invalidos = 1;
        }
        else if (cenario->linhas - linhaDeslocamento < sprite1->linhas)
        {
            printf("Deslocamente de linhas grande demais, digite um valor menor: ");
            valores_invalidos = 1;
        }
        else if (cenario->colunas - colunaDeslocamento < sprite1->colunas)
        {
            printf("Deslocamente de colunas grande demais, digite um valor menor: ");
            valores_invalidos = 1;
        }
    } while (valores_invalidos);

    printf("Desenhando os sprites no cenario, aguarde... ");
    //Desenha o sprite no cenario
    desenhar_imagem(cenario, sprite1, &cor_fundo_sprite1, linhaDeslocamento, colunaDeslocamento);
    printf("Concluido\n");
    printf("Digite o nome do arquivo de destino: ");
    scanf("%s", nome_arquivo);
    while ((salvar_sprite(cenario, nome_arquivo)) == 0)
    {
        printf("Nao foi possivel salvar o arquivo com este nome, tente novamente com outro nome: ");
        scanf("%s", nome_arquivo);
    }
    printf("Salvo");
    return 0;
}
