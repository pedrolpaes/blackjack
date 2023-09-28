
struct comms {
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