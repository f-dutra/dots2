#include "tagsets/t-default.h"

static int topbar              	    = 1;    /* 0 means bottom bar */
static const unsigned int padding      = 3;    /* border pixel of windows */
static const unsigned int borderpx     = 2;    /* border pixel of windows */
static const char *fonts[]     	    = {"MonaspiceNe NFP:size=10:antialias=true:autohint=true"};
static const char black[]      	    = "#000000";
static const char white[]       	    = "#eeeeee";
static const char blue[]			    = "#6376cf";
static const char *colors[][3] 	    = {
	/*	                fg      bg    border   */
	[SchemeNorm] 	  = { white, black, black },
	[SchemeSel]  	  = { black, blue,  blue  },
	[SchemeStatus]   = { white, black, black },
	[SchemeLayout]   = { white, black, black },
	[SchemeTagsNorm] = { white, black, black },
	[SchemeTagsSel]  = { black, blue,  black },
};

