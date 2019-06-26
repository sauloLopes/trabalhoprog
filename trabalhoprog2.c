#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int tabuleiroJogo(int m, char tabuleiro[][m], char tabuleirofc[][m])
{
    int i,j,h;

    //Printa o tabuleiro

    printf("\n");

    printf("%4c", ' ');

    for (h=0;h<m;h++)
        printf("%02d ", h);

    printf("\n");

    for (i=0,h=0;i<m,h<m;i++,h++)
    {
        printf("%02d| ", h);
        for (j=0;j<m;j++)
        {
            printf("%c  ", tabuleirofc[i][j]);
        }
        printf("%-c\b",'|');
        printf("\n");
    }
    return 0; 
}

int conferePalavras(int m, char tabuleiro[][m], char tabuleirofc[][m], char palavras[][16], int np, int x, int y)
{
    int i, j, ok, len, comp, pos;
    char string[16];

    printf("Coordenadas: %d %d\n", x, y);

    printf("Tabuleiro na posição x,y: %c\n", tabuleiro[x][y]);

    for (i=0;i<np*2;i++)
    {
        if (tabuleiro[x][y]== palavras[0][i]) //Confere se alguma palavra do tabuleiro começa com a letra da posição indicada.
        {
            printf("Entrou aqui no loop %d\n", i);

            len = strlen(palavras[i]);

            pos = i;

            //Confere se a palavra está na horizontal

            for (i=0,j=y;i<len;i++,j++)
            {
                string[i]=tabuleiro[x][j];
            }
            if (strcmp(string,palavras[pos]))
            {
                printf("A palavra tá aqui\n");
                printf("Palavra: %s\n", string);
                printf("Na matriz: %s\n", palavras[pos]);

                ok = 1;

                break;
            }
            else
            {
                printf("Nao foi irmao\n");
            }            
        }
    }
    return ok;
}

void execJogo(char *j1, char *j2, int m, char tabuleiro[][m], char palavras[][16],int nj, int np, char tabuleirofc[][m])
{
    int r1=0, r2=0;
    int p1=0, p2=0;
    int i, ok;
    int x, y;

   *while ((r1<np && r2<np) || n1<nj && n2<nj)

    printf("\n");
        
    printf("|            Palavras Restantes           |\n|%-16s(%02d)|%-16s(%02d)|\n", j1, p1, j2, p2);
    printf("|--------------------|--------------------|\n");

    for (i=0;i<np;i++)
    {
        printf("|%-20s|", palavras[i]);
        printf("%-20s|\n", palavras[np+i]);
    }

    tabuleiroJogo(m,tabuleiro,tabuleirofc);

    printf("\n%s por favor entre com as coordenadas para sua jogada:\n", j1);

    scanf("%d%d", &x, &y);

    //Confere se uma palavra foi encontrada

    printf("Posição x,y: %c\n", tabuleiro[x][y]);

    ok = conferePalavras(m,tabuleiro,tabuleirofc,palavras,np,x,y);

    //fimDeJogo(p1,p2);    
}*/

/*void fimDeJogo (int p1, int p2)
{
    if (p1>p2)
        printf("%s Ganhou!!!", j1);
    else if (p2>p1)
        printf("%s Ganhou!!!", j2);
    else (p1==p2)
        printf("Empate");
}*/

void limpaMat(char palavras[][16],int np, int m, char tabuleiro[][m])
{
    int i,j;

    for (i=0;i<25;i++)
        for (j=0;j<16;j++)
        {
            if (palavras[i][j]=='\n')
            {
                palavras[i][j]=' ';
            }
        }

    for (i=0;i<m;i++)
        for (j=0;j<m;j++)
        {
            if (tabuleiro[m][m]=='\n')
            {
                tabuleiro[m][m]=' ';
            }
        }
}

void criaTabuleiro(int m, char tabuleirofc[m][m])
{
    int i,j;

    for (i=0;i<m;i++)
        for (j=0;j<m;j++)
        {
            tabuleirofc[i][j]='-';
        }
}

int main(int argc, char *argv)
{
    char j1[16];
    char j2[16];
    
    char tabuleiro[100][100];

    char palavras[25][16];

    int m, n, nj, np;

    FILE *pont_config;
    FILE *pont_saida;

    pont_config = fopen("config.txt", "r");

    if (pont_config==NULL)
    {
        printf("Erro, nao foi possivel abrir o arquivo!");
        exit (1);
    }
    else
    {
        fscanf(pont_config,"%d\n", &nj);

        fscanf(pont_config,"%d\n", &m);

        for (n=0;n<m*2;n++)
        {
            fgets(tabuleiro[n],m+1,pont_config);
        }

        fscanf(pont_config,"%d\n", &np);

        for (n=0;n<np*2;n++)
        {
            fgets(palavras[n],16,pont_config);
        }
    }
    fclose(pont_config);

    printf("Nome do Jogador 1:\n");

    scanf("%s", j1);

    printf("Nome do Jogador 2:\n");

    scanf("%s", j2);

    limpaMat(palavras,np,m,tabuleiro);

    char tabuleirofc[m][m];

    criaTabuleiro(m,tabuleirofc);

    pont_saida = fopen("saida.txt", "w");

    for (n=0;n<m*2;n++)
        fprintf(pont_saida,"%s", tabuleiro[n]);

    fclose(pont_saida);

    //execJogo(j1,j2,m,tabuleiro,palavras,nj,np,tabuleirofc);

    return 0;
}