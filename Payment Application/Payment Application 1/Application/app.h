#include "../Server/server.h"
#include "../Terminal/terminal.h"
#include "../Card/card.h"

#ifndef APP_H
#define APP_H

void appStart(void);


EN_cardError_t getCardData(ST_cardData_t* cardData);
EN_terminalError_t runTerminal(ST_terminalData_t* termData, ST_cardData_t* cardData);
EN_transState_t runServer(ST_transaction_t* transData);

#endif
