#include <stdio.h>

int contains(char s[] , int c){
  for (int i = 0; s[i] != '\0'; i++)
    if (s[i] == c)
      return 1;
  return 0;
}


void squeeze(char s1[], char s2[]){
  int i , j;
  for (i = j = 0; s1[i] != '\0'; i++){
    if (!contains(s2, s1[i])){
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
}


int main(){
  char s1[] = "This is harsh sharma speaking!";
  char s2[] = "wow, such bullshit";

  squeeze(s1, s2);
  printf("%s\n", s1);
}



