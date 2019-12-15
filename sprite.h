#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Representa um pixel da imagem por cores RGB */
typedef struct pixel
{
    int R;
    int G;
    int B;
} pixel;

typedef struct sprite
{
    int colunas;   // Largura do sprite
    int linhas;    // Altura do sprite
    pixel *pixels; // Vetor de pixels
} sprite;

/* Abre o arquivo e cria o sprite */
sprite *abrir_arquivo(char *nome_arquivo);
/* Desenha um sprite sobre o outro */
void desenhar_imagem(sprite *cenario, sprite *sprite, pixel *pixelFundo, int deslocamentoLinhas, int deslocamentoColunas);
/* Compara se dois pixels são iguais */
int comparar_pixels(pixel *pixel1, pixel *pixel2);
/* Salva o sprite em arquivo */
int salvar_sprite(sprite *sprite, char *nome_arquivo);