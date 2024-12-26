var get_connect_info = function () {
  if (profile == "develop") {
    return connect_info_develop;
  } else if (profile == "prod") {
    return connect_info_prod;
  } else {
    return nil;
  }
};
