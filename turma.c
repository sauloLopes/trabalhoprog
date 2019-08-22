#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam_nome 30
#define tam_turma 100

typedef struct{
    int dia;
    int mes;
    int ano;
}tData;

tData leData()
{
    tData data;
    scanf("%d%d%d",&data.dia,&data.mes,&data.ano);

    return data;
}

void printData(tData data)
{
    printf("%d/%d/%d\n",data.dia,data.mes,data.ano);
}

int confereData(tData nasc, tData hj)
{
    if (nasc.dia==hj.dia && nasc.mes==hj.mes)
        return 1;
    return 0;
}  

typedef struct{
    char nome[tam_nome];
    int mat;
    int idade;
    float cr;
    tData nasc;
    tData ing;
}tAluno;

tAluno leAluno(int matricula)
{
    tAluno aluno;

    aluno.mat = matricula;
    fgets(aluno.nome,tam_nome,stdin);
    scanf("%d",&aluno.idade);
    scanf("%f",&aluno.cr);

    aluno.nasc = leData;
    aluno.ing = leData;

    return aluno;
}

void apresentaAluno(tAluno aluno)
{
    printf("Nome: %s\n", aluno.nome);
    printf("Matricula: %d\n", aluno.mat);
    printf("Idade: %d\n", aluno.idade);
    printf("CR: %f\n", aluno.cr);

    printData(aluno.nasc);
    printData(aluno.ing);
    printf("\n");
}

int ehAniversario(tAluno aluno)
{
    if (confereData(aluno.nasc))
        return 1;
    return 0;
}

int ehExcelente(tAluno aluno)
{
    if (aluno.cr>=8)
        return 1;
    return 0;
}

int comparaNome(tAluno turma[], int i)
{
    if (strcmp(turma[i].nome,turma[i+1].nome)>0)
        return 1;
    return 0;
}

typedef struct{
    tAluno turma[tam_turma];
    int nAlunos;
}tTurma

tTurma leTurma(tTurma t)
{
    int matricula;

    scanf("%d",&matricula);

    for (t.n=0;matricula!=0;t.n++)
    {
        t.turma[i] = leAluno(matricula);
        scanf("%d",&matricula);
    }

    return t;
}

void apresentaTodos(tTurma t)
{
    int i;

    for(i=0;i<t.nAlunos;i++)
    {
        apresentaAluno(t.turma[i]);
    }
}

void aniversariantes(tTurma t)
{
    int i;

    for (i=0;i<t.nAlunos;i++)
    {
        if (ehAniversario(t.turma[i]))
        {
            apresentaAluno(t.turma[i]);
        }
    }
}

void excelentes(tTurma t)
{
    int i;

    for (i=0;i<nAlunos;i++)
    {
        if (confereCr(t.turma[i]))
        {
            apresentaAluno(t.turma[i]);
        }
    }
}

void ordenaNome(tTurma t)
{
    int i,, j;
    tAluno aux;

    for (i=0;i<t.nAlunos-1;i++)
    {
        for (j=0;j<t.nAlunos-1;j++)
        {
            if (comparaNome(t.turma,i))
            {
                aux = t.turma[i];
                t.turma[i] = t.turma[i+1];
                t.turma[i+1] = aux;
            }
        }
    }
    apresentaTodos(t);
}

void ordenaData(tTurma t)
{
    
}

void ordenaCr(tAluno aluno, int nAlunos)
{

}


int main()
{
    tTurma t;
    
    return 0;
}