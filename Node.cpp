#include <bits/stdc++.h>
using namespace std;
 
class Node{
  private:
  public:
    int data;
    Node *next;

    Node(){
      this->next = NULL;
    }

    Node(int data){
      this->data = data;
      this->next = NULL;
    }

    Node(int data, Node *next){
      this->data = data;
      this->next = next;
    }

    Node* clone(){
      Node* temp = new Node(this->data, this->next);
      Node* res = new Node(this->data);
      while(temp->next != NULL){
    	temp = temp->next;
	res->insertR(temp->data);
      }
      return res;
    }

    void merge(Node* second){
      Node* temp = this;
      while(temp->next != NULL){
        temp = temp->next;
      }
      temp->next = second;
    }

    void mergeAndSort(Node* second, bool reverse = false){
      int direction =  reverse ? -1 : 1;
      this->sort(reverse);
      while(second != NULL){
	      this->insert(second->data, direction);
      	second = second->next;
      }
    }

    void insertL(int value){
      Node* temp = this->clone();
      this->data = value;
      this->next = temp;
    }

    void insertR(int value){
      Node* end = new Node(value);
      Node* temp = this;
      while(temp->next != NULL){
        temp = temp->next;
      }
      temp->next = end;
    }

    void insert(int value, int direction){
      if(direction == 0){
        this->insertR(value);
        return;
      }
      Node* temp = this;
      if(value*direction < temp->data*direction){
        this->insertL(value);
      }else if(value == temp->data){
        return;
      }else if(temp->next == NULL){
        this->insertR(value);
      }else{
        while(value*direction > temp->data*direction && temp->next != NULL){
          temp = temp->next;
        }
        if(value == temp->data){
          return;
        }
        if(value*direction > temp->data*direction){
          this->insertR(value);
        }
        if(value*direction < temp->data*direction || temp->next == NULL){
          Node* split = new Node(temp->data, temp->next);
          temp->data = value;
          temp->next = NULL;
          this->merge(split);
        }
      }  
    }

    void sort(bool reverse = false){
      int direction =  reverse ? -1 : 1;
      Node* temp = this->clone();
      this->next = NULL;
      temp = temp->next;
      while(temp != NULL){
	      this->insert(temp->data, direction);
    	  temp = temp->next;
      }
    }

    static void display(Node* node){
      while(node != NULL){
	cout << node->data << " ";
    	node = node->next;
      }
      cout << endl;
    }
};

class Program{
  private:
  public:
    // Bai 1
    static void One(){
      int n, data;
      cout << "+ Nhap so luong so nguyen: ";
      cin >> n;
      cout << "+ Nhap " << n << " so nguyen: ";
      cin >> data;
      Node* list = new Node(data);
      for(int i = 1; i < n; ++i){
        cin >> data;
        list->insert(data, 0);
      }
      cout << "Danh sach vua nhap theo thu tu tang dan: \n->> ";
      Node::display(list);
    }

    // Bai 2
    static void Two(){
      int n, data;
      cout << "+ Nhap so luong so nguyen: ";
      cin >> n;
      cout << "+ Nhap " << n << " so nguyen: ";
      cin >> data;
      Node* listA = new Node(data);
      for(int i = 1; i < n; ++i){
        cin >> data;
        listA->insert(data, 1);
      }
      cout << "+ Nhap so luong so nguyen: ";
      cin >> n;
      cout << "+ Nhap " << n << " so nguyen: ";
      cin >> data;
      Node* listB = new Node(data);
      for(int i = 1; i < n; ++i){
        cin >> data;
        listB->insert(data, 1);
      }
      listA->mergeAndSort(listB);
      cout << "Danh sach sau khi tron: \n->> ";
      Node::display(listA);
    }

    // Bai 3
    static void Three(){
      int n, data;
      cout << "+ Nhap so luong so nguyen: ";
      cin >> n;
      cout << "+ Nhap " << n << " so nguyen: ";
      cin >> data;
      Node* list = new Node(data);
      for(int i = 1; i < n; ++i){
        cin >> data;
        list->insert(data, 1);
      }
      bool a = false, b = false;
      Node* listA = new Node(list->data);
      Node* listB = new Node(list->data);
      while(list != NULL){
        if(list->data % 2){
          if(b){
            listB->insert(list->data, 1);
          }else{
            listB->data = list->data;
            b = true;
          }
        }else{
          if(a){
            listA->insert(list->data, 1);
          }else{
            listA->data = list->data;
            a = true;
          }
        }
    	list = list->next;
      }
      cout << "Danh sach so chan: \n->> ";
      if(a){
        Node::display(listA);
      }else{
        cout << endl;
      }
      cout << "Danh sach so le: \n->> ";
      if(b){
        Node::display(listB);
      }else{
        cout << endl;
      }
      
    }
};

int main(){
  cout << "                   ---------- Bai 1 ---------" << endl;
  Program::One();
  cout << "                   ---------- Bai 2 ---------" << endl;
  Program::Two();
  cout << "                   ---------- Bai 3 ---------" << endl;
  Program::Three();
  return 0;
}
