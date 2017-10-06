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

char * mstrncpy( char *d, char *s, int n ) {
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
  /*
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
  //printf("after:\t%s\t%s\n",mstrncpy(s3,s4,2),s4);
  
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
  char a = 'a';
  char b = 'b';
  char c = 'c';
  printf("find a in aaaaaaaaaab:\nours:\t%p\nactual:\t%p\n",mstrchr(t2,a),strchr(t2,a));
  printf("find b:\nours:\t%p\nactual:\t%p\n",mstrchr(t2,b),strchr(t2,b));
  printf("find c:\nours:\t%p\nactual:\t%p\n",mstrchr(t2,c),strchr(t2,c));
  */


  
  //string length----------------------------------------------------------------------

  printf("\nSTRLEN-----------------------------------------------");

  char *s0 = "";
  char *s1 = "aa";
  char *s2 = "aadjklsahflkjsdghlkadf";
  printf("\ns0: \"%s\"\ns1: \"%s\"\ns2: \"%s\"\n\n", s0, s1, s2);

  printf("Testing strlen(s0): \n\t[standard]: \t%ld \n\t[ours]: \t%d\n", strlen(s0), mstrlen(s0));
  printf("Testing strlen(s1): \n\t[standard]: \t%ld \n\t[ours]: \t%d\n", strlen(s1), mstrlen(s1));
  printf("Testing strlen(s2): \n\t[standard]: \t%ld \n\t[ours]: \t%d\n", strlen(s2), mstrlen(s2));

  //string n copy----------------------------------------------------------------------
  
  printf("\nSTRNCPY----------------------------------------------");

  char s3[] = "  11111111111111111111";
  char s4[] = "aadjklsahflkjsdghlkadf";
  printf("\ns3: \"%s\"\ns4: \"%s\"\n\n", s3, s4);

  printf("Testing strncpy(s3, s4, 2): \n\t[standard]: \t\"%s\" \n", strncpy(s3, s4, 2));
  strcpy(s3, "  11111111111111111111");
  printf("\t[ours]: \t\"%s\"\n", mstrncpy(s3, s4, 2));
  
  //string n concatenation-------------------------------------------------------------

  printf("\nSTRNCAT----------------------------------------------");

  char s5[8] = "1234";
  char s6[] = "567890";
  printf("\ns5: \"%s\"\ns6: \"%s\"\n\n", s5, s6);

  printf("Testing strncat(s5, s6, 4): \n\t[standard]: \t\"%s\" \n", strncat(s5, s6, 4));
  strcpy(s5, "1234");
  printf("\t[ours]: \t\"%s\"\n", mstrncat(s5, s6, 4));

  //string comparison------------------------------------------------------------------

  printf("\nSTRCMP-----------------------------------------------");

  char s7[] = "hello";
  char s8[] = "goodbye";
  char s9[] = "pine";
  char s10[] = "pineapple";
  char t0[] = "hello";
  printf("\ns7: \"%s\"\ns8: \"%s\"\ns9: \"%s\"\ns10: \"%s\"\nt0: \"%s\"\n\n", s7, s8, s9, s10, t0);

  printf("Testing strcmp(s7, s8): \n\t[standard]: \t%d \n\t[ours]: \t%d\n", strcmp(s7, s8), mstrcmp(s7, s8));
  printf("Testing strcmp(s9, s10): \n\t[standard]: \t%d \n\t[ours]: \t%d\n", strcmp(s9, s10), mstrcmp(s9, s10));
  printf("Testing strcmp(s7, s8): \n\t[standard]: \t%d \n\t[ours]: \t%d\n", strcmp(s7, t0), mstrcmp(s7, t0));

  //find char in string----------------------------------------------------------------

  printf("\nSTRCHR-----------------------------------------------");

  char t1[] = "aaaaaaaaaab";
  char a = 'a';
  char b = 'b';
  char c = 'c';
  printf("\nt1: \"%s\"\na: '%c'\nb: '%c'\nc: '%c'\n\n", t1, a, b, c);

  printf("Testing strchr(t1, a): \n\t[standard]: \t%p \n\t[ours]: \t%p\n", strchr(t1, a), mstrchr(t1, a));
  printf("Testing strchr(t1, b): \n\t[standard]: \t%p \n\t[ours]: \t%p\n", strchr(t1, b), mstrchr(t1, b));
  printf("Testing strchr(t1, c): \n\t[standard]: \t%p \n\t[ours]: \t%p\n", strchr(t1, c), mstrchr(t1, c));

  return 0;
}
