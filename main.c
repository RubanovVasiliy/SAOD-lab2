#include "bstree.h"
#include "hashtab.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int getrand(int min, int max);
double wtime();

int main(void)
{
    /*
    char w;
    double t;

    bstree tree = bstree_create(1, words[0]);
    for (int i = 2; i < 20000; i++) {
        tree = bstree_add(i - 1, words[i - 1]);
        if (i % 10000 == 0) {
            w = word[getRand(0, i - 1)];
            t = wtime();
            node = bstree_lookup(tree, w);
            t = wtime() - t;
            printf("n = %d; time = %.6lf", i - 1, t);
        }
    }

    */

    struct listnode* node;
    hashtab_init(hashtab);
    hashtab_add(hashtab, "Ocelot", 17);
    hashtab_add(hashtab, "Flamingo", 4);
    hashtab_add(hashtab, "Fox", 14);
    node = hashtab_lookup(hashtab, "Flamingo");
    if (node != NULL)
        printf("Node: %s, %d\n", node->key, node->value);

    return 0;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}