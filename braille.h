/ * ********************************************** **********************************
 * La licencia MIT (MIT) *
 * *
 * Copyright (c) 2018 Bertrand Martel *
 * * 
 * Por la presente se otorga permiso, sin cargo, a cualquier persona que obtenga una copia * 
 * de este software y los archivos de documentación asociados (el "Software"), para tratar * 
 * en el Software sin restricciones, incluidos, entre otros, los derechos * 
 * para usar, copiar, modificar, fusionar, publicar, distribuir, sublicenciar y / o vender * 
 * copias del Software, y para permitir a las personas a las que pertenece el Software * 
 * amueblado para ello, sujeto a las siguientes condiciones: * 
 * * 
 * El aviso de derechos de autor anterior y este aviso de permiso se incluirán en * 
* todas las copias o partes sustanciales del Software. *
 * * 
 * EL SOFTWARE SE PROPORCIONA "TAL CUAL", SIN GARANTÍA DE NINGÚN TIPO, EXPRESA O * 
 * IMPLÍCITA, INCLUYENDO PERO NO LIMITADO A LAS GARANTÍAS DE COMERCIABILIDAD, * 
* APTITUD PARA UN PROPÓSITO PARTICULAR Y NO INFRACCIÓN. EN NINGÚN CASO EL *
 * LOS AUTORES O TITULARES DE LOS DERECHOS DE AUTOR SERÁN RESPONSABLES DE CUALQUIER RECLAMO, DAÑOS U OTROS * 
 * RESPONSABILIDAD, YA SEA EN UNA ACCIÓN DE CONTRATO, AGRAVIO O DE OTRO MODO, QUE SURJA DE, * 
 * FUERA O EN CONEXIÓN CON EL SOFTWARE O EL USO U OTROS NEGOCIOS EN * 
* EL SOFTWARE. *
************************************************ ******************************** * /
/ * *
    braille.h
    
    Controlador Metec para el estándar Metec Braille-line de 20 celdas
    @autor Bertrand Martel
    @version 1.0
* /
# ifndef braille_h
# definir  braille_h

# Ifdef ARDUINO
# incluye  " Arduino.h "
# elif __arm__
# incluye  " stdint.h "
# endif

# definir  NADA                    0xFF
# definir  COMPLETO                       0x00
# define  DEFAULT_TIME_BETWEEN_CELL  30

# define  MIN_BRAILLE  0x2800
# define  MAX_BRAILLE  0x28FF

# Ifdef _WIN32
utilizando la  plataforma de espacio de nombres  ;
# incluye  < colección.h >
# definir  público PÚBLICO
# más
# definir  PÚBLICO
# endif  // _WIN32

