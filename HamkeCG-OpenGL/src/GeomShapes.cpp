#include "GeomShapes.h"

namespace HamkeCG {
	
	template <typename T>
	void GeomShapes<T>::Translate(const sPoints3<T>& translateFactor)
	{
		for (auto& pOut : m_Points3f) {
			for (auto& pIn : pOut) {
				pIn += translateFactor;
			}
		}
	}
	template <typename T>
	void GeomShapes<T>::Rotate(const sMatrix3<T>& rotM, sPoints3<T> rotateCenter)
	{

		for (auto& pOut : m_Points3f) {
			for (auto& pIn : pOut) {
				pIn *= rotM;
			}
		}

		//float xNew, yNew;
		//std::vector<sPoints3<T>>::iterator pInnerIt;
		//for (pOuterIt = m_Points3f.begin(); pOuterIt != m_Points3f.end(); pOuterIt++) {
		//	for (pInnerIt = pOuterIt->begin(); pInnerIt != pOuterIt->end(); pInnerIt++) {
		//		
		//		*pInnerIt *= rotM;
		//		//xNew= (pInnerIt->x * cos(angle)) - (pInnerIt->y * sin(angle));
		//		//yNew = (pInnerIt->x * sin(angle)) + (pInnerIt->y * cos(angle));
		//		//pInnerIt->x = xNew;
		//		//pInnerIt->y = yNew;
		//		//
		//		////pInnerIt->z += translateFactor.z;
		//	}
		//}
	}

	


	template <typename T>
	void GeomShapes<T>::Scale(sPoints3<T> scaleFactor)
	{
		for (auto& pInner : m_Points3f) {
			for (auto& pOuter : pInner) {
				pOuter.x *= scaleFactor.x;
				pOuter.y *= scaleFactor.y;
				pOuter.z *= scaleFactor.z;
			}
		}
	}
	
	template class GeomShapes<double>;
	template class GeomShapes<float>;
}