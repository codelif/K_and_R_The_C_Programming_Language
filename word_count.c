#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "getword.h"
#define MAXWORD 100


struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *talloc(void){
  return (struct tnode *) malloc(sizeof(struct tnode));
}

char *dupstr(char *str){
  char *m = (char *) malloc(strlen(str) + 1);
  strcpy(m, str);
  return m;
}

void treeprint(struct tnode *n){
  if (n != NULL){
    treeprint(n->left);
    printf("%3d\t%s\n", n->count, n->word);
    treeprint(n->right);
  }
}

int nodecount(struct tnode *n, int count){
  if (n != NULL) {
    count++;
    count = nodecount(n->left, count);
    count = nodecount(n->right, count);
  }

  return count;
}

int treesize(struct tnode *n){
  return nodecount(n, 0);
}

struct tnode *addtree(struct tnode *p, char *word){
  int cond;

  if (p == NULL){
    p = talloc();
    p->word = dupstr(word);
    p->count = 1;
    p->left = p->right = NULL;
  }else if ((cond = strcmp(p->word, word)) == 0){
    p->count++;
  }else if (cond > 0){
    p->left = addtree(p->left, word);
  }else{
    p->right = addtree(p->right, word);
  }

  return p;
}


void cpytree(struct tnode *p, struct tnode **tree){
  if (p != NULL){
    *(tree++) = p;
    cpytree(p->left, tree);
    cpytree(p->right, tree);
  }
}

int main(){
  struct tnode *root;
  char s[MAXWORD];
  
  root = NULL;
  while ((getword(s, MAXWORD)) != EOF){
    if (isalpha(*s) && strlen(s) > 1)
      root = addtree(root, s);
  }
  
  int size = treesize(root);
  struct tnode **tree = (struct tnode **) malloc (size * sizeof(struct tnode *))i[];
  
  cpytree(root, tree);
  for (int i = 0; i< size; i++){
    printf("%s\n", tree[i]->word);
  }
}
