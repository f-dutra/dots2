#include "tagsets/t-default.h"

static int topbar              	    = 1;    /* 0 means bottom bar */
static const unsigned int borderpx     = 2;    /* border pixel of windows */
static const unsigned int user_bh      = 12;    /* height of the bar (default: 2) */
static const char *fonts[]     	    = {"MonaspiceNe NFP:size=11:antialias=true:autohint=true"};
static const char black[]      	    = "#301731";
static const char gray[]      	    = "#c6a4cc";
static const char white[]       	    = "#f4c9ef";
static const char red[]       	    = "#c63351";
static const char *colors[][3] 	    = {
	/*	                fg      bg    border   */
	[SchemeNorm] 	  = { black, white, gray  },
	[SchemeSel]  	  = { black, white, white },
	[SchemeStatus]   = { black, gray, black },
	[SchemeLayout]   = { black, white, gray },
	[SchemeTagsNorm] = { black, gray,  gray },
	[SchemeTagsSel]  = { black, white, black },
};

