#include "minia.h"

void sigmoid_tab(vect tab, vect res)
{
    int i;

    i = 0;
    while(i < tab.size)
    {
        res.vect[i] = 1 / (1 + expf(-tab.vect[i]));
        i++;
    }
    return;
}

void ft_tanh_tab(vect tab)
{
    int i;

    i = 0;
    while(i < tab.size)
    {
        tab.vect[i] = (expf(tab.vect[i]) - expf(-tab.vect[i])) / (expf(tab.vect[i]) + expf(-tab.vect[i]));
        i++;
    }
    return;
}

void relu_tab(vect tab)
{
    int i;

    i = 0;
    while(i < tab.size)
    {
        tab.vect[i] = floatmax(tab.vect[i]);
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

void deriv(float (*f)(float), vect v1)
{
    int i;
    float h;

    i = 0;
    h = 1e-5f;
    while(i < v1.size)
    {
        v1.vect[i] =  (f(v1.vect[i] + h) - f(v1.vect[i] - h)) / (2 * h);
        i++;
    }
    return;
}

void deriv_relu(vect v1)
{
    int i;
 
    i = 0;
    while(i < v1.size)
    {
        if(v1.vect[i] > 0)
        {
            v1.vect[i] = 1;
        }
        else
            v1.vect[i] = 0;
        i++;
    }
    return;
}