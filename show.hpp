#include <bits/stdc++.h>
const std::string SHOW_MSG = "MSG|";
bool leftmost = true;
bool writeln = true;

template <typename... E>
void show(E... e);

template <typename... E>
void showAux(E... e) {
    (cout << ... << (cout << ' ', e));
}
template <typename T1, typename T2>
void showAux(std::pair<T1, T2> e) {
    cout << '(' << e.first << ',' << e.second << ')';
}

template <std::ranges::input_range R>
void showAux(R r) {
    for (auto it = begin(r); it != end(r); ++it) {
        cout << setw(3);
        writeln = false;
        show(*it);
        writeln = true;
    }
}
template <typename T>
concept Adaptor = requires(T t) {
    t.pop();
    t.top();
    t.empty();
};
template <Adaptor A>
void showAux(A a) {
    while (!a.empty()) {
        show(a.top());
        a.pop();
    }
}
template <typename T>
void showAux(std::queue<T> a) {
    while (!a.empty()) {
        show(a.front());
        a.pop();
    }
}

template <typename... E>
void show(E... e) {
    if (leftmost) {
        cout << SHOW_MSG;
        leftmost = false;
    }
    showAux(e...);
    if (writeln) {
        if (leftmost) cout << SHOW_MSG;
        cout << endl;
        leftmost = true;
    }
}
