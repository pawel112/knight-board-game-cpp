// knight.cpp : main project file.

#include "stdafx.h"
#include "chessboard.h"
#include <ctime>
#include <cstdlib>

using namespace knight;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	srand ((unsigned int)time(NULL));
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew chessboard());
	return 0;
}
