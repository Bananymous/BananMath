#pragma once

#include <random>
#include <type_traits>

namespace Banan
{
	static std::mt19937 s_gen;

	template<typename T>
	typename std::enable_if<std::is_integral<T>::value, T>::type get_random_uniform(T min, T max)
	{
		std::uniform_int_distribution dist(min, max);
		return dist(s_gen);
	}

	template<typename T>
	typename std::enable_if<std::is_floating_point<T>::value, T>::type get_random_uniform(T min, T max)
	{
		std::uniform_real_distribution dist(min, max);
		return dist(s_gen);
	}


	template<typename T>
	typename std::enable_if<std::is_floating_point<T>::value, T>::type get_random_normal(T mean, T std)
	{
		std::normal_distribution<T> dist(mean, std);
		return dist(s_gen);
	}

}