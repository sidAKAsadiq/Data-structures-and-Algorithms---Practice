#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include "math.h"

using namespace std;

int
precedence (char c)
{
 
if (c == '+' || c == '-')
   
return 1;
 
if (c == '*' || c == '/')
   
return 2;
 
if (c == '^')
   
return 3;
 
if (c == '(' || c == ')' || c == '{' || c == '}' || c == ']' || c == '[')
   
return 4;
 
return -1;

}

template<class T>
class node
{

public:
T data;
 
node * next;
 
node ()
  {
   
next = NULL;
 
}
node (T c)
  {
   
data = c;
   
next = NULL;
 
}
~node ()
  {
   
next = NULL;
   
delete next;

}
};

template <class S>
class char_stack
{

public:
    // node* head; //top hi tou mera head hai
    node<S> * top;
 
char_stack ()
  {
   
top = NULL;
 
}
char_stack (node<S> * n)
  {
   
top = n;
   
top->next = NULL;
 
}
void push (S c)
  {
   
      // This is basically insert at head
      if (top == NULL)
     
      {

top = new node <S>;

top->data = c;

top->next = NULL;

return;
     
}
   
node<S> * new_node = new node <S> (c);
   
new_node->next = top;
   
top = new_node;
 
}
 
void pop ()
  {
   
      // This is basically delete from head
      if (top == NULL)
     
      {

cout << "Stack Underflow\n";

return;
     
}
   
node <S>* temp = top;
   
top = top->next;
   
temp = NULL;
   
delete temp;
 
}
 
bool is_empty ()
  {
   
if (top == NULL)
     
return true;
   
return false;
 
}
 
S peek ()
  {
   
return top->data;
 
}
 
void traverse ()
  {
   
node <S>* t = new node<S>;
   
t = top;
   
while (t != NULL)
     
      {

cout << t->data << " ";

t = t->next;
     
}
   
cout << endl;
 
}
 
void infix_to_postfix (string s)
  {
   
string ans = "";
   
int i = 0;
   
while (i < s.length ())
      {

 //traverse();
 //cout<<ans<<endl;
 //If the character is an alphabet
 // if((s[i] >= 'a' && s[i] <= 'z')){
 //     ans.push_back(s[i]);
 //     i++;
 //     continue;
 // }
 if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'
     || s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}'
     || s[i] == ']' || s[i] == '[')
 {
   
 
cout << "Org anay wala " << s[i] << endl;
   
traverse ();
   
cout << ans << endl;
   
if (is_empty () || (peek () == '('))
     {

push (s[i]);

i++;

continue;
     
}
   
if (s[i] == '(')
     {

push (s[i]);

i++;

continue;
     
}
   
if (s[i] == ')')
     {

while (peek () != '(')
 {
   
ans.push_back (peek ());
   
pop ();
 
}

pop ();

i++;

continue;
     
}
   
if (precedence (s[i]) > precedence (peek ()))
     {

cout << "anay wala : " << s[i] << endl;

cout << "uper wala : " << peek () << endl;

push (s[i]);

i++;

continue;
     
}
   
if (precedence (s[i]) < precedence (peek ()))
     {

cout << " leess : anay wala : " << s[i] << endl;

cout << " lesss : uper wala : " << peek () << endl;

while (precedence (s[i]) < precedence (peek ()))
 {
   
if (peek () != '(')
     
ans.push_back (peek ());
   
pop ();
   
if (is_empty ())
     {

break;
     
}
 
}

if (is_empty ())
 {
   
push (s[i]);
   
i++;
   
continue;
 
}

if (precedence (s[i]) == precedence (peek ()))
 {
   
ans.push_back (peek ());
   
pop ();
   
push (s[i]);
   
i++;
   
continue;
 
}

if (precedence (s[i]) > precedence (peek ()))
 {
   
push (s[i]);
   
i++;
   
continue;
 
}
     
}
   
 
if (precedence (s[i]) == precedence (peek ()))
     {

 
ans.push_back (peek ());

pop ();

push (s[i]);

i++;

continue;
     
}
 
 
}

else
 {
   
cout << "opearnd aya: " << endl;
   
ans.push_back (s[i]);
   
i++;
   
continue;
 
}
     
}
   
