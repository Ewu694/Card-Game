#include "PointCard.hpp"

PointCard::PointCard()
{
    setDrawn(false);
    setImageData(nullptr);
    setType(POINT_CARD);
    setInstruction("");
}

bool PointCard::isPlayable()
{
    if(getDrawn() && std::stoi(getInstruction()) >= 0)
        return true;  
    return false;
}

void PointCard::Print() const
{
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;
    if(getImageData() != nullptr)
    {
        for(int i = 0; i < 80; ++i)
        {
            std::cout << getImageData()[i] << " " << std::endl;
        }
    }
    else
    {
        std::cout << "No image data" << std::endl;
    }
}
