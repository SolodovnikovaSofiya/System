#include <Windows.h>
#include <iostream>
int main()
{
	HANDLE hStd0ut; // дескриптор стандартного вывода
	CONSOLE_SCREEN_BUFFER_INFO csbi; // для параметров буфера экрана
	// читаем стандартный дескриптор вывода
	hStd0ut = GetStdHandle(STD_OUTPUT_HANDLE);
	// читаем параметры буфера экрана
	if (!GetConsoleScreenBufferInfo(hStd0ut, &csbi))
		std::cout << "Console screen buffer info failed." << std::endl;
	std::cout << "Console screen buffer info: " << std::endl << std::endl;
	// выводим на консоль параметры выходного буфера
	std::cout << "A number of columns = " << csbi.dwSize.X << std::endl;
	std::cout << "A number of rows = " << csbi.dwSize.Y << std::endl;
	std::cout << "X cursor coordinate = " << csbi.dwCursorPosition.X << std::endl;
	std::cout << "Y cursor coordinate = " << csbi.dwCursorPosition.Y << std::endl;
	std::cout << "Attributes = " << std::hex << csbi.wAttributes << std::dec << std::endl;
	std::cout << "Window upper corner = "
		<< csbi.srWindow.Left << ","
		<< csbi.srWindow.Top << std::endl;
	std::cout << "Window lower corner = "
		<< csbi.srWindow.Right << ","
		<< csbi.srWindow.Bottom << std::endl;
	std::cout << "Maximum number of columns = "
		<< csbi.dwMaximumWindowSize.X << std::endl;
	std::cout << "Maximum number of rows = "
		<< csbi.dwMaximumWindowSize.Y << std::endl << std::endl;
	return 0;
}