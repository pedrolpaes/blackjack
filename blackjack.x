struct card {
    int key;
    char *card_name;
};

struct deal {
    card *card_1;
    card *card_2;
    card *dealer_card;
};

struct player_call {
    char *player_call;
};

program BLACKJACK {
    version VERSION {
        deal process_call(player_call) = 1;
    } = 1;
} = 1;