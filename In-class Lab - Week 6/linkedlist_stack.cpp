#include <iostream>
using namespace std;

struct node{                //Creating the linked list
    int data;
    struct node *next;
};
struct node* top = NULL;

bool isEmpty(){             //Checking whether the stack is empty
    if (top == NULL){
        return true;
    } else {
        return false;
    }
}

// Since size is dynamic this time, I did not implement isFull() function.

void push(int value){      //New value is added to the front of the linked list
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    if (newnode == NULL){
        cout<<"Error - Stack overflow";
    } else{
    newnode -> data = value;
    newnode -> next = top; 
    top = newnode;
}
}

void pop(){               //Popping topmost value of stack
    if (isEmpty()){
        cout<<"Error - Stack Underflow";
    } else{
        top = top -> next;
    }
}

void display(){                                 //Prints elements from top to bottom of the stack
    struct node* temp;
    temp = top;

    if (isEmpty()){
        cout<<"Stack is empty."<<endl; 
    } else{
        while(temp){
            cout<<temp -> data<<" ";
            temp = temp -> next;
        } cout<<endl;
    }
}

void stackTop(){                                //Finding what is at the top of the stack
    if (isEmpty()){
        cout<<"Stack is empty.";
    } else {
        cout<<"Top element is "<< top -> data << ".";
    }   cout<<endl;
}

int main(){
    clock_t tStart = clock();

    push(8);
    push(10);
    push(5);
    push(11);
    push(15);
    push(23);
    push(6);
    push(18);
    push(20);
    push(17);

    display();

    pop();
    pop();
    pop();
    pop();
    pop();

    display();

    push(4);
    push(30);
    push(3);
    push(1);

    display();

    cout <<"Time taken: "<< double(clock() - tStart)/CLOCKS_PER_SEC;
}