#include "parser.h"

void Lexer::consumeToken()
{
    pre_peek_or_next = false;
}

void Lexer::reset()
{
    scan_str = nullptr;
    pre_peek_or_next = false;
    start = 0;
    cur = 0;
}

bool compareToken(const pair<Lexer::TokenType, ParseResult>& left, const pair<Lexer::TokenType, ParseResult>& right)
{
    if (left.first != right.first)
        return false;
    if (left.first != Lexer::TokenType::CONSTANT)
        return true;
    if (left.second.type_flag != right.second.type_flag)
        return false;
    return true;
}

string getTokenDesc(const pair<Lexer::TokenType, ParseResult>& t)
{
    switch (t.first)
    {
    case Lexer::TokenType::ADD: { return "加号"; }
    case Lexer::TokenType::MINUS_NEGATIVE: { return"减号或负号"; }
    case Lexer::TokenType::MULTIPLY: { return "乘号"; }
    case Lexer::TokenType::DIVIDE: { return "除号"; }
    case Lexer::TokenType::MOD: { return "取余"; }
    case Lexer::TokenType::COS: { return "余弦"; }
    case Lexer::TokenType::SIN: { return "正弦"; }
    case Lexer::TokenType::TAN: { return "正切"; }
    case Lexer::TokenType::ARCCOS: { return "反余弦"; }
    case Lexer::TokenType::ARCSIN: { return "反正弦"; }
    case Lexer::TokenType::ARCTAN: { return "反正切"; }
    case Lexer::TokenType::CSC: { return "余割"; }
    case Lexer::TokenType::SEC: { return "正割"; }
    case Lexer::TokenType::COT: { return "余切"; }
    case Lexer::TokenType::COSH: { return "双曲余弦"; }
    case Lexer::TokenType::SINH: { return "双曲正弦"; }
    case Lexer::TokenType::TANH: { return "双曲正切"; }
    case Lexer::TokenType::LN: { return "自然对数"; }
    case Lexer::TokenType::LOG: { return "常用对数"; }
    case Lexer::TokenType::POW: { return "幂运算"; }
    case Lexer::TokenType::FABS: { return "绝对值"; }
    case Lexer::TokenType::FLOOR: { return "向下取整"; }
    case Lexer::TokenType::CEIL: { return "向上取整"; }
    case Lexer::TokenType::CONSTANT: {
        if (t.second.type_flag == ParseResult::type::INTEGER)
        {
            return "整数";
        }
        else
        {
            return "浮点数";
        }
    }
    case Lexer::TokenType::_E: { return "自然常数"; }
    case Lexer::TokenType::_PI: { return "圆周率"; }
    case Lexer::TokenType::LEFT_BRACKET: { return "左括号"; }
    case Lexer::TokenType::RIGHT_BRACKET: { return "右括号"; }
    case Lexer::TokenType::FAC: { return "阶乘"; }
    case Lexer::TokenType::SQRT: { return "平方根"; }
    case Lexer::TokenType::CBRT: { return "立方根"; }
    case Lexer::TokenType::END: { return "结束"; }
    }
}

pair<Lexer::TokenType, ParseResult> Lexer::peekToken()
{
    if (pre_peek_or_next == false)
    {
        Token = nextToken();
        pre_peek_or_next = true;
    }
    return Token;
}

bool Lexer::expectToken(const pair<TokenType, ParseResult>& t)
{
    Token = peekToken();
    if (Token.first == Lexer::TokenType::ERROR)
    {
        //cout << "词法错误!" << std::endl;
        return false;
    }

    if (compareToken(Token, t))
    {
        return true;
    }
   // cout << "非预期的记号,预期为\"" << getTokenDesc(t) << "\"实际为\"" << getTokenDesc(Token) << "\"" << std::endl;
    return false;
}

string removePreSuffixZero(const string &_str)
{
    string::size_type i = _str.size() - 1;
    while (_str[i] == '0')
        --i;
    if (_str[i] == '.' && i + 1 != _str.size())
    {
        i += 2;
    }
    else
    {
        ++i;
    }

    string::size_type j = 0;
    while (_str[j] == '0')
    {
        ++j;
    }

    if (_str[j] == '.')
    {
        if (j != 0)
            --j;
    }
    return _str.substr(j, i-j);
}

