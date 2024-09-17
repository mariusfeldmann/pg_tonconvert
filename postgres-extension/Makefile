EXTENSION = tonconvert
MODULE_big = tonconvert
DATA = tonconvert--0.0.1.sql
OBJS = tonconvert.o

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)

LDFLAGS += -L. tonconvert.a
