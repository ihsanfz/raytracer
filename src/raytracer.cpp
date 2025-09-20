#include "commons.h"
#include "hittable.h"
#include "hittableList.h"
#include "sphere.h"
#include "camera.h"
#include "material.h"


int main() {

	hittableList world;

	auto materialGround = make_shared<lambertian>(color(1.0, 1.0, 1.0));
	auto materialBall1 = make_shared<metal>(color(0.0, 1.0, 0.0), 1.0);
	auto materialBall2 = make_shared<dielectric>(1.50);
	auto materialBall3 = make_shared<lambertian>(color(1.0, 1.0, 0.0));

	world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, materialGround));
	world.add(make_shared<sphere>(point3(0.0, 0.0, -1.0), 0.5, materialBall1));
	world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.5, materialBall2));
	world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5, materialBall3));


	camera cam;

	cam.aspectRatio = 16.0 / 9.0;
	cam.imageWidth = 400;
	cam.samplesPerPixel = 100;
	cam.maxDepth = 50;
	cam.vFov = 90;
	cam.lookFrom = point3(1.5, 1.5, 0);
	cam.lookAt = point3(0, 0, -1);
	cam.vUp = vec3(0, 1, 0);
	cam.defocusAngle = 0.1;
	cam.focusDist = 10.0;
	cam.render(world);
	
}