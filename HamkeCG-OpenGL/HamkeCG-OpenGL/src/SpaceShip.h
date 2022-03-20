#pragma once
#include "Core.h"
#include "Quad.h"
#include "Triangle.h"
namespace HamkeCG {
	class SpaceShip {
	public:
		// Requires 
		SpaceShip(std::string_view fileName);
		SpaceShip(std::vector<std::vector<sPoints3f>> points3f) :
			m_Points3f(points3f){}

		SpaceShip(std::vector<std::vector<sPoints3f>> points3f, std::vector<std::vector<sColors3f>> colors3f) :
			m_Points3f(points3f), m_Colors3f(colors3f){}

		void Draw();
		void Scale(sPoints3f scaleFactor);
		void Translate(sPoints3f translateFactor );
		void Colored(std::vector<std::vector<sColors3f>>* colors3f);
		void RandomlyColored();
		void ReadCSV(std::string_view fileName, std::vector<std::vector<sPoints3f>>& points3f,
			std::vector<std::vector<sColors3f>>& colors3f);
		std::vector <float>& getCoordBucket() { return coordBucket; }
		std::vector<bool>& getShapes() { return shape; }
		int getGeomNumber() { return shape.size(); }
	private:
		std::vector < std::vector <sColors3f>> m_Colors3f;
		std::vector < std::vector <sPoints3f>> m_Points3f;
		std::vector <std::vector <sPoints3f>>::iterator pOuterIt;
		std::vector <std::vector <sColors3f>>::iterator cOuterIt;
		std::vector<sPoints3f>::iterator pInnerIt;
		std::vector<sColors3f>::iterator cInnerIt;
		std::vector<bool> shape;
		std::vector <float> coordBucket;
		std::vector<bool>::iterator shapeIt;
		std::vector<float>::iterator coordIt;
	};
}
