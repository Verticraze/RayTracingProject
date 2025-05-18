// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "rayTracing.h"


int main()
{
	int imageWidth{ 256 };
	int imageHeight{ 256 };

	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

	for (int j = 0; j < imageHeight; j++)
	{
		std::clog << "\rScan lines remaining: " << (imageHeight - j) << ' ' << std::flush;
		for (int i = 0; i < imageWidth; i++)
		{
			auto r = double(i) / (imageWidth - 1);
			auto g = double(j) / (imageHeight - 1);
			auto b = 0.0;

			int imageRed = int(255.999 * r);
			int imageGreen = int(255.999 * g);
			int imageBlue = int(255.999 * b);

			std::cout << imageRed << ' ' << imageGreen << ' ' << imageBlue << "\n";
		}
	}

	std::clog << "\r Done.              \n";
	return 0;

}