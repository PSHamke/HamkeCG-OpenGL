#pragma once
struct sPoints3f {
	sPoints3f(float X, float Y, float Z) :
		x(X), y(Y), z(Z) {};
	sPoints3f(){}
	float x, y, z;
};

struct sColors3f {
	sColors3f(float X, float Y, float Z) :
		x(X), y(Y), z(Z) {};

	sColors3f(){}
	float x, y, z;
};