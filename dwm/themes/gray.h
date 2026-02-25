#include "tagsets/t-default.h"

static int topbar              	    = 1;    /* 0 means bottom bar */
static const unsigned int borderpx     = 1;    /* border pixel of windows */
static const unsigned int padding      = 3;    /* border pixel of windows */
static const char *fonts[]     	    = {"MonaspiceNe NFP:size=11:antialias=true:autohint=true"};
static const char black[]      	    = "#222222";
static const char gray[]      	    = "#a0a0a0";
static const char white[]       	    = "#cccccc";
static const char *colors[][3] 	    = {
	/*	                fg      bg    border   */
	[SchemeNorm] 	  = { black, white,  black },
	[SchemeSel]  	  = { black, white,  white  },
	[SchemeStatus]   = { black, white,  black },
	[SchemeTagsNorm] = { black, gray,  black },
	[SchemeTagsSel]  = { black, white, black },
};

