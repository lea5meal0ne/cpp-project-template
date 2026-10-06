#include "project/example.hpp"

#include <gtest/gtest.h>

TEST(ExampleTest, AddsTwoNumbers)
{
    EXPECT_EQ(project::add(20, 22), 42);
}

TEST(ExampleTest, HandlesNegativeNumbers)
{
    EXPECT_EQ(project::add(-10, -5), -15);
}
