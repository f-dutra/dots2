static const char *fonts[]     = { "monospace:size=10" };
static const char col_1[]      = "#222222";
static const char col_2[]      = "#444444";
static const char col_3[]      = "#bbbbbb";
static const char col_4[]      = "#eeeeee";
static const char col_5[]      = "#005577";
static const char col_6[]      = "#770000";
static const char *colors[][3] = {
	/*	                fg      bg    border   */
	[SchemeNorm] 	  = { col_3, col_1, col_2 },
	[SchemeSel]  	  = { col_4, col_5, col_6 },
	[SchemeStatus]   = { col_3, col_1, col_2 },
	[SchemeTagsNorm] = { col_3, col_1, col_2 },
	[SchemeTagsSel]  = { col_4, col_5, col_6 },
};

