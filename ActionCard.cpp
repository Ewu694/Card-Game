#include "ActionCard.hpp"

ActionCard::ActionCard()
{
    ActionCard action_card;
}

bool ActionCard::isPlayable()
{   
    char delimiter = ' ';//split instructions by spaces
    std::vector<std::string> tokens;//used to store each word after it is split and later used to make it so if the first word is DRAW or PLAY keep it playable without checking for how many cards needs to be drawn
    std::stringstream ss(instruction_);//used to read each instruction to split accordingly
    std::string token;//each word being split
    while(std::getline(ss, token, delimiter))//after splitting, push each singular word into tokens
    {
        tokens.push_back(token);
    } 

    if(drawn_ && (instruction_ == "REVERSE HAND" || instruction_ == "SWAP HAND WITH OPPONENT" || tokens[0] == "DRAW" || tokens[0] == "PLAY"))
    {
        return true;
    }
    return false;
}

void ActionCard::Print() const
{
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;
    if(bitmap_ == nullptr)
        std::cout << "No Image Data Found";
    else
    {
        std::cout << "Card: " << getImageData() << std::endl;
        for(int i = 0; i < 80; ++i)
            std::cout << getImageData()[i] << " ";
    }
}

