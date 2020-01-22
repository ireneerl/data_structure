#include <iostream>

struct node{
  int val;
  node *next;
};

node *front, *rear;

void enque(int x){
  if(rear == NULL){
    node *data = new node;
    data->val = x;
    data->next = NULL;
    rear = data;
    front = data;
  }else{
    node *data = new node;
    data->val = x;
    data->next = NULL;
    rear->next = data;
    rear = data;
  }
}

void deque(){
  if(rear == NULL && front == NULL){
    std::cout << "queue is empty" << '\n';
  }else{
    node *data =front;
    std::cout << data->val << " is deleted" << '\n';
    front=front->next;
    delete data;
    if(front == NULL){
      rear = NULL;
    }
  }
}

void show(){
  node *data = front;
  while(data != NULL){
    std::cout << data->val << '\t';
    data = data->next;
  }
}


int main(){
  int ch, x;
  std::cout << "\n1. Enque";
  std::cout << "\n2. Deque";
  std::cout << "\n3. Print";
  do
	{
		std::cout << "\nEnter Your Choice : ";
		std::cin >> ch;
		if (ch == 1){
			std::cout << "\nInsert : ";
			std::cin >> x;
			enque(x);
		}else if (ch == 2){
			deque();
		}else if (ch == 3){
			show();
		}
	} while (ch != 0);
}
