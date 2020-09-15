#include <stdio.h>
#include <stdarg.h>

enum setup {
    DESKTOP,
    LAPTOP,
    MONITOR,
    KEYBOARD,
    MOUSE,
    HEADPHONES
};

double price(enum setup s)
{    
    switch(s) {
    case DESKTOP:
        return 999.99;
    case LAPTOP:
        return 499.99;
    case MONITOR:
        return 199.99;
    case KEYBOARD:
        return 149.99;
    case MOUSE:
        return 99.99;
    case HEADPHONES:
        return 49.99;
    }

    return 0;
}

// The print_totals function contains macros (va_start, va_arg, and va_end). A macro is a set
// of instructions that are expanded by the preprocessor before the compilation of the program.
void print_total(int args, ...)  // The ... (ellipsis) means there are more arguments to come.
{
    double total = 0;

    va_list ap; // Used to store extra arguments passed to the function.
    va_start(ap, args); // Where the variable arguments start.
    for (int i = 0; i < args; i++) {
        enum setup s = va_arg(ap, enum setup); // Read the arguments stored in the va_list and pass
                                               // enum to indicate the type of the next argument.
        total = total += price(s);
    }
    va_end(ap); // Indicate the end of the arguments.

    printf("Total cost of setup: $%.2f\n", total);
}

int main()
{
    print_total(2, LAPTOP, HEADPHONES);
    print_total(5, DESKTOP, MONITOR, KEYBOARD, MOUSE, HEADPHONES);
}