#include "minia.h"

void relu_tab(mat mat1)
{
    int i;

    i = 0;
    while(i < mat1.column)
    {
        mat1.mat[0][i] = floatmax(mat1.mat[0][i]);
        i++;
    }
    return;
}

float sigmoid(float nbr)
{
    float res;

    res = 1 / (1 + expf(-nbr));
    return(res);
}

float ft_tanh(float nbr)
{
    float res;

    res = (expf(nbr) - expf(-nbr)) / (expf(nbr) + expf(-nbr));
    return(res);
}

float relu(float nbr)
{
    float res;

    res = floatmax(nbr);
    return(res);
}

void deriv_relu(mat v1)
{
    int i;
 
    i = 0;
    while(i < v1.column)
    {
        if(v1.mat[0][i] > 0)
        {
            v1.mat[0][i] = 1;
        }
        else
            v1.mat[0][i] = 0;
        i++;
    }
    return;
}

void softmax(mat output)
{
    int i;
    float somme;
    float max_val;

    max_val = output.mat[0][0];
    i = 0;
    while(i < output.column)
    {
        if (output.mat[0][i] > max_val)
            max_val = output.mat[0][i];
        i++;
    }
    somme = 0;
    i = 0;
    while(i < output.column)
    {
        output.mat[0][i] = expf(output.mat[0][i] - max_val);
        somme = somme + output.mat[0][i];
        i++;
    }
    i = 0;
    while(i < output.column)
    {
        output.mat[0][i] = output.mat[0][i] / somme;
        i++;
    }
}