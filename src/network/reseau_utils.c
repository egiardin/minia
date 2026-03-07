#include "minia.h"


void print_reseau(t_layers *layers, int nbr_layers, mat expected_output, FILE *output_file)
{
    int i;

    i = 1;
    fprintf(output_file, "\n---------- Input (couche 0) ----------\n");
    fprint_mat_sortie(layers[0].output, output_file);
    fprintf(output_file, "\n---------- Expected_output----------\n");
    fprint_mat_sortie(expected_output, output_file);
    while(i < nbr_layers)
    {
        fprintf(output_file, "\n");
        print_layer(layers, i, output_file);
        fprintf(output_file, "\n");   
        i++;
    }
}


void print_layer(t_layers *layers, int index, FILE *output_file)
{
    fprintf(output_file, "\n---------- Couche %d ----------\n", index);
    fprintf(output_file, "Poids W%d :\n", index);
    fprintf(output_file, "\n");
    fprint_mat_sortie(layers[index].W, output_file);
    fprintf(output_file, "\n");
    fprintf(output_file, "\nSortie avant activation (%d):\n", index);
    fprintf(output_file, "\n");
    fprint_mat_sortie(layers[index].output, output_file);
    fprintf(output_file, "\n");
    fprintf(output_file, "\nBiais");
    fprintf(output_file, "\n");
    fprint_mat_sortie(layers[index].biais, output_file);
    fprintf(output_file, "\n");
    fprintf(output_file, "Sortie après activation + biais:\n");
    fprintf(output_file, "\n");
    fprint_mat_sortie(layers[index].activation, output_file);
    fprintf(output_file, "\n");
    fprintf(output_file, "Delta %d:\n", index);
    fprintf(output_file, "\n");
    fprint_mat_sortie(layers[index].delta, output_file);
    fprintf(output_file, "\n");
    fprintf(output_file, "Gradient %d:\n", index);
    fprintf(output_file, "\n");
    fprint_mat_sortie(layers[index].gradient, output_file);
    fprintf(output_file, "\n");
}

void print_info_reseau(t_layers *layers, FILE *output_file)
{
    fprintf(output_file, "Input : (1, %d)\n", layers[0].size);
    fprintf(output_file, "\n");
    fprintf(output_file, "W1 : (%d,%d)\n", layers[1].W.line, layers[1].W.column);
    fprintf(output_file, "W2 : (%d,%d)\n", layers[2].W.line, layers[2].W.column);
    fprintf(output_file, "\n");
    fprintf(output_file, "Gradient W1 : (%d,%d)\n", layers[1].gradient.line, layers[1].gradient.column);
    fprintf(output_file, "Gradient W2 : (%d,%d)\n", layers[2].gradient.line, layers[2].gradient.column);
    fprintf(output_file, "\n");
    fprintf(output_file, "Output de l'input : (%d,%d)\n", layers[0].output.line, layers[0].output.column);
    fprintf(output_file, "Output de la couche 1 : (%d,%d)\n", layers[1].output.line, layers[1].output.column);
    fprintf(output_file, "Output de la couche 2 : (%d,%d)\n", layers[2].output.line, layers[2].output.column);
    fprintf(output_file, "\n");
    fprintf(output_file, "Activation de l'input : (%d,%d)\n", layers[0].activation.line, layers[0].activation.column);
    fprintf(output_file, "Activation de la couche 1 : (%d,%d)\n", layers[1].activation.line, layers[1].activation.column);
    fprintf(output_file, "Activation de la couche 2 : (%d,%d)\n", layers[2].activation.line, layers[2].activation.column);    
    fprintf(output_file, "\n");
    fprintf(output_file, "Taille de Delta 1 : (%d,%d)\n", layers[1].delta.line, layers[1].delta.column);
    fprintf(output_file, "Taille de Delta 2 : (%d,%d)\n", layers[2].delta.line, layers[2].delta.column);
    fprintf(output_file, "\n");
    fprintf(output_file, "Taille de Biais 1 : (%d,%d)\n", layers[1].biais.line, layers[1].biais.column);
    fprintf(output_file, "Taille de Biais 2 : (%d,%d)\n", layers[2].biais.line, layers[2].biais.column);
}
