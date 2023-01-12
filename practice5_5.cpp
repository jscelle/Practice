#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fill_vector(vector<int>& vec, const int count) {
    for (int i = 0; i < count; ++i) {
        int value;
        cin >> value;
        vec.push_back(value);
    }
}

void print_array(vector<int>& vec) {
    for (int value : vec) cout << value << ' ';
}

bool find_number(vector<int> vec, const int num) {
    int l = 0, h = vec.size() - 1;
    int mid;
    while (h - l > 1) {
        mid = (h - l) >> 1;
        if (vec[mid] == num) return true;
        vec[mid] > num ? h = mid - 1 : l = mid;
    }
    return vec[l] == num || vec[h] == num;
}

int main() {

    vector<int> vec;
    cout << "Enter elements count : ";
    int count; cin >> count;

    fill_vector(vec, count);
    sort(vec.begin(), vec.end());

    cout << "Enter elements to find : ";
    cin >> count;
    for (int i = 0; i < count; ++i) {
        int num; cin >> num;
        find_number(vec, num) ? cout << "present" : cout << "absent";
        cout << '\n';
    }
    return 0;
}