string getDecimal(const string &_str)
{
    string::size_type p = _str.find_first_of('e');
    if (p == string::npos)
    {
        p = _str.find_first_of('E');
    }
    return _str.substr(0, p);
}

pair<Lexer::TokenType, ParseResult> Lexer::nextToken()
{
    if (cur == scan_str->size())
    {
        return { TokenType::END, ParseResult() };
    }

    start = cur;
    switch ((*scan_str)[cur])
    {
    case '+': { ++cur; return { TokenType::ADD, ParseResult() }; }
    case '-': { ++cur; return { TokenType::MINUS_NEGATIVE, ParseResult() }; }
    case '*': { ++cur; return { TokenType::MULTIPLY, ParseResult() }; }
    case '/': { ++cur; return { TokenType::DIVIDE, ParseResult() }; }
    case '%': { ++cur; return { TokenType::MOD, ParseResult() }; }
    case '^': { ++cur; return { TokenType::POW, ParseResult() }; }
    case 'e': { ++cur; return { TokenType::_E, ParseResult() }; }
    case 'E': { ++cur; return { TokenType::ERROR, ParseResult() }; }
    case '(': { ++cur; return { TokenType::LEFT_BRACKET, ParseResult() }; }
    case ')': { ++cur; return { TokenType::RIGHT_BRACKET, ParseResult() }; }
    case '!': { ++cur; return { TokenType::FAC, ParseResult() }; }
    default: {
        signed char c = (*scan_str)[cur];
        if ('a' <= c && c <= 'z')
        {
            do
            {
                ++cur;
                string temp = scan_str->substr(start, cur - start);
                switch (temp.size())
                {
                case 2:
                {
                    if (temp == "ln")
                    {
                        return { TokenType::LN, ParseResult() };
                    }
                    else if (temp == "pi")
                    {
                        return { TokenType::_PI, ParseResult() };    ////
                    }
                    break;
                }
                case 3:
                {

                    if (temp == "cos")
                    {
                        return { TokenType::COS, ParseResult() };
                    }
                    else if (temp == "sin")
                    {
                        return { TokenType::SIN, ParseResult() };
                    }
                    else if (temp == "tan")
                    {
                        return { TokenType::TAN, ParseResult() };
                    }
                    else if (temp == "csc")
                    {
                        return { TokenType::CSC, ParseResult() };
                    }
                    else if (temp == "sec")
                    {
                        return { TokenType::SEC, ParseResult() };
                    }
                    else if (temp == "cot")
                    {
                        return { TokenType::COT, ParseResult() };
                    }
                    else if (temp == "log")
                    {
                        return { TokenType::LOG, ParseResult() };
                    }
                    break;
                }
                case 4:
                {
                    if (temp == "acos")
                    {
                        return { TokenType::ARCCOS, ParseResult() };
                    }
                    else if (temp == "asin")
                    {
                        return { TokenType::ARCSIN, ParseResult() };
                    }
                    else if (temp == "atan")
                    {
                        return { TokenType::ARCTAN, ParseResult() };
                    }
                    else if (temp == "cosh")
                    {
                        return { TokenType::COSH, ParseResult() };
                    }
                    else if (temp == "sinh")
                    {
                        return { TokenType::SINH, ParseResult() };
                    }
                    else if (temp == "tanh")
                    {
                        return { TokenType::TANH, ParseResult() };
                    }
                    if (temp == "fabs")
                    {
                        return { TokenType::FABS, ParseResult() };
                    }
                    else if (temp == "ceil")
                    {
                        return { TokenType::CEIL, ParseResult() };
                    }
                    else if (temp == "sqrt")
                    {
                        return { TokenType::SQRT, ParseResult() };
                    }
                    else if (temp == "cbrt")
                    {
                        return { TokenType::CBRT, ParseResult() };
                    }
                    break;
                }
                case 5:
                {
                    if (temp == "floor")
                    {
                        return { TokenType::FLOOR, ParseResult() };
                    }
                    return { TokenType::ERROR, ParseResult() };
                }
                default: break;
                }

                if (cur == scan_str->size())
                {
                    return { TokenType::ERROR, ParseResult() };
                }
                c = (*scan_str)[cur];
            } while ('a' <= c && c <= 'z');
            return { TokenType::ERROR, ParseResult() };
        }
        else
        {
            bool has_dot = false;
            bool has_e = false;
            bool has_positive_or_negative = false;
            do
            {
                ++cur;
                if (cur == scan_str->size())
                {
                    break;
                }
                c = (*scan_str)[cur];

                switch (c)
                {
                case 'e':
                case 'E':
                {
                    if (has_e)
                    {
                        return { TokenType::ERROR, ParseResult() };
                    }
                    has_e = true;
                    continue;
                }
                case '.':
                {
                    if (has_dot || has_e)
                    {
                        return { TokenType::ERROR, ParseResult() };
                    }
                    has_dot = true;
                    continue;
                }
                case '+':
                case '-':
                {
                    if (has_positive_or_negative)
                        break;
                    if (has_e == false)
                        break;
                    if ((*scan_str)[cur - 1] != 'E' && (*scan_str)[cur - 1] != 'e')
                        break;
                    has_positive_or_negative = true;
                    continue;
                }
                default:
                {
                    break;
                }
                }

                if (!('0' <= c && c <= '9'))
                {
                    break;
                }

            } while (true);

            string temp = (*scan_str).substr(start, cur - start);
            ParseResult result;
            if (has_dot == false && has_e == false)
            {
                try
                {
                    result = ParseResult(cpp_int(temp));
                }
                catch (const std::runtime_error& e)
                {
                    return { TokenType::ERROR, ParseResult() };
                }
            }
            else
            {
                try
                {
                    result = ParseResult(cpp_dec_float_50(temp), false);
                }
                catch (const std::runtime_error& e)
                {
                    return { TokenType::ERROR, ParseResult() };
                }

                std::ostringstream s_stream;
                if (has_e)
                {
                    s_stream << std::scientific;
                }
                else
                {
                    s_stream << std::fixed;
                }

                s_stream  << result.float_value;
                string s_temp = s_stream.str();
                if (has_e)
                {
                    temp = removePreSuffixZero(getDecimal(temp));
                    s_temp = removePreSuffixZero(getDecimal(s_temp));
                }
                else
                {
                    temp = removePreSuffixZero(temp);
                    s_temp = removePreSuffixZero(s_temp);
                }
                if (temp.size() - temp.find_first_of('.') != s_temp.size() - s_temp.find_first_of('.'))
                {
                    return { TokenType::ERROR, ParseResult() };  //精度损失实际上应该发出警告而不是将其视为错误
                }
            }
            return { TokenType::CONSTANT, result};
        }
    }
    }
}

