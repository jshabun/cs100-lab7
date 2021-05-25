#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Base* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateZero) {
    Base* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpEvaluateNegNonZero) {
    Base* test = new Op(-9);
    EXPECT_EQ(test->evaluate(), -9);
}

TEST(OpTest, OpStringifyNonZero) {
    Base* eight = new Op(8);
    EXPECT_EQ(eight->stringify(), "8.000000");
}

TEST(OpTest, OpStringifyZero) {
    Base* zero = new Op(0);
    EXPECT_EQ(zero->stringify(), "0.000000");
}

TEST(OpTest, OpStringifyNegNonZero) {
    Base* negnine = new Op(-9);
    EXPECT_EQ(negnine->stringify(), "-9.000000" );
}

#endif //__OP_TEST_HPP__

