#include <iostream>
#include <fstream>

int main() {
	int imageWidth = 256;
	int imageHeight = 256;
	std::ofstream finalFile("image.ppm");	

	
	finalFile << "P3\n" << imageWidth << ' ' << imageHeight << ' ' << "\n255\n";

	for (int j = 0; j < imageHeight; j++) {
		std::clog << "\rScanlines remaining: " << (imageHeight - j) << ' ' << std::flush;
		for (int i = 0; i < imageWidth; i++) {
			auto r = double(i) / (imageWidth - 1);
			auto g = double(j) / (imageHeight - 1);
			auto b = 0.0;

			int ir = int(255.99 * r);
			int ig = int(255.99 * g);
			int ib = int(255.99 * b);

			finalFile << ir << ' ' << ig << ' ' << ib << '\n';
 		}
	}
	std::clog << "\rDone\n";
	finalFile.close();
}