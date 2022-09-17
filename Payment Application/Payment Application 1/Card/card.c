#include <stdio.h>
#include "card.h"
#include <string.h>

EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {

    printf("Plz Enter Card Name: ");
    gets(cardData->cardHolderName);
    uint32_t i = strlen(cardData->cardHolderName);

    if (i > 24 || i < 20) {
        return WRONG_NAME;
    }

    return CARD_OK;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {

    printf("Plz Enter Expiry Date As 'MM/YY' : ");
    gets(cardData->cardExpirationDate);
    uint32_t i = strlen(cardData->cardExpirationDate);

    if (i != 5 || cardData->cardExpirationDate[2] != '/') {
        return WRONG_EXP_DATE;
    }

    return CARD_OK;
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData) {

    printf("PlZ Enter Card PAN: ");
    gets(cardData->primaryAccountNumber);
    uint32_t i = strlen(cardData->primaryAccountNumber);

    if (i > 19 || i < 16) {
        return WRONG_PAN;
    }

    return CARD_OK;
}

/*
// getCardHolderName function testing

int main() {

    ST_cardData_t buyer;
    EN_cardError_t error = getCardHolderName(&buyer);

    if (error == CARD_OK) {

        printf("The Name Is Correct.");
        return 0;
    }

    printf("The Name Is Not Correct.");

}
*/

/*
// getCardExpiryDate function testing


int main(){

    ST_cardData_t buyer ;
    EN_cardError_t error = getCardExpiryDate(&buyer);

    if(error == CARD_OK){

        printf("The Date Is Correct.");
        return 0;
    } else
        printf("The Date Is NOT Correct.");
}
*/


/*
// getCardPAN function testing
int main(){

    ST_cardData_t buyer ;
    EN_cardError_t error = getCardPAN(&buyer);

    if(error == CARD_OK){
        printf("Correctly PAN.");
        return 0;
    }
    printf("Incorrectly PAN.");

}
*/