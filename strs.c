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

char * mstrncopy( char *d, char *s, int n ) {
  int i = 0;
  while( i < n && s[i] ) {
    d[i] = s[i];
    i++;
  }
  while( i < n ) {
    d[i] = 0;
    i++;
  }
  return d;
}

char * mstrncat( char *d, char *s, int n ) {
  int i = mstrlen(d);
  int j = 0;
  
  while( j < n && s[j] ) {
    d[i] = s[j];
    i++;
    j++;
  }
  d[i] = 0;
  return d;
}





int main() {
  //string length
  char *s0 = "";
  char *s1 = "aa";
  char *s2 = "aadjklsahflkjsdghlkadf";
  printf("ours:\t%d\t%d\t%d\n",mstrlen(s0),mstrlen(s1),mstrlen(s2));
  printf("sys:\t%d\t%d\t%d\n",strlen(s0),strlen(s1),strlen(s2));
 
  //string n copy
  char s3[] = "  11111111111111111111";
  char s4[] = "aadjklsahflkjsdghlkadf";
  printf("before:\t%s\t%s\n",s3,s4);
  printf("after:\t%s\t%s\n",mstrncopy(s3,s4,2),s4);

  //string n concatenation
  char s5[8] = "1234";
  char s6[] = "567890";
  printf("before:\t%s\n",s5);
  printf("after:\t%s\n",mstrncat(s5,s6,4)); 
  return 0;
}
