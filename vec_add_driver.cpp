// Created by SwiftWare Lab on 9/24.
// CE 4SP4 - High Performance Programming
// Copyright (c) 2024 SwiftWare Lab


#include <iostream>
#include <vector>
#include <benchmark/benchmark.h>
#include "vec_add.h"



static void BM_VECADD(benchmark::State &state) {
 auto m = state.range(0);
 std::vector<float> a(m, 1.0);
 std::vector<float> b(m, 2.0);

 for(auto _ : state) {
   std::vector<float> c;
   swiftware::hpp::vec_add(a, b, c);
 }
}

BENCHMARK(BM_VECADD)->Arg(8)->Arg(64)->Arg(512)->Arg(1024);

BENCHMARK_MAIN();
