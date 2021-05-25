#ifndef __PARSE_TEST_HPP__
#define __PARSE_TEST_HPP__

#include "parse.hpp"
#include "gtest/gtest.h"

TEST(ParseTest, OneDigitNum){
	char* test_val[2];
	test_val[0] = strdup("./calculator");
	test_val[1] = strdup("6");
	Factory* fact = new Parse();
	Base* calc = fact->parse(test_val, 2);
	EXPECT_EQ("6.000000", calc->stringify());
	delete fact;
	delete calc;
	for(int i = 0; i < 2; i++){
		free(test_val[i]);
	}
}

TEST(ParseTest, TwoDigitNum){
	char* test_val[2];
	test_val[0] = strdup("./calculator");
	test_val[1] = strdup("21");
	Factory* fact = new Parse();
	Base* calc = fact-> parse(test_val, 2);
	EXPECT_EQ("21.000000",calc->stringify());
        delete fact;
        delete calc;
        for(int i = 0; i < 2; i++){
                free(test_val[i]);
        }
}

TEST(ParseTest, Addition){
	char* test_val[4];
	test_val[0] = strdup("./calculator");
	test_val[1] = strdup("9");
	test_val[2] = strdup("+");
	test_val[3] = strdup("10");
	Factory* fact = new Parse();
	Base* calc = fact-> parse(test_val, 4);
	EXPECT_EQ("(9.000000 + 10.000000)", calc->stringify());
        delete fact;
        delete calc;
        for(int i = 0; i < 4; i++){
                free(test_val[i]);
        }
}

TEST(InvalidTest, OneOperand) {
	char* test_val[3];
	test_val[0] = strdup("./calculator");
	test_val[1] = strdup("9");
	test_val[2] = strdup("+");
	Factory* fact = new Parse();
	Base* test = fact->parse(test_val, 3);
	EXPECT_EQ(test, nullptr);
        delete fact;
        delete test;
        for(int i = 0; i < 3; i++){
                free(test_val[i]);
       }	
}

TEST(InvalidTest, NoOperand) {
        char* test_val[3];
        test_val[0] = strdup("./calculator");
        test_val[1] = strdup("*");
        test_val[2] = strdup("/");
        Factory* fact = new Parse();
        Base* test = fact->parse(test_val, 3);
        EXPECT_EQ(test, nullptr);
        delete fact;
        delete test;
        for(int i = 0; i < 3; i++){
               free(test_val[i]);
        }
}

TEST(InvalidTest, TwoOperand) {
        char* test_val[5];
        test_val[0] = strdup("./calculator");
        test_val[1] = strdup("6");
        test_val[2] = strdup("-");
		test_val[3] = strdup("3");
		test_val[4] = strdup("*");
        Factory* fact = new Parse();
        Base* test = fact->parse(test_val, 5);
        EXPECT_EQ(test, nullptr);
        delete fact;
        delete test;
        for(int i = 0; i < 5; i++){
              free(test_val[i]);
        }
}

TEST(InvalidTest, SubMultAddDivSubInv) {
        char* test_val[10];
        test_val[0] = strdup("./calculator");
        test_val[1] = strdup("30");
        test_val[2] = strdup("-");
        test_val[3] = strdup("9");
        test_val[4] = strdup("*");
        test_val[5] = strdup("60");
        test_val[6] = strdup("+");
        test_val[7] = strdup("7");
        test_val[8] = strdup("/");
        test_val[9] = strdup("-");
        Factory* fact = new Parse();
        Base* test = fact->parse(test_val, 10);
        EXPECT_EQ(nullptr, test);
        delete fact;
        delete test;
        for(int i = 0; i < 10; i++){
               free(test_val[i]);
        }
}

TEST(LongerEquation, AddDiv) {
        char* test_val[6];
        test_val[0] = strdup("./calculator");
        test_val[1] = strdup("4");
        test_val[2] = strdup("+");
        test_val[3] = strdup("3");
        test_val[4] = strdup("/");
		test_val[5] = strdup("7");
        Factory* fact = new Parse();
        Base* test = fact->parse(test_val, 6);
        EXPECT_EQ(test->evaluate(), 1);
        delete fact;
        delete test;
        for(int i = 0; i < 6; i++){
                free(test_val[i]);
        }
}

