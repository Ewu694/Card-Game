#include "Card.hpp"

Card::~Card()
{
    delete[] bitmap_;
}

Card::Card(const &Card rhs)
{
    cardType_ = rhs
}

Card::Card()
{
    CardType cardType_ ;
    std::string instruction_ = "";
    int* bitmap_ = 0;
    bool drawn_ = false;
}

std::string getType() const
{
    return 
}

void setType(const CardType& type)
{

}

const std::string& getInstruction() const
{

}

void setInstruction(const std::string& instruction)
{

}

const int* getImageData() const
{

}

void setImageData(int* data)
{

}

bool getDrawn() const
{

}

void setDrawn(const bool& drawn)
{

}
