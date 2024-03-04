/*
 * contrib/debug/debug.c
 */
#include "postgres.h"
#include "fmgr.h"
#include "c.h"

#include "utils/fmgrprotos.h"

PG_MODULE_MAGIC;


PG_FUNCTION_INFO_V1(debug_1);

/* the tamplate function for debuging */
Datum
debug_1(PG_FUNCTION_ARGS)
{
	TransactionId xid = 0; 
	elog(WARNING, "xid=%u", xid);
	PG_RETURN_UINT64(xid);
}

