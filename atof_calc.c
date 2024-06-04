#include <stdio.h>
#define MAXBUFFER 100

int is_digit(char c){
  return (c >= '0' && c <= '9');
}

int is_space(char c){
  return (c == ' ');
}

int atoi_ex(char s[], int i){
  int val;
  int sign;

  for (; is_space(s[i]); ++i);
  sign = (s[i] == '-')? -1: 1;
  if (s[i] == '+'|| s[i] == '-')
    ++i;

  for (val = 0; is_digit(s[i]); ++i)
    val = val * 10 + (s[i] - '0');

  return sign * val;
}

int power(int base, int p){
  int val;
  for (val = 1; p > 0; --p)
    val *= base;
  return val;
}

double atof(char s[]){
  double val, pow;
  int i, sign;

  for (i = 0; is_space(s[i]); ++i);

  sign = (s[i] == '-')? -1: 1;
  if (s[i] == '+' || s[i] == '-')
    ++i;
  
  for (val = 0.0; is_digit(s[i]); ++i){
    val = val * 10.0 + (s[i] - '0');
  }

  if (s[i] == '.')
    ++i;

  for (pow = 1.0; is_digit(s[i]); ++i){
    val = val * 10.0 + (s[i] - '0');
    pow *= 10.0;
  }
  
  if (s[i] == 'e' || s[i] == 'E'){
    int p = atoi_ex(s, ++i);
    if (p >= 0){
      pow /= power(10, p);
    }else{
      pow *= power(10, -p);
    }
  }

  return sign * val / pow;
}


int get_line(char s[], int max){
  int i, c;
  for (i = 0; --max > 0 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (s[i] == '\n')
    s[i++] = '\n';
  s[i] = '\0';
  return i;
}

int main(){
  char line[MAXBUFFER];
  double sum;
  sum = 0.0;
  while (get_line(line, MAXBUFFER) > 0){
    sum += atof(line);
    printf("Current Sum: %f\n", sum);
  }
}



