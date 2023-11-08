#include "Card.hpp"

Card::~Card(){
	delete bitmap_;
	bitmap_= nullptr;
}

Card::Card(const Card& rhs){
	instruction_= rhs.instruction_;
	drawn_ = rhs.drawn_;
	cardType_ = rhs.cardType_;
	bitmap_= new int[80];
	for(int i=0; i<80; i++){
		bitmap_[i] = rhs.bitmap_[i];
	}
}

Card& Card::operator=(const Card& rhs){
	if(this!=&rhs){
		instruction_ = rhs.instruction_;
		drawn_ = rhs.drawn_;
		cardType_ = rhs.cardType_;
		delete bitmap_;
		bitmap_ = new int[80];
		for(int i=0; i<80; i++){
			bitmap_[i] = rhs.bitmap_[i];
		}
	}
	return *this;
}

Card::Card(Card&& rhs){
	cardType_ = rhs.cardType_;
	drawn_= rhs.drawn_;
	instruction_ = std::move(rhs.instruction_);
	bitmap_= rhs.bitmap_;
	rhs.bitmap_ = nullptr;
}

Card& Card::operator=(Card&& rhs){
	if(this != &rhs){
		cardType_ = rhs.cardType_;
		drawn_= rhs.drawn_;
		instruction_ = std::move(rhs.instruction_);
		delete bitmap_;
		bitmap_= nullptr;
		bitmap_ = rhs.bitmap_;
		rhs.bitmap_ = nullptr;
	}
	return *this;	
}

Card::Card()
{
    cardType_ = POINT_CARD;
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
