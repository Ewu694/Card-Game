#include "PointCard.hpp"

PointCard::PointCard()
{
    PointCard pointCard;
}

bool PointCard::isPlayable()
{

}

void PointCard::Print() const
{
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;
    if(bitmap_ == nullptr)
        std::cout << "No Image Data Found";
    else
    {
        std::cout << "Card: " << getImageData() << std::endl;
        for(int i = 0; i < 80; ++i)
            std::cout << bitmap_[i];
    }
}