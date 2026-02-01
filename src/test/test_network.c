#include "minia.h"

// void test_mat_utils_with_index()
// {
//     mat mat0;
//     mat mat1;
//     mat mat2;
//     mat mat3;
//     mat mat4;
//     mat mat5;
//     mat mat6;
//     mat mat7;
//     vect vect1;
//     vect vect2;
//     float nbr;

//     mat0 = init_matrice_random(3, 4);
//     mat1 = init_matrice_random(3, 4);
//     mat2 = init_matrice_random(4, 7);
//     mat3 = init_matrice_zero(3, 7);
//     mat4 = init_matrice_zero(4, 3);
//     mat5 = init_matrice_zero(4, 9);
//     mat6 = init_matrice_zero(3, 4);
//     mat7 = init_matrice_random(4, 4);
//     nbr = 2.0;
//     vect1 = init_vect_random(4);
//     vect2 = init_vect_zero(4);

//     mult_mat(mat1, mat2, mat3);
//     transp_mat(mat1, mat4);
//     soust_mat(mat0, mat1, mat6);
//     printf("\n----------- mat0 matrice random ----------\n");
//     print_mat(mat0);
//     printf("\n----------- mat1 matrice random ----------\n");
//     print_mat(mat1);
//     printf("\n----------- mat2 matrice random ----------\n");
//     print_mat(mat2);
//     printf("\n----------- mat3 = mat1 * mat2 ----------\n");
//     print_mat(mat3);
//     printf("\n----------- mat4 = transposé mat1 ----------\n");
//     print_mat(mat4);
//     printf("\n----------- mat5 = matrice à zéro----------\n");
//     print_mat(mat5);
//     printf("\n----------- mat6 = mat0 - mat1 ----------\n");
//     print_mat(mat6);
//     mult_nbr_mat(nbr,mat1);
//     printf("\n----------- mat1 = nbr * mat1 ----------\n");
//     print_mat(mat1);
//     mult_vect_mat(vect1, mat7, vect2);
//     printf("\n----------- vect2 = vect1 * mat7 ----------\n");
//     printf("----vect1----\n");
//     print_vect(vect1);
//     printf("----mat0---\n");
//     print_mat(mat7);
//     printf("\n");
//     print_vect(vect2);
//     return;
// }

// void test_mat_utils_without_index()
// {
//     mat mat0;
//     mat mat1;
//     mat mat2;
//     mat mat3;
//     mat mat4;
//     mat mat5;
//     mat mat6;
//     mat mat7;
//     vect vect1;
//     vect vect2;
//     float nbr;

//     mat0 = init_matrice_random(3, 4);
//     mat1 = init_matrice_he(3, 4);
//     mat2 = init_matrice_random(4, 7);
//     mat3 = init_matrice_zero(3, 7);
//     mat4 = init_matrice_zero(4, 3);
//     mat5 = init_matrice_zero(4, 9);
//     mat6 = init_matrice_zero(3, 4);
//     mat7 = init_matrice_random(4, 4);
//     nbr = 2.0;
//     vect1 = init_vect_random(4);
//     vect2 = init_vect_zero(4);

//     mult_mat(mat1, mat2, mat3);
//     transp_mat(mat1, mat4);
//     soust_mat(mat0, mat1, mat6);

//     printf("\n----------- mat0 matrice random ----------\n");
//     print_mat_without_index(mat0);

//     printf("\n----------- mat1 matrice he ----------\n");
//     print_mat_without_index(mat1);

//     printf("\n----------- mat2 matrice random ----------\n");
//     print_mat_without_index(mat2);

//     printf("\n----------- mat3 = mat1 * mat2 ----------\n");
//     print_mat_without_index(mat3);
    
//     printf("\n----------- mat4 = transposé mat1 ----------\n");
//     print_mat_without_index(mat4);

//     printf("\n----------- mat5 = matrice à zéro----------\n");
//     print_mat_without_index(mat5);

//     printf("\n----------- mat6 = mat0 - mat1 ----------\n");
//     print_mat_without_index(mat6);
//     mult_nbr_mat(nbr,mat1);

//     printf("\n----------- mat1 = nbr * mat1 ----------\n");
//     print_mat_without_index(mat1);
//     mult_vect_mat(vect1, mat7, vect2);

//     printf("\n----------- vect2 = vect1 * mat7 ----------\n");

//     printf("----vect1----\n");
//     print_vect(vect1);

//     printf("----mat0---\n");
//     print_mat_without_index(mat7);

//     printf("\n");
//     print_vect(vect2);
//     return;
// }

// void test_vect_utils_with_index()
// {
//     vect vect1;
//     vect vect2;
//     vect vect3;
//     vect vect4;
//     vect vect5;
//     vect vect6;
//     vect vect7;
//     mat mat1;
//     mat mat2;
//     float nbr = 0.0;
//     float floatmx;

//     vect1 = init_vect_zero(7);
//     vect2 = init_vect_random(7);
//     vect3 = init_vect_random(7);
//     vect4 = init_vect_zero(7);
//     vect5 = init_vect_zero(7);
//     mat1 = init_matrice_zero(7, 0);
//     mat2 = init_matrice_zero(vect2.size, vect3.size);
//     floatmx = floatmax(nbr);

