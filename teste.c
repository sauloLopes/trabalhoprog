#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    int dia;
    int mes;
    int ano;
}tData;

typedef struct cad{
    char nome[50];
    int mat;
    float p1;
    float p2;
    float t1;
    float t2;
    float t3;
    float mf;
    tData ing;
    tData nasc;
}tCadastro;

int leAlunos(tCadastro alunos[])
{
    int i;

    for (i=0;i<40;i++)
    {
        scanf("%[^n]%*c", aluno[i].nome);
        scanf("%d ");
    }

    return i;
}

void calculaMedia(int n, tCadastro alunos[])
{
    int i;

    for (i=0;i<n;i++)
    {
        alunos[i].mf = (alunos[i].p1*alunos[i].t1 + alunos[i].p2*alunos[i].t2)/20 + alunos[i].t3/10;
    }
}

void ordenaVetor(int n, tCadastro alunos[])
{
    int i, j, h;
    tCadastro aux;

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            h = strcmp(alunos[j].nome,alunos[j+1].nome);

            if (h>0)
            {
                aux = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = aux;
            }
        }
    }
}

void printRes(int n, tCadastro alunos[])
{
    int i;

    for (i=0;i<n;i++)
    {
        printf("Aluno: %s\nMedia final: %.2f\n", alunos[i].nome, alunos[i].mf);

        if (alunos[i].mf>=7)
        {
            printf("Prova final: Não\n\n");
        }
        else
            printf("Prova final: Sim\n\n");
    }
}

int main()
{
    int n;
    tCadastro alunos[40];

    n = leAlunos(alunos);

    calculaMedia(n,alunos);

    ordenaVetor(n,alunos);

    printRes(n,alunos);

    return 0;
}