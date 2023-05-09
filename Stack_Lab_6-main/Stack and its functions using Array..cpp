#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

# define stack_size 10  
int stack_array[stack_size];
int top = -1;

bool isEmpty() {
    if (top == -1) return 1;
    else return 0;  
}

bool isFull() {
    if (top == stack_size - 1) return 1;
    else return 0;
}

int StackTop() {
    return stack_array[top];
}

void Push(int data) {
    if (top == stack_size - 1) cout << "stack overflow" << endl;
    else {
        top++;
        stack_array[top] = data;
    }
}

int Pop() {
    if (top==-1) cout << "stack underflow '0' will be returned " << endl;
    else {
        int value = StackTop();
        top--;
        return value;
    }
}

void Display() {
    for (int i = 0; i < top + 1; i++) {
        cout << stack_array[i] << " ";
    }
    cout << endl;
}
int main() {
    auto start_time = high_resolution_clock::now();
    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;
}
