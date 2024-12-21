all: build_server

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
	screen -d -m xmake run ZmallWorldServer 0.0.0.0 8080 1;
	xdg-open ./client/src/index.html;
	screen -r
