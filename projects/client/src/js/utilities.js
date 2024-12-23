var load_script = function (script_name) {
  var newScript = document.createElement("script");
  newScript.type = "text/javascript";
  newScript.src = "js/" + script_name;
  document.getElementsByTagName("head")[0].prepend(newScript);
};
