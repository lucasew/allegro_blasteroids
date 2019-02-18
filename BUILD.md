# Como compilar o jogo?

1. Para ser possível compilar é primeiramente necessário um compilador de C, já foram testados o Clang, o GCC e o MinGW GCC 8.2.0.

2. Segundamente é necessário que a biblioteca Allegro 5.x esteja dentro do radar. No caso do arch apenas instale o pacote allegro, no caso dos Debian like como o Mint, ou o Ubuntu se faz necessário adicionar um [ppa](https://wiki.allegro.cc/index.php?title=Install_Allegro_from_Ubuntu_PPAs) por que a mesma não existe no repositório principal.

3. No caso do Windows, onde quase sempre tem uma manha a mais, eu recomendo baixar a biblioteca pré compilada e extrair a estrutura inteira dentro da pasta do MinGW. Foi assim que eu [empacotei a mesma para cross compilar usando o MinGW no Arch](https://aur.archlinux.org/packages/mingw-w64-allegro-static-bin/).

O link do pré-compilado se situa [aqui](https://github.com/liballeg/allegro5/releases). Para usá-lo provavelmente você necessitará baixar o MinGW por fora por que ele dá erro se tentar compilar com o GCC anterior ao 7.2.0. Baixe o 5.x. Na data da escrita desse arquivo é a 5.2.4. 4.x não funciona.

4. Antes de compilar é necessário gerar os scripts, e para isso é necessário o CMake. Se estiver usando Windows, use o Ninja, a menos que esteja usando cygwin. O make não roda direito fora do cygwin. E se compilar por lá o jogo vai depender do Cygwin.

5. Com a faca e o queijo na mão, abra um terminal ou prompt de comando, verifique se os comandos aparecem: cmake, gcc, ninja (opcional). Se faltar alguma coisa vai ser necessário adicionar a pasta onde estão esses programas na variável de ambiente PATH e após isso abrir outra janela do terminal/prompt de comando.

6. Com os programas acessíveis, baixe o código deste repositório, pode usar git clone, baixar a release de código ou baixar o zip do ultimo commit. O importante é achar um jeito de baixar.

7. No terminal/prompt de comando use o comando cd para chegar até a pasta onde você baixou o repositório.

8. Quando ckegar use o comando md ou mkdir para criar uma pasta, eu sempre nomeio como build mas pode ser qualquer nome, após isso de cd nela.

9. Alí dentro dessa pasta chamaremos o cmake para gerar os scripts.

```bash
cmake ..
```

Se quiser gerar scripts para o ninja simplesmente adicione ``` -G Ninja``` ao final do comando.

10. Com os scripts gerados chame o comando ```make``` ou o comando ```ninja``` para começar a compilar.

11. Após o processo terá um arquivo executável com o nome ```blasteroids```. Este é o executável do jogo compilado.

- Se aparecer que ele não conseguiu incluir um tal de ```<allegro5/allegro.h>``` ou um erro do ld o problema é muito provavelmente a instalação do allegro precompilado.

- Se não quiser compilar e estiver usando Windows, vá em releases, lá tem o jogo pré compilado já com todas as dlls que precisa para rodar.
