#include "Player.hpp"

Player::Player() : hand_(), score_(0), opponent_(nullptr), actiondeck_(nullptr), pointdeck_(nullptr) {}

Player::~Player() {}

const Hand& Player::getHand() const
{
    return hand_;
}

void Player::setHand(const Hand& hand)
{
    hand_ = hand;
}

int Player::getScore() const
{
    return score_;
}

void Player::setScore(const int& score)
{
    score_ = score;
}

void Player::play(ActionCard&& card)
{
    if(!card.isPlayable())
        return;

    std::string instruction = card.getInstruction();
    std::regex playInstruction("PLAY (\\d+) CARD(\\(S\\))?");
    std::regex drawInstruction("DRAW (\\d+) CARD(\\(S\\))?");
    std::smatch match;
    if(std::regex_match(instruction, match, playInstruction))
    {
        int num = std::stoi(match[1].str());
        for(int i = 0; i < num; ++i)
        {
            playPointCard();   
        }
    }
    else if(std::regex_match(instruction, match, drawInstruction))
    {
        int num = std::stoi(match[1].str());
        for(int i = 0; i < num; ++i)
        {
            hand_.addCard(pointdeck_ -> Draw());    
        }
    }
    else if(instruction == "SWAP HAND WITH OPPONENT")
    {
        Hand temp = getHand();
        setHand(opponent_ -> getHand());
        opponent_ -> setHand(temp);
    }
    else if(instruction == "REVERSE HAND")
    {
        hand_.Reverse();
    }
}

void Player::drawPointCard()
{
    pointdeck_ -> Draw();
}

void Player::playPointCard()
{
    
}

void Player::setOpponent(Player* opponent)
{
    opponent_ = opponent;
}

Player* Player::getOpponent()
{
    return opponent_;
}

void Player::setActionDeck(Deck<ActionCard>* actiondeck)
{
    actiondeck_ = actiondeck;
}

Deck<ActionCard>* Player::getActionDeck()
{
    return actiondeck_;
}

void Player::setPointDeck(Deck<PointCard>* pointdeck)
{
    pointdeck_ = pointdeck;
}

Deck<PointCard>* Player::getPointDeck()
{
    return pointdeck_;
}