ParseResult ParseExpr::parse()
{
    return parseAddAndMinus();
}

ParseResult ParseExpr::parseAddAndMinus()
{
    ParseResult r = parseMultiplyAndDivide();
    if (r.type_flag == ParseResult::type::INVAILD)
        return ParseResult();
    ParseResult final_result = _parseAddAndMinus(r);
    if (final_result.type_flag == ParseResult::type::INVAILD)
        return ParseResult();
    return final_result;

}

ParseResult ParseExpr::parseMultiplyAndDivide()
{
    ParseResult r = parsePowAndMod();
    if (r.type_flag == ParseResult::type::INVAILD)
        return ParseResult();
    ParseResult final_result = _parseMultiplyAndDivide(r);
    if (final_result.type_flag == ParseResult::type::INVAILD)
        return ParseResult();
    return final_result;
}

ParseResult ParseExpr::_parseAddAndMinus(const ParseResult& mid)
{
    pair<Lexer::TokenType, ParseResult> token = lexParse.peekToken();
    switch (token.first)
    {
    case Lexer::TokenType::ADD:
    case Lexer::TokenType::MINUS_NEGATIVE:
    {
        lexParse.consumeToken();
        ParseResult r = parseMultiplyAndDivide();
        if (r.type_flag == ParseResult::type::INVAILD)
            return ParseResult();

        ParseResult add_r;
        cpp_dec_float_50 result;
        if (token.first == Lexer::TokenType::ADD)
        {
            if (mid.type_flag == ParseResult::type::INTEGER)
            {
                if (r.type_flag == ParseResult::type::INTEGER)
                {
                    cpp_int result = mid.int_value + r.int_value;
                    add_r = ParseResult(result);
                }
                else
                {
                    result = mid.int_value.convert_to<cpp_dec_float_50>();
                    result = result + r.float_value;
                }
            }
            else
            {
                if (r.type_flag == ParseResult::type::INTEGER)
                {
                    result = r.int_value.convert_to<cpp_dec_float_50>();
                    result = result + mid.float_value;
                }
                else
                {
                    result = mid.float_value + r.float_value;
                }
            }
        }
        else
        {
            if (mid.type_flag == ParseResult::type::INTEGER)
            {
                if (r.type_flag == ParseResult::type::INTEGER)
                {
                    cpp_int result = mid.int_value - r.int_value;
                    add_r = ParseResult(result);
                }
                else
                {
                    result = mid.int_value.convert_to<cpp_dec_float_50>();
                    result = result - r.float_value;
                }
            }
            else
            {
                if (r.type_flag == ParseResult::type::INTEGER)
                {
                    result = r.int_value.convert_to<cpp_dec_float_50>();
                    result = mid.float_value - result;
                }
                else
                {
                    result = mid.float_value - r.float_value;
                }
            }
        }

        if (add_r.type_flag == ParseResult::type::INVAILD)
        {
            add_r = ParseResult(result, false);
        }
        add_r = _parseAddAndMinus(add_r);
        if (add_r.type_flag == ParseResult::type::INVAILD)
            return ParseResult();
        return add_r;
    }
    case Lexer::TokenType::ERROR: { return ParseResult(); }
    default: { return mid; }
    }
}

