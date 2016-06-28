Este é um simulador baseado em centros de serviço.


Configuração de um arquivo de entrada:

<Tempo simulado> (unsigned long)
<id_entrada> (unsigned long)
Configuração de roteadores e/ou componentes:
    Componentes:
        <'C', id> (char, unsigned long)
        <quantidade de servidores> (unsigned long)
        <min_intervalo, max_intervalo> (unsigned int, unsigned int)
        <tipo_da_saída, identificação> (char, unsigned long)
    Routers:
        <'D', id>  (char, unsigned long)
        <tipo de saída, id, chances> (char, unsigned long, unsigned int)
        <tipo de saída, id, chances> (char, unsigned long, unsigned int)


Tipos de saída podem ser:
    'D' que representam um roteador que toma decisões probabilísticas
    'C' que são componentes
    'S' que são saídas do modelo 


