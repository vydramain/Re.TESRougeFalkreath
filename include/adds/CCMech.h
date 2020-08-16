//
// Created by vydra on 8/10/20.
//

#pragma once

class CCMech {
 public:
  static int strpos(const char *s, const char *c, int n = 0) {
    int i, j;
    int lenC, lenS;

    for (lenC = 0; c[lenC]; lenC++) {}
    for (lenS = 0; s[lenS]; lenS++) {}

    for (i = 0; i <= lenS - lenC; i++) {
      for (j = 0; s[i + j] == c[j]; j++) {}
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
};
