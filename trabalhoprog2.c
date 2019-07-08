#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Estatisticas{
    int p1r;
    int p1f;
    int p2r;
    int p2f;
    
}tStats;

typedef struct letras{
    char inicial;
    int qnt;
}tIniciais;

void arquivoEstatisticas(tStats est, int p1, int p2, char j1[], char j2[], int numero_jog[50], int jogA, int vpont[], int np, char palavras[][16])
{
    int i, j, aux, qnt1=0, qnt2=0, qnt0=0;
    char auxv[16];

    for (i=0;i<np;i++)
    {
        for (j=0;j<np-1;j++)
        {
            if (vpont[i]<vpont[i+1])
            {
                aux = vpont[i];
                vpont[i] = vpont[i+1];
                vpont[i+1] = aux;

                strcpy(auxv,palavras[i]);
                strcpy(palavras[i],palavras[i+1]);
                strcpy(palavras[i+1],auxv);

                aux = numero_jog[i];
                numero_jog[i] = numero_jog[i+1];
                numero_jog[i+1] = aux;
            }
        }
    }
    for (i=0;i<np;i++)
    {
        if (vpont[i]==2)
            qnt2++;
        else if(vpont[i]==1)
            qnt1++;
        else
            qnt0++;
    }

    for (i=0;i<qnt2;i++)
    {
        for (j=0;j<qnt2-1;j++)
        {
            if (palavras[i][0]>palavras[i+1][0])
            {
                strcpy(auxv,palavras[i]);
                strcpy(palavras[i],palavras[i+1]);
                strcpy(palavras[i+1],palavras[i]);

                aux = numero_jog[i];
                numero_jog[i] = numero_jog[i+1];
                numero_jog[i+1] = aux;
            }
        }
    }
    for (i=qnt2;i<qnt2+qnt1;i++)
    {
        for (j=qnt2;j<qnt2+qnt1;j++)
        {
            if (palavras[i][0]>palavras[i+1][0])
            {
                strcpy(auxv,palavras[i]);
                strcpy(palavras[i],palavras[i+1]);
                strcpy(palavras[i+1],palavras[i]);

                aux = numero_jog[i];
                numero_jog[i] = numero_jog[i+1];
                numero_jog[i+1] = aux;
            }
        }
    }
    for (i=qnt2+qnt1;i<qnt2+qnt1+qnt0;i++)
    {
        for (i=qnt2+qnt1;i<qnt2+qnt1+qnt0;i++)
        {
            if (palavras[i][0]>palavras[i+1][0])
            {
                strcpy(auxv,palavras[i]);
                strcpy(palavras[i],palavras[i+1]);
                strcpy(palavras[i+1],palavras[i]);

                aux = numero_jog[i];
                numero_jog[i] = numero_jog[i+1];
                numero_jog[i+1] = aux;
            }
        }
    }

    FILE *sta;

    sta = fopen("Estatistica.txt","w");

    fprintf(sta,"--------------\n--- PONTOS ---\n--------------\n\n");

    fprintf(sta,"%s\nFeitos: %d\nRecebidos: %d\nTotal: %d\n\n", j1, est.p1f, est.p1r, p1);

    fprintf(sta,"%s\nFeitos: %d\nRecebidos: %d\nTotal: %d\n\n", j2, est.p2f, est.p2r, p2);

    fprintf(sta,"---------------------------\n--- PALAVRAS POR PONTOS ---\n---------------------------\n");

    fprintf(sta,"|P|    Palavra     | T |\n|-|----------------|---|\n");

    for (i=0;i<np;i++)
    {
        fprintf(sta,"|%d|%-16s|%03d|\n", vpont[i], palavras[i], numero_jog[i]);
    }

    fprintf(sta,"\n\n");

    if (qnt2+qnt1+qnt0==np)
    {
        fprintf(sta,"DEU CERTO ESSA MERDA!!!\n");
    }

    fclose(sta);
}

