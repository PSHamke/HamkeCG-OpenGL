#include "SpaceShip.h"
#include <cmath>


namespace HamkeCG {
	template <typename T>
	void SpaceShip<T>::Colored(std::vector<std::vector<sColors<T>>>* colors3f)
	{
		m_Colors3f.clear();
		std::copy(colors3f->begin(), colors3f->end(), back_inserter(m_Colors3f));
	}

	template <typename T>
	void SpaceShip<T>::RandomlyColored() {
		sColors<T> customColors(0.0, 1.0, 0.0);
		std::vector < std::vector <sColors<T>>>m_Colors3fTest;
		std::vector <sColors<T>>* innerColors;


		std::vector<bool>::iterator innerIt;
		srand(time(NULL));
		innerIt = shape.begin();
		int delimiter = 3;

		for (int i = 0; i < getGeomNumber(); i++) {
			if (*innerIt) { delimiter = 4; }
			else { delimiter = 3; }
			*innerIt++;
			innerColors = new std::vector<sColors<T>>;
			for (int j = 0; j < delimiter; j++) {
				customColors.x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				customColors.y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				customColors.z = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				innerColors->push_back(customColors);
			}

			m_Colors3fTest.push_back(*innerColors);
		}
		Colored(&m_Colors3fTest);
		CG_CORE_INFO("Randomly Colored");
	}
	
	template <typename T>
	void SpaceShip<T>::ReadCSV(std::string_view fileName, std::vector<std::vector<sPoints3<T>>>& points3f,
		std::vector<std::vector<sColors<T>>>& colors3f)  {
		using namespace csv;
		long int counter = 0;
		// Strategy -1-
		
		int pointCounter = 0;
		// -----------------------------

		CSVReader reader(fileName);

		for (CSVRow& row : reader) { // Input iterator
			for (CSVField& field : row) {
				if (counter++ == 0) { // Remove indexes
					continue;
				}
				if ((counter - 1) % 26 == 0 || counter % 26 == 0) {
					continue;
				}

				// By default, get<>() produces a std::string.
				// A more efficient get<string_view>() is also available, where the resulting
				// string_view is valid as long as the parent CSVRow is alive
				if (field.get<string_view>() == "") {
					if (pointCounter == 0) {
						continue;
					}
					else {
						pointCounter = 0;
						shape.push_back(false);
						continue;
					}

				}
				else {
					coordBucket.push_back(atof(field.get<string_view>().data()));
				}
				pointCounter++;
				if (pointCounter == 23) {
					shape.push_back(true);
					pointCounter = 0;
				}

			}
		}
		std::vector<sColors<T>>* cInner = new std::vector<sColors<T>>;
		std::vector<sPoints3<T>>* pInner = new std::vector<sPoints3<T>>;
		shapeIt = shape.begin();
		int count = 0;
		for (coordIt = coordBucket.begin(); coordIt != coordBucket.end(); coordIt++) {
			sPoints3<T>* n_points3f = new sPoints3<T>;
			sColors<T>* n_colors3f = new sColors<T>;
			n_points3f->x = *(coordIt)++;
			n_points3f->y = *(coordIt)++;
			n_points3f->z = *(coordIt)++;
			n_colors3f->x = *(coordIt)++;
			n_colors3f->y = *(coordIt)++;
			n_colors3f->z = *(coordIt);

			pInner->push_back(*n_points3f);
			cInner->push_back(*n_colors3f);
			count++;
			if (!*shapeIt && count == 3) {
				points3f.push_back(*pInner);
				colors3f.push_back(*cInner);
				count = 0;
				cInner = new std::vector<sColors<T>>;
				pInner = new std::vector<sPoints3<T>>;
				shapeIt++;
				CG_CORE_WARN("Triangle readed!");
			}
			else if (*shapeIt && count == 4) {
				points3f.push_back(*pInner);
				colors3f.push_back(*cInner);
				count = 0;
				cInner = new std::vector<sColors<T>>;
				pInner = new std::vector<sPoints3<T>>;
				shapeIt++;
				CG_CORE_WARN("Quad readed!");
			}

		}
	}

	template <typename T>
	void SpaceShip<T>::Draw() {

		for (pOuterIt = m_Points3f.begin(), cOuterIt = m_Colors3f.begin();
			pOuterIt != m_Points3f.end() && cOuterIt != m_Colors3f.end();
			pOuterIt++, cOuterIt++) {

			if (pOuterIt->size() == 4) {
				
				Quad<T>* quad = new Quad(*pOuterIt, *cOuterIt);
				quad->Draw();
				delete(quad);

			}
			else if (pOuterIt->size() == 3) {
				Triangle<T> * triangle = new Triangle(*pOuterIt, *cOuterIt);
				triangle->Draw();
				delete(triangle);
			}
		}
	}
	
	template class SpaceShip<double>;
	template class SpaceShip<float>;
}