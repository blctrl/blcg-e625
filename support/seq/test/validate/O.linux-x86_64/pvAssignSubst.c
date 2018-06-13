/* C code for program pvAssignSubstTest, generated by snc from ../pvAssignSubst.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 3 "../pvAssignSubst.st"
#include "../testSupport.h"

/* Variable declarations */
# line 5 "../pvAssignSubst.st"
static	string x;


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
}

/* Program entry func */
static void seqg_entry(SS_ID seqg_env)
{
# line 9 "../pvAssignSubst.st"
	seq_test_init(1);
}

/****** Code for state "one" in state set "test" ******/

/* Entry function for state "one" in state set "test" */
static void seqg_entry_test_0_one(SS_ID seqg_env)
{
# line 15 "../pvAssignSubst.st"
	seq_pvAssignSubst(seqg_env, 0/*x*/, "{pre}Assign{post}.NAME");
}

/* Event function for state "one" in state set "test" */
static seqBool seqg_event_test_0_one(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 17 "../pvAssignSubst.st"
	if (seq_pvConnected(seqg_env, 0/*x*/))
	{
		seq_exit(seqg_env);
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 21 "../pvAssignSubst.st"
	if (seq_delay(seqg_env, 2))
	{
		seq_exit(seqg_env);
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "one" in state set "test" */
static void seqg_action_test_0_one(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 18 "../pvAssignSubst.st"
			seq_pvGetTmo(seqg_env, 0/*x*/, SYNC, DEFAULT_TIMEOUT);
# line 19 "../pvAssignSubst.st"
			testOk1(strcmp(x, "pvAssignSubst") == 0);
		}
		return;
	case 1:
		{
# line 22 "../pvAssignSubst.st"
			testFail("timeout");
		}
		return;
	}
}

/* Program exit func */
static void seqg_exit(SS_ID seqg_env)
{
# line 28 "../pvAssignSubst.st"
	seq_test_done();
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", (size_t)&x, "x", P_STRING, 1, 1, 0, 0, 0, 0},
};

/* Event masks for state set "test" */
static const seqMask seqg_mask_test_0_one[] = {
	0x00000002,
};

/* State table for state set "test" */
static seqState seqg_states_test[] = {
	{
	/* state name */        "one",
	/* action function */   seqg_action_test_0_one,
	/* event function */    seqg_event_test_0_one,
	/* entry function */    seqg_entry_test_0_one,
	/* exit function */     0,
	/* event mask array */  seqg_mask_test_0_one,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "test",
	/* states */            seqg_states_test,
	/* number of states */  1
	},
};

/* Program table (global) */
seqProgram pvAssignSubstTest = {
	/* magic number */      2002006,
	/* program name */      "pvAssignSubstTest",
	/* channels */          seqg_chans,
	/* num. channels */     1,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "pre=pv,post=Subst",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF),
	/* init func */         seqg_init,
	/* entry func */        seqg_entry,
	/* exit func */         seqg_exit,
	/* num. queues */       0
};

#define PROG_NAME pvAssignSubstTest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void pvAssignSubstTestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&pvAssignSubstTest);
}
epicsExportRegistrar(pvAssignSubstTestRegistrar);
