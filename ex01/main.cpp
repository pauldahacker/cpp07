#include "iter.hpp"
#include <climits>
#include <cfloat>
#include <string>
#include <cstdlib>

template <typename T>
void	printElem(T &elem)
{
	std::cout << elem << std::endl;
}

int main(void)
{
	bool	bool_array[] = {true, false};
	char	char_array[] = {'P', 'A', 'U', 'L'};
	long long int	llint_array[] = \
		{LLONG_MAX,LLONG_MIN,INT_MAX,INT_MIN,CHAR_MAX,CHAR_MIN,0,1};
	long double	ldb_array[] = \
		{LDBL_MAX,LDBL_MIN,FLT_MAX,FLT_MIN,INT_MAX,INT_MIN,0.8,-0.8};
	std::string	string_array[] = \
		{"Hello", "everybody", "whats up"};
	void	*ptr_array[] = \
		{&llint_array, &ldb_array, &string_array, &bool_array, &char_array};

	std::cout << "BOOL array:" << std::endl;
	::iter(bool_array, 2, printElem);
	std::cout << "-------------------------------" << std::endl;
	std::cout << "CHAR array:" << std::endl;
	::iter(char_array, 4, printElem);
	std::cout << "-------------------------------" << std::endl;
	std::cout << "LONG LONG INT array:" << std::endl;
	::iter(llint_array, 8, printElem);
	std::cout << "-------------------------------" << std::endl;
	std::cout << "LONG DOUBLE array:" << std::endl;
	::iter(ldb_array, 8, printElem);
	std::cout << "-------------------------------" << std::endl;
	std::cout << "STD::STRING array:" << std::endl;
	::iter(string_array, 3, printElem);
	std::cout << "-------------------------------" << std::endl;
	std::cout << "POINTER array:" << std::endl;
	::iter(ptr_array, 5, printElem);
	return (0);
}
