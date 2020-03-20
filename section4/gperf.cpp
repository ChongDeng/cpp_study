// Copyright (c) 2020 by Chrono
//
// g++ gperf.cpp -std=c++14 -lprofiler -ltcmalloc -g -O0 -o a.out;./a.out

#include <cassert>

#include <iostream>
#include <memory>
#include <string>
#include <regex>

#include <gperftools/profiler.h>
#include <gperftools/heap-profiler.h>

using namespace std;

auto make_cpu_profiler =
[](const string& filename)
{
    ProfilerStart(filename.c_str());
    ProfilerRegisterThread();

    return std::shared_ptr<void>(
        nullptr,
        [](void*){
            ProfilerStop();
        }
    );
};

static
auto make_regex = [](const auto& txt)
{
    return std::regex(txt);
};

static
auto make_match = []()
{
    return std::smatch();
};

void case1()
{
    auto cp = make_cpu_profiler("case1.perf");

    auto str = "neir:automata"s;

#if 1
    auto reg  = make_regex(R"(^(\w+)\:(\w+)$)");
    auto what = make_match();
#endif

    for(int i = 0; i < 1000; i++) {

#if 0
        auto reg  = make_regex(R"(^(\w+)\:(\w+)$)");
        auto what = make_match();
#endif

        assert(regex_match(str, what, reg));
    }
}


int main()
{
    case1();

    cout << "gperf demo" << endl;
}
