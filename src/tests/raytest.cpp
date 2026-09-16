#include <gtest/gtest.h>

#include "../commons.h"
#include "../ray.h"

TEST(rayTest, At){

	point3 origin(1, 2, 3);
	vec3 direction(4, 5, 6);
	
	ray r(origin, direction);
	
	point3 p = r.at(2.0);
	
	EXPECT_EQ(p.x(), 9);
	EXPECT_EQ(p.y(), 12);
	EXPECT_EQ(p.z(), 15);
}
