#include "Storage.hpp"

 size_t sizeSt = 0;
 size_t* idArr = nullptr;
 std::wstring* nameArr = nullptr;
 size_t* countArr = nullptr;
 double* priceArr = nullptr;
 bool isStorageCreated = false;
 size_t maxStorageSize = 500;
 size_t currentStorageSize = 0;
 double maxPrice = 100000000;



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
		 std::wcout << L"\n\n\t\t\tСклад \"Quatnum\"\n\n";
		 std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t" << L"Кол-во\n\n";
		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(40) << nameArr[i]
				 << L"\t" << countArr[i] << L"\t" << std::setprecision(2) << priceArr[i] <<  L"\n";
		 }
		 std::wcout << L"\n\n";
		 system("pause");
	 }
	 else if (mode == 1)
	 {
		 system("cls");
		 std::wcout << L"\n\n\t\t\tПополнение склада \"Quatnum\"\n\n";
		 std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t" << L"Кол-во\t" << L"Цена\n\n";
		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(40) << nameArr[i]
				 << L"\t" << countArr[i] << L"\t" << std::setprecision(2) << priceArr[i] << L"\n";
		 }
		 std::wcout << L"\n\n";

		 std::wcout << L"Заполненность склада: " << currentStorageSize << L" из " << maxStorageSize << L"\n\n";
	 }
	 else if (mode == 2)
	 {
		 system("cls");
		 std::wcout << L"\n\n\t\t\tСписание товаров \"Quatnum\"\n\n";
		 std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t" << L"Кол-во\t" << L"Цена\n\n";
		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(40) << nameArr[i]
				 << L"\t" << countArr[i] << L"\t" << std::setprecision(2) << priceArr[i] << L"\n";
		 }
		 std::wcout << L"\n\n";

		 std::wcout << L"Заполненность склада: " << currentStorageSize << L" из " << maxStorageSize << L"\n\n";
	 }
	 else if (mode == 3)
	 {
		 system("cls");
		 std::wcout << L"\n\n\t\t\tИзменение цены \"Quatnum\"\n\n";
		 std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t" << L"Цена\n\n";
		 for (size_t i = 0; i < sizeSt; i++)
		 {
			 std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(40) << nameArr[i]
				 << L"\t"  << std::setprecision(2) << priceArr[i] << L"\n";
		 }
		 std::wcout << L"\n\n";

		 
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
					 if (count > maxStorageSize - currentStorageSize || count < 0)
					 {
						 std::wcout << L"Некорректное кол-во! На складе осталось " << maxStorageSize - currentStorageSize
							 << L" свободных мест\n\n";
						 Sleep(2000);
					 }
					 else
					 {
						 while (true)
						 {
							 system("cls");
							 std::wcout << nameArr[id] << L"\t" << countArr[id] << L"----->"
								 << countArr[id] + count << L"\n\n";
							 std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							 Getline(choose);

							 if (choose == L"1")
							 {
								 std::wcout << L"Товар успешно пополнен\n\n";
								 countArr[id] += count;
								 currentStorageSize += count;
								 Sleep(1500);
								 break;
							 }
							 else if (choose == L"2")
							 {
								 std::wcout << L"Отмена пополнения " << nameArr[id] << L"\n";
								 Sleep(1500);
								 break;
							 }
							 else
							 {
								 Err();
							 }
						 }
					 }
				 }
			 }
		 }
	 }
 }

 void RemoveProduct()
 {
	 std::wstring chooseId, chooseCount, choose;
	 int id = 0;
	 size_t count = 0;
	 while (true)
	 {
		 ShowStorage(2);
		 std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		 Getline(chooseId);
		 if (chooseId == L"exit" || chooseId == L"Exit")
		 {
			 std::wcout << L"Завершение операции списания товара\n\n";
			 Sleep(1600);
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
				 std::wcout << L"Введите кол-во товара для списания: ";
				 Getline(chooseCount);
				 if (IsNumber(chooseCount))
				 {
					 count = std::stoull(chooseCount);
					 if (count < 0 || count > countArr[id])
					 {
						 std::wcout << L"Некорректное кол-во! На складе осталось " << maxStorageSize - currentStorageSize
							 << L" ед. товара\n\n";
						 Sleep(2000);
					 }
					 else
					 {
						 while (true)
						 {
							 system("cls");
							 std::wcout << nameArr[id] << L"\t" << countArr[id] << L"----->"
								 << countArr[id] - count << L"\n\n";
							 std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							 Getline(choose);

							 if (choose == L"1")
							 {
								 std::wcout << L"Товар успешно списан\n\n";
								 countArr[id] -= count;
								 currentStorageSize -= count;
								 Sleep(1500);
								 break;
							 }
							 else if (choose == L"2")
							 {
								 std::wcout << L"Отмена пополнения " << nameArr[id] << L"\n";
								 Sleep(1500);
								 break;
							 }
							 else
							 {
								 Err();
							 }
						 }
					 }
				 }
			 }
		 }
	 }
 }

 void ChangePrice()
 {
	 std::wstring chooseId, choosePrice, choose;
	 int id = 0;
	 double price = 0;
	 
	 while (true)
	 {
		 ShowStorage(3);
		 std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		 Getline(chooseId);
		 if (chooseId == L"exit" || chooseId == L"Exit")
		 {
			 std::wcout << L"Завершение операции изменения цен\n\n";
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
				 std::wcout << L"Введите новую цену товара:  ";
				 Getline(choosePrice);
				 if (IsNumber(choosePrice))
				 {
					 price = std::stod(choosePrice);
					 if (price < 0 || price > maxPrice)
					 {
						 std::wcout << L"Некорректная цена! Максимально возможная цена: " << maxPrice
							 << L" рублей\n\n";
						 Sleep(2000);
					 }
					 else
					 {
						 while (true)
						 {
							 system("cls");
							 std::wcout << nameArr[id] << L"\t" << priceArr[id] << L"----->"
								 <<  price << L"\n\n";
							 std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							 Getline(choose);

							 if (choose == L"1")
							 {
								 std::wcout << L"Успешное изменение цены\n\n";
								 priceArr[id] = price;
								 // :)
								 Sleep(1500);
								 break;
							 }
							 else if (choose == L"2")
							 {
								 std::wcout << L"Отмена изменения цены " << nameArr[id] << L"\n";
								 Sleep(1500);
								 break;
							 }
							 else
							 {
								 Err();
							 }
						 }
					 }
				 }
			 }
		 }
	 }
 }

 void ChangeStorage()
 {
	 std::wstring choose;
	 while (true)
	 {
		 system("cls");

		 std::wcout << L"\n\n\t\t\tРедактирование склада \"Quantum\"\n\n";
		 std::wcout << L"1 - Добавить новый товар\n";
		 std::wcout << L"2 - Изменить название товара\n";
		 std::wcout << L"3 - Удаление товара\n";
		 std::wcout << L"4 - Изменить лимиты склада\n";
		 std::wcout << L"0 - Выход\n\n";
		 Getline(choose);

		 if (choose == L"1")
		 {
			 AddNewProduct();
		 }
		 else if (choose == L"2")
		 {
			 
		 }
		 else if (choose == L"3")
		 {
			 
		 }
		 else if (choose == L"4")
		 {
			 
		 }
		 else
		 {
			 Err();
		 }

	 }
 }

 void AddNewProduct()
 {
	 std::wstring chooseName ,chooseCount, choosePrice, choose;
	 size_t count = 0;
	 double price = 0;
	 
	 while (true)
	 {
		 while (true)
		 {
			 system("cls");

			 std::wcout << L"Введите название нового товара или \"exit\" для выхода: ";
			 Getline(chooseName);
			 if (chooseName == L"exit" || chooseName == L"Exit")
			 {
				 std::wcout << L"Отмена создания нового товара\n\n";
				 Sleep(1500);
				 return;
			 }
			 if (chooseName.size() < 3 || chooseName.size() > 40)
			 {
				 std::wcout << L"Ошибка длины названия товара\nДопустимое значение от 3 до 40 символов\n\n";
				 Sleep(1500);
			 }
			 if (!IsNotSameName(chooseName, nameArr, sizeSt))
			 {
				 continue;
			 }
			 else
			 {
				 break;
			 }
		 }
	 
		 while (true)
		 {
			 system("cls");

			 std::wcout << L"Введите кол-во нового товара или \"exit\" для выхода: ";
			 Getline(chooseCount);
			 if (chooseCount == L"exit" || chooseCount == L"Exit")
			 {
				 std::wcout << L"Отмена создания нового товара\n\n";
				 Sleep(1500);
				 return;
			 }
			 if (IsNumber(chooseCount))
			 {
				 size_t count = std::stoull(chooseCount);
				 if (count < 0 || count < maxStorageSize - currentStorageSize)
				 {
					 std::wcout << L"Ошибка! На складе осталось " <<
						 maxStorageSize - currentStorageSize << L" свободных мест\n\n";
					 Sleep(1500);
				 }
				 else
				 {
					 break;
				 }
			 }
		 }

		 while (true)
		 {
			 system("cls");

			 std::wcout << L"Введите цену нового товара или \"exit\" для выхода: ";
			 Getline(choosePrice);
			 if (choosePrice == L"exit" || choosePrice == L"Exit")
			 {
				 std::wcout << L"Отмена создания нового товара\n\n";
				 Sleep(1500);
				 return;
			 }
			 if (IsNumber(choosePrice))
			 {
				 price = std::stod(choosePrice);
				 if (price < 0 || price > maxPrice)
				 {
					 std::wcout << L"Некорректная цена! Максимально возможная цена: " <<
						 maxPrice << L" рублей\n\n";
					 Sleep(1500);
				 }
				 else
				 {
					 break;
				 }
			 }
		 }
	 
		 while (true)
		 {
			 system("cls");

			 std::wcout << L"Новый товар: " << chooseName << L"\n";
			 std::wcout << L"Кол-во товара: " << count << L"\n";
			 std::wcout << L"Цена товара: " << price << L"\n";
			 std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
			 Getline(choose);

			 if (choose == L"1")
			 {
				 //жесть остановились тут!
			 }
			 else if (choose == L"2")
			 {
				 std::wcout << L"Отмена\n";
				 Sleep(1400);
				 break;
			 }
			 else
			 {
				 Err();
			 }
		 }
	 }
	 
 }
