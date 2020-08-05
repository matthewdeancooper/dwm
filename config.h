  /* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 5;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Source code pro:size=10" };
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]     	= "#005577";
static const char my_border[]     	= "#6897BB";
static const char my_border2[]     	= "#1874CD";
static const char my_background[]     	= "#000000";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
 	/* [SchemeNorm] = { col_gray3, col_gray1, col_gray2 }, */
 	[SchemeNorm] = { col_gray3, col_gray1, my_background },
 	/* [SchemeSel] =  { col_gray4, col_cyan,  col_cyan}, */
 	[SchemeSel] =  { col_gray4, my_background,  my_border2},
};

/* tagging */
static const char *tags[] = { "q", "w", "e", "r"};
/* static const char *tags[] = { "q", "w", "e", "r", "t"}; */
/* static const char *tags[] = { "1", "2", "3", "4", "5"}; */

static const Rule rules[] = {
                             /* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Firefox",     NULL,       NULL,      0,            0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
                                 { "[d]",      deck },    /* first entry is default */
                                 { "[t]",      tile },    /* first entry is default */
                                 { "[m]",      monocle },
                                 { "[f]",      NULL },    /* no layout function means floating behaviour */
};

/* key definitions */
#define MODKEY Mod1Mask
#define MODKEY2 Mod4Mask
/* use windows key */
/* #define MODKEY Mod4Mask */
#define TAGKEYS(KEY,TAG)                                                \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL };
/* static const char *termcmd[]  = { "st", "-e", "tmux",  NULL }; */
static const char *termcmd[]  = { "st",  NULL };
/* static const char *edcmd[]  = { "emacsclient", "-c", NULL }; */
static const char *browcmd[]  = { "firefox", NULL  };
/* static const char *browcmd[]  = { "firefox", NULL  }; */
static const char *upvol[]  = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%", NULL };
static const char *downvol[]  = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%", NULL };
static const char *mutevol[]  = { "pactl", "set-sink-mute", "@DEFAULT_SINK@", "toggle", NULL };
static const char *upbright[]  = { "lux", "-a", "5%", NULL  };
static const char *downbright[]  = { "lux", "-s", "5%", NULL  };
/* static const char *xrand[]  = { "mydualscreen",  NULL  }; */
static const char *dnm[]  = { "networkmanager_dmenu", NULL  };
static const char *clip[]  = { "clipmenu", NULL  };
static const char *pkill[]  = { "dkillx", NULL  };
/* static const char *netreboot[]  = { "netreboot", NULL  }; */
static const char *pass[]  = { "passmenu", NULL  };
/* static const char *calmenu[]  = { "calmenu", NULL  }; */
/* static const char *slock[]  = { "slock", NULL  }; */
static const char *dwbuff[]  = { "dwbuff", NULL  };
static const char *skippy[]  = { "skippy-xd", "--activate-window-picker", NULL  };

static Key keys[] = {

	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	/* { MODKEY|ShiftMask,             XK_o, spawn,          {.v = edcmd } }, */
	{ MODKEY|ShiftMask,             XK_i, spawn,          {.v = browcmd } },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	/* { MODKEY,                       XK_c,      spawn,          {.v = calmenu } }, */
	{ MODKEY,                       XK_b,      spawn,          {.v = dwbuff } },
	{ MODKEY|ShiftMask,             XK_b,      spawn,          {.v = skippy } },
	{ MODKEY,                       XK_v, spawn,          {.v = clip } },
	/* { MODKEY,                       XK_BackSpace, spawn,             {.v = slock } }, */
	/* { MODKEY,                       XK_F8,      spawn,          {.v = dnm } }, */
	/* { MODKEY,                       XK_F9,     spawn,          {.v = pass } }, */
	/* { MODKEY,                       XK_Home,   togglebar,      {0} }, */
	/* { MODKEY,	                 	XK_Delete, spawn,          {.v = pkill } }, */
	/* { MODKEY|ShiftMask,             XK_Delete, quit,           {0} }, */
	{ MODKEY,                       XK_0,     spawn,          {.v = mutevol } },
	{ MODKEY,                       XK_minus,     spawn,          {.v = downvol } },
	{ MODKEY,			             XK_plus,     spawn,          {.v = upvol } },
	{ MODKEY,                       XK_F5,     spawn,          {.v = downbright } },
	{ MODKEY,          			   XK_F6,     spawn,          {.v = upbright } },
	/* { MODKEY,                       XK_F11,    spawn,          {.v = xrand } }, */
	/* { MODKEY,                       XK_F8,     spawn,          {.v = netreboot} }, */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_l,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_h,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
	/*{ MODKEY,                     XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },*/
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_d,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[3]} },
	/* { MODKEY,                       XK_space,  setlayout,      {0} }, */
	{ MODKEY|ShiftMask,             XK_f,      togglefloating, {0} },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	/* TAGKEYS(                        XK_1,                      0) */
	/* TAGKEYS(                        XK_2,                      1) */
	/* TAGKEYS(                        XK_3,                      2) */
	/* TAGKEYS(                        XK_4,                      3) */
	/* TAGKEYS(                        XK_5,                      4) */
	/* { MODKEY,                       XK_0,      view,           {.ui = ~0 } }, */
	/* { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, */
	TAGKEYS(                        XK_q,                      0)
	TAGKEYS(                        XK_w,                      1)
	TAGKEYS(                        XK_e,                      2)
	TAGKEYS(                        XK_r,                      3)
	/* TAGKEYS(                        XK_t,                      4) */
	{ MODKEY,                       XK_a,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_a,      tag,            {.ui = ~0 } },
};


/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
                           { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
                           { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,         Button1,        resizemouse,    {0} },
};
