#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "pow.hpp"
#include "op.hpp"

TEST(PowTest, powerZeroEv) {
	Op* op1 = new Op(4);
	Op* op2 = new Op(0);
	Pow* eval = new Pow(op1, op2);

	EXPECT_EQ(eval->evaluate(), 1);
}

TEST(PowTest, powerZeroStr) {
	Op* op1 = new Op(4);
	Op* op2 = new Op(0);
	Pow* eval = new Pow(op1, op2);

	EXPECT_EQ(eval->stringify(), "(4.000000 ** 0.000000)");
}

TEST(PowTest, powerNegEv) {
        Op* op1 = new Op(1);
        Op* op2 = new Op(-3);
        Pow* eval = new Pow(op1, op2);

        EXPECT_EQ(eval->evaluate(), 1);
}

TEST(PowTest, powerNegStr) {
        Op* op1 = new Op(1);
        Op* op2 = new Op(-3);
        Pow* eval = new Pow(op1, op2);

        EXPECT_EQ(eval->stringify(), "(1.000000 ** -3.000000)");
}

TEST(PowTest, powerPosEv) {
        Op* op1 = new Op(5);
        Op* op2 = new Op(7);
        Pow* eval = new Pow(op1, op2);

        EXPECT_EQ(eval->evaluate(), 78125);
}

TEST(PowTest, powerPosStr) {
        Op* op1 = new Op(5);
        Op* op2 = new Op(7);
        Pow* eval = new Pow(op1, op2);

        EXPECT_EQ(eval->stringify(), "(5.000000 ** 7.000000)");
}

#endif //__POW_TEST_HPP__
