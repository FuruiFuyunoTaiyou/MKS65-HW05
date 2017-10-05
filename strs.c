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

int mstrcmp(char *s1, char *s2) {
  int i;
  //compare s1[i] to s2[i]
  //s1[i] - s2[i] if s1i > s2i
  //s2i-s1i if s2i > s1i
  //otherwise 0
  //minimum mstrlen s1s2
  for(i = 0; i < mstrlen(s1) + 1 && i < mstrlen(s2) + 1; i++) {
    if( s1[i] - s2[i] ) {
      return s1[i] - s2[i];
    }
  }
  return 0;
}

char * mstrchr(char *s, char c) {
  int i;
  for(i = 0; i < mstrlen(s); i++) {
    //if(mstrcmp(s,c))
    if(!(s[i] - c)) {
      return &s[i];
    }
  }
  return NULL;
}

//char * mstrstr() {}


int main() {
  //string length
  char *s0 = "";
  char *s1 = "aa";
  char *s2 = "aadjklsahflkjsdghlkadf";
  printf("ours:\t%d\t%d\t%d\n",mstrlen(s0),mstrlen(s1),mstrlen(s2));
  printf("sys:\t%ld\t%ld\t%ld\n",strlen(s0),strlen(s1),strlen(s2));
 
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

  //string comparison
  char s7[] = "hello";
  char s8[] = "goodbye";

  char s9[] = "pine";
  char s10[] = "pineapple";

  char t0[] = "hello";
  char t1[] = "hello";


  printf( "compare hello, goodbye\nours:\t%d\nactual:\t%d\n" , mstrcmp(s7,s8), strcmp(s7,s8));
  printf( "compare pine, pineapple\nours:\t%d\nactual:\t%d\n" , mstrcmp(s9,s10), strcmp(s9,s10));
  printf( "compare hello, hello\nours:\t%d\nactual:\t%d\n" , mstrcmp(t0,t1), strcmp(t0,t1));

  //find char in string
  char t2[] = "aaaaaaaaaab";
  char a = "a";
  char b = "b";
  char c = "c";
  printf("find a in aaaaaaaaaab:\nours:\t%p\nactual:\t%p\n",mstrchr(t2,a),strchr(t2,a));
  printf("find b:\nours:\t%p\nactual:\t%p\n",mstrchr(t2,b),strchr(t2,b));
  printf("find c:\nours:\t%p\nactual:\t%p\n",mstrchr(t2,c),strchr(t2,c));


  return 0;
}
