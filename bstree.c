#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>

bstree* bstree_create(int key, char* value)
{
    bstree* node;

    node = malloc(sizeof(*node));
    if (node != NULL) {
        node->key = key;
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
};

void bstree_add(bstree* tree, int key, char* value)
{
    if (tree == NULL)
        return;
    bstree *parent, *node;

    while (tree != NULL) {
        parent = tree;
        if (key < tree->key)
            tree = tree->left;
        else if (key > tree->key)
            tree = tree->right;
        else
            return;
    }

    node = bstree_create(key, value);

    if (key < parent->key)
        parent->left = node;
    else
        parent->right = node;
};

bstree* bstree_lookup(bstree* tree, int key)
{
    while (tree != NULL) {
        if (key == tree->key)
            return tree;
        else if (key < tree->key)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return tree;
};

bstree* bstree_delete(bstree* tree, int key)
{

    bstree **q, *z;

    q = &tree;
    z = tree;
    //поиск удаляемого элемента
    while (1) {
        if (z == NULL)
            return 0;
        else if (key == z->key)
            break;
        else if (key > z->key) {
            q = &z->right;
            z = z->right;
        } else {
            q = &z->left;
            z = z->left;
        }
    }

    // непосредственное удаление элемента
    if (z->right == NULL)
        *q = z->left;
    else {
        bstree* y = z->right;
        if (y->left == NULL) {
            y->left = z->left;
            *q - y;
        } else {
            bstree* x = y->left;
            while (x->left != NULL) {
                y = x;
                x = y->left;
            }
            y->left = x->right;
            x->left = z->left;
            x->right = z->right;
            *q = x;
        }
    }
    free(z);
};

bstree* bstree_min(bstree* tree)
{
    if (tree == NULL)
        return NULL;

    while (tree->left != NULL)
        tree = tree->left;
    return tree;
};

bstree* bstree_max(bstree* tree)
{
    if (tree == NULL)
        return NULL;

    while (tree->right != NULL)
        tree = tree->right;
    return tree;
};