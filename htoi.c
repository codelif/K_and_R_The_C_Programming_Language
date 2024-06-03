#include <stdio.h>

int hex_char_value(int c){
  int value = 0;
  if (c >= '0' && c <= '9'){
    value = c - '0';
  }else if (c >= 'a' && c <= 'f'){
    value = c - 'a' + 10;
  }else if (c >= 'A' && c <= 'F'){
    value = c - 'A' + 10;
  }
  return value;
}

int is_hex_char(int c){
  return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

int htoi(char s[]){
  int i, v;
  i = 0;
  if (s[1] == 'x' || s[1] == 'X'){
    i = 2;
  }

  for (v = 0; is_hex_char(s[i]); ++i){
    v = 16*v + hex_char_value(s[i]);
  }
  return v;
}


int main(){
  printf("%d\n",htoi("0x152abdF"));
}
