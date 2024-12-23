all: build_image_list


build_image_list:
	image_list_file=src/js/image_list.js; \
	> $$image_list_file; \
	echo "var image_names = [" >> $$image_list_file; \
	images_dir=./src/resources/images/; \
	for entry in $$images_dir*; do \
		base_name=$$(basename $$entry); \
		pure_name=$$(echo $$base_name| rev | cut -c5- | rev); \
		echo "  \""$$pure_name"\"", >> $$image_list_file; \
	done; \
	echo "];" >> $$image_list_file;
