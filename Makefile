# contrib/pg_random_string/Makefile
MODULES = pg_random_string
EXTENSION = pg_random_string
DATA = pg_random_string--0.0.1.sql
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
