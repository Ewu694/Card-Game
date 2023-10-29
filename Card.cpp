#include "Card.hpp"

Card::~Card()
{
    delete[] bitmap_;
}

Card::Card(const Card& rhs)
{
    cardType_ = rhs.cardType_;
    bitmap_ = rhs.bitmap_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;
}

Card& operator=(const Card& rhs)
{
    
}

Card::Card()
{
    CardType cardType_;
    std::string instruction_ = "";
    int* bitmap_ = 0;
    bool drawn_ = false;
}

const char* cardTypes[] = {"POINT_CARD", "ACTION_CARD"};

std::string Card::enumToString(const CardType& card)
{
    return cardTypes[card];
}

std::string Card::getType() const
{
    return enumToString(cardType_);
}   

void Card::setType(const CardType& type)
{
    cardType_ = type;
}

const std::string& Card::getInstruction() const
{
    return instruction_;
}

void Card::setInstruction(const std::string& instruction)
{
    instruction_ = instruction;
}

const int* Card::getImageData() const
{
    return bitmap_;
}

void Card::setImageData(int* data)
{
    bitmap_ = data;
}

bool Card::getDrawn() const
{
    return drawn_;
}

void Card::setDrawn(const bool& drawn)
{
    drawn_ = drawn;
}
