#include "minia.h"

float calc_density_function(int x, float mu, float sigma)
{
    if(sigma == 0)
    {
        fprintf(stderr, "sigma est nulle");
        return(0);
    }
    float res;

    res = 0;
    res = (1 / (sigma * sqrt(2 * PI))) * exp(- ((x - mu) * (x - mu)) / (2 * (sigma * sigma)));
    return(res);
}

float normal_random(float mu, float sigma)
{
    static int second = 0;
    static float res_stock;
    float u1;
    float u2;
    float r;
    float teta;
    float res;

    if(second)
    {
        second = 0;
        return(mu + sigma * res_stock);
    }

    u1 = (float)rand() / (float)RAND_MAX;
    u2 = (float)rand() / (float)RAND_MAX;
    if(u1 <= 0)
        u1 = 0.0000001;
    r = sqrtf(-2.0f * logf(u1));
    teta = 2.0f * PI * u2;
    res = mu + (sigma * (r * cosf(teta)));
    res_stock = r * sinf(teta);
    second = 1;
    return(res);
}
