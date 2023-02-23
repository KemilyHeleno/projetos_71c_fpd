/*
Função de pausa cross-platform
Fonte: 
http://stackoverflow.com/questions/1157209/is-there-an-alternative-sleep-function-in-c-to-milliseconds

Adaptação: Profa. Ariane Scarelli - CTI Unesp - 2015
*/
#include <stdio.h>
#ifdef WIN32
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h>   // for nanosleep
#else
#include <unistd.h> // for usleep
#endif

void sleep_ms(int milliseconds) // cross-platform sleep function
{
#ifdef WIN32
    Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    usleep(milliseconds * 1000);
#endif
}
main()
{
	printf("\nOI");
	sleep_ms(3000);//espera 3 segundos
	printf("\nTCHAU");
}
