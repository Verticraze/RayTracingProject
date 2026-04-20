// CMakeProject1.cpp : Defines the entry point for the application.
//
#include"vec3.h"
#include"color.h"
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
			auto pixel_color = color(double(i) / (imageWidth - 1), double(j) / (imageHeight - 1), 0);
			write_color(std::cout,pixel_color);
		}
	}

	std::clog << "\r Done.              \n";
	return 0;

}