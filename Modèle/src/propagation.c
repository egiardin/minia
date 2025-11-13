#include "minia.h"

void forward_propagation(t_layers *layers, int nbr_layers, vect input)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while(k < input.size)
    {
        layers[i].output.vect[k] = input.vect[k];
        k++;
    }
    i++;
    while(i < nbr_layers)
    {
        if(i == 1)
            mult_vect_mat(layers[i - 1].output, layers[i].W, layers[i].output);
        else
            mult_vect_mat(layers[i - 1].activation, layers[i].W, layers[i].output);
        add_vect(layers[i].output, layers[i].biais, layers[i].activation);
        if(i != (nbr_layers - 1))
            relu_tab(layers[i].activation);
        i++;
    }
}

void calc_gradient(t_layers *layers, int nbr_layers, vect input)
{
    int i;

    i = nbr_layers - 1;
    while(i > 1)
    {
        mult_vect_vect(layers[i].delta, layers[i - 1].activation, layers[i].gradient);
        i--;
    }
     mult_vect_vect(layers[i].delta, input, layers[i].gradient);
     return;
}

void calc_delta(t_layers *layers, vect expected_output, int nbr_layers) 
{
    mat tmp_mat;
    vect deriv_temp;
    int i;

    i = nbr_layers - 1;
    deriv_temp = init_tab_zero(layers[i].output.size);
    soust_vect(layers[i].activation, expected_output, layers[i].delta);
    copy_vect(layers[i].delta, deriv_temp);
    deriv_relu(deriv_temp);
    mult_tab(layers[i].delta, deriv_temp, layers[i].delta);
    free_vect(&deriv_temp);
    i = nbr_layers - 2;
    while(i > 0)
    {
        deriv_temp = init_tab_zero(layers[i].output.size);
        tmp_mat = init_matrice_zero(layers[i + 1].W.column, layers[i + 1].W.line);    
        transp_mat(layers[i + 1].W, tmp_mat);
        mult_mat_vect(layers[i + 1].delta, tmp_mat, layers[i].delta);
        copy_vect(layers[i].delta, deriv_temp);
        deriv_relu(deriv_temp);
        mult_tab(layers[i].delta , deriv_temp, layers[i].delta);
        free_vect(&deriv_temp);
        i--;
    }
    return;
}

void update_weight(t_layers *layers, float learning_rate, int nbr_layers)
{
    int i;

    i = nbr_layers - 1;
    while(i > 0)
    {
        mult_nbr_mat(learning_rate, layers[i].gradient);
        soust_mat(layers[i].W, layers[i].gradient, layers[i].W);
        i--;
    }
    return;
}

void update_biais(t_layers *layers, float learning_rate, int nbr_layers)
{
    int i;
    int j;
    
    j = 0;
    i= nbr_layers - 1;
    while (i > 0)
    {
        while (j < layers[i].biais.size)
        {
            layers[i].biais.vect[j] -= learning_rate * layers[i].delta.vect[j];
            j++;
        }
        i--;
    }
}


void back_propagation(t_layers *layers, vect expected_output, int nbr_layers, float learning_rate, vect input)
{
    calc_delta(layers, expected_output, nbr_layers);
    calc_gradient(layers, nbr_layers, input);
    update_weight(layers, learning_rate, nbr_layers);
    update_biais(layers, learning_rate, nbr_layers);
    return;
}
