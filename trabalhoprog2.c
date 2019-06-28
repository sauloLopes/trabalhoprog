#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int confereHorizontalDireita(int x, int y, int len, char string[], char tabuleiro[][100], char palavras[][16], char tabuleirofc[][100], int pos)
{
    int i, j, ok;

    for (i=0,j=y;i<len;i++,j++)
    {
        string[i]=tabuleiro[x][j];
    }

    for (i=0;i<16;i++)
    {
        if (palavras[pos][i]<='a' && palavras[pos][i]>='z')
        {
            printf("%d %d\n", i, string[i]);
            break;
        }        
    }

    printf("Tamanho: %d\n", len);

    printf("\nComparando (%c) com (%c)\n", string[5], palavras[pos][5]);

    ok = strcmp(string,palavras[pos]);

    printf("O valor retornado foi: %d\n", ok);

    if (!ok)
    {
        printf("ENTROU AQUI!!!!!!!!\n");
        for (i=y,j=0;i<len,j<len;i++,j++)
        {
            if (tabuleiro[x][i]=='-')
                tabuleirofc[x][i]=string[j];
        }
    return 1;
    }
    return 0;
}

/*int confereHorizontalEsquerda(int x, int y, int len, char string[], char tabuleiro[][100], char palavras[][16], char tabuleirofc[][100])
{

}

int confereVerticalCima(int x, int y, int len, char string[], char tabuleiro[][100], char palavras[][16], char tabuleirofc[][100])
{

}

int confereVerticalBaixo(int x, int y, int len, char string[], char tabuleiro[][100], char palavras[][16], char tabuleirofc[][100])
{

}

int confereDiagonalBaixoDireita(int x, int y, int len, char string[], char tabuleiro[][100], char palavras[][16], char tabuleirofc[][100])
{
    for (h=0,i=x,j=y;i<len;i++,j++,h++)
    {
        string[h]=tabuleiro[i][j];
    }

    printf("A palavra formada foi: %s e a sera comparada com %s\n", string, palavras[pos]);
            
    if (strcmp(string,palavras[pos])==0)
    {
        for (h=0,i=x,j=y;h<len;j++,i++,h++)
        {
            tabuleirofc[i][j]=string[h];
        }
    }
}

int confereDiagonalBaixoEsquerda(int x, int y, int len, char string[], char tabuleiro[][100], char palavras[][16], char tabuleirofc[][100])
{

}

int confereDiagonalCimaDireita(int x, int y, int len, char string[], char tabuleiro[][100], char palavras[][16], char tabuleirofc[][100])
{

}

int confereDiagonalCimaEsquerda(int x, int y, int len, char string[], char tabuleiro[][100], char palavras[][16], char tabuleirofc[][100])
{

}*/

void tabuleiroJogo(int m, char tabuleiro[][100], char tabuleirofc[][m])
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
}

int conferePalavras(int m, char tabuleiro[][100], char tabuleirofc[][m], char palavras[][16], int np, int x, int y)
{
    int i, j, ok, len, pos;
    char string[16];

    printf("Tabuleiro na posição x,y: %c\n", tabuleiro[x][y]);

    for (i=0;i<np*2;i++)
    {
        if (tabuleiro[x][y]== palavras[i][0]) //Confere se alguma palavra do tabuleiro começa com a letra da posição indicada.
        {
            len = strlen(palavras[i]);

            pos = i;

            //Confere se a palavra está na horizontal para a direita e se estiver, irá exibi-la na proxima jogada

            if (confereHorizontalDireita(x,y,len,string,tabuleiro,palavras,tabuleirofc,pos))
                break;

            /*if (confereHorizontalEsquerda(x,y,len,string,tabuleiro,palavras,tabuleirofc))   
                break;

            if (confereVerticalCima(x,y,len,string,tabuleiro,palavras,tabuleirofc))
                break;

            if (confereVerticalBaixo(x,y,len,string,tabuleiro,palavras,tabuleirofc))
                break;

            if (confereDiagonalBaixoDireita(x,y,len,string,tabuleiro,palavras,tabuleirofc))
                break;

            if (confereDiagonalBaixoEsquerda(x,y,len,string,tabuleiro,palavras,tabuleirofc))
                break;

            if (confereDiagonalCimaDireita(x,y,len,string,tabuleiro,palavras,tabuleirofc))
                break;
            
            if (confereDiagonalCimaEsquerda(x,y,len,string,tabuleiro,palavras,tabuleirofc))
                break;*/          
        }
    }
    tabuleirofc[x][y]=toupper(tabuleiro[x][y]);

    return ok;
}

void execJogo(char *j1, char *j2, int m, char tabuleiro[][100], char palavras[][16],int nj, int np, char tabuleirofc[][m])
{
    int r1=0, r2=0;
    int p1=0, p2=0;
    int i, ok, j;
    int x, y;

   //while ((r1<np && r2<np) || n1<nj && n2<nj)

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

    scanf("%d %d", &x, &y);

    //Confere se uma palavra foi encontrada e se sim, exibe-a

    ok = conferePalavras(m,tabuleiro,tabuleirofc,palavras,np,x,y);

    tabuleiroJogo(m,tabuleiro,tabuleirofc);

    //fimDeJogo(p1,p2);    
}

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

    int m, n, nj, np, i, j;

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

        fscanf(pont_config,"%d", &m);

        fgetc(pont_config);

        for (i=0;i<m;i++)
        {
            fscanf(pont_config,"%s", tabuleiro[i]);     
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

    execJogo(j1,j2,m,tabuleiro,palavras,nj,np,tabuleirofc);

    return 0;
}