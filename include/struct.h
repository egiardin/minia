#include "minia.h"

typedef struct
{
    int line;
    int column;
    float **mat;
} mat;

typedef struct s_layers
{
    int size;
    mat output;
    mat activation;
    mat delta;
    mat W;
    mat gradient;
    mat biais;

} t_layers;

typedef struct s_data
{
    uint32_t img_magic;
    uint32_t img_count;
    uint32_t lines;
    uint32_t columns;
    size_t total_alloc;
    unsigned char *all_img;

    uint32_t lbl_magic;
    uint32_t lbl_count;
    unsigned char *labels;

} t_data;
