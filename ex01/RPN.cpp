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
    int i = 0;
    while (av[i])
    {
        if (av[i] == ' ')
        {
            i++;
            continue;
        }
        std::stringstream value;
        int               v;
        if(isdigit(av[i]))
        {
            value << av[i];
            value >> v;
            std::cout << "this is v " << v << std::endl; 
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
            switch (av[i])
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
                if (first == 0)
                    throw "Error";
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
        i++;
    }
    if(stk.size() == 1)
        std::cout << stk.top() << std::endl;
    else
        throw "Error";
}