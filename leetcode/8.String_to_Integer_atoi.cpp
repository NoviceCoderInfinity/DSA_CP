// Iterative Solution
class Solution {
public:
    bool sanityCheck(int result, int dig) {
        return (result > (INT_MAX - dig) / 10) || (result < (INT_MIN + dig) / 10);
    }
    int myAtoi(string s) {
        int i = 0, result = 0; bool positive = true;
        
        while(i < s.size() && s[i] == ' ') {++i;} // WhiteSpace

        if (s[i] == '-') {positive = false; ++i;} // Sign Check
        else if (s[i] == '+') {++i;}
        
        while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            if (sanityCheck(result, digit)){
                return positive ? INT_MAX : INT_MIN;
            }
            result *= 10; result += digit;
            ++i;
        }
        return positive ? result : -result;
    }
};


// Discrete Finite Automata Solution
enum State {q0, q1, q2, qd};

class StateMachine {
    State curr;
    int result;
    bool pos;

    bool sanityCheck(int dig) {
        return ((result > (INT_MAX - dig) / 10) || (result < (INT_MIN + dig) / 10));
    }

    void to_q1(char& ch) {
        curr = q1;
        add_to_result(ch - '0');
    }

    void to_q2(char& ch){
        curr = q2;
        if (ch == '-') {pos = false;}
        else {pos = true;}
    }

    void to_qd() {
        curr = qd;
    }

    void add_to_result(int dig) {
        if (sanityCheck(dig)) {
            if (pos) {result = INT_MAX;}
            else {result = INT_MIN; pos = true;}
            to_qd();
        }
        else {result = result * 10 + dig;}
    }

public:
    StateMachine() {
        curr = q0; result = 0; pos = true;
    }

    void transition(char& ch) {
        if (curr == q0) {
            if (ch == ' ') {return;}
            else if (ch == '-' || ch == '+') {return to_q2(ch);}
            else if (ch >= '0' && ch <= '9') {return to_q1(ch);}
            else {return to_qd();}
        }
        else if (curr == q1 || curr == q2) {
            if (ch >= '0' && ch <= '9') {to_q1(ch);}
            else {to_qd();}
        }
    }

    int getResult() {
        return pos ? result : -result;
    }

    State getState() {
        return curr;
    }
};


class Solution {
public:
    int myAtoi(string s) {
        StateMachine DFA;
        for (int i = 0; i < s.size(); ++i) {
            DFA.transition(s[i]);
        }

        return DFA.getResult();
    }
};
