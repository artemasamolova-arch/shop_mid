#include "Authorization.hpp"

void Start()
{
	while (true) //главный цикл программы
	{
		if (Login())
		{
			if (currentStatus == L"SuperAdmin")
			{
				CreateStorage();
				SuperAdminMenu();
			}
			else if (currentStatus == L"Admin")
			{
				//TO_DO
			}
			else if (currentStatus == L"User")
			{
				//TO_DO
			}
			else
			{
				std::wcerr << L"\n\n_CURRENT_STATUS_LOGIN_ERROR_\n\n";
			}
		}
		else
		{
			system("cls");
			std::wcout << L"\n\n\n\t\t\tВсего доброго\n\n\n";
			Sleep(1000);
			break;
		}
	}

}

bool Login()
{
	std::wstring login, pass;
	while (true)
	{
		system("cls");
		std::wcout << L"\n\n\n\t\t\tДобро пожаловать!\n\n\t\t\t    Quantum\n\n\n";
		std::wcout << L"Введите логин или \"exit\" для выхода: ";
		Getline(login);
		if (login == L"exit" || login == L"Exit")
		{
			return false;
		}
		else
		{
			std::wcout << L"Введите пароль: ";
			Getline(pass);
			for (size_t i = 0; i < userSize; i++)
			{
				if (login == loginArr[i] && pass == passArr[i])
				{
					std::wcout << L"\nДобро пожаловать " << loginArr[i] << L"\n";
					std::wcout << L"Ваш уровень доступа: " << statusArr[i] << L"\n";
					currentId = userIdArr[i];
					currentStatus = statusArr[i];
					return true;
				}
			}
			std::wcout << L"Неверный логин или пароль. Повторите попытку\n\n";
			Sleep(1500);
		}
	}
}

void SuperAdminMenu()
{
	std::wstring choose;
	while (true)
	{
		system("cls");

		std::wcout << L"1 - Начать продажу\n";
		std::wcout << L"2 - Показать товары\n";
		std::wcout << L"3 - Пополнить товары\n";
		std::wcout << L"4 - Списать товар\n";
		std::wcout << L"5 - Изменить цены\n";
		std::wcout << L"6 - Редактировать склад\n";
		std::wcout << L"7 - Редактировать сотрудников\n";
		std::wcout << L"8 - Показать прибыль\n";
		std::wcout << L"0 - Выход\n";
		std::wcout << L"Ввод: \n";
		Getline(choose);

		if (choose == L"1")
		{

		}
		else if (choose == L"2")
		{
			ShowStorage();
		}
		else if (choose == L"3")
		{
			AddProduct();
		}
		else if (choose == L"4")
		{

		}
		else if (choose == L"5")
		{

		}
		else if (choose == L"6")
		{

		}
		else if (choose == L"7")
		{

		}
		else if (choose == L"8")
		{

		}
		else if (choose == L"0")
		{

		}
		else
		{
			Err();
		}


	}
}
