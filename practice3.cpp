#include <iostream>
#include <vector>

void vectorSolution() {
    int n;
    std::cout << "Size of first array:";
    std::cin >> n;
    std::vector<int> a;
    std::vector<int> b;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cout << "Element:";
        std::cin >> val;
        a.push_back(val);
    }
    int k;
    std::cout << "K:";
    std::cin >> k;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] < k) {
            b.push_back(a[i]);
        }
    }
    std::cout << "Result:";
    for (int i = 0; i < b.size(); ++i) {
        std::cout << b[i] << ' ';
    }
}

int main() {
    vectorSolution();
}
