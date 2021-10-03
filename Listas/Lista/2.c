#include<stdio.h>
#include<locale.h>

#define TAMF 10
typedef struct lista
{
    /*definindo estrutura da lista
    com tamanho de 10 e indice n*/
    char valor[TAMF];
    int n;
} LISTA;

void inicializar(LISTA *L)  //inicializa a lista com -1, pois o vetor inicia com 0
{
    L->n = -1;
}

char acessar_elemento(LISTA *L, int k)
{
    /*
    Essa fun��o retorna o elemento que est� localizado no indice k
    */

    if((k<0) || (k> (L->n)))
        printf("\nErro - elemento fora do limite permitido.");
    else
        return L->valor[k];


}

int buscar_elemento(LISTA *L, char val_b)
{
    /*
    Essa fun��o recebe um valor e
    deve retornar o indice de onde o elemento se encontra
    */

    int elemento = -1;
    int i =0;

    while(i<=(L->n))
    {
        if(val_b == L->valor[i])
        {
            elemento = i;

            break;
        }
        i++;
    }

    return elemento;

}

int determina_tamanho(LISTA *L)
{
    return L->n+1;
}

int lista_cheia(LISTA *L)
{
    if(L -> n+1 == TAMF)
        /*se o indice for igual ao tamanho m�ximo, retorna 1,
         ou seja verdade que est� cheia*/
        return 1;
    else
        return 0;

}

int lista_vazia(LISTA *L)
{
    if(L -> n == -1)
        /*se o indice for igual ao -1(nada), retorna 1,
         ou seja verdade que est� vazia*/
        return 1;
    else
        return 0;

}

int inserirNoFim(LISTA *L, char elemento)
{

    if(lista_cheia(L))
    {
        printf("\nErro - A lista est� cheia.");
        return 1;
    }
    L-> valor[L->n+1] = elemento;
    L-> n = L-> n+1;
    return 0;

}

int inserirNoInicio(LISTA *L, char elemento)
{

    if(lista_cheia(L))
    {
        printf("\nErro - A lista est� cheia.");
        return 1;
    }

    int i;

    L-> n = L-> n+1;
    for(i=0; i<L->n; i++)
    {
        L->valor[i+1] = L->valor[i];
        break;
    }

    L-> valor[0] = elemento;


    return 0;

}

int inserirNaPosicao(LISTA *L, int k, char elemento)
{

    if(lista_cheia(L))
    {
        printf("\nErro - lista cheia.");
        return 1;
    }
    if(k<0||k>(L->n+1))
    {
        printf("\nErro - o elemento est� fora dos limites.");
        return 1;
    }

    int i;

    for(i=(L->n+1); i>k; i--)
    {
        L->valor[i] = L->valor[i-1];
    }

    L->valor[k] = elemento;
    L->n = L->n+1;
    return 0;
}

int modificar_elemento(LISTA *L, int k, char elemento)
{

    if(k<0||k>L->n)
    {
        printf("\nErro - elemento fora dos limite.");
        return 1;
    }

    L->valor[k] = elemento;
    return 0;


}

int remover_elemento(LISTA *L, int k){

    int i;

    if(k<0||k>L->n){
        printf("\nErro - elemento fora dos limites.");
        return 1;
    }

    for(i=k;i<(L->n);i++){
        L->valor[i] = L-> valor[i+1];
    }

    L->n = L-> n-1;
    return 0;
}

int removerInicio(LISTA *L){

    int i;

    for(i=0;i<(L->n);i++){
        L->valor[i] = L-> valor[i+1];
    }

    L->n = L-> n-1;
    return 0;
}

void imprimir_lista(LISTA *L){

int i;

for(i=0;i<(L->n+1);i++)
    printf("|%d|",L->valor[i]);


}

int main()
{
    setlocale(LC_ALL,"");
    LISTA L; //declara lista do tipo LISTA
    inicializar(&L); // inicializa a lista passando o endere�o da mesma como par�metro
    inserirNoFim(&L,4);
    inserirNoFim(&L,3);
    inserirNoFim(&L,12);
    inserirNoFim(&L,50);
    printf("Lista completa: ");
    imprimir_lista(&L);

    remover_elemento(&L,2);
    printf("\nLista removendo o elemento 2(n�mero 12): ");
    imprimir_lista(&L);

    removerInicio(&L);
    printf("\nLista removendo o primeiro elemento: ");
    imprimir_lista(&L);



    printf("\n\n\n");
}