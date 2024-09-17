CREATE OR REPLACE FUNCTION addr_to_human_readable(input text)
RETURNS text AS '$libdir/tonconvert', 'addr_to_human_readable'
LANGUAGE C STRICT;

CREATE OR REPLACE FUNCTION addr_to_human_readable_bounceable(input text)
RETURNS text AS '$libdir/tonconvert', 'addr_to_human_readable_bounceable'
LANGUAGE C STRICT;
