//Created by Brandon Barnes

#include <iostream> //for couts

using namespace std;

void profitMaximization(int array[], int size){
	bool profitPossible = false;
	bool currentlyProfitable = false;
	
	if(size < 2){
		cout << "No Profit Possible" << endl;
		return;
	}
	
	for(int i = 0; i<size-1; i++){
		if(array[i]<array[i+1]){
			profitPossible=true;
			if(currentlyProfitable!=true){
				currentlyProfitable = true;
				cout << "(" << i;
			}
			
		}
		else{
			if(currentlyProfitable){
				currentlyProfitable = false;
				cout << " " << i << ") "; 
			}
		}
	}
	if(currentlyProfitable){
		if(array[size-1] > array[size-2]){
			cout << " " << size-1 << ") ";
		}
		else{
			cout << " " << size-2 << ") "; 
		}
	}
	if(!(profitPossible)){
		cout << "No Profit Possible" << endl;
	}
	
	return;
}

int main(){
	int array[] = {23, 13, 25, 29, 33, 19, 34, 45, 65, 67};
	
	profitMaximization(array, 10);
	
	return 0;
}