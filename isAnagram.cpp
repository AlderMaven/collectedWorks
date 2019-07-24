//Created by Brandon Barnes

#include <string>
#include <iostream>
#include <locale>

using namespace std;

int charValue(char arg){
	char temp = tolower(arg); //make case insensitive
	
	switch(temp){
		case 'a': return 0; break;
		case 'b': return 1; break;
		case 'c': return 2; break;
		case 'd': return 3; break;
		case 'e': return 4; break;
		case 'f': return 5; break;
		case 'g': return 6; break;
		case 'h': return 7; break;
		case 'i': return 8; break;
		case 'j': return 9; break;
		
		case 'k': return 10; break;
		case 'l': return 11; break;
		case 'm': return 12; break;
		case 'n': return 13; break;
		case 'o': return 14; break;
		case 'p': return 15; break;
		case 'q': return 16; break;
		case 'r': return 17; break;
		case 's': return 18; break;
		case 't': return 19; break;
		
		case 'u': return 20; break;
		case 'v': return 21; break;
		case 'w': return 22; break;
		case 'x': return 23; break;
		case 'y': return 24; break;
		case 'z': return 25; break;
		default: return -1;
	}
	
}

bool isAnagram(string s1, string s2){
	
	if(s1.size() != s2.size()){
		return false;
	}
	int s1CharCount[26] = {0};
	int s2CharCount[26] = {0};
	int size = s1.size();
	int temp = 0;
	for(int i = 0; i<size; i++){
		
		temp = charValue(s1[i]);
		if(temp == -1){
			return false;
		}
		s1CharCount[temp] = s1CharCount[temp]+1;
		
		temp = charValue(s2[i]);
		if(temp == -1){
			return false;
		}
		s2CharCount[temp] = s2CharCount[temp]+1;
	}
	for(int i = 0; i<26;i++){
		if(s1CharCount[i] != s2CharCount[i]){
			return false;
		}
	}
	
	
	return true;
}

int main(){
	string s1 = "anagram";
	string s2 = "aGraman";
	
	cout << isAnagram(s1, s2) << endl;
	
	
	return 0;
}