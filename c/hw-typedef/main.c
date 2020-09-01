#include <stdio.h>

// typedef allows for an alias to be assigned to a data type,
// in this case the professional_programmer struct is aliased
// to just programmer.
typedef struct professional_programmer {
	const char *name;
	const char *programming_language;
	int age;
} programmer;

void print_info(programmer p)
{
	printf("%s is %i and likes to program using %s!\n",
		p.name, p.age, p.programming_language);
}

int main()
{
	programmer bob = {"Bob", "C", 42};
	print_info(bob);
	return 0;
}
