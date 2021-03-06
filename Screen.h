#ifndef Screen_h

#define	Screen_h

#include "Common.h"

#define 	ASSIGN_POS(x, y , cond) \
			if((cond) > 0) \
				(x) = (y);

// ------------ Display parameters -----------------------
// Overall display parameters
#define		ScreenX0 		0
#define		ScreenY0		0
#define		ScreenXsize		320
#define		ScreenYsize		240

#define		Rbits			0		// Red bits position
#define		Gbits			5		// Green bits position
#define		Bbits			11		// Blue bits position
#define		RGB(R, G, B)		(((R >> 3) << Rbits) | ((G >> 2) << Gbits) | ((B >> 3) << Bbits))
 
enum  COLOR{
	clBlack 		=	RGB(0, 0, 0),
	clWhite			= 	RGB(255, 255, 255),
	clRed			= 	RGB(255, 0, 0),
	clGreen			= 	RGB(0, 255, 0),
	clBlue			= 	RGB(0, 0, 255),
	clYellow		=	RGB(255, 255, 0),
	clGainsboro		=	RGB(220, 220, 220),
	clNavy			=	RGB(0, 0, 128),
	clAqua			=	RGB(0, 255, 255),
	clHotpink		=	RGB(255, 105, 180),
	clOrange		=	RGB(255, 165, 0),
	clDeepskyblue		=	RGB(0, 191, 255),
	clDimgray		=	RGB(105, 105, 105),
	cllightsalmon		=	RGB(255, 160, 122),
	cllightcoral		=	RGB(240, 128, 128),
	clpaleturquoise		=	RGB(175, 238, 238),
	clturquoise		=	RGB(64, 224, 208),
	clViolet		=	RGB(238, 130, 238),
	clGray1			=	RGB(90, 90, 90),
	clGray2			=	RGB(220, 220, 220),
	clGray3			=	RGB(240, 240, 240),
	clDarkgray		=	RGB(169, 169, 169),
	clSkyblue		= 	RGB(135, 206, 235),
	clChocolate		= 	RGB(210, 105, 30),
	clMediumseagreen	= 	RGB(60, 179, 113),
	clPeachpuff		=	RGB(255, 218, 185),
	clSeagreen		=	RGB(46, 139, 87)
} ;

typedef struct {
	U8 	*Array;
	U8	Xsize;
	U8	Ysize;
	U8	CharPitch;
	U8	LinePitch;
	U8	IndexOfs;
	} FONT;


//	Display Panel
// =======================================================
// Display parameters
#define	WWindowx0			10
#define	WWindowy0			15
#define	WWindowSizex			300
#define	WWindowSizey			200
#define	WWindowMidValue			0x800

#define	WD_WIDTH			301		// Wave display width
#define WD_HEIGHT			200		// Wave display height
#define WD_OFFSETX			10
#define WD_OFFSETY			20
#define WD_MIDY				(WD_OFFSETY + (WD_HEIGHT / 2))
#define BLK_PX				25		/* Pixels per block */

/* Grid */
#define GRID_WIDTH			1
#define GRID_CENTER_WIDTH		1	
#define GRID_CENTER_CL			clBlue
#define GRID_DIST			25
#define GRID_CL				clWhite

/* Info bar */

#define CHAR_WID			8

/* Timebase */
#define TIMEBASE_SIZE			5 * CHAR_WID
#define TIMEBASE_OFFSETX		142
#define TIMEBASE_OFFSETY		ScreenYsize - WD_OFFSETY + 4

/* Peak-to-peak voltage */
#define PPV_SIZE			9 * CHAR_WID
#define PPV_OFFSETX			WD_OFFSETX + 5
#define PPV_OFFSETY			2

/* Max voltage */
#define MAXV_OFFSETX			PPV_OFFSETX + PPV_SIZE + 20
#define MAXV_OFFSETY			2
#define MAXV_SIZE			9 * CHAR_WID

/* Frequency */
#define FREQ_SIZE			13 * CHAR_WID
#define FREQ_OFFSETX			MAXV_OFFSETX + MAXV_SIZE + 30
#define FREQ_OFFSETY			2

/* Waveform */
#define WF_CL				clYellow
#define BG_CL				clBlack
#define TEXT_CL				clWhite

/* Coursor */
#define CURSOR_LEFT_CL			clAqua
#define CURSOR_LEFTX			0
#define CURSOR_RIGHT_CL			clAqua
#define CURSOR_RIGHTX			WD_OFFSETX + WD_WIDTH

/* SINGLE mode */
#define SINGLES_OFFSETX			50
#define SINGLES_OFFSETY			ScreenYsize - WD_OFFSETY + 4
#define SINGLES_DEAC_CL			clWhite
#define SINGLES_ACT_CL			clGreen

#define SELECTED_CL			clHotpink

/* Time voltage cursor */	
#define TVC_CL				clYellow
#define TVC_LABEL_OFFSETX		200
#define	TVC_LABEL_OFFSETY		ScreenYsize - 45

extern	FONT ASC8X16;

void	clr_screen(void);
void	clr_blk(S16 x, S16 y, S16 sizex, S16 sizey);
void 	clr_square_blk(S16 x, S16 y, S16 size);
void	SetWindow(U16 x, U16 xsize, U16 y, U16 ysize);
void 	FillRect(S16 x, S16 y, S16 xsize, S16 ysize, U16 color);
void	PutcGenic(U16 x, U16 y, U8 ch, U16 fgcolor, U16 bgcolor, FONT *font);
void	PutsGenic(U16 x, U16 y, U8 *str, U16 fgcolor, U16 bgcolor, FONT *font);

void 	info_display(void);
void 	grid_display(void);
void 	timebase_display(U16 timebase);
void 	cursor_display(U16 posx, U16 posy, U8 cursor_type, U16 cursor_cl);
void 	voltage_display(U16 posx, U16 posy, U8 *label, U16 adc_val, U16 text_clr, U16 bg_clr);
void 	freq_display(double freq);

#endif

