#pragma once

#include <random>

namespace Banan
{

	static std::mt19937 s_generator;
	static std::uniform_real_distribution<double> s_distribution(0.0, 1.0);

	double random()
	{
		return s_distribution(s_generator);
	}

	double random(double min, double max)
	{
		std::uniform_real_distribution<double> distribution(min, max);
		return distribution(s_generator);
	}

}