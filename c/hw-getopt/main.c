#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char ch;
    char *msg;

    if (argc < 2) {
        fprintf(stderr, "Usage: ./main -m <message>\n");
        return 1;
    }

    while ((ch = getopt(argc, argv, "m:")) != EOF) {
        switch(ch) {
            case 'm':
                msg = optarg;
                break;
            default:
                fprintf(stderr, "Unknown option: '%s'\n", optarg);
                return 1;
        }
    }
    argc -= optind;
    argv += optind;

    fprintf(stdout, "Breaking announcement: %s\n", msg);

    return 0;
}
