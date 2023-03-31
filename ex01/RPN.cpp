#include "RPN.hpp"

Rpn::Rpn()
{};

Rpn::~Rpn()
{};

Rpn::Rpn(Rpn const & other)
{
    *this = other;
}

Rpn& Rpn::operator=(Rpn const & other)
{
    this->stk = other.stk;
    return *this;
}

void Rpn::all(char *av)
{
    std::stringstream s(av);
    std::string arg;
    
    while (getline(s, arg, ' '))
    {
        std::stringstream value;
        int               v;
        if(isdigit(arg[0]))
        {
            value << arg;
            value >> v;
            
            if(v < 10 || v > 0)
                stk.push(v);
            else
                throw "Error";
        }
        else
        {
            if(stk.size() >= 2)
            {   
            int first = stk.top();
            stk.pop();
            int last = stk.top();
            stk.pop();
            int r;
            switch (arg[0])
            {
            case '+':
                r = last + first;
                break;
            case '-':
                r = last - first;
                break;
            case '*':
                r = last * first;
                break;
            case '/':
                r = last / first;
                break;
            default:
                throw "Error";
            }
            stk.push(r);
            }
            else
                throw "Error";
        }
    }
    if(stk.size() == 1)
        std::cout << stk.top() << std::endl;
    else
        throw "Error";
}