ParseResult ParseExpr::_parseMultiplyAndDivide(const ParseResult& mid)
{
    pair<Lexer::TokenType, ParseResult> token = lexParse.peekToken();
    switch (token.first)
    {
    case Lexer::TokenType::MULTIPLY:
    case Lexer::TokenType::DIVIDE:
    {
        lexParse.consumeToken();
        ParseResult r = parsePowAndMod();
        if (r.type_flag == ParseResult::type::INVAILD)
            return ParseResult();

        ParseResult add_r;
        cpp_dec_float_50 result;
        if (token.first == Lexer::TokenType::MULTIPLY)
        {
            if (mid.type_flag == ParseResult::type::INTEGER)
            {
                if (r.type_flag == ParseResult::type::INTEGER)
                {
                    cpp_int result = mid.int_value * r.int_value;
                    add_r = ParseResult(result);
                }
                else
                {
                    result = mid.int_value.convert_to<cpp_dec_float_50>();
                    result = result * r.float_value;
                }
            }
            else
            {
                if (r.type_flag == ParseResult::type::INTEGER)
                {
                    result = r.int_value.convert_to<cpp_dec_float_50>();
                    result = result * mid.float_value;
                }
                else
                {
                    result = mid.float_value * r.float_value;
                }
            }

            if (add_r.type_flag == ParseResult::type::INVAILD)
            {
                add_r = ParseResult(result, false);
            }
        }
        else
        {
            if (mid.type_flag == ParseResult::type::INTEGER)
            {
                result = mid.int_value.convert_to<cpp_dec_float_50>();
                cpp_dec_float_50 result2;
                if (r.type_flag == ParseResult::type::INTEGER)
                {
                    if (r.int_value == cpp_int(0))
                        return ParseResult();
                    result2 = r.int_value.convert_to<cpp_dec_float_50>();
                    result = result / result2;
                }
                else
                {
                    if (r.float_value == cpp_dec_float_50(0.0))
                        return ParseResult();
                    result = result / r.float_value;
                }
            }
            else
            {
                if (r.type_flag == ParseResult::type::INTEGER)
                {
                    if (r.int_value == cpp_int(0))
                        return ParseResult();
                    result = r.int_value.convert_to<cpp_dec_float_50>();
                    result = mid.float_value / result;
                }
                else
                {
                    if (r.float_value == cpp_dec_float_50(0.0))
                        return ParseResult();
                    result = mid.float_value / r.float_value;
                }
            }
            add_r = ParseResult(result, false);
        }

        add_r = _parseMultiplyAndDivide(add_r);
        if (add_r.type_flag == ParseResult::type::INVAILD)
            return ParseResult();
        return add_r;
    }
    case Lexer::TokenType::ERROR: { return ParseResult(); }
    default: { return mid; }
    }
}

