{
  description = "Blasteroids-like game in Allegro 5";

  inputs = {
    nixpkgs.url = "nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system: let
      pkgs = import nixpkgs {
        inherit system;
      };
    in {
    packages = {
      default = pkgs.python3Packages.callPackage ./package.nix { inherit self; };
    };
    devShells.default = pkgs.mkShell {
      packages = with pkgs; [
        allegro5
        cmake
        ninja
        pkg-config
      ];
    };
  });
}
