#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include "mult.hpp"
#include "op.hpp"

TEST(MultTest, MultEvaluateNonZero) {
	Op* five = new Op(5);
	Op* four = new Op(4);
	Mult* test = new Mult(five, four);
	EXPECT_EQ(test->evaluate(), 20);
	delete test;
	delete five;
	delete four;
}

TEST(MultTest, MultEvaluateNegNonZero) {
        Op* three = new Op(3);
        Op* negsix = new Op(-6);
        Mult* test = new Mult(three, negsix);
        EXPECT_EQ(test->evaluate(), -18);
		delete test;
		delete three;
		delete negsix;
}

TEST(MultTest, MultStringifyNonZero) {
        Op* five = new Op(5);
        Op* four = new Op(4);
        Mult* test = new Mult(five, four);
        EXPECT_EQ(test->stringify(), "(5.000000 * 4.000000)");
		delete test;
		delete five;
		delete four;
}

TEST(MultTest, MultStringifyNegNonZero) {
        Op* three = new Op(3);
        Op* negsix = new Op(-6);
        Mult* test = new Mult(three, negsix);
        EXPECT_EQ(test->stringify(), "(3.000000 * -6.000000)");
		delete test;
		delete three;
		delete negsix;
}


#endif// __MULT_TEST_HPP__
