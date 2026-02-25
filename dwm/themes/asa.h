#include "tagsets/t-default.h"

static int topbar              	   = 1;    /* 0 means bottom bar */
static const unsigned int borderpx    = 2;    /* border pixel of windows */
static const unsigned int barborderpx = 2;    /* border pixel of windows */
static const unsigned int padding     = 4;    /* height of the bar (default: 2) */
static const char *fonts[]     	   = {"MonaspiceNE NFP:size=10:antialias=true:autohint=true"};
static const char black[]      	   = "#000000";
static const char white[]       	   = "#f0f0f0";
static const char *colors[][3] 	   = {
	/*	                fg      bg    border   */
	[SchemeNorm] 	  = { white, black,  black },
	[SchemeSel]  	  = { black, white,  white },
	[SchemeStatus]   = { white, black,  black },
	[SchemeTagsNorm] = { white, black,  black },
	[SchemeTagsSel]  = { black, white,  black },
};

