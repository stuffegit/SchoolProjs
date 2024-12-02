#ifndef TREE_H
#define TREE_H

struct node_t {
  int value;
  struct node_t* left;
  struct node_t* right;
};

struct node_t* insert(struct node_t* root, int value);
struct node_t* search(struct node_t* root, int value);
void inorder(struct node_t* root);
void free_tree(struct node_t* root);

#endif // !TREE_H
