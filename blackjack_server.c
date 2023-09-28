/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "blackjack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define DEALER_POINTS_LIMIT = 17

char dealer_hand[15][4] = {};
char player_hand[15][4] = {}; 

struct Deck {
	//int key;
	char *card_name;
};

struct Deck deck[] = {
	"2H","3H","4H","5H","6H","7H","8H","9H","10H", "JH", "QH", "KH", "AH",
	"2D","3D","4D","5D","6D","7D","8D","9D","10D", "JD", "QD", "KD", "AD",
	"2C","3C","4C","5C","6C","7C","8C","9C","10C", "JC", "QC", "KC", "AC",
	"2S","3S","4S","5S","6S","7S","8S","9S","10S", "JS", "QS", "KS", "AS"
	};

int select_card(struct Deck *deck){ // Pick a card position from the deck where the is sure to be a valid card 
	srand(time(NULL)); 
	int num = rand() % 52; // Generate a random number from 0 to 51
	while(deck[num].card_name == NULL ){
		num = rand() % 52; // If there is no card in the position "num" of the deck, keep trying to pick a card with a new position
	}

	return num;
}

void append_card(char hand[][4], char *card){ // Add a given card to a given hand
	for(int i = 0; i < 15; i++){
		if(hand[i][0] == '\0'){
			strcpy(hand[i], card);
			break;
		}
	}
}

int total_points(char hand[][4]){ // Sum the points of a given hand
	int total_sum = 0;
	int ace_counter = 0;
	for(int i=0; i<15; i++){ // Loops the hand searching for points while counting the number of "Ace" cards
		if(hand[i][0] == 'A'){
			ace_counter++;
		}else if(isdigit(hand[i][0]) && strlen(hand[i]) == 2){
			total_sum += hand[i][0] - '0';
		}else{
			total_sum += 10;
		}
	}

	for(int i=0; i<ace_counter; i++){ // Since an "Ace" can be either 1 or 11, which one is the most beneficial to the hand, we need sum it last
		if((total_sum + 11) >= 17){
			total_sum += 1;
		}else{
			total_sum += 11;
		}
	}
	
	return total_sum;
}

int match_result(){
	if(total_points(dealer_hand) > 21 || (total_points(dealer_hand) < total_points(player_hand) && total_points(player_hand) <= 21)){
		return 1;
	} else{
		return 0;
	}
}

deal *
process_call_1_svc(player_call *argp, struct svc_req *rqstp)
{
	printf("@@@@@@@@");
	static deal  result;
	printf("PASSOU AQUI1");
	int card_1 = -1;
	printf("PASSOU AQUI2");
	int card_2 = -1;
	printf("PASSOU AQUI3");
	int face_up_dealer_card = -1;
	printf("PASSOU AQUI4");
	int face_down_dealer_card = -1;
	printf("PASSOU AQUI5");
	//player_hand TODO: Salvar a mao do dealer e do player. Somar o total de pontos na mao do dealer, ele tem que parar assim q tiver mais do qu 17 pontos
	//dealer_hand Se o nome da carta comecar com 'A', ela vale 1 ou 11, se comecar com um numero, ela vale o valor do numero, else ela vale 10
	printf("PASSOU AQUI@@@@@");
	printf("%s", argp->player_call);

	if (strcmp("start", argp->player_call) == 0) {
		card_1 = select_card(deck); 
		result.card_1 = deck[card_1].card_name;
		append_card(player_hand, deck[card_1].card_name);
		deck[card_1].card_name = NULL;

		card_2 = select_card(deck);
		result.card_2 = deck[card_2].card_name;
		append_card(player_hand, deck[card_2].card_name);
		deck[card_2].card_name = NULL;

		face_up_dealer_card = select_card(deck);
		result.dealer_card = deck[face_up_dealer_card].card_name;
		append_card(dealer_hand, deck[face_up_dealer_card].card_name);
		deck[face_up_dealer_card].card_name = NULL;

		face_down_dealer_card = select_card(deck);
		append_card(dealer_hand, deck[face_down_dealer_card].card_name);
		deck[face_down_dealer_card].card_name = NULL;

		char buffer[256];
    	sprintf(buffer, "Your hand is %s and %s. The dealer face up card is %s", result.card_1, result.card_2, result.dealer_card);
    	strcpy(result.msg, buffer);

		return &result;

	}else if (strcmp("hit", argp->player_call) == 0) {
		card_1 = select_card(deck); 
		result.card_1 = deck[card_1].card_name;
		append_card(player_hand, deck[card_1].card_name);
		deck[card_1].card_name = NULL;
		if(total_points(dealer_hand)<17){
			face_up_dealer_card = select_card(deck);
			result.dealer_card = deck[face_up_dealer_card].card_name;
			append_card(dealer_hand, deck[face_up_dealer_card].card_name);
			deck[face_up_dealer_card].card_name = NULL;
		}
		if(match_result() == 1){
			char buffer[50];
    		sprintf(buffer, "You Win!");
    		strcpy(result.msg, buffer);
		}else{
			char buffer[50];
    		sprintf(buffer, "You Lose...");
    		strcpy(result.msg, buffer);
		}

		return &result;

	}else if (strcmp("stand", argp->player_call) == 0) {
		if(total_points(dealer_hand)<17){
			face_up_dealer_card = select_card(deck);
			result.dealer_card = deck[face_up_dealer_card].card_name;
			append_card(dealer_hand, deck[face_up_dealer_card].card_name);
			deck[face_up_dealer_card].card_name = NULL;
		}
		if(match_result() == 1){
			char buffer[50];
    		sprintf(buffer, "You Win!");
    		strcpy(result.msg, buffer);
		}else{
			char buffer[50];
    		sprintf(buffer, "You Lose...");
    		strcpy(result.msg, buffer);
		}

		return &result;
	}

	return &result;
}



