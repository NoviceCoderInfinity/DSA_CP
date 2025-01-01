/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insert_at(stack<int> &s, int element) {
    if (s.size() == 0 || s.top() < element) {s.push(element); return;}
    
    int top = s.top(); s.pop();
    insert_at(s, element);
    s.push(top);

    return ;
}

void SortedStack :: sort()
{
   //Your code here
   if (s.size() == 0) {return ;}
   
   int top = s.top(); s.pop();
   sort();
   insert_at(s, top);
   
   return;
}
