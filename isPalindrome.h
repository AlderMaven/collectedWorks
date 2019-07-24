//Created by Brandon Barnes
//Simple Palindromic checker for c++ using stack
//Works on even or odd length strings, case-sensitive

#include<stack>
#include<iostream>
#include<stdlib.h>


using namespace std;

class PalindromicChecker{ //Encapsulates isPalindrome to keep helper secure
	public:
	bool isPalindrome(string candidate){
		
		int length = candidate.length();
		if(length == 0){ //considered empty string as non-palindromic
			return false;
		}
		else if(length == 1){ //Quick out for base case
			return true;
		}
		else if(length%2){ //Determine if even or odd length string
			return this->palindromeHelper(candidate, length, false);
		}
		else{
			return this->palindromeHelper(candidate, length, true);
		}
		
	}

	private:
	bool palindromeHelper(string candidate, int length, bool isEven){
		stack<char> charStack;
		if(isEven){
			for(int i = 0; i<=length/2-1;i++){
				charStack.push(candidate[i]); //push front half on stack in order
			}
			for(int i = length/2; i<length;i++){
				if(candidate[i] == charStack.top()){ //compare balk half to front utilizing stack, FILO matches palindromic pattern
				}
				else{
					return false; //mismatch results in negation
				}
				charStack.pop(); //prep for next comparison
			}
		}
		else{	
			for(int i = 0; i<length/2;i++){
				charStack.push(candidate[i]); //add chars onto stack including middle char
			}
			//middle character is ignored for odd length palindromes
			for(int i = length/2+1; i<length;i++){
				if(candidate[i] != charStack.top()){
					return false; //If mismatch occurs then return false
				}
				charStack.pop(); //prepare for next comparison
			}
		}
		return true; //must be validated with no mismatches to reach here
	}
};

