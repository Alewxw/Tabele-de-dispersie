#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "disp.h"


int main()
{
    printf("Cate valori ai vrea sa aibe tabelul tau de dispersie?\n");
    int n;
    scanf("%d", &n);

    // Alocare dinamica
    lista *L;
    L = (lista*)malloc(sizeof(lista));

    tab_init(L, n);
    int x = -1;

    while ( x )
    {
        printf("\n !~~ MENIU ~~! \n");
        printf("Ce operatie vrei sa faci asupra tabelului?\n");
        printf("0: Iesire din program\n");
        printf("1: Inserare element in tabel\n");
        printf("2: Cautare element in tabel\n");
        printf("3: Stergere element din tabel\n");
        printf("4: Afisare tabel\n");

        scanf("%d", &x);

        getch();

        system("dir");

        switch(x)
        {
            case 0:
            {
                printf("Programul s-a incheiat\n");

                tab_free(L, n);
                free(L);
                return 0;
            }

            case 1:
            {
                int elem;
                printf("Ce element vrei sa adaugi in tabel?\n");
                scanf("%d", &elem);

                tab_insert(L, elem, n);
                printf("Elementul cu valoarea %d a fost inserat in pozitia %d\n", elem, tab_hash(elem, n));
                break;
            }

            case 2:
            {
                int elem;
                printf("Ce element vrei sa cauti in tabel?\n");
                scanf("%d", &elem);

                if ( tab_search(L, elem, n) ) {
                    printf("Elementul a fost gasit in tabel la pozitia %d\n", tab_hash(elem, n));
                } else {
                    printf("Elementul nu a fost gasit in tabel\n");
                }

                break;
            }

            case 3:
            {
                int elem;
                printf("Ce element vrei sa elimini din tabel?\n");
                scanf("%d", &elem);

                if ( tab_search(L, elem, n) )
                {
                    tab_delete(L, elem, n);
                    printf("Elementul a fost eliminat din tabel\n");
                }
                else printf("Elementul nu poate fi sters pentru ca nu este in tabel\n");
                break;
            }

            case 4:
            {
                tab_afis(L, n);
                break;
            }

            default:
            {
                printf("Operatie inexistenta!\n");
                break;
            }
        }
    }
    return 0;
}
