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
    Stack c(g);
    ASSERT_EQ(1, c.getTop());
    Stack b(g, 10);
    ASSERT_EQ(10, b.getTop());
}

TEST(Push, Push) 
{
    Massive g;
    g.setKey(10);
    Stack c(g);
    for (int i = 0; i < 5; i++)
    {
        c.push(g);
    }
    ASSERT_EQ(6, c.getTop());
    Stack h;
    h.push(g);
    ASSERT_EQ(1, h.getTop());
    Stack r(g,10);
    ASSERT_ANY_THROW(r.push(g));
}

TEST(Pop, pop) 
{
    Massive g;
    g.setKey(10);
    Stack c(g);
    for (int i = 0; i < 5; i++)
    {
        c.push(g);
    }
    Massive el;
    c.pop(el);
    ASSERT_EQ(5, c.getTop());
    ASSERT_EQ(el.getKey(), 10);
    Stack check;
    ASSERT_ANY_THROW(check.pop(el));
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
    ASSERT_EQ(a.check(), -1);
}



int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}