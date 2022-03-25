#include "Quad.h"

namespace HamkeCG
{
	void Quad::Draw() {
		glBegin(GL_QUADS);		

		for (pIt = m_Points3f.begin(), cIt = m_Colors3f.begin();
			pIt != m_Points3f.end() && cIt != m_Colors3f.end();
			pIt++, cIt++) {// Draw A Quad
			glColor3f(cIt->x, cIt->y, cIt->z);
			glVertex3f(pIt->x, pIt->y, pIt->z);
		}

		glEnd();
	}
} 