void arquivoInicializacao(char j1[], char j2[], char palavras[][16], int np)
{
    int i, j, h, m, in1=np, in2=np, cont=1;
    int maior1, maior2;
    char auxc;
    int auxi;
    tIniciais v1[25];
    tIniciais v2[25];

    m = strlen(palavras[0]);
    maior1 = 0;

    for (i=1;i<np;i++)
    {
        if (strlen(palavras[i]) > m)
        {
            m = strlen(palavras[i]);
            maior1 = i;
        }
    }
    m = strlen(palavras[np]);
    maior2 = np;

    for (i=np+1;i<np*2;i++)
    {
        if (strlen(palavras[i]) > m)
        {
            m = strlen(palavras[i]);
            maior2 = i;
        }
    }

    for (i=0,j=np;i<np;i++,j++)
    {
        v1[i].inicial=palavras[i][0];
        v2[i].inicial=palavras[j][0];
    }
    for (i=0;i<np;i++)
    {
        for (j=i+1;j<np;j++)
        {
            if (v1[j].inicial==v1[i].inicial)
            {
                for (h=j;h<np;h++)
                {
                    v1[h].inicial = v1[h+1].inicial;
                }
                in1--;
                cont++;
            }
        }
        v1[i].qnt = cont;
        cont = 1;
    }
    for (i=0;i<np;i++)
    {
        for (j=i+1;j<np;j++)
        {
            if (v2[j].inicial==v2[i].inicial)
            {
                for (h=j;h<np;h++)
                {
                    v2[h].inicial = v2[h+1].inicial;
                }
                in2--;
                cont++;
            }
        }
        v2[i].qnt = cont;
        cont = 1;
    }

    for (j=0;j<in1;j++)
    {
        for (i=0;i<in1-1;i++)
        {
            if (v1[i].inicial > v1[i+1].inicial)
            {
                auxc = v1[i].inicial;
                v1[i].inicial = v1[i+1].inicial;
                v1[i+1].inicial = auxc;

                auxi = v1[i].qnt;
                v1[i].qnt = v1[i+1].qnt;
                v1[i+1].qnt = auxi;
            }
        }
    }
    for (j=0;j<in2;j++)
    {
        for (i=0;i<in2-1;i++)
        {
            if (v2[i].inicial > v2[i+1].inicial)
            {
                auxc = v2[i].inicial;
                v2[i].inicial = v2[i+1].inicial;
                v2[i+1].inicial = auxc;

                auxi = v2[i].qnt;
                v2[i].qnt = v2[i+1].qnt;
                v2[i+1].qnt = auxi;
            }
        }
    }

    FILE *ini;

    ini = fopen("Inicializacao.txt","w");

    if (ini==NULL)
    {
        printf("Nao foi possivel gerar o arquivo inicializacao\n");
    }
    else
    {
        fprintf(ini,"--Jogador 1--\n");
        fprintf(ini,"Nome: %s\nPalavras:\n", j1);
        
        for (i=0;i<np;i++)
            fprintf(ini,"%s\n", palavras[i]);

        fprintf(ini,"Maior palavra:\n%s\n", palavras[maior1]);

        fprintf(ini,"Letras iniciais:\n");

        for(i=0;i<in1;i++)
            fprintf(ini,"%c -> %d\n", v1[i].inicial, v1[i].qnt);

        fprintf(ini,"\n");

        fprintf(ini,"--Jogador 2--\n");
        fprintf(ini,"Nome: %s\nPalavras:\n", j2);
        
        for (i=np;i<np*2;i++)
            fprintf(ini,"%s\n", palavras[i]);

        fprintf(ini,"Maior palavra:\n%s\n", palavras[maior2]);

        fprintf(ini,"Letras iniciais:\n");

        for(i=0;i<in2;i++)
            fprintf(ini,"%c -> %d\n", v2[i].inicial, v2[i].qnt);
    }
    fclose(ini);
}

int confereHorizontalDireita(int m, int x, int y, int len, char tabuleiro[][100], char palavras[][16], char tabuleirofc[][m], int pos)
{
    int i, j, n=0;

    for (i=0,j=y;i<len;i++,j++)
    {
        if (j>m)
            break;

        if (tabuleiro[x][j]==palavras[pos][i])
            n++;
    }

    if (n==len)
    {
        for (i=y,j=0;i<len,j<len;i++,j++)
        {
            if (tabuleirofc[x][i]=='-')
                tabuleirofc[x][i]=tabuleiro[x][i];
        }
    return 1;
    }
    return 0;
}

