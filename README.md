## PostgreSQL extension to convert TON addresses

The motivation behind this is to become more familiar with building PostgreSQL extensions. The conversion can of course also be done in C code, the Golang library step is pure convenience :-)

Hopefully this can come in helpful for someone who wants to build another postgres extension! 


### Building the Golang library 
```
cd tonconvertlib/
go mod tidy
make build
```

### Building the PostgreSQL extension
```
cd postgres-extension/
cp ../tonconvertlib/tonconvert.a .
cp ../tonconvertlib/tonconvert.h .
make USE_PGXS=1
make install
```

### Installing the library
```
psql -h localhost -U kingkong (<-- has to be SUPERUSER)

kingkong=# create extension log;
CREATE EXTENSION

kingkong=# select addr_to_human_readable_bounceable('-1:3333333333333333333333333333333333333333333333333333333333333333');
        addr_to_human_readable_bounceable         
--------------------------------------------------
 Ef8zMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzM0vF
(1 row)
```

### PostgreSQL check
Make sure `pg_config` is part of your PATH var
```
brew --prefix postgresql@15
/opt/homebrew/opt/postgresql@15

which pg_config
/opt/homebrew/opt/postgresql@15/bin/pg_config
```

#### Optional diagnosis for the static library 
```
file tonconvert.a
tonconvert.a: current ar archive random library

nm tonconvert.a | grep "convert_to_human_readable_c" 
000000000009e990 T __cgoexp_2e6779091b52_convert_to_human_readable_c
000000000009e510 t _main.convert_to_human_readable_c
                 U __cgoexp_2e6779091b52_convert_to_human_readable_c
0000000000000000 T _convert_to_human_readable_c
```

### Links 
- https://www.percona.com/blog/writing-postgresql-extensions-is-fun-c-language/
