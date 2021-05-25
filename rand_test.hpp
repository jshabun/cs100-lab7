#ifndef __RAND__TEST_HPP__
#define __RAND__TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "rand.hpp"

TEST(RandTest, EvaluateRandGen){
    Rand* test = new Rand();
    EXPECT_TRUE((test->evaluate() >= 0)&&(test->evaluate() <= 100));
}

TEST(RandTest, EvaluateRandGen2){
    Rand* test = new Rand();
    EXPECT_TRUE((test->evaluate() >= 0)&&(test->evaluate() <= 100));
}

TEST(RandTest, EvaluateRandGen3){
    Rand* test = new Rand();
    EXPECT_TRUE((test->evaluate() >= 0)&&(test->evaluate() <= 100));
}

#endif //__RAND_TEST_HPP__
