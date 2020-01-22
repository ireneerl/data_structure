#include<iostream>

struct node{
  int val;
  node *prev;
  node *next;
};

node *head;

void insert(int x){
  node *data = head;
  if (head!=NULL){
    while(data->next != NULL){
      data = data->next;
    }
    node *new_data = new node;
    data->next = new_data;
    new_data->val = x;
    new_data->prev = data;
    new_data->next = NULL;

  }else{
    node *new_data = new node;
    new_data->val = x;
    new_data->prev = NULL;
    new_data->next = NULL;
    head = new_data;
  }

}


void remove(int x){

  node *tmp_walk = head;bool found = false;
  //searching the element
  if(head->val == x){
    node *tmp = head;
    head = head->next;
    head->prev=NULL;
    delete tmp;
    return;
  }
  while(tmp_walk->next != NULL && tmp_walk->val != x){
    tmp_walk = tmp_walk->next;
    found=true;
  }
  if(tmp_walk->val == x && tmp_walk->next == NULL){
    tmp_walk->prev->next = NULL;
  }else if(found){
    tmp_walk->prev->next = tmp_walk->next;
    tmp_walk->next->prev = tmp_walk->prev;
  }
  delete tmp_walk;
}

void reverse(){
  node *data = head;
  while(data->next != NULL){
    data = data ->next; //get to the end of the data
  }
  while(data!=NULL){
    std::cout << data->val << '\n';
    data = data->prev;
  }
}


void unique_search(int x){
  node *data = head;
  bool not_found = true;
  while (data != NULL){
    if(data->val == x){
      not_found = false;
      break;
    }
    data = data->next;
  }
  std::cout << (!not_found ? "found" : "not found") << '\n';
}

void print(){
  node *data = head;
  while(data!=NULL){
    std::cout << data->val << '\t';
    std::cout << data->next << '\n';
    data = data->next;
  }
}

int main(){
  int choice = 0, x, result;
  std::cout << "\n1. Insert";
	std::cout << "\n2. Delete";
	std::cout << "\n3. Search";
	std::cout << "\n4. Print";
	std::cout << "\n5. Reverse";
	std::cout << "\n0. Exit";
  do{
		std::cout << "\n\nEnter you choice : ";
		std::cin >> choice;
    switch (choice){
      case 1:
        std::cout << "inserting : ";
        std::cin >> x;
        insert(x);
        break;
      case 2:
        std::cout << "delete x : ";
        std::cin >> x;
        remove(x);
        break;
      case 3:
        std::cout << "search key x : ";
        std::cin >> x;
        unique_search(x);
        break;
      case 4:
        print();
        break;
      case 5:
        reverse();
        break;
    }

  }while(choice != 0);
  return 0;
}
