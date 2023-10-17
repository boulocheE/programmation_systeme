#include <stdio.h>
#include <sys/types.h>

// Handler (fonction) associée au signal SIGINT
void traitement (int sig)
{
    if (sig == SIGINT)
        printf("signal SIGINT reçu !\n");
    if ( sig == SIGUSR1 )
        printf("signal SIGINTR1 reçu !\n")
}


int main ()
{
    struct sigaction action;
    sigset_t masque;

    sigemptyset(&masque);

    action.sa_handler = traitement;
    action.sa_mask    = masque;
    action.sa_flags   = 0;

    sigaction(SIGINT,  &action, null);
    sigaction(SIGUSR1, &action, null);

    printf("Mon pid est %d\n", getpid());

    while(1)
    {
        printf ("un tour !\n");
        sleep(1);
    }
}