#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node {
   int data;
   struct Node* next;
};
struct Node* top = NULL;

bool isEmpty(){
    if (top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int StackTop(){
    return top-> data;
}

void Push(int data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = data;
   new_node->next = top;
   top = new_node;
}

int Pop(){
   if (isEmpty()){
        cout << " Stack Underflow '0' will be returned" << endl;
        return 0;
   }
   
   else {
    int value = StackTop();
    top = top -> next;
    return value;
   }
}



void Display() {
   struct Node* temp;
   temp = top;
   while (temp != NULL) {
      cout<< temp->data <<" ";
      temp = temp->next;
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
