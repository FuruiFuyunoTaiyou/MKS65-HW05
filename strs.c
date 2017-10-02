#include <stdio.h>
#include <string.h>
#include "headers.h"

int mstrlen( char *s ) {
  int i = 0;
  while( s[i] ) {
    i++;
  }
  return i;
}

int main() {
  char *s0 = "";
  char *s1 = "aa";
  char *s2 = "aadjklsahflkjsdghlkadf";
  printf("ours:\t%d\t%d\t%d\n",mstrlen(s0),mstrlen(s1),mstrlen(s2));
  printf("sys:\t%d\t%d\t%d\n",strlen(s0),strlen(s1),strlen(s2));
  return 0;
}
