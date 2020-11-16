open Migrate_parsetree;
open Style_ppx;

let _ = Driver.run_as_ppx_rewriter();