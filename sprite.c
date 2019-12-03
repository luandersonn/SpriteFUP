#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sprite.h"

int main()
{
	sprite cenario = abrir_arquivo("sprites/stageGuile.ppm");
	sprite ryu = abrir_arquivo("sprites/ryu2.ppm");	
	return 0;
}

sprite abrir_arquivo(char *nome_arquivo)
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
	char texto[20];
	fgets(texto, 20, arquivo);				// Lê a primeira linha, que é "P3", não é necessária
	fgets(texto, 20, arquivo);				// lê a string  que tem a quantidade de colunas e linhas do sprite
	int colunas = atoi(strtok(texto, " ")); // Parte a string em 2 e converte as partes para inteiro
	int linhas = atoi(strtok(NULL, " "));   // Depois lê a parte 2 da string, a quantidade de linhas
	fgets(texto, 20, arquivo);				// Lê a quantidade de cores, não é ncessária
	/*
	A variável colunas indica quantos pixels de altura terá o sprite.
	E a variavél linhas indica quantos pixels de largura.
	Logo, a quantidade de pixels é colunas * linhas;
	Cada pixel tem 3 cores: Red, Green e Blue (RGB), e cada linha do arquivo
	presenta uma cor. Então a cada 3 linhas do arquivo, representa um pixel
	 */

	sprite sprite;
	sprite.colunas = colunas;
	sprite.linhas = linhas;
	// Aloca um vetor de pixels do tamano colunas * linhas
	sprite.pixels = malloc((colunas * linhas) * sizeof(pixel)); 

	for (int i = 0; i < (linhas * colunas) / 3; i++)
	{
		int red = atoi(fgets(texto, 20, arquivo));   // Linha 1 - Cor vermelha
		int green = atoi(fgets(texto, 20, arquivo)); // Linha 2 - Cor verde
		int blue = atoi(fgets(texto, 20, arquivo));  // Linha 3 - Cor azul
		// Cria o pixel a armazena no vetor de pixels
		pixel pixel;
		pixel.R = red;
		pixel.G = green;
		pixel.B = blue;				
		sprite.pixels[i] = pixel;
	}
	return sprite;
}
