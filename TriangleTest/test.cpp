#include "pch.h"
#include "triangle.h"


TEST(TriangleTest, GetA) {
    Triangle t;
    t.set_a(10);
    EXPECT_EQ(t.get_a(), 10);
}

TEST(TriangleTest, GetH) {
    Triangle t;
    t.set_h(5);
    EXPECT_EQ(t.get_h(), 5);
}


TEST(TriangleTest, SetA) {
    Triangle t;
    t.set_a(15);
    EXPECT_EQ(t.get_a(), 15);

    t.set_a(0);
    EXPECT_EQ(t.get_a(), 0);

    t.set_a(-5);
    EXPECT_EQ(t.get_a(), -5);
}


TEST(TriangleTest, SetH) {
    Triangle t;
    t.set_h(20);
    EXPECT_EQ(t.get_h(), 20);

    t.set_h(0);
    EXPECT_EQ(t.get_h(), 0);
}


TEST(TriangleTest, GetS) {
    Triangle t;
    t.set_a(10);
    t.set_h(5);
    EXPECT_DOUBLE_EQ(t.get_S(), 25.0);
}

TEST(TriangleTest, GetSFractional) {
    Triangle t;
    t.set_a(7);
    t.set_h(3);
    EXPECT_DOUBLE_EQ(t.get_S(), 10.5);
}

TEST(TriangleTest, GetSZeroSide) {
    Triangle t;
    t.set_a(0);
    t.set_h(10);
    EXPECT_DOUBLE_EQ(t.get_S(), 0.0);
}

TEST(TriangleTest, GetSZeroHeight) {
    Triangle t;
    t.set_a(10);
    t.set_h(0);
    EXPECT_DOUBLE_EQ(t.get_S(), 0.0);
}


TEST(TriangleTest, RecalculateArea) {
    Triangle t;
    t.set_a(10);
    t.set_h(5);
    EXPECT_DOUBLE_EQ(t.get_S(), 25.0);

    t.set_a(20);
    EXPECT_DOUBLE_EQ(t.get_S(), 50.0);

    t.set_h(10);
    EXPECT_DOUBLE_EQ(t.get_S(), 100.0);
}

TEST(TriangleTest, LargeNumbers) {
    Triangle t;
    t.set_a(1000);
    t.set_h(500);
    EXPECT_DOUBLE_EQ(t.get_S(), 250000.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}