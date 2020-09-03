#include <stdio.h>

// A bitfield allows for the specification of how many bits
// an individual field will store. The fields in the skillset
// struct all only of 1 byte size. Since the below is a sequence
// of bitfields, the computer will squash them together. The
// struct below can be stored in a single byte, since each of
// the 8 fields is only a single-bit bitfield. Each field in
// the struct represents a true/false value in this example.
// A bitfield should be declared as an unsigned int.
typedef struct {
    unsigned int c_programmer:1;
    unsigned int java_programmer:1;
    unsigned int python_programmer:1;
    unsigned int cpp_programmer:1;
    unsigned int go_programmer:1;
    unsigned int rust_programmer:1;
    unsigned int csharp_programmer:1;
    unsigned int asm_programmer:1;
} skillset;

int main()
{
    skillset bob = {1, 0, 1, 1, 1, 1, 0, 1};

    printf("Bob's skillset:\n* C: %i\n* Java: %i\n* Python: %i\n* C++: %i\n* Go: %i\n* Rust: %i\n* C#: %i\n* Assembly: %i\n",
        bob.c_programmer,
        bob.java_programmer,
        bob.python_programmer,
        bob.cpp_programmer,
        bob.go_programmer,
        bob.rust_programmer,
        bob.csharp_programmer,
        bob.asm_programmer);

    return 0;
}