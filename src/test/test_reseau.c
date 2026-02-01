#include "minia.h"

// void test_reseau_forward()
// {
//     t_layers *layers;
//     vect input;
//     vect expected_output;
//     int nbr_layers;

//     input = init_vect_zero(3); //196
//     input.vect[0] = -1;
//     input.vect[1] = -2;
//     input.vect[2] = -9;
//     expected_output = init_vect_zero(3);

//     expected_output.vect[0] = 0;
//     expected_output.vect[1] = 0;
//     expected_output.vect[2] = 1;

//     layers = init_reseau();

//     layers[1].biais.vect[0] = 3;
//     layers[1].biais.vect[1] = 4;
//     layers[1].biais.vect[2] = 5;

//     layers[2].biais.vect[0] = 1;
//     layers[2].biais.vect[1] = 2;
//     layers[2].biais.vect[2] = 3;

//     layers[1].W.mat[0][0] = -1;
//     layers[1].W.mat[0][1] = 0;
//     layers[1].W.mat[0][2] = -1;
//     layers[1].W.mat[1][0] = -1;
//     layers[1].W.mat[1][1] = -1;
//     layers[1].W.mat[1][2] = 1;
//     layers[1].W.mat[2][0] = 1;
//     layers[1].W.mat[2][1] = 1;
//     layers[1].W.mat[2][2] = -1;

//     layers[2].W.mat[0][0] = -1;
//     layers[2].W.mat[0][1] = 0;
//     layers[2].W.mat[0][2] = -1;
//     layers[2].W.mat[1][0] = -1;
//     layers[2].W.mat[1][1] = -1;
//     layers[2].W.mat[1][2] = 1;
//     layers[2].W.mat[2][0] = 1;
//     layers[2].W.mat[2][1] = 1;
//     layers[2].W.mat[2][2] = -1;
//     nbr_layers = 3;

//     forward_propagation(layers, nbr_layers, input);
//     back_propagation(layers, expected_output, nbr_layers, 0.01, input);
//     print_reseau(layers, nbr_layers);

//     return;
// }