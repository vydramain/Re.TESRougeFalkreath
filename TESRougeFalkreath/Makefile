all: clean reload build exec

run: reload build exec

mkdir_build:
	[ -d ./cmake-build-debug ] | mkdir -p cmake-build-debug

build:
	cd cmake-build-debug;make

exec:
	./cmake-build-debug/TESFalkreath

clean:
	rm -rf cmake-build-debug

reload: mkdir_build
	cd cmake-build-debug;cmake  ..

#install-linter:
#    pip install cpplint

