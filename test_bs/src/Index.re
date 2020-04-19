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

// Record style
Style({backgroundColor: "papayawhip", width: 42.->dp, height: 42.->dp});
// Object style
Style({"backgroundColor": "papayawhip", "width": 42.->dp, "height": 42.->dp});
// dp is also now the default for float values for attributes of "size" type
Style({
  backgroundColor: "papayawhip",
  width: 42., // <-- look ma no dp!
  height: 42.->dp,
  flex: 1. // <-- ppx does not touch this because it isn't a "size" attribute
});

// Compiles to:

style(~backgroundColor="papayawhip", ~width=42.->dp, ~height=42.->dp, ());