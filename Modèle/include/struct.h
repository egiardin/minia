#include "minia.h"

typedef struct
{
    int line;
    int column;
    float **mat;
} mat;

typedef struct
{
    int size;
    float *vect;
} vect;

typedef struct s_layers
{
    int size;
    vect output;
    vect activation;
    vect delta;
    mat W;
    mat gradient;
    vect biais;

} t_layers;

// typedef struct s_reseau
// {
//     int nbr_layers;
//     t_layers *layers;
// } t_reseau;