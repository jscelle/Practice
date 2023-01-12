#include <iostream>
#include <string>
#include <list>
#include <cmath>

int hash(std::string s) {
    int result = 1;
    for (size_t i = 0; i < s.length(); ++i) {
        result *= (s[i] + 101);
    }
    return result;
}

void findAnagram(std::string word, std::list<std::string> list) {
    std::list<std::string> buff;
    int r_hash = hash(word);
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (r_hash == hash(*it)) {
            buff.push_back(*it);
        }
    }
    for (auto it = buff.begin(); it != buff.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main() {
    std::list<std::string> list;
    list.push_back("enlists");
    list.push_back("google");
    list.push_back("inlets");
    list.push_back("banana");

    findAnagram("listen", list);
}
