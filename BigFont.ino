/*
   Large Font by Ben Lipsey www.varind.com 2016. This code is public domain, enjoy!
   https://github.com/varind/LCDCustomLargeFont
   
   based on characters by Michael Pilcher  2/9/2010
   http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1265696343
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 7, 6, 5, 4, 3);

byte char_x = 0;
byte char_y = 0;

char data1[] = "O, He";
char data2[] = "llo";
char data3[] = "12345";
 
void setup() {
  lcd.begin(20, 4);
  lcd.clear();
  createChars();
}

void loop() {
  char_x = 0;
  char_y = 0;

  printBigCharacters(data1, char_x, char_y);
  printBigCharacters(data2, char_x, char_y);

  char_x = 0;
  char_y = 2;

  printBigCharacters(data3, char_x, char_y);

  delay(1000);
}


//---------------------- Large LCD Characters ------------------------//  From Michael Pilcher with a few additions by Ben Lipsey

byte LT[8] =
{
  B00111,
  B01111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte UB[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte RT[8] =
{
  B11100,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte LL[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B01111,
  B00111
};
byte LB[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};
byte LR[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11110,
  B11100
};
byte UMB[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};
byte LMB[8] =
{
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};


void createChars() {
  lcd.createChar(1, UB);
  lcd.createChar(2, RT);
  lcd.createChar(3, LL);
  lcd.createChar(4, LB);
  lcd.createChar(5, LR);
  lcd.createChar(6, UMB);
  lcd.createChar(7, LMB);
  lcd.createChar(8, LT);
}


void printBigCharacters(char character[], byte x, byte y) {
  bool foundChar;
  byte charWidth = 0;

  for (byte i = 0; i < strlen(character); i++) {

    charWidth = 0;
    foundChar = false;

    if (character[i] == '0' || character[i] == 'O' || character[i] == 'o')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(8);
      lcd.write(1);
      lcd.write(2);
      lcd.setCursor(x, y + 1);
      lcd.write(3);
      lcd.write(4);
      lcd.write(5);
    }

    if (character[i] == '1')
    {
      foundChar = true;
      charWidth = 2;
      lcd.setCursor(x, y);
      lcd.write(1);
      lcd.write(2);
      lcd.setCursor(x + 1, y + 1);
      lcd.write(255);
      lcd.write(254);
    }

    if (character[i] == '2')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(6);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(x, y + 1);
      lcd.write(3);
      lcd.write(7);
      lcd.write(7);
    }

    if (character[i] == '3')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(6);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(x, y + 1);
      lcd.write(7);
      lcd.write(7);
      lcd.write(5);
    }

    if (character[i] == '4')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(3);
      lcd.write(4);
      lcd.write(2);
      lcd.setCursor(x + 2, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
    }

    if (character[i] == '5')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(6);
      lcd.write(6);
      lcd.setCursor(x, y + 1);
      lcd.write(7);
      lcd.write(7);
      lcd.write(5);
    }

    if (character[i] == '6')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(8);
      lcd.write(6);
      lcd.write(6);
      lcd.setCursor(x, y + 1);
      lcd.write(3);
      lcd.write(7);
      lcd.write(5);
    }

    if (character[i] == '7')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(1);
      lcd.write(1);
      lcd.write(2);
      lcd.setCursor(x + 1, y + 1);
      lcd.write(8);
      lcd.write(254);
      lcd.write(254);
    }

    if (character[i] == '8')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(8);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(x, y + 1);
      lcd.write(3);
      lcd.write(7);
      lcd.write(5);
    }

    if (character[i] == '9')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(8);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(x + 2, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
    }

    if (character[i] == 'A' || character[i] == 'a')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(8);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(255);
    }

    if (character[i] == 'B' || character[i] == 'b')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(6);
      lcd.write(5);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(7);
      lcd.write(2);
    }

    if (character[i] == 'C' || character[i] == 'c')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(8);
      lcd.write(1);
      lcd.write(1);
      lcd.setCursor(x, y + 1);
      lcd.write(3);
      lcd.write(4);
      lcd.write(4);
    }

    if (character[i] == 'D' || character[i] == 'd')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(1);
      lcd.write(2);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(4);
      lcd.write(5);
    }

    if (character[i] == 'E' || character[i] == 'e')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(6);
      lcd.write(6);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(7);
      lcd.write(7);
    }

    if (character[i] == 'F' || character[i] == 'f')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(6);
      lcd.write(6);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
    }

    if (character[i] == 'G' || character[i] == 'g')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(8);
      lcd.write(1);
      lcd.write(1);
      lcd.setCursor(x, y + 1);
      lcd.write(3);
      lcd.write(4);
      lcd.write(2);
    }

    if (character[i] == 'H' || character[i] == 'h')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(4);
      lcd.write(255);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(255);
    }

    if (character[i] == 'I' || character[i] == 'i')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(1);
      lcd.write(255);
      lcd.write(1);
      lcd.setCursor(x, y + 1);
      lcd.write(4);
      lcd.write(255);
      lcd.write(4);
    }

    if (character[i] == 'J' || character[i] == 'j')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x + 2, y);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
      lcd.setCursor(x, y + 1);
      lcd.write(4);
      lcd.write(4);
      lcd.write(5);
    }

    if (character[i] == 'K' || character[i] == 'k')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(4);
      lcd.write(5);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(2);
    }

    if (character[i] == 'L' || character[i] == 'l')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(4);
      lcd.write(4);
    }

    if (character[i] == 'M' || character[i] == 'm')
    {
      foundChar = true;
      charWidth = 4;
      lcd.setCursor(x, y);
      lcd.write(8);
      lcd.write(3);
      lcd.write(5);
      lcd.write(2);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
      lcd.write(255);
    }

    if (character[i] == 'N' || character[i] == 'n')
    {
      foundChar = true;
      charWidth = 4;
      lcd.setCursor(x, y);
      lcd.write(8);
      lcd.write(2);
      lcd.write(254);
      lcd.write(255);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(3);
      lcd.write(5);
    }

    if (character[i] == 'P' || character[i] == 'p')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
    }

    if (character[i] == 'Q' || character[i] == 'q')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(8);
      lcd.write(1);
      lcd.write(2);
      lcd.write(254);
      lcd.setCursor(x, y + 1);
      lcd.write(3);
      lcd.write(4);
      lcd.write(255);
      lcd.write(4);
    }

    if (character[i] == 'R' || character[i] == 'r')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(x, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(2);
    }

    if (character[i] == 'S' || character[i] == 's')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(8);
      lcd.write(6);
      lcd.write(6);
      lcd.setCursor(x, y + 1);
      lcd.write(7);
      lcd.write(7);
      lcd.write(5);
    }

    if (character[i] == 'T' || character[i] == 't')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(1);
      lcd.write(255);
      lcd.write(1);
      lcd.setCursor(x, y + 1);
      lcd.write(254);
      lcd.write(255);
      lcd.write(254);
    }

    if (character[i] == 'U' || character[i] == 'u')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(254);
      lcd.write(255);
      lcd.setCursor(x, y + 1);
      lcd.write(3);
      lcd.write(4);
      lcd.write(5);
    }

    if (character[i] == 'V' || character[i] == 'v')
    {
      foundChar = true;
      charWidth = 4;
      lcd.setCursor(x, y);
      lcd.write(3);
      lcd.write(254);
      lcd.write(254);
      lcd.write(5);
      lcd.setCursor(x + 1, y + 1);
      lcd.write(2);
      lcd.write(8);
      lcd.write(254);
      lcd.write(254);
    }

    if (character[i] == 'W' || character[i] == 'w')
    {
      foundChar = true;
      charWidth = 4;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
      lcd.write(255);
      lcd.setCursor(x, y + 1);
      lcd.write(3);
      lcd.write(8);
      lcd.write(2);
      lcd.write(5);
    }

    if (character[i] == 'X' || character[i] == 'x')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(3);
      lcd.write(4);
      lcd.write(5);
      lcd.setCursor(x, y + 1);
      lcd.write(8);
      lcd.write(254);
      lcd.write(2);
    }

    if (character[i] == 'Y' || character[i] == 'y')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(3);
      lcd.write(4);
      lcd.write(5);
      lcd.setCursor(x + 1, y + 1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
    }

    if (character[i] == 'Z' || character[i] == 'z')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(1);
      lcd.write(6);
      lcd.write(5);
      lcd.setCursor(x, y + 1);
      lcd.write(8);
      lcd.write(7);
      lcd.write(4);
    }

    if (character[i] == '?')
    {
      foundChar = true;
      charWidth = 3;
      lcd.setCursor(x, y);
      lcd.write(1);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(x, y + 1);
      lcd.write(254);
      lcd.write(7);
      lcd.write(254);
    }

    if (character[i] == '!')
    {
      foundChar = true;
      charWidth = 1;
      lcd.setCursor(x, y);
      lcd.write(255);
      lcd.setCursor(x, y + 1);
      lcd.write(7);
    }
    if (character[i] == ':')
    {
      foundChar = true;
      charWidth = 1;
      lcd.setCursor(x, y);
      lcd.print(".");
      lcd.setCursor(x, y + 1);
      lcd.print(".");
    }
    if (character[i] == ' ')
    {
      foundChar = true;
      charWidth = 2;
      lcd.setCursor(x, y);
      lcd.write(254);
      lcd.write(254);
      lcd.setCursor(x, y + 1);
      lcd.write(254);
      lcd.write(254);
    }

    if (character[i] == '.')
    {
      foundChar = true;
      charWidth = 1;
      lcd.setCursor(x, y);
      lcd.write(254);
      lcd.setCursor(x, y + 1);
      lcd.write(4);
    }
    if (character[i] == '-')
    {
      foundChar = true;
      charWidth = 2;
      lcd.setCursor(x, y);
      lcd.write(4);
      lcd.write(4);
      lcd.setCursor(x, y + 1);
      lcd.write(254);
      lcd.write(254);
    }
    if (character[i] == '\"')
    {
      foundChar = true;
      charWidth = 1;
      lcd.setCursor(x, y);
      lcd.write("\"");
      lcd.setCursor(x, y + 1);
      lcd.write(254);
    }
    if (character[i] == '\'')
    {
      foundChar = true;
      charWidth = 1;
      lcd.setCursor(x, y);
      lcd.write("\'");
      lcd.setCursor(x, y + 1);
      lcd.write(254);
    }
    if (character[i] == '|')
    {
      foundChar = true;
      charWidth = 1;
      lcd.setCursor(x, y);
      lcd.write("|");
      lcd.setCursor(x, y + 1);
      lcd.write("|");
    }
    if (character[i] == '/')
    {
      foundChar = true;
      charWidth = 2;
      lcd.setCursor(x, y);
      lcd.write(254);
      lcd.write("/");
      lcd.setCursor(x, y + 1);
      lcd.write("/");
      lcd.write(254);
    }

    if (foundChar) {
      char_x = char_x + charWidth;
      x = x + charWidth;
    } else {
      lcd.setCursor(x, y);
      lcd.write(254);
      lcd.setCursor(x, y + 1);
      lcd.print(character[i]);
      x = x + 1;
    }
  }
}

