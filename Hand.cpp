#include "Hand.hpp"
#include <algorithm>
#include <stack>

Hand::Hand()
{
    std::deque<PointCard> cards_();
}

Hand::~Hand()
{
    cards_.clear();
}

Hand::Hand(const Hand& other)
{
    for (auto itr = other.cards_.cbegin(); itr != other.cards_.cend(); ++itr) 
    {
        PointCard copied_card = *itr;
        cards_.insert(cards_.end(), copied_card);
    }
}

Hand& Hand::operator=(const Hand& other)
{
     if (this != &other) 
     {
        this->cards_.clear();

        for (auto itr = other.cards_.cbegin(); itr != other.cards_.cend(); ++itr) 
        {
            PointCard copied_card = *itr;
            this->cards_.insert(cards_.end(), copied_card);
        }
    }
    return *this;
}

Hand::Hand(Hand&& other)
{
    cards_ = std::move(other.cards_);
    }

Hand& Hand::operator=(Hand&& other){
    std::swap(cards_, other.cards_);
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

void Hand::Reverse() {
    for (size_t i = 0; i < cards_.size() / 2; ++i) {
        std::swap(cards_[i], cards_[cards_.size() - i - 1]);
    }
}

/**
* @post: Play the card at the front of the hand, removing it from the hand
* Throws an exception if the hand is empty or the card is not playable
* If the card is not playable, the card is removed from the hand
* @return the points earned from playing the card
*/
int Hand::PlayCard() {

    PointCard& card = cards_.front();

    try 
    {
        if (isEmpty() == true) 
            throw std::invalid_argument("\nInteger value is required.");
        else
        {
            if (card.isPlayable() == false)
                throw std::invalid_argument("\nCard is not playable.");
            else 
            {
                int num = std::stoi( card.getInstruction() );
                cards_.pop_front();
                return num;
            }
        } 
    } 
    catch (std::invalid_argument& e) 
    {
        std::cerr << "\nError: " << e.what() << " Either the card is not playable or the hand is empty ";
        cards_.pop_front();
        delete card.getImageData();
        return 0;
    }
}