#ifndef MINIA_H
 #define MINIA_H

 #include "struct.h"
 #include "stdio.h"
 #include "stdlib.h"
 #include "math.h"
 #include "unistd.h"
 #include "assert.h"
 #include "string.h"

 #define PI 3.14159265359

 /*-----------Tab_utils----------*/

 void print_tab(vect vecteur);
 vect init_tab_random(int size);
 vect init_tab_zero(int size);
 void mult_tab(vect tab1, vect tab2, vect output);
 float sum_tab(vect tab);
 float floatmax(float nbr);
 void soust_vect(vect v1, vect v2, vect output);
 void transp_vect(vect v1, mat output);
 void mult_vect_vect(vect v1, vect v2, mat output);
 void free_vect(vect *v1);
 void  copy_vect(vect v1, vect v2); 
 void add_vect(vect ouput, vect biais, vect activation);
 void mult_nbr_vect(float nbr, vect biais);


 /*-----------Mat_utils----------*/

 mat init_matrice_random(int line, int column);
 mat init_matrice_he(int line, int column);
 mat init_matrice_zero(int line, int column);
 void print_mat(mat mat);
 void mult_mat(mat mat1, mat mat2, mat output);
 void mult_vect_mat(vect v, mat mat1, vect output);
 void mult_mat_vect(vect v, mat mat1, vect output);
 void transp_mat(mat mat1, mat output);
 void free_mat(mat mat1);
 void free_partial_mat(mat mat1, int line);
 void soust_mat(mat mat1, mat mat2, mat output);
 void mult_nbr_mat(float nbr, mat mat1);


 /*-----------Activ_utils----------*/

 void sigmoid_tab(vect tab, vect output);
 void ft_tanh_tab(vect tab);
 void relu_tab(vect tab);
 float sigmoid(float nbr);
 float ft_tanh(float nbr);
 float relu(float nbr);
 void deriv(float (*f)(float), vect v1);
 void deriv_relu(vect v1);

 /*-----------Reseau_utils-----------*/

 void print_reseau(t_layers *layers, int nbr_layers);
 void print_layer(t_layers *layers, int index);

 /*---------- Init_reseau------------*/

 t_layers *init_reseau(void);

 /*------------Transformation-----------*/

void forward_propagation(t_layers *layers, int nbr_layers, vect input);
void back_propagation(t_layers *layers, vect expected_output, int nbr_layers, float learning_rate, vect input);
void calc_gradient(t_layers *layers, int nbr_layers, vect input);
void calc_delta(t_layers *layers, vect expected_output, int nbr_layers);
void update_weight(t_layers *layers, float learning_rate, int nbr_layers);

 /*------------- Test --------------*/

 void test_mat_utils(void);
 void test_tab_utils(void);
 void test_activ_utils(void);

 /*----------- Test Reseau -----------*/

 void test_reseau_forward(void);
 void test_reseau_backpropagation(void);

 /*------------ Math_utils -----------*/

 float calc_density_function(int x, float mu, float sigma);
 float normal_random(float mu, float sigma);

 /*------------ Training -------------*/
 
  /*------------ Normalization -------------*/
 

#endif