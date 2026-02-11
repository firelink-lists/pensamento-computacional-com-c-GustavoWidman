{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    flake-parts.url = "github:hercules-ci/flake-parts";
    systems.url = "github:nix-systems/default";
    devshell.url = "github:numtide/devshell";
  };

  outputs =
    inputs@{
      flake-parts,
      systems,
      devshell,
      ...
    }:
    flake-parts.lib.mkFlake { inherit inputs; } {
      systems = import systems;
      imports = [
        devshell.flakeModule
        # (import ./nix/package.nix inputs)
      ];
      perSystem =
        { pkgs, ... }:
        {
          devshells.default = {
            imports = [
              "${inputs.devshell}/extra/language/c.nix"
            ];

            language.c = {
              compiler = pkgs.clang;
              includes = [ ];
              libraries = [ ];
            };

            devshell = {
              packages = with pkgs; [
                clang-tools # provides clangd
                cmake
                gnumake
              ];

              motd = "";
            };
          };
        };
    };
}
