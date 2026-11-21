# Pac-Man Embarcado

Projeto acadêmico desenvolvido para a disciplina ELEW32 – Sistemas Embarcados.

## Sobre o projeto

Desenvolvimento de um jogo eletrônico de labirinto inspirado no Pac-Man, executado em um sistema embarcado. O jogador controla o personagem principal por meio da inclinação física do dispositivo, utilizando um sensor de movimento MPU6050.

O jogo apresenta um labirinto, personagens, inimigos e itens coletáveis em um display colorido ST7789. A interação também conta com botões físicos para navegação pelos menus e controle dos estados do jogo.

O projeto utiliza um sistema operacional de tempo real (RTOS) para organizar a execução das diferentes tarefas e a comunicação entre os módulos.

## Equipe e responsabilidades

| Integrante | Responsabilidade principal |
|---|---|
| Vinicius | Plataforma, hardware e interface gráfica |
| Eduardo | Sensores, controle por inclinação, botões e estados |
| Pedro | RTOS, lógica do jogo e inimigos |

## Organização do repositório

- `docs/`: documentação e diagramas do projeto.
- `software/`: código-fonte e testes.
- `hardware/`: informações sobre montagem e componentes.
- `assets/`: recursos gráficos e sonoros.
- `tools/`: scripts e ferramentas auxiliares.

## Desenvolvimento

O desenvolvimento é organizado em branches individuais e uma branch de integração.

- `main`: versão estável do projeto.
- `integration`: integração das funcionalidades desenvolvidas.
- `pessoa-1`: desenvolvimento da plataforma e interface gráfica.
- `pessoa-2`: desenvolvimento dos sensores e controles.
- `pessoa-3`: desenvolvimento do RTOS e da lógica do jogo.

As funcionalidades devem ser integradas e testadas antes de serem incorporadas à branch `main`.

## Estado do projeto

O repositório encontra-se em fase inicial de organização. A definição detalhada da plataforma de hardware e do ambiente de desenvolvimento será documentada conforme a implementação avançar.