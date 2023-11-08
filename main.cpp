#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Player.hpp"
#include "Hand.hpp"

int main() {
    int bitmap[80];
    for (int i = 0; i < 80; ++i) {
        bitmap[i] = i;
    }

    std::cout << "Testing badACard1:" << std::endl;

    ActionCard badACard1;
    badACard1.setType(ACTION_CARD);
    badACard1.setInstruction("DRAWS 2.0 CARD(S)");
    badACard1.setDrawn(false);
    badACard1.setImageData(bitmap);
    std::cout << "Expected Output: ACTION_CARD" << std::endl << "Actual Output: ";
    std::cout << badACard1.getType() << std::endl;
    std::cout << std::endl;
    std::cout << "Expected Output: DRAWS 2.0 CARD(S)" << std::endl << "Actual Output: ";
    std::cout << badACard1.getInstruction() << std::endl;
    std::cout << std::endl;
    std::cout << "Expected Output: 0" << std::endl << "Actual Output: ";
    std::cout << badACard1.getDrawn() << std::endl;
    std::cout << "Expected Output: 0" << std::endl << "Actual Output: ";
    std::cout << badACard1.isPlayable() << std::endl;
    std::cout << std::endl;
    std::cout << "Expected Output: 0 1 2 ... 78 79 //the dots will have integers" << std::endl << "Actual Output: ";
    if (badACard1.getImageData() != nullptr) {
        for (int i = 0; i < 80; i++) {
            std::cout << badACard1.getImageData()[i] << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "No image data" << std::endl;
    } 

    std::cout << std::endl;
    
    std::cout << "Testing badACard2:" << std::endl;

    ActionCard badACard2;
    badACard2.setType(ACTION_CARD);
    badACard2.setInstruction("DRAW 99 CARD(S)");
    badACard2.setDrawn(true);
    std::cout << "Expected Output: ACTION_CARD" << std::endl << "Actual Output: ";
    std::cout << badACard2.getType() << std::endl; 
    std::cout << std::endl;
    std::cout << "Expected Output: DRAW 99 CARD(S)" << std::endl << "Actual Output: ";
    std::cout << badACard2.getInstruction() << std::endl;
    std::cout << std::endl;
    std::cout << "Expected Output: 1" << std::endl << "Actual Output: ";
    std::cout << badACard2.getDrawn() << std::endl;
    std::cout << "Expected Output: 1" << std::endl << "Actual Output: ";
    std::cout << badACard2.isPlayable() << std::endl;
    std::cout << std::endl;
    std::cout << "Expected Output: No image data" << std::endl << "Actual Output: ";
    if (badACard2.getImageData() != nullptr) {
        for (int i = 0; i < 80; i++) {
            std::cout << badACard2.getImageData()[i] << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "No image data" << std::endl;
    } 

    std::cout << std::endl;

    std::cout << "Testing goodACard1:" << std::endl;

    ActionCard goodACard1;
    goodACard1.setType(ACTION_CARD);
    goodACard1.setInstruction("DRAW 99 CARD(S)");
    goodACard1.setDrawn(true);
    goodACard1.setImageData(bitmap);
    std::cout << "Expected Output: ACTION_CARD" << std::endl << "Actual Output: ";
    std::cout << goodACard1.getType() << std::endl; 
    std::cout << std::endl;
    std::cout << "Expected Output: DRAW 99 CARD(S)" << std::endl << "Actual Output: ";
    std::cout << goodACard1.getInstruction() << std::endl;
    std::cout << std::endl;
    std::cout << "Expected Output: 1" << std::endl << "Actual Output: ";
    std::cout << goodACard1.getDrawn() << std::endl;
    std::cout << std::endl;
    std::cout << "Expected Output: 1" << std::endl << "Actual Output: ";
    std::cout << goodACard1.isPlayable() << std::endl;
    std::cout << std::endl;
    std::cout << "Expected Output: 0 1 2 ... 78 79 //the dots will have integers" << std::endl << "Actual Output: ";
    if (goodACard1.getImageData() != nullptr) {
        for (int i = 0; i < 80; i++) {
            std::cout << goodACard1.getImageData()[i] << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "No image data" << std::endl;
    } 
    
    std::cout << std::endl;

    return 0;
}