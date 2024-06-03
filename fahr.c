#include <stdio.h>

float to_celsius(float fahr){
  return (5.0/9.0)*(fahr-32);
}


int main(){
  float fahr;
  
  for (fahr=300; fahr >= 0; fahr = fahr -20) {
    printf("%3.0f %6.1f\n", fahr, to_celsius(fahr));
  }
}
