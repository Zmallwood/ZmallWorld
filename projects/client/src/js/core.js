load_script("process_message.js");
load_script("image_loading.js");

var connect = function (port) {
  const canvas = document.getElementById("main_canvas");
  const ctx = canvas.getContext("2d");
  ctx.canvas.width = window.innerWidth;
  ctx.canvas.height = window.innerHeight;

  ctx.font = "48px serif";

  var ws = new WebSocket("ws://localhost:" + port);
  ws.onopen = function () {
    console.log("socket connection opened properly");
    ws.send("handshake"); // send a message
  };

  ws.onmessage = function (evt) {
    process_message(evt, ctx);
  };

  ws.onclose = function () {
    console.log("Connection closed...");
  };

  document.onkeydown = function (e) {
    e = e || window.event;
    ws.send("key_press;" + e.keyCode);
  };
};

var init = function () {
  connect(8080);
};
