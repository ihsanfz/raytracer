#ifndef CAMERA_H
#define CAMERA_H

#include "hittable.h"
#include "interval.h"
#include "material.h"

class camera {
	public:
		double aspectRatio = 1.0;
		int imageWidth = 100;
		int samplesPerPixel = 100;
		int maxDepth = 10;
		double vFov = 90;
		point3 lookFrom = point3(0, 0, 0);
		point3 lookAt = point3(0, 0, -1);
		vec3 vUp = vec3(0, 1, 0);
		double defocusAngle = 0;
		double focusDist = 10;

		void render(const hittable& world) {
			initialize();
			std::ofstream finalFile("image.ppm");
			finalFile << "P3\n" << imageWidth << ' ' << imageHeight << ' ' << "\n255\n";
			for (int j = 0; j < imageHeight; j++) {
				std::clog << "\rScanlines remaining: " << (imageHeight - j) << ' ' << std::flush;
				for (int i = 0; i < imageWidth; i++) {
					color pixelColor(0, 0, 0);
					for (int sample = 0; sample < samplesPerPixel; sample++) {
						ray r = getRay(i, j);
						pixelColor += rayColor(r, maxDepth, world);
					}
					writeColor(finalFile, pixelSamplesScale * pixelColor);
				}
			}
			std::clog << "\r\033[KDone.\n";
			finalFile.close();
		}

	private:
		int imageHeight;
		double pixelSamplesScale;
		point3 center;
		point3 pixel00Loc;
		vec3 pixelDeltaU;
		vec3 pixelDeltaV;
		vec3 u, v, w;
		vec3 defocusDiskU;
		vec3 defocusDiskV;

		void initialize() {
			imageHeight = int(imageWidth / aspectRatio);
			imageHeight = (imageHeight < 1) ? 1 : imageHeight;

			pixelSamplesScale = 1.0 / samplesPerPixel;
			
			center = lookFrom;

			auto theta = degreesToRadian(vFov);
			auto h = std::tan(theta / 2);
			auto viewportHeight = 2 * h * focusDist;
			auto viewportWidth = viewportHeight * (double(imageWidth) / imageHeight);

			w = unitVector(lookFrom - lookAt);
			u = unitVector(cross(vUp, w));
			v = cross(w, u);

			auto viewportU = viewportWidth * u;
			auto viewportV = viewportHeight * -v;

			pixelDeltaU = viewportU / imageWidth;
			pixelDeltaV = viewportV / imageHeight;

			auto viewportUpperLeft = center - (focusDist * w) - viewportU / 2 - viewportV / 2;
			pixel00Loc = viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);

			auto defocusRadius = focusDist * std::tan(degreesToRadian(defocusAngle / 2));
			defocusDiskU = u * defocusRadius;
			defocusDiskV = v * defocusRadius;
		}

		ray getRay(int i, int j) const {
			auto offset = sampleSquare();
			auto pixelSample = pixel00Loc + ((i + offset.x()) * pixelDeltaU) + ((j + offset.y()) * pixelDeltaV);

			auto rayOrigin = (defocusAngle <= 0) ? center : defocusDiskSample();
			auto rayDirection = pixelSample - rayOrigin;

			return ray(rayOrigin, rayDirection);
		}

		vec3 sampleSquare() const {
			return vec3(randomDouble() - 0.5, randomDouble() - 0.5, 0);
		}
		color rayColor(const ray& r, int depth, const hittable& world) const {
			
			if (depth <= 0) {
				return color(0, 0, 0);
			}
			
			hitRecord rec;

			if (world.hit(r, interval(0.001, infinity), rec)) {
				ray scattered;
				color attenuation;
				if (rec.mat->scatter(r, rec, attenuation, scattered)) {
					return attenuation * rayColor(scattered, depth - 1, world);
				}
				return color(0, 0, 0);
			}

			vec3 unitDirection = unitVector(r.direction());
			auto a = 0.5 * (unitDirection.y() + 1.0);
			return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
		}

		point3 defocusDiskSample() const {
			auto p = randomInUnitDisk();
			return center + (p[0] * defocusDiskU) + (p[1] * defocusDiskV);
		}

};


#endif