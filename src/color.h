#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

using color = vec3;

void writeColor(std::ostream& out, const color& pixelColor) {
	auto r = pixelColor.x();
	auto g = pixelColor.y();
	auto b = pixelColor.z();

	int rbyte = int(255.99 * r);
	int gbyte = int(255.99 * g);
	int bbyte = int(255.99 * b);

	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
#endif