ParseResult ParseExpr::parsePowAndMod()
{
    ParseResult r = parseFact();
    if (r.type_flag == ParseResult::type::INVAILD)
        return ParseResult();
    ParseResult final_result = _parsePowAndMod(r);
    if (final_result.type_flag == ParseResult::type::INVAILD)
        return ParseResult();
    return final_result;
}

bool zeroAfterPoint(const cpp_dec_float_50 &cur)
{
    cpp_dec_float_50 integerPart = trunc(cur);
    cpp_dec_float_50 decimalPart = fabs(cur - integerPart);
    if (decimalPart == cpp_dec_float_50(0.0))
    {
        return true;
    }
    return false;
}

cpp_dec_float_50 to_float_value(const ParseResult &cur)
{
    cpp_dec_float_50 result;
    if (cur.type_flag == ParseResult::type::INTEGER)
    {
        result = cur.int_value.convert_to<cpp_dec_float_50>();
    }
    else
    {
        result = cur.float_value;
    }
    return result;
}

ParseResult ParseExpr::_parsePowAndMod(const ParseResult& mid)
{
    pair<Lexer::TokenType, ParseResult> token = lexParse.peekToken();
    switch (token.first)
    {
    case Lexer::TokenType::POW:
    case Lexer::TokenType::MOD:
    {
        lexParse.consumeToken();
        ParseResult r = parseFact();
        if (r.type_flag == ParseResult::type::INVAILD)
            return ParseResult();

        ParseResult add_r;
        if (token.first == Lexer::TokenType::POW)
        {
            cpp_dec_float_50 result;
            if (mid.type_flag == ParseResult::type::E)
            {
                cpp_dec_float_50 result = pow(mid.float_value, r.float_value);
            }
            else
            {
                result = to_float_value(mid);
                cpp_dec_float_50 result2 = to_float_value(r);

                if (result2 == cpp_dec_float_50(2.0))
                {
                    result = result * result;
                }
                else if (result2 == cpp_dec_float_50(3.0))
                {
                    result = result * result * result;
                }
                else if (result2 == cpp_dec_float_50(-1.0))
                {
                    if (result == cpp_dec_float_50(0.0))
                        return ParseResult();
                    result = cpp_dec_float_50(1.0) / result;
                }
                else
                {
                    if (result < cpp_dec_float_50(0.0))
                    {
                        if (zeroAfterPoint(result2) == false)
                            return ParseResult();
                    }
                    else if (result == cpp_dec_float_50(0.0))
                    {
                        if (result2 <= cpp_dec_float_50(0.0))
                            return ParseResult();
                    }
                    result = pow(result , result2);
                }
            }
            add_r = ParseResult(result, false);
        }
        else
        {
            cpp_int result;
            if (mid.type_flag == ParseResult::type::INTEGER)
            {
                if (r.type_flag == ParseResult::type::INTEGER)
                {
                    if (r.int_value == cpp_int(0))
                    {
                        return ParseResult();
                    }
                    result = mid.int_value % r.int_value;
                }
                else
                {
                    if (zeroAfterPoint(r.float_value) == false)
                    {
                        return ParseResult();
                    }

                    result = r.float_value.convert_to<cpp_int>();
                    if (result == cpp_int(0))
                    {
                        return ParseResult();
                    }
                    result = mid.int_value % result;
                }
            }
            else
            {
                if (r.type_flag == ParseResult::type::INTEGER)
                {
                    if (r.int_value == cpp_int(0))
                    {
                        return ParseResult();
                    }

                    if (zeroAfterPoint(mid.float_value) == false)
                    {
                        return ParseResult();
                    }
                    result = mid.float_value.convert_to<cpp_int>() % r.int_value;
                }
                else
                {
                    if (zeroAfterPoint(mid.float_value) == false || zeroAfterPoint(r.float_value) == false)
                    {
                        return ParseResult();
                    }

                    if (r.float_value == cpp_dec_float_50(0.0))
                    {
                        return ParseResult();
                    }
                    result = mid.float_value.convert_to<cpp_int>() % r.float_value.convert_to<cpp_int>();
                }
            }
            add_r = ParseResult(result);
        }

        add_r = _parsePowAndMod(add_r);
        if (add_r.type_flag == ParseResult::type::INVAILD)
            return ParseResult();
        return add_r;
    }
    case Lexer::TokenType::ERROR: { return ParseResult(); }
    default: { return mid; }
    }
}

