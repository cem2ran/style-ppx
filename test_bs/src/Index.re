open ReactNative;

module Style = {
  include Style;
  let make = Style.style;
};

module ViewStyle = {
  let make = Style.viewStyle;
};

module TextStyle = {
  let make = Style.textStyle;
};

module ImageStyle = {
  let make = Style.imageStyle;
};

open Style;

Style({"backgroundColor": "papayawhip", "width": 42.->dp, "height": 42.->dp});

// Compiles to:

style(~backgroundColor="papayawhip", ~width=42.->dp, ~height=42.->dp, ());