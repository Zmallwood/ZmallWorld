var process_message = function(evt, ctx) {
    var msg = evt.data;
    var parts = msg.split(";");
    switch (parts[0]) {
      case "clear":
        var r = parts[1];
        var g = parts[2];
        var b = parts[3];
        ctx.fillStyle = "rgb(" + r + "," + g + "," + b + ")";
        ctx.fillRect(0, 0, ctx.canvas.width, ctx.canvas.height);

        break;
      case "draw_image":
        var image_name = parts[1];
        var x = parts[2];
        var y = parts[3];
        var w = parts[4];
        var h = parts[5];
        var xpx = x * ctx.canvas.width;
        var ypx = y * ctx.canvas.height;
        var wpx = w * ctx.canvas.width;
        var hpx = h * ctx.canvas.height;
        ctx.drawImage(images[image_name], xpx, ypx, wpx, hpx);
        break;
      case "draw_text":
        var text = parts[1];
        var x = parts[2];
        var y = parts[3];
        if (parts.length >= 7) {
          var r = parts[4];
          var g = parts[5];
          var b = parts[6];
          ctx.fillStyle = "rgb(" + r + "," + g + "," + b + ")";
        } else {
          ctx.fillStyle = "rgb(0,0,0)";
        }
        ctx.fillText(text, x, y);
        break;
      case "redirect":
        var port = parts[1];
        connect(port);
        break;
    }
}
