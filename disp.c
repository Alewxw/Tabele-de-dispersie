#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "disp.h"

void list_null ( lista *L )
{
    L->head = NULL;
}

void list_insert ( lista *L, int key )
{
    node* aux = (node*)malloc(sizeof(node));
    aux->val = key;

    aux->next = L->head;
    aux->prev = NULL;

    if ( L->head != NULL ) L->head->prev = aux;

    L->head = aux;
}

node* list_search ( lista *L, int elem )
{
    node* aux = L->head;

    while ( NULL != aux && aux->val != elem ) aux = aux->next;

    return aux;
}

void list_free ( lista *L )
{
    node *current = L->head;
    node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    L->head = NULL;
}

void tab_init ( lista *L, int n )
{
    for ( int i = 0 ; i < n ; i ++ )
        list_null(&L[i]);
}

int tab_hash ( int k, int n )
{
    return k % n;
}

void tab_insert ( lista *L, int val, int n )
{
    int x = tab_hash(val, n);

    list_insert(&L[x], val);
}

int tab_search ( lista *L, int val, int n )
{
    int poz = tab_hash(val, n);

    node* x = list_search(&L[poz], val);
    if ( NULL == x ) return 0;

    return 1;
}

void tab_free ( lista *L, int n )
{
    for (int i = 0; i < n; i++) {
        list_free(&L[i]);
    }
}

void tab_delete ( lista *L, int key, int n )
{
    int index = tab_hash(key, n);
    node *aux = L[index].head;

    while (aux != NULL)
    {
        if (aux->val == key)
        {
            if (aux->prev != NULL)
                aux->prev->next = aux->next;
            else
                L[index].head = aux->next;

            if (aux->next != NULL)
                aux->next->prev = aux->prev;

            free(aux);
            return;
        }
        aux = aux->next;
    }
}

void tab_afis ( lista *L, int n )
{
    for ( int i = 0 ; i < n ; i ++ )
    {
        node *aux = L[i].head;
        printf("Elementele de la pozitia %d sunt: ", i);

        while ( NULL != aux )
        {
            printf("%d ", aux->val);
            aux = aux->next;
        }

        printf("\n");
    }
}

