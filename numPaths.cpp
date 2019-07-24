//Created by Brandon Barnes

//Returns number of paths from top left to bottom right only moving right or down from a given cell
//Will not operate properly on jagged matrices

#include <iostream>
#include <vector>

using namespace std;

int numPaths(vector<vector<int> > matrix){
	int returnInt = 0;
	int temp = 0;
	int temp2 = 0;
	
	if(matrix.size()==0){
		return 0;
	}
	else if(matrix[0].size()==0){
		return 0;
	}
	else if(matrix.size()<matrix[0].size()){
		
		temp = matrix.size();
		for(int i = 0; i<temp;i++){
			matrix[0][i]=1;
			matrix[i][0]=1;
		}
		
		temp = matrix[0].size();
		for(int i = matrix.size(); i<temp; i++){
			matrix[0][i]=1;
		}
		
		
		temp2=matrix.size();
		for(int i=1; i<temp2; i++){
			
			for(int j = 1; j<temp;j++){
				matrix[i][j] = matrix[i-1][j]+matrix[i][j-1];
			}
		}
		returnInt = matrix[temp2-1][temp-1]; //assign value from bottom right cell
	}
	else{ //matrix.size()>=matrix[0].size()
		temp = matrix[0].size();
		for(int i = 0; i<temp; i++){
			matrix[0][i]=1;
			matrix[i][0]=1;
		}
		
		
		temp = matrix.size();
		for(int i = matrix[0].size(); i<temp;i++){
			matrix[i][0] =1;
		}
		
		
		temp2 = matrix[0].size();
		for(int i = 1; i<temp; i++){
			
			for(int j = 1; j<temp2;j++){
				matrix[i][j] = matrix[i-1][j]+matrix[i][j-1];
			}
		}
		returnInt = matrix[temp-1][temp2-1]; //assign value from bottom right cell
	}
	
	
	return returnInt;
}

int main(){
	vector<vector<int> > matrix(2, vector<int>(8));
	
	
	cout << numPaths(matrix) << endl;
	
	
	
	
	return 0;
}