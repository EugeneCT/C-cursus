#pragma once
# include<iostream>

template<typename T>
void swap(T &first, T &sec)
{
	T tmp = first;
	first = sec;
	sec = tmp;
}

template<typename T>
T min(const T &first, const T &sec)
{
	if (first < sec)
		return (first);
	else
		return (sec);
}

template<typename T>
T max(const T &first, const T &sec)
{
	if (first > sec)
		return (first);
	else
		return (sec);
}