espacio de nombres  MetecDriverLibrary
{
PUBLIC enum  class  ButtonState {Released = 0 , Pushed = 1 };

# Ifdef _WIN32
clase de  referencia pública MetecDriver sellado {
# más
class  MetecDriver {
#endif // _WIN32

público:
    MetecDriver ( uint8_t cellCount,
                       uint8_t on_pin,
                       uint8_t din_pin,
                       uint8_t strobe_pin,
                       uint8_t clk_pin,
                       uint8_t dout_pin);

    void  init ();

    vacío  claro ();

    vacío  completo ();

# Ifdef _WIN32
    void  writeCells ( const Array < uint16_t > ^ patrón, uint8_t max_charac, bool reverse);
# más
    void  writeCells ( uint16_t * patrón, uint8_t max_charac, bool reverse);
# endif  // _WIN32

    void  writeSingleCell ( uint8_t posición, uint16_t patrón);

    void  enableModule ();

    void  disableModule ();

    void  setWait ( uint8_t espera);
    uint8_t  getWait ();
    
    void  checkButton ();

# Ifdef _WIN32
    propiedad uint8_t btn_position
    {
        uint8_t  get () { return _btn_position; }
    }
    propiedad ButtonState btn_state
    {
        ButtonState get () { return _btn_state; }
    }
    propiedad bool btn_update
    {
        bool  get () { return _btn_update; }
         conjunto vacío ( valor bool ) {_btn_update = valor; }
    }
    propiedad bool btn_listen
    {
        bool  get () { return _btn_listen; }
         conjunto vacío ( valor bool ) {_btn_listen = valor; }
    }
# más
    uint8_t btn_position;
    ButtonState btn_state;
    bool btn_update;
    // verdadero al escuchar el botón / falso en caso contrario
    bool btn_listen = true ;
    ~ MetecDriver ();
# endif  // _WIN32

privado:
# Ifdef _WIN32
    ~ MetecDriver ();
# endif
    void  SetCell ( uint8_t posición, uint8_t valor);
    void  setCellNoDelay ( uint8_t posición, uint8_t valor);
    void  writeAllCell ();
    void  stopCheckingBtn ();

    uint8_t _on_pin_val = 0 ;
    uint8_t _din_pin_val = 0 ;
    uint8_t _strobe_pin_val = 0 ;
    uint8_t _clk_pin_val = 0 ;
    uint8_t _dout_pin_val = 0 ;
    uint8_t _wait = DEFAULT_TIME_BETWEEN_CELL;

    // establecer al iniciar checkButton
    bool btn_listening = false ;

# Ifdef _WIN32
    Windows :: Dispositivos :: Gpio :: GpioPin ^ _on_pin;
    Windows :: Dispositivos :: Gpio :: GpioPin ^ _din_pin;
    Windows :: Dispositivos :: Gpio :: GpioPin ^ _strobe_pin;
    Windows :: Dispositivos :: Gpio :: GpioPin ^ _clk_pin;
    Windows :: Dispositivos :: Gpio :: GpioPin ^ _dout_pin;
# más
    uint8_t _on_pin = 0 ;
    uint8_t _din_pin = 0 ;
    uint8_t _strobe_pin = 0 ;
    uint8_t _clk_pin = 0 ;
    uint8_t _dout_pin = 0 ;
# endif  // _WIN32

    uint8_t _cellSize = 0 ;
    uint8_t * _cells = 0 ;
    uint8_t * _keys = 0 ;

# Ifdef _WIN32
    uint8_t _btn_position = 0 ;
    ButtonState _btn_state = ButtonState :: Lanzado;
    bool _btn_update;
    bool _btn_listen;
# endif
};

const  uint16_t braille_db [ 256 ] = {
    0xFF , // 0x2800 ⠀ PATRÓN DE BRAILLE EN BLANCO
    0xF7 , // 0x2801 ⠁ PATRÓN DE BRAILLE DOTS-1
    0xEF , // 0x2802 ⠂ PATRÓN DE BRAILLE DOTS-2
    0xE7 , // 0x2803 ⠃ PATRÓN DE BRAILLE DOTS-12
    0xDF , // 0x2804 ⠄ PATRÓN DE BRAILLE DOTS-3
    0xD7 , // 0x2805 ⠅ PATRÓN DE BRAILLE DOTS-13
    0xCF , // 0x2806 ⠆ PATRÓN DE BRAILLE DOTS-23
    0xC7 , // 0x2807 ⠇ PATRÓN DE BRAILLE DOTS-123
    0xFE , // 0x2808 ⠈ PATRÓN DE BRAILLE DOTS-4
    0xF6 , // 0x2809 ⠉ PATRÓN DE BRAILLE DOTS-14
    0xEE , // 0x280A ⠊ PATRÓN DE BRAILLE DOTS-24
    0xE6 , // 0x280B ⠋ PATRÓN DE BRAILLE DOTS-124
    0xDE , // 0x280C ⠌ PATRÓN DE BRAILLE DOTS-34
    0xD6 , // 0x280D ⠍ PATRÓN DE BRAILLE DOTS-134
    0xCE , // 0x280E ⠎ PATRÓN DE BRAILLE DOTS-234
    0xC6 , // 0x280F ⠏ PATRÓN DE BRAILLE DOTS-1234
    0xFD , // 0x2810 ⠐ PATRÓN DE BRAILLE DOTS-5
    0xF5 , // 0x2811 ⠑ PATRÓN DE BRAILLE DOTS-15
    0xED , // 0x2812 ⠒ PATRÓN DE BRAILLE DOTS-25
    0xE5 , // 0x2813 ⠓ PATRÓN DE BRAILLE DOTS-125
    0xDD , // 0x2814 ⠔ PATRÓN DE BRAILLE DOTS-35
    0xD5 , // 0x2815 ⠕ PATRÓN DE BRAILLE DOTS-135
    0xCD , // 0x2816 ⠖ PATRÓN DE BRAILLE DOTS-235
    0xC5 , // 0x2817 ⠗ PATRÓN DE BRAILLE DOTS-1235
    0xFC , // 0x2818 ⠘ PATRÓN DE BRAILLE DOTS-45
    0xF4 , // 0x2819 ⠙ PATRÓN DE BRAILLE DOTS-145
    0xEC , // 0x281A ⠚ PATRÓN DE BRAILLE DOTS-245
    0xE4 , // 0x281B ⠛ PATRÓN DE BRAILLE DOTS-1245
    0xDC , // 0x281C ⠜ PATRÓN DE BRAILLE DOTS-345
    0xD4 , // 0x281D ⠝ PATRÓN DE BRAILLE DOTS-1345
    0xCC , // 0x281E ⠞ PATRÓN DE BRAILLE DOTS-2345
    0xC4 , // 0x281F ⠟ PATRÓN DE BRAILLE DOTS-12345
    0xFB , // 0x2820 ⠠ PATRÓN DE BRAILLE DOTS-6
    0xF3 , // 0x2821 ⠡ PATRÓN DE BRAILLE DOTS-16
    0xEB , // 0x2822 ⠢ PATRÓN DE BRAILLE DOTS-26
    0xE3 , // 0x2823 ⠣ PATRÓN DE BRAILLE DOTS-126
    0xDB , // 0x2824 ⠤ PATRÓN DE BRAILLE DOTS-36
    0xD3 , // 0x2825 ⠥ PATRÓN DE BRAILLE DOTS-136
    0xCB , // 0x2826 ⠦ PATRÓN DE BRAILLE DOTS-236
    0xC3 , // 0x2827 ⠧ PATRÓN DE BRAILLE DOTS-1236
    0xFA , // 0x2828 ⠨ PATRÓN DE BRAILLE DOTS-46
    0xF2 , // 0x2829 ⠩ PATRÓN DE BRAILLE DOTS-146
    0xEA , // 0x282A ⠪ PATRÓN DE BRAILLE DOTS-246
    0xE2 , // 0x282B ⠫ PATRÓN DE BRAILLE DOTS-1246
    0xDA , // 0x282C ⠬ PATRÓN DE BRAILLE DOTS-346
    0xD2 , // 0x282D ⠭ PATRÓN DE BRAILLE DOTS-1346
    0xCA , // 0x282E ⠮ PATRÓN DE BRAILLE DOTS-2346
    0xC2 , // 0x282F ⠯ PATRÓN DE BRAILLE DOTS-12346
    0xF9 , // 0x2830 ⠰ PATRÓN DE BRAILLE DOTS-56
    0xF1 , // 0x2831 ⠱ PATRÓN DE BRAILLE DOTS-156
    0xE9 , // 0x2832 ⠲ PATRÓN DE BRAILLE DOTS-256
    0xE1 , // 0x2833 ⠳ PATRÓN DE BRAILLE DOTS-1256
    0xD9 , // 0x2834 ⠴ PATRÓN DE BRAILLE DOTS-356
    0xD1 , // 0x2835 ⠵ PATRÓN DE BRAILLE DOTS-1356
    0xC9 , // 0x2836 ⠶ PATRÓN DE BRAILLE DOTS-2356
    0xC1 , // 0x2837 ⠷ PATRÓN DE BRAILLE DOTS-12356
    0xF8 , // 0x2838 ⠸ PATRÓN DE BRAILLE DOTS-456
    0xF0 , // 0x2839 ⠹ PATRÓN DE BRAILLE DOTS-1456
    0xE8 , // 0x283A ⠺ PATRÓN DE BRAILLE DOTS-2456
    0xE0 , // 0x283B ⠻ PATRÓN DE BRAILLE DOTS-12456
    0xD8 , // 0x283C ⠼ PATRÓN DE BRAILLE DOTS-3456
    0xD0 , // 0x283D ⠽ PATRÓN DE BRAILLE DOTS-13456
    0xC8 , // 0x283E ⠾ PATRÓN DE BRAILLE DOTS-23456
    0xC0 , // 0x283F ⠿ PATRÓN DE BRAILLE DOTS-123456
    0x7F , // 0x2840 ⡀ PATRÓN DE BRAILLE DOTS-7
    0x77 , // 0x2841 ⡁ PATRÓN DE BRAILLE DOTS-17
    0x6F , // 0x2842 ⡂ PATRÓN DE BRAILLE DOTS-27
    0x67 , // 0x2843 ⡃ PATRÓN DE BRAILLE DOTS-127
    0x5F , // 0x2844 ⡄ PATRÓN DE BRAILLE DOTS-37
    0x57 , // 0x2845 ⡅ PATRÓN DE BRAILLE DOTS-137
    0x4F , // 0x2846 ⡆ PATRÓN DE BRAILLE DOTS-237
    0x47 , // 0x2847 ⡇ PATRÓN DE BRAILLE DOTS-1237
    0x7E , // 0x2848 ⡈ PATRÓN DE BRAILLE DOTS-47
    0x76 , // 0x2849 ⡉ PATRÓN DE BRAILLE DOTS-147
    0x6E , // 0x284A ⡊ PATRÓN DE BRAILLE DOTS-247
    0x66 , // 0x284B ⡋ PATRÓN DE BRAILLE DOTS-1247
    0x5E , // 0x284C ⡌ PATRÓN DE BRAILLE DOTS-347
    0x56 , // 0x284D ⡍ PATRÓN DE BRAILLE DOTS-1347
    0x4E , // 0x284E ⡎ PATRÓN DE BRAILLE DOTS-2347
    0x46 , // 0x284F ⡏ PATRÓN DE BRAILLE DOTS-12347
    0x7D , // 0x2850 ⡐ PATRÓN DE BRAILLE DOTS-57
    0x75 , // 0x2851 ⡑ PATRÓN DE BRAILLE DOTS-157
    0x6D , // 0x2852 ⡒ PATRÓN DE BRAILLE DOTS-257
    0x65 , // 0x2853 ⡓ PATRÓN DE BRAILLE DOTS-1257
    0x5D , // 0x2854 ⡔ PATRÓN DE BRAILLE DOTS-357
    0x55 , // 0x2855 ⡕ PATRÓN DE BRAILLE DOTS-1357
    0x4D , // 0x2856 ⡖ PATRÓN DE BRAILLE DOTS-2357
    0x45 , // 0x2857 ⡗ PATRÓN DE BRAILLE DOTS-12357
    0x7C , // 0x2858 ⡘ PATRÓN DE BRAILLE DOTS-457
    0x74 , // 0x2859 ⡙ PATRÓN DE BRAILLE DOTS-1457
    0x6C , // 0x285A ⡚ PATRÓN DE BRAILLE DOTS-2457
    0x64 , // 0x285B ⡛ PATRÓN DE BRAILLE DOTS-12457
    0x5C , // 0x285C ⡜ PATRÓN DE BRAILLE DOTS-3457
    0x54 , // 0x285D ⡝ PATRÓN DE BRAILLE DOTS-13457
    0x4C , // 0x285E ⡞ PATRÓN DE BRAILLE DOTS-23457
    0x44 , // 0x285F ⡟ PATRÓN DE BRAILLE DOTS-123457
    0x7B , // 0x2860 ⡠ PATRÓN DE BRAILLE DOTS-67
    0x73 , // 0x2861 ⡡ PATRÓN DE BRAILLE DOTS-167
    0x6B , // 0x2862 ⡢ PATRÓN DE BRAILLE DOTS-267
    0x63 , // 0x2863 ⡣ PATRÓN DE BRAILLE DOTS-1267
    0x5B , // 0x2864 ⡤ PATRÓN DE BRAILLE DOTS-367
    0x53 , // 0x2865 ⡥ PATRÓN DE BRAILLE DOTS-1367
    0x4B , // 0x2866 ⡦ PATRÓN DE BRAILLE DOTS-2367
    0x43 , // 0x2867 ⡧ PATRÓN DE BRAILLE DOTS-12367
    0x7A , // 0x2868 ⡨ PATRÓN DE BRAILLE DOTS-467
    0x72 , // 0x2869 ⡩ PATRÓN DE BRAILLE DOTS-1467
    0x6A , // 0x286A ⡪ PATRÓN DE BRAILLE DOTS-2467
    0x62 , // 0x286B ⡫ PATRÓN DE BRAILLE DOTS-12467
    0x5A , // 0x286C ⡬ PATRÓN DE BRAILLE DOTS-3467
    0x52 , // 0x286D ⡭ PATRÓN DE BRAILLE DOTS-13467
    0x4A , // 0x286E ⡮ PATRÓN DE BRAILLE DOTS-23467
    0x42 , // 0x286F ⡯ PATRÓN DE BRAILLE DOTS-123467
    0x79 , // 0x2870 ⡰ PATRÓN DE BRAILLE DOTS-567
    0x71 , // 0x2871 ⡱ PATRÓN DE BRAILLE DOTS-1567
    0x69 , // 0x2872 ⡲ PATRÓN DE BRAILLE DOTS-2567
    0x61 , // 0x2873 ⡳ PATRÓN DE BRAILLE DOTS-12567
    0x59 , // 0x2874 ⡴ PATRÓN DE BRAILLE DOTS-3567
    0x51 , // 0x2875 ⡵ PATRÓN DE BRAILLE DOTS-13567
    0x49 , // 0x2876 ⡶ PATRÓN DE BRAILLE DOTS-23567
    0x41 , // 0x2877 ⡷ PATRÓN DE BRAILLE DOTS-123567
    0x78 , // 0x2878 ⡸ PATRÓN DE BRAILLE DOTS-4567
    0x70 , // 0x2879 ⡹ PATRÓN DE BRAILLE DOTS-14567
    0x68 , // 0x287A ⡺ PATRÓN DE BRAILLE DOTS-24567
    0x60 , // 0x287B ⡻ PATRÓN DE BRAILLE DOTS-124567
    0x58 , // 0x287C ⡼ PATRÓN DE BRAILLE DOTS-34567
    0x50 , // 0x287D ⡽ PATRÓN DE BRAILLE DOTS-134567
    0x48 , // 0x287E ⡾ PATRÓN DE BRAILLE DOTS-234567
    0x40 , // 0x287F ⡿ PATRÓN DE BRAILLE DOTS-1234567
    0xBF , // 0x2880 ⢀ PATRÓN DE BRAILLE DOTS-8
    0xB7 , // 0x2881 ⢁ PATRÓN DE BRAILLE DOTS-18
    0xAF , // 0x2882 ⢂ PATRÓN DE BRAILLE DOTS-28
    0xA7 , // 0x2883 ⢃ PATRÓN DE BRAILLE DOTS-128
    0x9F , // 0x2884 ⢄ PATRÓN DE BRAILLE DOTS-38
    0x97 , // 0x2885 ⢅ PATRÓN DE BRAILLE DOTS-138
    0x8F , // 0x2886 ⢆ PATRÓN DE BRAILLE DOTS-238
    0x87 , // 0x2887 ⢇ PATRÓN DE BRAILLE DOTS-1238
    0xBE , // 0x2888 ⢈ PATRÓN DE BRAILLE DOTS-48
    0xB6 , // 0x2889 ⢉ PATRÓN DE BRAILLE DOTS-148
    0xAE , // 0x288A ⢊ PATRÓN DE BRAILLE DOTS-248
    0xA6 , // 0x288B ⢋ PATRÓN DE BRAILLE DOTS-1248
    0x9E , // 0x288C ⢌ PATRÓN DE BRAILLE DOTS-348
    0x96 , // 0x288D ⢍ PATRÓN DE BRAILLE DOTS-1348
    0x8E , // 0x288E ⢎ PATRÓN DE BRAILLE DOTS-2348
    0x86 , // 0x288F ⢏ PATRÓN DE BRAILLE DOTS-12348
    0xBD , // 0x2890 ⢐ PATRÓN DE BRAILLE DOTS-58
    0xB5 , // 0x2891 ⢑ PATRÓN DE BRAILLE DOTS-158
    0xAD , // 0x2892 ⢒ PATRÓN DE BRAILLE DOTS-258
    0xA5 , // 0x2893 ⢓ PATRÓN DE BRAILLE DOTS-1258
    0x9D , // 0x2894 ⢔ PATRÓN DE BRAILLE DOTS-358
    0x95 , // 0x2895 ⢕ PATRÓN DE BRAILLE DOTS-1358
    0x8D , // 0x2896 ⢖ PATRÓN DE BRAILLE DOTS-2358
    0x85 , // 0x2897 ⢗ PATRÓN DE BRAILLE DOTS-12358
    0xBC , // 0x2898 ⢘ PATRÓN DE BRAILLE DOTS-458
    0xB4 , // 0x2899 ⢙ PATRÓN DE BRAILLE DOTS-1458
    0xAC , // 0x289A ⢚ PATRÓN DE BRAILLE DOTS-2458
    0xA4 , // 0x289B ⢛ PATRÓN DE BRAILLE DOTS-12458
    0x9C , // 0x289C ⢜ PATRÓN DE BRAILLE DOTS-3458
    0x94 , // 0x289D ⢝ PATRÓN DE BRAILLE DOTS-13458
    0x8C , // 0x289E ⢞ PATRÓN DE BRAILLE DOTS-23458
    0x84 , // 0x289F ⢟ PATRÓN DE BRAILLE DOTS-123458
    0xBB , // 0x28A0 ⢠ PATRÓN DE BRAILLE DOTS-68
    0xB3 , // 0x28A1 ⢡ PATRÓN DE BRAILLE DOTS-168
    0xAB , // 0x28A2 ⢢ PATRÓN DE BRAILLE DOTS-268
    0xA3 , // 0x28A3 ⢣ PATRÓN DE BRAILLE DOTS-1268
    0x9B , // 0x28A4 ⢤ PATRÓN DE BRAILLE DOTS-368
    0x93 , // 0x28A5 ⢥ PATRÓN DE BRAILLE DOTS-1368
    0x8B , // 0x28A6 ⢦ PATRÓN DE BRAILLE DOTS-2368
    0x83 , // 0x28A7 ⢧ PATRÓN DE BRAILLE DOTS-12368
    0xBA , // 0x28A8 ⢨ PATRÓN DE BRAILLE DOTS-468
    0xB2 , // 0x28A9 ⢩ PATRÓN DE BRAILLE DOTS-1468
    0xAA , // 0x28AA ⢪ PATRÓN DE BRAILLE DOTS-2468
    0xA2 , // 0x28AB ⢫ PATRÓN DE BRAILLE DOTS-12468
    0x9A , // 0x28AC ⢬ PATRÓN DE BRAILLE DOTS-3468
    0x92 , // 0x28AD ⢭ PATRÓN DE BRAILLE DOTS-13468
    0x8A , // 0x28AE ⢮ PATRÓN DE BRAILLE DOTS-23468
    0x82 , // 0x28AF ⢯ PATRÓN DE BRAILLE DOTS-123468
    0xB9 , // 0x28B0 ⢰ PATRÓN DE BRAILLE DOTS-568
    0xB1 , // 0x28B1 ⢱ PATRÓN DE BRAILLE DOTS-1568
    0xA9 , // 0x28B2 ⢲ PATRÓN DE BRAILLE DOTS-2568
    0xA1 , // 0x28B3 ⢳ PATRÓN DE BRAILLE DOTS-12568
    0x99 , // 0x28B4 ⢴ PATRÓN DE BRAILLE DOTS-3568
    0x91 , // 0x28B5 ⢵ PATRÓN DE BRAILLE DOTS-13568
    0x89 , // 0x28B6 ⢶ PATRÓN DE BRAILLE DOTS-23568
    0x81 , // 0x28B7 ⢷ PATRÓN DE BRAILLE DOTS-123568
    0xB8 , // 0x28B8 ⢸ PATRÓN DE BRAILLE DOTS-4568
    0xB0 , // 0x28B9 ⢹ PATRÓN DE BRAILLE DOTS-14568
    0xA8 , // 0x28BA ⢺ PATRÓN DE BRAILLE DOTS-24568
    0xA0 , // 0x28BB ⢻ PATRÓN DE BRAILLE DOTS-124568
    0x98 , // 0x28BC ⢼ PATRÓN DE BRAILLE DOTS-34568
    0x90 , // 0x28BD ⢽ PATRÓN DE BRAILLE DOTS-134568
    0x88 , // 0x28BE ⢾ PATRÓN DE BRAILLE DOTS-234568
    0x80 , // 0x28BF ⢿ PATRÓN DE BRAILLE DOTS-1234568
    0x3F , // 0x28C0 ⣀ PATRÓN DE BRAILLE DOTS-78
    0x37 , // 0x28C1 ⣁ PATRÓN DE BRAILLE DOTS-178
    0x2F , // 0x28C2 ⣂ PATRÓN DE BRAILLE DOTS-278
    0x27 , // 0x28C3 ⣃ PATRÓN DE BRAILLE DOTS-1278
    0x1F , // 0x28C4 ⣄ PATRÓN DE BRAILLE DOTS-378
    0x17 , // 0x28C5 ⣅ PATRÓN DE BRAILLE DOTS-1378
    0x0F , // 0x28C6 ⣆ PATRÓN DE BRAILLE DOTS-2378
    0x07 , // 0x28C7 ⣇ PATRÓN DE BRAILLE DOTS-12378
    0x3E , // 0x28C8 ⣈ PATRÓN DE BRAILLE DOTS-478
    0x36 , // 0x28C9 ⣉ PATRÓN DE BRAILLE DOTS-1478
    0x2E , // 0x28CA ⣊ PATRÓN DE BRAILLE DOTS-2478
    0x26 , // 0x28CB ⣋ PATRÓN DE BRAILLE DOTS-12478
    0x1E , // 0x28CC ⣌ PATRÓN DE BRAILLE DOTS-3478
    0x16 , // 0x28CD ⣍ PATRÓN DE BRAILLE DOTS-13478
    0x0E , // 0x28CE ⣎ PATRÓN DE BRAILLE DOTS-23478
    0x06 , // 0x28CF ⣏ PATRÓN DE BRAILLE DOTS-123478
    0x3D , // 0x28D0 ⣐ PATRÓN DE BRAILLE DOTS-578
    0x35 , // 0x28D1 ⣑ PATRÓN DE BRAILLE DOTS-1578
    0x2D , // 0x28D2 ⣒ PATRÓN DE BRAILLE DOTS-2578
    0x25 , // 0x28D3 ⣓ PATRÓN DE BRAILLE DOTS-12578
    0x1D , // 0x28D4 ⣔ PATRÓN DE BRAILLE DOTS-3578
    0x15 , // 0x28D5 ⣕ PATRÓN DE BRAILLE DOTS-13578
    0x0D , // 0x28D6 ⣖ PATRÓN DE BRAILLE DOTS-23578
    0x05 , // 0x28D7 ⣗ PATRÓN DE BRAILLE DOTS-123578
    0x3C , // 0x28D8 ⣘ PATRÓN DE BRAILLE DOTS-4578
    0x34 , // 0x28D9 ⣙ PATRÓN DE BRAILLE DOTS-14578
    0x2C , // 0x28DA ⣚ PATRÓN DE BRAILLE DOTS-24578
    0x24 , // 0x28DB ⣛ PATRÓN DE BRAILLE DOTS-124578
    0x1C , // 0x28DC ⣜ PATRÓN DE BRAILLE DOTS-34578
    0x14 , // 0x28DD ⣝ PATRÓN DE BRAILLE DOTS-134578
    0x0C , // 0x28DE ⣞ PATRÓN DE BRAILLE DOTS-234578
    0x04 , // 0x28DF ⣟ PATRÓN DE BRAILLE DOTS-1234578
    0x3B , // 0x28E0 ⣠ PATRÓN DE BRAILLE DOTS-678
    0x33 , // 0x28E1 ⣡ PATRÓN DE BRAILLE DOTS-1678
    0x2B , // 0x28E2 ⣢ PATRÓN DE BRAILLE DOTS-2678
    0x23 , // 0x28E3 ⣣ PATRÓN DE BRAILLE DOTS-12678
    0x1B , // 0x28E4 ⣤ PATRÓN DE BRAILLE DOTS-3678
    0x13 , // 0x28E5 ⣥ PATRÓN DE BRAILLE DOTS-13678
    0x0B , // 0x28E6 ⣦ PATRÓN DE BRAILLE DOTS-23678
    0x03 , // 0x28E7 ⣧ PATRÓN DE BRAILLE DOTS-123678
    0x3A , // 0x28E8 ⣨ PATRÓN DE BRAILLE DOTS-4678
    0x32 , // 0x28E9 ⣩ PATRÓN DE BRAILLE DOTS-14678
    0x2A , // 0x28EA ⣪ PATRÓN DE BRAILLE DOTS-24678
    0x22 , // 0x28EB ⣫ PATRÓN DE BRAILLE DOTS-124678
    0x1A , // 0x28EC ⣬ PATRÓN DE BRAILLE DOTS-34678
    0x12 , // 0x28ED ⣭ PATRÓN DE BRAILLE DOTS-134678
    0x0A , // 0x28EE ⣮ PATRÓN DE BRAILLE DOTS-234678
    0x02 , // 0x28EF ⣯ PATRÓN DE BRAILLE DOTS-1234678
    0x39 , // 0x28F0 ⣰ PATRÓN DE BRAILLE DOTS-5678
    0x31 , // 0x28F1 ⣱ PATRÓN DE BRAILLE DOTS-15678
    0x29 , // 0x28F2 ⣲ PATRÓN DE BRAILLE DOTS-25678
    0x21 , // 0x28F3 ⣳ PATRÓN DE BRAILLE DOTS-125678
    0x19 , // 0x28F4 ⣴ PATRÓN DE BRAILLE DOTS-35678
    0x11 , // 0x28F5 ⣵ PATRÓN DE BRAILLE DOTS-135678
    0x09 , // 0x28F6 ⣶ PATRÓN DE BRAILLE DOTS-235678
    0x01 , // 0x28F7 ⣷ PATRÓN DE BRAILLE DOTS-1235678
    0x38 , // 0x28F8 ⣸ PATRÓN DE BRAILLE DOTS-45678
    0x30 , // 0x28F9 ⣹ PATRÓN DE BRAILLE DOTS-145678
    0x28 , // 0x28FA ⣺ PATRÓN DE BRAILLE DOTS-245678
    0x20 , // 0x28FB ⣻ PATRÓN DE BRAILLE DOTS-1245678
    0x18 , // 0x28FC ⣼ PATRÓN DE BRAILLE DOTS-345678
    0x10 , // 0x28FD ⣽ PATRÓN DE BRAILLE DOTS-1345678
    0x08 , // 0x28FE ⣾ PATRÓN DE BRAILLE DOTS-2345678
    0x00 , // 0x28FF ⣿ PATRÓN DE BRAILLE DOTS-12345678
};
}
#endif // braille_h
