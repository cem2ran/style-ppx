open Migrate_parsetree;
open Ppx_style;

let _ = Driver.run_as_ppx_rewriter();