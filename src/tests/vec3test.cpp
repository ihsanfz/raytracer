#include <gtest/gtest.h>

#include "../commons.h"
#include "../vec3.h"


TEST(Vec3Test, Addition){
    vec3 a(1, 2, 3);
    vec3 b(4, 5, 6);

    vec3 result = a + b;

    EXPECT_EQ(result.x(), 5);
    EXPECT_EQ(result.y(), 7);
    EXPECT_EQ(result.z(), 9);
}

TEST(Vec3Test, Subtraction){
    vec3 a(4, 5, 6);
    vec3 b(1, 2, 3);

    vec3 result = a - b;

    EXPECT_EQ(result.x(), 3);
    EXPECT_EQ(result.y(), 3);
    EXPECT_EQ(result.z(), 3);
}

TEST(Vec3Test, dotProduct){
    vec3 a(1, 2, 3);
    vec3 b(4, 5, 6);

    auto result = dot(a, b);

    EXPECT_EQ(result, 32);
}

TEST(Vec3Test, Division){
	vec3 a(2.0, 4.0, 6.0);
	
	a /= 2.0;
	
    EXPECT_DOUBLE_EQ(a.x(), 1.0);
	EXPECT_DOUBLE_EQ(a.y(), 2.0);
	EXPECT_DOUBLE_EQ(a.z(), 3.0);
}

TEST(Vec3Test, Multiplication){
	vec3 a(1.0, 2.0, 3.0);
	
	a *= 2.0;
	
	EXPECT_DOUBLE_EQ(a.x(), 2.0);
	EXPECT_DOUBLE_EQ(a.y(), 4.0);
	EXPECT_DOUBLE_EQ(a.z(), 6.0);

}
