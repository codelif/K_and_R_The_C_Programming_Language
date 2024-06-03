#include <stdio.h>

int search(int arr[], int n, int x){
  int lo, hi, in;
  lo = 0;
  hi = n-1;
  
  while (lo <= hi){
    in = (lo+hi)/2;
    if (arr[in] == x){
      return in;
    }else if (arr[in] > x){
      hi = in - 1;
    }else{
      lo = in + 1;
    }
  }

  return -1;

}


int main(){
  int a[] = {1, 4, 6, 7, 8, 10, 30};
  int n = 7;

  int x = 4;

  printf("%d\n", search(a, n, x));
}
