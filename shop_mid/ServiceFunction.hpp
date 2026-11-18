#ifndef _SERVICEFUNCTION_HPP_
#define _SERVICEFUNCTION_HPP_

#include <Windows.h>
#include <string>
#include <iostream>
#include <iomanip>

void Getline(std::wstring& str);
bool IsNumber(const std::wstring& str);

__forceinline void Err()
{
	std::wcout << L"Некорректный ввод\n\n";
	Sleep(1500);
}

template <class ArrType>
void FillArray(ArrType* dynamicArr, ArrType* staticArr, size_t commonSize)
{
	for (size_t i = 0; i < commonSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

#endif //!_SERVICEFUNCTION_HPP_