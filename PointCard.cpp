#include "PointCard.hpp"

PointCard::PointCard()
{
    PointCard pointCard;
}

bool PointCard::isPlayable()
{
    char delimiter = ' ';//split instructions by spaces
    std::vector<std::string> tokens;//used to store each word after it is split and later used to make it so if the first word is DRAW or PLAY keep it playable without checking for how many cards needs to be drawn
    std::stringstream ss(instruction_);//used to read each instruction to split accordingly
    std::string token;//each word being split
    while(std::getline(ss, token, delimiter))//after splitting, push each singular word into tokens
    {
        tokens.push_back(token);
    } 
    
    int num_instruction = std::stoi(tokens[1]);

    if(drawn_ && num_instruction > 0)
        return true;
    else
        return false;
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