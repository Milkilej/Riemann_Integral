#include <iostream>
#include <sstream>
#include <cmath>
#include <functional>

struct TestCase { std::string name{}; std::ostringstream failures{}; };
template <typename T> void operator | (TestCase& testCase, T&& testBody) {
    testBody(); auto failures = testCase.failures.str();
    if (failures.empty()) std::cout << testCase.name << ": SUCCESS\n";
    else std::cerr << testCase.name << ": FAILURE\n" << failures;
}
void addFailure(std::ostream& os, const char* file, unsigned line, const char* condition) {
    os << file << ":" << line << ": Failed: " << condition << "\n";
}
#define TEST(name) TestCase name{#name}; name | [&, &failures = name.failures]
#define EXPECT(cond) if (cond) {} else addFailure(failures, __FILE__, __LINE__, #cond)
#define ASSERT(cond) if (cond) {} else return addFailure(failures, __FILE__, __LINE__, #cond)



double Compute (const std::function<double(double)>&f, double start, double end, double interval=1) {
    auto sum = 0.0;
    if (start > end) 
    {
        std::cout << "Wrong range" << std::endl;
        return -1;
    }
    if (interval <= 0)
    {
        std::cout << "Wrong interval range" << std::endl;
        return -1;
    }
    for(auto x = start; x < end; x+=interval)
    {
        if(x+interval > end)
        {
            sum += std::abs((end-x)*f(x+((end-x)/2))); 
        }
        else 
        {
            sum += std::abs(interval*f(x+(interval/2)));
        }
    }
    return sum;
}
double Substract (const std::function<double(double)>&f,const std::function<double(double)>&g)
{
    return 0;
}

int main() 
{
    
    TEST(GivenAEqualTo1AndRangeFrom0To2ThenFunctionReturnsHalf)
    {
        auto f = [](double x)
        {
            return 1*x;
        };
        EXPECT(Compute(f,0,1)==0.5);
    };
    
    TEST(GivenAEqualTo1AndRangeFrom0To2ThenFunctionReturns2)
    {
        auto f = [](double x)
        {
            return 1*x;
        };
        EXPECT(Compute(f,0,2)==2);
    };
    
    TEST(GivenAEqualTo2AndRangeFrom0To2ThenFunctionReturns4)
    {
        auto f = [](double x)
        {
            return 2*x;
        };
        EXPECT(Compute(f,0,2)==4);
    };

    TEST(GivenAEqualTo1AndRangeFrom2To3ThenFunctionReturns2AndHalf)
    {
        auto f = [](double x)
        {
            return 1*x;
        };
        EXPECT(Compute(f,2,3)==2.5);
    };

    TEST(GivenAEqualTo2AndRangeFrom4To2ThenFunctionReturnsError)
    {
        auto f = [](double x)
        {
            return 1*x;
        };
        EXPECT(Compute(f,4,2)==-1);
    };

    TEST(GivenAEqualTo1AndRangeFrom2To6AndInterval2ThenFunctionReturns16)
    {
        auto f = [](double x)
        {
            return 1*x;
        };
        EXPECT(Compute(f,2,6,2)==16);
    };

    TEST(GivenAEqualTo1AndRangeFrom2To3AndInterval2ThenFunctionReturns2AndHalf)
    {
        auto f = [](double x)
        {
            return 1*x;
        };
        EXPECT(Compute(f,2,3,2)==2.5);
    };

    TEST(GivenAEqualTo1AndRangeFrom2To3AndInterval3ThenFunctionReturns2AndHalf)
    {
        auto f = [](double x)
        {
            return 1*x;
        };
        EXPECT(Compute(f,2,3,3)==2.5);
    };
    
    TEST(GivenAEqualTo1AndRangeFrom2To3AndInterval0ThenFunctionReturnsError)
    {
        auto f = [](double x)
        {
            return 1*x;
        };
        EXPECT(Compute(f,2,3,0)==-1);
    };

    TEST(GivenAEqualTo1AndRangeFromNegative1To0AndInterval1ThenFunctionReturnsHalf)
    {
        auto f = [](double x)
        {
            return 1*x;
        };
        EXPECT(Compute(f,-1,0,1)==0.5);
    };
    
    TEST(GivenTwoSameFunctionsThenSubractionReturnZero)
    {
        auto f = [](double x)
        {
            return 1*x;
        };
        EXPECT(Substract(f,f)==0);
    };



}