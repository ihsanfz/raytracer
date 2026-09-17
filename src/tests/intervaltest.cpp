#include <gtest/gtest.h>

#include "../commons.h"
#include "../interval.h"

TEST(IntervalTest, containsValue){

	interval i(1.0, 5.0);
	
	EXPECT_TRUE(i.contains(3.0));
	EXPECT_TRUE(i.contains(1.0));
	EXPECT_FALSE(i.contains(9.0));
}

TEST(IntervalTest, surroundsValue){

	interval i(1.0, 5.0);
	
	EXPECT_TRUE(i.surrounds(3.0));
	EXPECT_TRUE(i.surrounds(4.0));
	EXPECT_FALSE(i.surrounds(1.0));
	EXPECT_FALSE(i.surrounds(9.0));
}

TEST(IntervalTest, size){
	
	interval i(1.0, 5.0);
	
	EXPECT_EQ(i.size(), 4.0);
}

TEST(IntervalTest, clamp){
	
	interval i(1.0, 5.0);
	
	EXPECT_EQ(i.clamp(-7.0), 1.0);
	EXPECT_EQ(i.clamp(12.0), 5.0);
	EXPECT_EQ(i.clamp(3.0), 3.0);
}
