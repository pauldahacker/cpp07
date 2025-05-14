#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstddef>

// Can modify values
template<typename T>
void	iter(T *array, size_t len, void (*ft)(T &))
{
	for (size_t i = 0; i < len; ++i)
		ft(array[i]);
}

// Read-only
template<typename T>
void	iter(T *array, size_t len, void (*ft)(T const &))
{
	for (size_t i = 0; i < len; ++i)
		ft(array[i]);
}

#endif