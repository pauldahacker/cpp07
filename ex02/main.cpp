#include "Array.tpp"
#include <cmath>
#include "../ex01/iter.hpp"

// << operator overload (for printing tests)
template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T> &array)
{
	out << "size: " << array.size() << ", content: ";
	for (unsigned int i = 0; i < array.size(); ++i)
		out << "[" << array[i] << "] ";
	out << std::endl;
	return (out);
}

int main(void)
{
	std::cout << "----------------------------------------" << std::endl;
	// No parameter construction
	Array<float> empty = Array<float>();
	std::cout << empty;
	std::cout << "----------------------------------------" << std::endl;
	// Construction with one parameter (n)
	Array<float> test = Array<float>(3);
	std::cout << test;
	std::cout << "----------------------------------------" << std::endl;
	// Subscript operator overload []
	test[0] = -0.5;
	test[1] = 0;
	test[2] = 0.5;
	std::cout << test;
	std::cout << "----------------------------------------" << std::endl;
	// Copy construction
	Array<float> testCpy = Array<float>(test);
	std::cout << testCpy;
	testCpy[0] /= 2;
	testCpy[1] /= 2;
	testCpy[2] /= 2;
	std::cout << "Original Array:" << std::endl;
	std::cout << test;
	std::cout << "Copied + modified Array:" << std::endl;
	std::cout << testCpy;
	std::cout << "----------------------------------------" << std::endl;
	// Assignment operator overload
	test = testCpy;
	std::cout << test;
	testCpy[0] *= M_PI;
	testCpy[1] *= M_PI;
	testCpy[2] *= M_PI;
	std::cout << "Original Array:" << std::endl;
	std::cout << testCpy;
	std::cout << "Assigned + modified Array:" << std::endl;
	std::cout << test;
	std::cout << "----------------------------------------" << std::endl;
	// Out of bounds exception
	try
	{
		std::cout << test[3] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	return (0);
}
