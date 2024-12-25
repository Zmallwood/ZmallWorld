new_draw_commands = []

var process_message = function (evt, ctx, draw_commands) {
  var msg = evt.data;
  var parts = msg.split(";");
  switch (parts[0]) {
    case "clear":
      var r = parts[1];
      var g = parts[2];
      var b = parts[3];
      new_draw_commands.push(
        "ctx.fillStyle = 'rgb(" + r + "," + g + "," + b + ")';",
      );
      new_draw_commands.push(
        "ctx.fillRect(0, 0, ctx.canvas.width, ctx.canvas.height);",
      );

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
      new_draw_commands.push(
        "ctx.drawImage(images['" +
          image_name +
          "'], " +
          xpx +
          "," +
          ypx +
          "," +
          wpx +
          "," +
          hpx +
          ");",
      );
      break;
    case "draw_text":
      var text = parts[1];
      var x = parts[2];
      var y = parts[3];
      var xpx = x * ctx.canvas.width;
      var ypx = y * ctx.canvas.height;
      if (parts.length >= 7) {
        var r = parts[4];
        var g = parts[5];
        var b = parts[6];
        new_draw_commands.push(
          "ctx.fillStyle = 'rgb(" + r + "," + g + "," + b + ")';",
        );
      } else {
        new_draw_commands.push("ctx.fillStyle = 'rgb(0,0,0)';");
      }
      new_draw_commands.push("ctx.fillText('"  + text + "'," + xpx + "," + ypx + ");");
      break;
    case "present":
      draw_commands.length = 0;
      for (entry of new_draw_commands) {
        draw_commands.push(entry);
      }
      new_draw_commands = [];
      break;
    case "redirect":
      var port = parts[1];
      connect(port);
      break;
  }
};
