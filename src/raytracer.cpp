#include "commons.h"
#include "hittable.h"
#include "hittableList.h"
#include "sphere.h"
#include "camera.h"


int main() {

	hittableList world;
	world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
	world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));
	
	camera cam;

	cam.aspectRatio = 16.0 / 9.0;
	cam.imageWidth = 400;

	cam.render(world);
	
}