#include "Card.hpp"

Card::~Card()
{
    if(bitmap_ != nullptr)
        delete[] bitmap_;
	bitmap_= nullptr;
}

Card::Card(const Card& rhs)
{
	instruction_= rhs.instruction_;
	drawn_ = rhs.drawn_;
	cardType_ = rhs.cardType_;
    if(rhs.bitmap_ == nullptr)
    {
        bitmap_ = nullptr;
    }
    else{
	    bitmap_ = new int[80];//creates a bitmap of size 80 as per project specifications
	    for(int i = 0; i < 80; ++i){
		    bitmap_[i] = rhs.bitmap_[i];
	    }
    }
}

Card& Card::operator=(const Card& rhs)
{
	if(this != &rhs){//if this lhs isn't equal to rhs then:
		instruction_ = rhs.instruction_;
		drawn_ = rhs.drawn_;
		cardType_ = rhs.cardType_;
		delete[] bitmap_;//deallocates bitmap to make sure it is empty for when we set add the rhs values into it
		bitmap_ = new int[80];//only goes up to 80 per project specifications
		for(int i = 0; i < 80; ++i){
			bitmap_[i] = rhs.bitmap_[i];
		}
	}
	return *this;
}

Card::Card(Card&& rhs)
{
	cardType_ = rhs.cardType_;
	drawn_= rhs.drawn_;
	instruction_ = std::move(rhs.instruction_);
	bitmap_= rhs.bitmap_;
	rhs.bitmap_ = nullptr;
}

Card& Card::operator=(Card&& rhs)
{
	if(this != &rhs){//if lhs not equal to rhs then: 
		cardType_ = rhs.cardType_;
		drawn_= rhs.drawn_;
		instruction_ = std::move(rhs.instruction_);
		delete[] bitmap_;//deallocates bitmap to make sure it is empty for when we set add the rhs values into it
		bitmap_= nullptr;
		bitmap_ = rhs.bitmap_;
		rhs.bitmap_ = nullptr;
	}
	return *this;	
}

Card::Card()
{
    instruction_ = "";
    bitmap_ = nullptr;
    drawn_ = false;
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