int confereHorizontalEsquerda(int m, int x, int y, int len, char tabuleiro[][100], char palavras[][16], char tabuleirofc[][m], int pos)
{
    int i, j, n=0;

    for (i=0,j=y;i<len;i++,j--)
    {
        if (j<0)
            break;

        if (tabuleiro[x][j]==palavras[pos][i])
            n++;
    }

    if (n==len)
    {
        for (i=y,j=0;j<len;i--,j++)
        {
            if (tabuleirofc[x][i]=='-')
                tabuleirofc[x][i]=tabuleiro[x][i];
        }
    return 1;
    }
    return 0;
}

int confereVerticalCima(int m, int x, int y, int len, char tabuleiro[][100], char palavras[][16], char tabuleirofc[][m], int pos)
{
    int i, j, n=0;

    for (i=x,j=0;j<len;i--,j++)
    {
        if (i<0)
            break;

        if (tabuleiro[i][y]==palavras[pos][j])
            n++;
    }

    if (n==len)
    {
        for (i=x,j=0;j<len;i--,j++)
        {
            if (tabuleirofc[i][y]=='-')
                tabuleirofc[i][y]=tabuleiro[i][y];
        }
    return 1;
    }
    return 0;
}

int confereVerticalBaixo(int m, int x, int y, int len, char tabuleiro[][100], char palavras[][16], char tabuleirofc[][m], int pos)
{
    int i, j, n=0;

    for (i=x,j=0;j<len;i++,j++)
    {
        if (i>m)
            break;

        if (tabuleiro[i][y]==palavras[pos][j])
            n++;
    }

    if (n==len)
    {
        for (i=x,j=0;j<len;i++,j++)
        {
            if (tabuleirofc[i][y]=='-')
                tabuleirofc[i][y]=tabuleiro[i][y];
        }
    return 1;
    }
    return 0;
}

int confereDiagonalBaixoDireita(int m, int x, int y, int len, char tabuleiro[][100], char palavras[][16], char tabuleirofc[][m], int pos)
{
    int i, j, n=0, h=0;

    for (i=x,j=y;j<len;i++,j++)
    {
        if (i>m && j>m)
            break;

        if (tabuleiro[i][j]==palavras[pos][h])
            n++;

        h++;
    }

    if (n==len)
    {
        for (i=x,j=y;j<len;i++,j++)
        {
            if (tabuleirofc[i][j]=='-')
                tabuleirofc[i][j]=tabuleiro[i][j];
        }
    return 1;
    }
    return 0;
}

int confereDiagonalBaixoEsquerda(int m, int x, int y, int len, char tabuleiro[][100], char palavras[][16], char tabuleirofc[][m], int pos)
{
    int i, j, n=0, h=0;

    for (i=x,j=y;h<len;i++,j--)
    {
        if (i>m && j<0)
            break;

        if (tabuleiro[i][j]==palavras[pos][h])
            n++;

        h++;
    }

    if (n==len)
    {
        for (h=0,i=x,j=y;h<len;i++,j--)
        {
            if (tabuleirofc[i][j]=='-')
            {
                tabuleirofc[i][j]=tabuleiro[i][j];
            }
            h++;
        }
    return 1;
    }
    return 0;
}

int confereDiagonalCimaDireita(int m, int x, int y, int len, char tabuleiro[][100], char palavras[][16], char tabuleirofc[][m], int pos)
{
    int i, j, n=0, h=0;

    for (i=x,j=y;h<len;i--,j++)
    {
        if (i<0 && j>m)
            break;

        if (tabuleiro[i][j]==palavras[pos][h])
            n++;

        h++;
    }

    if (n==len)
    {
        for (h=0,i=x,j=y;h<len;i--,j++)
        {
            if (tabuleirofc[i][j]=='-')
            {
                tabuleirofc[i][j]=tabuleiro[i][j];
            }
            h++;
        }
    return 1;
    }
    return 0;
}

