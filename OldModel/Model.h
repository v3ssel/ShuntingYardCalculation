#ifndef MODEL_H
#define MODEL_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>

#define NUMBER_ERR_CODE 301
#define isRight(x) (((x) >= 'A' && (x) <= 'Z') || ((x) >= 'a' && (x) <= 'z'))

typedef long double ld;

namespace s21 {
enum class ExpressionTypes {
    NUMBER,
    X,
    OPEN_BRACKET,
    CLOSED_BRACKET,
    PLUS,
    MINUS,
    MULT,
    DIV,
    MOD,
    POWER,
    SQRT,
    COS,
    SIN,
    TAN,
    ACOS,
    ASIN,
    ATAN,
    LN,
    LOG
};

struct Data {
    ld value;
    short priority;
    ExpressionTypes type;
};

class Model {
    using ET = ExpressionTypes;
public:
    double entryPoint(std::string& exp, const ld& x);

    void calcMonthly(ld&, int64_t&, double, bool&, double*, double*, double*);
    void calcLoan(ld&, int64_t&, double&, double&, double&, double&);
    void calcTerm(ld, double&, double&, int64_t&, double&, double&);

    void depositCalc(ld&, int64_t&, bool&, int64_t*, size_t&, size_t&, ld*, ld&,
        short&, bool&, int64_t*, ld*, ld*, ld*, ld*);

// private:
    bool parseExpresssion_(const std::string& exp, const ld& x);
    void getFullNumber_(const std::string& exp, size_t& i, size_t len);
    void basicOps_(const std::string& exp, const size_t& i, bool& err_code,
        const short&& sign);
    void easyCases_(const char&, const std::string&, size_t&, size_t&, bool&,
        const ld&);
    void hardCases_(const char&, const std::string&, size_t&, size_t&, bool&);
    void lastChecker_(size_t&, size_t&, size_t&, bool&);

    void shuntingYard_();
    void calcus_();

    void stackReverse_();
    void setVals_(ld& v1, ld& v2, std::stack<Data>& s);


    bool isOperator(ET type);

    std::stack<Data> expression_;
};
} // namespace s21

#endif // MODEL_H
