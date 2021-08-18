#include <stdio.h>

void leSudoku(int n,int sudoku[16][16])
{
    char s[2];
    int i,j,dim = n*n;
    for(i = 0;i < dim ; i++)
        for(j = 0;j < dim; j++)
        {
            scanf("%s",s);
            if(s[0]>= '1' && s[0]<= '9')
                sudoku[i][j] = s[0] - '0';
            if(s[0]>= 'A' && s[0] <= 'G')
                sudoku[i][j] = s[0] - 'A' + 10;
        }
}

void imprimeLinha(int n)
{
    int i,j;
    for( i = 0; i < n ;i++)
    {
        printf("+");
        for(j = 0; j < n ;j++)
            printf("---");
    }
    printf("+\n");
}

void imprimeSudoku(int n, int sudoku[16][16])
{
    int i,j,dim = n * n;
    imprimeLinha(n);
    for( i = 0; i < dim;i++)
    {
        printf("|");
        for(j = 0 ; j < dim ; j++)
        {
            int num = sudoku[i][j];
            if(num <= 9)
                printf("%2d ", num);
            else
                printf("%2c ",num - 10 + 'A');
            if((j + 1) % n == 0)
                printf("|");
        }
        printf("\n");
        if((i + 1) % n ==0)
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

int sudokuOk(int n, int sudoku[16][16],int *lin, int *col)
{
    // verificar se dentro da regiao(n) tem algum numero igual
    // definir as regioes fazendo for dentro de 2 for 
    // verificar se na linha ha numeros iguais
    // verificar se na coluna ha numeros iguais
    int i=0,j=n,p=0,k,l=0,countUm=0,countDois=0,countTres=0,countQuatro=0,countCinco=0,countSeis=0,countSete=0,countOito=0,countNove=0;

            while(p < n * n){      
                for(k = i;k < j; k++){      
                    if(sudoku[k][l] == 1)
                        countUm++; 
                    else if(sudoku[k][l] == 2)
                            countDois++;
                        else if (sudoku[k][l] == 3)
                                countTres++;
                            else if (sudoku[k][l] == 4)
                                    countQuatro++;
                                else if(sudoku[k][l] == 5)
                                        countCinco++;
                                    else if(sudoku[k][l] == 6)
                                            countSeis++;
                                        else if(sudoku[k][l] == 7)
                                                countSete++;
                                            else if(sudoku[k][l] == 8)
                                                    countOito++;
                                                else if(sudoku[k][l] == 9)
                                                        countNove++;
                    if(countUm > 1 ||countDois > 1 ||countTres > 1 ||countQuatro > 1 ||countCinco > 1 ||countSeis > 1 ||countSete > 1 ||countOito > 1 ||countNove > 1 ){
                        *lin = k;
                        *col = l;
                        printf("Valor duplicado na posicao sudoku[%d][%d]",k,l);
                        return 0;
                    }
                    printf("sodoku[%d][%d] = %d\n",k,l,sudoku[k][l]);
                }
                
                l++;
                if(l % 3 == 0){
                    countUm=0;
                    countDois=0;
                    countTres=0;
                    countQuatro=0;
                    countCinco=0;
                    countSeis=0;
                    countSete=0;
                    countOito=0;
                    countNove=0;
                    p++;
                }
                if(l >= n * n){
                    l = 0;
                    i = i + n;
                    j = j + n;
                }
                
            }
    
}

int main(void)
{
    int n, nlin, ncol, ok;
    int sudoku[16][16];
    scanf("%d",&n);
    leSudoku(n,sudoku);
    imprimeSudoku(n,sudoku);
    ok = sudokuOk(n,sudoku,&nlin,&ncol);
    if (ok)
        puts("Sudoku Ok!");
    else
        printf("Erro na posicao (%d,%d)\n",nlin,ncol);
    return 0;
}