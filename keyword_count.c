// wow
#include <stdio.h>
#include "getch.h"
#define NKEYS 32
//wow

struct key {
  char *word;
  int count;
} keytab[NKEYS] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

int mstrcmp(char *s, char *t){
  for (;*s == *t; s++, t++){
    if (*s == '\0')
      return 0;
  }
  return *s - *t;
}

int get_keyword(char *word){
  extern struct key keytab[];
  int cond;
  int lo, hi, mid;
  
  lo = 0;
  hi = NKEYS-1;
  
  while (lo <= hi){
    mid = (lo + hi)/2;
    if ((cond = mstrcmp(word, keytab[mid].word)) > 0){
      lo = mid + 1;
    }else if (cond < 0){
      hi = mid - 1;
    }else {
      return mid;
    }
  }
  return -1;
}



int isdigit(char c){
  return (c >= '0' && c <= '9');
}

int isalpha(char c){
  return (c >= 'a' && c <= 'z') ||
         (c >= 'A' && c <= 'Z');
}

int isvalidvar(char c){
  return (isdigit(c) || isalpha(c) || c == '_');
}

int isspace(char c){
  return (c == ' ');
}

int getword(char *word, int lim){
  char c;
  char *w = word;
  

  while (isspace(c = getch()));
  
  if (c != EOF)
    *w++ = c;

  if (!isalpha(c)){
    *w = '\0';
    return c;
  }
  
  for (; --lim > 0; w++){
    if (!isvalidvar(*w = getch())){
      ungetch(*w);
      break;
    }
  }
  
  *w = '\0';
  return *word;
}


int main(){
  char s[100];
  char c;
  int index;

  int inside_string = 0, escape = 0, comment = 0, preprocessor = 0;


  while ((c = getword(s, 100)) >= 0){
    if (c == '\"' && !escape){
      inside_string = !inside_string;
    }
    escape = 0;

    if (c == '\\')
      escape = 1;
    
    if (inside_string){
      continue;
    }
    
    if (c == '\n'){
      comment = 0;
      preprocessor = 0;
    }

    if (comment >= 2){
      continue;
    }

    if (c == '/'){
      comment++;
    }
    else{
      comment = 0;
    }

    if (c == '#'){
      preprocessor = 1;
    }

    if (preprocessor){
      continue;
    }


    if ((index = get_keyword(s)) >= 0){
      keytab[index].count++;
    }
  }

  for (int i = 0; i < NKEYS; i++){
    if (keytab[i].count > 0){
      printf("%s\t\t%d\n", keytab[i].word, keytab[i].count);
    }
  }
}
