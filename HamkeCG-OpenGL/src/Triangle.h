#pragma once
#include "Core.h"

#include "sPoints3.h"

namespace HamkeCG {
	template <typename T>
	class Triangle {
	public:
		Triangle(std::vector <sPoints3 <T> > points3f, std::vector <sColors<T>> colors3f) :
			m_Points3f(points3f), m_Colors3f(colors3f) {}

		void Draw();
		//static void Draw(std::vector <sPoints3f> points3f, std::vector <sColors3f> colors3f);
	private:
		std::vector <sPoints3<T>> m_Points3f;
		std::vector <sColors<T>> m_Colors3f;
		typename std::vector<sPoints3<T>>::iterator pIt;
		typename std::vector<sColors<T>>::iterator cIt;
	};
}
