{ stdenv
, lib
, allegro5
, cmake
, ninja
}:

stdenv.mkDerivation {
  pname = "allegro_blasteroids";
  version = "0.1";

  src = ./.;

  buildInputs = [ allegro5 ];

  nativeBuildInputs = [ cmake ninja ];

  meta = {
    mainProgram = "blasteroids";
    maintainers = [ lib.maintainers.lucasew ];
  };
}
