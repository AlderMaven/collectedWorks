//Created by Brandon Barnes

#include <iostream>
#include <climits>

using namespace std;

class Node;
bool isBSTHelper(Node*, int, int);

class Node{
	int data;
    Node* right;
    Node* left;
    
public:
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
	
	Node* getLeft(){
		return this->left;
	}
	Node* getRight(){
		return this->right;
	}
	int getData(){
		return this->data;
	}
	void setLeft(Node* newLeft){
		this->left=newLeft;
	}
	void setRight(Node* newRight){
		this->right=newRight;
	}
	void setData(int newData){
		this->data=newData;
	}
	
};


bool isBSTHelper(Node* root, int min, int max){
	bool returnBool =true;
	
	if(root==NULL){
		return true;
	}
	if(root->getData()>=max || root->getData()<=min){
		return false;
	}
	else{
		return(isBSTHelper(root->getLeft(), min, root->getData()) &&
		isBSTHelper(root->getRight(), root->getData(), max));
	}
	
	
	
	
}

bool isBST(Node* root){
	bool returnBool = true;
	if(root==NULL){
		return true;
	}
	
	
	

	
	
	return isBSTHelper(root, INT_MIN, INT_MAX);
}


int main(){
	
	
	Node root = Node(5);
	
	
	Node* temp = new Node(4);
	root.setLeft(temp);
	
	
	temp = new Node(10);
	root.setRight(temp);
	
	
	temp = new Node(6);
	root.getLeft()->setRight(temp);
	
	
	
	
	cout << isBST(&root) << endl;
	
	return 0;
}