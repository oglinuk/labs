#include <stdio.h>

typedef struct professional_programmer {
	const char *name;
	const char *programming_language;
	int age;
} programmer;

void print_info(programmer p)
{
	fprintf(stdout, "%s is %i and likes to program using %s!\n",
		p.name, p.age, p.programming_language);
}

int main()
{
	programmer bob = {"Bob", "C", 42};
	print_info(bob);
	return 0;
}
