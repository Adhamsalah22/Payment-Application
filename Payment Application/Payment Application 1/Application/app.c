#include<stdio.h>
#include "app.h"

void appStart(void) {

    ST_cardData_t newCard;

    EN_cardError_t  cardError = getCardData(&newCard);

    if (cardError != CARD_OK) {
        return;
    }

    ST_terminalData_t newTerminal;

    EN_terminalError_t terminalError = runTerminal(&newTerminal, &newCard);

    if (terminalError != CARD_OK) {
        return;
    }

    ST_transaction_t newTransaction;
    newTransaction.cardHolderData = newCard;
    newTransaction.terminalData = newTerminal;


    runServer(&newTransaction);

}

EN_cardError_t getCardData(ST_cardData_t* cardData) {

    printf("____________CARD HOLDER DATA____________\n");

    EN_cardError_t error;

    error = getCardHolderName(cardData);


    if (error != CARD_OK)
    {
        printf("\nWrong Name");
        return error;
    }


    error = getCardExpiryDate(cardData);


    if (error != CARD_OK)
    {
        printf("\nWrong Date");
        return error;
    }

    error = getCardPAN(cardData);

    if (error != CARD_OK)
    {
        printf("\nWrong Num");
        return error;
    }

    return CARD_OK;
}
EN_terminalError_t runTerminal(ST_terminalData_t* termData, ST_cardData_t* cardData) {

    printf("\n");
    printf("____________TERMINAL____________\n");
    EN_terminalError_t error;
    getTransactionDate(termData);

    setMaxAmount(termData);

    error = isCardExpired(*cardData, *termData);

    if (error != TERMINAL_OK)
    {
        printf("\nCard is Expired");
        return error;
    }

    error = isValidCardPAN(cardData);

    if (error != TERMINAL_OK)
    {
        printf("\nCard is not Valid");

        return error;
    }

    error = getTransactionAmount(termData);

    if (error != TERMINAL_OK)
    {
        printf("\nInvalid Amount");

        return error;
    }

    error = isBelowMaxAmount(termData);

    if (error != TERMINAL_OK)
    {
        printf("\nExceeded the Maximum");

        return error;
    }

    return TERMINAL_OK;
}
EN_transState_t runServer(ST_transaction_t* transData) {
    printf("\n");
    printf("____________SERVER RESPONSE____________\n");
    EN_transState_t serverError = recieveTransactionData(transData);

    switch (serverError) {

    case DECLINED_INSUFFECIENT_FUND:
        printf("Low Balance");
        break;

    case DECLINED_STOLEN_CARD:
        printf("Stolen Card");
        break;

    case INTERNAL_SERVER_ERROR:
        printf("Transaction Couldn't be Saved ");
        break;

    case APPROVED:
        printf("Transaction is done successfully");
        break;

    default:
        printf("ERROR");
    }




}
