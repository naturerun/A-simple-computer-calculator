#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <utility>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/math/special_functions.hpp>

using std::string;
using std::pair;
using std::make_pair;

using namespace boost::multiprecision;

struct ParseResult
{
    enum class type { FLOAT, INTEGER, INVAILD, E };
    type type_flag;
    union
    {
        cpp_int int_value;
        cpp_dec_float_50 float_value;
    };
    ParseResult() :type_flag(type::INVAILD) {}
    ParseResult(const cpp_int &i) :type_flag(type::INTEGER), int_value(i) {}
    ParseResult(const cpp_dec_float_50& f, bool is_e):float_value(f)
    {
        if (is_e)
        {
            type_flag = type::E;
        }
        else
        {
            type_flag = type::FLOAT;
        }
    }
    ParseResult(const ParseResult& copy):type_flag(copy.type_flag)
    {
        if (type_flag == type::INTEGER)
        {
            new (&int_value) cpp_int(copy.int_value);
        }
        else if (type_flag == type::FLOAT || type_flag == type::E)
        {
            new (&float_value) cpp_dec_float_50(copy.float_value);
        }
    }
    ParseResult& operator=(const ParseResult& copy)
    {
        if (type_flag != type::INVAILD)
        {
            if (type_flag == type::INTEGER)
            {
                int_value.~cpp_int();
            }
            else if (type_flag == type::FLOAT || type_flag == type::E)
            {
                float_value.~cpp_dec_float_50();
            }
        }

        if (copy.type_flag == type::INTEGER)
        {
            new (&int_value) cpp_int(copy.int_value);
        }
        else if (copy.type_flag == type::FLOAT || copy.type_flag == type::E)
        {
            new (&float_value) cpp_dec_float_50(copy.float_value);
        }
        type_flag = copy.type_flag;
        return *this;
    }

    ~ParseResult()
    {
        if (type_flag == type::INTEGER)
        {
            int_value.~cpp_int();
        }
        else if (type_flag == type::FLOAT || type_flag == type::E)
        {
            float_value.~cpp_dec_float_50();
        }
    }
};

class Lexer
{
public:
    enum class TokenType {
        ADD, MINUS_NEGATIVE, MULTIPLY, DIVIDE,
        MOD, COS, SIN, TAN, ARCCOS, ARCSIN, ARCTAN, CSC, SEC, COT, COSH, SINH, TANH, LN, LOG, POW, FABS,
        FLOOR, CEIL, CONSTANT, _E, _PI, LEFT_BRACKET, RIGHT_BRACKET, FAC, END, SQRT, CBRT, ERROR
    };
    Lexer(const string* s) :scan_str(s) {}
    Lexer() = default;
    void set_str(const string* s) { scan_str = s; }
    pair<TokenType, ParseResult> nextToken();
    pair<TokenType, ParseResult> peekToken();
    void consumeToken();
    bool expectToken(const pair<TokenType, ParseResult>& t);
    void reset();
private:
    const string* scan_str = nullptr;
    pair<TokenType, ParseResult> Token;
    bool pre_peek_or_next = false;
    string::size_type start = 0;
    string::size_type cur = 0;

};

class ParseExpr
{
public:
    ParseExpr(const string* s, bool r = true) :lexParse(s), radian_or_angle(r){}
    ParseExpr(bool r = true) { radian_or_angle = r; }
    void set_str(const string* s) { lexParse.set_str(s); }
    void reset() { lexParse.reset(); }
    void setRAMode(bool r) { radian_or_angle = r; }
    ParseResult parse();
private:
    ParseResult parseAddAndMinus();
    ParseResult parseMultiplyAndDivide();
    ParseResult _parseAddAndMinus(const ParseResult& mid);
    ParseResult _parseMultiplyAndDivide(const ParseResult& mid);
    ParseResult parsePowAndMod();
    ParseResult _parsePowAndMod(const ParseResult& mid);
    ParseResult parseFact();
    ParseResult parseNegative();
    ParseResult parseSubExpr();
    cpp_dec_float_50 toRadian(cpp_dec_float_50 angle);
    cpp_dec_float_50 toAngle(cpp_dec_float_50 angle);
    Lexer lexParse;
    bool radian_or_angle = true;
};


#endif // PARSER_H