int confereDiagonalCimaEsquerda(int m, int x, int y, int len, char tabuleiro[][100], char palavras[][16], char tabuleirofc[][m], int pos)
{
    int i, j, n=0, h=0;

    for (i=x,j=y;h<len;i--,j--)
    {
        if (i<0 && j<0)
            break;

        if (tabuleiro[i][j]==palavras[pos][h])
            n++;

        h++;
    }

    if (n==len)
    {
        for (h=0,i=x,j=y;h<len;i--,j--)
        {
            if (tabuleirofc[i][j]=='-')
            {
                tabuleirofc[i][j]=tabuleiro[i][j];
            }
            h++;
        }
    return 1;
    }
    return 0;
}

int conferePalavras(int m, char tabuleiro[][100], char tabuleirofc[][m], char palavras[][16], int np, int x, int y, int numero_jog[50], int jogA)
{
    int i, j, ok, len, pos;

    for (i=0;i<np*2;i++)
    {
        if (tabuleiro[x][y]==palavras[i][0]) //Confere se alguma palavra começa com a letra da posição indicada.
        {
            len = strlen(palavras[i]);

            pos = i;

            //Confere se a palavra está na horizontal para a direita e se estiver, irá exibi-la na proxima jogada

            if (ok=confereHorizontalDireita(m,x,y,len,tabuleiro,palavras,tabuleirofc,pos))
                break;

            if (ok=confereHorizontalEsquerda(m,x,y,len,tabuleiro,palavras,tabuleirofc,pos))   
                break;

            if (ok=confereVerticalCima(m,x,y,len,tabuleiro,palavras,tabuleirofc,pos))
                break;

            if (ok=confereVerticalBaixo(m,x,y,len,tabuleiro,palavras,tabuleirofc,pos))
                break;

            if (ok=confereDiagonalBaixoDireita(m,x,y,len,tabuleiro,palavras,tabuleirofc,pos))
                break;

            if (ok=confereDiagonalBaixoEsquerda(m,x,y,len,tabuleiro,palavras,tabuleirofc,pos))
                break;

            if (ok=confereDiagonalCimaDireita(m,x,y,len,tabuleiro,palavras,tabuleirofc,pos))
                break;
            
            if (ok=confereDiagonalCimaEsquerda(m,x,y,len,tabuleiro,palavras,tabuleirofc,pos))
                break;          
        }
    }
    tabuleirofc[x][y]=toupper(tabuleiro[x][y]);

    if (ok==1)
    {
        numero_jog[pos] = jogA;
        return pos;
    }
    return 150;
}

void tabuleiroJogo(int m, char tabuleirofc[][m])
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

void tabelaPalavras(int np, int p1, int p2, char j1[], char j2[], char palavras[][16])
{
    int i;
            
    printf("|            Palavras Restantes           |\n|%-16s(%02d)|%-16s(%02d)|\n", j1, p1, j2, p2);
    printf("|--------------------|--------------------|\n");

    for (i=0;i<np;i++)
    {
        printf("|%-20s|", palavras[i]);
        printf("%-20s|\n", palavras[np+i]);
    }
}

void fimDeJogo (int m, int p1, int p2, char j1[], char j2[], char palavras[][16], char tabuleirofc[][m], int np)
{
    int i;

    tabelaPalavras(np,p1,p2,j1,j2,palavras);

    tabuleiroJogo(m,tabuleirofc);

    if (p1>p2)
        printf("\n%s Ganhou!!!\n", j1);
    else if (p2>p1)
        printf("\n%s Ganhou!!!\n", j2);
    else
        printf("\nEmpate\n");
}

/*void removePalavra(int np, char palavras[][16])
{
    int i, j;




}*/

