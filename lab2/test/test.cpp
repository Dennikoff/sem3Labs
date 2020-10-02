#include "pch.h"
#include "C:/Users/dhark/source/repos/cpp3lab2/Deltoida.h"
//#include <tchar.h>
#include "C:/Users/dhark/source/repos/cpp3lab2/Deltoida.cpp"
const double error = 0.0001;
//Constructor
TEST(DeltoidaConstructor, DefaultConstructor) {
    Prog2::Deltoida a;
    ASSERT_EQ(1, a.getR());
    ASSERT_EQ(0, a.getT());
}
TEST(DeltoidaConstructor, InitConstructor) {
    Prog2::Deltoida a(-1);
    ASSERT_EQ(1, a.getR());
    ASSERT_EQ(0, a.getT());
}

TEST(DeltoidaConstructor, getrs) {
    Prog2::Deltoida a(10,15);
    ASSERT_EQ(10, a.getR());
    ASSERT_EQ(15, a.getT());
}

//Setter
TEST(DeltoidaMethods, setR) {
    Prog2::Deltoida a;
    a.setR(10);
    ASSERT_EQ(10, a.getR());
    ASSERT_ANY_THROW(a.setR(-1));
}
//Other Methods
TEST(DeltoidaMethods, getLengthKas) {
    Prog2::Deltoida a(0,0);
    ASSERT_EQ(0, a.getLengthKas());
    a.setR(10);
    ASSERT_EQ(40, a.getLengthKas());
    a.setR(20);
    ASSERT_EQ(80, a.getLengthKas());
}
TEST(DeltoidaMethods, getLength) {
    Prog2::Deltoida a(0);
    ASSERT_EQ(0, a.getLength());
    a.setR(31);
    ASSERT_EQ(496, a.getLength());
    ASSERT_ANY_THROW(a.setR(-1));
}
TEST(DeltoidaMethods, getS) {
    Prog2::Deltoida a(4);
    ASSERT_NEAR(100.5309,a.getS(),error);
    a.setR(15);
    ASSERT_NEAR(1413.7164, a.getS(), error);
    a.setR(50);
    ASSERT_NEAR(15707.9600, a.getS(), error);
}
TEST(DeltoidaMethods, getX) {
    Prog2::Deltoida a;
    ASSERT_NEAR(3, a.getX(), error);
    a.setR(10);
    a.setT(-2);
    ASSERT_NEAR(-14.8593, a.getX(), error);
    a.setR(100);
    a.setT(25);
    ASSERT_NEAR(294.7371, a.getX(), error);
}
TEST(DeltoidaMethods, getY) {
    Prog2::Deltoida a;
    ASSERT_NEAR(0, a.getY(), error);
    a.setR(15);
    a.setT(-100);
    ASSERT_NEAR(2.0915, a.getY(), error);
    a.setR(25);
    a.setT(71);
    ASSERT_NEAR(62.2476, a.getY(), error);
}
TEST(DeltoidaMethods, formulaY) {
    Prog2::Deltoida a;
    ASSERT_STREQ("y = 2*1*sin(0)-1*sin(2*0)",a.formulaY());
    a.setR(15);
    a.setT(-10);
    ASSERT_STREQ("y = 2*15*sin(-10)-15*sin(2*-10)", a.formulaY());
}

TEST(DeltoidaMethods, formulaX) {
    Prog2::Deltoida a;
    ASSERT_STREQ("x = 2*1*cos(0)+1*cos(2*0)", a.formulaX());
    a.setR(20);
    a.setT(-1);
    ASSERT_STREQ("x = 2*20*cos(-1)+20*cos(2*-1)", a.formulaX());
}
//
int _tmain(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}