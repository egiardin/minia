#include "minia.h"

t_layers *init_reseau()
{
    int nbr_layers;
    t_layers *layers;

    nbr_layers = 3;
    layers = calloc(nbr_layers, sizeof(t_layers));
    if(!layers)
    {
        fprintf(stderr, "Erreur d'allocation du reseau\n");
        return(NULL);
    }
    layers[0].size = 3; //196
    layers[0].output.size = 3;
    layers[0].output.vect = calloc(3, sizeof(float));
    layers[0].activation.size = 3;
    layers[0].activation.vect = calloc(3, sizeof(float));

    layers[1].size = 3;//128
    layers[1].W = init_matrice_he(layers[0].size, layers[1].size); //changement
    layers[1].output.size = 3;
    layers[1].output.vect = calloc(3, sizeof(float));
    layers[1].delta.size = 3;
    layers[1].delta.vect = calloc(3, sizeof(float));
    layers[1].activation.size = 3;
    layers[1].activation.vect = calloc(3, sizeof(float));
    layers[1].gradient = init_matrice_zero(layers[1].size, layers[0].size);  // delta × input
    layers[1].biais.size = layers[1].size;
    layers[1].biais = init_tab_zero(layers[1].size);


    layers[2].size = 3;//64
    layers[2].W = init_matrice_he(layers[1].size, layers[2].size);
    layers[2].output.size = 3;
    layers[2].output.vect = calloc(3, sizeof(float));
    layers[2].delta.size = 3;
    layers[2].delta.vect = calloc(3, sizeof(float));
    layers[2].activation.size = 3;
    layers[2].activation.vect = calloc(3, sizeof(float));
    layers[2].gradient = init_matrice_zero(layers[2].size, layers[1].size);
    layers[2].biais.size = layers[2].size;
    layers[2].biais = init_tab_zero(layers[2].size);

    
    return(layers);
}