#include "tagsets/t-default.h"

static int topbar              	    = 1;    /* 0 means bottom bar */
static const unsigned int borderpx     = 1;    /* border pixel of windows */
static const unsigned int padding      = 0;    /* border pixel of windows */
static const char *fonts[]     	    = {"Jetbrains Mono NerdFont:size=10"};
static const char black[]      	    = "#000000";
static const char gray[]      	    = "#42be65";
static const char white[]       	    = "#eeeeee";
static const char *colors[][3] 	    = {
	/*	                fg      bg    border   */
	[SchemeNorm] 	  = { white, black, black },
	[SchemeSel]  	  = { white, black, white },
	[SchemeStatus]   = { white, black, white },
	[SchemeTagsNorm] = { white, black, white },
	[SchemeTagsSel]  = { black, gray,  white },
};

