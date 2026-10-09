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
  Serial.print("tamanho da string e bytes: ");
  Serial.println(tamanhoMensagem);

  //* Acessando um caractere em uma posicao especifica
  char primeiraLetra = mensagem.charAt(0);
  Serial.print("Primeira letra é: ");
  Serial.println(primeiraLetra);

  //* Tambem é possivel acessar atraves de [] colchetes

  //*Localizando texto dentro da string
  int posicaoTexto =  mensagem.indexOf("curso");
  Serial.println(posicaoTexto);
}