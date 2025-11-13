#include "minia.h"

void test_mat_utils()
{
    mat mat0;
    mat mat1;
    mat mat2;
    mat mat3;
    mat mat4;
    mat mat5;
    mat mat6;
    mat mat7;
    vect vect1;
    vect vect2;
    float nbr;

    mat0 = init_matrice_random(3, 4);
    mat1 = init_matrice_random(3, 4);
    mat2 = init_matrice_random(4, 7);
    mat3 = init_matrice_zero(3, 7);
    mat4 = init_matrice_zero(4, 3);
    mat5 = init_matrice_zero(4, 9);
    mat6 = init_matrice_zero(3, 4);
    mat7 = init_matrice_random(4, 4);
    nbr = 2.0;
    vect1 = init_tab_random(4);
    vect2 = init_tab_zero(4);

    mult_mat(mat1, mat2, mat3);
    transp_mat(mat1, mat4);
    soust_mat(mat0, mat1, mat6);
    printf("\n----------- mat0 matrice random ----------\n");
    print_mat(mat0);
    printf("\n----------- mat1 matrice random ----------\n");
    print_mat(mat1);
    printf("\n----------- mat2 matrice random ----------\n");
    print_mat(mat2);
    printf("\n----------- mat3 = mat1 * mat2 ----------\n");
    print_mat(mat3);
    printf("\n----------- mat4 = transposé mat1 ----------\n");
    print_mat(mat4);
    printf("\n----------- mat5 = matrice à zéro----------\n");
    print_mat(mat5);
    printf("\n----------- mat6 = mat0 - mat1 ----------\n");
    print_mat(mat6);
    mult_nbr_mat(nbr,mat1);
    printf("\n----------- mat1 = nbr * mat1 ----------\n");
    print_mat(mat1);
    mult_vect_mat(vect1, mat7, vect2);
    printf("\n----------- vect2 = vect1 * mat7 ----------\n");
    printf("----vect1----\n");
    print_tab(vect1);
    printf("----mat0---\n");
    print_mat(mat7);
    printf("\n");
    print_tab(vect2);
    return;
}

void test_tab_utils()
{
    vect vect1;
    vect vect2;
    vect vect3;
    vect vect4;
    vect vect5;
    vect vect6;
    vect vect7;
    mat mat1;
    mat mat2;
    float nbr;
    float floatmx;

    vect1 = init_tab_zero(7);
    vect2 = init_tab_random(7);
    vect3 = init_tab_random(7);
    vect4 = init_tab_zero(7);
    vect5 = init_tab_zero(7);
    mat1 = init_matrice_zero(7, 0);
    mat2 = init_matrice_zero(vect2.size, vect3.size);
    floatmx = floatmax(nbr);

    mult_tab(vect2, vect3, vect4);
    soust_vect(vect4, vect3, vect5);
    transp_vect(vect2, mat1);
    mult_vect_vect(vect2, vect3, mat2);
    nbr = sum_tab(vect4);

    printf("\n----------- vect1 vecteur zéro ----------\n");
    print_tab(vect1);
    printf("\n----------- vect2 vecteur random ----------\n");
    print_tab(vect2);
    printf("\n----------- vect3 vecteur random ----------\n");
    print_tab(vect3);
    printf("\n----------- vect4 = vect2 * vect3 (produit scalaire)----------\n");
    print_tab(vect4);
    printf("\n----------- vect5 = vect4 - vect3 ----------\n");
    print_tab(vect5);
    printf("\n----------- transp de vect2 ---------\n");
    printf("\n----- vect2 ------\n");
    print_tab(vect2);
    printf("\n----- mat1------\n");
    print_mat(mat1);
    printf("\n----------- vect4 = vect2 * vect3 (matrice)----------\n");
    print_mat(mat2);
    printf("\n----------- Sum vect4 ----------\n");
    printf("%f", nbr);
    printf("\n----------- Floatmax ----------\n");
    printf("%f", nbr);
    return;
}

void test_activ_utils()
{
    vect vect1;
    vect vect2;
    vect vect3;
    float nbr1;
    float nbr2;
    float nbr3;

    vect1 = init_tab_random(4);
    vect2 = init_tab_random(5);
    vect3 = init_tab_random(9);
    nbr1 = sigmoid(-5);
    nbr2 = ft_tanh(13.9897893);
    nbr3 = relu(13.9897893);
    printf("\n----------- vect1 ----------\n");
    print_tab(vect1);
    printf("\n----------- vect1 avant sigmoid ----------\n");
    print_tab(vect1);
    sigmoid_tab(vect1, vect1);
    printf("\n----------- vect1 après sigmoid ----------\n");
    print_tab(vect1);
    printf("\n----------- vect1 avant deriv ----------\n");
    print_tab(vect1);
    deriv(sigmoid, vect1);
    printf("\n----------- deriv(sigmoid, vect1) ----------\n");
    print_tab(vect1);
    /* */
    printf("\n----------- vect2 avant ft_tanh ----------\n");
    print_tab(vect2);
    ft_tanh_tab(vect2);
    printf("\n----------- vect2 après ft_tanh ----------\n");
    print_tab(vect2);
    /**/
    printf("\n----------- vect3 avant relu----------\n");
    print_tab(vect3);
    relu_tab(vect3);
    printf("\n----------- vect3 après relu ----------\n");
    print_tab(vect3);
    /**/
    printf("\n----------- nbr1 = sigmoid(-5) ----------\n");
    printf("%.10f\n", nbr1);
    /**/
    printf("\n----------- nbr2 = ft_tanh(13.9897893) ----------\n");
    printf("%.10f\n", nbr2);
    /**/
    printf("\n----------- nbr3 = relu(13.9897893) ----------\n");
    printf("%.10f\n", nbr3);
    /**/
    return;
}
