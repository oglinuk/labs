#include <string.h>
#include "utils.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, 
            "Usage: ./filter <csv file> <filter 0> <filter N> ...\n");
        return 1;
    }

    float lat;
    float lon;
    char info[80];

    FILE *dataf;
    FILE *filters[argc - 2];

    if (!(dataf = fopen(argv[1], "r"))) {
        fprintf(stderr, "%s does not seem to exist ...\n", argv[1]);
    }

    for (int i = 0; i < ARRAYSIZE(filters); i++) {
        if (!(filters[i] = fopen(argv[i+2], "w"))) {
            fprintf(stderr, "Could not open %s ...\n", argv[i]);
            return 1;
        }
    }

    while (fscanf(dataf, "%f, %f, %79[^\n]", &lat, &lon, info) == 3) {
        for (int i = 0; i < ARRAYSIZE(filters); i++) {
            if (strcmp(info, argv[i+2]) == 0) {
                fprintf(filters[i], "%f, %f, %s\n", lat, lon, info);
            }
        }
    }
    fclose(*filters);
    return 0;
}
