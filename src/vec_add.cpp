// Created by SwiftWare Lab on 9/24.
// CE 4SP4 - High Performance Programming
// Copyright (c) 2024 SwiftWare Lab

#include "vec_add.h"

namespace swiftware::hpp {

  void vec_add(std::vector<float> a, std::vector<float> b, std::vector<float> &c) {
   int n = a.size();
   c.resize(n);
   for (int i = 0; i < n; ++i) {
    c[i] = a[i] + b[i];
   }


   // TODO: add another vector addition implementation


  }
 }