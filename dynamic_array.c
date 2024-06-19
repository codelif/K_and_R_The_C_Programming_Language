#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
  int* array;
  int size;
  int capacity;
} vector;


vector *new_vector(int n){
  if (n < 1){
    return NULL;
  }


  vector *v;
  v = (vector *) malloc(sizeof(vector));
  v->array = (int *) malloc(n * sizeof(int));

  v->size = 0;
  v->capacity = n;
  return v;
}



void resize_vector(vector *v, int new_cap){
  if (!v){ 
    return;
  }


  int *nw_arr = (int *) malloc(new_cap * sizeof(int));
  v->size = (new_cap < v->size)? new_cap: v->size;

  for (int i = 0; i < v->size; i++){
    nw_arr[i] = v->array[i];
  }

  free(v->array);
  v->array = nw_arr;
  v->capacity = new_cap;
}


int append_vector(vector *v, int item){
  if (!v)
    return -1;

  if (v->size == v->capacity){
    resize_vector(v, v->capacity * 2);
  }

  v->array[(v->size)++] = item;
  
  return v->size;
}

int pop_vector(vector *v, int index){
  if (!v || index >= v->size){
    return -1;
  }
  

  while (++index < v->size){
    v->array[index-1] = v->array[index];
  }

  v->size--;

  if (v->capacity/2 > v->size){
    resize_vector(v, v->capacity/2);
  }
  
  return v->size;
}

void free_vector(vector *v){
  if (v){
    free(v->array);
    free(v);
  }
}


void printd_vector(vector *v){
  printf("size:%2d, cap:%2d [", v->size, v->capacity);
  for (int i = 0; i < v->size; i++){
    printf((i+1 == v->size)?"%d":"%d, ", v->array[i]);
  }
  printf("]\n");
}


int main(){
  srand(time(NULL));

  vector *v = new_vector(1);
  
  if (v == NULL){
    printf("error (new_vector): null pointer returned\n");
    exit(1);
  }

  for (int i = 0; i < 6; i++){
    append_vector(v, rand()%50);
    printd_vector(v);
  }

  
  int size = v->size;
  for (int i = 0; i < size; i++){
    pop_vector(v, rand()%v->size);
    printd_vector(v);
  }
}





