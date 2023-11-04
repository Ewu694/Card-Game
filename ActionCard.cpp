#include "ActionCard.hpp"

ActionCard::ActionCard()
{
    setDrawn(false);
    setImageData(nullptr);
    setType(ACTION_CARD);
    setInstruction("");
}

bool ActionCard::isPlayable()
{   
    std::regex drawRegex("^DRAW [0-9] CARD\\(S\\)");
    std::regex playRegex("PLAY [0-9] CARD\\(S\\)");

    if(std::regex_match(getInstruction(), drawRegex) || std::regex_match(getInstruction(), playRegex) || getInstruction() == "REVERSE HAND" || getInstruction() == "SWAP HAND WITH OPPONENT")
        return true;  
    return false;
}


/**
 * @post: Print the ActionCard in the following format:
 * Type: [CardType]
 * Instruction: [Instruction]
 * Card: 
 * [ImageData]
 * 
 * Note: For [ImageData]: If there is no image data, print "No image data" instead
 */
void ActionCard::Print() const
{
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;
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

