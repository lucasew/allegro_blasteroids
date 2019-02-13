# allegro_blasteroids

Um jogo simples onde o objetivo é destruir o máximo de asteróides possível. [AUR](https://aur.archlinux.org/packages/allegro-blasteroids-git/)

![jogo](https://raw.githubusercontent.com/lucas59356/allegro_blasteroids/master/doc/jogo.png)

O jogo gera um asteroide novo a cada 10 segundos com vida, velocidade de rotação e velocidade aleatórios. O jogador destroi os asteroides danto tiro com a navezinha usando a tecla espaço, os tiros tem velocidade e dano aleatórios. Ao destruir um asteróide outro é gerado logo depois.

Você até pode atirar que nem o rambo para destruir os asteroides, mas saiba que os tiros perdem 1 de dano, a princípio, a cada 1 segundo, e sim, podem ter dano negativo e aumentar a vida dos asteroides.

As colisões são calculadas por distância, então pode acontecer de no desenho a bala passar pelo asteroide e não dar dano.

Ao morrer o jogo fecha retornando o tempo de jogo e quantos pontos foram feitos.

![gameover](https://raw.githubusercontent.com/lucas59356/allegro_blasteroids/master/doc/gameover.png)

O build do jogo é feito via cmake, por preguiça minha (ou automação), fiz um script chamado adm que basicamente roda o cmake e o ninja só que dentro de uma pasta chamada build, pra evitar de ter aquele monte de arquivo do cmake na raiz do projeto bagunçando tudo e reduzindo o trabalho de criar gitignore. Além disso não preciso ficar digitando os comandos na mão toda vez \o/.

Sobre dependências, de biblioteca só é necessário o allegro5. O jogo funciona onde o allegro funciona, pelo menos foi assim no Windows 7, 10, Xubuntu 18.04 e Arch. O build funciona 100% seja usando makefiles ou um script ninja gerado pelo cmake (eu uso ninja por que o build é mais rápido, tipo o dobro).

A ideia do jogo começou com a última proposta de projeto do livro Use a Cabeça C. Como não sou bom com design, peguei os desenhos do asteroide e da nave do próprio livro e depois fui incrementando.
