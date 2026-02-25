#include "tagsets/t-default.h"

static int topbar              	    = 1;    /* 0 means bottom bar */
static const unsigned int borderpx     = 1;    /* border pixel of windows */
static const unsigned int padding      = 1;    /* border pixel of windows */
static const char *fonts[]     	    = {"MonaspiceNe NFP:size=11:antialias=true:autohint=true"};
static const char black[]      	    = "#1d2021";
static const char gray[]      	    = "#cc241d";
static const char white[]       	    = "#eeeeee";
static const char *colors[][3] 	    = {
	/*	                fg      bg    border   */
	[SchemeNorm] 	  = { white, black, gray  },
	[SchemeSel]  	  = { white, black, white },
	[SchemeStatus]   = { white, black, white },
	[SchemeTagsNorm] = { white, black, white },
	[SchemeTagsSel]  = { white, gray, white },
};