//     produit_hadamard(vect2, vect3, vect4);
//     soust_vect(vect4, vect3, vect5);
//     transp_vect(vect2, mat1);
//     mult_vect_vect(vect2, vect3, mat2);
//     nbr = sum_tab(vect4);

//     printf("\n----------- vect1 vecteur zéro ----------\n");
//     print_vect(vect1);
//     printf("\n----------- vect2 vecteur random ----------\n");
//     print_vect(vect2);
//     printf("\n----------- vect3 vecteur random ----------\n");
//     print_vect(vect3);
//     printf("\n----------- vect4 = vect2 * vect3 (produit scalaire)----------\n");
//     print_vect(vect4);
//     printf("\n----------- vect5 = vect4 - vect3 ----------\n");
//     print_vect(vect5);
//     printf("\n----------- transp de vect2 ---------\n");
//     printf("\n----- vect2 ------\n");
//     print_vect(vect2);
//     printf("\n----- mat1------\n");
//     print_mat(mat1);
//     printf("\n----------- vect4 = vect2 * vect3 (matrice)----------\n");
//     print_mat(mat2);
//     printf("\n----------- Sum vect4 ----------\n");
//     printf("%f", nbr);
//     printf("\n----------- Floatmax ----------\n");
//     printf("%f", nbr);
//     return;
// }

// void test_vect_utils_without_index()
// {
//     vect vect1;
//     vect vect2;
//     vect vect3;
//     vect vect4;
//     vect vect5;
//     vect vect6;
//     vect vect7;
//     mat mat1;
//     mat mat2;
//     float nbr = 0.0;
//     float floatmx;

//     vect1 = init_vect_zero(7);
//     vect2 = init_vect_random(7);
//     vect3 = init_vect_random(7);
//     vect4 = init_vect_zero(7);
//     vect5 = init_vect_zero(7);
//     mat1 = init_matrice_zero(7, 3);
//     mat2 = init_matrice_zero(vect2.size, vect3.size);
//     floatmx = floatmax(nbr);

//     produit_hadamard(vect2, vect3, vect4);
//     soust_vect(vect4, vect3, vect5);
//     transp_vect(vect2, mat1);
//     mult_vect_vect(vect2, vect3, mat2);
//     nbr = sum_tab(vect4);

//     printf("\n----------- vect1 vecteur zéro ----------\n");
//     print_vect_without_index(vect1);
//     printf("\n----------- vect2 vecteur random ----------\n");
//     print_vect_without_index(vect2);
//     printf("\n----------- vect3 vecteur random ----------\n");
//     print_vect_without_index(vect3);
//     printf("\n----------- vect4 = vect2 * vect3 (produit scalaire)----------\n");
//     print_vect_without_index(vect4);
//     printf("\n----------- vect5 = vect4 - vect3 ----------\n");
//     print_vect_without_index(vect5);
//     printf("\n----------- transp de vect2 ---------\n");
//     printf("\n----- vect2 ------\n");
//     print_vect_without_index(vect2);
//     printf("\n----- mat1------\n");
//     print_mat_without_index(mat1);
//     printf("\n----------- vect4 = vect2 * vect3 (matrice)----------\n");
//     print_mat_without_index(mat2);
//     printf("\n----------- Sum vect4 ----------\n");
//     printf("%f", nbr);
//     printf("\n----------- Floatmax ----------\n");
//     printf("%f", nbr);
//     return;
// }

// void test_activ_utils()
// {
//     vect vect1;
//     vect vect2;
//     vect vect3;
//     float nbr1;
//     float nbr2;
//     float nbr3;

//     vect1 = init_vect_random(4);
//     vect2 = init_vect_random(5);
//     vect3 = init_vect_random(9);
//     nbr1 = sigmoid(-5);
//     nbr2 = ft_tanh(13.9897893);
//     nbr3 = relu(13.9897893);
//     printf("\n----------- vect1 ----------\n");
//     print_vect(vect1);
//     printf("\n----------- vect1 avant sigmoid ----------\n");
//     print_vect(vect1);
//     sigmoid_tab(vect1, vect1);
//     printf("\n----------- vect1 après sigmoid ----------\n");
//     print_vect(vect1);
//     printf("\n----------- vect1 avant deriv ----------\n");
//     print_vect(vect1);
//     deriv(sigmoid, vect1);
//     printf("\n----------- deriv(sigmoid, vect1) ----------\n");
//     print_vect(vect1);
//     /* */
//     printf("\n----------- vect2 avant ft_tanh ----------\n");
//     print_vect(vect2);
//     ft_tanh_tab(vect2);
//     printf("\n----------- vect2 après ft_tanh ----------\n");
//     print_vect(vect2);
//     /**/
//     printf("\n----------- vect3 avant relu----------\n");
//     print_vect(vect3);
//     relu_tab(vect3);
//     printf("\n----------- vect3 après relu ----------\n");
//     print_vect(vect3);
//     /**/
//     printf("\n----------- nbr1 = sigmoid(-5) ----------\n");
//     printf("%.10f\n", nbr1);
//     /**/
//     printf("\n----------- nbr2 = ft_tanh(13.9897893) ----------\n");
//     printf("%.10f\n", nbr2);
//     /**/
//     printf("\n----------- nbr3 = relu(13.9897893) ----------\n");
//     printf("%.10f\n", nbr3);
//     /**/
//     return;
// }


