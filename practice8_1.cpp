#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    
    int n;
    std::cin >> n;

    map<string,string> m; 

    for(int i = 0;i < n;++i){
        string key;cin >> key;
        cin >> m[key];
    }

    string s;
    while(cin >> s){
        auto value = m.find(s);
        if(value == m.end())
            cout << "Not found\n";
        else
            cout << value->second << endl;
    }
    return 0;
}
