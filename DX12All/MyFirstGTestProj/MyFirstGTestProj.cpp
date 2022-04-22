// MyFirstGTestProj.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "gtest/gtest.h"

#pragma comment(lib, "gtest.lib")
#pragma comment(lib, "gtest_main.lib")

int add(int a, int b)
{
    return a + b;
}

int floatAddRound(float a, float b)
{
    return int(a + b + 0.5f);
}

int floatAddCeil(float a, float b)
{
    return int(a + b);
}

int floatAddFloor(float a, float b)
{
    return (int)floor(a + b);
}

TEST(MyTestSuite, Add)
{
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(4, 3), 7);
}

TEST(MyTestSuite, Round)
{
    EXPECT_EQ(floatAddRound(2.3f, 3.5f), 6);
    EXPECT_EQ(floatAddRound(4.1f, 3.39f), 7);
}

TEST(MyTestSuite, Ceil)
{
    EXPECT_EQ(floatAddCeil(2.3f, 3.5f), 5);
    EXPECT_EQ(floatAddCeil(4.7f, 3.79f), 8);
}

TEST(MyTestSuite, Floor)
{
    EXPECT_EQ(floatAddFloor(2.401f, 3.602f), 6);
    EXPECT_EQ(floatAddFloor(4.107f, 3.89f), 7);
}

bool IsPrime(int n)
{
    // Trivial case 1: small numbers
    if (n <= 1) return false;
    // Trivial case 2: even numbers
    if (n % 2 == 0) return n == 2;
    // Now, we have that n is odd and n >= 3.
    // Try to divide n by every odd number i, starting from 3
    for (int i = 3; ; i += 2)
    {
        // We only have to try i up to the squre root of n
        if (i > n / i) break;
        // Now, we have i <= n/i < n.
        // If n is divisible by i, n is not prime.
        if (n % i == 0) return false;
    }
    // n has no integer factor in the range (1, n), and thus is prime.
    return true;
}

class IsPrimeParamTest : public ::testing::TestWithParam<int>{};
TEST_P(IsPrimeParamTest, TestSomeValue)
{
    int n = GetParam();
    EXPECT_TRUE(IsPrime(n));
}

INSTANTIATE_TEST_SUITE_P(TrueReturn, IsPrimeParamTest, testing::Values(3, 5, 11, 23, 17));

class CSomeClass
{
public:
    CSomeClass() { m_uiData = 0; }
    ~CSomeClass() {}
    unsigned int GetData();
    void SetData(unsigned int data) { m_uiData = data & 0x0000ffff; }
protected:
private:
    unsigned int m_uiData;
};



/*int main(int argc, wchar_t** argv)
{
    std::cout << "Hello gTest";
    testing::InitGoogleTest(&argc, argv);
    int iRes = RUN_ALL_TESTS();
    return iRes;
}
*/

