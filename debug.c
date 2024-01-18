/*
 * contrib/debug/debug.c
 */
#include "postgres.h"
#include "fmgr.h"
#include "c.h"

#include "access/global_csn_log.h"
#include "access/slru.h"
#include "utils/fmgrprotos.h"

PG_MODULE_MAGIC;


PG_FUNCTION_INFO_V1(debug_1);

Datum
debug_1(PG_FUNCTION_ARGS)
{

	// SlruCtl slru = exportGlobalCSNData();

	TransactionId xid = (TransactionId) DirectFunctionCall1(pg_current_xact_id, -1); 
	elog(WARNING, "xid=%u", xid);
	GlobalCSN csn = GlobalCSNLogGetCSN(xid);

	// elog(WARNING, "is dirty = %d page=%d count=%d",(int) *(slru->shared->page_dirty), 
	// 	*(slru->shared->page_number), *(slru->shared->page_lru_count) );
	PG_RETURN_UINT64(csn);
}

