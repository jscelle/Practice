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

std::string encryptString(std::string str, int c) {
	/*
		tmp_c - кол-во столбцов квадрата с учетом добавления
		новых символов в строку
		0123456  	     0123			   01
		abcdehu    => adubceh   =>   adube_ch
		tmp_c = 3	  tmp_c = 2		 tmp_c = 1
	*/
	int tmp_c = c;
	int shift = 0;
	int insert_shift;
	int j = 0;

	// Цикл по кол-ву колонок квадрата
	for(int i = 0; i < c; i++) {
		// Длина строки - длина добавленных символов
		j = (str.length() - 1) - shift;
		// Сдвиг для вставки букв (с учетом длины добавленных символов)
		insert_shift = shift;
		while(j >= 0) {
			if (j % tmp_c == 0) {
				// Буква с индексом j с учетом длины добавленных символов
				char letter = str[j + shift];
				// Добавить в конец
				str.insert(str.begin()+insert_shift, letter);
				// Сдвинуть индексы (длина добавленных символов)
				shift++;
				// Удалить букву с индексом j с учетом добавленных символов
				str.erase(j + shift, 1);
			}
			j--;
		}
		// Добавление пробелов, если длина строчки не равна числу колонок
		while(shift % (c-1) != 0) {
			str.insert(str.begin()+shift, ' ');
			shift++;
		}
		tmp_c--;
	}
	return str;
}


int main() {
    //izogramm();
       //bob();
    substring();
}
