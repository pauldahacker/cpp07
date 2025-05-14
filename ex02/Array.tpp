#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>
# include <cstddef>
# include <stdexcept>

/*
https://en.cppreference.com/w/cpp/error/out_of_range

*/
template<typename T>
class Array {
	public:
		// No parameter construction
		Array(void) : _n(0), _array(NULL)
		{
			std::cout << "Created empty Array" << std::endl;
		}
		// Construction with one parameter (n)
		Array(unsigned int n) : _n(n), _array(new T[n])
		{
			std::cout << "Created Array with size " << size() << std::endl;
		}
		// Copy construction
		Array(const Array &other) : _n(other.size()), _array(new T[other.size()])
		{
			for (unsigned int i = 0; i < size(); ++i)
				this->_array[i] = other[i];
			*this = other;
			std::cout << "Copied Array with size " << size() << std::endl;
		}
		// Destructor
		~Array(void)
		{
			std::cout << "Destructor called for Array with size " << size() << std::endl;
			if (this->_array)
				delete[] this->_array;
		}

		// Assignment operator overload
		const Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				delete[] this->_array;
				this->_n = other.size();
				this->_array = new T[other.size()];
				for (unsigned int i = 0; i < other.size(); ++i)
					this->_array[i] = other[i];
			}
			return (*this);
		}
		// Subscript operator overloads
		T	&operator[](unsigned int index)
		{
			if (index < size())
				return (this->_array[index]);
			throw (std::out_of_range("Index is out of bounds!"));
		}
		const T	&operator[](unsigned int index) const
		{
			if (index < size())
				return (this->_array[index]);
			throw (std::out_of_range("Index is out of bounds"));
		}

		// Member function
		unsigned int	size(void) const
		{
			return (this->_n);
		}

	private:
		unsigned int	_n;
		T				*_array;
};

#endif