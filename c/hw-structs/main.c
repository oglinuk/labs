#include <stdio.h>

struct person {
	const char *name;
	const char *programming_language;
	int age;
};

void print_info(struct person p)
{
	printf("%s is %i and likes to program using %s!\n",
		p.name, p.age, p.programming_language);
}

int main()
{
	struct person bob = {"Bob", "C", 42};
	print_info(bob);
	return 0;
}
