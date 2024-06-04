#include <stdio.h>
#include <stdbool.h>


bool isPalindrome(int x) {
    int result = 0;
    int residue = x;

    do{
        result = result * 10 + (residue % 10);
    }while((residue/=10) != 0);

    return (result == x);
}


int main(){
  int x = 121;
  printf("%d\n", isPalindrome(x));
}
