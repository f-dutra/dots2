//#include "tagsets/t-default.h"
#include "tagsets.h"

static const unsigned int snap   = 0;   /* snap pixel */
static const unsigned int gappih = 10;   /* horiz inner gap between windows */
static const unsigned int gappiv = 10;   /* vert inner gap between windows */
static const unsigned int gappoh = 10;   /* horiz outer gap between windows and screen edge */
static const unsigned int gappov = 10;   /* vert outer gap between windows and screen edge */
static const int smartgaps       = 0;    /* 1 means no outer gap when there is only one window */
static const int showbar         = 1;    /* 0 means no bar */
static unsigned int ulinepad	   = 5;	/* horizontal padding between the underline and tag */
static unsigned int ulinestroke  = 2;	/* thickness / height of the underline */
static unsigned int ulinevoffset = 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 	   = 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const float mfact     	   = 0.51; /* factor of master area size */
static const int nmaster     	   = 1;    /* number of clients in master area */
static const int resizehints 	   = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen  = 1;    /* 1 will force focus on the fullscreen window */
static const int refreshrate 	   = 240;  /* refresh rate (per second) for client move/resize */
static const int swallowfloating = 0;    /* 1 means swallow floating windows by default */
static const unsigned int baralpha = 0xff;
static const unsigned int borderalpha = OPAQUE;
static const int decorhints  = 1;    /* 1 means respect decoration hints */
static const char logo[]		   = " ";

static int showlayout = 0;
static int hidevacant = 0;
static int topbar                = 1;    /* 0 means bottom bar */
static unsigned int borderpx     = 1;    /* border pixel of windows */
static unsigned int padding      = 3;    /* border pixel of windows */
static const char *fonts[]	   = { "MonaspiceNe NFP:size=10:antialias=true:autohint=true", "Noto Sans CJK JP:size=10"};
static char normbg[]             = "#222222";
static char normborder[]         = "#444444";
static char normfg[]             = "#bbbbbb";
static char selfg[]              = "#eeeeee";
static char selborder[]          = "#770000";
static char selbg[]              = "#005577";
static char tagnormbg[]          = "#222222";
static char tagnormfg[]          = "#bbbbbb";
static char tagoccfg[]           = "#eeeeee";
static char tagoccbg[]           = "#222222";
static char tagselfg[]           = "#eeeeee";
static char tagselbg[]           = "#005577";
static char statusbg[]           = "#222222";
static char statusfg[]           = "#bbbbbb";
static char *colors[][3] 	   = {
	/*	                fg      	  bg    	   border     */
	[SchemeNorm] 	  = { normfg, 	  normbg,    normborder },
	[SchemeSel]  	  = { selfg, 	  selbg, 	   selborder  },
	[SchemeStatus]   = { statusfg,  statusbg,  normborder },
	[SchemeTagsNorm] = { tagnormfg, tagnormbg, normborder },
	[SchemeTagsSel]  = { tagselfg,  tagselbg,  selborder  },
	[SchemeTagsOcc]  = { tagoccfg,  tagoccbg,  normborder  },
};


static const unsigned int alphas[][3]      = {
     /*               fg      bg        border*/
     [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeStatus]  = { OPAQUE, baralpha, borderalpha },
     [SchemeTagsNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsOcc]  = { OPAQUE, baralpha, borderalpha },
};

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "normbg",        STRING,  &normbg },
		{ "normborder",    STRING,  &normborder },
		{ "normfg",        STRING,  &normfg },
		{ "selbg",         STRING,  &selbg },
		{ "selborder",     STRING,  &selborder },
		{ "selfg",         STRING,  &selfg },
		{ "tagselbg",      STRING,  &tagselbg },
		{ "tagselfg",      STRING,  &tagselfg },
		{ "tagnormbg",     STRING,  &tagnormbg },
		{ "tagnormfg",     STRING,  &tagnormfg },
		{ "tagoccbg",     STRING,  &tagoccbg },
		{ "tagoccfg",     STRING,  &tagoccfg },
		{ "statusfg",      STRING,  &statusfg },
		{ "statusbg",      STRING,  &statusbg },
		{ "borderpx",      INTEGER, &borderpx },
		{ "padding",       INTEGER, &padding },
		{ "topbar",        INTEGER, &topbar },
		{ "hidevacant",    INTEGER, &hidevacant },
		{ "tagset",   	    INTEGER, &tagset },
		{ "ulinestroke",   INTEGER, &ulinestroke },
		{ "ulinepad",      INTEGER, &ulinepad },
};

