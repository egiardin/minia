#include "minia.h"


void print_reseau(t_layers *layers, int nbr_layers, mat expected_output, FILE *sortie)
{
    int i;

    i = 1;
    fprintf(sortie, "\n---------- Input (couche 0) ----------\n");
    fprint_mat_sortie(layers[0].output, sortie);
    fprintf(sortie, "\n---------- Expected_output----------\n");
    fprint_mat_sortie(expected_output, sortie);
    while(i < nbr_layers)
    {
        fprintf(sortie, "\n");
        print_layer(layers, i, sortie);
        fprintf(sortie, "\n");   
        i++;
    }
}


void print_layer(t_layers *layers, int index, FILE *sortie)
{
    fprintf(sortie, "\n---------- Couche %d ----------\n", index);
    fprintf(sortie, "Poids W%d :\n", index);
    fprintf(sortie, "\n");
    fprint_mat_sortie(layers[index].W, sortie);
    fprintf(sortie, "\n");
    fprintf(sortie, "\nSortie avant activation (%d):\n", index);
    fprintf(sortie, "\n");
    fprint_mat_sortie(layers[index].output, sortie);
    fprintf(sortie, "\n");
    fprintf(sortie, "\nBiais");
    fprintf(sortie, "\n");
    fprint_mat_sortie(layers[index].biais, sortie);
    fprintf(sortie, "\n");
    fprintf(sortie, "Sortie après activation + biais:\n");
    fprintf(sortie, "\n");
    fprint_mat_sortie(layers[index].activation, sortie);
    fprintf(sortie, "\n");
    fprintf(sortie, "Delta %d:\n", index);
    fprintf(sortie, "\n");
    fprint_mat_sortie(layers[index].delta, sortie);
    fprintf(sortie, "\n");
    fprintf(sortie, "Gradient %d:\n", index);
    fprintf(sortie, "\n");
    fprint_mat_sortie(layers[index].gradient, sortie);
    fprintf(sortie, "\n");
}

void print_info_reseau(t_layers *layers, FILE *sortie)
{
    fprintf(sortie, "Input : (1, %d)\n", layers[0].size);
    fprintf(sortie, "\n");
    fprintf(sortie, "W1 : (%d,%d)\n", layers[1].W.line, layers[1].W.column);
    fprintf(sortie, "W2 : (%d,%d)\n", layers[2].W.line, layers[2].W.column);
    fprintf(sortie, "\n");
    fprintf(sortie, "Gradient W1 : (%d,%d)\n", layers[1].gradient.line, layers[1].gradient.column);
    fprintf(sortie, "Gradient W2 : (%d,%d)\n", layers[2].gradient.line, layers[2].gradient.column);
    fprintf(sortie, "\n");
    fprintf(sortie, "Output de l'input : (%d,%d)\n", layers[0].output.line, layers[0].output.column);
    fprintf(sortie, "Output de la couche 1 : (%d,%d)\n", layers[1].output.line, layers[1].output.column);
    fprintf(sortie, "Output de la couche 2 : (%d,%d)\n", layers[2].output.line, layers[2].output.column);
    fprintf(sortie, "\n");
    fprintf(sortie, "Activation de l'input : (%d,%d)\n", layers[0].activation.line, layers[0].activation.column);
    fprintf(sortie, "Activation de la couche 1 : (%d,%d)\n", layers[1].activation.line, layers[1].activation.column);
    fprintf(sortie, "Activation de la couche 2 : (%d,%d)\n", layers[2].activation.line, layers[2].activation.column);    
    fprintf(sortie, "\n");
    fprintf(sortie, "Taille de Delta 1 : (%d,%d)\n", layers[1].delta.line, layers[1].delta.column);
    fprintf(sortie, "Taille de Delta 2 : (%d,%d)\n", layers[2].delta.line, layers[2].delta.column);
    fprintf(sortie, "\n");
    fprintf(sortie, "Taille de Biais 1 : (%d,%d)\n", layers[1].biais.line, layers[1].biais.column);
    fprintf(sortie, "Taille de Biais 2 : (%d,%d)\n", layers[2].biais.line, layers[2].biais.column);
}