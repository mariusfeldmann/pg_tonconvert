#include "postgres.h"
#include "fmgr.h"
#include "tonconvert.h"
#include "utils/builtins.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

/* Declare the function */
Datum addr_to_human_readable(PG_FUNCTION_ARGS);

/* Define the function */
PG_FUNCTION_INFO_V1(addr_to_human_readable);

Datum addr_to_human_readable(PG_FUNCTION_ARGS) {
    text *input = PG_GETARG_TEXT_PP(0);
    char *c_str = text_to_cstring(input);

    GoString go_str = {c_str, strlen(c_str)};
    char *go_return = convert_to_human_readable_c(go_str);
    pfree(c_str);

    if (go_return == NULL || strlen(go_return) == 0) {
        ereport(ERROR,
                (errcode(ERRCODE_EXTERNAL_ROUTINE_EXCEPTION),
                 errmsg("Conversion to human-readable address failed")));
        PG_RETURN_NULL();
    }

    text *pg_return = cstring_to_text(go_return);

    PG_RETURN_TEXT_P(pg_return);
}

/* Declare the function */
Datum addr_to_human_readable_bounceable(PG_FUNCTION_ARGS);

/* Define the function */
PG_FUNCTION_INFO_V1(addr_to_human_readable_bounceable);

Datum addr_to_human_readable_bounceable(PG_FUNCTION_ARGS) {
    text *input = PG_GETARG_TEXT_PP(0);
    char *c_str = text_to_cstring(input);

    GoString go_str = {c_str, strlen(c_str)};
    char *go_return = convert_to_human_readable_bounceable_c(go_str);
    pfree(c_str);

    if (go_return == NULL || strlen(go_return) == 0) {
        ereport(ERROR,
                (errcode(ERRCODE_EXTERNAL_ROUTINE_EXCEPTION),
                 errmsg("Conversion to human-readable bounceable address failed")));
        PG_RETURN_NULL();
    }

    text *pg_return = cstring_to_text(go_return);

    PG_RETURN_TEXT_P(pg_return);
}
