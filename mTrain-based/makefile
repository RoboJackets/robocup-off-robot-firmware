.PHONY : all projects

all: projects

projects:
	mkdir -p build && cd build && cmake .. && make -j$(nproc)

clean:
	rm -rf build
