all: run

run:
	make -f MakeRun.mk all

clean: 
	make -f MakeRun.mk clean
	@ rm -rf ./build/objs/ ./build/lib/