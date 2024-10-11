#include <Windows.h>
#include <iostream>
int main()
{
	COORD coord; // для размера буфера экрана
	HANDLE hStd0ut; // дескриптор стандартного вывода
	// читаем дескриптор стандартного вывода
	hStd0ut = GetStdHandle(STD_OUTPUT_HANDLE);
	// вводим новый размер буфера экрана
	std::cout << "Enter new screen buffer size." << std::endl;
	std::cout << "A number of columns: ";
	std::cin >> coord.X;
	std::cout << "A number of rows: ";
	std::cin >> coord.Y;
	// устанавливаем новый размер буфера экрана
	if (!SetConsoleScreenBufferSize(hStd0ut, coord))
	{
		std::cout << "Set console screen buffer size failed." << std::endl; return GetLastError();
	}
	return 0;
}