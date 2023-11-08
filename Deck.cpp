#include "Deck.hpp"


template <typename CardType>
Deck<CardType>::Deck() : cards_(){}

template <typename CardType>
Deck<CardType>::~Deck(){}

template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card)
{   
    cards_.push_back(card);
}

/**
 * @post: Draw a card from the deck
 * @pre: the deck is not empty
 * @return the right-hand value of type CardType 
 */
template <typename CardType>
CardType&& Deck<CardType>::Draw()
{
    if(IsEmpty() == false)
    {
        CardType && card = std::move(cards_.back());
        cards_.pop_back();
        return std::move(card);
    }
}

template <typename CardType>
bool Deck<CardType>::IsEmpty() const
{
    return cards_.empty();
}

template <typename CardType>
void Deck<CardType>::Shuffle()
{
    std::mt19937 rng(2028358904);
    std::shuffle(cards_.begin(), cards_.end(), rng);
}

template<typename CardType>
int Deck<CardType>::getSize() const
{
    return cards_.size();
}

template<typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const
{
    return cards_;
}
