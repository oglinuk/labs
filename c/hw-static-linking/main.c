#include <stdio.h>

// The compiler looks for header files using < > in
// standard header directories. The /usr/local/include
// directory is the first place checked and used for 
// third-party libraries. The /usr/include directory
// is normally for operating system header file.
#include <encrypt.h>
#include <checksum.h>

int main()
{
    char s[] = "Speak friend and enter";
    encrypt(s);
    printf("Encrypted: '%s'\n", s);
    printf("Checksum: %i\n", checksum(s));
    encrypt(s);
    printf("Decrypted: %s\n", s);
    printf("Checksum: %i\n", checksum(s));
    return 0;
}