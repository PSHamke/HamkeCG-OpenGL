#include "SpaceShip.h"

namespace HamkeCG {

	SpaceShip::SpaceShip(std::string_view fileName) {
		ReadCSV(fileName, m_Points3f, m_Colors3f);
	}
	void SpaceShip::Colored(std::vector<std::vector<sColors3f>>* colors3f)
	{
		m_Colors3f.clear();
		std::copy(colors3f->begin(), colors3f->end(), back_inserter(m_Colors3f));
	}
	void SpaceShip::RandomlyColored() {
		sColors3f customColors(0.0, 1.0, 0.0);
		std::vector < std::vector <sColors3f>>m_Colors3fTest;
		std::vector <sColors3f>* innerColors;
		std::vector <sColors3f>::iterator colorsIt;
		
		std::vector<bool>::iterator innerIt;
		srand(time(NULL));
		innerIt = shape.begin();
		int delimiter = 3;

		for (int i = 0; i < getGeomNumber(); i++) {
			if (*innerIt) { delimiter = 4; }
			else { delimiter = 3; }
			*innerIt++;
			innerColors = new std::vector<sColors3f>;
			for (int j = 0; j < delimiter; j++) {
				innerColors->push_back(customColors);
			}
			customColors.x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			customColors.y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			customColors.z = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			m_Colors3fTest.push_back(*innerColors);
		}
		Colored(&m_Colors3fTest);
	}
	void SpaceShip::ReadCSV(std::string_view fileName, std::vector<std::vector<sPoints3f>>& points3f,
		std::vector<std::vector<sColors3f>>& colors3f)  {
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
		std::vector<sColors3f>* cInner = new std::vector<sColors3f>;
		std::vector<sPoints3f>* pInner = new std::vector<sPoints3f>;
		shapeIt = shape.begin();
		int count = 0;
		for (coordIt = coordBucket.begin(); coordIt != coordBucket.end(); coordIt++) {
			sPoints3f* n_points3f = new sPoints3f;
			sColors3f* n_colors3f = new sColors3f;
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
				cInner = new std::vector<sColors3f>;
				pInner = new std::vector<sPoints3f>;
				shapeIt++;
				CG_CORE_WARN("Triangle readed!");
			}
			else if (*shapeIt && count == 4) {
				points3f.push_back(*pInner);
				colors3f.push_back(*cInner);
				count = 0;
				cInner = new std::vector<sColors3f>;
				pInner = new std::vector<sPoints3f>;
				shapeIt++;
				CG_CORE_WARN("Quad readed!");
			}

		}
	}


	void SpaceShip::Draw() {

		

		for (pOuterIt = m_Points3f.begin(), cOuterIt = m_Colors3f.begin();
			pOuterIt != m_Points3f.end() && cOuterIt != m_Colors3f.end();
			pOuterIt++, cOuterIt++) {

			if (pOuterIt->size() == 4) {
				
				Quad* quad = new Quad(*pOuterIt, *cOuterIt);
				quad->Draw();
				delete(quad);

			}
			else if (pOuterIt->size() == 3) {
				Triangle* triangle = new Triangle(*pOuterIt, *cOuterIt);
				triangle->Draw();
				delete(triangle);
			}
		}
	}
}