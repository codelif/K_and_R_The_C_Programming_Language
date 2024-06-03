#include <stdio.h>

int contains(char s[], int c){
  for (int i = 0; s[i] != '\0'; i++)
    if (s[i] == c)
      return 1;
  return 0;
}

int any(char s1[], char s2[]){
  int i;
  for (i = 0; s1[i] != '\0'; i++)
    if (contains(s2, s1[i]))
      return i;
  return -1;
}


int main(){
  char s1[] = "This is harsh sharma!";
  char s2[] = "ar";

  printf("%d\n", any(s1, s2));
}
