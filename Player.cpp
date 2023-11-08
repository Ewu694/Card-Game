#include "Player.hpp"

Player::Player(): score_(0), opponent_(nullptr){

    actiondeck_ = new Deck<ActionCard>();
    pointdeck_ = new Deck<PointCard>();
}

Player::~Player(){

    delete actiondeck_;
    delete pointdeck_;
}

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
    if(!card.isPlayable())//edge case
        return;

    std::string instruction = card.getInstruction();
    std::regex playInstruction("PLAY (\\d+) CARD(\\(S\\))?");//regex for play instructions
    std::regex drawInstruction("DRAW (\\d+) CARD(\\(S\\))?");//regex for draw instructions
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
            drawPointCard();   
        }
    }
    else if(instruction == "SWAP HAND WITH OPPONENT")
    {
        Hand temp = std::move(getHand());//temp is the player hand
        setHand(std::move(opponent_ -> getHand()));//set player's hand to opponent hand with move semantics
        opponent_ -> setHand(std::move(temp));//set opponent's hand to player hand with move semantics
    }
    else if(instruction == "REVERSE HAND")
    {
        hand_.Reverse();
    }
}

void Player::drawPointCard()
{
    hand_.addCard(std::move(pointdeck_ -> Draw()));
}

void Player::playPointCard()
{
    if(!hand_.isEmpty())
        score_ += hand_.PlayCard();
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
