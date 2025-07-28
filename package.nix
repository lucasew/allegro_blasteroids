{ stdenv
, lib
, allegro5
, cmake
, ninja
, pkg-config
, self
}:

stdenv.mkDerivation {
  pname = "allegro_blasteroids";
  version = "${builtins.readFile ./version.txt}-${self.shortRev or self.dirtyShortRev or "rev"}";

  src = ./.;

  buildInputs = [ allegro5 ];

  nativeBuildInputs = [ cmake ninja pkg-config ];

  meta = {
    mainProgram = "blasteroids";
    maintainers = [ lib.maintainers.lucasew ];
  };
}
