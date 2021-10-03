#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


typedef struct formando
{
    int prontuario;
    char nome[50];
    char curso[50];
    //int anoIngresso;
    int anoFormatura;
    /*
    char endereco[100];
    char telefone1[30];
    char telefone2[30];
    */

} FORMANDO;

typedef struct cell
{
    FORMANDO f; //conte�do da c�lula
    struct cell *next; //endere�o da pr�xima c�lula
} CELULA;

CELULA *init(CELULA *lista)
{
    //inicializa o ponteiro externo � lista com o valor NULL
    lista = NULL;
    return lista;
}

int empty (CELULA *lista)  //verifica se a lista encadeada est� vazia
{
    if(lista == NULL) //lista � o endere�o do primeiro n� da lista
        return 1;
    return 0;
}

CELULA *getnode()
{
    //essa fun��o aloca/cria um n� para uma lista encadeada
    return (CELULA*) malloc(sizeof(CELULA));
}

void freenode(CELULA *q)
{
    //liberar o espa�o de mem�ria ocupado por um n�
    //q seria o endere�o a ser liberado
    free(q);
}

CELULA *insere_inicio(CELULA *lista, FORMANDO f)
{

    CELULA *q;

    q = getnode();
    if(q!=NULL)
    {
        q->f = f;
        q->next = lista;
        lista = q;
        return lista;
    }
    else
    {
        printf("\nERRO na aloca��o do n�.\n");
        return NULL;
    }

}

CELULA *insere_fim(CELULA *lista, FORMANDO f)
{

    CELULA *q;
    CELULA *aux;

    q = getnode();
    if(q!=NULL)
    {
        q->f = f;
        q->next = NULL;

        if(empty(lista))
        {
            lista = q;
        }
        else
        {
            aux = lista;
            while(aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = q;
        }
        return lista;
    } //fim do if (q!=NULL)
    else
    {
        printf("\nERRO na aloca��o do n�.\n");
        return NULL;

    }

}

CELULA *remove_inicio(CELULA *lista)
{

    CELULA *q;

    q = lista;
    if(!empty(lista))  // h� itens na lista
    {
        lista = q->next;
        freenode(q);
        return lista;
    }
    else
    {
        printf("\nERRO: lista vazia.");
        return NULL;
    }

}

CELULA *pesquisa (CELULA *lista,FORMANDO f)
{

    CELULA *q;

    if(!empty(lista))
    {
        q = lista;
        while(q!=NULL)
        {
            if(q->f.nome == f.nome
                    && q->f.prontuario == f.prontuario
                    && q->f.anoFormatura == f.anoFormatura
                    && q->f.curso == f.curso)
            {
                return q; // encontrou o n�
            }
            q = q-> next; //avan�a para o pr�ximo
        }
    }
    return NULL; // caso n�o encontre
}

CELULA *pesquisaCurso (CELULA *lista)
{

    CELULA *q;

    if(!empty(lista))
    {
        q = lista;
        while(q!=NULL)
        {
            if(q->f.curso == lista->f.curso)
            {
                return q; // encontrou o n�
            }
            q = q-> next; //avan�a para o pr�ximo
        }
    }
    return NULL; // caso n�o encontre
}

CELULA *remove_valor(CELULA *lista, FORMANDO f)
{

    CELULA *q, *aux;

    if((q=pesquisa(lista,f)) != NULL)
    {
        aux = lista;
        if(aux == q)  //n� est� no inicio da lista
        {
            remove_inicio(lista);
        }
        else
        {
            while(aux->next != q)
            {
                aux = aux->next;
            }
            aux->next = q->next;
            freenode(q);
        }
        return lista; //removeu
    }
    return NULL; //n�o removeu
}

void exibe_lista(CELULA *lista)
{

    CELULA *aux;
    aux = lista;
    printf("\nLista Encadeada:\n");
    if(aux == NULL)
    {
        printf("\nLista vazia.");
    }
    while(aux != NULL)
    {
        printf("\n|Nome: %s - Pront: %d - Curso: %s - Formando em:%d|",
               aux->f.nome,aux->f.prontuario,aux->f.curso,aux->f.anoFormatura);
        aux = aux ->next;
    }


    printf("\n\n");
}

void exibe_lista_por_Curso(CELULA *lista)
{
    CELULA *aux;
    aux = lista;
    char pesquisado[40];
    int achou = 0;

    printf("\nQual o curso que deseja exibir os alunos? ");
    scanf("%s",&pesquisado);
    fflush(stdin);

    if(aux == NULL)
    {
        printf("\nLista vazia.\n\n");
        return;
    }


    while(aux != NULL)
    {
        if(strcmp(aux->f.curso, pesquisado) == 0)
        {
            achou = 1;
            printf("\n|Nome: %s - Pront: %d - Curso: %s - Formando em:%d|",
                   aux->f.nome,aux->f.prontuario,aux->f.curso,aux->f.anoFormatura);
            aux = aux ->next;

        }
        else
        {
            aux = aux ->next;
        }
    }

    if(achou == 0)
    {
        printf("\nN�o h� mais resultados.\n");
    }


    printf("\n\n");
}


FORMANDO lerDados(CELULA *lista)
{

    FORMANDO f;
    int  prontuario,anoFormatura;
    char curso[50],nome[50];

    printf("\nInsira o nome: ");
    scanf("%s",&nome);
    strcpy(f.nome,nome);
    fflush(stdin);
    printf("\nInsira o curso: ");
    scanf("%s",&curso);
    strcpy(f.curso,curso);
    printf("\nInsira o prontu�rio: ");
    scanf("%d",&prontuario);
    printf("\nInsira o ano da formatura: ");
    scanf("%d",&anoFormatura);
    printf("\n\n");

    f.prontuario = prontuario;
    f.anoFormatura = anoFormatura;

    return f;
}

void main()
{
    setlocale(LC_ALL,"");

    //instanciando um ponteiro externo que
    //aponta para o primeiro n� da lista.
    CELULA *ptrlista;
    ptrlista = init(ptrlista);

    FORMANDO f;
    int opcao;

    do
    {
        printf("<MENU>");
        printf("\n1-Inserir Formando.");
        printf("\n2-Imprimir Lista de Formandos.");
        printf("\n3-Imprimir Lista por Curso.");
        printf("\n0-Encerrar Programa.");

        printf("\n\nSelecione uma op��o: ");
        scanf("%d",&opcao);

        switch(opcao)
        {

        case 1:
            f = lerDados(ptrlista);
            ptrlista = insere_inicio(ptrlista,f);
            break;
        case 2:
            exibe_lista(ptrlista);
            break;
        case 3:
            exibe_lista_por_Curso(ptrlista);
            break;
        case 0:
            printf("\nEncerrando Programa.");
            break;
        }
    }
    while(opcao!=0);






}

