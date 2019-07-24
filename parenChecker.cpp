//Created by Brandon Barnes

#include <iostream>
#include <stack>


using namespace std;

bool parenChecker(string arg){
	stack<char> validityStack;
	char temp;
	
	validityStack.push('$'); //I'm using this char as a check when popping
	//If I pop this element, then parenChecker should return false
	//If upon parsing string this is not the top element, then should return false
	
	for(int i = 0; i<arg.size();i++){
		temp = arg[i];
		switch(temp){
			case '(': validityStack.push('('); break;
			case '[': validityStack.push('['); break;
			case '{': validityStack.push('{'); break;
			
			case ')': if(validityStack.top()!='('){return false;} 
					  else{validityStack.pop();} break;
			case ']': if(validityStack.top()!='['){return false;} 
					  else{validityStack.pop();} break;
			case '}': if(validityStack.top()!='{'){return false;} 
					  else{validityStack.pop();} break;
			
			default: break; //Non enclosing char are irrelevant
		}
	}
	
	if(validityStack.top()=='$'){
		return true;
	}
	else{
		return false;
	}
	
	
}


int main(){
	string arg = "{[{{}]}";
	
	cout << parenChecker(arg)<<endl;
	
	return 0;
}