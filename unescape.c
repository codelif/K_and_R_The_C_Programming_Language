#include <stdio.h>


int unescape(char s[], char t[]){
  int i, j;

  for (i = j = 0; t[i] != '\0'; ++i){
      if (t[i] == '\\'){
          switch(t[++i]){
            case 'n':
              s[j++] = '\n';
              break;
            case 't':
              s[j++] = '\t';
              break;
            default:
              s[j++] = '\\';
              s[j++] = t[i];
              break;
          }
  }else {
      s[j++] = t[i];
  }
}

  s[j] = '\0';
  return j;
}


int main(){

  char s[1000];
  char t[] = "Hello, this is\\nharsh sharma.\\n\\tA good guy.";

  unescape(s, t);
  printf("%s\n%s\n", t, s);
}
