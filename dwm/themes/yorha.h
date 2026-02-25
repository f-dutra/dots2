#include "tagsets/t-default.h"

static int topbar              	    = 1;    /* 0 means bottom bar */
static const unsigned int padding      = 3;    /* border pixel of windows */
static const unsigned int borderpx     = 2;    /* border pixel of windows */
static const char *fonts[]     	    = {"MonaspiceNe NFP:size=11:antialias=true:autohint=true"};
static const char black[]      	    = "#222222";
static const char gray[]      	    = "#baafa1";
static const char white[]       	    = "#d9caba";
static const char *colors[][3] 	    = {
	/*	                fg      bg    border   */
	[SchemeNorm] 	  = { black, white, gray  },
	[SchemeSel]  	  = { black, white, white },
	[SchemeStatus]   = { black, white, black },
	[SchemeLayout]   = { black, white, gray },
	[SchemeTagsNorm] = { black, gray,  gray },
	[SchemeTagsSel]  = { black, white, black },
};

