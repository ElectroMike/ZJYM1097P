
/**************************************************************************
Il s'agit d'un exemple pour nos écrans OLED monochromes basés sur le driver SSD1306

Procurez-vous-en un dès aujourd'hui dans la boutique Adafruit !
------> http://www.adafruit.com/category/63_98

Cet exemple est destiné à un écran de 128x64 pixels utilisant SPI pour la communication.
4 ou 5 broches sont nécessaires pour l'interface.

Adafruit consacre du temps et des ressources pour fournir ce code source open source,
veuillez soutenir Adafruit et le matériel open source en achetant des produits chez Adafruit !

Modifié par l'équipe d'ElectroMike pour les écrans ZJYM1097P.
Consultez notre code source sur GitHub :
------> https://github.com/ElectroMike

Visitez notre site web pour en savoir plus :
------> https://www.electromike.com

Écrit par Limor Fried/Ladyada pour Adafruit Industries,
avec des contributions de la communauté open source.
Licence BSD, consultez license.txt pour plus d'informations.
Tous les textes ci-dessus, ainsi que l'écran de démarrage ci-dessous, doivent
être inclus dans toute redistribution.
**************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // Largeur de l'affichage OLED, en pixels
#define SCREEN_HEIGHT 64 // Hauteur de l'affichage OLED, en pixels

// Déclaration pour l'affichage SSD1306 connecté en utilisant le SPI logiciel (cas par défaut) :
#define OLED_MOSI  11
#define OLED_CLK   13
#define OLED_DC    9
#define OLED_CS    8
#define OLED_RESET 10
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

/* Commentez ci-dessus, décommentez ce bloc pour utiliser le SPI matériel
#define OLED_DC     6
#define OLED_CS     7
#define OLED_RESET  8
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  &SPI, OLED_DC, OLED_RESET, OLED_CS);
*/

#define NUMFLAKES     10 // Nombre de flocons de neige dans l'exemple d'animation

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ 0b00000000, 0b11000000,
  0b00000001, 0b11000000,
  0b00000001, 0b11000000,
  0b00000011, 0b11100000,
  0b11110011, 0b11100000,
  0b11111110, 0b11111000,
  0b01111110, 0b11111111,
  0b00110011, 0b10011111,
  0b00011111, 0b11111100,
  0b00001101, 0b01110000,
  0b00011011, 0b10100000,
  0b00111111, 0b11100000,
  0b00111111, 0b11110000,
  0b01111100, 0b11110000,
  0b01110000, 0b01110000,
  0b00000000, 0b00110000 };

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = générer la tension d'affichage à partir de 3,3V en interne
  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Ne pas continuer, boucler indéfiniment
  }

   display.ssd1306_command(0xA0); // Réaffectation du segment pour que l'adresse de colonne 127 corresponde à SEG0 (miroir)



  // Affiche les contenus initiaux du tampon d'affichage à l'écran --
  // la bibliothèque initialise cela avec un écran de démarrage Adafruit.
  display.display();
  delay(2000);  // Pause de 2 secondes
  
  // Efface le tampon
  display.clearDisplay();

  // Dessine un seul pixel en blanc
  display.drawPixel(10, 10, SSD1306_WHITE);

// Affiche le tampon d'affichage à l'écran. Vous DEVEZ appeler display() après
// commandes de dessin pour les rendre visibles à l'écran !
  display.display();
  delay(2000);
// display.display() n'est pas nécessaire après chaque commande de dessin,
// sauf si c'est ce que vous voulez... au lieu de cela, vous pouvez regrouper plusieurs
// opérations de dessin et mettre à jour l'écran en une seule fois en appelant
// display.display(). Ces exemples démontrent les deux approches...

testdrawline(); // Dessiner plusieurs lignes

testdrawrect(); // Dessiner des rectangles (contours)

testfillrect(); // Dessiner des rectangles (remplis)

testdrawcircle(); // Dessiner des cercles (contours)

testfillcircle(); // Dessiner des cercles (remplis)

testdrawroundrect(); // Dessiner des rectangles arrondis (contours)

testfillroundrect(); // Dessiner des rectangles arrondis (remplis)

testdrawtriangle(); // Dessiner des triangles (contours)

testfilltriangle(); // Dessiner des triangles (remplis)

testdrawchar(); // Dessiner des caractères de la police par défaut

testdrawstyles(); // Dessiner des caractères "stylisés"

testscrolltext(); // Dessiner un texte défilant

