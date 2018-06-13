/* C code for program entryVarTest, generated by snc from ../entryVar.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"

/* Variable declarations */
# line 13 "../entryVar.st"
static	float v;


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
}

/****** Code for state "low" in state set "ss1" ******/

/* Entry function for state "low" in state set "ss1" */
static void seqg_entry_ss1_0_low(SS_ID seqg_env)
{
# line 23 "../entryVar.st"
	v = 20.0;
# line 24 "../entryVar.st"
	seq_pvPutTmo(seqg_env, 0/*v*/, DEFAULT, DEFAULT_TIMEOUT);
# line 25 "../entryVar.st"
	printf("Init v = %g on first entry to low\n", v);
}

/* Exit function for state "low" in state set "ss1" */
static void seqg_exit_ss1_0_low(SS_ID seqg_env)
{
# line 46 "../entryVar.st"
	printf("low, print this on exit of low\n");
}

/* Event function for state "low" in state set "ss1" */
static seqBool seqg_event_ss1_0_low(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 27 "../entryVar.st"
	if (v < 11.0)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 32 "../entryVar.st"
	if (v > 80)
	{
		*seqg_pnst = 0;
		*seqg_ptrn = 1;
		return TRUE;
	}
# line 37 "../entryVar.st"
	if (seq_delay(seqg_env, 2.0))
	{
		*seqg_pnst = 0;
		*seqg_ptrn = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "low" in state set "ss1" */
static void seqg_action_ss1_0_low(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 30 "../entryVar.st"
			printf("low, v = %g, now changing to high\n", v);
		}
		return;
	case 1:
		{
# line 34 "../entryVar.st"
			v = 20;
# line 35 "../entryVar.st"
			seq_pvPutTmo(seqg_env, 0/*v*/, DEFAULT, DEFAULT_TIMEOUT);
		}
		return;
	case 2:
		{
# line 39 "../entryVar.st"
			printf("low, delay timeout, incr v and now reenter low\n");
# line 40 "../entryVar.st"
			v = v + 1.0;
# line 41 "../entryVar.st"
			seq_pvPutTmo(seqg_env, 0/*v*/, DEFAULT, DEFAULT_TIMEOUT);
# line 42 "../entryVar.st"
			printf("v = %g\n", v);
		}
		return;
	}
}

/****** Code for state "high" in state set "ss1" ******/

/* Entry function for state "high" in state set "ss1" */
static void seqg_entry_ss1_0_high(SS_ID seqg_env)
{
# line 53 "../entryVar.st"
	printf("\nEntered high\n");
}

/* Event function for state "high" in state set "ss1" */
static seqBool seqg_event_ss1_0_high(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 54 "../entryVar.st"
	if (v >= 20.0)
	{
		*seqg_pnst = 0;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 58 "../entryVar.st"
	if (seq_delay(seqg_env, 3.0))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "high" in state set "ss1" */
static void seqg_action_ss1_0_high(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 56 "../entryVar.st"
			printf("high, v = %g changing to low\n", v);
		}
		return;
	case 1:
		{
# line 60 "../entryVar.st"
			v = 20;
# line 61 "../entryVar.st"
			seq_pvPutTmo(seqg_env, 0/*v*/, DEFAULT, DEFAULT_TIMEOUT);
# line 62 "../entryVar.st"
			printf("high, delay timeout, resetting v = %g\n", v);
		}
		return;
	}
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"CD01:FD:PERIOD", (size_t)&v, "v", P_FLOAT, 1, 1, 0, 1, 0, 0},
};

/* Event masks for state set "ss1" */
static const seqMask seqg_mask_ss1_0_low[] = {
	0x00000002,
};
static const seqMask seqg_mask_ss1_0_high[] = {
	0x00000002,
};

/* State table for state set "ss1" */
static seqState seqg_states_ss1[] = {
	{
	/* state name */        "low",
	/* action function */   seqg_action_ss1_0_low,
	/* event function */    seqg_event_ss1_0_low,
	/* entry function */    seqg_entry_ss1_0_low,
	/* exit function */     seqg_exit_ss1_0_low,
	/* event mask array */  seqg_mask_ss1_0_low,
	/* state options */     (0)
	},
	{
	/* state name */        "high",
	/* action function */   seqg_action_ss1_0_high,
	/* event function */    seqg_event_ss1_0_high,
	/* entry function */    seqg_entry_ss1_0_high,
	/* exit function */     0,
	/* event mask array */  seqg_mask_ss1_0_high,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "ss1",
	/* states */            seqg_states_ss1,
	/* number of states */  2
	},
};

/* Program table (global) */
seqProgram entryVarTest = {
	/* magic number */      2002006,
	/* program name */      "entryVarTest",
	/* channels */          seqg_chans,
	/* num. channels */     1,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF),
	/* init func */         seqg_init,
	/* entry func */        0,
	/* exit func */         0,
	/* num. queues */       0
};

#define PROG_NAME entryVarTest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void entryVarTestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&entryVarTest);
}
epicsExportRegistrar(entryVarTestRegistrar);
