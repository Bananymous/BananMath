#pragma once

#include "pcg/pcg_random.hpp"

#include <random>
#include <type_traits>

namespace Banan
{
	static pcg32_fast s_pcg32_fast;

	static void seed_generator()
	{
		s_pcg32_fast.seed(pcg_extras::seed_seq_from<std::random_device>());
	}

	template<typename T>
	typename std::enable_if<std::is_integral<T>::value, T>::type get_random_uniform(T min = T(0), T max = T(1))
	{
		std::uniform_int_distribution dist(min, max);
		return dist(s_pcg32_fast);
	}

	template<typename T>
	typename std::enable_if<std::is_floating_point<T>::value, T>::type get_random_uniform(T min = T(0), T max = T(1))
	{
		std::uniform_real_distribution dist(min, max);
		return dist(s_pcg32_fast);
	}

	template<typename T>
	typename std::enable_if<std::is_floating_point<T>::value, T>::type get_random_normal(T mean, T std)
	{
		std::normal_distribution<T> dist(mean, std);
		return dist(s_pcg32_fast);
	}

}