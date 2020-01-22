#include <iostream>

int stack[10];
int front = 0 ;
int rear = 0 ;

void push(int x){
  if(rear ==10){
    std::cout << "overflow" << '\n';
  }else{
    stack[rear++]=x;
  }
}
void pop(){
  if(rear==front){
    std::cout << "underflow" << '\n';
  }else{
    std::cout << "pop element -> " << stack[--rear]<< '\n';
  }
}

void show(){
  for (int i = front; i < rear; i++){
		std::cout << stack[i] << "\t";
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