// t_layers *test_init_reseau(vect test_expected_output)
// {
//     t_layers *layer_test;
//     vect expected_output;
//     int nbr_layer_test;

//     nbr_layer_test = 3;
//     test_expected_output.size = 3;
//     layer_test = calloc(nbr_layer_test, sizeof(t_layers));
//     if(!layer_test)
//     {
//         printf("Erreur dans l'allocation du layer_test\n");
//         exit(-1);
//     }
//     write(1, "a", 1);


//     layer_test[2].size = test_expected_output.size;
//     layer_test[1].size = layer_test[2].size;
//     layer_test[0].size = 3;







//     layer_test[2].W = init_matrice_he(layer_test[1].size, layer_test[2].size);
//     layer_test[2].output.size = test_expected_output.size;
//     layer_test[2].output.vect = calloc(test_expected_output.size, sizeof(float));
//     layer_test[2].delta.size = test_expected_output.size;
//     layer_test[2].delta.vect = calloc(test_expected_output.size, sizeof(float));
//     layer_test[2].activation.size = test_expected_output.size;
//     layer_test[2].activation.vect = calloc(test_expected_output.size, sizeof(float));
//     layer_test[2].gradient = init_matrice_zero(layer_test[1].size, layer_test[2].size);
//     layer_test[2].biais.size = layer_test[2].size;
//     layer_test[2].biais = init_vect_zero(layer_test[2].size);

//     write(1, "b", 1);
//     layer_test[1].size = layer_test[2].size; //sortie (int column)
//     layer_test[1].W = init_matrice_he(layer_test[0].size, layer_test[1].size); //changement 0 et 1 
//     layer_test[1].output.size = 3;
//     layer_test[1].output.vect = calloc(3, sizeof(float));
//     layer_test[1].delta.size = 3;
//     layer_test[1].delta.vect = calloc(3, sizeof(float));
//     layer_test[1].activation.size = 3;
//     layer_test[1].activation.vect = calloc(3, sizeof(float));
//     layer_test[1].gradient = init_matrice_zero(layer_test[0].size, layer_test[1].size);  // changement aussi 
//     layer_test[1].biais.size = layer_test[1].size;
//     layer_test[1].biais = init_vect_zero(layer_test[1].size);

//     /* ----- Calloc du bloc reservé à l'input ----- */
//     write(1, "c", 1);
//     layer_test[0].size = 3;
//     layer_test[0].output.size = 3;
//     layer_test[0].output.vect = calloc(3, sizeof(float));
//     layer_test[0].activation.size = 3;
//     layer_test[0].activation.vect = calloc(3, sizeof(float));
    


    // layer_test[1].size = layer_test[2].size; //sortie (int column)
    // layer_test[1].W = init_matrice_he(layer_test[0].size, layer_test[1].size); //changement 0 et 1 
    // layer_test[1].output.size = 3;
    // layer_test[1].output.vect = calloc(3, sizeof(float));
    // layer_test[1].delta.size = 3;
    // layer_test[1].delta.vect = calloc(3, sizeof(float));
    // layer_test[1].activation.size = 3;
    // layer_test[1].activation.vect = calloc(3, sizeof(float));
    // layer_test[1].gradient = init_matrice_zero(layer_test[0].size, layer_test[1].size);  // changement aussi 
    // layer_test[1].biais.size = layer_test[1].size;
    // layer_test[1].biais = init_vect_zero(layer_test[1].size);
    // write(1, "b", 1);

    // layer_test[2].size = test_expected_output.size;
    // layer_test[2].W = init_matrice_he(layer_test[1].size, layer_test[2].size);
    // layer_test[2].output.size = 3;
    // layer_test[2].output.vect = calloc(3, sizeof(float));
    // layer_test[2].delta.size = 3;
    // layer_test[2].delta.vect = calloc(3, sizeof(float));
    // layer_test[2].activation.size = 3;
    // layer_test[2].activation.vect = calloc(3, sizeof(float));
    // layer_test[2].gradient = init_matrice_zero(layer_test[1].size, layer_test[2].size);
    // layer_test[2].biais.size = layer_test[2].size;
    // layer_test[2].biais = init_vect_zero(layer_test[2].size);
    // write(1, "c", 1);

    
//     print_reseau(layer_test, 3);
//     return(layer_test);
// }

// void test_reseau_forward()
// {
//     t_layers *layers;
//     vect input;
//     vect expected_output;
//     int nbr_layers;

//     input = init_vect_zero(3); //196
//     expected_output = init_vect_zero(3);

//     input.vect[0] = -1;
//     input.vect[1] = -2;
//     input.vect[2] = -9;

//     expected_output.vect[0] = 0;
//     expected_output.vect[1] = 0;
//     expected_output.vect[2] = 1;

//     layers = test_init_reseau();

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