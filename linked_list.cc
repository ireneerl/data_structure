#include <iostream>

struct node{
  int val;
  node *next;
};

node *head;

void insert(int x){
  node *data = head;
  if(head != NULL){
    while(data->next != NULL){
      data = data->next;
    }
    node *data_new = new node;
    data->next = data_new;
    data_new->val = x;
    data_new->next=NULL;
  }else{
    node *data_new = new node;
    data_new->val = x;
    data_new->next=NULL;
    head = data_new;
  }
}

void remove(int x){
  if(head == NULL){
    std::cout << "The Link is empty" << '\n';
    return;
  }else if(head->val == x){
    node *tmp = head;
    head = head->next;
    delete tmp;
    return;
  }

  node *tmp_walk = head, *tmp_behind = head;
  //searching the element
  while(tmp_walk != NULL && tmp_walk->val != x){
    tmp_behind = tmp_walk;
    tmp_walk = tmp_walk->next;
  }
  if(tmp_walk == NULL){
    std::cout << "Element not found" << '\n';
    return;
  }
  tmp_behind->next = tmp_walk->next;
  delete tmp_walk;
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
  while(data != NULL){
    std::cout << data->val << '\t';
    data = data->next;
  }
}

void reverse(){
  node *new_head = head;
  node *walker = new_head->next;
  while (walker != NULL) {
    node *walker_next = walker->next;
    walker->next = new_head;
    new_head = walker;
    walker = walker_next;
  }
  head->next = NULL;
  head = new_head;
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
