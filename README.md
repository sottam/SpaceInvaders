# SpaceInvaders
Um simples space invaders escrito em C/C++ com auxilio da Biblioteca Allegro.

Esse jogo foi fruto de um trabalho final da materia de computação I na UFRJ.
Foi originalmente escrito de maneira bem hardcore, usando Gedit e compilação por linha de comando em terminal. Simplesmente por que eu não tinha tempo suficiente para setar uma IDE no Linux Mint. Somente depois que o projeto foi entregue que coloquei no Code::Blocks.

Mas, não sabia usar GitHub, entao ficou abandonado, entregue em meio aos bits e bytes e esquecido no meu Dropbox. Hoje(08/06/17), depois de uma aula de Computadores e Programação me lembrei do projeto de decidi ver se conseguia colocar para funcionar novamente. Com isso, aproveitei para ver se era portável no Windows, uma vez que foi originalmente escrito no Linux.

Funcionou perfeitamente! Entretanto, por uma falha no projeto, o jogo estava rodando insanamente acelerado no Windows e em sua velocidade esperada no linux(Que estava rodando em ambiente Virtualizado). A falha era simples! Nenhuma funcao de movimento fazia uso de Frame Delta Time para calcular a movimentação com tempo escalado.

Uma vez identificada a falha, pus a mão na massa para deixar o projeto em um estado jogavel em qualquer plataforma!

Nenhuma arte foi feita por mim, foram obtidas no calor do momento da deadline da entrega desse projeto. Portanto, arte nenhuma é de minha autoria. Além disso, parte do código original foi fornecido pelo próprio professor, eu fiz o trabalho de compreender e dar prosseguimento a coisa!

ENJOY !

=D
