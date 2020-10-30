#include "pch.h"
#include "../lib/Stack.h"

using namespace Stk;
TEST(Constructor, EmptyConstructor)
{
    Stack c;
    ASSERT_EQ(c.getTop(), 0);
}

TEST(Constructor, DefConstructor)
{
    Massive g;
    g.setKey(10);
    Stack c(g,5);
    ASSERT_EQ(5,c.getTop());
    Stack b(g, 10);
    ASSERT_EQ(10, b.getTop());
    Stack a(c); 
    ASSERT_EQ(5, a.getTop());
}

TEST(Push, Push)
{
    Massive g;
    g.setKey(10);
    Stack c(g);
    for (int i = 0; i < 5; i++)
    {
        c += g;
    }
    ASSERT_EQ(6, c.getTop());
    Stack h;
    h += g;
    ASSERT_EQ(1, h.getTop());
    h += c;
    ASSERT_EQ(7, h.getTop());
    h += h;
    ASSERT_EQ(14, h.getTop());
}

TEST(Pop, pop)
{
    Massive g;
    Stack c;
    for (int i = 0; i < 5; i++)
    {
        g.setKey(i);
        c += g;
    }
    Massive el;
    for (int i = 0; i < 5; i++)
    {
        c(el);
        ASSERT_EQ(4-i, c.getTop());
        ASSERT_EQ(el.getKey(), 4-i);
    }
    ASSERT_ANY_THROW(c(el));
    Stack th;
    ASSERT_ANY_THROW(th(el));
    Stack empty(th);
    ASSERT_ANY_THROW(empty(el));
}

TEST(Check, check)
{
    Massive g;
    g.setKey(10);
    Stack c(g);
    Stack k;
    Stack a(g, 10);
    ASSERT_EQ(c.check(), 0);
    ASSERT_EQ(k.check(), 1);
    //ASSERT_EQ(a.check(), -1);
}



int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}