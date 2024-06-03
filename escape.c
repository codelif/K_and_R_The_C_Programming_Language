#include <stdio.h>

int escape(char s[], char t[]){
  int i, j;
  for (i=j=0; t[i]!='\0'; ++i){
    switch (t[i]){
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
      default:
        s[j++] = t[i];
        break;
    }
  }
  s[j] = '\0';
  return j;
}

int main(){
  char s[1000];
  char t[] = "Hello, this is\nharsh sharma.\n\tA good guy.";

  escape(s, t);
  printf("%s\n%s\n", t, s);
}



