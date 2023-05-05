#include <iostream>               
using namespace std;

int top = 0;                    //Initially no items are at stack. Therefore we set top as -1 instead of 0.

bool isEmpty(int stack){        //Checking whether the stack is empty
    if (top == -1){
        return true;
    } else{
        return false;
    }
}

bool isFull(int stack[]){                           //Checking whether the stack is full
    int sz = sizeof(*stack) / sizeof(stack[0]);

    if (top == sz-1){
        return true;
    } else {
        return false;
    }
}

void push(int stack[], int value){          //Inserting data to stack
    top++;

    if (isFull(stack)){
        cout<<"Error - Stack Overflow"<<endl;        
    } else {
        stack[top] = value;
    }
}

void pop(int stack[]){                      //Removing data from stack
    if (isEmpty(*stack)){
        cout<<"Error - Stack Underflow"<<endl;
    } else {
        top--;
    }
}

void stackTop(int stack[]){                 //Finding what is at the top of the stack
    if (isEmpty(*stack)){
        cout<<"Stack is empty.";
    } else {
        cout<<"Top element is "<< stack[top] << ".";
    }   cout<<endl;
}


void display(int stack[]){                  //Prints elements from top to bottom of the stack
    if (isEmpty(*stack)){
        cout<<"Stack is empty.";
    } else {
      for(int i=top; i>0; i--){            
        cout<<stack[i]<<" ";
      }  cout<<endl;
    } 
}

int main(){
    cout << "Enter array size - ";     //We can give array size here.
    int s;
    cin >> s;

    int stk[s];                        

    clock_t tStart = clock();

    push(stk,8);
    push(stk,10);
    push(stk,5);
    push(stk,11);
    push(stk,15);
    push(stk,23);
    push(stk,6);
    push(stk,18);
    push(stk,20);
    push(stk,17);

    display(stk);

    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);

    display(stk);

    push(stk,4);
    push(stk,30);
    push(stk,3);
    push(stk,1);

    display(stk);

    cout <<"Time taken: "<< double(clock() - tStart)/CLOCKS_PER_SEC;
    
    return 0;
}