testdrawbitmap(); // Dessiner une petite image bitmap

// Inverser et restaurer l'affichage, avec une pause entre les deux
  display.invertDisplay(true);
  delay(1000);
  display.invertDisplay(false);
  delay(1000);

  testanimate(logo_bmp, LOGO_WIDTH, LOGO_HEIGHT); // Animer des bitmaps
}

void loop() {
}

void testdrawline() {
  int16_t i;

  display.clearDisplay(); // Effacer la mémoire tampon de l'écran

  for(i=0; i<display.width(); i+=4) {
    display.drawLine(0, 0, i, display.height()-1, SSD1306_WHITE);
    display.display(); // Mettre à jour l'écran avec chaque ligne nouvellement dessinée
    delay(1);
  }
  for(i=0; i<display.height(); i+=4) {
    display.drawLine(0, 0, display.width()-1, i, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  delay(250);

  display.clearDisplay();

  for(i=0; i<display.width(); i+=4) {
    display.drawLine(0, display.height()-1, i, 0, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  for(i=display.height()-1; i>=0; i-=4) {
    display.drawLine(0, display.height()-1, display.width()-1, i, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  delay(250);

  display.clearDisplay();

  for(i=display.width()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, i, 0, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  for(i=display.height()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, 0, i, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  delay(250);

  display.clearDisplay();

  for(i=0; i<display.height(); i+=4) {
    display.drawLine(display.width()-1, 0, 0, i, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  for(i=0; i<display.width(); i+=4) {
    display.drawLine(display.width()-1, 0, i, display.height()-1, SSD1306_WHITE);
    display.display();
    delay(1);
  }

  delay(2000); // Pause for 2 seconds
}

void testdrawrect(void) {
  display.clearDisplay();

  for(int16_t i=0; i<display.height()/2; i+=2) {
    display.drawRect(i, i, display.width()-2*i, display.height()-2*i, SSD1306_WHITE);
    display.display(); // Mettre à jour l'écran avec chaque rectangle nouvellement dessiné
    delay(1);
  }

  delay(2000);
}

void testfillrect(void) {
  display.clearDisplay();

  for(int16_t i=0; i<display.height()/2; i+=3) {
    // The INVERSE color is used so rectangles alternate white/black
    display.fillRect(i, i, display.width()-i*2, display.height()-i*2, SSD1306_INVERSE);
    display.display(); // Mettre à jour l'écran avec chaque rectangle nouvellement dessiné
    delay(1);
  }

  delay(2000);
}

void testdrawcircle(void) {
  display.clearDisplay();

  for(int16_t i=0; i<max(display.width(),display.height())/2; i+=2) {
    display.drawCircle(display.width()/2, display.height()/2, i, SSD1306_WHITE);
    display.display();
    delay(1);
  }

  delay(2000);
}

void testfillcircle(void) {
  display.clearDisplay();

  for(int16_t i=max(display.width(),display.height())/2; i>0; i-=3) {
    // The INVERSE color is used so circles alternate white/black
    display.fillCircle(display.width() / 2, display.height() / 2, i, SSD1306_INVERSE);
    display.display(); // Update screen with each newly-drawn circle
    delay(1);
  }

  delay(2000);
}

void testdrawroundrect(void) {
  display.clearDisplay();

  for(int16_t i=0; i<display.height()/2-2; i+=2) {
    display.drawRoundRect(i, i, display.width()-2*i, display.height()-2*i,
      display.height()/4, SSD1306_WHITE);
    display.display();
    delay(1);
  }

  delay(2000);
}

void testfillroundrect(void) {
  display.clearDisplay();

  for(int16_t i=0; i<display.height()/2-2; i+=2) {
    // The INVERSE color is used so round-rects alternate white/black
    display.fillRoundRect(i, i, display.width()-2*i, display.height()-2*i,
      display.height()/4, SSD1306_INVERSE);
    display.display();
    delay(1);
  }

  delay(2000);
}

void testdrawtriangle(void) {
  display.clearDisplay();

  for(int16_t i=0; i<max(display.width(),display.height())/2; i+=5) {
    display.drawTriangle(
      display.width()/2  , display.height()/2-i,
      display.width()/2-i, display.height()/2+i,
      display.width()/2+i, display.height()/2+i, SSD1306_WHITE);
    display.display();
    delay(1);
  }

  delay(2000);
}

void testfilltriangle(void) {
  display.clearDisplay();

  for(int16_t i=max(display.width(),display.height())/2; i>0; i-=5) {
    // La couleur INVERSE est utilisée pour alterner les rectangles en blanc/
    display.fillTriangle(
      display.width()/2  , display.height()/2-i,
      display.width()/2-i, display.height()/2+i,
      display.width()/2+i, display.height()/2+i, SSD1306_INVERSE);
    display.display();
    delay(1);
  }

  delay(2000);
}

void testdrawchar(void) {
  display.clearDisplay();

display.setTextSize(1); // Échelle de pixels normale 1:1
display.setTextColor(SSD1306_WHITE); // Texte blanc
display.setCursor(0, 0); // Début en haut à gauche
display.cp437(true); // Utiliser la police 'Code Page 437' avec les 256 caractères

// Tous les caractères ne rentreront pas sur l'écran. C'est normal.
// La bibliothèque dessinera ce qu'elle peut et le reste sera coupé.
  for(int16_t i=0; i<256; i++) {
    if(i == '\n') display.write(' ');
    else          display.write(i);
  }

  display.display();
  delay(2000);
}

void testdrawstyles(void) {
  display.clearDisplay();

display.setTextSize(1);             // Échelle de pixels normale 1:1
display.setTextColor(SSD1306_WHITE);        // Texte blanc
display.setCursor(0,0);             // Début en haut à gauche
display.println(F("Bonjour, monde !"));

display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Texte 'inverse'
display.println(3.141592);

display.setTextSize(2);             // Texte à l'échelle 2X
display.setTextColor(SSD1306_WHITE);
display.print(F("0x")); display.println(0xDEADBEEF, HEX);

display.display();
delay(2000);
}

void testscrolltext(void) {
display.clearDisplay();

display.setTextSize(2); // Texte à l'échelle 2X
display.setTextColor(SSD1306_WHITE);
display.setCursor(10, 0);
display.println(F("défilement"));
display.display();      // Affiche le texte initial
delay(100);

// Faire défiler dans différentes directions, avec une pause entre chaque :
display.startscrollright(0x00, 0x0F);
delay(2000);
display.stopscroll();
delay(1000);
display.startscrollleft(0x00, 0x0F);
delay(2000);
display.stopscroll();
delay(1000);
display.startscrolldiagright(0x00, 0x07);
delay(2000);
display.startscrolldiagleft(0x00, 0x07);
delay(2000);
display.stopscroll();
delay(1000);
}

void testdrawbitmap(void) {
  display.clearDisplay();

  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(1000);
}

#define XPOS   0 // Indexe dans le tableau 'icons' dans la fonction ci-dessous
#define YPOS   1
#define DELTAY 2

void testanimate(const uint8_t *bitmap, uint8_t w, uint8_t h) {
int8_t f, icons[NUMFLAKES][3];

// Initialiser les positions des 'flocons de neige'
for(f=0; f< NUMFLAKES; f++) {
  icons[f][XPOS]   = random(1 - LOGO_WIDTH, display.width());
  icons[f][YPOS]   = -LOGO_HEIGHT;
  icons[f][DELTAY] = random(1, 6);
  Serial.print(F("x: "));
  Serial.print(icons[f][XPOS], DEC);
  Serial.print(F(" y: "));
  Serial.print(icons[f][YPOS], DEC);
  Serial.print(F(" dy: "));
  Serial.println(icons[f][DELTAY], DEC);
}

for(;;) { // Boucle infinie...
display.clearDisplay(); // Efface la mémoire tampon de l'affichage

// Dessiner chaque flocon de neige :
for(f=0; f< NUMFLAKES; f++) {
  display.drawBitmap(icons[f][XPOS

], icons[f][YPOS], bitmap, w, h, SSD1306_WHITE);
}

display.display(); // Affiche la mémoire tampon sur l'écran
delay(200);        // Pause de 1/10 de seconde

// Mettre à jour les coordonnées de chaque flocon de neige...
for(f=0; f< NUMFLAKES; f++) {
  icons[f][YPOS] += icons[f][DELTAY];
  // Si le flocon de neige dépasse le bas de l'écran...
  if (icons[f][YPOS] >= display.height()) {
    // Réinitialiser à une position aléatoire, juste au-dessus
    icons[f][XPOS]   = random(1 - LOGO_WIDTH, display.width());
    icons[f][YPOS]   = -LOGO_HEIGHT;
    icons[f][DELTAY] = random(1, 6);
      }
    }
  }
}
