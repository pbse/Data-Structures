#include <iostream>
using namespace std;

template <typename T>
class node {
private:
	T data;
	node<T> *left;
	node<T> *right;
	int h;
public:
	node<T>() : left(nullptr), right(nullptr), h(1){}
	node<T>(T data) : data(data), left(nullptr), right(nullptr), h(1){}
	T getData() {
		return this->data;
	}
	void setLeft(node<T> *n) {
		this->left = n;
	}
	void setRight(node<T> *n) {
		this->right = n;
	}
	void setHeight(int h) {
		this->h = h;
	}
	node<T> * getLeft() {
		return this->left;
	}
	node<T> * getRight() {
		return this->right;
	}
	int getHeight() {
		return this->h;
	}

	int depth() {
		if(this==NULL){
			return 0;
		}
		else return this->getHeight();
	}

	int getBalance() {
		if(this==NULL) return 0;
		return (this->getLeft()->depth() - this->getRight()->depth()) ;
	}

// Rotations - LeftRotation and Right Rotation

	node<T> * rightRotation() {
		node<T> *left = this->getLeft();
		node<T> *right = left->getRight();

		// Make the rotation
		left->right = this;
		this->left = right;

		// Change the height of both the elements
		this->setHeight(max(this->getLeft()->depth(), this->getRight()->depth()) + 1);
		left->setHeight(max(left->getLeft()->depth(), left->getRight()->depth()) + 1);

		return left;
	}

	node<T> * leftRotation() {
		node<T> *right = this->getRight();
		node<T> *left = right->getLeft();

		// Make the rotation
		right->left = this;
		this->right = left;

		// Change the height of both the elements
		this->setHeight(max(this->getLeft()->depth(), this->getRight()->depth()) + 1);
		right->setHeight(max(right->getLeft()->depth(), right->getRight()->depth()) + 1);

		return right;
	}

	node<T>* insert(T data) {
		if(data >= this->data) {
			if(this->right==NULL) {
				this->right = new node<T>(data);
			}
			else {
				this->right = this->getRight()->insert(data);
			}
		}
		else {
			if(this->left==NULL) {
				this->left = new node<T>(data);
			}
			else {
				this->left = this->getLeft()->insert(data);

			}
		}

		this->setHeight(max(this->getLeft()->depth(), this->getRight()->depth()) + 1);
		int balance = this->getBalance();

		// Left Left Condition
		if(balance >1 && data < this->getLeft()->data) {
			return this->rightRotation();
		}

		// Right Right Condition
		if(balance <-1 && data > this->getRight()->data) {
			return this->leftRotation();
		}

		// Left Right Condition
		if(balance >1 && data > this->getLeft()->data) {
			this->left = this->getLeft()->leftRotation();
			return this->rightRotation();
		}

		// Right Left Condition
		if(balance <-1 && data < this->getRight()->data) {
			this->right = this->getRight()->rightRotation();
			return this->leftRotation();
		}

		// Return the Pointer back. The last one will always be root.
		return this;
	}

	node<T> * find(T data) {
		if(this->data == data) {
			cout<<"Found at height - "<<this->getHeight();
			return this;
		}
		if(this->data > data && this->left!=NULL) {
			return this->left->find(data);
		}
		if(this->right!=NULL)
			return this->right->find(data);

		return NULL;
	}

// Traversals - Inorder, Preorder, PostOrder, level Order
	void inOrder() {
		if(this==NULL) return;
		this->left->inOrder();
		cout<<this->data<<", ";
		this->right->inOrder();
	}

	void preOrder() {
		if(this==NULL) return;
		cout<<this->data<<", ";
		this->left->preOrder();
		this->right->preOrder();
	}

	void postOrder() {
		if(this==NULL) return;
		this->left->postOrder();
		this->right->postOrder();
		cout<<this->data<<", ";
	}

	int height() {
		if(this==NULL) return 0;
		int l = this->left->height();
		int r = this->right->height();
		if(l>r) return l+1;
		else return r+1;
	}

	void levelOrder(int level) {
		if(this==NULL) return;
		if(level==1)
			cout<<this->data<<", ";
		else {
			this->left->levelOrder(level-1);
			this->right->levelOrder(level-1);
		}
	}
 };

template <typename T>
T max(T a, T b) {
	return a>b ? a : b;
}
