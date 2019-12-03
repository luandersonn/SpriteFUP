/* Representa um pixel da imagem */
typedef struct pixel
{
    int R;
    int G;
    int B;
} pixel;

typedef struct sprite
{
    int colunas;   // Altura do sprite
    int linhas;    // Largura do sprite
    pixel *pixels; // Vetor de pixels
} sprite;

/* Abre o arquivo e cria o sprite */
sprite abrir_arquivo(char *nome_arquivo);
void desenhar_imagem(sprite *cenario, sprite *sprite, pixel *pixelFundo, int deslocamentoLinhas, int deslocamentoColunas);
int comparar_pixels(pixel *pixel1, pixel *pixel2);
void salvar_sprite(sprite *sprite, char *nome_arquivo);