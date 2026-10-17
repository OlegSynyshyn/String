// ConsoleApplication49.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class String {
private:
    char* str;
    int size;
    static int count;

    static int length(const char* text) {
        int i = 0;
        while (text[i] != '\0') {
            i++;
        }
        return i;
    }

public:
    String(int s) {
        size = s;
        str = new char[size + 1];
        str[0] = '\0';
        count++;
    }

    String() : String(80) {}

    String(const char* text) : String(length(text)) {
        for (int i = 0; i < size; i++) {
            str[i] = text[i];
        }
        str[size] = '\0';
    }

    void input() {
        cout << "Enter string: ";
        cin.getline(str, size + 1);
    }

    void output() {
        cout << str << endl;
    }

    static int getCount() {
        return count;
    }

    ~String() {
        delete[] str;
        count--;
    }

    String(const String&) = delete;
    String& operator=(const String&) = delete;
};

int String::count = 0;

int main() {
    String s1;
    String s2(50);
    String s3("Hello World");

    cout << "String 1: ";
    s1.input();

    cout << "String 2: ";
    s2.input();

    cout << "\nAll strings:\n";

    s1.output();
    s2.output();
    s3.output();

    cout << "\nCount: " << String::getCount() << endl;

    return 0;
}