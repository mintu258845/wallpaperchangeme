

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






