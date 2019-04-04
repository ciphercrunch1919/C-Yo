#include <limits>
#include <iostream> 
using namespace std;
int main()
{
    cout << "Size of short : " << sizeof(short) << endl;
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of unsigned int : " << sizeof(unsigned int) << endl;
    cout << "Size of long : " << sizeof(long) << endl;
    cout << "Size of unsigned long : " << sizeof(unsigned long) << endl;
	std::cout << "short\t"
              << std::numeric_limits<short>::min() << '\t' << '\t'
              << std::numeric_limits<short>::max() << endl;
    std::cout << "int\t"
              << std::numeric_limits<int>::min() << '\t'
              << std::numeric_limits<int>::max() << endl;
    std::cout << "unsigned int\t"
              << std::numeric_limits<unsigned int>::min() << '\t'
              << std::numeric_limits<unsigned int>::max() << endl;
    std::cout << "long\t"
              << std::numeric_limits<long>::min() << '\t'
              << std::numeric_limits<long>::max() << endl;
    std::cout << "unsigned long\t"
              << std::numeric_limits<unsigned long>::min() << '\t'
              << std::numeric_limits<unsigned long>::max() << endl;

    return 0;
}
