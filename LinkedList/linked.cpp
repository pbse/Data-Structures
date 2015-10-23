#include <iostream>
#include <set>
using namespace std;

template <typename T>
class Node{
public:
	T data;
	Node<T> *next;
	Node() : next(NULL) {}
	Node(T a, Node *t) : next(t), data(a) {}
	~Node() {}
};

template <typename T>
class LinkedList {
private:
	Node<T> *head;
public:
	LinkedList() : head(NULL){}
	~LinkedList() {}

	// Simple Insert
	void insert(T d) {
		// Insert for the first time
		if(head == NULL) {
			head = new Node<T>(d,NULL);
		}
		else {
			Node<T> *temp = head;
			while(temp->next!=NULL) {
				temp = temp->next;
			}
			Node<T> *n = new Node<T>(d,NULL);
			temp->next = n;
		}
	}

	// Inserting at Specific Location
	void insertAt(T d, int pos) {
		// Insert at First Position
		Node<T> *temp;
		if(pos == 0) {
			temp = new Node<T>(d,NULL);
			temp->next = head;
			head = temp;
		}
		else {
			int i = 1;
			temp = head;
			while(i<pos) {
				if(temp->next==NULL) {
					if(i==pos) {
						Node<T> *n = new Node<T>(d,NULL);
						temp->next = n;
					}
					else {
						std::cout<<"Entered Position is out of bounds"<<endl;
						return;
					}
				}
				temp = temp->next;
				i++;
			}
			Node<T> *n = new Node<T>(d,NULL);
			n->next = temp->next;
			temp->next = n;
		}
	}

	void delAt(int pos) {
		// Delete The First Element
		Node<T> *temp;
		if(pos==0) {
			temp = head;
			head = head->next;
			delete temp;
		}
		else {
			int i = 0;
			temp = head;
			while(i<pos-1) {
				temp = temp->next;
				i++;
				if(temp->next == NULL) {
					std::cout<<"Position Out Of Bound"<<endl;
					return;
				}
			}
			Node<T> *t = temp->next;
			temp->next = t->next;
			delete t;
		}
	}

	int length() {
		Node<T> *temp = head;
		int i = 0;
		while(temp!=NULL) {
			temp = temp->next;
			i++;
		}
		return i;
	}

	int search(T item) {
		Node<T> *temp = head;
		int i = 0;
		while(temp!=NULL) {
			if(temp->data == item) {
				return i;
			}
			temp = temp->next;
			i++;
		}
		std::cout<<"Element Not Found"<<endl;
		return -1;
	}

	void reverse() {
		Node<T> *temp = head;
		Node<T> *t1 = head;
		Node<T> *t2 = NULL;
		while(temp!=NULL) {
			temp = temp->next;
			t1->next = t2;
			t2 = t1;
			t1 = temp;
		}
		head = t2;
	}

	// Remove any Duplicate Entry in Your Linked List
	void removeDuplicate() {
		std::set<T> m;
		Node<T> *temp = head;
		Node<T> *previous = NULL;
		while(temp!=NULL) {
			if(m.count(temp->data)==0) {
				m.insert(temp->data);
				previous = temp;
				temp = temp->next;
			}
			// Duplicate Found. Need to delete the element
			else {
				previous->next = temp->next;
				Node<T> *t = temp;
				temp = temp->next;
				delete t;
			}
		}
	}

	void print() {
		Node<T> *temp = head;
		while(temp!=NULL) {
			std::cout<<temp->data<<", ";
			temp = temp->next;
		}
		std::cout<<endl;
	}

};


int main() {
	LinkedList<int> *a = new LinkedList<int>();
	a->insert(10);
	a->insert(12);
	a->insert(16);
	a->insert(24);
	a->insertAt(8,2);
	a->insertAt(9,2);
	a->insertAt(3,0);
	a->insertAt(3,6);
	a->insertAt(19,8);
//	a->print();
	a->delAt(0);
	a->delAt(1);
	a->print();
	std::cout<<"Length of the List is - "<<a->length()<<endl;
	std::cout<<"Searched for 3 - "<<a->search(3)<<endl;
	std::cout<<"reversing The LinkedList"<<endl;
	a->reverse();
	a->print();
	std::cout<<"Removing The Duplicates"<<endl;
	a->insert(10);
	a->insertAt(3,0);
	a->insertAt(3,0);
	a->insertAt(3,0);
	a->print();
	a->removeDuplicate();
	a->print();

//	LinkedList<char> *b = new LinkedList<char>();
//	char y = 'a';
//	b->insert(y);
//	b->print();
	return 0;
}
