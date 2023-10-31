#include "Deck.hpp"


template <typename CardType>
Deck<CardType>::Deck() : cards() {}

template <typename CardType>
Deck<CardType>::~Deck()
{
}

template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card)
{   

}

template <typename CardType>
CardType&& Deck<CardType>::Draw()
{
}

template <typename CardType>
bool Deck<CardType>::IsEmpty() const
{
    if(cards_.size == 0)
        return true;
    return false;
}

template <typename CardType>
void Deck<CardType>::Shuffle()
{

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
