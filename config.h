
/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 4;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrains Mono:size=11", "JoyPixels:pixelsize=11:antialias=true:autohint=true"};
static const char dmenufont[]       = "JetBrains Mono:size=11";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#005577";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#eeeeee";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selbgcolor,  selfgcolor,  selfgcolor  },
};

static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "7", "9", "10", "11", "12", "13", "14", "15", "16", "17", "17 |" };
# i dont like no 8 lol

static const Rule rules[] = {
    /* class                instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
        { "firefox",			NULL,     NULL,           1 << 1,    0,          0,          -1,        -1 },
        { NULL,				NULL,     NULL,           1 << 2,    0,          0,          -1,        -1 },
        { "St",				NULL,     NULL,           0,         0,          1,           0,        -1 },
        { NULL,				NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, 
};

/* layout(s) */
static const float mfact     = 0.55;
static const int nmaster     = 1;
static const int resizehints = 1;

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },
	{ "><>",      NULL },
	{ "[M]",      monocle },
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0";
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont};
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_g,      togglebar,      {0} },
	{ MODKEY,                       XK_f,	   zoom,           {0} },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_s,      incnmaster,     {.i = +1 } },
	{ MODKEY,		        XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_w,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_e,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_r,  	   togglefloating, {0} },
	{ MODKEY,                       XK_t,  	   setlayout,      {0} },
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,			XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,			XK_minus,  setgaps,	   {.i = -1 } },
	{ MODKEY,			XK_equal,  setgaps,	   {.i = +1 } },
	{ MODKEY|ShiftMask,		XK_equal,  setgaps,	   {.i =  0 } },
	{ MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,		XK_q,      quit,           {0} },
	{ ControlMask,			XK_0,	   view,	   {.ui = 10} },
	{ ControlMask,			XK_1,	   view,	   {.ui = 11} },
	{ ControlMask,			XK_2,	   view,	   {.ui = 12} },
	{ ControlMask,			XK_3,	   view,	   {.ui = 13} },
	{ ControlMask,			XK_4,	   view,	   {.ui = 14} },
	{ ControlMask,			XK_5,	   view,	   {.ui = 15} },
	{ ControlMask,			XK_6,	   view,	   {.ui = 16} },
	{ ControlMask,			XK_7,	   view,	   {.ui = 17} },
	{ ControlMask,			XK_8,	   view,	   {.ui = 18} },
};

static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

