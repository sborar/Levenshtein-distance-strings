/*  Auto-built C++ source file 'edit-distance.cpp'.  */
/******************************************************************************
  Aalto University
  CS-E3190 Principles of Algorithmic Techniques
  Autumn 2020
  Exercise: Edit distance
  Description:
  This exercise asks you to implement an algorithm that computes the edit
  distance (Levenshtein distance) between two given strings. More precisely,
  for two strings $a$ and $b$, the *Levenshtein distance* $D(a,b)$ is the
  minimum length of a sequence of edit operations that transforms the string
  $a$ into the string $b$, where each edit operation in the sequence is one of
  the following:
      1. deletion of one character from the string,
      2. insertion of one character into the string, or
      3. changing of one character in the string into another character.
  For example, the Levenshtein distance satisfies $D(a,a)=0$ for all strings
  $a$, since a sequence of zero edit operations suffices to transform $a$
  into $a$. Similarly, one can show that $D(a,b)=D(b,a)$ and
  $D(a,c)\leq D(a,b)+D(b,c)$ for all strings $a,b,c$. That is, $D$ is a metric
  in the space of all strings.
  **Your task** in this exercise is to complete the subroutine
  ``void solver(int n, int m, const char *a, const char *b, int &d)`` ,
  which takes as input a string `a` of length `n` and a string `b` of
  length `m`. The subroutine should compute the Levenshtein distance $D(a,b)$
  and store it into `d`. To locate the subroutine quickly, you can search for
  "`???`" in the source file. You may assume that $n,m\geq 0$ and
  $nm\leq 4294967296$. Furthermore, you may assume that $a[n]=b[m]=0$.
  *Grading*. This exercise awards you up to 100 points in
  the course grading. The number of points awarded is the maximum points times
  the number of tests passed over the total number of tests, rounded up. To
  successfully complete a test, your implementation must use no more than
  15 seconds of wall clock time and 10 MiB of memory. Each test
  will in general require the successful solution of one or more problem
  instances. In each batch of scaling tests, the first failed test will
  cause all subsequent tests in the batch to be skipped.
******************************************************************************/
#include <iostream>
#include <new>
#include <algorithm>
#include <cstring>

int helper(int n, int m, const char *a, const char *b, int** d_array ){
    if(n==0){
        d_array[n][m] = m;
        return m;
    }
    else if(m==0){
        d_array[n][m] = n;
        return n;
    }
    char *a_copy = new char[n];
    std::strcpy (a_copy,a);
    char *b_copy = new char[m];
    std::strcpy (b_copy,b);
    char last_char_a = a[n-1];
    char last_char_b = b[m-1];
    a_copy[n-1] = '\0';
    b_copy[m-1] = '\0';
    int d_remove_both_last = (d_array[n-1][m-1]!=-1) ? d_array[n-1][m-1] : helper(n-1,m-1,a_copy,b_copy, d_array);
    if(last_char_a==last_char_b){
        d_array[n][m] = d_remove_both_last;
        return d_remove_both_last;
    }
    else{
        b_copy[m-1] = last_char_b;
        int d_remove_a_last = (d_array[n-1][m]!=-1) ? d_array[n-1][m] : helper(n-1,m,a_copy,b_copy, d_array);
//            d_array[n-1][m] if(d_array[n-1][m]!=-1) else helper(n-1,m,a_copy,b_copy, d_array);
        a_copy[n-1] = last_char_a;
        b_copy[m-1] = '\0';
        int d_remove_b_last = (d_array[n][m-1]!=-1) ? d_array[n][m-1] : helper(n,m-1,a_copy,b_copy, d_array);
        int minimum(std::min({d_remove_a_last, d_remove_b_last, d_remove_both_last}));
        d_array[n][m] = minimum+1;
        return minimum+1;
    }
}
void solver(int n, int m, const char *a, const char *b, int &d)
{
    int** d_array = new int*[n+1];
    for(int i = 0; i < n+1; ++i) {
        d_array[i] = new int[m + 1];
        for(int j=0;j<m+1;j++){
            d_array[i][j] = -1;
        }
    }
    d = helper(n,m,a,b, d_array);
}

int main()
{
    int n = 3;
    int m = 3;
    const char a[] = "abd";
    const char b[] = "abc";
    int d = 0;
    solver(n, m, a, b, d);
    std::cout<<d;
    return 0;
}