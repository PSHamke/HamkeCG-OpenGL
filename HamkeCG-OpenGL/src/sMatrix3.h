#pragma once
#include "sPoints3.h"

template <typename T> 
class  sMatrix3{

public:
	T elements[3][3];
	
	sMatrix3 operator* ( const sMatrix3& rhs) const {
		sMatrix3 result;
		for (size_t j = 0; j < 3; j++)
		{
			for (size_t k = 0; k < 3; k++)
			{
				T sum = (T)0.0;
				for (size_t i = 0; i < 3; i++)
				{
					sum += elements[j][i] * rhs.elements[i][k];
				}
				result.elements[j][k] = sum;
			}
		}
		return result;
	}
	
	
	static sMatrix3 RotationZ(T theta) { 

		const T sinTheta = sin(theta);
		const T cosTheta = cos(theta);

		return {
			cosTheta, -sinTheta, (T)0.0,
			sinTheta, cosTheta, (T)0.0,
			(T)0.0, (T)0.0, (T)1.0
		};
	}	
	
	static sMatrix3 RotationY(T theta) { // Rotate around Y

		const T sinTheta = sin(theta);
		const T cosTheta = cos(theta);

		return {
			cosTheta, (T)0.0, -sinTheta,
			(T)0.0, (T)1.0, (T)0.0,
			sinTheta, (T)0.0, cosTheta
		};
	}
	
	static sMatrix3 RotationX(T theta) { // Rotate around X
		const T sinTheta = sin(theta);
		const T cosTheta = cos(theta);

		return {
			(T)1.0,(T)0.0, T(0.0),
			(T)0.0, cosTheta, sinTheta,
			(T)0.0, -sinTheta, cosTheta
		};
	}
};
	
template <typename T>
sPoints3<T>& operator*=(sPoints3<T>& lhs, sMatrix3<T> rhs) {
	return lhs = lhs * rhs;
}

template <typename T>
sPoints3<T> operator* (const sPoints3<T>& lhs, const sMatrix3<T>& rhs) {
	return {
		lhs.x * rhs.elements[0][0] + lhs.y * rhs.elements[1][0] + lhs.z * rhs.elements[2][0],
		lhs.x * rhs.elements[0][1] + lhs.y * rhs.elements[1][1] + lhs.z * rhs.elements[2][1],
		lhs.x * rhs.elements[0][2] + lhs.y * rhs.elements[1][2] + lhs.z * rhs.elements[2][2]
	};
}

