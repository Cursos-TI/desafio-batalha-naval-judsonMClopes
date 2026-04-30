#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
// Matriz bidimensional 10x10 representando o tabuleiro, inicializada com 0 (água).
int tabuleiro [10][10] = {0};

// Exibição do título do tabuleiro no painel do console.
printf("\n ***** TABULEIRO BATALHA NAVAL *****\n\n");

// Vetor de caracteres que representa as colunas do tabuleiro  (A até J).
char linha [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

// Espaçamento inicial para alinhar as colunas com os números das linhas
printf("  ");

// Variável de controle que indica se as posições estão livres (1 = livre, 0 = ocupado).
int livre = 1;

// Loop para verificar se as posições do navio vertical estão livres.
 for (int linhaVertical = 6; linhaVertical < 9; linhaVertical++)
    {
      // Estrutura de decisão que verifica se a posição do tabuleiro já está ocupada.
      if(tabuleiro[linhaVertical][1] != 0)
      // Define 0 a variável livre; indicando posição ocupada.
      livre = 0;
    }
    // Verifica se todas as posições estão livres para posicionar o navio.
      if (livre)
      {
        // Peercorre as posições do navio vertical.
        for (int linhaVertical = 6; linhaVertical < 9; linhaVertical++)
        {
          // Posiciona o navio vertical no tabuleiro.
            tabuleiro[linhaVertical][1] = 3;
        }   
      } 
    // Redefine a variável de controle para verificar se as posições estão livres (1 = livre, 0 = ocupado).
      livre = 1;
    // Loop para verificar se as posições do navio horizontal estão livres.
    for (int colunaHorizontal = 7; colunaHorizontal <= 9; colunaHorizontal++)
        {
          // Estrutura de decisão que verifica se a posição do tabuleiro já está ocupada.
          if (tabuleiro[1][colunaHorizontal] != 0)
          // Define 0 a variável livre; indicando posição ocupada.
          livre = 0;
        }
        // Verifica se todas as posições estão livres para posicionar o navio.
          if (livre)
          {
            // Percorre as posições do navio horizontal.
            for (int colunaHorizontal = 7; colunaHorizontal <= 9; colunaHorizontal++)
            {
              // Posiciona navio horizontal no tabuleiro.
              tabuleiro[1][colunaHorizontal] = 3;
            } 
          }
          
// Percorre vetor com as letras das colunas.          
for (int colunaCab = 0; colunaCab < 10; colunaCab++)
{
  // Imprime cada letra do cabeçalho do tabuleiro.
    printf("%c ", linha[colunaCab]);
}
// Quebra de linha após o cabeçalho.
printf("\n");

// Percorre as linhas do tabuleiro.
for (int linhaExterna = 0; linhaExterna < 10; linhaExterna++)
{
  // Imprime número identificador da linha atual.
   printf("%-2d ", linhaExterna + 1);
    // Percorre as colunas da linha atual.
    for (int colunaTab = 0; colunaTab < 10; colunaTab++)
    {
      // Imprime o valor de cada posição da matriz.
        printf("%d ", tabuleiro[linhaExterna][colunaTab]);
    } 
    // Quebra de linha para exibir a próxima linha do tabuleiro.   
    printf("\n");
}
   // Encerra o programa com sucesso.
    return 0;
}

    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

