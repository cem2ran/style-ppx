# style-ppx

![](https://github.com/cem2ran/style-ppx/workflows/ppx_style%20pipeline/badge.svg)

A project that includes the minimum configuration for a [ppx](https://blog.hackages.io/reasonml-ppx-8ecd663d5640) called `ppx_style`, a project that uses Reason and [Esy](https://github.com/esy-ocaml/esy).

`ppx_style` implements a ppx that applies the record or object to the `make` function defined in the Style module.

So, the code:

```reason

module Style = {
    let make = (~backgroundColor, ~width, ~height, ()) = ...;
};

Style({backgroundColor: "papayawhip", width: 42.->dp, height: 42.->dp});
// or
Style({"backgroundColor": "papayawhip", "width": 42.->dp, "height": 42.->dp});
```

Is transformed into:

```reason
make(~backgroundColor="papayawhip", ~width=42.->dp, ~height=42.->dp, ());
```

## Files and folders

The example contains a couple of different targets that will be handled by dune (an OCaml build system)
to use the ppx in different projects:

- The library: located under `lib` folder. It is used directly by native projects, and indirectly by BuckleScript projects
- The standalone binary: BuckleScript does not provide a way to compose multiple ppxs together, so each ppx gets called individually, getting a serialized version of the AST, using the `-ppx` compiler flag behind the scenes. This can be configured in BuckleScript projects by using the `ppx-flags` key in `bsconfig.json` (see "Examples" section below).

For this reason, `ppx_style` exposes an executable that can be consumed by BuckleScript projects.

## Examples

The repo contains a couple of demo examples that show one way to consume the ppx from both BuckleScript and native environments.

Check the readmes on each example folder:

- [BuckleScript](test_bs/README.md)
- [Native](test_native/README.md)
