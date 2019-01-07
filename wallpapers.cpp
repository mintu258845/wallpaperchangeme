// wallpapers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
//#include <iostream>
//#include <Windows.h>
//#include <string>
//#include <experimental/filesystem> 
//#include <filesystem>
//#include <time.h>
//#include <random>
//
//using namespace std::experimental::filesystem::v1;
//
//using namespace std;
//
//
//
//
//
//int main(int argc, char **argv)
//{
//	path current = current_path();
//
//	cout << current << endl;
//
//	vector<path> filenames;
//	STARTUPINFO info;
//	char *files[256];
//	char path[256];
//	int i = 0;
//	for (const auto& p : ::directory_iterator(current))
//	{
//		if ((p.path().extension() == ".jpg") || (p.path().extension() == ".bmp"))
//		{
//			files[i] = new char[p.path().stem().string().length() + 1];
//			strcpy(files[i], p.path().stem().string().c_str());
//			++i;
//		}
//	}
//	srand(time(NULL));
//	const char *pic = files[rand() % (i - 1)];
//	strcat(path, pic);
//	strcat(path, ".jpg");
//	printf("%s\n", path);
//	SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, (void *)path, SPIF_SENDCHANGE);
//
//	return 0;
//}

#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#include <string>
#include <iostream>
#include <time.h>
#include <random>
#include <filesystem>

#define BUFSIZE MAX_PATH

using namespace std;
namespace fs = std::experimental::filesystem::v1;



int main(int argc, char **argv)
{


	char *pictures[128];

	bool loop = true;
	int count = 0;
	srand(time(NULL));
	int i = 0;
	char path[256];
	GetCurrentDirectoryA(256, path);
	strcat(path, "\\wallpapers\\");
	printf("%s\n", path);
	for (const auto & file : fs::directory_iterator(path)) {

		pictures[i] = new char[file.path().stem().string().length() + 1];

		strcpy(pictures[i], file.path().stem().string().c_str());
		i++;
	}

	const char *pic = pictures[rand() % (i - 1)];
	printf("%s\n", pic);
	strcat(path, pic);
	strcat(path, ".jpg");
	printf("%s\n", path);
	SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, (void *)path, SPIF_SENDCHANGE);

	return 0;

}






