#include "rbtree.h"
#include <stdlib.h>
#include <assert.h>

typedef enum RBNCOLOR {
    RED,
    BLACK
} RBNCOLOR;

typedef struct rbnode {
    /* No recursion, so we need to keep track of the parent as well */
    struct rbnode *lhs, *rhs, *parent;
    RBNCOLOR color;
    void *data;
} rbnode;

struct rbtree {
    rbnode *root;
    comparator comp;
};

/* Creates a new RB Tree. *
 * If no comparator is given, *
 * the pointers are just compared */
rbtree *RBNew(comparator compare)
{
    rbtree *tree = malloc(sizeof(rbtree));
    assert(tree);
    tree->comp = compare;
    tree->root = NULL;
    return tree;
}

/* Deletes the RB Tree */
void RBDelete(rbtree *tree)
{
    RBEmpty(tree);
    free(tree);
}

/* Removes all elements from the RB Tree */
void RBEmpty(rbtree *tree)
{
    rbnode *next = tree->root;
    while(next) {
        if(next->lhs) {
            next = next->lhs;
        }
        else if(next->rhs) {
            next = next->rhs;
        }
        else {
            next = next->parent;
            /* Make certain we didn't leave the root;
             * The roots parent is NULL */
            if(next) {
                /* Since we prefer the LHS of the tree,
                 * we delete it first because if it's there,
                 * we came from there */
                if(next->lhs) {
                    free(next->lhs);
                    next->lhs = NULL;
                }
                else {
                    /* We must have come from the RHS */
                    free(next->rhs);
                    next->rhs = NULL;
                }
            }
        }
    }
    free(tree->root);
}

/* Creates a RB Node. Returns NULL on failure */
rbnode *RBNNew(rbnode *parent, void *data)
{
    rbnode *node = malloc(sizeof(struct rbnode));
    if(!node)
        return NULL;
    node->parent = parent;
    node->data = data;
    node->color = RED;
    node->lhs = NULL;
    node->rhs = NULL;
    return node;
}

/* 'Helps' insert a non-root element */
int RBInsertHelper(rbtree *tree, void *data)
{
    return 0;
}

/* Inserts an element into the RB Tree.
 * Returns 0 on success */
int RBInsert(rbtree *tree, void *data)
{
    if(tree->root) {
        return RBInsertHelper(tree, data);
    }
    else {
        tree->root = RBNNew(NULL, data);
        assert(tree->root);
        if(tree->root) {
            tree->root->color = BLACK;
            return 0;
        }
        return 1;
    }
}

/* Removes an element from the RB Tree *
 * Returns 0 on success, 1 if the element does not exist */
int RBRemove(rbtree *tree, void *data);

/* Checks if the element is in the tree *
 * Returns true if the element is in the tree, else false */
int RBContains(rbtree *tree, void *data);

/* Returns the minimum element in the tree */
void *RBMinimum(rbtree *tree);

/* Returns the maximum element in the tree */
void *RBMaximum(rbtree *tree);

/* Returns the number of elements in the tree *
 * Returns a negative number for an invalid tree,
 * or asserts in debug mode */
int RBSize(rbtree *tree);

/* Takes as many elements in the RB Tree as it can, *
 * ordered from least to greatest, *
 * and puts them into the array */
void RBEnumerate(rbtree *tree, void **array, int length);

/* Takes as many elements in the RB Tree as it can, *
 * ordered from least to greatest, *
 * and puts them into the array */
void RBRange(rbtree *tree, void *lbound, void *ubound, void **array, int length);
