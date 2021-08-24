/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
2 ∗ UNIFAL − Universidade Federal de Alfenas .
3 ∗ BACHARELADO EM CIENCIA DA COMPUTACAO.
4 ∗ Trabalho . . : Atividade 4
5 ∗ Disciplina : Programacao
6 ∗ Professor . : Luiz Eduardo da Silva
7 ∗ Aluno . . . . . : Eduardo Sapio Saccardo
8 ∗ Data . . . . . . : 19/08/2021
9 ∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

#include <stdio.h>

void leSudoku(int n, int sudoku[16][16])
{
    char s[2];
    int i, j, dim = n * n;
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
        {
            scanf("%s", s);
            if (s[0] >= '1' && s[0] <= '9')
                sudoku[i][j] = s[0] - '0';
            if (s[0] >= 'A' && s[0] <= 'G')
                sudoku[i][j] = s[0] - 'A' + 10;
        }
}

void imprimeLinha(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("+");
        for (j = 0; j < n; j++)
            printf("---");
    }
    printf("+\n");
}

void imprimeSudoku(int n, int sudoku[16][16])
{
    int i, j, dim = n * n;
    imprimeLinha(n);
    for (i = 0; i < dim; i++)
    {
        printf("|");
        for (j = 0; j < dim; j++)
        {
            int num = sudoku[i][j];
            if (num <= 9)
                printf("%2d ", num);
            else
                printf("%2c ", num - 10 + 'A');
            if ((j + 1) % n == 0)
                printf("|");
        }
        printf("\n");
        if ((i + 1) % n == 0)
            imprimeLinha(n);
    }
}

/* --------------------------------------------
* Funcao que testa uma solucao do sudoku
* Parametros :
*   n = dimensao das regioes
*   sudoku - jogo preenchido
*   lin - linha do erro ( se houver)
*   col - coluna do erro ( se houver)
* Retorna :
*    1 se a matriz e uma solucao do problema
*    0 caso contrario, modificando os parametros
*   lin e col para indicar a linha e coluna onde foi detectado o problema
*------------------------------------------------*/

