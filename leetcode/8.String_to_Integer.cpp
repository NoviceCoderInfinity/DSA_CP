#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
        int i = 0; bool positive = true; long number = 0; 
        
        while(i < s.size() && s[i] == ' ') {++i;}
        
        if (s[i] == '-') {positive = false; ++i;}
        else if (s[i] == '+') {++i;}
        
        while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            number *= 10; number += (long)(digit); ++i; 
            if (positive && number > INT_MAX) {return INT_MAX;}
            else if (!positive && number - 1 > INT_MAX) {return INT_MIN;}
        }
        return positive ? number : -number;
    }


int main() {
	string s; cout << "Input the number in the string format: ";
	cin >> s;
	int result = myAtoi(s);
	cout << result << endl;
}
