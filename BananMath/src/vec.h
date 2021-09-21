#pragma once

#include <cmath>
#include <cstdint>

#include "random.h"

namespace Banan
{

	template<typename Ty, uint32_t Size>
	class vec;

	/* #################### 2d Vector Definiton #################### */
	
	template<typename Ty>
	class vec<Ty, 2>
	{
	public:
		union
		{
			Ty value[2];
			struct { Ty x, y; };
		};

	public:
		// Constructors
		vec<Ty, 2>()
			: x(Ty(0)), y(Ty(0))
		{ }
		vec<Ty, 2>(const Ty& x, const Ty& y)
			: x(x), y(y)
		{ }

		// Unary operators
		vec<Ty, 2> operator+() const
		{
			return vec<Ty, 2>(x, y);
		}
		vec<Ty, 2> operator-() const
		{
			return vec<Ty, 2>(-x, -y);
		}

		// Assignment operators
		vec<Ty, 2>& operator =(const vec<Ty, 2>& v)
		{
			x = v.x;
			y = v.y;
			return *this;
		}
		vec<Ty, 2>& operator+=(const vec<Ty, 2>& v)
		{
			x += v.x;
			y += v.y;
			return *this;
		}
		vec<Ty, 2>& operator-=(const vec<Ty, 2>& v)
		{
			x -= v.x;
			y -= v.y;
			return *this;
		}
		vec<Ty, 2>& operator*=(const Ty& val)
		{
			x *= val;
			y *= val;
			return *this;
		}
		vec<Ty, 2>& operator/=(const Ty& val)
		{
			x /= val;
			y /= val;
			return *this;
		}

		// Other vector operators
		Ty dot(const vec<Ty, 2>& v)	const
		{
			return x * v.x + y * v.y;
		}
		Ty magSq()					const
		{
			return x * x + y * y;
		}
		Ty mag()					const
		{
			return std::sqrt(magSq());
		}
		vec<Ty, 2>& normalize()
		{
			return *this /= mag();
		}

		// Random vectors
		static vec<Ty, 2> random(Ty min, Ty max)
		{
			return vec<Ty, 2>(
				get_random_uniform<Ty>(min, max),
				get_random_uniform<Ty>(min, max)
			);
		}
		static vec<Ty, 2> random()
		{
			vec<Ty, 2> res(
				get_random_normal<Ty>(Ty(0), Ty(1)),
				get_random_normal<Ty>(Ty(0), Ty(1))
			);
			return res.normalize();
		}
		static vec<Ty, 2> random_in_unit_disc()
		{
			vec<Ty, 2> res = random(Ty(-1), Ty(1));
			while(res.magSq() > 1.0)
				res = random(Ty(-1), Ty(1));
			return res;
		}

	};

	/* #################### 3d Vector Definiton #################### */

	template<typename Ty>
	class vec<Ty, 3>
	{
	public:
		union
		{
			Ty values[3];
			struct { Ty x, y, z; };
			struct { Ty r, g, b; };
		};

	public:
		// Constructors
		vec<Ty, 3>()
			: x(Ty(0)), y(Ty(0)), z(Ty(0))
		{ }
		vec<Ty, 3>(const Ty& x, const Ty& y, const Ty& z)
			: x(x), y(y), z(z)
		{ }

		// Unary operators
		vec<Ty, 3> operator+() const
		{
			return vec<Ty, 3>(x, y, z);
		}
		vec<Ty, 3> operator-() const
		{
			return vec<Ty, 3>(-x, -y, -z);
		}

		// Assignment operators
		vec<Ty, 3>& operator =(const vec<Ty, 3>& v)
		{
			x = v.x;
			y = v.y;
			z = v.z;
			return *this;
		}
		vec<Ty, 3>& operator+=(const vec<Ty, 3>& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}
		vec<Ty, 3>& operator-=(const vec<Ty, 3>& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}
		vec<Ty, 3>& operator*=(const Ty& val)
		{
			x *= val;
			y *= val;
			z *= val;
			return *this;
		}
		vec<Ty, 3>& operator/=(const Ty& val)
		{
			x /= val;
			y /= val;
			z /= val;
			return *this;
		}

		// Other vector operators
		Ty dot(const vec<Ty, 3>& v)	const
		{
			return x * v.x + y * v.y + z * v.z;
		}
		Ty magSq()					const
		{
			return x * x + y * y + z * z;
		}
		Ty mag()					const
		{
			return std::sqrt(magSq());
		}
		vec<Ty, 3>& normalize()
		{
			if (magSq() == 0.0)
				return *this;
			return *this /= mag();
		}

		// Cross product
		vec<Ty, 3> cross(const vec<Ty, 3>& v) const
		{
			return vec<Ty, 3>(
				y * v.z - z * v.y,
				z * v.x - x * v.z,
				x * v.y - y * v.x
			);
		}

