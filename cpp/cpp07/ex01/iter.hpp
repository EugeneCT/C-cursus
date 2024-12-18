
# include<iostream>

template<typename T_array, typename T_function>
void iter(T_array *array, size_t len, T_function func)
{
	for (size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

template <typename T_function>
void times_two(int &x) {
    x= (2 * x);  // Multiply int by 2
}