#include "Card.hpp"

Card::~Card()//destructor
{
    delete[] bitmap_;
}


Card::Card(const Card& rhs)//copy constructor
{
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;
    if (rhs.bitmap_ != nullptr) 
    {
        bitmap_ = new int[80]; // Assuming bitmapSize is the size of the array
        std::copy(rhs.bitmap_, rhs.bitmap_ + 80, this -> bitmap_);
    }
    else 
        bitmap_ = nullptr;
}

Card& Card::operator=(const Card& rhs) // Copy Assignment
{
    if (this != &rhs) // Checking for self assignment. So it checks if card1 != card1.
    {
        cardType_ = rhs.cardType_; // you can do this->
        instruction_ = rhs.instruction_;
        drawn_ = rhs.drawn_;

        delete[] bitmap_;

        if (rhs.bitmap_ != nullptr) // just keep bitmap new and for loop
        {
            bitmap_ = new int[80];
            for (int i=0; i<80; i++)
            {
                bitmap_[i] = rhs.bitmap_[i];
            }
        }
        else
        {
            bitmap_= nullptr;
        }
    }
    return *this;
}

Card::Card(Card&& rhs)
{
    instruction_ = std::move(rhs.instruction_); // Using move to change lvalue rvalue. cardType
    drawn_ = std::move(rhs.drawn_);
    cardType_ = std::move(rhs.cardType_);
    bitmap_ = std::move(rhs.bitmap_);

    rhs.bitmap_ = nullptr; // set the rhs.bitmap to nothing. A clean slate.
    rhs.drawn_ = 0; // 0 = false and 1 = true. I might play around with !true to represent false because why not.
}

Card& Card::operator=(Card&& rhs)
{
    if(this != &rhs) // self assignment check
    {
        delete[] bitmap_; // Deallocate previous allocated memory for this object.
        instruction_ = std::move(rhs.instruction_); // cardType_
        cardType_ = std::move(rhs.cardType_);
        drawn_ = std::move(rhs.drawn_);
        bitmap_ = std::move(rhs.bitmap_);

        rhs.bitmap_ = nullptr;
        rhs.drawn_ = 0;
    }
    return *this;
}

std::string Card::getType() const 
{
    switch ((cardType_))
    {
    case POINT_CARD:
        return "POINT_CARD";
        break;
    case ACTION_CARD:
        return "ACTION_CARD";
        break;
    default:
        break;
    }
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
