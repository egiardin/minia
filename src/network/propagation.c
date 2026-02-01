#include "minia.h"

void forward_propagation(t_layers *layers, int nbr_layers, mat input)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while(k < input.column)
    {
        layers[i].output.mat[0][k] = input.mat[0][k];
        k++;
    }
    i++;
    while(i < nbr_layers)
    {
        if(i == 1)
            mult_mat(layers[i - 1].output, layers[i].W, layers[i].output);
        else
            mult_mat(layers[i - 1].activation, layers[i].W, layers[i].output);


        add_mat(layers[i].output, layers[i].biais, layers[i].activation);
        if(i == (nbr_layers - 1))
            softmax(layers[i].activation);
        else
            relu_tab(layers[i].activation);
        i++;
    }
}


void calc_gradient(t_layers *layers, int nbr_layers, mat input)
{
    int i;

    i = nbr_layers - 1;
    while(i > 1)
    {
        mult_mat_transp_a(layers[i - 1].activation, layers[i].delta, layers[i].gradient);
        i--;
    }
     mult_mat_transp_a(input, layers[i].delta, layers[i].gradient);
     return;
}

void calc_delta(t_layers *layers, mat expected_output, int nbr_layers) 
{
    mat tmp_mat;
    mat deriv_temp;
    int i;

    i = nbr_layers - 1;
    soust_mat(layers[i].activation, expected_output, layers[i].delta);
    i = nbr_layers - 2;
    while(i > 0)
    {
        deriv_temp = init_matrice_zero(1, layers[i].activation.column);
        tmp_mat = init_matrice_zero(layers[i + 1].W.column, layers[i + 1].W.line);    //W1 transposé
        transp_mat(layers[i + 1].W, tmp_mat);
        mult_mat(layers[i + 1].delta, tmp_mat, layers[i].delta); //à verifier en detail
        copy_vect(layers[i].activation, deriv_temp);
        deriv_relu(deriv_temp);
        produit_hadamard(layers[i].delta , deriv_temp, layers[i].delta);
        free_mat(deriv_temp);
        free_mat(tmp_mat);
        i--;
    }
    return;
}

void update_weight(t_layers *layers, float learning_rate, int nbr_layers)
{
    int i;
    mat tmp;

    i = nbr_layers - 1;
    while(i > 0)
    {
        tmp = init_matrice_zero(layers[i].gradient.line, layers[i].gradient.column);
        copy_vect(layers[i].gradient, tmp);
        mult_nbr_mat(learning_rate, tmp);
        soust_mat(layers[i].W, tmp, layers[i].W);
        free_mat(tmp);
        i--;
    }
    return;
}


void update_biais(t_layers *layers, float learning_rate, int nbr_layers)
{
    int i;
    int j;
    
    i= nbr_layers - 1;
    while (i > 0)
    {
        j = 0; 
        while (j < layers[i].biais.column)
        {
            layers[i].biais.mat[0][j] -= learning_rate * layers[i].delta.mat[0][j];
            j++;
        }
        i--;
    }
}

void back_propagation(t_layers *layers, mat expected_output, int nbr_layers, float learning_rate, mat input)
{
    calc_delta(layers, expected_output, nbr_layers);
    calc_gradient(layers, nbr_layers, input);
    update_weight(layers, learning_rate, nbr_layers);
    update_biais(layers, learning_rate, nbr_layers);
    return;
}