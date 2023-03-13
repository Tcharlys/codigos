#include <stdio.h>
#define MAX_TURMAS 5

struct aluno
{
    int mat;
    char nome[81];
    float notas[3];
    float media;
};
typedef struct aluno Aluno;

struct turma
{
    char id;
    int vagas;
    Aluno *aluno[MAX_VAGAS];
};
typedef struct turma Turma;

Turma *cria_turma(char id)
{
    Turma* turma1 = (Turma*) malloc(sizeof(Turma));
    turma1->id = id;
    turma1->vagas = 2;
    
    int i;
    
    for(i = 0; i < 2; i++)
    {
        turma1->alunos[i] = NULL;
    }
}

int main(void){

    int opcao;
    Turma t_turmas = (Turma *) malloc(MAX_TURMAS * sizeof(Turma));
    
    printf("MENUS:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair\n\n");
    printf("Digite sua opcao:");
    scanf(" %d", &opcao);

    switch (opcao)
    {
    case(opcao == 1):
        for ( i = 0; i < count; i++)
        {
            
        }
        
        break;
    
    default:
        break;
    }
    
    return 0;
}