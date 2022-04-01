#pragma once
#include "sMatrix3.h"
#include "Core.h"
namespace HamkeCG {
	
	template <typename T>
	class GeomShapes {
	public: 
		GeomShapes() = default;
		GeomShapes(std::vector<std::vector<sPoints3<T>>> points3f) :
			m_Points3f(points3f) {}

		GeomShapes(std::vector<std::vector<sPoints3<T>>> points3f, std::vector<std::vector<sColors<T>>> colors3f) :
			m_Points3f(points3f), m_Colors3f(colors3f) {}
		void Scale(sPoints3<T> scaleFactor);
		void Translate(const sPoints3<T>& translateFactor);
		void Rotate(const sMatrix3<T>& rotM, sPoints3<T> rotateCenter);
	
	protected:
		std::vector < std::vector <sColors<T>>> m_Colors3f;
		std::vector < std::vector <sPoints3<T>>> m_Points3f;
		typename std::vector <std::vector <sPoints3<T>>>::iterator pOuterIt;
		typename std::vector <std::vector <sColors<T>>>::iterator cOuterIt;
		typename std::vector<sPoints3<T>>::iterator pInnerIt;
		typename std::vector<sColors<T>>::iterator cInnerIt;
	};
	
	
}