int sudokuOk(int n, int sudoku[16][16], int *lin, int *col)
{
    // verificar se dentro da regiao(n) tem algum numero igual
    // verificar se na linha ha numeros iguais
    // verificar se na coluna ha numeros iguais
    int i = 0, j = n, p = 0, k, l = 0, a, c, d = 0, b = 0, countUm = 0, countDois = 0, countTres = 0, countQuatro = 0, countCinco = 0, countSeis = 0, countSete = 0, countOito = 0, countNove = 0;
    int countDez = 0, countOnze = 0, countDoze = 0, countTreze = 0, countQuatorze = 0, countQuinze = 0, countDezesseis = 0;
    while (p < n * n)   
    {
        for (k = i; k < j; k++) //percorre 3 linhas  sai do for incrementa l(coluna) percorre + 3 linhas 
        {
            if (sudoku[k][l] == 1)
                countUm++;
            else if (sudoku[k][l] == 2)
                countDois++;
            else if (sudoku[k][l] == 3)
                countTres++;
            else if (sudoku[k][l] == 4)
                countQuatro++;
            else if (sudoku[k][l] == 5)
                countCinco++;
            else if (sudoku[k][l] == 6)
                countSeis++;
            else if (sudoku[k][l] == 7)
                countSete++;
            else if (sudoku[k][l] == 8)
                countOito++;
            else if (sudoku[k][l] == 9)
                countNove++;
            else if (sudoku[k][l] == 'A')
                countDez++;
            else if (sudoku[k][l] == 'B')
                countOnze++;
            else if (sudoku[k][l] == 'C')
                countDoze++;
            else if (sudoku[k][l] == 'D')
                countTreze++;
            else if (sudoku[k][l] == 'E')
                countQuatorze++;
            else if (sudoku[k][l] == 'F')
                countQuinze++;
            else if (sudoku[k][l] == 'G')
                countDezesseis++;
            if (countUm > 1 || countDois > 1 || countTres > 1 || countQuatro > 1 || countCinco > 1 || countSeis > 1 || countSete > 1 || countOito > 1 || countNove > 1 || countDez > 1 || countOnze > 1 || countDoze > 1 || countTreze > 1 || countQuatorze > 1 || countQuinze > 1 || countDezesseis > 1)
            {
                *lin = k;
                *col = l;
                // printf("Valor duplicado na regiao sudoku[%d][%d]\n",k,l);
                return 0;
            }
            printf("sodoku[%d][%d] = %d\n",k,l,sudoku[k][l]);
        }

        l++;
        if (l % 3 == 0)     // se nao houver erro na regiao zera todos os contadores
        {
            countUm = 0;
            countDois = 0;
            countTres = 0;
            countQuatro = 0;
            countCinco = 0;
            countSeis = 0;
            countSete = 0;
            countOito = 0;
            countNove = 0;
            countDez = 0;
            countOnze = 0;
            countDoze = 0;
            countTreze = 0;
            countQuatorze = 0;
            countQuinze = 0;
            countDezesseis = 0;
            p++;
        }
        if (l >= n * n) 
        {
            l = 0;
            i = i + n;
            j = j + n;
        }
    }

    while (b < n * n)
    {
        for (a = 0; a < n * n; a++)
        {
            if (sudoku[a][b] == 1)
                countUm++;
            else if (sudoku[a][b] == 2)
                countDois++;
            else if (sudoku[a][b] == 3)
                countTres++;
            else if (sudoku[a][b] == 4)
                countQuatro++;
            else if (sudoku[a][b] == 5)
                countCinco++;
            else if (sudoku[a][b] == 6)
                countSeis++;
            else if (sudoku[a][b] == 7)
                countSete++;
            else if (sudoku[a][b] == 8)
                countOito++;
            else if (sudoku[a][b] == 9)
                countNove++;
            else if (sudoku[a][b] == 'A')
                countDez++;
            else if (sudoku[a][b] == 'B')
                countOnze++;
            else if (sudoku[a][b] == 'C')
                countDoze++;
            else if (sudoku[a][b] == 'D')
                countTreze++;
            else if (sudoku[a][b] == 'E')
                countQuatorze++;
            else if (sudoku[a][b] == 'F')
                countQuinze++;
            else if (sudoku[a][b] == 'G')
                countDezesseis++;
            if (countUm > 1 || countDois > 1 || countTres > 1 || countQuatro > 1 || countCinco > 1 || countSeis > 1 || countSete > 1 || countOito > 1 || countNove > 1 || countDez > 1 || countOnze > 1 || countDoze > 1 || countTreze > 1 || countQuatorze > 1 || countQuinze > 1 || countDezesseis > 1)
            {
                *lin = a;
                *col = b;
                printf("Valor duplicado na Linha sudoku[%d][%d]", a, b);
                return 0;
            }
        }
        countUm = 0;
        countDois = 0;
        countTres = 0;
        countQuatro = 0;
        countCinco = 0;
        countSeis = 0;
        countSete = 0;
        countOito = 0;
        countNove = 0;
        countDez = 0;
        countOnze = 0;
        countDoze = 0;
        countTreze = 0;
        countQuatorze = 0;
        countQuinze = 0;
        countDezesseis = 0;
        b++;
    }

    while (d < n * n)
    {
        for (c = 0; c < n * n; c++)
        {
            if (sudoku[d][c] == 1)
                countUm++;
            else if (sudoku[d][c] == 2)
                countDois++;
            else if (sudoku[d][c] == 3)
                countTres++;
            else if (sudoku[d][c] == 4)
                countQuatro++;
            else if (sudoku[d][c] == 5)
                countCinco++;
            else if (sudoku[d][c] == 6)
                countSeis++;
            else if (sudoku[d][c] == 7)
                countSete++;
            else if (sudoku[d][c] == 8)
                countOito++;
            else if (sudoku[d][c] == 9)
                countNove++;
            else if (sudoku[d][c] == 'A')
                countDez++;
            else if (sudoku[d][c] == 'B')
                countOnze++;
            else if (sudoku[d][c] == 'C')
                countDoze++;
            else if (sudoku[d][c] == 'D')
                countTreze++;
            else if (sudoku[d][c] == 'E')
                countQuatorze++;
            else if (sudoku[d][c] == 'F')
                countQuinze++;
            else if (sudoku[d][c] == 'G')
                countDezesseis++;
            if (countUm > 1 || countDois > 1 || countTres > 1 || countQuatro > 1 || countCinco > 1 || countSeis > 1 || countSete > 1 || countOito > 1 || countNove > 1 || countDez > 1 || countOnze > 1 || countDoze > 1 || countTreze > 1 || countQuatorze > 1 || countQuinze > 1 || countDezesseis > 1)
            {
                *lin = d;
                *col = c;
                printf("Valor duplicado na Coluna sudoku[%d][%d]", d, c);
                return 0;
            }
        }
        countUm = 0;
        countDois = 0;
        countTres = 0;
        countQuatro = 0;
        countCinco = 0;
        countSeis = 0;
        countSete = 0;
        countOito = 0;
        countNove = 0;
        countDez = 0;
        countOnze = 0;
        countDoze = 0;
        countTreze = 0;
        countQuatorze = 0;
        countQuinze = 0;
        countDezesseis = 0;
        d++;
    }
}

int main(void)
{
    int n, nlin, ncol, ok;
    int sudoku[16][16];
    scanf("%d", &n);
    leSudoku(n, sudoku);
    imprimeSudoku(n, sudoku);
    ok = sudokuOk(n, sudoku, &nlin, &ncol);
    if (ok)
        puts("Sudoku Ok!");
    else
        printf("Erro na posicao (%d,%d)\n", nlin, ncol);
    return 0;
}