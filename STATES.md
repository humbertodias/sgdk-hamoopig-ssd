# HAMOOPIG Estados / States

Este documento descreve os estados (FSM - Finite State Machine) utilizados no engine HAMOOPIG.

## Uso dos Enums

Os estados agora podem ser identificados usando enums definidos em `inc/game_types.h` ao invés de números mágicos.

### Exemplo de uso:

Antes (números mágicos):
```c
if(P[i].state == 100) { 
    // Personagem parado
}
```

Depois (usando enums):
```c
if(P[i].state == STATE_PARADO) { 
    // Personagem parado - código mais legível
}
```

## Tabela de Estados

### Retratos
| Enum | Valor | Descrição |
|------|-------|-----------|
| STATE_PORTRAIT_GRANDE | 0 | Retrato Grande do Personagem |
| STATE_PORTRAIT_PEQUENO | 1 | Retrato Pequeno do Personagem |

### Em Pé - Distância Longa
| Enum | Valor | Descrição |
|------|-------|-----------|
| STATE_PARADO | 100 | Personagem PARADO |
| STATE_SOCO_FRACO_LONGE | 101 | Soco Fraco de Longe |
| STATE_SOCO_MEDIO_LONGE | 102 | Soco Médio de Longe |
| STATE_SOCO_FORTE_LONGE | 103 | Soco Forte de Longe |
| STATE_CHUTE_FRACO_LONGE | 104 | Chute Fraco de Longe |
| STATE_CHUTE_MEDIO_LONGE | 105 | Chute Médio de Longe |
| STATE_CHUTE_FORTE_LONGE | 106 | Chute Forte de Longe |
| STATE_DEFESA_PE_INICIO | 107 | Inicio da Defesa em Pé |
| STATE_DEFESA_PE_DEFENDENDO | 108 | Defendendo em Pé |
| STATE_DEFESA_PE_FINAL | 109 | Final da Defesa em Pé |
| STATE_DEFESA_PE_APLICADA | 110 | Defesa em Pé, Aplicada |

### Em Pé - Distância Curta
| Enum | Valor | Descrição |
|------|-------|-----------|
| STATE_SOCO_FRACO_PERTO | 151 | Soco Fraco de Perto |
| STATE_SOCO_MEDIO_PERTO | 152 | Soco Médio de Perto |
| STATE_SOCO_FORTE_PERTO | 153 | Soco Forte de Perto |
| STATE_CHUTE_FRACO_PERTO | 154 | Chute Fraco de Perto |
| STATE_CHUTE_MEDIO_PERTO | 155 | Chute Médio de Perto |
| STATE_CHUTE_FORTE_PERTO | 156 | Chute Forte de Perto |

### Abaixado
| Enum | Valor | Descrição |
|------|-------|-----------|
| STATE_ABAIXADO | 200 | Abaixado |
| STATE_SOCO_FRACO_ABAIXADO | 201 | Soco Fraco Abaixado |
| STATE_SOCO_MEDIO_ABAIXADO | 202 | Soco Médio Abaixado |
| STATE_SOCO_FORTE_ABAIXADO | 203 | Soco Forte Abaixado |
| STATE_CHUTE_FRACO_ABAIXADO | 204 | Chute Fraco Abaixado |
| STATE_CHUTE_MEDIO_ABAIXADO | 205 | Chute Médio Abaixado |
| STATE_CHUTE_FORTE_ABAIXADO | 206 | Chute Forte Abaixado |
| STATE_DEFESA_ABAIXADO_INICIO | 207 | Inicio da Defesa Abaixado |
| STATE_DEFESA_ABAIXADO_DEFENDENDO | 208 | Defendendo Abaixado |
| STATE_DEFESA_ABAIXADO_FINAL | 209 | Final da Defesa Abaixado |
| STATE_DEFESA_ABAIXADO_APLICADA | 210 | Defesa Abaixada, Aplicada |

### No Ar - Neutro
| Enum | Valor | Descrição |
|------|-------|-----------|
| STATE_PULO_NEUTRO | 300 | Pulo Neutro |
| STATE_SOCO_FRACO_AEREO_NEUTRO | 301 | Soco Fraco Aéreo Neutro |
| STATE_SOCO_MEDIO_AEREO_NEUTRO | 302 | Soco Médio Aéreo Neutro |
| STATE_SOCO_FORTE_AEREO_NEUTRO | 303 | Soco Forte Aéreo Neutro |
| STATE_CHUTE_FRACO_AEREO_NEUTRO | 304 | Chute Fraco Aéreo Neutro |
| STATE_CHUTE_MEDIO_AEREO_NEUTRO | 305 | Chute Médio Aéreo Neutro |
| STATE_CHUTE_FORTE_AEREO_NEUTRO | 306 | Chute Forte Aéreo Neutro |

### No Ar - Para Trás
| Enum | Valor | Descrição |
|------|-------|-----------|
| STATE_PULO_TRAS | 310 | Pulo para Trás |
| STATE_SOCO_FRACO_AEREO_TRAS | 311 | Soco Fraco Aéreo para Trás |
| STATE_SOCO_MEDIO_AEREO_TRAS | 312 | Soco Médio Aéreo para Trás |
| STATE_SOCO_FORTE_AEREO_TRAS | 313 | Soco Forte Aéreo para Trás |
| STATE_CHUTE_FRACO_AEREO_TRAS | 314 | Chute Fraco Aéreo para Trás |
| STATE_CHUTE_MEDIO_AEREO_TRAS | 315 | Chute Médio Aéreo para Trás |
| STATE_CHUTE_FORTE_AEREO_TRAS | 316 | Chute Forte Aéreo para Trás |