void execJogo(char *j1, char *j2, int m, char tabuleiro[][100], char palavras[][16],int nj, int np, char tabuleirofc[][m], int jogadas[][100], int numero_jog[50])
{
    int r1=0, r2=0;
    int p1=0, p2=0;
    int ntotal=0;
    int i, ok, j, cont=1;
    int x, y, r=0;
    int pont=0, pos;
    int vpont[50];
    tStats est;
    int jogA=1;
    est.p1f = 0;
    est.p2f = 0;
    est.p1r = 0;
    est.p2r = 0;

    for (i=0;i<np*2;i++)
    {
        vpont[i] = 0;
        numero_jog[i] = 0;
    }

    while ((r1<np && r2<np) && ntotal<nj)
    {
        tabelaPalavras(np,p1,p2,j1,j2,palavras);

        tabuleiroJogo(m,tabuleirofc);

        if (cont==1)
            printf("\n%s por favor entre com as coordenadas para sua jogada:\n", j1);
        else
            printf("\n%s por favor entre com as coordenadas para sua jogada:\n", j2);

        while (r==0)
        {
            if(scanf("%d %d", &x, &y)!=2)
            {
                if (cont==1)
                    printf("Coordenadas invalidas. %s por favor entre com novas coordenadas para sua jogada:\n", j1);
                else
                    printf("Coordenadas invalidas. %s por favor entre com novas coordenadas para sua jogada:\n", j2);
            }
            else
            {
                if (x>=m || x<0 || y>=m || y<0)
                {
                    if (cont==1)
                        printf("Coordenadas fora do tabuleiro. %s por favor entre com novas coordenadas para sua jogada:\n", j1);
                    else
                        printf("Coordenadas fora do tabuleiro. %s por favor entre com novas coordenadas para sua jogada:\n", j2);

                    r = 0;
                }
                else
                {
                    if (jogadas[x][y]==1)
                    {
                        if (cont==1)
                            printf("Coordenadas já jogadas. %s por favor entre com novas coordenadas para sua jogada:\n", j1);
                        else
                            printf("Coordenadas já jogadas. %s por favor entre com novas coordenadas para sua jogada:\n", j2);
                    }
                    else
                    {
                        r++;
                    }                
                }
            }
        }
        r=0;
        
        jogadas[x][y] = 1;

        //Confere se uma palavra foi encontrada e se sim, exibe-a

        pos = conferePalavras(m,tabuleiro,tabuleirofc,palavras,np,x,y,numero_jog,jogA);

        jogA++;
        
        if (pos!=150)
        {
            if (pos>np-1)
            {
                ok = 2;
            }
            else
                ok = 1;
        }
        else
            ok = 0;

        if (ok==1)
        {
            //removePalavra();

            if (cont==1)
            {
                p1+=2;
                est.p1f+=2;
                pont = 2;
            }
            else
            {
                p1++;
                est.p1r++;
                pont = 1;
            }

            r1++;

            //infStats()
        }
        else if (ok==2)
        {
            //removePalavra();

            if (cont==1)
            {
                p2++;
                est.p2r++;
                pont = 1;
            }
            else
            {
                p2+=2;
                est.p2f+=2;
                pont = 2;
            }
            r2++;
        }
        cont++;

        vpont[pos] = pont;

        if (cont==2)
        {
            ntotal++;
            cont=0;
        }     
    }
    arquivoInicializacao(j1,j2,palavras,np);

    arquivoEstatisticas(est,p1,p2,j1,j2,numero_jog,jogA,vpont,np,palavras);

    fimDeJogo(m,p1,p2,j1,j2,palavras,tabuleirofc,np);
}

void limpaMat(char palavras[][16],int np, int m, char tabuleiro[][m])
{
    int i,j;

    for (i=0;i<25;i++)
        for (j=0;j<16;j++)
        {
            if (palavras[i][j]=='\n')
            {
                palavras[i][j]='\0';
            }
        }

    for (i=0;i<m;i++)
        for (j=0;j<m;j++)
        {
            if (tabuleiro[i][j]=='\n')
            {
                tabuleiro[i][j]='\0';
            }
        }
}

void inicializaMatrizes(int m, char tabuleirofc[m][m],int jogadas[][100])
{
    int i,j;

    for (i=0;i<m;i++)
        for (j=0;j<m;j++)
        {
            tabuleirofc[i][j]='-';
            jogadas[i][j] = 0;
        }
}

int main(int argc, char *argv)
{
    char j1[16];
    char j2[16];
    int jogadas[100][100];
    char tabuleiro[100][100];
    char palavras[50][16];
    int numero_jog[50];

    int m, n, nj, np, i, j;

    FILE *pont_config;

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

    inicializaMatrizes(m,tabuleirofc,jogadas);

    execJogo(j1,j2,m,tabuleiro,palavras,nj,np,tabuleirofc,jogadas,numero_jog);

    return 0;
}