#ifndef DEF_INSIDE
	#define DEF_INSIDE

	/*#include"mpi.h"*/	/*IMRCの伝統的な神様*/
	#include <assert.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdint.h>
	#include <string.h>
	#include <memory.h>
	#include <signal.h>
	#include <gmp.h>

	#define FLUSH
	#define NODP
	#include "debug.h"

	#ifndef X
		#error Define X in compile
	#endif

	#define Ceilings (X*X)
	#define OneLine (X*(Ceilings+1)/2)

	/*enum bool{
		False, True
	};*/
	#define False (0)
	#define True (!False)

	enum trident{
		Unknown=0, Filled=1, AutoFilled=2
	};

	struct coord{
		uint_fast8_t x;
		uint_fast8_t y;
	};

	struct ring{
		uint_fast8_t x, y;	/*code[x][y]*/
		uint_fast8_t toafillcont;
		/*TODO: not needed to alloc so many*/
		struct coord toafill[Ceilings];
		/*TODO: not needed to alloc so many(maybe)*/
		struct coord toafillroad[Ceilings][X-1];
	};

	extern struct ring chain[Ceilings];
	extern uint_fast8_t chaincont;
	extern void pfCode(int code[X][X]);
	extern void will_and_die(char*, int);
#endif