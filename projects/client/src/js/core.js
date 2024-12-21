var init = function() {
    const canvas = document.getElementById("myCanvas");
    const ctx = canvas.getContext("2d");
    ctx.fillStyle = "red";
    ctx.fillRect(0, 0, 150, 75);
    var image = new Image();
    image.onload = function() {
      ctx.drawImage(image, 0, 0);
    }
    image.src = "./resources/images/ground_grass.png"
     var ws = new WebSocket('ws://localhost:8080/', 'echo-protocol');
      ws.onopen = function () {
          console.log('socket connection opened properly');
          ws.send("Hello World"); // send a message
          console.log('message sent');
      };

      ws.onmessage = function (evt) {
          console.log("Message received = " + evt.data);
      };

      ws.onclose = function () {
          // websocket is closed.
          console.log("Connection closed...");
      };
}
