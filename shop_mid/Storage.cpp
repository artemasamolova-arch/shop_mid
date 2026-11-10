#include "Storage.hpp"

 size_t sizeSt = 0;
 size_t* idArr = nullptr;
 std::wstring* nameArr = nullptr;
 size_t* countArr = nullptr;
 double* priceArr = nullptr;

 void CreateStorage(int mode)
 {
	 const size_t staticSize = 10;
	 size_t idArrStatic[staticSize]{1,2,3,4,5,6,7,8,9,10};
	 std::wstring nameArrStatic[staticSize]
	 {
		L"GIGABYTE GeForce RTX 5070 GAMING OC", L"Palit GeForce RTX 5080 GamingPro", L"Intel Core Ultra 7 265KF OEM", L"Intel Core Ultra 9 285KF OEM"
		L"AMD Ryzen 7 7800X3D OEM", L"AMD Ryzen 7 9800X3D OEM", L""
	 };
	 size_t countArrStatic[staticSize];
	 double priceArrStatic[staticSize];

 }
