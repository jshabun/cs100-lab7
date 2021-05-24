#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "add.hpp"
#include "op.hpp"

TEST(AddTest, AddNegativesEv) {
	Op* op1 = new Op(-6);
	Op* op2 = new Op(-4);
	Add* eval = new Add(op1, op2);
	
	EXPECT_EQ(eval->evaluate(), -10);
}

TEST(AddTest, AddNegativesStr) {
	Op* op1 = new Op(-6);
        Op* op2 = new Op(-4);
        Add* eval = new Add(op1, op2);

	EXPECT_EQ(eval->stringify(), "(-6.000000 + -4.000000)");
}

TEST(AddTest, AddPositivesEv) {
	Op* op1 = new Op(3);
        Op* op2 = new Op(2);
	Add* eval = new Add(op1, op2);

	EXPECT_EQ(eval->evaluate(), 5);
}

TEST(AddTest, AddPositivesStr) {	
	Op* op1 = new Op(3);
        Op* op2 = new Op(2);
        Add* eval = new Add(op1, op2);

	EXPECT_EQ(eval->stringify(),"(3.000000 + 2.000000)");
}

TEST(AddTest, AddZeroEv) {
	Op* op1 = new Op(0);
        Op* op2 = new Op(0);
        Add* eval = new Add(op1, op2);  

        EXPECT_EQ(eval->evaluate(), 0);
}

TEST(AddTest,AddZeroStr) {
	Op* op1 = new Op(0);
        Op* op2 = new Op(0);
        Add* eval = new Add(op1, op2);

        EXPECT_EQ(eval->stringify(),"(0.000000 + 0.000000)");
}

#endif //__ADD_TEST_HPP
