#include "Dominios.h"

const regex Nota::PADRAO_ACEITO = regex("^([0-9]|10)$");


const unordered_set<string> Idioma::POSSIVEIS_VALORES = {"Arabe", "Bengali", "Chines", "Espanhol", "Frances", "Hindi", "Indonesio", "Ingles", "Mandarim", "Portugues", "Russo"};



const regex Data::PADRAO_ACEITO = regex(
    "^(([0-2][0-9]|[3][01])[\\/](Jan|Mar|Mai|Jul|Ago|Out|Dez))|([0-2][0-9]|[3][0])[\\/](Abr|Jun|Set|Nov)|([0-2][0-9])[\\/](Fev)$"
    );


const unordered_set<string> Cidade::POSSIVEIS_VALORES = {
    // Matrícula: 211038208

    "Antalya", "Bangkok", "Delhi", "Dubai", "Hong Kong", "Londres", "Macau",
    "Mumbai", "Paris", "Rio de Janeiro", "Sao Paulo", "Seul", "Istambul",
    "Kuala Lumpur", "Nova Iorque", "Osaka", "Phuket", "Shenzhen", "Toquio"
    };


const regex Email::PADRAO_ACEITO = regex(
    "^(?!^[.]|.*[-_.]{2}.*[@]|.*[._@][@-]|.*[-][.@]|.*[-.]$)[a-zA-Z0-9-_.]{1,64}[@]([a-zA-Z0-9-]{1,63}[.]?)+$"
    );


const regex Senha::PADRAO_ACEITO = regex("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!#$%&])[a-zA-Z0-9!#$%&]{5}$");
