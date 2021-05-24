#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"
#include "op.hpp"

TEST(SubTest, SubNegEv) {
	Op* op1 = new Op(-3);
	Op* op2 = new Op(-12);
	Sub* eval = new Sub(op1, op2);

	EXPECT_EQ(eval->evaluate(), 9);
}

TEST(SubTest, SubNegStr) {
        Op* op1 = new Op(-3);
        Op* op2 = new Op(-12);
        Sub* eval = new Sub(op1, op2);

        EXPECT_EQ(eval->stringify(), "(-3.000000 - -12.000000)");
}

TEST(SubTest, SubPosEv) {
        Op* op1 = new Op(4);
        Op* op2 = new Op(9);
        Sub* eval = new Sub(op1, op2);

        EXPECT_EQ(eval->evaluate(), -5);
}

TEST(SubTest, SubPosStr) {
        Op* op1 = new Op(4);
        Op* op2 = new Op(9);
        Sub* eval = new Sub(op1, op2);

        EXPECT_EQ(eval->stringify(), "(4.000000 - 9.000000)");
}

#endif // __SUB_TEST_HPP__
