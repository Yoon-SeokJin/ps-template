// Require version : C++2a
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <ranges>
#include <vector>
using namespace std;
namespace rng = ranges;
namespace vw = views;

auto calc_time(function<void(void)> f, int repeat = 50) {
    chrono::duration<double, milli> dur;
    for (int i = 0; i < repeat; ++i) {
        auto start = chrono::high_resolution_clock::now();
        f();
        auto finish = chrono::high_resolution_clock::now();
        dur += finish - start;
    }
    return dur.count() / repeat;
}

template <typename T>
struct Plot {
    string label;
    vector<T> x;
    vector<double> y;
    function<void(T)> f;
    function<void()> init;
    Plot(string label, vector<T> x, function<void(T)> f) : label(label), x(x), f(f) {
        init = [] {
        };
    }
    Plot(string label, vector<T> x, function<void()> init, function<void(T)> f)
        : label(label), x(x), f(f), init(init) {}
    void calc(bool verbose = false, int log_interval = 10) {
        if (verbose) cout << label << ": calc start." << endl;
        for (int i = 0; i < ssize(x); ++i) {
            init();
            y.push_back(calc_time(bind(f, x[i])));
            if (verbose && i % log_interval == 0) {
                cout << "[" << i + 1 << " / " << ssize(x) << "] ";
                cout << "x: " << x[i] << "/ y: " << y[i] << endl;
            }
        }
        if (verbose) cout << label << ": calc complete." << endl;
    }
    void save(string pth) {
        ofstream file(pth.data(), ofstream::out | ofstream::app);
        if (file.is_open()) {
            file << "- label: \"" << label << "\"" << endl;
            file << "  x: [";
            rng::copy(x, ostream_iterator<T>(file, ", "));
            file << "]" << endl;
            file << "  y: [";
            rng::copy(y, ostream_iterator<double>(file, ", "));
            file << "]" << endl;
        }
    }
};

void file_clear(string pth) {
    ofstream file(pth.data(), ofstream::out | ofstream::trunc);
}

constexpr int M = 1e6, N = 123;
int arr2[M], num_arr2;
int* fetch2() {
    return &arr2[num_arr2++];
}
vector<int> arr3;
int* fetch3() {
    return &arr3.emplace_back();
}
list<int> arr4;
int* fetch4() {
    return &arr4.emplace_back();
}
deque<int> arr5;
int* fetch5() {
    return &arr5.emplace_back();
}

int* arr[M];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string trgt_pth = "data.yaml";
    vector<Plot<int>> plots;
    vector<int> x;
    for (double i = 4.0; i <= 6.0; i += 0.005)
        x.push_back(pow(10, i));
    auto init1 = [&] {
        memset(arr, 0, sizeof arr);
    };
    auto init2 = [&] {
        memset(arr, 0, sizeof arr);
        num_arr2 = 0;
    };
    auto init3 = [&] {
        memset(arr, 0, sizeof arr);
        arr3.clear();
    };
    auto init4 = [&] {
        memset(arr, 0, sizeof arr);
        arr4.clear();
    };
    auto init5 = [&] {
        memset(arr, 0, sizeof arr);
        arr5.clear();
    };
    plots.emplace_back("new/free", x, init1, [&](int n) {
        for (int i = 0; i < n; ++i)
            arr[i] = new int(N);
        for (int i = 0; i < n; ++i)
            delete arr[i];
    });
    plots.emplace_back("global array", x, init2, [&](int n) {
        for (int i = 0; i < n; ++i) {
            arr[i] = fetch2();
            *arr[i] = N;
        }
    });
    plots.emplace_back("node pool: vector", x, init3, [&](int n) {
        for (int i = 0; i < n; ++i) {
            arr[i] = fetch3();
            *arr[i] = N;
        }
    });
    plots.emplace_back("node pool: list", x, init4, [&](int n) {
        for (int i = 0; i < n; ++i) {
            arr[i] = fetch4();
            *arr[i] = N;
        }
    });
    plots.emplace_back("node pool: deque", x, init5, [&](int n) {
        for (int i = 0; i < n; ++i) {
            arr[i] = fetch5();
            *arr[i] = N;
        }
    });
    for (auto& e : plots)
        e.calc(true);
    file_clear(trgt_pth);
    for (auto& e : plots)
        e.save(trgt_pth);
    cout << "Done.";
    return 0;
}