#include<iostream>
#include<sstream>
#include<map>

using namespace std;

string normalize_string(const string src){
    string out;
    for(char c : src){
        out += isalpha(c) || isdigit(c) ? c : ' ';
    }
    return out;
}

string string_to_lower(const string src){
    string out;
    for(char c : src) out += tolower(c);
    return out;
}

struct comparator{
    bool operator()(const string& a,const string& b) const{
        return string_to_lower(a) < string_to_lower(b);
    }
};

int main(){
    map<string,int,comparator> m;
    string in; getline(cin,in);
    istringstream sstream(normalize_string(in));
    string word;
    while(sstream >> word) m[word]++;
    for(auto pair : m){
        cout << pair.first << '-' << pair.second << '\n';
    }
    return 0;
}
