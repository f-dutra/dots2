#include "tagsets/t-roman.h"

static int topbar              	    = 1;    /* 0 means bottom bar */
static int hidevacant		 	    = 1;    /* 1 means hide vacant tags */
static const unsigned int borderpx     = 2;    /* border pixel of windows */
static const unsigned int barborderpx  = 0;    /* border pixel of windows */
static const unsigned int barulinepx   = 0;    /* border pixel of windows */
static const unsigned int user_bh      = 4;    /* height of the bar (default: 2) */
static const unsigned int ulinepad	    = 0;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke  = 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset = 0;	/* how far above the bottom of the bar the line should appear */
static const char *fonts[]     	    = {"Cloister Black:size=12:antialias=true:autohint=true"};
static const char black[]      	    = "#111111";
static const char white[]      	    = "#cccccc";
static const char gray[]       	    = "#222222";
static const char lgray[]              = "#777777";
static const char *colors[][3] 	    = {
	/*	                fg      bg    border   */
	[SchemeNorm] 	  = { white, black, gray },
	[SchemeSel]  	  = { white, black, white },
	[SchemeStatus]   = { white, black, black },
	[SchemeTagsNorm] = { white, black, black },
	[SchemeTagsSel]  = { white, gray,  black },
};

