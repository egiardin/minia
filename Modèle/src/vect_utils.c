#include "minia.h"

void print_tab(vect vecteur)
{
    int i;

    i = 0;
    while(i < vecteur.size)
    {
        printf("tab[%i] = %.5f\n", i, vecteur.vect[i]);
        i++;
    }
    return;
}

vect init_tab_random(int size)
{
    vect res;
    int i;

    i = 0;
    res.size = size;
    res.vect = calloc(size, sizeof(float));
    if(!res.vect)
    {
        res.size = 0;
        return(res);
    }
    while(i < res.size)
    {
        res.vect[i] = (float)rand() / (float)RAND_MAX;
        i++;
    }
    return(res);
}

vect init_tab_zero(int size)
{
    vect res;
    int i;

    i = 0;
    res.size = size;
    res.vect = calloc(size, sizeof(float));
    if(!res.vect)
    {
        res.size = 0;
        return(res);
    }
    while(i < res.size)
    {
        res.vect[i] = 1; //(float)0;
        i++;
    }
    return(res);
}

void mult_tab(vect tab1, vect tab2, vect output)
{
    int i;

    i = 0;
    while(i < tab1.size)
    {
       output.vect[i] =  tab1.vect[i] * tab2.vect[i];
       i++;
    }
    return;
}

void soust_vect(vect v1, vect v2, vect output)
{
    int i;

    i = 0;
    output.size = v1.size;
    while(i < output.size)
    {
        output.vect[i] = v1.vect[i] - v2.vect[i];
        i++;
    }
    return;
}

void transp_vect(vect v1, mat output)
{
    int i;

    i = 0;
    while(i < v1.size)
    {
        output.mat[i][0] = v1.vect[i];
        i++;
    }
    return;
}

void add_vect(vect ouput, vect biais, vect activation)
{
    int i;

    i = 0;
    while(i < activation.size)
    {
        activation.vect[i] = ouput.vect[i] + biais.vect[i];
        i++;
    }
    return;
}

void mult_vect_vect(vect v1, vect v2, mat output)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < output.line)
    {
        while(j < output.column)
        {
            output.mat[i][j] = v1.vect[i] * v2.vect[j];
            j++;
        }
        j = 0;
        i++;
    }
    return;
}

float sum_tab(vect tab)
{
    float sum;
    int i;

    sum = 0;
    i = 0;
    while(i < tab.size)
    {
        sum += tab.vect[i];
        i++;
    }
    return(sum);
}

float floatmax(float nbr)
{

    if (nbr < 0)
        return(0);
    else
        return(nbr);
}

void free_vect(vect *v1)
{
    if(v1->vect)
    {
        free(v1->vect);
        v1->vect = NULL;
        v1->size = 0;
    }
}

void  copy_vect(vect v1, vect v2)
{
    if(v1.size != v2.size)
    {
        write(1, "Erreur de size dans copy_vect", 30);
        return;
    }
    int i;

    i = 0;
    while(i < v1.size)
    {
        v2.vect[i] = v1.vect[i];
        i++;
    }
    return;
}

void mult_nbr_vect(float nbr, vect biais)
{
    int i;

    i = 0;
    while(i < biais.size)
    {
        biais.vect[i] *= nbr;
        i++;
    }
    return;
}