+# Adafruit_SSD1306 [![Build Status](https://github.com/adafruit/Adafruit_SSD1306/workflows/Arduino%20Library%20CI/badge.svg)](https://github.com/adafruit/Adafruit_SSD1306/actions)[![Documentation](https://github.com/adafruit/ci-arduino/blob/master/assets/doxygen_badge.svg)](http://adafruit.github.io/Adafruit_SSD1306/html/index.html)

Il s'agit d'une bibliothèque pour nos écrans OLED monochromes basés sur les pilotes SSD1306. Les références ont été changer pour le produit ZJYM1097P SPI IC:CH1115 SKU: ARDUINO-SCREEN-SPI Tous les mérites reviennent à Adafruit.

Achetez-en un aujourd'hui dans la boutique Adafruit !
------> http://www.adafruit.com/category/63_98

Ces écrans utilisent la communication I2C ou SPI, et 2 à 5 broches sont nécessaires pour l'interface.

Adafruit consacre du temps et des ressources pour fournir ce code source open source. Veuillez soutenir Adafruit et le matériel open-source en achetant des produits chez Adafruit !

Écrit par Limor Fried/Ladyada pour Adafruit Industries, avec des contributions de la communauté open source. Le code de défilement a été contribué par Michael Gregg. L'allocation dynamique de tampon est basée sur le travail d'Andrew Canaday.
Licence BSD, consultez license.txt pour plus d'informations. Tout le texte ci-dessus doit être inclus dans toute redistribution.

La méthode d'installation préférée consiste à utiliser le gestionnaire de bibliothèques de l'IDE Arduino. Pour télécharger la source depuis Github, cliquez sur "Clone or download" ci-dessus, puis sur "Download ZIP". Après avoir décompressé, renommez le dossier résultant en "Adafruit_SSD1306". Vérifiez que le dossier "Adafruit_SSD1306" contient les fichiers Adafruit_SSD1306.cpp et Adafruit_SSD1306.h.

Vous devrez également installer la **bibliothèque Adafruit GFX** qui fournit des primitives graphiques telles que des lignes, des cercles, du texte, etc. Cette bibliothèque est également disponible dans le Gestionnaire de bibliothèques Arduino, ou vous pouvez obtenir la source depuis https://github.com/adafruit/Adafruit-GFX-Library.

## Changements
Demande de tirage :
   (novembre 2021)
   * Ajout de la définition `SSD1306_NO_SPLASH` pour exclure l'inclusion d'images d'introduction dans `PROGMEM` et le dessin sur l'écran lors de l'utilisation de `begin`.

Demande de tirage :
   (septembre 2019)
   * Nouvelles définitions pour SSD1306_BLACK, SSD1306_WHITE et SSD1306_INVERSE qui correspondent au schéma de dénomination des autres #define existants et n'entrent pas en conflit avec les noms de couleur courants.
   * Anciennes définitions pour BLACK, WHITE et INVERSE conservées pour la compatibilité ascendante (exclusion avec #define NO_ADAFRUIT_SSD1306_COLOR_COMPATIBILITY)

La version 1.2 (novembre 2018) introduit quelques changements importants :

  * Les dimensions de l'écran sont désormais spécifiées dans le constructeur... vous n'avez plus besoin de modifier le fichier .h pour différents écrans (bien que les anciens croquis puissent continuer

 à fonctionner de cette manière).
  * Les transactions SPI sont utilisées et la fréquence de transfert SPI peut être spécifiée (les deux nécessitent Arduino 1.6 ou une version ultérieure).
  * Les interfaces SPI et Wire (I2C) autres que les valeurs par défaut sont prises en charge.

<!-- START COMPATIBILITY TABLE -->

## Compatibilité

MCU         |Fonctionne|Ne fonctionne pas|Non testé|Remarques
------------|:----------:|:----------:|:--------:|-----
Atmega328   |      X     |            |          |
Atmega32u4  |      X     |            |          |
Atmega2560  |      X     |            |          |
ESP8266     |      X     |            |          | Changez OLED_RESET vers une broche différente si vous utilisez les broches I2C par défaut D4/D5.
ESP32       |      X     |            |          |
ATSAM3X8E   |      X     |            |          |
ATSAMD21    |      X     |            |          |
Intel Curie |      X     |            |          |
WICED       |      X     |            |          | Pas de SPI matériel - bit-banging uniquement
ATtiny85    |            |      X     |          |
Particle    |      X     |            |          |

  * ATmega328 : Arduino UNO, Adafruit Pro Trinket, Adafruit Metro 328, Adafruit Metro Mini
  * ATmega32u4 : Arduino Leonardo, Arduino Micro, Arduino Yun, Teensy 2.0, Adafruit Flora, Bluefruit Micro
  * ATmega2560 : Arduino Mega
  * ESP8266 : Adafruit Huzzah
  * ATSAM3X8E : Arduino Due
  * ATSAMD21 : Arduino Zero, M0 Pro, Adafruit Metro Express, Feather M0
  * ATtiny85 : Adafruit Gemma, Arduino Gemma, Adafruit Trinket
  * Particle: Particle Argon

<!-- END COMPATIBILITY TABLE -->