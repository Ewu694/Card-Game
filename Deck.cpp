#include "Deck.hpp"

template <typename CardType> 
Deck<CardType>::Deck(){}

template <typename CardType>
Deck<CardType>::~Deck(){}

template <typename CardType> 
void Deck<CardType>::AddCard(const CardType& card)
{
    cards_.push_back(card);
}

template <typename CardType>
CardType&& Deck<CardType>::Draw()
{
	if(cards_.empty()){
		throw std::runtime_error("Deck is Empty, unable to draw");
	}
    cards_setDrawn(true);
	CardType&& drawnCard = std::move(cards_.back());
    drawnCard.setDrawn(true);
	cards_.pop_back();
	return std::move(drawnCard);
}

template <typename CardType> 
bool Deck<CardType>::IsEmpty() const
{
    return cards_.empty();
}

template <typename CardType> 
void Deck<CardType>::Shuffle()
{
    std::mt19937 randum(2028358904);
    std::shuffle(cards_.begin(), cards_.end(), randum);
}

template <typename CardType> 
int Deck<CardType>::getSize() const
{
    return cards_.size();
}

template <typename CardType> //return vector of cards in deck
std::vector<CardType> Deck<CardType>::getDeck() const
{
    return cards_;
}