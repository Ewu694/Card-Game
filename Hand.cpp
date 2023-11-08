#include "Hand.hpp"
#include <algorithm>
#include <stack>

Hand::Hand(){}

Hand::~Hand()
{
    while(!this->isEmpty()){
        cards_.pop_back();
    }
}

Hand::Hand(const Hand& other)
{
    for (auto card : other.cards_){
        this -> cards_.push_back(card);
    }
}

Hand& Hand::operator=(const Hand& other)
{
    for (auto card : other.cards_){
        this -> cards_.push_back(card);
    }
    return *this;
}

Hand::Hand(Hand&& other)
{
    this -> cards_ = std::move(other.cards_);
}

Hand& Hand::operator=(Hand&& other){
    if (this != &other){
        cards_ = std::move(other.cards_);
    }
    return *this;
}

const std::deque<PointCard>& Hand::getCards() const
{
    return cards_;
}

void Hand::addCard(PointCard&& card)
{
   card.setDrawn(true);
   cards_.push_back(std::move(card));
}

bool Hand::isEmpty() const
{
    return (cards_.size() == 0);
}

void Hand::Reverse()
{
    std::stack <PointCard> reverse;
    while(!cards_.empty()){
        reverse.push(cards_.back());
        cards_.pop_back();
    }
    while(!reverse.empty()){
        cards_.push_front(reverse.top());
        reverse.pop();
    }
}

int Hand::PlayCard()
{
    if(isEmpty())
        throw std::invalid_argument("No cards in hand"); 
    else if(cards_[0].isPlayable() == false)
    {
        throw std::invalid_argument("Card is not playable");
        cards_.pop_front();
    }
    else
        cards_.pop_front();
        return std::stoi(cards_[0].getInstruction());
}