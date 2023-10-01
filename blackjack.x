typedef char card[15];

typedef card dealer_hand_commns[4];
typedef card player_hand_commns[4];

struct comms {
    dealer_hand_commns dh;
    player_hand_commns ph;
    char card_1[4];
    char card_2[4];
    char dealer_card[4];
    char msg[50];
    char player_call[10];
};

program BLACKJACK {
    version VERSION {
        comms process_call(comms) = 1;
    } = 2;
} = 2;