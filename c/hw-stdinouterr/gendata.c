#include <time.h>
#include <stdlib.h>
#include "utils.h"

float gen_float(int cap, int is_neg)
{
    float rnd_f;

    if (is_neg == 0) {
        rnd_f = (((float)rand()/(float)(RAND_MAX)) * cap) - cap;
    } else {
        rnd_f = ((float)rand()/(float)(RAND_MAX)) * cap;
    }
    return rnd_f;
}

int main()
{
    char categories[][8] = {
        "unknown",
        "known"
    };

    srand((unsigned int)time(NULL));
    FILE *genf = fopen("data.csv", "w");
    
    float cap = 42.0;

    for (int i = 0; i < 666; i++) {
        int is_neg = rand()%2;
        float lat = gen_float(90, is_neg);
        is_neg = rand()%2;
        float lon = gen_float(180, is_neg);
        fprintf(genf, "%f, %f, %s\n", lat, lon,
            categories[rand()%ARRAYSIZE(categories)]);
    }
    fclose(genf);
    return 0;
}
