#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <ctime>

template<typename T>
T random(T min, T max)
{
	static srand(time(0));
	return (rand() % (max - min + 1)) + min;
}

#endif