#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define STACKSIZE 100
#define OPBUFFER 100
#define GETCHBUFFER 10
#define REGSIZE 27

enum operators { NUMBER = '0', ADDITION = '+', SUBTRACTION = '-', MULTIPLICATION = '*', DIVISON = '/', MODULUS = '%', IGNORE = '\n', COMMAND = 'c', ACCESS = '$', ASSIGN = '&'};

double vregister[REGSIZE]; 

char bfr[GETCHBUFFER];
int bfrp = -1;
int getch(){
  if (bfrp < 0)
    return getchar();

  return bfr[bfrp--];
}

void ungetch(char c){
  if (bfrp + 2 > GETCHBUFFER){
    printf("ungetch: getch buffer is full");
  }else{
    bfr[++bfrp] = c;
  }
}

void ungets(char s[]){
  for (int i = strlen(s)-1; i >= 0; --i)
    ungetch(s[i]);
}


double stack[STACKSIZE];
int sp = -1;

double pop(){
  extern double stack[];
  extern int sp;

  if (sp < 0){
    printf("error: stack is empty\n");
    return 0.0;
  }

  return stack[sp--];
}

void push(double item){
  extern double stack[];
  extern int sp;

  if (sp + 2 > STACKSIZE){
    printf("error: stack is full\n");
    return;
  }

  stack[++sp] = item;
}

double read(){
  extern double stack[];
  extern int sp;

  if (sp < 0){
    printf("error: stack is empty\n");
    return 0.0;
  }

  return stack[sp];
}

void swap(){
  double p2 = pop();
  double p1 = pop();
  push(p2);
  push(p1);
}

void dup(){
  push(read());
}

char getop(char s[]){
  int i, c;
  i = 0;
  while ((s[i] = c = getch()) == ' ' || c == '\t');
  if (isalpha(c)){
    while (isalpha(c = getch())){
      s[++i] = c;
    }
    s[++i] = '\0';
    ungetch(c);
    return COMMAND;
  }

  if (c == ASSIGN || c == ACCESS){
    char pass = c;
    while ((c = getch()) != ' ' && isalpha(c)){
      s[i++] = c;
    }
    s[i] = '\0';
    ungetch(c);
    return pass;
  }

  if (!isdigit(c) && c != '.' && c != '_')
    return c;

  if (c == '_')
    s[0] = '-';
    s[++i] = c = getch();

  if (isdigit(c))
    while(isdigit(s[++i] = c = getch()));

  if (c == '.')
    while (isdigit(s[++i] = c = getch()));
  
  s[i] = '\0';
  ungetch(c);
  return NUMBER;
}

double atof(char s[]){
  double val, power;
  int i, sign;
  
  for (i = 0; s[i] == ' '; ++i);

  sign = (s[i] == '-')? -1: 1;
  if (s[i] == '+' || s[i] == '-')
    ++i;

  for (val = 0.0; isdigit(s[i]); ++i)
    val = val * 10.0 + (s[i] - '0');

  if (s[i] == '.')
    ++i;

  for (power = 1.0; isdigit(s[i]); ++i){
    val = val * 10.0 + (s[i] - '0');
    power *= 10;
  }

  return sign * val / power;

}

void command(const char s[]){
  extern int sp;
  extern double vregister[REGSIZE];

  if (!strcmp(s, "p")){
    double v = read();
    if (sp >= 0)
      printf("%f\n", v);
      vregister[0] = v;
  }else if (!strcmp(s, "d")){
    dup();
  }else if (!strcmp(s, "c")){
    sp = -1;
  }else if (!strcmp(s, "s")){
    swap();
  }else if (!strcmp(s, "q")){
    ungetch(-1);
  }else if (!strcmp(s, "sin")){
    push(sin(pop()));
  }
  else if (!strcmp(s, "exp")){
    push(exp(pop()));
  }
  else if (!strcmp(s, "pow")){
    double p = pop();
    push(pow(pop(), p));
  }
  else{
    printf("error: unrecognised command");
  }
}


int main(){
  extern double vregister[REGSIZE];
  char s[OPBUFFER];
  char type;
  double op2;

  for (int i = 0; i < REGSIZE; ++i)
    vregister[i] = 0.0;
  
  while ((type = getop(s)) != EOF){
    switch (type){
      case NUMBER:
        push(atof(s));
        break;
      case ADDITION:
        push(pop()+pop());
        break;
      case SUBTRACTION:
        op2 = pop();
        push(pop()-op2);
        break;
      case MULTIPLICATION:
        push(pop()*pop());
        break;
      case DIVISON:
        op2 = pop();
        if (op2 == 0.0){
          printf("error: division by zero\n");
        }else{
          push(pop()/op2);
        }
        break;
      case MODULUS:
        op2 = pop();
        if (op2 == 0.0){
          printf("error: modulo by zero\n");
        }else{
          push(fmod(pop(), op2));
        }
        break;
      case ASSIGN:
        vregister[s[0] - '0' + 1] = read();
        break;
      case ACCESS:
        if (s[0] == '\0')
          push(vregister[0]);
        else
          push(vregister[s[0] - '0' + 1]);
        break;
      case COMMAND:
        command(s);
        break;
      case IGNORE:
        break;
      default:
        printf("error: unrecognised operand.\n");
        break;
    }
  }
  return 0;
}

