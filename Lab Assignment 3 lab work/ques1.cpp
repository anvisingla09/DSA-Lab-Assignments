#include<iostream>
using namespace std;

#define SIZE 5
class Stack{
    int arr[SIZE];
    int top;
public:
Stack(){
  top=-1;
}
void push(int x){
  if(top==SIZE - 1){
    cout<<"satck is full\n";
  }
  else{
    top++;
    arr[top]=x;
    cout<<x<<"inserted\n";
  }
}

void pop(){
  if(top== -1){
    cout<<"stack is empty\n";
  }
  else{
    cout<<arr[top]<<"removed\n";
    top--;
  }
}

void peek(){
  if(top == -1){
    cout<<"stack is empty\n";
  }
  else{
    cout<<"top element:" << arr[top]<<"\n";
  }
}
void display(){
  if(top ==-1){
    cout<<"stack is empty\n";
  }
  else{
    cout<<"stack elements:";
    for(int i=top;i>=0;i--){
      cout<<arr[i]<<" ";
    }
    cout<<"\n";
  }
}

void isEmpty(){
  if(top==-1) cout<<"yes,empty\n";
  else cout<<"not empty\n";
}
void isFull(){
  if(top==SIZE -1) cout<<"yes.full\n";
  else cout<<"not full\n";
}

};
int main() {
    Stack s;
    int ch, val;
    do {
        cout << "\n1.Push\n2.Pop\n3.isEmpty\n4.isFull\n5.Display\n6.Peek\n7.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch) {
            case 1: cout << "Enter value: ";
                    cin >> val;
                    s.push(val);
                    break;
            case 2: s.pop();
                    break;
            case 3: s.isEmpty();
                    break;
            case 4: s.isFull();
                    break;
            case 5: s.display();
                    break;
            case 6: s.peek();
                    break;
            case 7: cout << "Exiting...\n";
                    break;
            default: cout << "Invalid Choice\n";
        }
    } while (ch != 7);

    return 0;
}
