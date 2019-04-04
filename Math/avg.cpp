#include <iostream>
using namespace std;

int main()
{ 
	int max = 0, min = 1, num, sum = 0;
	float avg;
	int count, total;
	
	cout << "How many numbers do you want to enter?: ";
	cin >> count;
	total = count;
	
	while(count > 0){
		cout << "Enter a number: "; 
		cin >> num;
		max = (num > max)?num:max;
		min = (num < min)?num:min;
		sum+=num;
		count--;
	}
	avg = float(sum)/float(total);
	cout << "minimum: " << min << endl;
	cout << "maximum: " << max << endl;
	cout << "average: " << avg << endl;
	
return 0;
}