ParseResult ParseExpr::parseFact()
{
    ParseResult r = parseNegative();
    if (r.type_flag == ParseResult::type::INVAILD)
    {
        return ParseResult();
    }

    pair<Lexer::TokenType, ParseResult> token = lexParse.peekToken();
    if (token.first != Lexer::TokenType::FAC)
    {
        return ParseResult(r);
    }
    else
    {
        lexParse.consumeToken();
        cpp_int result;
        if (r.type_flag == ParseResult::type::INTEGER)
        {
            if (r.int_value < cpp_int(0))
            {
                return ParseResult();
            }
            result = r.int_value;
        }
        else
        {
            if (zeroAfterPoint(r.float_value) == false || r.float_value < cpp_dec_float_50(0.0))
            {
                return ParseResult();
            }
            result = r.float_value.convert_to<cpp_int>();
        }

        if (result > cpp_int(70))
            return ParseResult();
        cpp_int c_r = 1;
        for (cpp_int i = 1; i <= result; ++i)
        {
            c_r = c_r * i;
        }
        return ParseResult(c_r);
    }
}

ParseResult ParseExpr::parseNegative()
{
    pair<Lexer::TokenType, ParseResult> token = lexParse.peekToken();
    if (token.first == Lexer::TokenType::MINUS_NEGATIVE)
    {
        lexParse.consumeToken();
    }

    ParseResult r = parseSubExpr();
    if (r.type_flag == ParseResult::type::INVAILD)
        return ParseResult();
    if (token.first == Lexer::TokenType::MINUS_NEGATIVE)
    {
        if (r.type_flag == ParseResult::type::INTEGER)
        {
            return ParseResult(-r.int_value);
        }
        else
        {
            return ParseResult(-r.float_value, false);
        }
    }
    else
    {
        return r;
    }
}

cpp_dec_float_50 ParseExpr::toRadian(cpp_dec_float_50 angle)
{
    if (radian_or_angle == false)
        return angle * boost::math::constants::pi<cpp_dec_float_50>() / cpp_dec_float_50(180.0);
    return angle;
}

cpp_dec_float_50 ParseExpr::toAngle(cpp_dec_float_50 angle)
{
    if (radian_or_angle == false)
        return angle * cpp_dec_float_50(180.0)/boost::math::constants::pi<cpp_dec_float_50>();
    return angle;
}

