/*
 *
 * status tracing for microwin
 * 2006/06/27
 *
 */



#include "jpegtrace.h"


typedef struct _StatusTrace_t {
	int index;
	int values[];
} StatusTrace_t;


StatusTrace_t *g_jpeg_stattrace = 0;
int            g_jpeg_trace_maxidx = 0;


void JpegRegisterTraceBlock( void *pTrace, int sizeTrace )
{
	g_jpeg_stattrace = (StatusTrace_t*)pTrace;
	g_jpeg_trace_maxidx = sizeTrace-1;
}

