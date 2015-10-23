#include "bst.hpp"
using namespace std;

template <typename T>
class BST {
private:
	node<T> *root;
public:
	BST<T>() : root(nullptr){}
	void insert(T data) {
		if(this->root==NULL) {
			root = new node<T>(data);
		}
		else root = root->insert(data);
	}

	node<T> * find(T data) {
		if(this->root!=NULL)
			return root->find(data);
		else return NULL;
	}

	void remove(T data) {
		if(this->root==NULL) return;
		node<T> *current = root;
		node<T> *parent = root;
		bool isLeftChild = false;

		while(current!=NULL && current->getData() != data){
			parent = current;
			if(data < current->getData()) {
				current = current->getLeft();
				isLeftChild = true;
			}
			else {
				current = current->getRight();
				isLeftChild = false;
			}
		}

		if(current==NULL) return;

		// Check if the node to be deleted is a Leaf Node
		if(current->getLeft()==NULL && current->getRight()==NULL){
			if(current==this->root) {
				root = NULL;
			}
			else {
				if(isLeftChild) parent->setLeft(NULL);
				else parent->setRight(NULL);
			}
		}

		if(current->getLeft()!=NULL && current->getRight()==NULL) {
			if(current==root) root = current->getLeft();
			else {
				if(isLeftChild)
					parent->setLeft(current->getLeft());
				else parent->setRight(current->getLeft());
			}
		}
		else if(current->getRight()!=NULL && current->getLeft()==NULL) {
			if(current==root) root = current->getRight();
			else {
				if(isLeftChild)
					parent->setLeft(current->getRight());
				else parent->setRight(current->getRight());
			}
		}

	}

	void inOrder() {
		if(this->root==NULL) return;
		this->root->inOrder();
	}
	void preOrder() {
		if(this->root==NULL) return;
		this->root->preOrder();
	}
	void postOrder() {
		if(this->root==NULL) return;
		this->root->postOrder();
	}

	void levelOrder() {
		if(this->root==NULL) return;
		int h = height();
		for(int i=1;i<=h;i++){
			this->root->levelOrder(i);
			cout<<endl;
		}
	}

	int height() {
		if(this->root==NULL) return 0;
		return this->root->height();
	}
};

int main() {
	BST<int> b;
	b.insert(1);
	b.insert(2);
	b.insert(3);
	b.insert(4);
	b.insert(4);
	b.insert(4);
	b.insert(4);
	b.insert(5);
	b.insert(6);
	b.insert(7);
	b.insert(8);
	b.insert(9);
	b.insert(10);
	b.remove(1);
	b.find(8);
	cout<<endl;
	b.inOrder();
	cout<<endl;
	b.preOrder();
	cout<<endl;
	b.postOrder();
	cout<<endl;
	cout<<b.height();
	cout<<endl;
	b.levelOrder();
	return 0;
}
