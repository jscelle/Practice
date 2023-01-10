#include <iostream>
#include <string.h>
#include<string>
using namespace std;

void substring() {

    string s, subs;
    int n;
    bool fd = true;

    cout << "Enter a string, then number \n";
    cin >> s;
    cin >> n;
    cout << "\n";

    if (n > 0) {
        if (n <= s.length()) {
            fd = false;
        }
    }

    while (fd) {
        if (n < 0) {
            cout << "Wrong data, n < 0 \n";
        }
        else if (n == 0) {
            cout << "Wrong data, n equals 0 \n";
        }
        else {
            cout << "Wrong data, n > string size \n";
        }
        cout << "Enter a string, then number \n";
        cin >> s >> n;
        cout << "\n";

        if (n > 0) {
            if (n <= s.length()) {
                fd = false;
                break;
            }
        }

    }
    for (int i = 0; i <= s.length() - n; i++) {
        subs = s.substr(i, n);
        cout << subs << " ";
    }
}


void bob() {

    bool empty = true;
    bool dub = false;
    bool loud = true;
    char znak, rezerv;
    string s = "";
    cout << "Bob: Oh, hello. \n";


    while (true) {
        loud = true;
        empty = true;
        dub = false;
        getline(cin, s);
        if (s == "Bye, see you later.") {
            break;
        }

        znak = s[s.length() - 1];
        if (znak == '!') {
            rezerv = s[s.length() - 2];
            if (rezerv == '?') {
                znak = rezerv;
                dub = true;
            }
        }
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] != ' ') {
                empty = false;
            }
        }
        if (empty) {
            cout << "Bob: Fine. Be that way! \n";
            continue;
        }



        if (znak == '?') {
            for (int i = 0; i < s.length() - 2 - dub; i++) {
                if (isalpha(s[i]) and s[i] > 'Z') {
                    cout << "Bob: Sure. \n";
                    loud = false;
                    break;
                }
            }
            if (loud) cout << "Bob: Calm down, I know what I'm doing! \n";
        }
        else if ((znak == '.') or (znak = '!')) {
            for (int i = 0; i < s.length() - 2; i++) {
                if (isalpha(s[i]) and s[i] > 'Z') {
                    cout << "Bob: Whatever. \n";
                    loud = false;
                    break;
                }
            }
            if (loud) cout << "Bob: Whoa, chill out! \n";
        }
    }

    cout << "Bob: Fine, good luck!";
}


void izogramm() {

    string str;
    cout << "Enter your string: " << endl;
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i]) == 0)
            continue;
        for (int j = i + 1; j < str.length(); j++) {
            if (toupper(str[i]) == toupper(str[j])) {
                cout << "False";
                exit(0);
            }
        }
    }
    cout << "True";
}


int main() {
    //izogramm();
       //bob();
    substring();
}
