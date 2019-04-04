#include <iostream>
using namespace std;

bool isPerfect(int n){
    int sum = 1;
    for (int i=2; i*i<=n; i++)
        if (n%i==0)
            sum = sum + i + n/i;
     if (sum == n && n != 1){
		 return true;
	 }
     else{
		 return false;
	 }
}
int main(){
	int num;
	while(num <= 9999){
		if (isPerfect(num)){
			cout << num << " is a perfect number." << endl;
		}
		num ++;
	}
return 0;
}
