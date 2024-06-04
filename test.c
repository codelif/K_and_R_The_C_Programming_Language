#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* longestCommonPrefix(char** strs, int strsSize) {
    char *prefix = malloc(200);
    int i, c;

    for (i = 0; (c = strs[0][i]) != '\0'; ++i){
        for (int j = 1; j < strsSize; ++j){
            if (strs[j][i] != c || strs[j][i] == '\0'){
                return prefix;
            }
        }
        strcat(prefix, (char[2]) { (char) c, '\0' });
    }
    return prefix;
}


int main(){
  char *strs[] = {"flower","flow","flight"};
  printf("%s\n", longestCommonPrefix(strs, 3));
}
