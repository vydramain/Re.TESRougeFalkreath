//
// Created by vydra on 8/24/20.
//

#include "adds/CCMech.h"

#include <cstring>
#include <string>
#include <vector>

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

std::vector<std::string *> CCMech::split(std::string *input_text) {
  unsigned input_size = input_text->size();
  unsigned counter = 0;
  std::vector<std::string *> return_strings;
  return_strings.push_back(new std::string());
  for (unsigned i = 0; i < input_size; i++) {
    if ((*input_text)[i] == ' ') {
      return_strings.push_back(new std::string());
      counter++;
    }
    return_strings[counter]->append(sizeof(char), (*input_text)[i]);
  }
  return return_strings;
}

int CCMech::char_to_int(char c) {
  return c - '0';
}
