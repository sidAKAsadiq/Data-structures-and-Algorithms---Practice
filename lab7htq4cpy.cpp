#include <iostream>
#include <string>

using namespace std;
int precedence(char c){
    if (c == '+' || c == '-')
    return 1;
    if (c == '*' || c == '/')
    return 2;
    if(c == '^')
    return 3;
    if(c == '(' || c == ')' || c == '{' || c == '}' || c == ']' || c == '[')
    return 4;
    return 0;
}
class node
{
public:
    char data;
    node *next;
    node()
    {
        next = NULL;
    }
    node(char c)
    {
        data = c;
        next = NULL;
    }
    ~node()
    {
        next = NULL;
        delete next;
    }
};

class char_stack
{
public:
    // node* head; //top hi tou mera head hai
    node *top;
    char_stack()
    {
        top = NULL;
    }
    char_stack(node *n)
    {
        top = n;
        top->next = NULL;
    }
    void push(char c)
    {
        // This is basically insert at head
        if (top == NULL)
        {
            top = new node;
            top->data = c;
            top->next = NULL;
            return;
        }
        node *new_node = new node(c);
        new_node->next = top;
        top = new_node;
    }
    void pop()
    {
        // This is basically delete from head
        if (top == NULL)
        {
            cout << "Stack Underflow\n";
            return;
        }
        node *temp = top;
        top = top->next;
        temp = NULL;
        delete temp;
    }
    bool is_empty()
    {
        if (top == NULL)
            return true;
        return false;
    }
    char peek()
    {
        return top->data;
    }
    void traverse()
    {
        node *t = new node;
        t = top;
        while (t != NULL)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
    void infix_to_postfix(string s){
        string ans;
        int i = 0;
        while (i < s.length()){
            //If the character is an alphabet
            // if((s[i] >= 'a' && s[i] <= 'z')){
            //     ans.push_back(s[i]);
            //     i++;
            //     continue;
            // }
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}' || s[i] == ']' || s[i] == '['){
            if(is_empty() || (peek() == '(' || peek() == '[' || peek() == '{') ){
                push(s[i]);
                i++;
                continue;
            }
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                push(s[i]);
                i++;
                continue;
            }
            if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                char c;
                if(s[i] == ')') c = '(';
                if(s[i] == ']') c = '[';
                if(s[i] == '}') c = '{';
                while(peek() != c){
                    ans.push_back(peek());
                    pop();
                }
                pop();
                i++;
                continue;
            }
            if(precedence(s[i]) > precedence(peek())){
                push(s[i]);
                i++;
                continue;
            }
            if(precedence(s[i]) < precedence(peek())){
                while(precedence(s[i]) < precedence(peek())){
                    ans.push_back(peek());
                    pop();
                    if(is_empty()){
                        break;
                    }
                }   
                if(is_empty()){
                    push(s[i]);
                    i++;
                    continue;
                }
                if(precedence(s[i]) == precedence(peek())){
                    
                    ans.push_back(peek());
                    pop();
                    push(s[i]);
                    i++;
                    continue;
                }
                if(precedence(s[i]) > precedence(peek())){
                    push(s[i]);
                    i++;
                    continue;                    
                }
            }
                if(precedence(s[i]) == precedence(peek())){
                    
                    ans.push_back(peek());
                    pop();
                    push(s[i]);
                    i++;
                    continue;
                }            

        }
        else{
                ans.push_back(s[i]);
                i++;
                continue;            
        }
        }
        while(!is_empty()){
            ans.push_back(peek());
            pop();
        }
        cout<<"Postfix : "<<ans;
    }
};

int main() {                                        
    char_stack c1;
    c1.infix_to_postfix("(11+22-(3*4-7)*5-127)");
    return 0;
}