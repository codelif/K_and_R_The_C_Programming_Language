#include <stdio.h>
#include <limits.h>


int myAtoi(char* s) {
    long val;
    int sign, i;
    for (i = 0; s[i] == ' '; ++i);

    sign = (s[i] == '-') ? -1: 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    
    for (val = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        val = val * 10 + (s[i] - '0');
        if (val > INT_MAX && sign == -1){
            return INT_MIN;
        }else if (val > INT_MAX && sign == 1){
            return INT_MAX;
        }
 
    return sign *val;
}

int main(){
  char c[] = "20000000000000000000";
  printf("%d\n", myAtoi(c));
}

