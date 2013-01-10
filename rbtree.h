#ifndef RBTREE_H
#define RBTREE_H

/* An implementation of a Red Black Tree in C. *
 * Due to embedded system constraints, *
 * no recursion is allowed */
typedef struct rbtree rbtree;

/* A comparator function returns 0 if the elements are equal *
 * If the left hand side is greater, it returns a positive value *
 * If the right hand side is greater, it returns a negative value */
typedef int (*comparator)(void *lhs, void *rhs);

/* Creates a new RB Tree. *
 * If no comparator is given, *
 * the pointers are just compared */
rbtree *RBNew(comparator compare);

/* Deletes the RB Tree */
void RBDelete(rbtree *tree);

/* Removes all elements from the RB Tree */
void RBEmpty(rbtree *tree);

/* Inserts an element into the RB Tree.
 * Returns 0 on success */
int RBInsert(rbtree *tree, void *data);

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

#endif // RBTREE_H
