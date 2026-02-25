enum { TagsNorm, TagsOcc, TagsSel };
/* do not change TagDefault and TagLast or you may experience crashes */
enum { TagDefault, TagRoman, TagNumBall, TagOmarchy, TagSquares, TagLast };

/* selected tagset */
static int tagset = TagOmarchy;
static int tagamount = 6;	/* max 9, min 1 */

static char *tags[][3][9] = {
	[TagDefault] = {
		{"1", "2", "3", "4", "5", "6", "7", "8", "9"},
		{"1", "2", "3", "4", "5", "6", "7", "8", "9"},
		{"1", "2", "3", "4", "5", "6", "7", "8", "9"},
	},
	[TagRoman] = {
		{ "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
		{ "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
		{ "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
	},
	[TagNumBall] = {
		{"❶", "❷", "❸", "❹", "❺", "❻", "❼", "❽", "❾"},
		{"❶", "❷", "❸", "❹", "❺", "❻", "❼", "❽", "❾"},
		{"❶", "❷", "❸", "❹", "❺", "❻", "❼", "❽", "❾"},
	},
	[TagOmarchy] = {
		{"1", "2", "3", "4", "5", "6", "7", "8", "9"},
		{"1", "2", "3", "4", "5", "6", "7", "8", "9"},
		{"󱓻", "󱓻", "󱓻", "󱓻", "󱓻", "󱓻", "󱓻", "󱓻", "󱓻"},
	},
	[TagSquares] = {
		{"󱓼", "󱓼", "󱓼", "󱓼", "󱓼", "󱓼", "󱓼", "󱓼", "󱓼"},
		{"󱓻", "󱓻", "󱓻", "󱓻", "󱓻", "󱓻", "󱓻", "󱓻", "󱓻"},
		{"󱓻", "󱓻", "󱓻", "󱓻", "󱓻", "󱓻", "󱓻", "󱓻", "󱓻"},
	},
};

