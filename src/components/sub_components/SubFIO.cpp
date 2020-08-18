//
// Created by vydra on 8/18/20.
//

#include "components/sub_components/SubFIO.hpp"

SubFIO::SubFIO(const char* input_fio) {
  if(strlen(input_fio) > 24){
    return;
  }
  fio = input_fio;
}

SubFIO::~SubFIO() = default;

const char *SubFIO::get_fio() const {
  return fio;
}
void SubFIO::set_fio(const char *input_fio) {
  if(strlen(input_fio) > 24){
    return;
  }
  fio = input_fio;
}
