#include "Hand.hpp"

Hand::Hand() : cards_() {}

Hand::~Hand() {}

Hand::Hand(const Hand& other) 
{
    for (const PointCard& card : other.cards_) {
        cards_.emplace_back(card); //constructs the objects into the vector, can use insert to copy into constructor instead
    }
}

// Copy Assignment Operator
Hand& Hand::operator=(const Hand& other) {
    if (this != &other) {
        cards_.clear();// Clear the current contents in the vector
        for (const PointCard& card : other.cards_) {
            cards_.emplace_back(card); 
        }
    }
    return *this;
}

Hand::Hand(Hand&& other) : cards_(std::move(other.cards_)) {}

Hand& Hand::operator=(Hand&& other) {
    if (this != &other) {
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
    cards_.emplace_back(card);
}

bool Hand::isEmpty() const
{
    if(cards_.size() == 0)
    {
        return true;
    }
    return false;
}

void Hand::Reverse()
{
    
}