//Created by Brandon Barnes




#include <iostream> //for example display


int dumbSelect(int arr1[], int arr2[], int sizeOne, int sizeTwo){
	//assumes arrays are already properly sorted
	int maxPossible = 1; //Can always take 1st
	int lastTaken = 0;
	if(sizeOne != sizeTwo || sizeOne < 1){
		return -1;
	}
	
	for(int i=1; i<sizeOne; i++){
		if(arr2[lastTaken]<=arr1[i]){ //set to pure less than if exclusivity in end of one activity and start of another is needed, flip turns and make > if speed needed
			lastTaken = i;
			maxPossible+=1;
		}
	}
	return maxPossible;

}

using namespace std;


int main(){
	int arr1[] = {1,2,3,4,5,6};
	int arr2[] = {3,4,5,6,7,8};
	int sizeOne = sizeof(arr1)/sizeof(arr1[0]);
	
	int sizeTwo = sizeof(arr2)/sizeof(arr2[0]);
	
	cout << dumbSelect(arr1, arr2, sizeOne, sizeTwo) << endl;
}