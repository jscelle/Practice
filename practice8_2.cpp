#include<iostream>
#include<sstream>
#include<map>

using namespace std;

string normalize_string(const string src) {
    string out;
    for (char c : src) {
        out += isalpha(c) || isdigit(c) ? tolower(c) : ' ';
    }
    return out;
}

int main() {
    map<string, int> m;
    string in; getline(cin, in);
    istringstream sstream(normalize_string(in));
    string word;
    while (sstream >> word) m[word]++;
    for (auto pair : m) {
        cout << pair.first << '-' << pair.second << '\n';
    }
    return 0;
}
// Lorem ipsum do sit amet, consectetur adipiscing elit, sit do eiusmod elit incididunt ut lorem do dolore elit elit.