TEST(LongerEquation, SubPow) {
        char* test_val[6];
        test_val[0] = strdup("./calculator");
        test_val[1] = strdup("6");
        test_val[2] = strdup("-");
        test_val[3] = strdup("3");
        test_val[4] = strdup("**");
        test_val[5] = strdup("2");
        Factory* fact = new Parse();
        Base* test = fact->parse(test_val, 6);
        EXPECT_EQ(test->evaluate(), 9);
        delete fact;
        delete test;
        for(int i = 0; i < 6; i++){
                free(test_val[i]);
       }
}

TEST(LongerEquation, MultAddSubDiv) {
        char* test_val[10];
        test_val[0] = strdup("./calculator");
        test_val[1] = strdup("56");
        test_val[2] = strdup("*");
        test_val[3] = strdup("3");
        test_val[4] = strdup("+");
        test_val[5] = strdup("19");
		test_val[6] = strdup("-");
        test_val[7] = strdup("87");
		test_val[8] = strdup("/");
		test_val[9] = strdup("10");
        Factory* fact = new Parse();
        Base* test = fact->parse(test_val, 10);
        EXPECT_EQ(test->evaluate(), 10);
        delete fact;
        delete test;
        for(int i = 0; i < 10; i++){
                free(test_val[i]);
        }
}

TEST(ParseTest, Sub){
	char* test_val[4];
	test_val[0] = strdup("./calculator"); 
    test_val[1] = strdup("90");
	test_val[2] = strdup("-");
    test_val[3] = strdup("45");
	Factory* fact = new Parse();
	Base* test = fact->parse(test_val, 4);
	EXPECT_EQ("(90.000000 - 45.000000)", test->stringify());
        delete fact;
        delete test;
        for(int i = 0; i < 4; i++){
                free(test_val[i]);
        }
}

TEST(ParseTest, SubNegative){
	char* test_val[4];
	test_val[0]= strdup("./calculator"); 
	test_val[1]= strdup("3"); 
	test_val[2]= strdup("-"); 
	test_val[3]= strdup("21");
	Factory* fact = new Parse();
	Base* test = fact->parse(test_val, 4);
	EXPECT_EQ(-18, test->evaluate());
	delete fact;
    delete test;
    for(int i = 0; i < 4; i++){
            free(test_val[i]);
        }
}

TEST(ParseTest, Mult){
	char* test_val[4];
	test_val[0]= strdup("./calculator"); 
	test_val[1]= strdup("8"); 
	test_val[2]= strdup("*"); 
	test_val[3]= strdup("7");
	Factory* fact = new Parse();
	Base* test = fact->parse(test_val, 4);
	EXPECT_EQ(56, test->evaluate());
        delete fact;
        delete test;
        for(int i = 0; i < 4; i++){
                free(test_val[i]);
        }
}

TEST(ParseTest, Pow){
	char* test_val[4];
	test_val[0] = strdup("./calculator");
	test_val[1] = strdup("9"); 
	test_val[2] = strdup("**"); 
	test_val[3] = strdup("2");
	Factory* fact = new Parse();
	Base* test = fact->parse(test_val,4);
	EXPECT_EQ(81, test->evaluate());
        delete fact;
        delete test;
        for(int i = 0; i < 4; i++){
                free(test_val[i]);
        }
}

TEST(ParseTest, Div){
	char* test_val[4];
	test_val[0] = strdup("./calculator"); 
	test_val[1] = strdup("200"); 
	test_val[2] = strdup("/"); 
	test_val[3] = strdup("40");
	Factory* fact = new Parse();
	Base* test = fact->parse(test_val, 4);
	EXPECT_EQ(5, test->evaluate());
        delete fact;
        delete test;
        for(int i = 0; i < 4; i++){
                free(test_val[i]);
        }
}

#endif //__PARSE_TEST_HPP__
