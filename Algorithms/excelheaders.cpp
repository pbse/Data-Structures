// Simple Program to Generate Excel Sheet Headers

#include <iostream>
#include <list>
using namespace std;

void excel(int n) {

	for(int i=0; i<=n;i++) {
		int check = i;
		std::list<char> cap;

		while(check>=0) {
			char c = 'a' + (check%26);
			cap.push_front(c);
			check = (check/26) - 1;
		}
		std::list<char>::const_iterator a;
		for (a = cap.begin(); a != cap.end(); ++a)
		    std::cout << *a;
		std::cout<<" at "<< i << endl;
	}
}

int main() {
	cout<<"Enter The Number"<<endl;
	int a;
	cin>>a;
	excel(a);
	return 0;
}
