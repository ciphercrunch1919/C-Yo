#include <iostream>
using namespace std;

int detwo(int num){
	int count = 0;
	
	while(num >= 2) {
	count += 1;
	num /= 2;
	}
	return count;
	
	}


	
int main() 
{
	int x;
	cout << "Enter a value: ";
	cin >> x;
	cout << "That number is divisible by 2 by a count of " << detwo(x) << " times." << endl;
	return 0;

}
