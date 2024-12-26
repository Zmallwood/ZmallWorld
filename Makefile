all: build_image_list build_server build_darkworld

build_darkworld:
	cd projects/server/apps/DarkWorld; \
	xmake -P .; \
	xmake project  -k compile_commands -P .;

build_image_list:
	cd projects/client; \
	make;

build_server:
	cd projects/server; \
	xmake; \
	xmake project -k compile_commands;

clean:
	cd projects/server; \
	xmake require --uninstall boost; \
	rm -rf .xmake; \
	rm build; \
	xmake f --ccache=n;

run_dev:
	cd ./projects/server;\
	screen -S "ZmallWorldServer" -d -m xmake run ZmallWorldServer 0.0.0.0 8080 1;
	xdg-open ./projects/client/src/index.html; \
	cd ./projects/server/apps/DarkWorld;\
	screen -S "DarkWorld" -d -m xmake run DarkWorld -P .;\
	screen -RR; \
	screen -XS ZmallWorldServer quit;

build_prod:
	cp ./projects/server/build/linux/x86_64/release/ZmallWorldServer ./prod_build/ZmallWorld

run_prod:
	cd prod_build; \
	docker compose up --build;
