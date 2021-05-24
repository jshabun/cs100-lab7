#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"
#include "op.hpp"

TEST(DivTest, DivNegativesEv) {
	Op* op1 = new Op(-2);
	Op* op2 = new Op(-8);
	Div* eval = new Div(op1,op2);
	
	EXPECT_EQ(eval->evaluate(), 0.25);
}

TEST(DivTest, DivNegativesStr) {
        Op* op1 = new Op(-2);
        Op* op2 = new Op(-8);
        Div* eval = new Div(op1,op2);

        EXPECT_EQ(eval->stringify(), "(-2.000000 / -8.000000)");
}

TEST(DivTest, DivPositiveEv) {
        Op* op1 = new Op(10);
        Op* op2 = new Op(5);
        Div* eval = new Div(op1,op2);

        EXPECT_EQ(eval->evaluate(), 2);
}

TEST(DivTest, DivPositiveStr) {
        Op* op1 = new Op(10);
        Op* op2 = new Op(5);
        Div* eval = new Div(op1,op2);

        EXPECT_EQ(eval->stringify(), "(10.000000 / 5.000000)");
}

#endif //__DIV_TEST_HPP__
