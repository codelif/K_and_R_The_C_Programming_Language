#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSEED 13
#define HASHTABLE 101

struct tnode {
  struct tnode *next;
  char *key;
  char *value;
};

static struct tnode *hashtable[HASHTABLE];

unsigned hash(const char *c){
  unsigned hashval;

  for (hashval = 0; *c != '\0'; c++){
    hashval = *c + (HASHSEED * hashval);
  }
  
  return hashval % HASHTABLE;
}

struct tnode *lookup(const char *key){
  struct tnode *node;
  for (node = hashtable[hash(key)]; node != NULL; node = node->next){
    if (strcmp(key, node->key) == 0){
      return node;
    }
  }

  return NULL;
}

struct tnode *talloc(){
  return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode *install(const char *key, const char *value){
  struct tnode *node;
  node = hashtable[hash(key)];

  while (node != NULL && node->next != NULL){
    node = node->next;
    if (strcmp(node->key, key) == 0){
      node->value = strdup(value);
      return node;
    }
  }
  
  struct tnode *newnode = talloc();
  newnode->key = strdup(key);
  newnode->value = strdup(value);

  if (node == NULL){
    return (hashtable[hash(key)] = newnode);
  }else{
    return (node->next = newnode);
  }
}

void undef(char *key){
  struct tnode *node;
  struct tnode *temp;
  node = hashtable[hash(key)];
  
  while (node != NULL && node->next != NULL){
    if (strcmp(node->next->key, key) == 0){
      temp = node->next;
      node->next = node->next->next;
      free(temp);
      return;
    }
  }

  if (node != NULL && node->next == NULL){
    if (strcmp(node->key, key) == 0){
      hashtable[hash(key)] = NULL;
      return;
    }
  }
}


void printlist(struct tnode *node){
  while (node != NULL){
    printf("    \"%s\": \"%s\",\n", node->key, node->value);
    node = node->next;
  }
}

void print_table(){
  printf("{\n");
  for (int i = 0; i < HASHTABLE; i++){
    printlist(hashtable[i]);
  }
  printf("}\n");
}

int main(){
  install("harsh", "sharma");
  install("key1", "1");
  install("key2", "2");
  print_table();
  undef("key2");
  print_table();
}
