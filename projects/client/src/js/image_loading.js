var images = {};

load_script("image_list.js");

for (const image_name of image_names) {
  var image = new Image();
  image.src = "./resources/images/" + image_name + ".png";
  images[image_name] = image;
}