### No Ar - Para Frente
| Enum | Valor | Descrição |
|------|-------|-----------|
| STATE_PULO_FRENTE | 320 | Pulo para Frente |
| STATE_SOCO_FRACO_AEREO_FRENTE | 321 | Soco Fraco Aéreo para Frente |
| STATE_SOCO_MEDIO_AEREO_FRENTE | 322 | Soco Médio Aéreo para Frente |
| STATE_SOCO_FORTE_AEREO_FRENTE | 323 | Soco Forte Aéreo para Frente |
| STATE_CHUTE_FRACO_AEREO_FRENTE | 324 | Chute Fraco Aéreo para Frente |
| STATE_CHUTE_MEDIO_AEREO_FRENTE | 325 | Chute Médio Aéreo para Frente |
| STATE_CHUTE_FORTE_AEREO_FRENTE | 326 | Chute Forte Aéreo para Frente |

### Movimentação
| Enum | Valor | Descrição |
|------|-------|-----------|
| STATE_ANDANDO_TRAS | 410 | Andando para Trás |
| STATE_ANDANDO_FRENTE | 420 | Andando para Frente |
| STATE_ESQUIVA_BAIXO | 470 | Esquiva para Baixo / Esquiva para Trás |
| STATE_ROLAMENTO_TRAS | 471 | Rolamento para Trás |
| STATE_ROLAMENTO_FRENTE | 472 | Rolamento para Frente |
| STATE_CORRIDA_INICIO | 480 | Inicio da corrida |
| STATE_CORRENDO | 481 | Correndo |
| STATE_CORRIDA_FINAL | 482 | Final da Corrida |

### Levando Golpe
| Enum | Valor | Descrição |
|------|-------|-----------|
| STATE_HIT_TIPO1_FRACO | 501 | Hit Tipo 1, Fraco |
| STATE_HIT_TIPO1_MEDIO | 502 | Hit Tipo 1, Medio |
| STATE_HIT_TIPO1_FORTE | 503 | Hit Tipo 1, Forte |
| STATE_HIT_TIPO2_FRACO | 506 | Hit Tipo 2, Fraco |
| STATE_HIT_TIPO2_MEDIO | 507 | Hit Tipo 2, Medio |
| STATE_HIT_TIPO2_FORTE | 508 | Hit Tipo 2, Forte |
| STATE_HIT_TIPO3_FRACO | 511 | Hit Tipo 3, Fraco |
| STATE_HIT_TIPO3_MEDIO | 512 | Hit Tipo 3, Medio |
| STATE_HIT_TIPO3_FORTE | 513 | Hit Tipo 3, Forte |
| STATE_USER_HIT | 516 | User Hit |
| STATE_CAINDO | 550 | Caindo |
| STATE_QUICANDO_CHAO | 551 | Quicando no chão |
| STATE_LEVANTANDO | 552 | Levantando |
| STATE_CAIDO_MORTO | 570 | Caido, Morto |

### Transições
| Enum | Valor | Descrição |
|------|-------|-----------|
| STATE_ABAIXANDO | 601 | Abaixando |
| STATE_LEVANTANDO_TRANSICAO | 602 | Levantando |
| STATE_INICIO_PULO_TRAS | 603 | Inicio Pulo para Trás |
| STATE_INICIO_PULO_NEUTRO | 604 | Inicio Pulo Neutro |
| STATE_INICIO_PULO_FRENTE | 605 | Inicio Pulo para Frente |
| STATE_FINAL_PULO | 606 | Final do Pulo / Aterrisando no chão |
| STATE_VIRANDO_PE | 607 | Virando, em Pé |
| STATE_VIRANDO_ABAIXADO | 608 | Virando Abaixado |

### Comemorações e Derrotas
| Enum | Valor | Descrição |
|------|-------|-----------|
| STATE_INTRO | 610 | Intro |
| STATE_WIN1 | 611 | Win1 |
| STATE_WIN2 | 612 | Win2 |
| STATE_WIN3 | 613 | Win3 |
| STATE_WIN4 | 614 | Win4 |
| STATE_PERDENDO_TIME_OVER | 615 | Perdendo por Time Over |
| STATE_RAGE_EXPLOSION | 618 | Rage Explosion (Samurai Shodown 2) |

### Especiais
| Enum | Valor | Descrição |
|------|-------|-----------|
| STATE_ESPECIAL_700 | 700 | Especial 1 |
| STATE_FIREBALL_701 | 701 | Fireball 1 |
| STATE_SPARK_FIREBALL | 702 | Spark da Fireball 1 |
| STATE_ESPECIAL_710 | 710 | Especial 2 |
| STATE_ESPECIAL_711 | 711 | Especial 2 Fireball |
| STATE_ESPECIAL_720 | 720 | Especial 3 |
| STATE_ESPECIAL_730 | 730 | Especial 4 |
| STATE_ESPECIAL_790 | 790 | Last special slot |

## Notas

Os números de 700 a 900 podem ser usados para especiais. Recomenda-se usar cada dezena para um tipo de especial, assim do 700 até o 900 há espaço para 20 especiais e supers.

Exemplo de como trabalhar um especial:
- 700-709: Especial 1 e variações
- 710-719: Especial 2 e variações  
- 720-729: Especial 3 e variações
- etc.
