/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "blackjack.h"

bool_t
xdr_card (XDR *xdrs, card *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->key))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->card_name, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_deal (XDR *xdrs, deal *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)&objp->card_1, sizeof (card), (xdrproc_t) xdr_card))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->card_2, sizeof (card), (xdrproc_t) xdr_card))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->dealer_card, sizeof (card), (xdrproc_t) xdr_card))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_player_call (XDR *xdrs, player_call *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)&objp->player_call, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}
