//Created by Brandon Barnes

//favors the later node for middle on even length lists

#include <iostream>

using namespace std;

class Node;

class Node{
	public:
	int value;
	Node* next;
	
	Node(int setValue){
		this->value = setValue;
		this->next = NULL;
	}
	Node(){
	}
};

int getMiddle(Node* head){
	int returnValue = 0;
	
	
	if(head==NULL){
		return 0; //Change to error value based on problem
	}
	if(head->next==NULL){
		return head->value;
	}
	if(head->next->next == NULL){
		return head->next->value;
	}
	Node* trail = head->next;
	Node* pioneer = head->next;
	
	while(pioneer != NULL && pioneer->next !=NULL && pioneer->next->next != NULL){
		cout << "loophell" << endl;
		//cout << pioneer;
		pioneer = pioneer->next->next;
		trail = trail->next;
		
	}

	returnValue = trail->value;
	
	return returnValue;
}

int main(){
	Node head = Node(1);
	Node* current = &head;
	Node* temp;
	
	for(int i =2; i<7;i++){
		temp = new Node(i);
		current->next = temp;
		current = current->next;
		
	}
	
	cout << getMiddle(&head) << endl;
	
	
	return 0;
}