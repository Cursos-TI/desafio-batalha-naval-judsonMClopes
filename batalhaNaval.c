// Biblioteca usada para funções de entrada e saída, necessária para usar printf e scanf.
#include <stdio.h>

// Constante que define o número de linhas do tabuleiro.
#define LINHAS 10
// Constante que define o número de colunas do tabuleiro.
#define COLUNAS 10
// Constante que define o tamanho das habilidades especiais.
#define TAM_HAB_ESPC 5


// Função principal onde o programa começa a executar, retorna um valor inteiro ao sistema operacional.
int main() {

// Matriz bidimensional 10x10 representando o tabuleiro, inicializada com 0 (água).
int tabuleiro [LINHAS][COLUNAS] = {0};

// Exibição do título do tabuleiro no painel do console.
printf("\n ***** TABULEIRO BATALHA NAVAL *****\n\n");

// Vetor de caracteres que representa as colunas do tabuleiro  (A até J).
char linha [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

// Espaçamento inicial para alinhar as colunas com os números das linhas.
printf("   ");

// Variável de controle que indica se as posições estão livres (1 = livre, 0 = ocupado).
int livre = 1;

// Loop para verificar se as posições do navio vertical estão livres.
 for (int linhaVertical = 0; linhaVertical < 3; linhaVertical++)
    {
      // Estrutura de decisão que verifica se a posição do tabuleiro já está ocupada.
      if(tabuleiro[linhaVertical][6] != 0)
      // Define 0 a variável livre; indicando posição ocupada.
      livre = 0;
    }
    // Verifica se todas as posições estão livres para posicionar o navio.
      if (livre)
      {
        // Peercorre as posições do navio vertical.
        for (int linhaVertical = 0; linhaVertical < 3; linhaVertical++)
        {
          // Posiciona o navio vertical no tabuleiro.
            tabuleiro[linhaVertical][6] = 3;
        }   
      } 
    // Redefine a variável de controle para verificar se as posições estão livres (1 = livre, 0 = ocupado).
      livre = 1;
    // Loop para verificar se as posições do navio horizontal estão livres.
    for (int colunaHorizontal = 0; colunaHorizontal < 3; colunaHorizontal++)
        {
          // Estrutura de decisão que verifica se a posição do tabuleiro já está ocupada.
          if (tabuleiro[0][colunaHorizontal] != 0)
          // Define 0 a variável livre; indicando posição ocupada.
          livre = 0;
        }
        // Verifica se todas as posições estão livres para posicionar o navio.
          if (livre)
          {
            // Percorre as posições do navio horizontal.
            for (int colunaHorizontal = 0; colunaHorizontal < 3; colunaHorizontal++)
            {
              // Posiciona navio horizontal no tabuleiro.
              tabuleiro[0][colunaHorizontal] = 3;
            } 
          }
          // Redefine a variávle de controle para verificar se as posições estão livres (1 = livre e 0 = ocupado)
          livre = 1;
          // Loop para verificar se as posições do navio diagonal principal estão livres.
          for (int diagonalPrincipal = 7; diagonalPrincipal <= 9; diagonalPrincipal++)
          {
            // Estrutura de decisão que verifica se a posição do tabuleiro já está ocupada.
            if (tabuleiro[diagonalPrincipal][diagonalPrincipal] != 0)
            // Define 0 a variável livre; indicando posição ocupada.
              livre = 0;
          }
          // Verifica se todas as posições estão livres para posicionar o navio.
          if (livre)
          {
            // Percorre as posições do navio diagonal principal.
              for (int diagonalPrincipal = 7; diagonalPrincipal <= 9; diagonalPrincipal++)
            {
            // Posiciona navio diagonal principal no tabuleiro.
            tabuleiro[diagonalPrincipal][diagonalPrincipal] = 3;
            }
          }
  // Redefine a variável de controle para verificar se as posições estão livres (1 = livre, 0 = ocupado).
        livre = 1;
        // Loop para verificar se as posições do navio diagonal secundária estão livres.
        for (int diagonalSecundaria = 0; diagonalSecundaria < 3; diagonalSecundaria++)
        {
          // Estrutura de decisão que verifica se a posição do tabuleiro já está ocupada.
          if (tabuleiro[diagonalSecundaria][9 - diagonalSecundaria] != 0)
          {
            // Define 0 a variável livre; indicando posição ocupada.
            livre = 0;
          } 
        }
        // Verifica se todas as posições estão livres para posicionar o navio.
        if (livre)
        {
          // Percorre todas as posições do navio diagonal secundária.
          for (int diagonalSecundaria = 0; diagonalSecundaria < 3; diagonalSecundaria++)
          {
            // Posiciona navio diagonal secundária no tabuleiro.
            tabuleiro[diagonalSecundaria][9 - diagonalSecundaria] = 3;
          }
          
        }

  // MATRIZES DE HABILIDADE (5x5)
  // Cada posição vale 1 se é afetada pela habilidade, 0 caso contrário.
  // Matrizes das três habilidades, inicializadas com 0.
  int cone[TAM_HAB_ESPC][TAM_HAB_ESPC] = {0};
  int cruz[TAM_HAB_ESPC][TAM_HAB_ESPC] = {0};
  int octaedro[TAM_HAB_ESPC][TAM_HAB_ESPC] = {0};

  // Centro da matriz de habilidade (índice 2 para tamanho 5)
  int centro = TAM_HAB_ESPC / 2;

  // Construção do CONE 
  // O cone aponta para baixo: na linha i, as colunas afetadas vão de
  // (centro - i) até (centro + i), alargando conforme desce.
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < TAM_HAB_ESPC; j++)
    {
      // Célula afetada se estiver dentro da faixa permitida para a linha i.
      if (j >= centro - i && j <= centro +i)
        cone[i][j] = 1;
        
        else
          cone[i][j] = 0;
    }
    
  }

     // Construção da CRUZ
     // Afeta toda a linha central e toda a coluna central da matriz.
      for (int i = 0; i < TAM_HAB_ESPC; i++)
      {
        for (int j = 0; j < TAM_HAB_ESPC; j++)
        {

          // Célula afetada se estiver na linha do meio OU na coluna do meio.
          if (i == centro || j == centro)
            cruz[i][j] = 1;

          else
            cruz[i][j] = 0;
          
        }
        
      }

  // Construção do OCTAEDRO (losango)
  // Afeta as células cuja distância de Manhattan ao centro é <= raio (centro).
  // Distância de Manhattan = |i - centro| + |j - centro|
  for (int i = 0; i < TAM_HAB_ESPC; i++)
  {
    for (int j = 0; j < TAM_HAB_ESPC; j++)
    {
      // Calcula distância de Manhattan sem usar abs()
      int distI = (i - centro) >= 0 ? (i - centro) : (centro - i);
      int distJ = (j - centro) >= 0 ? (j - centro) : (centro - j);
 
      // Célula afetada se a soma das distâncias for menor ou igual ao raio.
      if (distI + distJ <= centro)
        octaedro[i][j] = 1;
      else
        octaedro[i][j] = 0;
    }
  }
      
   // SOBREPOSIÇÃO DO CONE ao tabuleiro
  // Origem = topo da ponta do cone (linha 1, coluna 2).
  // A linha i da matriz vira origemConeL + i no tabuleiro (desce a partir da ponta).
  // A coluna j da matriz vira origemConeC + (j - centro) (centraliza na coluna).
  int origemConeL = 1, origemConeC = 2;

  for (int i = 0; i < TAM_HAB_ESPC; i++)
  {
    for (int j = 0; j < TAM_HAB_ESPC; j++)
    {
      int tabL = origemConeL + i; // Desce a partir da ponta. 
      int tabC = origemConeC + (j - centro); // Centraliza na coluna.

      // Verifica limites do tabuleiro antes de marcar.
      if (tabL >= 0 && tabL < LINHAS && tabC >= 0 && tabC < COLUNAS)
      {
        // Marca com 5 se a célula for afetada e não houver navio.
        if (cone[i][j] == 1 && tabuleiro[tabL][tabC] != 3)
        tabuleiro[tabL][tabC] = 5;
      }
      
    }
    
  }

  // SOBREPOSIÇÃO DA CRUZ ao tabuleiro
  // Origem = centro da cruz (linha 5, coluna 5).
  int origemCruzL = 7, origemCruzC = 2;
 
  for (int i = 0; i < TAM_HAB_ESPC; i++)
  {
    for (int j = 0; j < TAM_HAB_ESPC; j++)
    {
      // Offset em relação ao centro: (i - centro) e (j - centro).
      int tabL = origemCruzL + (i - centro);
      int tabC = origemCruzC + (j - centro);
 
      // Verifica limites do tabuleiro antes de marcar.
      if (tabL >= 0 && tabL < LINHAS && tabC >= 0 && tabC < COLUNAS)
      {
        // Marca com 5 se a célula for afetada e não houver navio.
        if (cruz[i][j] == 1 && tabuleiro[tabL][tabC] != 3)
          tabuleiro[tabL][tabC] = 5;
      }
    }
  }
 
  // SOBREPOSIÇÃO DO OCTAEDRO ao tabuleiro
  // Origem = centro do losango (linha 7, coluna 4).
  int origemOctL = 5, origemOctC = 6;
 
  for (int i = 0; i < TAM_HAB_ESPC; i++)
  {
    for (int j = 0; j < TAM_HAB_ESPC; j++)
    {
      // Offset em relação ao centro: (i - centro) e (j - centro).
      int tabL = origemOctL + (i - centro);
      int tabC = origemOctC + (j - centro);
 
      // Verifica limites do tabuleiro antes de marcar.
      if (tabL >= 0 && tabL < LINHAS && tabC >= 0 && tabC < COLUNAS)
      {
        // Marca com 5 se a célula for afetada e não houver navio.
        if (octaedro[i][j] == 1 && tabuleiro[tabL][tabC] != 3)
          tabuleiro[tabL][tabC] = 5;
      }
    }
  }
  
        
// Percorre vetor com as letras das colunas.          
for (int colunaCab = 0; colunaCab < COLUNAS; colunaCab++)
{
  // Imprime cada letra do cabeçalho do tabuleiro.
    printf("%c ", linha[colunaCab]);
}
// Quebra de linha após o cabeçalho.
printf("\n");

// Percorre as linhas do tabuleiro.
for (int linhaExterna = 0; linhaExterna < LINHAS; linhaExterna++)
{
  // Imprime número identificador da linha atual.
   printf("%-2d ", linhaExterna + 1);
    // Percorre as colunas da linha atual.
    for (int colunaTab = 0; colunaTab < COLUNAS; colunaTab++)
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