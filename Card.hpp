#ifndef CARD_HPP_
#define CARD_HPP_
#include <iostream>
#include <string>

/**
* Destructor
* @post: Destroy the Card object
*/
˜Card();
/**
* Copy Constructor
* @post: Construct a new Card object
* @param: const reference to a Card object
*/
Card(const Card& rhs);
/**
* Copy Assignment Operator
* @param const reference to a Card object
* @return this Card object
*/
Card& operator=(const Card& rhs);
/**
* Move Constructor
* @param: rvalue reference to a Card object
*/
Card(Card&& rhs);
/**
* Move assignment operator
* @param: rvalue reference to a Card object
* @return this card object
*/
Card& operator=(Card&& rhs);
/**
* Default Constructor
* @post: Construct a new Card object
*/
Card();
/**
* @return the string representation of the card type
*/
std::string getType() const;
/**
* @post: set the card type
* @param const reference to a CardType object
*/
void setType(const CardType& type);

/**
* @return the string representation of the card instruction
*/
const std::string& getInstruction() const;
/**
* @post: set the card instruction
* @param: const reference to an instruction
*/
void setInstruction(const std::string& instruction);
/**
* @return the image data
*/
const int* getImageData() const;
/**
* @post: Set the image data
* @param pointer to an array of integers
*/
void setImageData(int* data);
/**
* @return the drawn status of the card
*/
bool getDrawn() const;
/**
* @post: set the drawn status of the card
*
* @param: const reference to a boolean
*/
void setDrawn(const bool& drawn);
// Pure Virtual Functions : No implementation required
virtual void Print() const = 0;
virtual bool isPlayable() = 0;

#endif