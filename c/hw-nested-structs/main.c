#include <stdio.h>

struct programming_info {
	const char *language;
	int years_programming;
};

struct person {
	const char *name;
	int age;
	struct programming_info info;
};

void print_info(struct person p)
{
	printf("%s is %d and has been programming in %s for %d years!\n"
		, p.name, p.age, p.info.language, p.info.years_programming);
}

int main()
{
	struct person bob = {"Bob", 42, {"C", 7}};
	print_info(bob);
	return 0;
}
