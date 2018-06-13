/* C code for program pvAssignStressTest, generated by snc from ../pvAssignStress.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 3 "../pvAssignStress.st"
#include "../testSupport.h"

/* Variable declarations */
# line 5 "../pvAssignStress.st"
static	string names[3];
# line 10 "../pvAssignStress.st"
static	int x[3];
struct seqg_vars_test {
# line 19 "../pvAssignStress.st"
	int i;
# line 20 "../pvAssignStress.st"
	int shift;
} seqg_vars_test;


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
	{
# line 5 "../pvAssignStress.st"
	static string seqg_initvar_names[3] = {"pvAssignStress0", "pvAssignStress1", "pvAssignStress2"};
	memcpy(&names, &seqg_initvar_names, sizeof(seqg_initvar_names));
	}
	{
# line 20 "../pvAssignStress.st"
	static int seqg_initvar_shift = 0;
	memcpy(&seqg_vars_test.shift, &seqg_initvar_shift, sizeof(seqg_initvar_shift));
	}
}

/* Program entry func */
static void seqg_entry(SS_ID seqg_env)
{
# line 15 "../pvAssignStress.st"
	seq_test_init(27);
}

/****** Code for state "disconn" in state set "test" ******/

/* Entry function for state "disconn" in state set "test" */
static void seqg_entry_test_0_disconn(SS_ID seqg_env)
{
# line 24 "../pvAssignStress.st"
	for (seqg_vars_test.i = 0; seqg_vars_test.i < 3; seqg_vars_test.i++)
	{
# line 25 "../pvAssignStress.st"
		seq_pvAssign(seqg_env, 0/*x*/ + (CH_ID)(seqg_vars_test.i), names[(seqg_vars_test.i + seqg_vars_test.shift) % 3]);
	}
}

/* Event function for state "disconn" in state set "test" */
static seqBool seqg_event_test_0_disconn(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 28 "../pvAssignStress.st"
	if (seq_pvConnected(seqg_env, 0/*x*/ + (CH_ID)(0)) && seq_pvConnected(seqg_env, 0/*x*/ + (CH_ID)(1)) && seq_pvConnected(seqg_env, 0/*x*/ + (CH_ID)(2)))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 35 "../pvAssignStress.st"
	if (seq_delay(seqg_env, 2))
	{
		seq_exit(seqg_env);
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "disconn" in state set "test" */
static void seqg_action_test_0_disconn(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 29 "../pvAssignStress.st"
			for (seqg_vars_test.i = 0; seqg_vars_test.i < 3; seqg_vars_test.i++)
			{
# line 30 "../pvAssignStress.st"
				seq_pvGetTmo(seqg_env, 0/*x*/ + (CH_ID)(seqg_vars_test.i), SYNC, DEFAULT_TIMEOUT);
# line 31 "../pvAssignStress.st"
				testOk(x[seqg_vars_test.i] == (seqg_vars_test.i + seqg_vars_test.shift) % 3, "%d==%d", x[seqg_vars_test.i], (seqg_vars_test.i + seqg_vars_test.shift) % 3);
			}
# line 33 "../pvAssignStress.st"
			seqg_vars_test.shift++;
		}
		return;
	case 1:
		{
# line 36 "../pvAssignStress.st"
			testFail("timeout");
		}
		return;
	}
}

/****** Code for state "conn" in state set "test" ******/

/* Entry function for state "conn" in state set "test" */
static void seqg_entry_test_0_conn(SS_ID seqg_env)
{
# line 41 "../pvAssignStress.st"
	for (seqg_vars_test.i = 0; seqg_vars_test.i < 3; seqg_vars_test.i++)
	{
# line 42 "../pvAssignStress.st"
		seq_pvAssign(seqg_env, 0/*x*/ + (CH_ID)(seqg_vars_test.i), "");
	}
}

/* Event function for state "conn" in state set "test" */
static seqBool seqg_event_test_0_conn(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 45 "../pvAssignStress.st"
	if (seqg_vars_test.shift == 9)
	{
		seq_exit(seqg_env);
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 47 "../pvAssignStress.st"
	if (!seq_pvConnected(seqg_env, 0/*x*/ + (CH_ID)(0)) && !seq_pvConnected(seqg_env, 0/*x*/ + (CH_ID)(1)) && !seq_pvConnected(seqg_env, 0/*x*/ + (CH_ID)(2)))
	{
		*seqg_pnst = 0;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "conn" in state set "test" */
static void seqg_action_test_0_conn(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/* Program exit func */
static void seqg_exit(SS_ID seqg_env)
{
# line 53 "../pvAssignStress.st"
	seq_test_done();
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", (size_t)&x[0], "x[0]", P_INT, 1, 1, 0, 1, 0, 0},
	{"", (size_t)&x[1], "x[1]", P_INT, 1, 2, 0, 1, 0, 0},
	{"", (size_t)&x[2], "x[2]", P_INT, 1, 3, 0, 1, 0, 0},
};

/* Event masks for state set "test" */
static const seqMask seqg_mask_test_0_disconn[] = {
	0x0000000e,
};
static const seqMask seqg_mask_test_0_conn[] = {
	0x0000000e,
};

/* State table for state set "test" */
static seqState seqg_states_test[] = {
	{
	/* state name */        "disconn",
	/* action function */   seqg_action_test_0_disconn,
	/* event function */    seqg_event_test_0_disconn,
	/* entry function */    seqg_entry_test_0_disconn,
	/* exit function */     0,
	/* event mask array */  seqg_mask_test_0_disconn,
	/* state options */     (0 | OPT_NORESETTIMERS)
	},
	{
	/* state name */        "conn",
	/* action function */   seqg_action_test_0_conn,
	/* event function */    seqg_event_test_0_conn,
	/* entry function */    seqg_entry_test_0_conn,
	/* exit function */     0,
	/* event mask array */  seqg_mask_test_0_conn,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "test",
	/* states */            seqg_states_test,
	/* number of states */  2
	},
};

/* Program table (global) */
seqProgram pvAssignStressTest = {
	/* magic number */      2002006,
	/* program name */      "pvAssignStressTest",
	/* channels */          seqg_chans,
	/* num. channels */     3,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF),
	/* init func */         seqg_init,
	/* entry func */        seqg_entry,
	/* exit func */         seqg_exit,
	/* num. queues */       0
};

#define PROG_NAME pvAssignStressTest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void pvAssignStressTestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&pvAssignStressTest);
}
epicsExportRegistrar(pvAssignStressTestRegistrar);
