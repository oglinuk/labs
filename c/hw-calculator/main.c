#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}

double exponential(double a, double b)
{
    double n = 1.0;
    for (int i = 0; i < (int)b; i++) {
        n *= a;
    }
    return n;
}

void do_opreration(double a, char op, double b)
{
    double c;
    switch (op) {
    case '+':
        c = add(a, b);
        break;
    case '-':
        c = subtract(a, b);
        break;
    case 'x':
        c = multiply(a, b);
        break;
    case '/':
        c = divide(a, b);
        break;
    case '^':
        c = exponential(a, b);
        break;
    default:
        fprintf(stderr, "'%s' not a valid operation ...\n", op);
        exit(1);
    }
    printf("%lf %c %lf = %lf\n", a, op, b, c);
}

char getOp()
{
    char op;
    printf("Operator: ");
    scanf(" %c", &op);
    return op;
}

double getNum()
{
    double num;
    printf("Num: ");
    scanf("%lf", &num);
    return num;
}

int main(int argc, char *argv[])
{
    if (argc > 2) {
        printf("Arg1: %s\nArg2: %d\nArg3: %s\n", argv[1], argv[2][0], argv[3]);
        do_opreration(atof(argv[1]), argv[2][0], atof(argv[3]));
    } else {
        double a = getNum();
        char op = getOp();
        double b = getNum();
        do_opreration(a, op, b);
    }
    return 0;
}