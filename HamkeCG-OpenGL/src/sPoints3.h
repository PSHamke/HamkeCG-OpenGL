#pragma once
#include "Core.h"
template <typename T>
class sPoints3 {
public:
	sPoints3(T X, T Y, T Z) :
		x(X), y(Y), z(Z) {};
	sPoints3() = default;
	
	sPoints3 operator -()const {
		return sPoints3(-x, -y, -z);
	}
	sPoints3 operator =(const sPoints3& sP) {
		CG_CORE_INFO("sP = &sP");
		x = sP.x;
		y = sP.y;
		z = sP.z;
		return *this;
	}
	sPoints3 operator +=(const sPoints3& sP){
		x += sP.x;
		y += sP.y;
		z += sP.z;
		return *this;
	}
	sPoints3 operator -=(const sPoints3& sP) {
		x -= sP.x;
		y -= sP.y;
		z -= sP.z;
		return *this;
	}
	sPoints3 operator *=(const T& sP) {
		CG_CORE_INFO("Sp *= T");
		x *= sP;
		y *= sP;
		z *= sP;
		return *this;
	}
	sPoints3 operator /=(const T& sP) {
		x /= sP;
		y /= sP;
		z /= sP;
		return *this;
	}
	T operator *(const sPoints3& sP) {
		CG_CORE_INFO("sP * sP");
		return x * sP.x + y * sP.y + z * sP.z;
	}
	sPoints3 operator *(const T& sP) {
		CG_CORE_INFO("sP * T");
		return sPoints3(x * sP, y * sP, z * sP);
	}
	sPoints3 operator /(const T& sP) {
		return sPoints3(x / sP, y / sP, z / sP);
	}
	
	bool operator ==(const sPoints3& sP) {
		return x == sP.x && y == sP.y && z == sP.z;
	}
	bool operator != (const sPoints3& sP) {
		return !(*this == sP);
	}
	
	T x, y, z;
};




template <typename T>
class sColors{
public:
	sColors(T X, T Y, T Z) :
		x(X), y(Y), z(Z) {};

	sColors(){}
	T x, y, z;
};