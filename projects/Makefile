all: build_image_list build_server build_darkworld

build_darkworld:
	cd server/apps/DarkWorld; \
	xmake -P .; \
	xmake project  -k compile_commands -P .;

build_image_list:
	cd client; \
	make;

build_server:
	cd server; \
	xmake; \
	xmake project -k compile_commands;

clean:
	cd server; \
	xmake require --uninstall boost; \
	rm -rf .xmake; \
	rm build; \
	xmake f --ccache=n;

run:
	cd ./server;\
	screen -S "ZmallWorldServer" -d -m xmake run ZmallWorldServer 0.0.0.0 8080 1;
	xdg-open ./client/src/index.html; \
	cd ./server/apps/DarkWorld;\
	screen -S "DarkWorld" -d -m xmake run DarkWorld -P .;\
	screen -RR; \
	screen -XS ZmallWorldServer quit;

run_zmallsim:
	cd ./server/apps/ZmallSim;\
	rye run zmallsim;
