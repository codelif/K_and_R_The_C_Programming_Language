#include <stdio.h>

unsigned long strlen(const char s[]){
  unsigned long i;
  for (i=0; s[i] != '\0'; ++i);
  return i;
}

void reverse(char line[]){
  char i, j, c;
  for (i = 0, j = strlen(line)-1; i < j; ++i, --j){
    c = line[j];
    line[j] = line[i];
    line[i] = c;
  }
}



int main(){
  char s[] = "This is harsh sharma.";
  printf("%s\n", s);
  reverse(s);
  printf("%s\n", s);


}
