var init = function () {
  const canvas = document.getElementById("myCanvas");
  const ctx = canvas.getContext("2d");
  ctx.canvas.width = window.innerWidth;
  ctx.canvas.height = window.innerHeight;
  ctx.fillStyle = "red";
  ctx.fillRect(0, 0, 150, 75);
  var image = new Image();
  ctx.fillStyle = "rgb(0,255,0)";
  ctx.fillRect(0, 0, canvas.width, canvas.height);
  image.onload = function () {
    ctx.drawImage(image, 0, 0);
  };
  image.src = "./resources/images/ground_grass.png";
  ctx.font = "48px serif";
  var ws = new WebSocket("ws://localhost:8080/");
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
      case "draw_text":
        var x = parts[1];
        var y = parts[2];
        var text = parts[3];
        ctx.fillStyle = "rgb(0,0,0)";
        ctx.fillText(text, x, y);
        break;
      case "render_finished":
        ws.send("second message");
        break;
    }
  };

  ws.onclose = function () {
    console.log("Connection closed...");
  };

  document.onkeydown = function (e) {
    e = e || window.event;
    alert("Keypress: " + e.keyCode);
  };
};
