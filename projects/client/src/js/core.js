var init = function() {
    const canvas = document.getElementById("myCanvas");
    const ctx = canvas.getContext("2d");
    ctx.fillStyle = "red";
    ctx.fillRect(0, 0, 150, 75);
    var image = new Image();
    ctx.fillStyle=  "rgb(0,255,0)";
    ctx.fillRect(0, 0, canvas.width, canvas.height);
    image.onload = function() {
      ctx.drawImage(image, 0, 0);
    }
    image.src = "./resources/images/ground_grass.png"
     var ws = new WebSocket('ws://localhost:8080/');
      ws.onopen = function () {
          console.log('socket connection opened properly');
          ws.send("Hello World"); // send a message
          console.log('message sent');
      };

      ws.onmessage = function (evt) {
          console.log("Message received = " + evt.data);
          var msg = evt.data;
          var parts = msg.split(",");
          switch (parts[0]) {
            case "clear":
            var r = parts[1];
            var g = parts[2];
            var b = parts[3];
            ctx.fillStyle = "rgb(" + r + "," + g + "," + b + ")";
            ctx.fillRect(0, 0, canvas.width, canvas.height);
          break;
          }
          ws.send("second message");
      };

      ws.onclose = function () {
          // websocket is closed.
          console.log("Connection closed...");
      };
}
