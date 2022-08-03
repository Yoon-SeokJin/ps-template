template <typename E>
void show(E e) {
    cout << ' ' << e;
}
template <typename T1, typename T2>
void show(pair<T1, T2> e) {
    cout << e.first << ' ' << e.second << endl;
}
template <ranges::input_range R>
void show(R r) {
    for (auto it = begin(r); it != end(r); ++it) {
        cout << setw(3);
        show(*it);
    }
    cout << endl;
}
template <typename T>
concept Adaptor = requires(T t) {
    t.pop();
    t.top();
    t.empty();
};
template <Adaptor A>
void show(A a) {
    while (!a.empty()) {
        show(a.top());
        a.pop();
    }
    cout << endl;
}
template <typename T>
void show(queue<T> a) {
    while (!a.empty()) {
        show(a.front());
        a.pop();
    }
    cout << endl;
}