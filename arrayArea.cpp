//Created by Brandon Barnes

//Higher the int the higher the hills
//ends of array (positions less than 0 or greater than size) are considered dead and will not act as walls

#include <iostream>

using namespace std;

int arrayArea(int array[], int size){
	int totalArea = 0;
	int leftWallPosition;
	int leftWallHeight;
	int rightWallPosition;
	int rightWallHeight;
	bool leftHigher = false;
	bool areEqual = true;
	int tempIterator = 2;
	int leftIterator = 1;
	int rightIterator = size-2;
	bool leftHasPit = false;
	bool rightHasPit = false;
	
	
	if(size<1 || array == NULL){
		return -1;
	}
	if(size < 3){
		return 0;
	}
	
	leftWallPosition = 0;
	rightWallPosition = size-1;
	leftWallHeight = array[0];
	rightWallHeight = array[size-1];
	
	while(rightWallPosition>leftWallPosition && leftIterator<size && rightIterator >-1){
		if(leftWallHeight<=array[leftIterator]){ //tempRight is >= leftWall,  place leftWall to be at leftIterator once done with if
			if(leftHasPit){ //there is space for holding, so must update totalArea
				
				for(int i = leftWallPosition; i<leftIterator;i++){
					totalArea = totalArea + (leftWallHeight - array[i]);
				}
				leftHasPit = false;  //update for there being no pit after above loop and following updates to leftWallHeight and leftWallPosition
			}
			leftWallHeight = array[leftIterator];
			leftWallPosition=leftIterator;
			
		}
		else if(leftWallPosition < leftIterator){ //leftwall greater than tempRight 
			leftHasPit = true;
		}
		
		leftIterator++; //regardless of result of above leftIterator is updated to next possible position
		if(leftWallPosition >= rightWallPosition){ //means that update for leftWallPosition has covered pit made with rightWall, this avoids double counting said pit
			break;
		}
		if(rightWallHeight<=array[rightIterator]){
			if(rightHasPit){
				for(int i = rightWallPosition; i > rightIterator; i--){
					totalArea = totalArea + (rightWallHeight - array[i]);
				}
				
				rightHasPit = false;
			}
			
			rightWallHeight = array[rightIterator];
			rightWallPosition = rightIterator;
		}
		else{
			rightHasPit = true;
		}
		rightIterator--; //regardless of outcome rightIterator is updated to next position
	}
	
	return totalArea;
}

int main(){
	int temp = 0;
	int size = 6;
	int array[] = {0, 7, 3, 0, 0, 7};
	
	temp = arrayArea(array, size);
	
	cout << temp << endl;
	return 0;
}