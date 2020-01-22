#include <iostream>

int queue[10];
int front = 0 ;
int rear = 0 ;

void enque(int x){
  if(rear ==10){
    std::cout << "overflow" << '\n';
  }else{
    queue[rear++]=x;
  }
}
void deque(){
  if(rear==front){
    std::cout << "underflow" << '\n';
  }else{
    std::cout << "deque element -> " << queue[front++]<< '\n';
    for(int i = front; i < rear ; i++){
      queue[i-front]=queue[i]; //shift the value;
    }
    rear= rear-front;
    front=0;
  }
}

void show(){
  for (int i = front; i < rear; i++){
		std::cout << queue[i] << "\t";
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
