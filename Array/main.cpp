#include "Array.h"
#include <iostream>

int main()
{
	int a[] = { 1, 2, 5, 4, 0, 6, 2, 8 };

	int len = sizeof(a) / sizeof(a[0]);

	Array arr(a, len, len);

	arr.insert(4, 5);

	std::cout << arr.size() << " " << arr.length();




	return 0;
}