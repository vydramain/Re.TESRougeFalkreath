//
// Created by vydra on 9/3/20.
//

#pragma once

#include <string>

#include "adds/publisher/ISubject.hpp"

class IObserver {
 public:
  virtual ~IObserver() = default;

  virtual void subscribe(ISubject *input_subscriber) = 0;
  virtual void unsubscribe(ISubject *input_subscriber) = 0;
  virtual void notify() = 0;
};