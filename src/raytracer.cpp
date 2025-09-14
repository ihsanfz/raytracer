#include <iostream>
#include <fstream>

#include "color.h"
#include "vec3.h"

int main() {
	int imageWidth = 256;
	int imageHeight = 256;
	std::ofstream finalFile("image.ppm");	

	
	finalFile << "P3\n" << imageWidth << ' ' << imageHeight << ' ' << "\n255\n";

	for (int j = 0; j < imageHeight; j++) {
		std::clog << "\rScanlines remaining: " << (imageHeight - j) << ' ' << std::flush;
		for (int i = 0; i < imageWidth; i++) {
			auto pixelColor = color(double(i) / (imageWidth - 1), double(j) / (imageHeight - 1), 0);
			writeColor(finalFile, pixelColor);
 		}
	}
	std::clog << "\r\033[KDone.\n";
	finalFile.close();
}