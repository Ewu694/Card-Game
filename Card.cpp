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

Card& Card::operator=(const Card& rhs)//copy assignment operator
{   
    if (this == &rhs) {
        return *this; // Self-assignment, no need to do anything
    }
    // Release any previously allocated memory for bitmap_
    delete[] this -> bitmap_;
    this -> cardType_ = rhs.cardType_;
    this -> instruction_ = rhs.instruction_;
    this -> drawn_ = rhs.drawn_;
    if (rhs.bitmap_ != nullptr) {
        this -> bitmap_ = new int[80]; // Assuming bitmapSize is the size of the array
        std::copy(rhs.bitmap_, rhs.bitmap_ + 80, this -> bitmap_);
    } else {
        this -> bitmap_ = nullptr;
    }
    // Initialize other members as necessary
    return *this;
}

Card::Card(Card&& rhs)//movement constructor
    :cardType_(rhs.cardType_), instruction_(std::move(rhs.instruction_)), bitmap_(std::move(rhs.bitmap_)), drawn_(rhs.drawn_)
    {
        rhs.bitmap_ = nullptr;
    }

Card& Card::operator=(Card&& rhs)
{
    if(this == &rhs)
        return *this;//if its already the same, nothing needs to be moved or changed

    delete[] bitmap_;//deletes current bitmap

    cardType_ = std::move(rhs.cardType_);
    instruction_ = std::move(rhs.instruction_);
    bitmap_ = std::move(rhs.bitmap_);  
    drawn_ = std::move(rhs.drawn_);

    rhs.bitmap_ = nullptr; //deallocates the source object

    return *this;
}

Card::Card()
{
    CardType cardType_;
    std::string instruction_ = "";
    int* bitmap_ = 0;
    bool drawn_ = false;
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
