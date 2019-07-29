//Created by Brandon Barnes
//Based on example from: https://stackoverflow.com/questions/23063074/how-to-create-a-lookup-table 



#include <iostream> //for example display


using namespace std;


typedef void (*selectedOutcome)();

void outcomeOne(){
	cout << "testing outcome 1" <<endl;
}

void outcomeTwo(){
	cout << "testing outcome 2" <<endl;
}

void outcomeThree(){
	cout << "testing outcome 3" <<endl;
}

selectedOutcome outcomes[] = {
	outcomeOne, outcomeTwo, outcomeThree
};

int main(){
	
	outcomes[0]();
	outcomes[1]();
	outcomes[2]();
	
	cout << "exiting" << endl;
	return 0;
}