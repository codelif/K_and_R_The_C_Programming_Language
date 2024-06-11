#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1000

// int atoi(char *s){
//   int val, sign;
//   while (*s == ' '){
//     s++;
//   }
//   
//   sign = (*s == '-') ? -1:1;
//   if (*s == '-' || *s == '+'){
//     s++;
//   }
//
//   for (val = 0; *s >= '0' && *s <= '9'; s++)
//     val = 10 * val + (*s - '0');
//
//   return val * sign;
// }

int get_line(char *s, int max){
  int i, c;
  for (i = 0; i < max-1 && (c=getchar()) != EOF && c != '\n'; i++){
    s[i] = c;
  }
  if (c == '\n')
    s[i++] = '\n';

  s[i] = '\0';
  return i;
}


int main(int argc, char *argv[]){
  int n;
  if (argc == 3){
    if (argv[1][0] == '-' && argv[1][1] == 'n'){
      n = atoi(argv[2]);
      if (n < 0)
        n = 10;
    }else{
      goto invalid;
    }
  }else if (argc == 1){
    n = 10;
  }else {
  invalid:
    printf("usage: %s [options]\n", argv[0]);
    return 1;
  }
  
  // printf("%d", n);
  char *buffer[n];
  int bufptr = 0;
  char line[MAXLEN];
  int len;
  
  int count = 0;
  while ((len = get_line(line, MAXLEN)) > 0) {
    if (bufptr >= n){
      free(buffer[0]);
      for (int i = 0; i < n-1; ++i){
        buffer[i] = buffer[i+1];
      }
      bufptr--;
    }
    buffer[bufptr] = (char *) malloc((len+1) * sizeof(char));
    strcpy(buffer[bufptr++], line);
    count++;
  }
  
  count = (count < n) ? count : n;

  int i;
  for (i = 0; i < count; i++){
    printf("%s", buffer[i]);
    free(buffer[i]);
  }



}
