class Solution{
public:
    void insert_at_bottom(stack<int> &St, int element) {
        if (St.size() == 0) {
            St.push(element);
            return;
        }
        
        int top = St.top(); St.pop();
        insert_at_bottom(St, element);
        St.push(top);
    }
    
    void Reverse(stack<int> &St){
        if (St.size() == 0) {return ;}
        int top = St.top(); St.pop();
        St.pop();
        
        Reverse(St);
        insert_at_bottom(St, top);
        return;
    }
};