#define SESSION_FILE "/tmp/dwm-session"

#define TERMINAL "st"
#define TERMCLASS "St"
#define BROWSER "firefox"

static const Layout layouts[] = {
	/* symbol     arrange function */
	//{ "󱒎",	  tile },
	{ "󱇙",      tile },    /* first entry is default */
	{ "󱂬",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",    NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "Firefox", NULL,     NULL,           0, 	     0,          0,          -1,        -1 },
	{ "St",      NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,      NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* Aliases for long commands to avoid line breaks on the keys array */
#define VOLUP "wpctl set-volume @DEFAULT_AUDIO_SINK@ 2%+; kill -44 $(pidof dwmblocks)"
#define VOLDOWN "wpctl set-volume @DEFAULT_AUDIO_SINK@ 2%-; kill -44 $(pidof dwmblocks)"
#define MUTE "wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)"
#define KBUP "setxkbmap -layout br -variant abnt2 -model pc105"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	/* modifier         key        function        argument */
	/* Window Manager Keys */
	{ MODKEY,           XK_a,      togglegaps,     {0} },
	{ MODKEY|ShiftMask, XK_a,      defaultgaps,    {0} },
	{ MODKEY,           XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask, XK_BackSpace, quit,        {1} },
	{ MODKEY|ShiftMask, XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,           XK_f,      togglefullscr,  {0} },
	{ MODKEY,           XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,           XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|Mod1Mask,  XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,           XK_o,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask, XK_o,      incnmaster,     {.i = -1 } },
	{ MODKEY,			XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask, XK_q, 	 spawn,       	  {.v = (const char*[]){ "sysact", NULL } }},
	{ MODKEY,           XK_space,  zoom,           {0} },
	{ MODKEY|ShiftMask, XK_space,  togglefloating, {0} },
	{ MODKEY,           XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,           XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask, XK_Tab,    spawn,          SHCMD(KBUP) },
	{ MODKEY,           XK_x,      incrgaps,       {.i = -1 } },
	{ MODKEY, 	     XK_z,      incrgaps,       {.i = +1 } },
	/* Aplication Launcher Keys */
	{ MODKEY, 	     XK_BackSpace, spawn,       {.v = (const char*[]){ "sysact", NULL } }},
	{ MODKEY,           XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,			XK_m,      spawn,          {.v = (const char*[]){ TERMINAL, "-e", "ncmpcpp", NULL } } },
	{ MODKEY,			XK_r,      spawn,          {.v = (const char*[]){ TERMINAL, "-e", "lfub", NULL } } },
	{ MODKEY|ShiftMask, XK_r,      spawn,          {.v = (const char*[]){ TERMINAL, "-e", "htop", NULL } } },
	{ MODKEY,           XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,			XK_v, 	 spawn,       	  {.v = (const char*[]){ "dmenurecord", NULL } }},
	{ MODKEY,		     XK_w,      spawn,          {.v = (const char*[]){ BROWSER, NULL } } },
	/* Media and Volume Keys */
	{ MODKEY,		     XK_bracketleft,  spawn,    {.v = (const char*[]){ "mpc", "seek", "-10", NULL } } },
	{ MODKEY|ShiftMask, XK_bracketleft,  spawn,    {.v = (const char*[]){ "mpc", "seek", "-60", NULL } } },
	{ MODKEY,		     XK_bracketright, spawn,    {.v = (const char*[]){ "mpc", "seek", "+10", NULL } } },
	{ MODKEY|ShiftMask, XK_bracketright, spawn,    {.v = (const char*[]){ "mpc", "seek", "+60", NULL } } },
	{ MODKEY,		     XK_comma,  spawn,          {.v = (const char*[]){ "mpc", "prev", NULL } } },
	{ MODKEY|ShiftMask, XK_comma,  spawn,          {.v = (const char*[]){ "mpc", "seek", "0%", NULL } } },
	{ MODKEY|ShiftMask, XK_m,      spawn,          SHCMD(MUTE) },
	{ MODKEY,		     XK_equal,  spawn,          SHCMD(VOLUP) },
	{ MODKEY,		  	XK_minus,  spawn,          SHCMD(VOLDOWN) },
	{ MODKEY|ShiftMask,	XK_equal,  spawn,          {.v = (const char*[]){ "sudo", "xbacklight", "-inc", "15", NULL } } },
	{ MODKEY|ShiftMask,	XK_minus,  spawn,          {.v = (const char*[]){ "sudo", "xbacklight", "-dec", "15", NULL } } },
	{ MODKEY,			XK_p,      spawn,          {.v = (const char*[]){ "mpc", "toggle", NULL } } },
	{ MODKEY|ShiftMask, XK_p,      spawn,          SHCMD("mpc pause; pauseallmpv") },
	{ MODKEY,		     XK_period, spawn,          {.v = (const char*[]){ "mpc", "next", NULL } } },
	{ MODKEY|ShiftMask, XK_period, spawn,          {.v = (const char*[]){ "mpc", "repeat", NULL } } },
	{ MODKEY|ShiftMask, XK_s,      spawn,          {.v = (const char*[]){ "mpc", "stop", NULL } } },
	/* Tag Keys */
	{ MODKEY,           XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask, XK_0,      tag,            {.ui = ~0 } },
	TAGKEYS(            XK_1,                      0)
	TAGKEYS(            XK_2,                      1)
	TAGKEYS(            XK_3,                      2)
	TAGKEYS(            XK_4,                      3)
	TAGKEYS(            XK_5,                      4)
	TAGKEYS(            XK_6,                      5)
	TAGKEYS(            XK_7,                      6)
	TAGKEYS(            XK_8,                      7)
	TAGKEYS(            XK_9,                      8)
	/* Stack Keys */
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click          event mask button    function        argument */
	{ ClkLtSymbol,    0,         Button1,  setlayout,      {0} },
	{ ClkLtSymbol,    0,         Button3,  setlayout,      {.v = &layouts[2]} },
#ifndef __OpenBSD__
	{ ClkWinTitle,    0,         Button2,  zoom,           {0} },
	{ ClkStatusText,  0,         Button1,  sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,  0,         Button2,  sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,  0,         Button3,  sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,  0,         Button4,  sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,  0,         Button5,  sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,  ShiftMask, Button1,  sigdwmblocks,   {.i = 6} },
#endif
	{ ClkClientWin,   MODKEY,    Button1,  movemouse,      {0} },
	{ ClkClientWin,   MODKEY,    Button2,  togglefloating, {0} },
	{ ClkClientWin,   MODKEY,    Button3,  resizemouse,    {0} },
	{ ClkLogoBar,     0,         Button1,  spawn,          {.v = (const char*[]){ "sysact", NULL } } },
	{ ClkLogoBar,     0,         Button2,  quit,           {1} },
	{ ClkLogoBar,     0,         Button3,  spawn,          {.v = dmenucmd } },
	{ ClkTagBar,      0,         Button1,  view,           {0} },
	{ ClkTagBar,      0,         Button3,  toggleview,     {0} },
	{ ClkTagBar,      MODKEY,    Button1,  tag,            {0} },
	{ ClkTagBar,      MODKEY,    Button3,  toggletag,      {0} },
};

