#ifndef _BCFFILE_H_
#define _BCFFILE_H_

#include <Rdefines.h>
#include "vcf.h"

#ifdef MIGRATE_ME

/* io_bcf.c */
typedef struct {
    bcf_t *file;
    bcf_idx_t *index;
} _BCF_FILE;

#define BCFFILE(b) ((_BCF_FILE *) R_ExternalPtrAddr(b))

#endif  /* MIGRATE_ME */

SEXP bcffile_init();

#ifdef MIGRATE_ME

SEXP bcffile_open(SEXP filename, SEXP indexname, SEXP mode);
SEXP bcffile_close(SEXP ext);
SEXP bcffile_isopen(SEXP ext);
SEXP bcffile_isvcf(SEXP ext);

SEXP scan_bcf_header(SEXP ext);
SEXP scan_bcf(SEXP ext, SEXP space, SEXP typemap);

SEXP as_bcf(SEXP file, SEXP dictionary, SEXP destination);
SEXP index_bcf(SEXP file);

#endif  /* MIGRATE_ME */

#endif                          /* _BCFFILE_H_ */
