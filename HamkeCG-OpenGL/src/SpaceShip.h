#pragma once
#include "Core.h"
#include "Quad.h"
#include "Triangle.h"
#include "GeomShapes.h"


namespace HamkeCG {
	template <typename T>
	class SpaceShip : public GeomShapes<T> {
	public:
		// Requires 
		SpaceShip(std::string_view fileName) {
			ReadCSV(fileName, m_Points3f, m_Colors3f);
		}
		
		SpaceShip(std::vector<std::vector<sPoints3<T>>> points3f) :
			GeomShapes(points3f){}

		SpaceShip(std::vector<std::vector<sPoints3<T>>> points3f, std::vector<std::vector<sColors<T>>> colors3f) :
			GeomShapes(points3f,colors3f) {}

		void Draw();
		void Colored(std::vector<std::vector<sColors<T>>>* colors3f);
		void RandomlyColored();
		void ReadCSV(std::string_view fileName, std::vector<std::vector<sPoints3<T>>>& points3f,
			std::vector<std::vector<sColors<T>>>& colors3f);
		std::vector <T>& getCoordBucket() { return coordBucket; }
		std::vector<bool>& getShapes() { return shape; }
		int getGeomNumber() { return shape.size(); }
	private:
		std::vector<bool> shape;
		std::vector <T> coordBucket;
		std::vector<bool>::iterator shapeIt;
		typename std::vector<T>::iterator coordIt;
	};
}
