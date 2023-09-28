/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "blackjack.h"


void
blackjack_2(char *host)
{
	CLIENT *clnt;
	comms  *result_1;
	comms  process_call_2_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, BLACKJACK, VERSION, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	printf("Select 'start', 'hit' or 'stand'\n");
	scanf("%s", process_call_2_arg.player_call);
	result_1 = process_call_2(&process_call_2_arg, clnt);
	
	printf("%s\n", result_1->msg);
	if (result_1 == (comms *) NULL) {
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
	blackjack_2 (host);
exit (0);
}