while (!is_empty ())
      {

cout << "idhar";

ans.push_back (peek ());

pop ();
     
}
   
cout << "Postfix : " << ans;
 
}
 
 
string infix_to_prefix (string s)
  {
   
string ans;
   
reverse (s.begin (), s.end ());
   
   
int i = 0;
   
while (i < s.length ())
      {





if (s[i] != '(' && s[i] != ')' && s[i] != '+' && s[i] != '-'
    && s[i] != '*')
 {
   
if((s[i] == '1' && s[i-1] == '+') || (s[i] == '3')  || (s[i] == '4') || (s[i] == '7') || (s[i] == '5'))
ans.push_back(' ');
ans.push_back (s[i]);

   
i++;
   
continue;
 
}

else
 {
   
if (is_empty ())
     {

push (s[i]);

i++;

continue;
     
}
   
if (s[i] == '(')
     {

while (peek () != ')')
 {
   
ans.push_back (peek ());
   
pop ();
 
}

pop ();

i++;

continue;
     
}
   
if (precedence (s[i]) > precedence (peek ()))
     {

push (s[i]);

i++;

continue;
     
}
   
if (precedence (s[i]) == precedence (peek ()))
     {

push (s[i]);

i++;

continue;
     
}
   
if (s[i] == ')')
     {

push (s[i]);

i++;

continue;
     
}
   
if (peek () == ')')
     {

push (s[i]);

i++;

continue;
     
}
   
 
if (precedence (s[i]) < precedence (peek ()))
     {

while (precedence (s[i]) < precedence (peek ()))
 {
   
if (peek () == ')')
     
break;
   
ans.push_back (peek ());
   
pop ();
 
}

if (peek () == ')')
 {
   
push (s[i]);
   
i++;
   
continue;
 
}

if (precedence (s[i]) == precedence (peek ()))
 {
   
push (s[i]);
   
i++;
   
continue;
 
}

if (precedence (s[i]) > precedence (peek ()))
 {
   
push (s[i]);
   
i++;
   
continue;
 
}
     
}
 
}
     
 
 
}
   
while (!is_empty ())
      {

ans.push_back (peek ());

pop ();
     
}
   
reverse (ans.begin (), ans.end ());
   
//cout << "\nPrefix : " << ans;
return ans;
 
}
void calculate(string s){
    int i = s.length() - 2;
    cout<<endl<<"Prefix : "<<s<<endl;
    int ans = 0;
    int c = 0;
    while(i >= 0){
        if(s[i] != ' ' && s[i] != '+' && s[i] != '-' && s[i] != '*'){
        int a = s[i] - '0';
        //cout<<a<<endl;
        ans = ans + (a * pow(10,c));
        i--;
        c++;
        if(c==3)ans+=1;
        //cout<<ans+1<<endl;
        }
        else{
        if(ans!=0)
        push(ans);
        ans = 0;
        c = 0;
        if(s[i] == ' '){
            i--;;
            continue;
        }
        else{
            int op1 = peek();
            pop();
            int op2 = peek();
            pop();
            int ans2;
            if(s[i] == '+'){
                ans2 = op1 + op2;
            }
            else if(s[i] == '-'){
                ans2 = op1 - op2;
            }
            else if(s[i] == '*'){
                ans2 = op1*op2;
            }
            i--;
            push(ans2);
        }
        }
    }
    cout<<"Final answer: "<<peek();
   
}

 
};


 
int
main ()
{
  // 127 25 33
char_stack <char> c1;
cout<<"Original :(11+22-(3*4-7)*5)-127";
string s = c1.infix_to_prefix ("(11+22-(3*4-7)*5)-127");

char_stack <int> c2;
c2.calculate(s);

 
return 0;

}
