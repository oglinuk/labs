#include <stdio.h>

struct person {
	const char *name;
	const char *programming_language;
	int age;
    int times_cried;
};

void print_info(struct person p)
{
	printf("%s is %i, programs in %s, and has cried %i times\n",
        p.name, p.age, p.programming_language, p.times_cried);
}

void cry(struct person *p)
{
    p->times_cried++; // p->times_cried is the same as (*p).times_cried
    print_info(*p);
}

int main()
{
	struct person bob = {"Bob", "C", 42, 0};
	print_info(bob);
    cry(&bob); // If we just passed bob and not the reference to our person bob, then
               // cry would increment a copy of bob value not the original.
	return 0;
}
