#include "minia.h"

mat init_matrice_he(int line, int column) 
{
    mat mat;
    int i;
    int j;

    i = 0;
    j = 0;
    mat.line = line;
    mat.column = column;
    mat.mat = calloc(line, sizeof(float *));
    if(!mat.mat)
    {
        mat.line = 0;
        mat.column = 0;
        return(mat);
    }
    while(i < line)
    {
        mat.mat[i] = calloc(column, sizeof(float));
        if(!mat.mat[i])
        {
            free_partial_mat(mat, i);
            mat.line = 0;
            mat.column = 0;
            return(mat);
        }
        while(j < column)
        {
            mat.mat[i][j] = normal_random(0, sqrtf(2.0f / column));
            j++;
        }
        j = 0;
        i++;
    }
    return(mat);
}

mat init_matrice_random(int line, int column) 
{
    mat mat;
    int i;
    int j;
    int nbr;

    i = 0;
    j = 0;
    nbr = 1;
    mat.line = line;
    mat.column = column;
    mat.mat = calloc(line, sizeof(float *));
    if(!mat.mat)
    {
        mat.line = 0;
        mat.column = 0;
        return(mat);
    }
    while(i < line)
    {
        mat.mat[i] = calloc(column, sizeof(float));
        if(!mat.mat[i])
        {
            free_partial_mat(mat, i);
            mat.line = 0;
            mat.column = 0;
            return(mat);
        }
        while(j < column)
        {
            mat.mat[i][j] = nbr;
            nbr++;
            j++;
        }
        j = 0;
        i++;
    }
    return(mat);
}

mat init_matrice_zero(int line, int column)
{
    mat mat;
    int i;
    int j;

    i = 0;
    j = 0;
    mat.line = line;
    mat.column = column;
    mat.mat = calloc(line, sizeof(float *));
    if(!mat.mat)
    {
        mat.line = 0;
        mat.column = 0;
        return(mat);
    }
    while(i < line)
    {
        mat.mat[i] = calloc(column, sizeof(float));
        if(!mat.mat[i])
        {
            free_partial_mat(mat, i);
            mat.line = 0;
            mat.column = 0;
            return(mat);
        }
        while(j < column)
        {
            mat.mat[i][j] = (float)0;
            j++;
        }
        j = 0;
        i++;
    }
    return(mat);
}

void print_mat(mat mat)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < mat.line)
    {
        while(j < mat.column)
        {
            printf("mat[%d][%d] = %.5f\n", i, j, mat.mat[i][j]);
            j++;
        }
        j = 0;
        i++;
    }
}

void mult_mat(mat mat1, mat mat2, mat output) 
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while(i < output.line)
    {
        while(j < output.column)
        {
            while(k < mat1.column)
            {
                output.mat[i][j] += mat1.mat[i][k] * mat2.mat[k][j];
                k++;
            }
            k = 0;
            j++;
        }
        i++;
        j = 0;
        k =0;
    }
    return;
}

void soust_mat(mat mat1, mat mat2, mat output)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < mat1.line)
    {
        while(j < mat1.column)
        {
            output.mat[i][j] = mat1.mat[i][j] - mat2.mat[i][j];
            j++;
        }
        j = 0;
        i++;
    }
    return;
}

void mult_nbr_mat(float nbr, mat mat1)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < mat1.line)
    {
        while(j < mat1.column)
        {
            mat1.mat[i][j] = nbr * mat1.mat[i][j];
            j++;
        }
        j = 0;
        i++;
    }
    return;
}

void mult_vect_mat(vect v, mat mat1, vect output)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(j < mat1.column)
    {
        output.vect[j] = 0;
        while(i < mat1.line)
        {
            output.vect[j] += v.vect[i] * mat1.mat[i][j];
            i++;
        }
        i = 0;
        j++;
    }
    return;
}

void mult_mat_vect(vect v, mat mat1, vect output)
{
        int i;
    int j;

    i = 0;
    j = 0;
    while(i < mat1.line)
    {
        output.vect[i] = 0;
        while(j < mat1.column)
        {
            output.vect[i] += mat1.mat[i][j] * v.vect[j];
            j++;
        }
        j = 0;
        i++;
    }
    return;
}

void transp_mat(mat mat1, mat output) 
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < mat1.line)
    {
        while(j < mat1.column)
        {
            output.mat[j][i] = mat1.mat[i][j];
            j++;
        }
        j = 0;
        i++;
    }
    return;
}

void free_mat(mat mat1)
{
    int i;

    i = 0;
    while(i < mat1.line)
    {
        free(mat1.mat[i]);
        i++;
    }
    free(mat1.mat);
}

void free_partial_mat(mat mat1, int line)
{
    int i;

    i = 0;
    while(i < line)
    {
        free(mat1.mat[i]);
        i++;
    }
    free(mat1.mat);
}