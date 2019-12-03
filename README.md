##### Universidade Federal do Ceará - Fundamentos de Programação
##### Prof. Rafael Ivo

# Trabalho Parcial 3A – Combinação de Sprites

### Regras Gerais:

- O trabalho deve ser feito em equipes de até 4 pessoas.
- O envio do trabalho será exclusivamente no SIGAA, no prazo estipulado.
- Utilize boas regras de programação como: identação de código, nomes intuitivos para as variáveis e
    comentários explicando as ideias utilizadas
- O topo do arquivo do código-fonte deve conter um comentário com os nomes completos dos
    integrantes da equipe e seus números de matrícula.
- Trabalhos copiados receberão nota zero, independente se comprove ser o trabalho original.

### Descrição:

Na época em que jogos em duas dimensões eram o máximo de que o hardware de um usuário padrão era
capaz de exibir, todas as cenas de todos os jogos precisavam ser compostas através de diversas imagens
bidimensionais posicionadas de tal modo que representavam o posicionamento específico de cada um dos
elementos que compunham as cenas. Estes objetos exibidos em duas dimensões, que geralmente compõem
elementos de fundo ou são sobrepostos, são chamados **_sprites_**. Em consoles como o Super Nintendo, cada
sprite poderia ter até 16 cores, com cada cor pertencente a uma paleta pré-definida. Uma das cores dessa
paleta era a transparência, para pemitir a inserção da imagem do sprite sem a detecção de alguma borda.
Atualmente, computadores podem processar milhares de cores definidos em diversos tipos de sistemas. Entre
eles está o **_RGB_** que utiliza uma combinação de cores vermelho, verde e azul para exibir uma paleta de mais
de 10 mil cores.

O trabalho consiste em ler três imagens: Uma contendo um cenário de fundo e duas contendo um
personagem cada:

<img src="Arquivos/Imagem 01.png">

Os nomes dos arquivos devem ser pedidos para o usuário. Verifique se o arquivo passado é válido. Caso não
seja, continue pedindo.


O usuário deve informar a posição de cada personagem. Essa posição é a distância entre os cantos superior
esquerdo entre a imagem do personagem e a imagem do cenário:

<img src="Arquivos/Imagem 02.png">

O usuário também deve informar a cor de fundo presente nas imagens dos personagens:

<img src="Arquivos/Imagem 03.png"   >

Peça do usuário um nome de arquivo e salve uma imagem com a mesma resolução da imagem do cenário. As
cores dos sprites dos personagens devem se sobrepor as cores do cenário, exceto se ela for igual a cor de
fundo definida pelo usuário.

<img src="Arquivos/Imagem 04.png">

### Regras de Implementação:

- O formato de imagem a ser utilizado será o PPM (Portable Pix Map). Mais informações abaixo.
- O programa deve ser genérico a ponto de funcionar com qualquer imagem de fundo e imagens de
    personagens.
- Não permita que o usuário insira uma posição onde o personagem esteja parcialmente fora do
    cenário.
- Pode haver interseção entre as imagens dos personagens na imagem final.


### Cores RGB

RGB é a abreviatura de um sistema de cores aditivas em que o Vermelho (Red), o Verde (Green) e o Azul
(Blue) são combinados de várias formas de modo a reproduzir um largo espectro cromático. O propósito
principal do sistema RGB é a reprodução de cores em dispositivos eletrônicos como monitores de TV e
computador, retroprojetores, scanners e câmeras digitais, assim como na fotografia tradicional.

Uma cor no modelo de cores RGB pode ser descrita pela indicação da quantidade de vermelho, verde e azul
que contém. Cada uma pode variar entre o mínimo (completamente escuro) e máximo (completamente
intenso). Quando todas as cores estão no mínimo, o resultado é preto. Se todas estão no máximo, o resultado
é branco.

Uma das representações mais usuais para as cores é a utilização da escala de 0 à 255, bastante encontrada na
computação pela conveniência de se guardar cada valor de cor em 1 byte (8 bits). Assim, o vermelho
completamente intenso é representado por 255, 0, 0.

<img src="Arquivos/Imagem 05.png">

### Imagens PPM

Esse formato de imagem permite criar e editar imagens em modo de texto ASCII. Cada arquivo inicia com um cabeçalho: os caracteres “P3”. Então, informa-se a resolução da imagem ( _linhas × colunas_ ) e a quantidade de tonalidades dos canais de cor: o valor máximo no caso é 255. Depois desse cabeçalho, três
números inteiros indicam a cor de cada pixel. Os pixels são descritos na ordem de cima para baixo, da esquerda para a direita, linha após linha. Obs: Não existe a obrigatoriedade dos dados da imagem estarem dispostos como no exemplo abaixo, eles foram colocados dessa forma para tornar mais claro a correlação
entre os dados gravados e a forma da imagem mostrada. Exemplo de uma imagem de 5 pixels de largura e 5 pixels de altura:

<img src="Arquivos/Imagem 06.png">

> “Obrigado Mario! Mas nossa princesa está em outro castelo!” (Super Mário)

