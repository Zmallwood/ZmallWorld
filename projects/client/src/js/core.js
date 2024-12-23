var connect = function(port) {

  const canvas = document.getElementById("myCanvas");
  const ctx = canvas.getContext("2d");
  ctx.canvas.width = window.innerWidth;
  ctx.canvas.height = window.innerHeight;
  ctx.fillStyle = "red";
  ctx.fillRect(0, 0, 150, 75);
  ctx.fillStyle = "rgb(0,255,0)";
  ctx.fillRect(0, 0, canvas.width, canvas.height);

  var image_ground_grass = new Image();
  image_ground_grass.onload = function () {
    ctx.drawImage(image, 0, 0);
  };
  image_ground_grass.src = "./resources/images/ground_grass.png";

  var image_default_scene_background = new Image();
  image_default_scene_background.src = "./resources/images/dark_world/scene_graphics/default_scene_background.png";

  images = {
    "ground_grass": image_ground_grass,
    "default_scene_background": image_default_scene_background
  };

  ctx.font = "48px serif";
  var ws = new WebSocket("ws://localhost:" + port);
  ws.onopen = function () {
    console.log("socket connection opened properly");
    ws.send("Hello World"); // send a message
    console.log("message sent");
  };

  ws.onmessage = function (evt) {
    console.log("Message received = " + evt.data);
    var msg = evt.data;
    var parts = msg.split(";");
    switch (parts[0]) {
      case "clear":
        var r = parts[1];
        var g = parts[2];
        var b = parts[3];
        ctx.fillStyle = "rgb(" + r + "," + g + "," + b + ")";
        ctx.fillRect(0, 0, canvas.width, canvas.height);

        break;
      case "draw_image":
        var image_name = parts[1];
        var x = parts[2];
        var y = parts[3];
        var w = parts[4];
        var h = parts[5];
        var xpx = x*ctx.canvas.width;
        var ypx = y*ctx.canvas.height;
        var wpx = w*ctx.canvas.width;
        var hpx = h*ctx.canvas.height;
        ctx.drawImage(images[image_name], xpx, ypx, wpx, hpx);
      break;
      case "draw_text":
        var x = parts[1];
        var y = parts[2];
        var text = parts[3];
        ctx.fillStyle = "rgb(0,0,0)";
        ctx.fillText(text, x, y);
        break;
      case "redirect":
        var port = parts[1]
        connect(port)
      break;
    }
  };

  ws.onclose = function () {
    console.log("Connection closed...");
  };

  document.onkeydown = function (e) {
    e = e || window.event;
    ws.send("key_down;" + e.keyCode);
  };
}


var init = function () {
  connect(8080);
};
