#include <iostream>

struct node{
  int val;
  node *next;
};

node *top;

void push(int x){
  if(top == NULL){
    node *data = new node;
    data->val = x;
    data->next = NULL;
    top = data;
  }else{
    node *data = new node;
    data->val = x;
    data->next = top;
    top = data;
  }
}

void pop(){
  if(top == NULL){
    std::cout << "stack is empty" << '\n';
  }else{
    node *data = top;
    std::cout << data->val << " is deleted" << '\n';
    top=top->next;
    delete data;
  }
}

void show(){
  node *data = top;
  while(data != NULL){
    std::cout << data->val << '\t';
    data = data->next;
  }
}


int main(){
  int ch, x;
  std::cout << "\n1. Push";
  std::cout << "\n2. Pop";
  std::cout << "\n3. Print";
  do
	{
		std::cout << "\nEnter Your Choice : ";
		std::cin >> ch;
		if (ch == 1){
			std::cout << "\nInsert : ";
			std::cin >> x;
			push(x);
		}else if (ch == 2){
			pop();
		}else if (ch == 3){
			show();
		}
	} while (ch != 0);
}
