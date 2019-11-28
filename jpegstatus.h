/*
 *
 * status tracing for microwin
 * 2006/06/27
 *
 */


#ifndef __JPEGSTATUS_H
#define __JPEGSTATUS_H  1



#define  USE_STATUS_TRACING  1



typedef struct _StatusTrace_t {
	int index;
	int values[];
} StatusTrace_t;

extern StatusTrace_t *g_jpeg_stattrace;
extern int            g_jpeg_trace_maxidx;



#if USE_STATUS_TRACING

//#define STATUS_TRACE(n)   (do { if(g_jpeg_stattrace) {(g_jpeg_stattrace->index)++; \
//       g_jpeg_stattrace->values[(g_jpeg_stattrace->index)&g_jpeg_trace_maxidx]=(unsigned int)(n); } } while(0))



#define STATUS_TRACE(n)   ((g_jpeg_stattrace) ? \
    (  (g_jpeg_stattrace->index)++, \
       g_jpeg_stattrace->values[(g_jpeg_stattrace->index)&g_jpeg_trace_maxidx]=(unsigned int)(n)) : \
    (  (void)(0)  ))
    


#else  /* #if USE_STATUS_TRACING */


#define STATUS_TRACE(n)  ((void)(0))


#endif /* #if USE_STATUS_TRACING */


#endif /* #ifndef __JPEGSTATUS_H */

