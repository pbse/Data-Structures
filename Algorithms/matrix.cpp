// Spiral Print of a Matrix
/*
	Input - 1 2 3 4
			5 6 7 8
			9 0 1 2

	Output - 1 2 3 4 8 2 1 0 9 5 6 7 1 0

*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > matrix;

void spiralprint() {

	int check = 0;
	int len = matrix[0].size();
	int col = matrix.size();
	int temp = len/2;
	int i=0;
	int j = 0;
	//cout<<col;
	while(check<=temp) {
		if(check==temp && check%2==0) break;
		//Printing Top Side
		for(i=check;i<len;i++) {
			cout<<matrix[j][i]<<" ";
		}
		// Printing Right Side Top To Bottom
		for(i=check+1;i<col;i++) {
			cout<<matrix[i][len-1]<<" ";
		}

		//Printing Bottom Side
		for(i=len-2;i>=check;i--) {
			cout<<matrix[len-1][i]<<" ";
		}

		// Printing Left Side Bottom To Top
		for(i=len-2;i>=check+1;i--) {
			cout<<matrix[i][j]<<" ";
		}
		check++;
		j++;
		len--;
		col--;
		cout<<endl;
	}
}

int main() {

	int i,j;
	for(i=0;i<4;i++) {
		matrix.push_back(vector<int>() );
		for(j=i;j<i+4;j++) {
			matrix[i].push_back(j*i + j);
		}
	}
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}

	spiralprint();

	return 0;
}
