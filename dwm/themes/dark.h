#include "tagsets/t-default.h"

static int topbar              	    = 1;    /* 0 means bottom bar */
static const unsigned int borderpx     = 1;    /* border pixel of windows */
static const char *fonts[]     	    = {"MonaspiceNe NFP:size=11.5:antialias=true:autohint=true"};
static const char black[]      	    = "#000000";
static const char gray[]      	    = "#0f0f0f";
static const char white[]       	    = "#dddddd";
static const char *colors[][3] 	    = {
	/*	                fg      bg    border   */
	[SchemeNorm] 	  = { white, black, black },
	[SchemeSel]  	  = { white, black, white },
	[SchemeStatus]   = { white, black, black },
	[SchemeTagsNorm] = { white, gray,  black },
	[SchemeTagsSel]  = { white, black, black },
};

