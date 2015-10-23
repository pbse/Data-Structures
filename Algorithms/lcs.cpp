#include <iostream>
#include <string>
using namespace std;

int max(int a, int b) {
	return a>b ? a : b;
}

// Function for all types of array.
template <typename T>
void lcs(T a[], T b[], int n, int m) {
	int arr[n+1][m+1];
	int i,j;
	for(i=0;i<=n;i++) {
		for(j=0;j<=m;j++) {
			if(i==0 || j==0) arr[i][j] = 0;
			else if(a[i-1] == b[j-1]) arr[i][j] = 1 + arr[i-1][j-1];
				else arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
		}
	}
	cout<<arr[n][m]<<endl;
	int total = arr[n][m];
	T c[total];
	i=n;j=m;
	int temp = total;
	while(i>0 && j>0) {
		if(a[i-1]==b[j-1]) {
			c[total-1] = a[i-1];
			i--; j--; total--;
		}
		else if (arr[i-1][j] > arr[i][j-1]) {
			i--;
		}
		else j--;
	}

	for(i=0;i<temp;i++) {
		cout<<c[i]<<", ";
	}
	cout<<endl;

}


int main() {
	int a[] = {1,2,3,4,5,6,7};
	int b[] = {2,3,4,5,6,7,7};
	lcs(a,b,7,7);
	// Test For character
	char x[] = "ABCDEFGHI";
	char y[] = "ABVCDGGJHHS";
	int a1 = std::char_traits<char>::length(x);
	int a2 = std::char_traits<char>::length(y);
	lcs(x,y,a1, a2);
	// Test for String
	// Make Sure for String, The Function arguments should be T a and not T a[]
	std::string q = "qwertyusss";
	std::string w = "ertyuiopjgdfdds";
	int l1 = q.length();
	int l2 = w.length();
	lcs(q,w,l1,l2);
	return 0;
}