		// Random vectors
		static vec<Ty, 3> random(Ty min, Ty max)
		{
			return vec<Ty, 3>(
				get_random_uniform<Ty>(min, max),
				get_random_uniform<Ty>(min, max),
				get_random_uniform<Ty>(min, max)
			);
		}
		static vec<Ty, 3> random()
		{
			vec<Ty, 3> vec(
				get_random_normal<Ty>(Ty(0), Ty(1)),
				get_random_normal<Ty>(Ty(0), Ty(1)),
				get_random_normal<Ty>(Ty(0), Ty(1))
			);
			return vec.normalize();
		}
		static vec<Ty, 3> random_in_unit_sphere()
		{
			vec<Ty, 3> res = vec<Ty, 3>::random(Ty(-1), Ty(1));
			while (res.magSq() > 1.0)
				res = vec<Ty, 3>::random(Ty(-1), Ty(1));
			return res;
		}

	};

	/* #################### 4d Vector Definiton #################### */

	template<typename Ty>
	class vec<Ty, 4>
	{
	public:
		union
		{
			Ty values[4];
			struct { Ty x, y, z, w; };
			struct { Ty r, g, b, a; };
		};

	public:
		// Constructors
		vec<Ty, 4>()
			: x(Ty(0)), y(Ty(0)), z(Ty(0)), w(Ty(0))
		{ }
		vec<Ty, 4>(const Ty& x, const Ty& y, const Ty& z, const Ty& w)
			: x(x), y(y), z(z), w(w)
		{ }

		// Unary operators
		vec<Ty, 4> operator+() const
		{
			return vec<Ty, 4>(x, y, z, w);
		}
		vec<Ty, 4> operator-() const
		{
			return vec<Ty, 4>(-x, -y, -z, -w);
		}

		// Assignment operators
		vec<Ty, 4>& operator =(const vec<Ty, 4>& v)
		{
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;
			return *this;
		}
		vec<Ty, 4>& operator+=(const vec<Ty, 4>& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			w += v.w;
			return *this;
		}
		vec<Ty, 4>& operator-=(const vec<Ty, 4>& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			w -= v.w;
			return *this;
		}
		vec<Ty, 4>& operator*=(const Ty& val)
		{
			x *= val;
			y *= val;
			z *= val;
			w *= val;
			return *this;
		}
		vec<Ty, 4>& operator/=(const Ty& val)
		{
			x /= val;
			y /= val;
			z /= val;
			w /= val;
			return *this;
		}

		// Other vector operators
		Ty dot(const vec<Ty, 4>& v) const
		{
			return x * v.x + y * v.y + z * v.z + w * v.w;
		}
		Ty magSq() const
		{
			return x * x + y * y + z * z + w * w;
		}
		Ty mag() const
		{
			return std::sqrt(magSq());
		}
		vec<Ty, 4>& normalize()
		{
			return *this /= mag();
		}

		// Random vectors
		static vec<Ty, 4> random(Ty min, Ty max)
		{
			return vec<Ty, 4>(
				get_random_uniform<Ty>(min, max),
				get_random_uniform<Ty>(min, max),
				get_random_uniform<Ty>(min, max),
				get_random_uniform<Ty>(min, max)
			);
		}
		static vec<Ty, 4> random()
		{
			vec<Ty, 4> res(
				get_random_normal<Ty>(Ty(0), Ty(1)),
				get_random_normal<Ty>(Ty(0), Ty(1)),
				get_random_normal<Ty>(Ty(0), Ty(1)),
				get_random_normal<Ty>(Ty(0), Ty(1))
			);
			return res.normalize();
		}

	};


	/* ################### 5d+ Vector Definiton #################### */

	template<typename Ty, uint32_t Size>
	class vec
	{
	public:
		Ty values[Size]{};

	public:
		vec() = default;
		

		// Unary operators
		vec<Ty, Size> operator+() const
		{
			return *this;
		}
		vec<Ty, Size> operator-() const
		{
			vec<Ty, Size> result = *this;
			for (int i = 0; i < Size; i++)
				result.values[i] = -result.values[i];
			return result;
		}

		// Assignment operators
		vec<Ty, Size>& operator =(const vec<Ty, Size>& v)
		{
			for (int i = 0; i < Size; i++)
				values[i] = v.values[i];
			return *this;
		}
		vec<Ty, Size>& operator+=(const vec<Ty, Size>& v)
		{
			for (int i = 0; i < Size; i++)
				values[i] += v.values[i];
			return *this;
		}
		vec<Ty, Size>& operator-=(const vec<Ty, Size>& v)
		{
			for (int i = 0; i < Size; i++)
				values[i] -= v.values[i];
			return *this;
		}
		vec<Ty, Size>& operator*=(const Ty& val)
		{
			for (int i = 0; i < Size; i++)
				values[i] *= val;
			return *this;
		}
		vec<Ty, Size>& operator/=(const Ty& val)
		{
			for (int i = 0; i < Size; i++)
				values[i] /= val;
			return *this;
		}

