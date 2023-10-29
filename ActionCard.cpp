#include "ActionCard.hpp"

virtual bool Card::isPlayable() override
{
    if(drawn_ && (stoi(instruction_) >= 1))
    {
        return true;
    }
}

virtual void Print() const override
{

}

