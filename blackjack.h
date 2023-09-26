/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _BLACKJACK_H_RPCGEN
#define _BLACKJACK_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct card {
	int key;
	char *card_name;
};
typedef struct card card;

struct deal {
	card *card_1;
	card *card_2;
	card *dealer_card;
	char msg[50];
};
typedef struct deal deal;

struct player_call {
	char *player_call;
};
typedef struct player_call player_call;

#define BLACKJACK 1
#define VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define process_call 1
extern  deal * process_call_1(player_call *, CLIENT *);
extern  deal * process_call_1_svc(player_call *, struct svc_req *);
extern int blackjack_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define process_call 1
extern  deal * process_call_1();
extern  deal * process_call_1_svc();
extern int blackjack_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_card (XDR *, card*);
extern  bool_t xdr_deal (XDR *, deal*);
extern  bool_t xdr_player_call (XDR *, player_call*);

#else /* K&R C */
extern bool_t xdr_card ();
extern bool_t xdr_deal ();
extern bool_t xdr_player_call ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_BLACKJACK_H_RPCGEN */
