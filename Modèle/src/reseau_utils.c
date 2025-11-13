#include "minia.h"

void print_reseau(t_layers *layers, int nbr_layers)
{
    int i;

    i = 1;
    printf("\n---------- Input (couche 0) ----------\n");
    print_tab(layers[0].output);
    while(i < nbr_layers)
    {
        printf("\n");
        print_layer(layers, i);
        printf("\n");    
        i++;
    }
}

void print_layer(t_layers *layers, int index)
{
    printf("\n---------- Couche %d ----------\n", index);
    printf("Poids W%d :\n", index);
    printf("\n");
    print_mat(layers[index].W);
    printf("\n");
    printf("\nSortie avant activation (%d):\n", index);
    printf("\n");
    print_tab(layers[index].output);
    printf("\n");
    printf("\nBiais");
    printf("\n");
    print_tab(layers[index].biais);
    printf("\n");
    printf("Sortie après activation + biais:\n");
    printf("\n");
    print_tab(layers[index].activation);
    printf("\n");
    printf("Delta %d:\n", index);
    printf("\n");
    print_tab(layers[index].delta);
    printf("\n");
    printf("Gradient %d:\n", index);
    printf("\n");
    print_mat(layers[index].gradient);
    printf("\n");
}
