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
    std::cout << "Instruction: " << getInstruction() << std::endl;
    const int* imageData = getImageData();
    if(bitmap_ == nullptr)
    {
    std::cout << "Card: " << imageData << std::endl;
    std::cout << "No image data";
    }
    else
    {
        std::cout << "Card: " << imageData << std::endl;
        std::cout << getInstruction() << std::endl;
    }
}