#include <stdio.h>
#include <string.h>
#define STACKSIZE 20

long stack[STACKSIZE];
int stptr = 0; // points to next free stack index

long pop(){
  if (stptr > 0){
    return stack[--stptr];
  }else{
    printf("error: stack empty\n");
    return 0L;
  }
}

void push(long item){
  if (stptr >= STACKSIZE){
    printf("error: stack full\n");
  }else{
    stack[stptr++] = item;
  }
}

int isdigit(char c){
  return c >= '0' && c <= '9';
}

int atoi(char s[]){
  int sign, val;
  while (*s == ' '){
    s++;
  }

  sign = (*s == '-') ? -1: 1;
  for (val = 0; isdigit(*s); s++){
    val = val * 10 + (*s - '0');
  }

  return val * sign;
}

#define BUFSIZE 20
char buf[BUFSIZE];
int bufptr = 0;

int isinteger(char *s){
    return ((s[0] == '-' || s[0] == '+') && isdigit(s[1])) || isdigit(s[0]);
}


int main(int argc, char* argv[]){
  char *opt;
  int op2;
  while (--argc){
    opt = *(++argv);
    if (isinteger(opt)){
      push(atoi(opt));
    }else if (strlen(opt) == 1){
      switch (opt[0]){
        case '+':
          push(pop()+pop());
          break;
        case '-':
          op2 = pop();
          push(pop()-op2);
          break;
        case '/':
          op2 = pop();
          if (op2 == 0){
            printf("error: divison by zero\n");
          }else{
            push(pop()/op2);
          }
          break;
        case 'x':
        case '*':
          push(pop()*pop());
          break;
        default:
          goto invalid;
          break;
      }
    }else {
    invalid:
      printf("error: unknown operator\n");
    }
  }
  printf("%d\n", pop());
}

