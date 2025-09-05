#include<iostream>
#include<string.h>
using namespace std;

#define SIZE 100

class Stack{
    char arr[SIZE];
    int top;
public:
Stack(){
  top = -1;
}

void push(char c){
  if(top == SIZE -1){
    cout<<"stack full\n";
  } else{
    arr[++top] = c;
  }
}

char pop(){
  if(top == -1){
    return '\0';
  } else{
    return arr[top--];
  }
}

bool isEmpty(){
  return (top==-1);
}
};

int main(){
  Stack s;
  char str[SIZE];
  cout<<"enter a string:";
  cin>>str;

  int n = strlen(str);

  for(int i=0;i<n;i++){
    s.push(str[i]);
  }

  cout<<"reversed string:";
  while(!s.isEmpty()){
    cout<<s.pop();
  }
  cout<<endl;

  return 0;
}
