#include "sprite.h"

sprite *abrir_arquivo(char *nome_arquivo)
{
	/*
	strtok - Split string into tokens
	char * strtok ( char * str, const char * delimiters );
	C string to truncate.
	Notice that this string is modified by being broken into smaller strings (tokens).
	Alternativelly, a null pointer may be specified, in which case the function continues
	scanning where a previous successful call to the function ended.
	*/

	// Abre o arquivo
	FILE *arquivo = fopen(nome_arquivo, "r");
	if(arquivo == NULL) 
		return NULL; // Arquivo não encontrado
	
	char texto[20];
	fgets(texto, 20, arquivo);				// Lê a primeira linha, que é "P3", não é necessária
	fgets(texto, 20, arquivo);				// lê a string  que tem a quantidade de colunas e linhas do sprite
	int colunas = atoi(strtok(texto, " ")); // Parte a string em 2 e converte as partes para inteiro
	int linhas = atoi(strtok(NULL, " "));   // Depois lê a parte 2 da string, a quantidade de linhas
	fgets(texto, 20, arquivo);				// Lê a quantidade de cores, não é ncessária
	/*
	A variável colunas indica quantos pixels de largura terá o sprite.
	E a variavél linhas indica quantos pixels de altura.
	Logo, a quantidade de pixels é colunas * linhas;
	Cada pixel tem 3 cores: Red, Green e Blue (RGB), e cada linha do arquivo
	presenta uma cor. Então a cada 3 linhas do arquivo, representa um pixel
	*/

	sprite *sprite = malloc(sizeof(sprite)); // Inicializa o ponteiro
	sprite->colunas = colunas;
	sprite->linhas = linhas;
	// Aloca um vetor de pixels do tamano colunas * linhas
	sprite->pixels = malloc((colunas * linhas) * sizeof(pixel));

	for (int i = 0; i < (linhas * colunas); i++)
	{
		int red = atoi(fgets(texto, 20, arquivo));   // Linha 1 - Cor vermelha
		int green = atoi(fgets(texto, 20, arquivo)); // Linha 2 - Cor verde
		int blue = atoi(fgets(texto, 20, arquivo));  // Linha 3 - Cor azul
		// Cria o pixel a armazena no vetor de pixels
		pixel pixel;
		pixel.R = red;
		pixel.G = green;
		pixel.B = blue;
		sprite->pixels[i] = pixel;
	}
	printf("Sprite aberto - %dx%d\n", sprite->colunas, sprite->linhas);
	return sprite;
}

void desenhar_imagem(sprite *cenario, sprite *sprite, pixel *pixelFundo, int deslocamentoLinhas, int deslocamentoColunas)
{
	int contador = 0;
	for (int i = 0; i < sprite->linhas; i++)
	{		
		int indice = ((deslocamentoLinhas - 1) * cenario->colunas) + deslocamentoColunas - 1;		
		for (int j = 0; j < sprite->colunas; j++)
		{

			if (comparar_pixels(&sprite->pixels[contador], pixelFundo) == 0)
				cenario->pixels[indice] = sprite->pixels[contador];
			indice++;
			contador++;
		}
		deslocamentoLinhas++;
	}
}

int salvar_sprite(sprite *sprite, char *nome_arquivo)
{
	FILE *arquivo = fopen(nome_arquivo, "w");
	if(arquivo == NULL)
		return 0;
	fprintf(arquivo, "P3\n%d %d\n255\n", sprite->colunas, sprite->linhas);
	int i = 0;
	for (i = 0; i < sprite->colunas * sprite->linhas; i++)
	{
		pixel pixel = sprite->pixels[i];
		fprintf(arquivo, "%d\n%d\n%d\n", pixel.R, pixel.G, pixel.B);
	}
	return 1;
}
int comparar_pixels(pixel *pixel1, pixel *pixel2)
{
	int CorVermelhaIgual = pixel1->R == pixel2->R;
	int corVerdeIgual = pixel1->G == pixel2->G;
	int corBlueIgual = pixel1->B == pixel2->B;
	return CorVermelhaIgual && corVerdeIgual && corBlueIgual;
}