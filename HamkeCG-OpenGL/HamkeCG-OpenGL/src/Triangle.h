#pragma once
#include "Core.h"

#include "Primitives.h"

namespace HamkeCG {
	class Triangle {
	public:
		Triangle(std::vector <sPoints3f> points3f, std::vector <sColors3f> colors3f) :
			m_Points3f(points3f), m_Colors3f(colors3f) {}

		void Draw();
		//static void Draw(std::vector <sPoints3f> points3f, std::vector <sColors3f> colors3f);
	private:
		std::vector <sPoints3f> m_Points3f;
		std::vector <sColors3f> m_Colors3f;
		std::vector<sPoints3f>::iterator pIt;
		std::vector<sColors3f>::iterator cIt;
	};
}
