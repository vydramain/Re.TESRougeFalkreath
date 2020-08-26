//
// Created by vydra on 8/24/20.
//

#include "adds/CCMech.h"

int CCMech::strpos(const char *s, const char *c, int n) {
  int i, j;
  int lenC, lenS;

  for (lenC = 0; c[lenC]; lenC++) {
  }
  for (lenS = 0; s[lenS]; lenS++) {
  }

  for (i = 0; i <= lenS - lenC; i++) {
    for (j = 0; s[i + j] == c[j]; j++) {
    }
    if (j - lenC == 1 && i == lenS - lenC && !(n - 1)) {
      return i;
    }
    if (j == lenC) {
      if (n - 1) {
        n--;
      } else {
        return i;
      }
    }
  }
  return -1;
}
