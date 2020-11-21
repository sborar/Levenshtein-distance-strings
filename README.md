# Levenshtein-distance-strings
Dynamic programming recursive implementation of Levenshtein edit distance between two strings.

Problem Description:

  This exercise asks you to implement an algorithm that computes the edit distance (Levenshtein distance) between two given strings. More precisely, for two strings a and b, the Levenshtein distance D(a,b) is the minimum length of a sequence of edit operations that transforms the string a into the string b, where each edit operation in the sequence is one of the following:
  
      1. deletion of one character from the string,
      2. insertion of one character into the string, or
      3. changing of one character in the string into another character.
      
  For example, the Levenshtein distance satisfies D(a,a)=0 for all strings a, since a sequence of zero edit operations suffices to transform a into a. Similarly, one can show that D(a,b)=D(b,a) and D(a,c)\leq D(a,b)+D(b,c) for all strings a,b,c. That is, D is a metric in the space of all strings.
  
Algorithm:

Check last character of each string, if it is the same the edit distance is same if those two characters were not there, so we do a recursive call after removing the last two characters. Else, the edit distance is the minimum value between D(a(without last character),b),D(a,b(without last character)) and D(a(without last character),b(without last character)).So we recursive call the solver function with smaller strings until we reach the base case to get the edit distance. The edit distance is stored for memoization.

Instructions:

Change the strings a,b in main.cpp and run main.cpp.
  