		// Other vector operators
		Ty dot(const vec<Ty, Size>& v) const
		{
			Ty result = Ty(0);
			for (int i = 0; i < Size; i++)
				result += values[i] * v.values[i];
			return result;
		}
		Ty magSq() const
		{
			Ty result = Ty(0);
			for (int i = 0; i < Size; i++)
				result += values[i] * values[i];
			return result;
		}
		Ty mag() const
		{
			return std::sqrt(magSq());
		}
		vec<Ty, Size>& normalize()
		{
			return *this /= mag();
		}

		// Random vectors
		static vec<Ty, Size> random(Ty min, Ty max)
		{
			vec<Ty, Size> res;
			for (int i = 0; i < Size; i++)
				res[i] = get_random_uniform<Ty>(min, max);
			return res;
		}
		static vec<Ty, Size> random()
		{
			vec<Ty, Size> res;
			for (int i = 0; i < Size; i++)
				res[i] = get_random_normal<Ty>(Ty(0), Ty(1));
			return res.normalize();
		}

	};


	/* ##################### For All vectors ####################### */

	// Unit vector
	template<typename Ty, uint32_t Size>
	vec<Ty, Size> unit(const vec<Ty, Size>& v)
	{
		vec<Ty, Size> copy = v;
		return copy.normalize();
	}

	// Reflect/Refract vector
	template<typename Ty, uint32_t Size>
	vec<Ty, Size> reflect(const vec<Ty, Size>& v, const vec<Ty, Size>& n)
	{
		return v - Ty(2) * (v * n) * n;
	}
	template<typename Ty, uint32_t Size>
	vec<Ty, Size> refract(const vec<Ty, Size>& v, const vec<Ty, Size>& n, Ty refraction_ratio)
	{
		Ty cos_theta = std::min(-v * n, Ty(1));
		vec<Ty, Size> r_out_prep = refraction_ratio * (v + cos_theta * n);
		vec<Ty, Size> r_out_paral = -std::sqrt(std::abs(Ty(1) - r_out_prep.magSq())) * n;
		return r_out_prep + r_out_paral;
	}

	// Addition/Subtraction of vectors
	template<typename Ty, uint32_t Size>
	vec<Ty, Size> operator+(const vec<Ty, Size>& a, const vec<Ty, Size>& b)
	{
		vec<Ty, Size> copy = a;
		return copy += b;
	}
	template<typename Ty, uint32_t Size>
	vec<Ty, Size> operator-(const vec<Ty, Size>& a, const vec<Ty, Size>& b)
	{
		vec<Ty, Size> copy = a;
		return copy -= b;
	}

	// Multiplying/Dividing vector with scalar
	template<typename Ty, uint32_t Size>
	vec<Ty, Size> operator*(const vec<Ty, Size>& v, const Ty& val)
	{
		vec<Ty, Size> copy = v;
		return copy *= val;
	}
	template<typename Ty, uint32_t Size>
	vec<Ty, Size> operator*(const Ty& val, const vec<Ty, Size>& v)
	{
		vec<Ty, Size> copy = v;
		return copy *= val;
	}
	template<typename Ty, uint32_t Size>
	vec<Ty, Size> operator/(const vec<Ty, Size>& v, const Ty& val)
	{
		vec<Ty, Size> copy = v;
		return copy /= val;
	}

	// Multiplying vector with vector (dot and cross (3d))
	template<typename Ty, uint32_t Size>
	Ty operator*(const vec<Ty, Size>& a, const vec<Ty, Size>& b)
	{
		return a.dot(b);
	}
	template<typename Ty, uint32_t Size>
	Ty dot(const vec<Ty, Size>& a, const vec<Ty, Size>& b)
	{
		return a.dot(b);
	}
	template<typename Ty>
	vec<Ty, 3> cross(const vec<Ty, 3>& a, const vec<Ty, 3>& b)
	{
		return a.cross(b);
	}

	// Multiply elements together
	template<typename Ty, uint32_t Size>
	vec<Ty, Size> elem_mult(const vec<Ty, Size>& a, const vec<Ty, Size>& b)
	{
		vec<Ty, Size> result = a;
		for (int i = 0; i < Size; i++)
			result.values[i] *= b.values[i];
		return result;
	}




	// Definitions for most common vectors
	using vec2i = vec<int32_t,	2>;
	using vec2f = vec<float,	2>;
	using vec2d = vec<double,	2>;

	using vec3i = vec<int32_t,	3>;
	using vec3f = vec<float,	3>;
	using vec3d = vec<double,	3>;

	using vec4i = vec<int32_t,	4>;
	using vec4f = vec<float,	4>;
	using vec4d = vec<double,	4>;

}