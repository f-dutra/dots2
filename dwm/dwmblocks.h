#define CMDLENGTH		50

typedef struct {
	char* icon;
	char* command;
	unsigned int interval;
	unsigned int signal;
} Block;

static void sighandler();
static void buttonhandler(int ssi_int);
static void replace(char *str, char old, char new);
static void remove_all(char *str, char to_remove);
static void getcmds(int time);
static void getsigcmds(int signal);
static void setupsignals();
static int  getstatus(char *str, char *last);
static void setroot();
static void statusloop();
static void termhandler(int signum);


#include "config.h"

static char statusbar[LENGTH(blocks)][CMDLENGTH] = {0};
static char statusstr[2][256];
static int  statusContinue = 1;
static int  signalFD;
static int  timerInterval = -1;
static void (*writestatus) () = setroot;

