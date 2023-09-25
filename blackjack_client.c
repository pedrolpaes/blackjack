/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "blackjack.h"


void
blackjack_1(char *host)
{
	CLIENT *clnt;
	deal  *result_1;
	player_call  process_call_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, BLACKJACK, VERSION, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = process_call_1(&process_call_1_arg, clnt);
	if (result_1 == (deal *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	blackjack_1 (host);
exit (0);
}
