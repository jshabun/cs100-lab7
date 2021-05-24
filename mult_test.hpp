#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include "mult.hpp"
#include "op.hpp"

TEST(MultTest, MultEvaluateNonZero) {
	Base* five = new Op(5);
	Base* four = new Op(4);
	Mult* test = new Mult(five, four);
	EXPECT_EQ(test->evaluate(), 20);
}

TEST(MultTest, MultEvaluateNegNonZero) {
        Base* three = new Op(3);
        Base* negsix = new Op(-6);
        Mult* test = new Mult(three, negsix);
        EXPECT_EQ(test->evaluate(), -18);
}

TEST(MultTest, MultStringifyNonZero) {
        Base* five = new Op(5);
        Base* four = new Op(4);
        Mult* test = new Mult(five, four);
        EXPECT_EQ(test->stringify(), "(5.000000 * 4.000000)");
}

TEST(MultTest, MultStringifyNegNonZero) {
        Base* three = new Op(3);
        Base* negsix = new Op(-6);
        Mult* test = new Mult(three, negsix);
        EXPECT_EQ(test->stringify(), "(3.000000 * -6.000000)");
}


#endif// __MULT_TEST_HPP__
