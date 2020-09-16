#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//              start_node
//          /                 \
//      node-yes            node-no
//     /        \          /        \
//  node-yes   node-no  node-yes  node-no
typedef struct node {
    char *question;
    struct node *no;
    struct node *yes;
} node;

void strip_sentinel(char word[])
{
    word[strlen(word)-1] = '\0';
}

int yes_no(char *question)
{
    char answer[3];
    printf("%s? [y/n]: ", question);
    fgets(answer, 3, stdin);
    return answer[0] == 'y';
}

node* create(char *question)
{
    node *n = malloc(sizeof(node));
    n->question = question;
    n->no = NULL;
    n->yes = NULL;
    return n;
}

void release(node *n)
{
    if (n) {
        if (n->no) {
            release(n->no);
        }
        if (n->yes) {
            release(n->yes);
        }
        if (n->question) {
            free(n->question);
        }
        free(n);
    }
}

int main()
{
    char question[80];
    char suspect[20];
    node *start_node = create("Does the suspect have a beard");
    start_node->no = create("Bob");
    start_node->yes = create("Alice");

    node *current;
    do {
        current = start_node;
        while (1) {
            if (yes_no(current->question)) {
                if (current->yes) {
                    current = current->yes;
                } else {
                    printf("Found the suspect!\n");
                    break;
                }
            } else if (current->no) {
                current = current->no;
            } else {
                printf("Who is the new suspect? ");
                fgets(ans, 20, stdin);
                strip_sentinel(ans);
                node *yes_node = create(ans);
                current->yes = yes_node;

                node *no_node = create(current->question);
                current->no = no_node;

                printf("What is TRUE for %s but not for %s? ", ans, current->question);
                fgets(question, 80, stdin);
                strip_sentinel(question);
                current->question = strdup(question);

                break;
            }
        }
    } while (yes_no("Run again"));
    release(start_node);
    return 0;
}