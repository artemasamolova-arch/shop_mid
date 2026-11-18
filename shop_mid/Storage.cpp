#include "Storage.hpp"

 size_t sizeSt = 0;
 size_t* idArr = nullptr;
 std::wstring* nameArr = nullptr;
 size_t* countArr = nullptr;
 double* priceArr = nullptr;
 bool isStorageCreated = false;
 size_t maxStorageSize = 500;
 size_t currentStorageSize = 0;



 void CreateStorage(int mode)
 {
	 if (mode == 0 && !isStorageCreated)
	 {
		 const size_t staticSize = 10;
		 size_t idArrStatic[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
		 std::wstring nameArrStatic[staticSize]
		 {
			L"GIGABYTE GeForce RTX 5070 GAMING OC", L"Palit GeForce RTX 5080 GamingPro", L"Intel Core Ultra 7 265KF OEM", L"Intel Core Ultra 9 285KF OEM",
			L"AMD Ryzen 7 7800X3D OEM", L"AMD Ryzen 7 9800X3D OEM", L"DDR5 UDIMM Kingston FURY Beast Black 32ГБ", L"DDR5 UDIMM ADATA XPG Lancer Blade 16 GB",
			L"1000 ГБ M.2 NVMe накопитель Kingston NV3" , L"960 ГБ SATA накопитель Kingston A400"};
		 
		 size_t countArrStatic[staticSize]{5, 10,50,43,13,4,1,6,8,43};
		 double priceArrStatic[staticSize]{250,210,231,4023,1240,21402,1204,2104,521,2410};
		 sizeSt = staticSize;
		 idArr = new size_t[sizeSt];
		 nameArr = new std::wstring[sizeSt];
		 countArr = new size_t[sizeSt];
		 priceArr = new double[sizeSt];

		 FillArray(idArr, idArrStatic, sizeSt);
		 FillArray(nameArr, nameArrStatic, sizeSt);
		 FillArray(countArr, countArrStatic, sizeSt);
		 FillArray(priceArr, priceArrStatic, sizeSt);

		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 currentStorageSize += countArrStatic[i];
		 }

		 isStorageCreated = true;

	
	 
	 
	 }
	 
	 else if (mode == 1)
	 {
		 //TO_ DO
	 }
	 else
	 {
		 std::wcout << L"Склад уже создан\n\n";
	 }
	 

 }
 void ShowStorage(int mode)
 {
	 if (mode == 0)
	 {
		 system("cls");
		 std::wcout << L"\n\n\t\t\tПополнение склада\n\n";
		 std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t" << L"Кол-во\n\n";
		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				 << L"\t" << countArr[i] << L"\n";
		 }
		 std::wcout << L"\n\n";
		 system("pause");
	 }
	 else if (mode == 1)
	 {
		 system("cls");
		 std::wcout << L"\n\n\t\t\tСклад\n\n";
		 std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t" << L"Кол-во\t" << L"Цена\n\n";
		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				 << L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		 }
		 std::wcout << L"\n\n";

		 std::wcout << L"Заполненность склада: " << currentStorageSize << L" из " << maxStorageSize << L"\n\n";
	 }
 }

 void AddProduct()
 {
	 std::wstring chooseId, chooseCount, choose;
	 int id = 0;
	 size_t count = 0;
	 while (true)
	 {
		 ShowStorage(1);
		 std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		 Getline(chooseId);
		 if (chooseId == L"exit" || chooseId == L"Exit")
		 {
			 std::wcout << L"Завершение операции пополнения товара\n\n";
			 return;
		 }
		 else if (IsNumber(chooseId))
		 {
			 id = std::stoi(chooseId) - 1;
			 if (id < 0 || id > sizeSt - 1)
			 {
				 Err();
			 }
			 else
			 {
				 std::wcout << L"Введите кол-во товара для пополнения: ";
				 Getline(chooseCount);
				 if (IsNumber(chooseCount))
				 {
					 count = std::stoull(chooseCount);
					 // проверить есть ли куда положить товар. закончили тут
				 }
			 }
		 }
	 }
 }
