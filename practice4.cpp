#include <iostream>
#include <list>
#include <iterator>

void solution() {
    int n;
    std::cout << "Size:";
    std::cin >> n;
    std::list<int> a;
    for (int i = 0; i < n; ++i) {
        int v;
        std::cout << "Element:";
        std::cin >> v;
        a.insert(a.cbegin(), v);
    }
    std::cout << "Result:";
    for (int val : a) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
    std::cout << "Result:";
    copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "Result:";
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        std::cout << *it << ' ';
    }

}

int main() {
    solution();
}
