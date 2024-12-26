load_script("process_message.js");
load_script("image_loading.js");

var connect_info = get_connect_info();

var connect = function (port) {
  var current_buffer = 1;
  const canvas = document.getElementById("canvas_buffer_1");
  const ctx = canvas.getContext("2d");
  ctx.canvas.width = window.innerWidth;
  ctx.canvas.height = window.innerHeight;

  ctx.font = "38px serif";

  var draw_commands = [];

  var ws = new WebSocket("ws://" + connect_info["HOST"] + ":" + port);
  ws.onopen = function () {
    console.log("socket connection opened properly");
    ws.send("canvas_size;" + ctx.canvas.width + ";" + ctx.canvas.height); // send a message
    draw_frame();
  };

  ws.onmessage = function (evt) {
    process_message(ws, evt, ctx, draw_commands);
  };

  ws.onclose = function () {
    console.log("Connection closed...");
  };

  document.onkeydown = function (e) {
    e = e || window.event;
    ws.send("key_press;" + e.keyCode);
  };

  document.onkeyup = function (e) {
    e = e || window.event;
    ws.send("key_release;" + e.keyCode);
  };

  var draw_frame = function () {
    requestAnimationFrame(draw_frame);
    ctx.save();
    for (cmd of draw_commands) {
      eval(cmd);
    }
    ctx.restore();
    ws.send("frame_finished");
  };
};

var init = function () {
  connect(connect_info["PORT"]);
};
