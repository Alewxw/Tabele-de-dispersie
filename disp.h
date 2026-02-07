#ifndef _DISP_H_
#define _DISP_H_

typedef struct nod_lista {
    int val;
    struct nod_lista *prev, *next;
} node;

typedef struct {
    node *head;
} lista;

void list_null ( lista *L );
void list_insert ( lista *L, int key );
node* list_search ( lista *L, int elem );
void list_free ( lista *L );

void tab_init ( lista *L, int n );
int tab_hash ( int k, int n );
void tab_insert ( lista *L, int val, int n );
int tab_search ( lista *L, int val, int n );
void tab_free ( lista *L, int n );
void tab_delete ( lista *L, int key, int n );
void tab_afis ( lista *L, int n );

#endif
