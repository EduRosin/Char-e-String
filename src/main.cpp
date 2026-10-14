/* =====================================================
? PROJETO: CHAR E STRING
? DESCRIÇÃO: EXPLICAÇÃO SOBRE CHAR E STRING.
? NOME: EDUARDO ROSIN
? DATA: 09/10/2026
? VERSÃO 0.1
======================================================*/
#include <Arduino.h>
#include <string.h> //* strlem, strcpy, strcat, strcmp, strchr
#include <stdlib.h> //* atoi

void textoChar();
void textoString();

void setup()
{
  Serial.begin(9600);
  Serial.println();
  textoChar();
  textoString();
}

void loop()
{
}

void textoChar()
{
  //! texto literal
  //! usamos const char* quado o texto nao sera alterado
  const char cidade[] = "Sao paulo";
  Serial.println(cidade);

  //! Descobrindo o tamnho do texto
  //! strlen conta quantos caracteres antes do \0
  int tamanhoTextoCidade = strlen(cidade);
  Serial.print("Comprimento do texto: ");
  Serial.println(tamanhoTextoCidade);

  //! sizeof() retorna o espaco ocupado pela variavel
  int tamanhoVariavelCidade = sizeof(cidade);
  Serial.print("Espaco utilizado: ");
  Serial.println(tamanhoVariavelCidade);

  //! ao usar aspas duplas "" o compilador ja compreende a variavel como texto/string
  //! e automaticamente inclui o \0
  char vetorTexto[] = {'E', 'd', 'u', 'a', 'r', 'd', 'o', '\0'};
  Serial.println(vetorTexto);

  //! Comparar texto
  //! strcmp analiza a ordem lexica das palavras, se a primeira palavra vem antes da segunda
  //! o valor retornado sera menor que zero
  const char *cidade1 = "Sao Caetano";
  const char *cidade2 = "Sao Caetano";

  if (strcmp(cidade1, cidade2) == 0)
    Serial.println("os textos sao iguais");
  else
    Serial.println("os textos sao diferentes");

  //*===================================
  //*=====TEXTO EDITAVEL COM CHAR[]=====
  //*===================================

  char nomeAluno[20] = "EDUARDi";
  Serial.println(nomeAluno);
  nomeAluno[6] = 'O';
  Serial.println(nomeAluno);

  //! copiando outro texto para dentro do vetor, cuidado, o vetor precisa de espaco suficiente
  //! substitui
  strcpy(nomeAluno, "TADEU");
  Serial.println(nomeAluno);

  //! concatenando ao texto final
  char frase[40] = "ola ";
  strcat(frase, "mundo!");
  Serial.println(frase);

  //! localizando um caractere especifico no texto
  char *posicaoLetra = strchr(frase, 'm');
  if (posicaoLetra != NULL)
  {
    Serial.print("letra encontrada: ");
    Serial.println(posicaoLetra);
  }
  else
    Serial.println("Caractere nao encontrado");

  //! convertendo texto numeric para inteiro

  char idadeTexto[] = "45"; // 52, 53, \0
  int idade = atoi(idadeTexto);
  Serial.println(idade);
  Serial.println(idadeTexto);

  //TODO Montando texto

  char buffer[100];
  char* local = "sala de aula";
  float temperatura = 26.4;
  int humidade = 58;


  snprintf(buffer, sizeof(buffer), "%s | Temp.: %.1f | Humidade: %d %% \n\r", buffer, temperatura, humidade);
  Serial.print(buffer);

  //TODO snprintf monta o texto dentro de um vetor char
  //TODO snprintf(OndeOTextoFicaArmazenado, TamanhoMaximoDoTexto, TextoComFormatacao, ConteudoDoTexto);
  //TODO util pra salvar um texto grande dentro de uma variavel
  //TODO enviar pra MQTT(IoT), Display ou Imprimir na Serial


  //? EPECIFICADORES
  //? %d ou %i = Int
  //? %u ou %lu = Unsigned int/long
  //? %f = Float
  //? %c = Char
  //? %s = Char* (string)
  //? %g = Float, mais curto
  //? %x ou %X = Hexadecimal minusculo/maiusculo
  //? %o = Octal
  //? %% = O proprio %
  //? %p = Ponteiro
  //? %e = Notacao cientifica
  //?
  //?
  //?   FLAG, LARGURA E PRECISÃO
  //?
  //? %5d = Imprime com largura MINIMA de 5 alinhado a direita [    4], [  100], [1000000000000]
  //? %-4d = Imprime com largura MINIMA de 4 alinhado a esquerda [4   ], [100 ], [123456789]
  //? %03d = Completa com zeros a esquerda [002]
  //? %+d = Sempre mostra o sinal [+3], [-6]
  //? %.2f = Duas casas decimais num float [0,02]
  //? %4.2f = Largura minima de 4 a direita com 2 casas decimais
  //? %02X = Hexadecimal com 2 digitos [0F] [5A]
  //? %#x = Imprime o prefixo 0x
  //? %.3s = Somente os 3 primeiros caracteres da strings

  //? int largura = 3;
  //? int numero = 9;
  //? %*d = Largura passada como argumento 
  //? snprintf(buffer, sizeof(buffer),"numero %*d \n\r" largura, numero)
  //? Serial.print(buffer) -> [  9]
  //?
  
  //* FORMATADORES DE TEXTO
  //* 
  //* 
  //* \n passa para a proxima linha
  //* \r volta para o inicio da linha
  //* \lu retorna unsigned long
  //* 
  //* 
  //* 
  //* 
  //* 
  //* 
  //*
  //*

}

void textoString()
{
  //*============================
  //*======USANDO STRINGS========
  //*============================

  String nome = "Eduardo";
  String curso = "Logica de Programação";
  String mensagem = "Olá";
  //*concatenando
  mensagem = mensagem + "," + nome + "! Bem vindo ao curso de " + curso + ".";
  Serial.println(mensagem);

  //* Tamanho de uma string
  int tamanhoMensagem = mensagem.length();
  Serial.print("tamanho da string em letras: ");
  Serial.println(tamanhoMensagem);

  //* Acessando um caractere em uma posicao especifica
  char primeiraLetra = mensagem.charAt(0);
  Serial.print("Primeira letra é: ");
  Serial.println(primeiraLetra);

  //* Tambem é possivel acessar atraves de [] colchetes

  //*Localizando texto dentro da string
  int posicaoTexto = mensagem.indexOf("curso");
  Serial.println(posicaoTexto);

  //*Extraindo um texto dentro da string
  int inicioTextoDesejado = posicaoTexto + 9;
  Serial.println(mensagem.substring(inicioTextoDesejado, tamanhoMensagem - 1));

  //* substituindo texto da string
  mensagem.replace("Olá,", "Oi, Tudo bom? ");
  Serial.println(mensagem);

  //*Convertendo para maiusculas
  mensagem.toUpperCase();
  Serial.println(mensagem);

  //* Convertendo para minusculas
  mensagem.toLowerCase();
  Serial.println(mensagem);

  //*Converntendo texto numerico para inteiros
  String textoNumerico = "123456";
  int numero = textoNumerico.toInt();
  Serial.println(numero * 2);

  //* Verificando se a string esta vazio
  String textoExtra = "";
  if (textoExtra.length() == 0)
    Serial.println("texto esta vazio");

  //*Convertendo string para const char
  //* util quando alguma biblioteca exige um texto tipo C
  const char *textoComoChar = mensagem.c_str();
  Serial.println(textoComoChar);
}