ParseResult ParseExpr::parseSubExpr()
{
    pair<Lexer::TokenType, ParseResult> token = lexParse.peekToken();

    switch (token.first)
    {
    case Lexer::TokenType::_E: { lexParse.consumeToken(); return ParseResult(boost::math::constants::e<cpp_dec_float_50>(), true); }
    case Lexer::TokenType::_PI: { lexParse.consumeToken(); return ParseResult(boost::math::constants::pi<cpp_dec_float_50>(), false); }
    case Lexer::TokenType::CONSTANT: { lexParse.consumeToken(); return token.second; }
    default:break;
    }

    switch (token.first)
    {
    case Lexer::TokenType::COS:
    case Lexer::TokenType::SIN:
    case Lexer::TokenType::TAN:
    case Lexer::TokenType::ARCCOS:
    case Lexer::TokenType::ARCSIN:
    case Lexer::TokenType::ARCTAN:
    case Lexer::TokenType::CSC:
    case Lexer::TokenType::SEC:
    case Lexer::TokenType::COT:
    case Lexer::TokenType::COSH:
    case Lexer::TokenType::SINH:
    case Lexer::TokenType::TANH:
    case Lexer::TokenType::LN:
    case Lexer::TokenType::LOG:
    case Lexer::TokenType::FABS:
    case Lexer::TokenType::FLOOR:
    case Lexer::TokenType::CEIL:
    case Lexer::TokenType::SQRT:
    case Lexer::TokenType::CBRT:
    {
        lexParse.consumeToken();
        if (lexParse.expectToken(make_pair(Lexer::TokenType::LEFT_BRACKET, ParseResult())) == false)
        {
            return ParseResult();
        }
        lexParse.consumeToken();
        break;
    }
    case Lexer::TokenType::LEFT_BRACKET: { lexParse.consumeToken(); break; }
    default: { return ParseResult(); }
    }

    ParseResult r = parseAddAndMinus();
    if (r.type_flag == ParseResult::type::INVAILD)
        return ParseResult();

    if (lexParse.expectToken(make_pair(Lexer::TokenType::RIGHT_BRACKET, ParseResult())) == false)
    {
        return ParseResult();
    }
    lexParse.consumeToken();

    cpp_dec_float_50 result = to_float_value(r);

    switch (token.first)
    {
    case Lexer::TokenType::LEFT_BRACKET: { return r; }
    case Lexer::TokenType::COS: { result = cos(toRadian(result)); break; }
    case Lexer::TokenType::SIN: { result = sin(toRadian(result)); break; }
    case Lexer::TokenType::TAN: { result = tan(toRadian(result)); break; }
    case Lexer::TokenType::ARCCOS:
    {
        if (!(cpp_dec_float_50(-1.0) <= result && result <= cpp_dec_float_50(1.0)))
        {
            return ParseResult();
        }
        result = toAngle(acos(result));
        break;
    }
    case Lexer::TokenType::ARCSIN:
    {
        if (!(cpp_dec_float_50(-1.0) <= result && result <= cpp_dec_float_50(1.0)))
        {
            return ParseResult();
        }
        result = toAngle(asin(result));
        break;
    }
    case Lexer::TokenType::ARCTAN: { result = toAngle(atan(result)); break; }
    case Lexer::TokenType::CSC:
    {
        cpp_dec_float_50 t = sin(toRadian(result));
        if (t == cpp_dec_float_50(0.0))
        {
            return ParseResult();
        }
        result = cpp_dec_float_50(1.0) / t;
        break; }
    case Lexer::TokenType::SEC:
    {
        cpp_dec_float_50 t = cos(toRadian(result));
        if (t == cpp_dec_float_50(0.0))
        {
            return ParseResult();
        }
        result = cpp_dec_float_50(1.0) / t;
        break;
    }
    case Lexer::TokenType::COT:
    {
        cpp_dec_float_50 t = tan(toRadian(result));
        if (t == cpp_dec_float_50(0.0))
        {
            return ParseResult();
        }
        result = cpp_dec_float_50(1.0) / t;
        break;
    }
    case Lexer::TokenType::COSH: { result = cosh(result); break; }
    case Lexer::TokenType::SINH: { result = sinh(result); break; }
    case Lexer::TokenType::TANH: { result = tanh(result); break; }
    case Lexer::TokenType::LN:
    {
        if (result <= cpp_dec_float_50(0.0))
        {
            return ParseResult();
        }
        result = log(result);
        break;
    }
    case Lexer::TokenType::LOG:
    {
        if (result <= cpp_dec_float_50(0.0))
        {
            return ParseResult();
        }
        result = log10(result);
        break;
    }
    case Lexer::TokenType::FABS: { result = fabs(result); break; }
    case Lexer::TokenType::FLOOR: { result = floor(result); break; }
    case Lexer::TokenType::CEIL: { result = ceil(result); break; }
    case Lexer::TokenType::SQRT:
    {
        if (result < cpp_dec_float_50(0.0))
        {
            return ParseResult();
        }
        result = sqrt(result);
        break;
    }
    case Lexer::TokenType::CBRT: { result = cbrt(result); break; }   //角度弧度转换
    }

    return ParseResult(result, false);
}
